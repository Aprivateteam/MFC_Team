// ListCtrlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "ListCtrlDlg.h"
#include "afxdialogex.h"


// CListCtrlDlg �Ի���

IMPLEMENT_DYNAMIC(CListCtrlDlg, CDialogEx)

CListCtrlDlg::CListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LISTCTRL_DIALOG, pParent)
{

}

CListCtrlDlg::~CListCtrlDlg()
{
}

void CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRAM_LANG_LIST, m_programLangList);

}


BEGIN_MESSAGE_MAP(CListCtrlDlg, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_PROGRAM_LANG_LIST, &CListCtrlDlg::OnNMClickProgramLangList)
END_MESSAGE_MAP()


// CListCtrlDlg ��Ϣ�������


void CListCtrlDlg::OnNMClickProgramLangList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CString strLangName;
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;

	if (pNMListView->iItem != -1) { // ���iItem����-1����˵�����б��ѡ��
		//��ȡ��ѡ���б���ĵ�һ��������ı�
		strLangName = m_programLangList.GetItemText(pNMListView->iItem, 0);
		//��ѡ���������ʾ�ڱ༭����
		SetDlgItemText(IDC_LANG_SEL_EDIT, strLangName);
	}
}


BOOL CListCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	CRect rect;
	//��ȡ�б���ͼ�ؼ���λ�����С
	m_programLangList.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����
	m_programLangList.SetExtendedStyle(m_programLangList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ��������
	m_programLangList.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_programLangList.InsertColumn(1, _T("2012.02����"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_programLangList.InsertColumn(2, _T("2011.02����"), LVCFMT_CENTER, rect.Width() / 3, 2);

	// ���б���ͼ�ؼ��в����б���������б������ı�
	m_programLangList.InsertItem(0, _T("Java"));
	m_programLangList.SetItemText(0, 1, _T("1"));
	m_programLangList.SetItemText(0, 2, _T("1"));
	m_programLangList.InsertItem(1, _T("C"));
	m_programLangList.SetItemText(1, 1, _T("2"));
	m_programLangList.SetItemText(1, 2, _T("2"));
	m_programLangList.InsertItem(2, _T("C#"));
	m_programLangList.SetItemText(2, 1, _T("3"));
	m_programLangList.SetItemText(2, 2, _T("6"));
	m_programLangList.InsertItem(3, _T("C++"));
	m_programLangList.SetItemText(3, 1, _T("4"));
	m_programLangList.SetItemText(3, 2, _T("3"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
