#include <windows.h>
//Гулько Дмитрий 
// Редактирование КНА
//---------------------------------------------------------------------------
HWND hWnd;
LPCTSTR ClsName = L"GDIFund";
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
	HDC hDC;
	POINT FAR* lt=0; 
	PAINTSTRUCT Ps;
	switch(Msg)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &Ps);
		hPen = CreatePen(PS_SOLID, 10, RGB(100,200,0));//толщина карандаша
		SelectObject (hDC, hPen);
		Ellipse(hDC, 280, 160, 360, 320);
		 MoveToEx(hDC , 360, 200,lt);
		 LineTo(hDC , 480, 180);
		 MoveToEx(hDC, 280, 200,lt);
		 LineTo(hDC ,140, 180);
		 MoveToEx(hDC, 310, 320,lt);
		 LineTo(hDC ,140, 380);
		 MoveToEx(hDC, 330, 320,lt);
		 LineTo(hDC ,140, 380);
		 Rectangle(hDC , 260, 100, 380, 200);
		Ellipse(hDC, 284, 120, 308, 160);
		Ellipse(hDC, 332, 120, 356, 160);



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


//---------------------------------------------------------------------------