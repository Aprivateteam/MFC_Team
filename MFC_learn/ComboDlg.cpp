// ComboDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "ComboDlg.h"
#include "afxdialogex.h"


// CComboDlg �Ի���

IMPLEMENT_DYNAMIC(CComboDlg, CDialogEx)

CComboDlg::CComboDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COMBO_DIALOG, pParent)
{

}

CComboDlg::~CComboDlg()
{
}

void CComboDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WEB_COMBO, m_comboWeb);


}


BEGIN_MESSAGE_MAP(CComboDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_WEB_COMBO, &CComboDlg::OnCbnSelchangeWebCombo)
END_MESSAGE_MAP()


// CComboDlg ��Ϣ�������


void CComboDlg::OnCbnSelchangeWebCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strWeb;
	int nSel;

	nSel = m_comboWeb.GetCurSel();
	m_comboWeb.GetLBText(nSel, strWeb);
	SetDlgItemText(IDC_SEL_WEB_EDIT, strWeb);
}


BOOL CComboDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_comboWeb.AddString(_T("������:http://www.jizhuomi.com/"));
	m_comboWeb.AddString(_T("�ٶ�:http://www.baidu.com/"));
	m_comboWeb.AddString(_T("����:http://www.sina.com.cn/"));
	m_comboWeb.InsertString(3, _T("è��:http://www.mop.com/"));

	m_comboWeb.SetCurSel(0);

	SetDlgItemText(IDC_SEL_WEB_EDIT, _T("������:http://www.jizhuomi.com/"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
