// MyListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "MyListDlg.h"
#include "afxdialogex.h"


// CMyListDlg �Ի���

IMPLEMENT_DYNAMIC(CMyListDlg, CDialogEx)

CMyListDlg::CMyListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LIST_DIALOG, pParent)
{
}

CMyListDlg::~CMyListDlg()
{
}

void CMyListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
	
}


BEGIN_MESSAGE_MAP(CMyListDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMyListDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CMyListDlg ��Ϣ�������


void CMyListDlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strText;
	int nCurSel;

	nCurSel = m_listBox.GetCurSel();
	m_listBox.GetText(nCurSel, strText);
	SetDlgItemText(IDC_SEL_WEB_EDIT, strText);
}


BOOL CMyListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_listBox.AddString(_T("����:http://www.sina.com.cn/"));
	m_listBox.AddString(_T("������:http://www.jizhuomi.com/"));
	m_listBox.AddString(_T("è��:http://www.mop.com/"));
	m_listBox.InsertString(2, _T("�ٶ�:http://www.baidu.com/"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
