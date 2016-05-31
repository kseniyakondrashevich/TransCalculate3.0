// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "../Server/ClientSocket.h"


// CClientSocket

CClientSocket::CClientSocket(CPool* ppool){
	pPool = ppool;
}

CClientSocket::~CClientSocket(){
}

void CClientSocket::OnReceive(int nErrorCode){

	char buff[4096];
	CString buffer;
	int nRead = Receive(buff, sizeof(buff));
	
	switch (nRead){
		case SOCKET_ERROR:
			MessageBox(NULL, "Error occurred", "dadsa", MB_OK | MB_ICONASTERISK);
			Close();
			break;
		case 0:
			Close();
			break;
		default:
			buff[nRead] = '\0';
			buffer = buff;
			pPool->ProcessRead(this, buffer);
	}

	CSocket::OnReceive(nErrorCode);
}

void CClientSocket::OnClose(int nErrorCode){

	pPool->ProcessClose(this);
	CSocket::OnClose(nErrorCode);
}


// CClientSocket member functions
