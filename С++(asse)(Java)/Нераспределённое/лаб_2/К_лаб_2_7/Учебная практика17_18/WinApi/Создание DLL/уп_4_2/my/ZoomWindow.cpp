#include "afxwin.h"
#include "ZoomWindow.h"

CZoomWindow::CZoomWindow()
{
 win=CSize(1,1);
 view=CSize(1,1);
}

CZoomWindow::~CZoomWindow()
{
}

void CZoomWindow::ZoomIn()  // больше
{
 if (win==CSize(1,1)) view+=CSize(1,1);	
 else win-=CSize(1,1);
}

void CZoomWindow::ZoomOut() // меньше
{
 if (view==CSize(1,1)) win+=CSize(1,1);
else view-=CSize(1,1);
}

CSize CZoomWindow::GetWin()
{ 
 return win;
}

CSize CZoomWindow::GetView()
{
 return view;
}
