
// MFC_learn.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "LoginDlg.h"


// CMFC_learnApp:
// �йش����ʵ�֣������ MFC_learn.cpp
//

class CMFC_learnApp : public CWinApp
{
public:
	CMFC_learnApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_learnApp theApp;