
// ClientDlg.h : файл заголовка
//

#pragma once
#include "UserSocket.h"
#include "afxwin.h"
#include "ClientData.h"

class CUserSocket;
// диалоговое окно CClientDlg
class CClientDlg : public CDialogEx
{
// Создание
public:
	CClientDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CUserSocket *pSocket;
public:
	CString _login;
	afx_msg void OnBnClickedConnect();
	CString _password;
};
