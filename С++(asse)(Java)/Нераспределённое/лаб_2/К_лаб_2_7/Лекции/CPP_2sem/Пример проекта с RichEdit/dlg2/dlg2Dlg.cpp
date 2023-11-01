// dlg2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "dlg2.h"
#include "dlg2Dlg.h"
#include "fstream"
#include "cstdlib"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cdlg2Dlg dialog




Cdlg2Dlg::Cdlg2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cdlg2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdlg2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, RC);
}

BEGIN_MESSAGE_MAP(Cdlg2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &Cdlg2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cdlg2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cdlg2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cdlg2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Cdlg2Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// Cdlg2Dlg message handlers

BOOL Cdlg2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cdlg2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cdlg2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cdlg2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cdlg2Dlg::OnBnClickedButton1()
{
	// Добавление по 2 строки
	CString strText("Hello\n  Hello\n");
	int iNewSelBegin = RC.GetTextLength();
    int iNewSelEnd = iNewSelBegin + strText.GetLength ();

    RC.SetSel(iNewSelEnd, iNewSelEnd);
    RC.ReplaceSel(strText );
    RC.SetSel(0, 0);

}

void Cdlg2Dlg::OnBnClickedButton2()
{
	// //Изменение шрифта выделенного фрагмента

	CHARFORMAT cf;
	RC.GetSelectionCharFormat(cf);

	CFontDialog dlg(cf);

  if (dlg.DoModal() == IDOK)
  {
		dlg.GetCharFormat(cf);

		RC.SetSelectionCharFormat(cf);
	}

	RC.SetFocus();

}

void Cdlg2Dlg::OnBnClickedButton3()
{
	//Изменение строк - дописывание впереди //
	CString str,str2;
	RC.GetWindowText(str);
	str2="//";
	for(int i=0; i<str.GetLength(); i++)
{
str2+=str[i];
if(str[i]=='\n')
str2+="//";
}
RC.SetWindowText(str2);

}

void Cdlg2Dlg::OnBnClickedButton4()
{
	// Отображение текстового файла
	ifstream in("in.txt");
	in.seekg(0, ios::end);
	int length = in.tellg();
	in.seekg(0, ios::beg);
	char * buffer;
	// распределяем память под файл
	buffer =  new char[length+1];

	// читаем файл
	memset(buffer,0,length+1);
	in.read(buffer,length);

	in.close();
	RC.Clear();
	CString	str2(buffer);
	RC.SetWindowText(str2);
		delete []buffer;

}

void Cdlg2Dlg::OnBnClickedButton5()
{
	// сохранение в текстовом файле
	ofstream out("out.txt");
	wchar_t * bufferw;
	CString str,str2;
	RC.GetWindowText(str);
	
	bufferw =  str.GetBuffer();
	int length = RC.GetTextLength();
	char * buffer =  new char[length+1];
		memset(buffer,0,length+1);
	for(int i=0;i<=length;i++)
		buffer[i]=bufferw[i];
	out.write((char*)buffer,length);

	out.close();

}
