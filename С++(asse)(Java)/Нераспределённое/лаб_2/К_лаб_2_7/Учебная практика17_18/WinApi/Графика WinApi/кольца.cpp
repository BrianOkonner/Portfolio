//как прикладная программа может изменить цвет пера в контексте устройства (DC),
// используя функцию GetStockObject или функции SetDCPenColor и  SetDCBrushColor.
//
//SelectObject(hdc,GetStockObject(DC_PEN));
//SetDCPenColor(hdc,RGB(00,0xff,00);
//Rectangle(0,0,20,20);
//SetDCPenColor(hdc,RGB(00,00,0xff));
//Rectangle(0,0,20,20)
//
//// Цвет кисти может быть изменен похожим способом. 
//SetDCPenColor  и SetDCBrushColor могут использоваться взаимозаменяемо 
// с GetStockObject, чтобы изменить текущий цвет. 
//
//SelectObject(hDC,GetStockObject(DC_BRUSH));
//SetDCBrushColor(hDC,0x0) 
//
//// Обеспечивает(Предоставляет) ту же самую гибкость как:
//
//SelectObject(hDC,GetStockOBject(BLACK_BRUSH));
//
//// Нет необходимости вызвать DeleteObject, чтобы удалить 
//// стандартные объекты. 
// 


#include <windows.h>
//Семашко Татьяна
HWND hWnd;
LPCTSTR ClsName = L"Олимпийские кольца";
LPCTSTR WindowCaption = L"GDI Fundamentals";
LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
//---------------------------------------------------------------------------
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine, int nCmdShow)
{
	MSG         Msg;
	WNDCLASSEX  WndClsEx;

	WndClsEx.cbSize        = sizeof(WNDCLASSEX);
	WndClsEx.style         = CS_HREDRAW | CS_VREDRAW;
	WndClsEx.lpfnWndProc   = WndProc;
	WndClsEx.cbClsExtra    = NULL;
	WndClsEx.cbWndExtra    = NULL;
	WndClsEx.hInstance     = hInstance;
	WndClsEx.hIcon         = LoadIcon(hInstance, IDI_APPLICATION);
	WndClsEx.hCursor       = LoadCursor(NULL, IDC_ARROW);
	WndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClsEx.lpszMenuName  = NULL;
	WndClsEx.lpszClassName = ClsName;
	WndClsEx.hIconSm       = LoadIcon(hInstance, IDI_APPLICATION);

	RegisterClassEx(&WndClsEx);

	hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
		ClsName,
		WindowCaption,
		WS_OVERLAPPEDWINDOW,
		100,
		120,
		640,
		480,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while( GetMessage(&Msg, NULL, 0, 0) )
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return 0;
}
//---------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam){
		 HPEN hPen;
		 HPEN hPen1;
		 HPEN hPen2;
		 HPEN hPen3;
		 HPEN hPen4;
	HDC hDC;
	PAINTSTRUCT Ps;
	HGDIOBJ obj;
	switch(Msg)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &Ps);
		hPen = CreatePen(PS_SOLID, 10, RGB(30,144,255));//толщина карандаша
		hPen1 = CreatePen(PS_SOLID, 10, RGB(0,0,0));
		hPen2 = CreatePen(PS_SOLID, 10, RGB(205,55,0));
		hPen3 = CreatePen(PS_SOLID, 10, RGB(255,215,0));
		hPen4 = CreatePen(PS_SOLID, 10, RGB(50,205,50));
		obj = SelectObject(hDC, (HGDIOBJ)GetStockObject(NULL_BRUSH));

		SelectObject (hDC, hPen);
		Ellipse(hDC, 100, 100, 250, 250); //синий

		SelectObject (hDC, hPen1);
		Ellipse(hDC, 260, 100, 410, 250); //черный

		SelectObject (hDC, hPen2);
		Ellipse(hDC, 420, 100, 570, 250); //красный
		
		SelectObject (hDC, hPen3);
		Ellipse(hDC, 180, 180, 330, 330); //желтый		

		SelectObject (hDC, hPen4);
		Ellipse(hDC, 340, 180, 490, 330); //зеленый

		EndPaint(hWnd, &Ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return 0;
	
}
