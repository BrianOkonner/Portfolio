// Matrix

#include "Matrix.h"
#include <string>
#include <stdio.h>

static TCHAR szTitle[] = "Matrix";
Matrix matr(3, 3);
HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex; // Клас акна

	// Вызначэнне класа акна
	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINLOGO));
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = NULL;
	wcex.lpszClassName  = "WinWND";
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_WINLOGO));

	// Рэгістрацыя класа акна
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			"Call to RegisterClassEx failed!",
			"Win32 Guided Tour",
			NULL);

		return 1;
	}

	hInst = hInstance; // Store instance handle in our global variable

	// Стварэнне акна
	HWND hWnd = CreateWindow(
		"WinWND",			      // the name of the application
		szTitle,					  // the text that appears in the title bar
		WS_OVERLAPPEDWINDOW,		  // the type of window to create
		CW_USEDEFAULT, CW_USEDEFAULT, // initial position (x, y)    
		650, 350, // initial size (width, length)
		NULL,						  // the parent of this window   
		NULL,					      // this application does not have a menu bar
		hInstance,					  // the first parameter from WinMain
		NULL						  // not used in this application
		);

	if (!hWnd)
	{
		MessageBox(NULL,
			"Call to CreateWindow failed!",
			"Win32 Guided Tour",
			NULL);

		return 1;
	}

	ShowWindow(hWnd, // the value returned from CreateWindow    
		nCmdShow);   // the fourth parameter from WinMain
	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{ // PURPOSE: Processes messages for the main window.
	static HWND hEdit11 = 0;
	static HWND hEdit12 = 0;
	static HWND hEdit13 = 0;
	static HWND hEdit21 = 0;
	static HWND hEdit22 = 0;
	static HWND hEdit23 = 0;
	static HWND hEdit31 = 0;
	static HWND hEdit32 = 0;
	static HWND hEdit33 = 0;
	static HWND hEditRes = 0;
	static HWND hText11, hText12, hText13, hText21, hText22, hText23, hText31, hText32, hText33;
	static HWND hButtonCalc;
	char *a;

	switch (message)
	{
	case WM_CREATE:
		hText11 = CreateWindowEx(WS_EX_CLIENTEDGE, "static", "a11 =", WS_CHILD|WS_VISIBLE, 20, 10, 50, 20, hWnd, (HMENU)0, 0, NULL);
		hText12 = CreateWindowEx(WS_EX_CLIENTEDGE, "static", "a12 =", WS_CHILD|WS_VISIBLE, 220, 10, 50, 20, hWnd, (HMENU)0, 0, NULL);
		hText13 = CreateWindowEx(WS_EX_CLIENTEDGE, "static", "a13 =", WS_CHILD|WS_VISIBLE, 420, 10, 50, 20, hWnd, (HMENU)0, 0, NULL);
		hText21 = CreateWindowEx(WS_EX_CLIENTEDGE, "static", "a21 =", WS_CHILD|WS_VISIBLE, 20, 60, 50, 20, hWnd, (HMENU)0, 0, NULL);
		hText22 = CreateWindowEx(WS_EX_CLIENTEDGE, "static", "a22 =", WS_CHILD|WS_VISIBLE, 220, 60, 50, 20, hWnd, (HMENU)0, 0, NULL);
		hText23 = CreateWindowEx(WS_EX_CLIENTEDGE, "static", "a23 =", WS_CHILD|WS_VISIBLE, 420, 60, 50, 20, hWnd, (HMENU)0, 0, NULL);
		hText31 = CreateWindowEx(WS_EX_CLIENTEDGE, "static", "a31 =", WS_CHILD|WS_VISIBLE, 20, 110, 50, 20, hWnd, (HMENU)0, 0, NULL);
		hText32 = CreateWindowEx(WS_EX_CLIENTEDGE, "static", "a32 =", WS_CHILD|WS_VISIBLE, 220, 110, 50, 20, hWnd, (HMENU)0, 0, NULL);
		hText33 = CreateWindowEx(WS_EX_CLIENTEDGE, "static", "a33 =", WS_CHILD|WS_VISIBLE, 420, 110, 50, 20, hWnd, (HMENU)0, 0, NULL);

		hEdit11 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "0", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL, 75, 10, 130, 20, hWnd, (HMENU)100, 0, NULL);
		hEdit12 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "1", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL, 275, 10, 130, 20, hWnd, (HMENU)100, 0, NULL);
		hEdit13 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "2", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL, 475, 10, 130, 20, hWnd, (HMENU)100, 0, NULL);
		hEdit21 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "1", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL, 75, 60, 130, 20, hWnd, (HMENU)100, 0, NULL);
		hEdit22 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "2", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL, 275, 60, 130, 20, hWnd, (HMENU)100, 0, NULL);
		hEdit23 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "2", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL, 475, 60, 130, 20, hWnd, (HMENU)100, 0, NULL);
		hEdit31 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "5", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL, 75, 110, 130, 20, hWnd, (HMENU)100, 0, NULL);
		hEdit32 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "4", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL, 275, 110, 130, 20, hWnd, (HMENU)100, 0, NULL);
		hEdit33 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "2", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL, 475, 110, 130, 20, hWnd, (HMENU)100, 0, NULL);
		hEditRes = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_AUTOVSCROLL|ES_AUTOHSCROLL, 200, 150, 400, 150, hWnd, (HMENU)100, 0, NULL);
		hButtonCalc = CreateWindowEx(NULL, "BUTTON", "Вылічыць матрыцу", WS_TABSTOP|WS_VISIBLE|BS_MULTILINE|WS_CHILD|BS_DEFPUSHBUTTON, 20, 150, 80, 50, hWnd,(HMENU)105, GetModuleHandle(NULL), NULL);

		a = new char[100];
		GetWindowText(hEdit11, a, 5);
		matr(0, 0) = double(atoi(a));
		GetWindowText(hEdit12, a, 5);
		matr(0, 1) = double(atoi(a));
		GetWindowText(hEdit13, a, 5);
		matr(0, 2) = double(atoi(a));
		GetWindowText(hEdit21, a, 5);
		matr(1, 0) = double(atoi(a));
		GetWindowText(hEdit22, a, 5);
		matr(1, 1) = double(atoi(a));
		GetWindowText(hEdit23, a, 5);
		matr(1, 2) = double(atoi(a));
		GetWindowText(hEdit31, a, 5);
		matr(2, 0) = double(atoi(a));
		GetWindowText(hEdit32, a, 5);
		matr(2, 1) = double(atoi(a));
		GetWindowText(hEdit33, a, 5);
		matr(2, 2) = double(atoi(a));
		delete a;
		break;

	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case 105:
			{
				char *a = new char[100];
				GetWindowText(hEdit11, a, 5);
				matr(0, 0) = double(atoi(a));
				GetWindowText(hEdit12, a, 5);
				matr(0, 1) = double(atoi(a));
				GetWindowText(hEdit13, a, 5);
				matr(0, 2) = double(atoi(a));
				GetWindowText(hEdit21, a, 5);
				matr(1, 0) = double(atoi(a));
				GetWindowText(hEdit22, a, 5);
				matr(1, 1) = double(atoi(a));
				GetWindowText(hEdit23, a, 5);
				matr(1, 2) = double(atoi(a));
				GetWindowText(hEdit31, a, 5);
				matr(2, 0) = double(atoi(a));
				GetWindowText(hEdit32, a, 5);
				matr(2, 1) = double(atoi(a));
				GetWindowText(hEdit33, a, 5);
				matr(2, 2) = double(atoi(a));
				delete a;

				std::string output = "Вызнaчнік (determinant): ";
				output += matr.double_to_string(matr.determinant());
				output += "\r\n";
				output += "Inversed matrix:\r\n";
				
				matr = matr.inverse();
				for(int i=0; i<3; ++i)
				{
					for(int j=0; j<3; j++)
						output += matr.get_string_value(i, j) + ' ';
					output += "\r\n";
				}

				SetWindowText(hEditRes, output.c_str());
			}
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}