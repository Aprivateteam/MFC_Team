#pragma once
#include "afxwin.h"


// CComboDlg �Ի���

class CComboDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CComboDlg)

public:
	CComboDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CComboDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMBO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboWeb;
	afx_msg void OnCbnSelchangeWebCombo();
	virtual BOOL OnInitDialog();
};
