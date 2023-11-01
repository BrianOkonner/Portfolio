/*

=========================================
Самостоятельная работа УП 9 апреля 2015
-----------------------------------------
Вариант 3
-----------------------------------------
Выполнил студент 1 курса 8 группы
Афанасенко Алексей
-----------------------------------------
Задание:
=========================================
*/

#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE 
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>



#define ID_BUTTON1 1212
#define ID_EDIT1 2431
#define ID_EDIT2 2432
#define ID_EDIT3 2434
#define ID_EDIT4 2435

HWND hButton1, hEdit1, hEdit2, hEdit3, hEdit4;


void transf(char *a, char *b)
{
	int ans = 0;
	_asm
	{
		// Длина строки
		xor ecx, ecx
		push    edi
		xor eax, eax
		cld
		dec ecx
		mov edi, a
		repne   scasb
		not ecx
		pop edi
		lea eax, [ecx - 1]
		
		// Средний символ + цифра на среднем месте
		mov ecx, eax
		shr ecx, 1
		mov edi, a
		add edi, ecx
		xor eax, eax
		mov al, [edi]
		sub al, '0'
		mov ecx, eax
		mov ans, ecx

		// Копирование
		mov esi, edi
		mov edi, b
		mov al, '\0'
		repne movsb
		mov [edi], '\0'
	}
}

int mulS(char *a, char *b)
{
	int ans = 0;
	int c = atoi(b);
	_asm
	{
		// Длина строки
		xor ecx, ecx
		push    edi
		xor eax, eax
		cld
		dec ecx
		mov edi, a
		repne   scasb
		not ecx
		pop edi
		lea eax, [ecx - 1]
		
		//Умножение

		mov edx, c
		mul edx
		mov ans, eax
	}	
	return ans;
}

double mySqrt(double x)
{
	double ans = 0;
	_asm
	{
		fld x
		fsqrt
		fstp ans
	}
	return ans;

}

static TCHAR szWindowClass[] = "win32app";

static TCHAR szTitle[] = "УП 09.04.2015";

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			"Call to RegisterClassEx failed!",
			"Error",
			NULL);

		return 1;
	}

	hInst = hInstance; 
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		350, 300,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	if (!hWnd)
	{
		MessageBox(NULL,
			"Call to CreateWindow failed!",
			"Error!",
			NULL);

		return 1;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	char copyr[] = "© 2015, Алексей Афанасенко";

	static char in1[18];
	switch (message)
	{

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		TextOut(hdc, 5, 5, "Введите число из нечетного количества цифр:", strlen("Введите число из нечетного количества цифр:"));
		
		hEdit1 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 5, 25, 70, 20, hWnd, (HMENU)ID_EDIT1, hInst, 0);
		hButton1 = CreateWindow("button", "Результат", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 5, 50, 80, 30, hWnd, (HMENU)ID_BUTTON1, hInst, 0);

		TextOut(hdc, 5, 90, "Полученная строка:", strlen("Полученная строка:"));
		hEdit2 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 5, 110, 70, 20, hWnd, (HMENU)ID_EDIT2, hInst, 0);
		
		TextOut(hdc, 5, 130, "Полученное число:", strlen("Полученное число:"));
		hEdit3 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 5, 150, 70, 20, hWnd, (HMENU)ID_EDIT3, hInst, 0);

		TextOut(hdc, 5, 180, "Корень числа:", strlen("Корень числа:"));

		hEdit4 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 5, 200, 70, 20, hWnd, (HMENU)ID_EDIT4, hInst, 0);

		
		TextOut(hdc, 130, 230, copyr, strlen(copyr));

		SetFocus(hEdit1);
		
		EndPaint(hWnd, &ps);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
			case ID_BUTTON1:
				SendMessage(hEdit1, WM_GETTEXT, sizeof(in1) / sizeof(in1[0]), (LPARAM)in1);
				if (!(strlen(in1) & 1))
				{
					MessageBox(hWnd, "Ошибка: Количеств цифр должно быть нечетным!", "Error!", 0);
				}
				else
				{
					char buffer[50];

					transf(in1, buffer);
					
					SetWindowText(hEdit2, buffer);
					int x = mulS(in1, buffer);
					_itoa_s(x, buffer, 10);
					SetWindowText(hEdit3, buffer);
					_gcvt(mySqrt(x*1.0), 18, buffer);
					SetWindowText(hEdit4, buffer);
				}
				
				
				
				break;

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