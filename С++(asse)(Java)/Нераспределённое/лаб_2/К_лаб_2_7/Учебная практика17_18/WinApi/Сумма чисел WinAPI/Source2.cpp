#undef UNICODE
#pragma comment (lib, "winmm.lib")

#include <windows.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

char *mystring;

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
     {
		srand(time(NULL));
		int a, b;
		a = rand() % 1000;
		b = rand() % 1000;
		int c = a + b;
		char *a1 = new char [10], *b1 = new char [10];
		a1 = itoa(a, a1, 10);
		b1 = itoa(b, b1, 10);
		char *c1 = new char [10];
		c1 = itoa(c, c1, 10);
		int len1 = strlen(a1), len2 = strlen(b1), len3 = strlen(c1);
		mystring = new char [len1 + len2 + len3 + 7];
		strcpy(mystring, a1);
		strcat(mystring, " + ");
		strcat(mystring, b1);
		strcat(mystring, " = ");
		strcat(mystring, c1);
		static char szAppName[] = "MySum";
		HWND        hwnd;
		MSG         msg;
		WNDCLASSEX  wndclass;
		wndclass.cbSize        = sizeof(wndclass);
		wndclass.style         = CS_HREDRAW | CS_VREDRAW;               // ��������� ����� ������ ����
		wndclass.lpfnWndProc   = WndProc;                               // ��������� ��������� �� ������� ����
		wndclass.cbClsExtra    = 0;
		wndclass.cbWndExtra    = 0;
		wndclass.hInstance     = hInstance;
		wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION);      // ��������� ����������� ����������� ����������
		wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW);          // ��������� ����������� ������� ��� ����������
		wndclass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);  // ��������� ����������� ����� ��� �������� ����
		wndclass.lpszMenuName  = NULL;
		wndclass.lpszClassName = szAppName;                             // ��������� ��������� �� ������ � ������ ������ ����
		wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION);      // ��������� ����������� ����� �����������
		RegisterClassEx (&wndclass); // ����������� ������ ����, �������� �������� ���������� � ���������� wndclass
		hwnd = CreateWindow (szAppName, "Sum", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
		ShowWindow (hwnd, iCmdShow);
		UpdateWindow (hwnd);
		while (GetMessage (&msg, NULL, 0, 0))
			{
				TranslateMessage (&msg);
				DispatchMessage (&msg);
			}
		return msg.wParam;
     }

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
	{
		HDC         hdc;
		PAINTSTRUCT ps;
		RECT        rect;
		char str[] = "It is the sum of two random numbers:";
		switch (iMsg)
			{
				BOOL xx;
					case WM_PAINT:
						hdc = BeginPaint (hwnd, &ps);
						GetClientRect (hwnd, &rect);               
						DrawText (hdc, mystring, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
						TextOut (hdc, 382, 200, str, strlen(str));
						EndPaint (hwnd, &ps);
						return 0;
					case WM_DESTROY:
						PostQuitMessage (0);
						return 0;
			}
		return DefWindowProc (hwnd, iMsg, wParam, lParam);
	}