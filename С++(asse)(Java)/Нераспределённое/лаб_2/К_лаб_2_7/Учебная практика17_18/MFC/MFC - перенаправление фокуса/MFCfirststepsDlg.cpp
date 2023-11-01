// MFCfirststepsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCfirststeps.h"
#include "MFCfirststepsDlg.h"
#include <vector>
#include "Dlg.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



bool line    = false;
bool ellipse = false;

CPoint point_1; 
CPoint point_2; 
bool f = true;


vector <CPoint> line_vector;


vector <CPoint> ellipse_vector;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCfirststepsDlg dialog

CMFCfirststepsDlg::CMFCfirststepsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCfirststepsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCfirststepsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCfirststepsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCfirststepsDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_STATIC_OUTPUT, staticOutput);
}

BEGIN_MESSAGE_MAP(CMFCfirststepsDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCfirststepsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_PAINT_0, OnLine)
	ON_COMMAND(ID_PAINT_1, OnEllipse)
	ON_COMMAND(ID_MENU_EXIT, OnMenuExit)
	ON_COMMAND(ID_MENU_DIALOG, OnMenuDialog)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCfirststepsDlg message handlers

BOOL CMFCfirststepsDlg::OnInitDialog()
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

void CMFCfirststepsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCfirststepsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		//---------------------------------------
		// перерисовываем линии

		//Создать объект контекста устройства(DC)
		CPaintDC dc(this); 

		for(int i = 0; i < (line_vector.capacity() / 2); i++)
		{
			
			//Создать новое перо
			CPen MyNewPen;
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(0,0,255)); 

			//Выбрать перо
			CPen* pOriginalPen;
			pOriginalPen=dc.SelectObject(&MyNewPen);
			
			//Нарисовать линию
			dc.MoveTo(line_vector[2*i].x, line_vector[2*i].y);
			dc.LineTo(line_vector[2*i + 1].x, line_vector[2*i + 1].y);

			//Выбрать первоначальное перо
			dc.SelectObject(pOriginalPen);
		}

		// перерисовываем эллипсы
		for(i = 0; i < (ellipse_vector.capacity() / 2); i++)
		{
			//Создать объект контекста устройства(DC)
			//CPaintDC dc(this); 

			//Создать новое перо
			//CPen MyNewPen;
			//MyNewPen.CreatePen(PS_SOLID, 10, RGB(0,0,255)); 

			//Выбрать перо
			//CPen* pOriginalPen;
			//pOriginalPen=dc.SelectObject(&MyNewPen);

			
			

			//Создать новое перо
			CPen MyNewPen;
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(0,56,255)); 

			//Выбрать перо
			CPen* pOriginalPen;
			pOriginalPen=dc.SelectObject(&MyNewPen);



			CRect MyRectangle(ellipse_vector[2*i].x, ellipse_vector[2*i].y, ellipse_vector[2*i + 1].x, ellipse_vector[2*i + 1].y); 
			//CRect MyRectangle(50,50,100,100);

			//Нарисовать круг
			dc.Ellipse(&MyRectangle); 

			//Выбрать первоначальное перо
			dc.SelectObject(pOriginalPen);
		}
		//---------------------------------------

		CDialog::OnPaint();
		
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCfirststepsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCfirststepsDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MessageBox("Щелчок по кнопке");
	
}

void CMFCfirststepsDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnRButtonDown(nFlags, point);
	
	CString str = CTime::GetCurrentTime().Format("%m/%d/%y %H:%M:%S");
	char *s = new char[20];
	strcpy(s, str);

	CClientDC pDC(this);
	pDC.TextOut(point.x,point.y,s);
}

void CMFCfirststepsDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDblClk(nFlags, point);

	CClientDC pDC(this);
	pDC.TextOut(point.x,point.y,"двойной щелчок левой кнопки мыши");
}

void CMFCfirststepsDlg::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnRButtonDblClk(nFlags, point);

	Invalidate(TRUE);
}

void CMFCfirststepsDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnMouseMove(nFlags, point);

	CClientDC pDC(this);
	CRect r = new CRect;
	CWnd::GetClientRect(r);
	char *s = new char[16];

	if((point.x <= r.right - r.left)&&(point.y <= r.bottom - r.top))
	{
		sprintf(s,"%d %d",point.x,point.y);

		pDC.TextOut(r.right - r.left - 80, 30, "                 ");
		pDC.TextOut(r.right - r.left - 80, 30, s);
	}
}

void CMFCfirststepsDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);

	CClientDC pDC(this);
	CRect r = new CRect;
	CWnd::GetClientRect(r);

	pDC.TextOut(30,30,"             ");
	pDC.TextOut(30,30,nChar);

}

void CMFCfirststepsDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonUp(nFlags, point);

	//если линия
	if(line)
	{
		if(f)
		{
			point_2 = point;
			f = true;

			line_vector.push_back(point_1);
			line_vector.push_back(point_2);

			CClientDC pDC(this);

			CPen NewPen;
			NewPen.CreatePen(PS_SOLID, 10, RGB(0,0,255));

			CPen *OriginalPen;
			OriginalPen = pDC.SelectObject(&NewPen);

			pDC.MoveTo(point_1.x,point_1.y);
			pDC.LineTo(point_2.x,point_2.y);

			pDC.SelectObject(OriginalPen);
		}
	}

	if(ellipse)
	{
		if(f)
		{
			point_2 = point;
			f = true;

			ellipse_vector.push_back(point_1);
			ellipse_vector.push_back(point_2);

			CClientDC pDC(this);

			CPen NewPen;
			NewPen.CreatePen(PS_SOLID, 10, RGB(0,0,255));

			CPen *OriginalPen;
			OriginalPen = pDC.SelectObject(&NewPen);

			CRect MyRect(point_1.x, point_1.y, point_2.x, point_2.y);

			pDC.Ellipse(&MyRect);

			pDC.SelectObject(OriginalPen);


		}
	}
}

void CMFCfirststepsDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);

	if(line)
	{
		if(f)
		{
			point_1 = point;
			//f = false;
		}
	}

	if(ellipse)
	{
		if(f)
		{
			point_1 = point;
			//f = false;
		}
	}
}



void CMFCfirststepsDlg::OnLine() 
{
	// TODO: Add your command handler code here
	
	line = true;
	ellipse = false;
}

void CMFCfirststepsDlg::OnEllipse() 
{
	line = false;
	ellipse = true;
	
}

void CMFCfirststepsDlg::OnMenuExit() 
{
	OnOK();	
}

void CMFCfirststepsDlg::OnMenuDialog() 
{
	// TODO: Add your command handler code here
	CDlg m_dlg;

	m_dlg.DoModal();
}

int CMFCfirststepsDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
/*	static UINT indicators[] =  

{ 

ID_SEPARATOR, 

ID_INDICATOR_NUM, 

ID_INDICATOR_IDLE, 

ID_INDICATOR_TIME 

 };


if(!m_wndStatusBar.Create(this) && 

!m_wndStatusBar.SetIndicators(indicators, 

sizeof(indicators)/sizeof(UINT)))  

{ 

TRACEO("Ошибка при создании строки состоянияn");  

return -1;  

} */


	return 0;
}

BOOL CMFCfirststepsDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_KEYDOWN)
	{
		//Key was pressed
		//show info about key parameters		
		//this->staticOutput.Format("lParam %x, wParam %x, ",	pMsg->lParam, pMsg->wParam);
		this->staticOutput.Format("код клавиши: %x, клавиша: %c ",	pMsg->wParam, pMsg->wParam);
		
		this->UpdateData(FALSE);
		
		

	}

	return CDialog::PreTranslateMessage(pMsg);
}