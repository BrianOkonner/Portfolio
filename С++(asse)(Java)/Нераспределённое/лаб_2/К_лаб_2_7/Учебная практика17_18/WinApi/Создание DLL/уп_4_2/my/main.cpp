#include <afxwin.h> // MFC Основные и стандартные компоненты
#include <afxext.h> // MFC Расширения
#include "ScreenPos.h"
#include "ZoomWindow.h"
#include "ClassShapes.h"
#define IDC_BUTTON1 100 // Идентификатор кнопки
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class CMyPaintDC: public CPaintDC
{
public:
 CMyPaintDC(CWnd* pWnd);
 void DrawCross(int iPosX, int iPosY);
 void DrawTriangle(CPaintDC &dc,ClassPoint& p1,ClassPoint& p2,ClassPoint& p3);
 void DrawCircle(CPaintDC &dc,int r,ClassPoint& p);
 void DrawTriangleFilled(CPaintDC &dc,ClassPoint& p1,ClassPoint& p2,ClassPoint& p3,int color);
 void DrawCircleFilled(CPaintDC &dc,int r,ClassPoint& p,int color);
};
CMyPaintDC::CMyPaintDC(CWnd* pWnd):CPaintDC(pWnd)           
{
}
void CMyPaintDC::DrawCross(int iPosX, int iPosY)
{
	MoveTo(iPosX-50,iPosY);
	LineTo(iPosX+50,iPosY);
	MoveTo(iPosX,iPosY-50);
	LineTo(iPosX,iPosY+50);
}
void CMyPaintDC::DrawCircle(CPaintDC &dc,int r,ClassPoint& p)
{
	KCircle c(r,p);
	c.Draw(dc);
}
void CMyPaintDC::DrawCircleFilled(CPaintDC &dc,int r,ClassPoint& p,int color)
{
	KCircleFilled cf(r,p,color);
	cf.Draw(dc);
}
void CMyPaintDC::DrawTriangle(CPaintDC &dc,ClassPoint& p1,ClassPoint& p2,ClassPoint& p3)
{
	KTriangle t(p1,p2,p3);
	t.Draw(dc);
}
void CMyPaintDC::DrawTriangleFilled(CPaintDC &dc,ClassPoint& p1,ClassPoint& p2,ClassPoint& p3,int color)
{
	KTriangleFilled tf(p1,p2,p3,color);
	tf.Draw(dc);
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class CMainWnd : public CFrameWnd
 {
 public:
   CMainWnd(); 
   afx_msg void OnLButtonDblClk( UINT, CPoint ); 
   afx_msg void OnRButtonDblClk( UINT, CPoint );
   afx_msg void OnKeyDown( UINT, UINT, UINT );
   afx_msg void OnLButtonUp( UINT, CPoint cp);
   afx_msg void OnLButtonDown( UINT, CPoint cp);
   int OnCreate(LPCREATESTRUCT lpCreateStruct);// эта функция вызываеться при создании окна
   afx_msg void OnPaint();
 private:
	 CScreenPos position;
	 BOOL blFlagMove;
	 CPoint TempPoint;

	 CZoomWindow zoomWin;

	 CButton* Button1; // Указатель на обьект кнопка

	 DECLARE_MESSAGE_MAP(); // таблица откликов
 };

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

CMainWnd::CMainWnd()
{
   Create(NULL,"my",WS_OVERLAPPEDWINDOW,rectDefault,NULL,NULL); // Создать окно программы
   blFlagMove=false;
   Button1= new CButton;
   //Button1->Create("Button1",WS_CHILD|WS_VISIBLE|SS_CENTER,CRect(120,10,220,50),this,IDC_BUTTON1);

}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd) 
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()

	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()

	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void CMainWnd::OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{		
	switch(nChar)
	{
	case 39://->
		{				
			CPoint cp(10,0);
			position.MovePoint(cp);
			Invalidate(true);
			break;
		}
	case 38://^
		{
			CPoint cp(0,-10);
			position.MovePoint(cp);
			Invalidate(true);
			break;
		}
	case 37://<-
		{			
			CPoint cp(-10,0);
			position.MovePoint(cp);
			Invalidate(true);
			break;
		}
	case 40:
		{			
			CPoint cp(0,10);
			position.MovePoint(cp);
			Invalidate(true);
			break;		
		}
	case 34://-
		{			
			zoomWin.ZoomOut();
			Invalidate(true);
			break;
		}
	case 33://+
		{			
			zoomWin.ZoomIn();
			Invalidate(true);
			break;		
		}
	}	
	//36 -Home, 35-end,34-pgdn

}

void CMainWnd::OnRButtonDblClk( UINT, CPoint )
{
	zoomWin.ZoomOut();
	Invalidate(true);
}
void CMainWnd::OnLButtonDblClk( UINT, CPoint)
{
	zoomWin.ZoomIn();
	Invalidate(true);
 }
int CMainWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
 {
  if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
  return -1;

  return 0;
 }
void CMainWnd::OnPaint()
{
    CMyPaintDC dc(this);
	CPen MyPen(PS_SOLID,1,RGB(0,0,0));
	dc.SetViewportOrg(position.GetPoint());

	dc.SetMapMode( MM_ANISOTROPIC  );
 	dc.SetViewportOrg(position.GetPoint());				
	dc.SetViewportExt(zoomWin.GetView());
	dc.SetWindowExt(zoomWin.GetWin());

	dc.SelectObject(MyPen);

	ClassPoint p1(200,200);
	ClassPoint p2(100,100);
	dc.DrawCircleFilled(dc,20,p2,RGB(0,255,0));
	p2+=p1;
	ClassPoint p3(300,200);
	p1+=p3;
	dc.DrawTriangleFilled(dc,p1,p2,p3,RGB(255,0,0));
	
}
void CMainWnd::OnLButtonDown( UINT, CPoint cp)
{
	blFlagMove=true;
	TempPoint=cp;
}
void CMainWnd::OnLButtonUp( UINT, CPoint cp)
{
 if (blFlagMove)
 {
   position.MovePoint(cp-TempPoint);
   Invalidate(true);
 }
 blFlagMove=false;
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class CMyApp : public CWinApp
{

public:
CMyApp(); // конструктор по умолчанию
virtual BOOL InitInstance(); // стандартная инициализация
};

CMyApp::CMyApp() // конструктор главного класса приложения
{}

BOOL CMyApp::InitInstance() // стандартная инициализация
{ 
	m_pMainWnd=new CMainWnd();
	ASSERT(m_pMainWnd);
	m_pMainWnd->ShowWindow(SW_SHOW); // Показать окно
	m_pMainWnd->UpdateWindow(); // Обновить окно
	return TRUE; // Вернуть что все нормально 
};

CMyApp theApp; // запуск приложения
