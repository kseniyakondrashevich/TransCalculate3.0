// ListeningSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ListeningSocket.h"


// CListeningSocket

CListeningSocket::CListeningSocket(CPool* ppool){
	pPool = ppool;
}

CListeningSocket::~CListeningSocket(){
}

void CListeningSocket::OnAccept(int nErrorCode){

	pPool->ProcessAccept();
	CSocket::OnAccept(nErrorCode);
}


// CListeningSocket member functions
