#pragma once

#include "Pool.h"

class CPool;

class CClientSocket : public CSocket
{
public:
	CClientSocket(CPool* ppool);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual ~CClientSocket();
protected:
	CPool* pPool;
};


