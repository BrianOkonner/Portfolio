#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

LRESULT CALLBACK WindProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX  WndCls;
	static TCHAR szAppName[] = TEXT("ExoBrush");
	MSG         Msg;

	WndCls.cbSize        = sizeof(WndCls);
	WndCls.style         = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	WndCls.lpfnWndProc   = WindProcedure;
	WndCls.cbClsExtra    = 0;
	WndCls.cbWndExtra    = 0;
	WndCls.hInstance     = hInstance;
	WndCls.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	WndCls.hCursor       = LoadCursor(NULL, IDC_ARROW);
	WndCls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndCls.lpszMenuName  = NULL;
	WndCls.lpszClassName = szAppName;
	WndCls.hIconSm       = LoadIcon(hInstance, IDI_APPLICATION);
	RegisterClassEx(&WndCls);

	CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
		szAppName, TEXT("GDI Brushes Fundamentals"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, 400, 280,
		NULL, NULL, hInstance, NULL);

	while( GetMessage(&Msg, NULL, 0, 0) )
	{
		TranslateMessage(&Msg);
		DispatchMessage( &Msg);
	}

	return static_cast<int>(Msg.wParam);
}

LRESULT CALLBACK WindProcedure(HWND hWnd, UINT Msg,
							   WPARAM wParam, LPARAM lParam)
{
	HDC         hDC;
	PAINTSTRUCT Ps;
	HBRUSH      NewBrush;
	POINT       Pt[3];

	srand ( time(NULL) );

	/* generate secret number: */
	int RED = (int)rand() % 255 + 1;
	int YE = (int)rand() % 255 + 1;
	int BL = (int)rand() % 255 + 1;

	switch(Msg)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &Ps);		

		NewBrush = CreateSolidBrush(RGB(RED, YE, BL));
		SelectObject(hDC, NewBrush);

		// Top Triangle
		Pt[0].x = 125; Pt[0].y = 10;
		Pt[1].x =  95; Pt[1].y = 70;
		Pt[2].x = 155; Pt[2].y = 70;

		Polygon(hDC, Pt, 3);

		// Left Triangle
		Pt[0].x =  80; Pt[0].y =  80;
		Pt[1].x =  20; Pt[1].y = 110;
		Pt[2].x =  80; Pt[2].y = 140;

		Polygon(hDC, Pt, 3);

		// Bottom Triangle
		Pt[0].x =  95; Pt[0].y = 155;
		Pt[1].x = 125; Pt[1].y = 215;
		Pt[2].x = 155; Pt[2].y = 155;

		Polygon(hDC, Pt, 3);

		// Right Triangle
		Pt[0].x = 170; Pt[0].y =  80;
		Pt[1].x = 170; Pt[1].y = 140;
		Pt[2].x = 230; Pt[2].y = 110;

		Polygon(hDC, Pt, 3);

		DeleteObject(NewBrush);

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