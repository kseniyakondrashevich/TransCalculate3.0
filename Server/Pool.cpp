// Pool.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "Pool.h"

// CPool

CPool::CPool()
{
}

CPool::~CPool()
{
	while (!connectionList.IsEmpty())
	{
		CClientSocket*pSocket = (CClientSocket*)connectionList.RemoveHead();
		if (pSocket != NULL)
		{
			pSocket->Close();
			delete pSocket;
		}
	}
	m_pSocket->Close();
	delete m_pSocket;
}

BOOL CPool::Init(void *phost, int port){

	pHost = (CServerDlg*)phost;
	m_pSocket = new CListeningSocket(this);
	if (m_pSocket->Create(port)){
		if (m_pSocket->Listen()) {
			return TRUE;
		}
	}
	
	return FALSE;
}

int CPool::ProcessAccept(){

	CClientSocket* pSocket = new CClientSocket(this);
	if (m_pSocket->Accept(*pSocket)){
		connectionList.AddTail(pSocket);
		// to do написать, кто подключился и потом, кто отключился
	}
	else {
		delete pSocket;
		return -1;
	}
		
	return 0;
}

void CPool::ProcessClose(CClientSocket *pSocket)
{
	POSITION pos = connectionList.Find(pSocket);
	connectionList.RemoveAt(pos);
	delete pSocket;
}

void CPool::ProcessRead(CClientSocket *pSocket, CString msg)
{
	Manager manager;
	string response = manager.makeResponse((string)msg);
	pSocket->Send(response.c_str(), response.size());
}


// CPool member functions
