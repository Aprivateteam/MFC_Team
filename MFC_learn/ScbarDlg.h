#pragma once
#include "afxwin.h"


// CScbarDlg �Ի���

class CScbarDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScbarDlg)

public:
	CScbarDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CScbarDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCBAR_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CScrollBar m_horiScrollbar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
};
