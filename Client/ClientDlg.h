
// ClientDlg.h : ���� ���������
//

#pragma once
#include "UserSocket.h"
#include "afxwin.h"
#include "ClientData.h"

class CUserSocket;
// ���������� ���� CClientDlg
class CClientDlg : public CDialogEx
{
// ��������
public:
	CClientDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
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
