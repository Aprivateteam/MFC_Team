// TreeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "TreeDlg.h"
#include "afxdialogex.h"


// CTreeDlg �Ի���

IMPLEMENT_DYNAMIC(CTreeDlg, CDialogEx)

CTreeDlg::CTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TREE_DIALOG, pParent)
{

}

CTreeDlg::~CTreeDlg()
{
}

void CTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WEB_TREE, m_webTree);
}


BEGIN_MESSAGE_MAP(CTreeDlg, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_WEB_TREE, &CTreeDlg::OnTvnSelchangedWebTree)
	ON_NOTIFY(TVN_GETINFOTIP, IDC_WEB_TREE, &CTreeDlg::OnTvnGetInfoTipWebTree)
END_MESSAGE_MAP()


// CTreeDlg ��Ϣ�������


BOOL CTreeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	HICON hIcon[3];
	HTREEITEM hRoot;		// ���ĸ��ڵ�ľ��
	HTREEITEM hCataItem;	// �ɱ�ʾ��һ����ڵ�ľ��
	HTREEITEM hArtItem;		// �ɱ�ʾ��һ���½ڵ�ľ��

	// ����ͼ��
	hIcon[0] = theApp.LoadIcon(IDI_HOUSE_ICON);
	hIcon[1] = theApp.LoadIcon(IDI_BLUE_ICON);
	hIcon[2] = theApp.LoadIcon(IDI_RED_ICON);

	m_imageList.Create(32, 32, ILC_COLOR32, 3, 3);
	
	for (int i = 0;i < 3;i++) {
		m_imageList.Add(hIcon[i]);
	}
	
	//m_imageList.Add(hIcon[0]);

	// Ϊ���οؼ�����ͼ������
	m_webTree.SetImageList(&m_imageList, TVSIL_NORMAL);

	// ������ڵ�
	hRoot = m_webTree.InsertItem(_T("�ֲ�ʽ��Դ"));
	hCataItem = m_webTree.InsertItem(_T("ʵʱ�������"), 1, 1, hRoot, TVI_LAST);
	m_webTree.SetItemData(hCataItem, 1);
	hArtItem = m_webTree.InsertItem(_T("��ѹ"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 2);
	hArtItem = m_webTree.InsertItem(_T("����"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 3);
	hCataItem = m_webTree.InsertItem(_T("ʵʱ����ϵͳ"), 1, 1, hRoot, TVI_LAST);
	m_webTree.SetItemData(hCataItem, 4);
	hArtItem = m_webTree.InsertItem(_T("���ر���ϵͳ"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 5);
	hArtItem = m_webTree.InsertItem(_T("��������ϵͳ"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 6);
	hCataItem = m_webTree.InsertItem(_T("ͳ������"), 1, 1, hRoot, TVI_LAST);
	m_webTree.SetItemData(hCataItem, 7);
	hArtItem = m_webTree.InsertItem(_T("���յ���"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 8);
	hArtItem = m_webTree.InsertItem(_T("��ʷ����"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 9);
	hArtItem = m_webTree.InsertItem(_T("�����ʷ��¼"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 10);
	hCataItem = m_webTree.InsertItem(_T("���API"), 1, 1, hRoot, TVI_LAST);
	m_webTree.SetItemData(hCataItem, 11);
	hArtItem = m_webTree.InsertItem(_T("����ת������"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 12);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CTreeDlg::OnTvnSelchangedWebTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CString strText; // ���ڵ�ı�ǩ�ı��ַ���

	// ��ȡ��ǰѡ�нڵ�ľ��
	HTREEITEM hItem = m_webTree.GetSelectedItem();

	// ��ȡѡ�нڵ�ı�ǩ�ı��ַ���
	strText = m_webTree.GetItemText(hItem);
	// ���ַ�����ʾ���༭����
	SetDlgItemText(IDC_ITEM_SEL_EDIT, strText);
}


void CTreeDlg::OnTvnGetInfoTipWebTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVGETINFOTIP pGetInfoTip = reinterpret_cast<LPNMTVGETINFOTIP>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	NMTVGETINFOTIP* pTVTipInfo = (NMTVGETINFOTIP*)pNMHDR;
	HTREEITEM hRoot = m_webTree.GetRootItem();
	CString strText;

	if (pTVTipInfo->hItem == hRoot) {
		strText = _T("");
	}
	else {
		strText.Format(_T("%d"), pTVTipInfo->lParam);
	}

	wcscpy(pTVTipInfo->pszText, strText);
}
