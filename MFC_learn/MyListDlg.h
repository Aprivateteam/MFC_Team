#pragma once
#include "afxwin.h"


// CMyListDlg �Ի���

class CMyListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyListDlg)

public:
	CMyListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyListDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listBox;
	afx_msg void OnLbnSelchangeList1();
	virtual BOOL OnInitDialog();
};
