// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent)
	, m_name(_T(""))
	, m_password(_T(""))
{
}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME_EDIT, m_name);
	DDX_Text(pDX, IDC_PW_EDIT, m_password);
}

BOOL CLoginDlg::Login_Check() {
	return TRUE;
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN_BUTTON, &CLoginDlg::OnBnClickedLoginButton)
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedLoginButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_name == _T("") || m_password ==_T("")) {
		MessageBox(_T("������Ϸ��û��������룡"),_T("��ʾ"), MB_OK | MB_ICONWARNING);
		CDialogEx::OnCancel();
	}
	else if(CLoginDlg::Login_Check()){
		CDialogEx::OnOK();
	}
	else {
		CDialogEx::OnCancel();
	}
}
