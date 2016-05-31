// UserSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "UserSocket.h"


// CUserSocket

CUserSocket::CUserSocket(void *pDlg, int type){
	
	m_pDlg = pDlg;
	_class_type = type;
}

CUserSocket::~CUserSocket()
{
}

void CUserSocket::OnClose(int nErrorCode)
{
	//m_pDlg->GetDlgItem(IDC_CONNECT)->EnableWindow(TRUE);
	delete this;
	CSocket::OnClose(nErrorCode);
}
void CUserSocket::OnReceive(int nErrorCode)
{
	char buff[4096];
	CString buffer;
	int nRead = Receive(buff, sizeof(buff));

	switch (nRead) {
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
		// to do сделать в отдельном методе
		Manager manager;
		switch (manager.getType((string)buffer)) {
			case 1:
				string act = manager.makeActions((string)buffer);
				if (act == "admin" && _class_type == 0) {
					((CClientDlg*)m_pDlg)->EndDialog(-1);
				}
				break;
		}
	}

	CSocket::OnReceive(nErrorCode);
}


// CUserSocket member functions
