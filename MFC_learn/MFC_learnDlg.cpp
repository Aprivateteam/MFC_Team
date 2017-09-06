
// MFC_learnDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "MFC_learnDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_learnDlg �Ի���




CMFC_learnDlg::CMFC_learnDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_learnDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pListDlg = NULL;
	m_pComboDlg = NULL;
	m_pScbarDlg = NULL;
	m_pPictureDlg = NULL;
	m_pListCtrlDlg = NULL;
	m_pTreeDlg = NULL;
	m_pTabDlg = NULL;

}
CMFC_learnDlg::~CMFC_learnDlg()
{
	if (m_pListDlg != NULL) {
		delete m_pListDlg;
	}
	if (m_pComboDlg != NULL) {
		delete m_pComboDlg;
	}
	if (m_pScbarDlg != NULL) {
		delete m_pScbarDlg;
	}
	if(m_pPictureDlg != NULL) {
		delete m_pPictureDlg;
	}
	if (m_pListCtrlDlg != NULL) {
		delete m_pListCtrlDlg;
	}
	if (m_pTreeDlg != NULL) {
		delete m_pTreeDlg;
	}
	if (m_pTabDlg != NULL) {
		delete m_pTabDlg;
	}
}

void CMFC_learnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_D_CHECK1, m_check1);
	DDX_Control(pDX, IDC_D_CHECK2, m_check2);
	DDX_Control(pDX, IDC_D_CHECK3, m_check3);
	DDX_Control(pDX, IDC_D_CHECK4, m_check4);
	DDX_Control(pDX, IDC_D_CHECK5, m_check5);
	DDX_Control(pDX, IDC_D_CHECK6, m_check6);
}

BEGIN_MESSAGE_MAP(CMFC_learnDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_PORTAL_RADIO, &CMFC_learnDlg::OnBnClickedPortalRadio)
	ON_BN_CLICKED(IDC_FORUM_RADIO, &CMFC_learnDlg::OnBnClickedForumRadio)
	ON_BN_CLICKED(IDC_BLOG_RADIO, &CMFC_learnDlg::OnBnClickedBlogRadio)
	ON_BN_CLICKED(IDOK, &CMFC_learnDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_LIST_BUTTON, &CMFC_learnDlg::OnBnClickedListButton)
	ON_BN_CLICKED(IDC_COMBO_BUTTON, &CMFC_learnDlg::OnBnClickedComboButton)
	ON_BN_CLICKED(IDC_SCBAR_BUTTON, &CMFC_learnDlg::OnBnClickedScbarButton)
	ON_BN_CLICKED(IDC_PICTURE_BUTTON, &CMFC_learnDlg::OnBnClickedPictureButton)
	ON_BN_CLICKED(IDC_LISTCTRL_BUTTON, &CMFC_learnDlg::OnBnClickedListctrlButton)
	ON_BN_CLICKED(IDC_Tree_BUTTON, &CMFC_learnDlg::OnBnClickedTreeButton)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_learnDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFC_learnDlg ��Ϣ�������

BOOL CMFC_learnDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CheckDlgButton(IDC_PORTAL_RADIO, 1);
	OnBnClickedPortalRadio();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_learnDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_learnDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		/*CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		CDC dcBmp;
		dcBmp.CreateCompatibleDC(&dc);
		CBitmap bmp;
		bmp.LoadBitmapW(IDB_BITMAP1);
		BITMAP m_bitmap;
		bmp.GetBitmap(&m_bitmap);
		CBitmap *pbmpOld=dcBmp.SelectObject(&bmp);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);
		*/
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_learnDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





HBRUSH CMFC_learnDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	/*CBitmap m_bmp;
	CBrush m_brush;
	m_bmp.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP1));
	m_brush.CreatePatternBrush(&m_bmp);
	if (nCtlColor == CTLCOLOR_DLG){
		return m_brush;
	}*/
	return hbr;
}

void CMFC_learnDlg::initAllCheckBoxStatus()
{
	// ȫ������
	m_check1.EnableWindow(FALSE);
	m_check2.EnableWindow(FALSE);
	m_check3.EnableWindow(FALSE);
	m_check4.EnableWindow(FALSE);
	m_check5.EnableWindow(FALSE);
	m_check6.EnableWindow(FALSE);
	
	// ȫ����ѡ��
	m_check1.SetCheck(0);
	m_check2.SetCheck(0);
	m_check3.SetCheck(0);
	m_check4.SetCheck(0);
	m_check5.SetCheck(0);
	m_check6.SetCheck(0); 

}
void CMFC_learnDlg::OnBnClickedPortalRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	initAllCheckBoxStatus();
	m_check2.EnableWindow(TRUE);
	m_check5.EnableWindow(TRUE); 
	SetDlgItemText(IDC_WEBSITE_SEL_EDIT,CString(" "));

}


void CMFC_learnDlg::OnBnClickedForumRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	initAllCheckBoxStatus();
	m_check3.EnableWindow(TRUE);
	m_check6.EnableWindow(TRUE); 
	SetDlgItemText(IDC_WEBSITE_SEL_EDIT,CString(" "));
}


void CMFC_learnDlg::OnBnClickedBlogRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	initAllCheckBoxStatus();
	m_check1.EnableWindow(TRUE);
	m_check4.EnableWindow(TRUE); 
	SetDlgItemText(IDC_WEBSITE_SEL_EDIT,CString(" "));
}


void CMFC_learnDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strWebsiteSel;

	if(m_check1.GetCheck() == 1){
		strWebsiteSel += _T("������ ");
	}
	if(m_check2.GetCheck() == 1){
		strWebsiteSel += _T("������̳ ");
	}
	if(m_check3.GetCheck() == 1){
		strWebsiteSel += _T("���� ");
	}
	if(m_check4.GetCheck() == 1){
		strWebsiteSel += _T("�������� ");
	}
	if(m_check5.GetCheck() == 1){
		strWebsiteSel += _T("���� ");
	}
	if(m_check6.GetCheck() == 1){
		strWebsiteSel += _T("�������̳ ");
	}
	SetDlgItemText(IDC_WEBSITE_SEL_EDIT, strWebsiteSel);

}


void CMFC_learnDlg::OnBnClickedListButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pListDlg == NULL) {
		m_pListDlg = new CMyListDlg();
		m_pListDlg->Create(IDD_LIST_DIALOG, this);
	}
	m_pListDlg->ShowWindow(SW_SHOW);
}


void CMFC_learnDlg::OnBnClickedComboButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pComboDlg == NULL) {
		m_pComboDlg = new CComboDlg();
		m_pComboDlg->Create(IDD_COMBO_DIALOG, this);
	}
	m_pComboDlg->ShowWindow(SW_SHOW);
}


void CMFC_learnDlg::OnBnClickedScbarButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pScbarDlg == NULL) {
		m_pScbarDlg = new CScbarDlg();
		m_pScbarDlg->Create(IDD_SCBAR_DIALOG1, this);
	}
	m_pScbarDlg->ShowWindow(SW_SHOW);
}


void CMFC_learnDlg::OnBnClickedPictureButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pPictureDlg == NULL) {
		m_pPictureDlg = new CPictureDlg();
		m_pPictureDlg->Create(IDD_PICTURE_DIALOG, this);
	}
	m_pPictureDlg->ShowWindow(SW_SHOW);
}


void CMFC_learnDlg::OnBnClickedListctrlButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pListCtrlDlg == NULL) {
		m_pListCtrlDlg = new CListCtrlDlg();
		m_pListCtrlDlg->Create(IDD_LISTCTRL_DIALOG, this);
	}
	m_pListCtrlDlg->ShowWindow(SW_SHOW);
}


void CMFC_learnDlg::OnBnClickedTreeButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pTreeDlg == NULL) {
		m_pTreeDlg = new CTreeDlg();
		m_pTreeDlg->Create(IDD_TREE_DIALOG, this);
	}
	m_pTreeDlg->ShowWindow(SW_SHOW);
}


void CMFC_learnDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pTabDlg == NULL) {
		m_pTabDlg = new CTabDlg();
		m_pTabDlg->Create(IDD_TAB_DIALOG, this);
	}
	m_pTabDlg->ShowWindow(SW_SHOW);
}
