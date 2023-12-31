//��������� ������� 1 ���� 7 ������
#include <windows.h>
#include "shapes.h"

const double Pi = 3.1415926;
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
					PSTR szCmdLine, int iCmdShow)
{
	static wchar_t szAppName[] = L"Test Shapes" ;
	HWND        hwnd ;
	MSG         msg ;
	WNDCLASSEX  wndclass ;

	wndclass.cbSize        = sizeof (wndclass) ;
	wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
	wndclass.lpfnWndProc   = WndProc ;
	wndclass.cbClsExtra    = 0 ;
	wndclass.cbWndExtra    = 0 ;
	wndclass.hInstance     = hInstance ;
	wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
	wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
	wndclass.lpszMenuName  = NULL ;
	wndclass.lpszClassName = szAppName ;
	wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;

	RegisterClassEx (&wndclass) ;

	hwnd = CreateWindow (szAppName,        // window class name
		L"Shapes Class Test",   // window caption
		WS_OVERLAPPEDWINDOW,     // window style
		CW_USEDEFAULT,           // initial x position
		CW_USEDEFAULT,           // initial y position
		CW_USEDEFAULT,           // initial x size
		CW_USEDEFAULT,           // initial y size
		NULL,                    // parent window handle
		NULL,                    // window menu handle
		hInstance,               // program instance handle
		NULL) ;		   // creation parameters

	ShowWindow (hwnd, iCmdShow) ;
	UpdateWindow (hwnd) ;

	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg) ;
		DispatchMessage (&msg) ;
	}
	return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc ;
	PAINTSTRUCT ps ;
	RECT        rect ;
	POINT		p,p1,p2,p3;
	p1.x = 50;
	p1.y = 35;
	p2.x = 350;
	p2.y = 250;
	p3.x = 50;
	p3.y = 250;
	static BOOL  fBlocking;
	static KTriangleFilled tr(p1,p3,p2,RGB(rand()%255,rand()%255,rand()%255));
	static KCirclePunched cir(50,p2,15);
	switch (iMsg)
	{
	case WM_CREATE :
		return 0 ;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_DOWN:
			tr.SetColor(RGB(rand()%255,rand()%255,rand()%255));
			tr.Shift(0,5);
			cir.Shift(0,5);
			InvalidateRect(hwnd,NULL,true);
			break;

		case VK_UP:
			tr.SetColor(RGB(rand()%255,rand()%255,rand()%255));
			tr.Shift(0,-5);
			cir.Shift(0,-5);
			InvalidateRect(hwnd,NULL,true);
			break;

		case VK_RIGHT:
			tr.SetColor(RGB(rand()%255,rand()%255,rand()%255));
			tr.Shift(5,0);
			cir.Shift(5,0);
			InvalidateRect(hwnd,NULL,true);
			break;

		case VK_LEFT:
			tr.SetColor(RGB(rand()%255,rand()%255,rand()%255));
			tr.Shift(-5,0);
			cir.Shift(-5,0);
			InvalidateRect(hwnd,NULL,true);
			break;

		case VK_INSERT:
			tr.SetColor(RGB(rand()%255,rand()%255,rand()%255));
			tr.Show();
			cir.Show();
			InvalidateRect(hwnd,NULL,true);
			break;

		case VK_DELETE:
			tr.SetColor(RGB(rand()%255,rand()%255,rand()%255));
			tr.Hide();
			cir.Hide();
			InvalidateRect(hwnd,NULL,true);
			break;

		case VK_HOME:
			tr.SetColor(RGB(rand()%255,rand()%255,rand()%255));
			tr.Explode(1.1);
			cir.Explode(1.1);
			InvalidateRect(hwnd,NULL,true);
			break;

		case VK_END:
			tr.SetColor(RGB(rand()%255,rand()%255,rand()%255));
			tr.Explode(0.9);	
			cir.Explode(0.9);
			InvalidateRect(hwnd,NULL,true);
			break;
		}

	case WM_PAINT :
		hdc = BeginPaint (hwnd, &ps) ;
		GetClientRect (hwnd, &rect) ;
		cir.Explode(1);
		tr.Draw(hdc);
		cir.Draw(hdc);
		EndPaint (hwnd, &ps) ;
		return 0 ;

	case WM_DESTROY :
		PostQuitMessage (0) ;
		return 0 ;
	}

	return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}