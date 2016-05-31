#pragma once

// CUserSocket command target
#include "ClientDlg.h"
#include "../Server/Manager.h"
class CClientDlg;

class CUserSocket : public CSocket
{
public:
	CUserSocket(void *pDlg, int type = 0);
	~CUserSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void *m_pDlg;
	int _class_type;
};


