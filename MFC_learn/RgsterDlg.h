#pragma once


// CRgsterDlg �Ի���

class CRgsterDlg : public CDialogEx
{

	DECLARE_DYNAMIC(CRgsterDlg)

public:
	CRgsterDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRgsterDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGSTER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
