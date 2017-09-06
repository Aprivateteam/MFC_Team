// TabDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "TabDlg.h"
#include "afxdialogex.h"


// CTabDlg �Ի���

IMPLEMENT_DYNAMIC(CTabDlg, CDialogEx)

CTabDlg::CTabDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_DIALOG, pParent)
{

}

CTabDlg::~CTabDlg()
{
}

void CTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABCTRL, m_tab);
}


BEGIN_MESSAGE_MAP(CTabDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABCTRL, &CTabDlg::OnTcnSelchangeTabctrl)
END_MESSAGE_MAP()


// CTabDlg ��Ϣ�������


BOOL CTabDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect tabRect; // ��ǩ�ؼ��ͻ�����λ�ô�С
	m_tab.InsertItem(0, _T("������"));
	m_tab.InsertItem(1, _T("��Ͽ�"));
	m_scbarDlg.Create(IDD_SCBAR_DIALOG1, &m_tab);
	m_comboDlg.Create(IDD_COMBO_DIALOG, &m_tab);

	m_tab.GetClientRect(&tabRect); // ��ȡ�ѱ�ǩ�ؼ��ͻ���Rect
	// ����tabRect,ʹ�串�Ƿ�Χ�ʺϷ��ñ�ǩҳ
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 25;
	tabRect.bottom -= 1;
	// ���ݵ����õ�tabRect����m_scbarDlg�ӶԻ���,����Ϊ��ʾ
	m_scbarDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
	m_comboDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CTabDlg::OnTcnSelchangeTabctrl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	CRect tabRect; // ��ǩ�ؼ��ͻ�����λ�ô�С

	m_tab.GetClientRect(&tabRect);
	
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 25;
	tabRect.bottom -= 1;
	
	switch (m_tab.GetCurSel())
	{
	case 0:
		m_scbarDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
		m_comboDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		break;
	case 1:
		m_scbarDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		m_comboDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
		break;
	default:
		break;
	}
}
