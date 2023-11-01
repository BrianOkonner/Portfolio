#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

LRESULT CALLBACK WindProcedure(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX  WndCls;
	static TCHAR szAppName[] = TEXT("ExoBrush");
	MSG         Msg;

	WndCls.cbSize = sizeof(WndCls);
	WndCls.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	WndCls.lpfnWndProc = WindProcedure;
	WndCls.cbClsExtra = 0;
	WndCls.cbWndExtra = 0;
	WndCls.hInstance = hInstance;
	WndCls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndCls.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndCls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndCls.lpszMenuName = NULL;
	WndCls.lpszClassName = szAppName;
	WndCls.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	RegisterClassEx(&WndCls);

	CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
		szAppName, TEXT("GDI Brushes Fundamentals"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, 400, 280,
		NULL, NULL, hInstance, NULL);

	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return static_cast<int>(Msg.wParam);
}
LRESULT CALLBACK WindProcedure(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc, backDC;
    PAINTSTRUCT ps;

    static POINT prevPt;

    // Draw or Erase
    static bool isDraw = false;
    static bool isErase = false;

    // Select Pen Color
    static int selectColor = 1;

    // Color Pen(R, G, B) and Current Pen
    static HPEN redPen;
    static HPEN greenPen;
    static HPEN bluePen;
    static HPEN* currentPen = &redPen;

    switch (iMessage)
    {
    case WM_CREATE:
    {
        redPen = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));
        greenPen = CreatePen(PS_SOLID, 4, RGB(0, 255, 0));
        bluePen = CreatePen(PS_SOLID, 4, RGB(0, 0, 255));
        return 0L;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0L;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        return 0L;
    case WM_LBUTTONDOWN:
        prevPt.x = LOWORD(lParam);
        prevPt.y = HIWORD(lParam);
        isDraw = true;
        return 0L;
    case WM_LBUTTONUP:
        isDraw = false;
        return 0L;
    case WM_MOUSEMOVE:
    {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);
        if (isDraw)
        {
            hdc = GetDC(hWnd);

            HPEN OldPen = (HPEN)SelectObject(hdc, *currentPen);
            MoveToEx(hdc, prevPt.x, prevPt.y, NULL);
            LineTo(hdc, x, y);

            prevPt.x = x;
            prevPt.y = y;
            DeleteObject(OldPen);
            ReleaseDC(hWnd, hdc);
        }
    }
    return 0L;
    case WM_RBUTTONDOWN:
        isErase = true;
        return 0L;
    case WM_RBUTTONUP:
        isErase = false;
        return 0L;
    case WM_MOUSEWHEEL:
        if (selectColor > 3)
            selectColor = 1;

        if (selectColor == 1)   // Red
            currentPen = &redPen;
        else if (selectColor == 2)
            currentPen = &greenPen;
        else if (selectColor == 3)
            currentPen = &bluePen;

        selectColor++;
        return 0L;
    }

    return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
