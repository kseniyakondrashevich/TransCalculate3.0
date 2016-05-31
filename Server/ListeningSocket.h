#pragma once

#include "Pool.h"

class CPool;

class CListeningSocket : public CSocket
{
public:
	CListeningSocket(CPool* ppool);
	virtual void OnAccept(int nErrorCode);
	virtual ~CListeningSocket();
protected:
	CPool* pPool;
};


