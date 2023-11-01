#include "afxwin.h"
#include "ScreenPos.h"

CScreenPos::CScreenPos()
{
 cpXY=CPoint(0,0);
}

CScreenPos::~CScreenPos()
{
}

CPoint CScreenPos::GetPoint()
{ 
	return cpXY;
}

void CScreenPos::MovePoint(CPoint cp)
{
	cpXY+=cp;
}
