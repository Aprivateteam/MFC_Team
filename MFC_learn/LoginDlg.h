#pragma once


#include <iostream>
#include <fstream>
#include "RgsterDlg.h"

// CLoginDlg �Ի���

class CLoginDlg : public CDialogEx
{
	CString m_name;
	CString m_password;
	CRgsterDlg *m_pRgsterDlg;
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	BOOL Login_Check();
	afx_msg void OnBnClickedLoginButton();
	afx_msg void OnBnClickedRegsterButton();
};
