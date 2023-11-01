//"Чернявский Дмитрий УП"
#undef UNICODE 
#include <Windows.h>
#include <cstring>

#define ID_BUTTON1 1212
#define ID_EDIT1 1122
#define ID_EDIT2 2432
#define ID_EDIT3 3742
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
	wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW+1;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClass(&wndClass);

	hWnd = CreateWindow(lpszCN,
		"Сумма",
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		180,
		180,
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
	
	static HWND hButton1, hStatic1, hEdit1, hEdit2,hEdit3, hStatic2;
	static HMENU hMainMenu, hFileMenu;

	char number1[20], number2[20];

	switch (msg) {
	case WM_CREATE :

		hMainMenu = CreateMenu();

		hFileMenu = CreatePopupMenu();
		CreateMenuItem(hFileMenu, "Выход", 3, EXIT_PROGRAM, NULL, FALSE, MFT_STRING);
		CreateMenuItem(hMainMenu, "Меню выхода", 1, MENU_PROGRAM, hFileMenu, FALSE, MFT_STRING);
		CreateMenuItem(hMainMenu, "О программе", 2, MENU_ABOUT, 0, FALSE, MFT_STRING);
		SetMenu(hWnd, hMainMenu);
		DrawMenuBar(hWnd);

		//hStatic1 = CreateWindow("static", "Enter two numbers", WS_CHILD | WS_VISIBLE | BS_CENTER, 210, 140, 300, 20, hWnd, (HMENU)ID_STATIC1, hInstance, 0);
		hStatic2 = CreateWindow("static", "+", WS_CHILD | WS_VISIBLE | BS_CENTER | SS_CENTER, 80, 15, 10, 10, hWnd, (HMENU)(ID_STATIC1+1), hInstance, 0);
		hEdit1 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 10, 70, 20, hWnd, (HMENU)ID_EDIT1, hInstance, 0);
		hEdit2 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 90, 10, 70, 20, hWnd, (HMENU)ID_EDIT2, hInstance, 0);
		hEdit3 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 40, 70, 20, hWnd, (HMENU)ID_EDIT3, hInstance, 0);
		hButton1 = CreateWindow("button", "Резултат", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 45, 70, 80, 50, hWnd, (HMENU)ID_BUTTON1, hInstance, 0);
		SetFocus(hEdit1);

		break;
	case WM_COMMAND:
		switch (wParam) {

		case EXIT_PROGRAM :
			PostQuitMessage(0);
			break;
		case MENU_ABOUT :
			MessageBox(hWnd,"Программа выполнена Чернявским Дмитрием для себя и будующих поколений :), 2016","О программе",0);
			break;
		case ID_BUTTON1 :
			SendMessage(hEdit1, WM_GETTEXT, sizeof(number1) / sizeof(number1[0]), (LPARAM)number1);
			SendMessage(hEdit2, WM_GETTEXT, sizeof(number2) / sizeof(number2[0]), (LPARAM)number2);

			char buffer[20];
			_itoa_s(atoi(number1) + atoi(number2),buffer,10);

			
			SetWindowText(hEdit3, (LPCSTR)buffer);
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