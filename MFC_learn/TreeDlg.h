#pragma once
#include "afxcmn.h"


// CTreeDlg �Ի���

class CTreeDlg : public CDialogEx
{
	CImageList m_imageList;

	DECLARE_DYNAMIC(CTreeDlg)
	
public:
	CTreeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTreeDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_webTree;
	virtual BOOL OnInitDialog();
	afx_msg void OnTvnSelchangedWebTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnGetInfoTipWebTree(NMHDR *pNMHDR, LRESULT *pResult);
};
