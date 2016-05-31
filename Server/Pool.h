#pragma once

// CPool command target
#include "ClientSocket.h"
#include "ListeningSocket.h"
#include "ServerDlg.h"
#include "Manager.h"
#include "dbUsers.h"

class CClientSocket;
class CListeningSocket;

class CPool
{
public:
	CPool();
	virtual ~CPool();
	BOOL Init(void *phost, int port);
	void ProcessClose(CClientSocket *pSocket);
	void ProcessRead(CClientSocket* pSocket, CString msg);
	int ProcessAccept();
protected:
	CListeningSocket *m_pSocket;
	CPtrList connectionList;
	void *pHost;
};


