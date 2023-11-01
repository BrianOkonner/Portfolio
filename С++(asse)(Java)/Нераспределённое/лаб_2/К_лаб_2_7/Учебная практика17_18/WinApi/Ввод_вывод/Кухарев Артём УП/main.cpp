//"Êóõàðåâ Àðò¸ì ÓÏ"
#undef UNICODE 
#include <Windows.h>
#include <cstring>

#define ID_BUTTON1 1212
#define ID_EDIT1 1122
#define ID_EDIT2 2432
#define ID_STATIC1 3872
#define ID_MENU1 2222
#define MENU_ABOUT 230
#define MENU_PROGRAM 229
#define EXIT_PROGRAM 228

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInstance;

int WINAPI WinMain(HINSTANCE hInstance,
	               HINSTANCE hPrevInstance,
				   PSTR lpCmdLine,
				   int iCmdShow) {

	PSTR lpszCN = "FirstWindow";

	MSG msg = {0};
	HWND hWnd;
	WNDCLASS wndClass = {0};

	wndClass.lpszClassName = lpszCN;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)COLOR_MENU;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClass(&wndClass);

	hWnd = CreateWindow(lpszCN,
		"Summ of two",
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		640,
		480,
		0,
		NULL,
		hInstance,
		0);

	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, hWnd, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

BOOL CreateMenuItem(HMENU hMenu, PSTR str, UINT ulns, UINT uCom, HMENU hSubMenu, bool flag, UINT fType) {
	MENUITEMINFO mii;
	mii.cbSize = sizeof(MENUITEMINFO);
	mii.cch = sizeof(str);
	mii.fState = MFS_ENABLED;
	mii.dwTypeData = str;
	mii.wID = uCom;
	mii.hSubMenu = hSubMenu;
	mii.fType = fType;
	mii.fMask = MIIM_ID | MIIM_STATE | MIIM_SUBMENU | MIIM_TYPE;

	return InsertMenuItem(hMenu, ulns, flag, &mii);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	static HWND hButton1, hStatic1, hEdit1, hEdit2, hStatic2;
	static HMENU hMainMenu, hFileMenu;

	char number1[20], number2[20];

	switch (msg) {
	case WM_CREATE :

		hMainMenu = CreateMenu();

		hFileMenu = CreatePopupMenu();
		CreateMenuItem(hFileMenu, "Exit", 3, EXIT_PROGRAM, NULL, FALSE, MFT_STRING);
		CreateMenuItem(hMainMenu, "Program", 1, MENU_PROGRAM, hFileMenu, FALSE, MFT_STRING);
		CreateMenuItem(hMainMenu, "About", 2, MENU_ABOUT, 0, FALSE, MFT_STRING);
		SetMenu(hWnd, hMainMenu);
		DrawMenuBar(hWnd);

		hStatic1 = CreateWindow("static", "Enter two numbers", WS_CHILD | WS_VISIBLE | BS_CENTER, 210, 140, 300, 20, hWnd, (HMENU)ID_STATIC1, hInstance, 0);
		hStatic2 = CreateWindow("static", "+", WS_CHILD | WS_VISIBLE | BS_CENTER | SS_CENTER, 284, 192, 12, 15, hWnd, (HMENU)(ID_STATIC1+1), hInstance, 0);
		hEdit1 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 210, 190, 70, 20, hWnd, (HMENU)ID_EDIT1, hInstance, 0);
		hEdit2 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 300, 190, 70, 20, hWnd, (HMENU)ID_EDIT2, hInstance, 0);
		hButton1 = CreateWindow("button", "Result", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 395, 175, 80, 50, hWnd, (HMENU)ID_BUTTON1, hInstance, 0);
		SetFocus(hEdit1);

		break;
	case WM_COMMAND:
		switch (wParam) {

		case EXIT_PROGRAM :
			PostQuitMessage(0);
			break;
		case MENU_ABOUT :
			MessageBox(hWnd,"This program was created by Artyom Kuharev, 2014","About",0);
			break;
		case ID_BUTTON1 :
			SendMessage(hEdit1, WM_GETTEXT, sizeof(number1) / sizeof(number1[0]), (LPARAM)number1);
			SendMessage(hEdit2, WM_GETTEXT, sizeof(number2) / sizeof(number2[0]), (LPARAM)number2);

			char buffer[20];
			_itoa_s(atoi(number1) + atoi(number2),buffer,10);
			MessageBox(hWnd, (LPCSTR)buffer, "Result", 0);
	
			SetWindowText(hEdit1, "");
			SetWindowText(hEdit2, "");
			SetFocus(hEdit1);

			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}