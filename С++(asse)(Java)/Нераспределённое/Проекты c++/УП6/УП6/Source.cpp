

#include "Header.h"

#define MoveTo(hdc, x, y) MoveToEx (hdc, x, y, NULL)
HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0)), hPen1 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0)), hPen2 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255)), hPen3 = CreatePen(PS_SOLID | PS_DASHDOT, 1, RGB(50, 100, 0));
HFONT font;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Вход в программу

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, // Точка входа в программу
	PSTR szCmdLine, int iCmdShow)
{
	font = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Times New Roman"));
	static LPCWSTR szAppName = TEXT("Connect");
	HWND        hwnd;
	MSG         msg
	WNDCLASSEX  wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = NULL;


	RegisterClassEx(&wndclass);
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		szAppName,
		TEXT("Tank"), WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZE | WS_OVERLAPPED,
		CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
		NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL,  // NULL - каждое сообщение 
		0,						   // Минимальное значение опис. сообщ.	
		0))						   // Максимальное значение опис. сообщ.
	{
		TranslateMessage(&msg);	   // Преобразования сообщения от клавиатуры
		DispatchMessage(&msg);	   // Пеpедача сообщения для функции окна
	}


	return msg.wParam;
}
Tank tank;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{  // wparam для int and handle // lparam - pointers
	HDC          hdc;
	PAINTSTRUCT  ps;
	RECT rect;

	static HANDLE hFile = NULL;
	

	static bool error = 0;
	static double sx = 0, sy = 0;

	static char text[2] = { ' ','\0' };
	static int mousex = 10, mousey = 10, lastx = 0, lasty = 0;
	tank.setTank(sx/10,sy/10,5);
	switch (iMsg)
	{

	case WM_CREATE:
		sx = LOWORD(lParam); //ширина
		sy = HIWORD(lParam); //высота
		break;
	case WM_SIZE:
		sx = LOWORD(lParam); //ширина
		sy = HIWORD(lParam); //высота
		break;
	
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 37:
			tank.move_left();
			//InvalidateRect(hwnd,NULL,0);
			hdc = GetDC(hwnd);
			Rectangle(hdc, 0, 0, sx, sy);
			SelectObject(hdc, hBrush);
			tank.paint(hdc, tank.get_center_x(), tank.get_center_y());
			ReleaseDC(hwnd, hdc);
			//SendMessage(hwnd, WM_PAINT, wParam, lParam);
			break;
		case 38:
			tank.move_top();
			//InvalidateRect(hwnd, NULL, 0);
			hdc = GetDC(hwnd);
			Rectangle(hdc, 0, 0, sx, sy);
			SelectObject(hdc, hBrush);
			tank.paint(hdc, tank.get_center_x(), tank.get_center_y());
			ReleaseDC(hwnd, hdc);
			break;
		case 39:
			tank.move_right();
			//InvalidateRect(hwnd, NULL, 0);
			hdc = GetDC(hwnd);
			Rectangle(hdc, 0, 0, sx, sy);
			SelectObject(hdc, hBrush);
			tank.paint(hdc, tank.get_center_x(), tank.get_center_y());
			ReleaseDC(hwnd, hdc);
			break;
		case 40:
			tank.move_bottom();
			//InvalidateRect(hwnd, NULL, 0);
			hdc = GetDC(hwnd);
			Rectangle(hdc, 0, 0, sx, sy);
			SelectObject(hdc, hBrush);
			tank.paint(hdc, tank.get_center_x(), tank.get_center_y());
			ReleaseDC(hwnd, hdc);
			break;

		default:
			break;
		}break;


	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);


		SelectObject(hdc, hBrush);
		tank.paint(hdc,100,100);



		EndPaint(hwnd, &ps); // Указание конца pаскpаски в Wnd
		return 0;

	case WM_DESTROY: // Случай поступления сообщения WM_DESTROY
		PostQuitMessage(0); // Напpавление сообщения wm_Quit в ответ на сообщение wm_Destroy
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam); // Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)
}
