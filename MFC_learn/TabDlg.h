#pragma once
#include "afxcmn.h"
#include "ScbarDlg.h"
#include "ComboDlg.h"


// CTabDlg �Ի���

class CTabDlg : public CDialogEx
{
	CScbarDlg m_scbarDlg;
	CComboDlg m_comboDlg;
	DECLARE_DYNAMIC(CTabDlg)

public:
	CTabDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTabDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabctrl(NMHDR *pNMHDR, LRESULT *pResult);
};
