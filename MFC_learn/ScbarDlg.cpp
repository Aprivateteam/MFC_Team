// ScbarDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "ScbarDlg.h"
#include "afxdialogex.h"


// CScbarDlg �Ի���

IMPLEMENT_DYNAMIC(CScbarDlg, CDialogEx)

CScbarDlg::CScbarDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SCBAR_DIALOG1, pParent)
{

}

CScbarDlg::~CScbarDlg()
{
}

void CScbarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_horiScrollbar);

}


BEGIN_MESSAGE_MAP(CScbarDlg, CDialogEx)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CScbarDlg ��Ϣ�������


void CScbarDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int pos = m_horiScrollbar.GetScrollPos(); // ��ȡˮƽ��������ǰλ��

	switch(nSBCode)
	{
	// ������� pos -= 1
	case SB_LINELEFT:
		pos -= 1;
		break;

	//���ҹ��� pos += 1
	case SB_LINERIGHT:
		pos += 1;
		break;

	//�������һҳ pos -= 10
	case SB_PAGELEFT:
		pos -= 10;
		break;
	// ������ҹ���һҳ��pos +=10
	case SB_PAGERIGHT:
		pos += 10;
		break;
	// �������������ˣ���posΪ1
	case SB_LEFT:
		pos = 1;
		break;
	//������������Ҷˣ���posΪ100
	case SB_RIGHT:
		pos = 100;
		break;
	// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ
	case SB_THUMBPOSITION:
		pos = nPos;
		break;

	// �����m_horiScrollbar.SetScrollPos(pos);
	// ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ  
	default:
		SetDlgItemInt(IDC_HSCROLL_EDIT, pos);
		return;
	}
	// ���ù�����λ��
	m_horiScrollbar.SetScrollPos(pos);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL CScbarDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_horiScrollbar.SetScrollRange(1, 100);
	m_horiScrollbar.SetScrollPos(20);
	SetDlgItemInt(IDC_HSCROLL_EDIT, 20);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
