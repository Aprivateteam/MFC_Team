// PictureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "PictureDlg.h"
#include "afxdialogex.h"


// CPictureDlg �Ի���

IMPLEMENT_DYNAMIC(CPictureDlg, CDialogEx)

CPictureDlg::CPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PICTURE_DIALOG, pParent)
{

}

CPictureDlg::~CPictureDlg()
{
}

void CPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPictureDlg, CDialogEx)
END_MESSAGE_MAP()


// CPictureDlg ��Ϣ�������
