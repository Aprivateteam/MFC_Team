#pragma once
#include "afxcmn.h"


// CListCtrlDlg �Ի���

class CListCtrlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CListCtrlDlg)

public:
	CListCtrlDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CListCtrlDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTCTRL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_programLangList;
	afx_msg void OnNMClickProgramLangList(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
};
