#include <windows.h> // Заголовочный файл, содержащий практически все функции объявленные в API
#include "resource.h"
#include "header.h"
#include <commctrl.h>
#include <mmsystem.h>
#include <ctime>

#pragma comment(lib, "comctl32.lib") // for visual styles
#pragma comment(linker, "/manifestdependency:\"type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' \
language='*'\"")
#include <commctrl.h>

#define MoveTo(hdc, x, y) MoveToEx (hdc, x, y, NULL)
HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0)), hPen1 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0)), hPen2 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255)), hPen3 = CreatePen(PS_SOLID|PS_DASHDOT, 1, RGB(50, 100, 0));
HFONT font;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Вход в программу

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, // Точка входа в программу
	PSTR szCmdLine, int iCmdShow)
{
	font = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");
	static char szAppName[] = "Connect";
	HWND        hwnd;
	MSG         msg;
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
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));


	RegisterClassEx(&wndclass);
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		szAppName,
		"Sudoku", WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZE,
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
Field a;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{  // wparam для int and handle // lparam - pointers
	HDC          hdc;
	PAINTSTRUCT  ps;
	RECT rect;

	static HANDLE hFile = NULL;
	DWORD NumberOfBytesRead;
	
	static bool error=0;
	static double sx = 0, sy = 0;
	a.Field1(sx, sy);

	static char text[2] = { ' ','\0' };
	static int mousex = 10, mousey = 10, lastx = 0, lasty = 0;
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
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_AUTOR:
			MessageBox(hwnd, "Автор: Головатый Максим\nБГУ ФПМИ 2018", "О программе", MB_OK);
			break;
		case ID_HELP:
			MessageBox(hwnd, "Для того, чтобы ввести цифру в клетку, нажмите на неё мышкой\nа затем нажмите цифру. Программа подскажет вам характерным\nзвуком, если цифра была поставлена неправильно. В меню вы можете выбрать тестовый вариант судоку.", "Информация", MB_OK);

			break;
		case ID_EXIT:
			exit(0);
		case ID_SOLVE:
			hdc = GetDC(hwnd);
			a.solve(hdc);
			if (a.solved())MessageBox(hwnd, "Победа!", "Cудоку решено!", MB_OK);
			ReleaseDC(hwnd, hdc);
			break;
		case ID_TEST:
			hdc = GetDC(hwnd);
			SelectObject(hdc, font);
			//--------------printtest---------------
			a.test();
			a.printexample(hdc);
			ReleaseDC(hwnd, hdc);
			break;
			//--------------------------------------
		case ID_CLEAR:
			hdc = GetDC(hwnd);

			SelectObject(hdc, hPen2);
			Rectangle(hdc, 0, 0, sx, sy);
			InvalidateRect(hwnd, NULL, FALSE);  // Добавление Rect к области обновления окна (область пользователя в окне становится недостоверной)

			ReleaseDC(hwnd, hdc);
			a.clear();
			break;
		case ID_SAVE1:
			hFile = CreateFile(FILE_PATH1, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
				if (hFile)
				{
					WriteFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
					CloseHandle(hFile);
				}
				else
					MessageBox(hwnd, ("Невозможно открыть файл"),("Ошибка"), MB_ICONWARNING | MB_OK);
			break;
		case ID_LOAD1:
			hFile = CreateFile(FILE_PATH1, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile)
			{
				ReadFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
				CloseHandle(hFile);
			}
			else
				MessageBox(hwnd, ("Невозможно открыть файл"), ("Ошибка"), MB_ICONWARNING | MB_OK);
			hdc = GetDC(hwnd);

			SelectObject(hdc, hPen2);
			Rectangle(hdc, 0, 0, sx, sy);
			InvalidateRect(hwnd, NULL, FALSE);  // Добавление Rect к области обновления окна (область пользователя в окне становится недостоверной)


			a.printexample(hdc);
			ReleaseDC(hwnd, hdc);
			break;
		case ID_SAVE2:
			hFile = CreateFile(FILE_PATH2, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile)
			{
				WriteFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
				CloseHandle(hFile);
			}
			else
				MessageBox(hwnd, ("Невозможно открыть файл"), ("Ошибка"), MB_ICONWARNING | MB_OK);
			break;
		case ID_LOAD2:
			hFile = CreateFile(FILE_PATH2, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile)
			{
				ReadFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
				CloseHandle(hFile);
			}
			else
				MessageBox(hwnd, ("Невозможно открыть файл"), ("Ошибка"), MB_ICONWARNING | MB_OK);
			hdc = GetDC(hwnd);
			a.printexample(hdc);
			ReleaseDC(hwnd, hdc);
			break;
		case ID_SAVE3:
			hFile = CreateFile(FILE_PATH3, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile)
			{
				WriteFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
				CloseHandle(hFile);
			}
			else
				MessageBox(hwnd, ("Невозможно открыть файл"), ("Ошибка"), MB_ICONWARNING | MB_OK);
			break;
		case ID_LOAD3:
			hFile = CreateFile(FILE_PATH3, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile)
			{
				ReadFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
				CloseHandle(hFile);
			}
			else
				MessageBox(hwnd, ("Невозможно открыть файл"), ("Ошибка"), MB_ICONWARNING | MB_OK);
			hdc = GetDC(hwnd);
			a.printexample(hdc);
			ReleaseDC(hwnd, hdc);
			break;
		case ID_SAVE4:
			hFile = CreateFile(FILE_PATH4, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile)
			{
				WriteFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
				CloseHandle(hFile);
			}
			else
				MessageBox(hwnd, ("Невозможно открыть файл"), ("Ошибка"), MB_ICONWARNING | MB_OK);
			break;
		case ID_LOAD4:
			hFile = CreateFile(FILE_PATH4, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile)
			{
				ReadFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
				CloseHandle(hFile);
			}
			else
				MessageBox(hwnd, ("Невозможно открыть файл"), ("Ошибка"), MB_ICONWARNING | MB_OK);
			hdc = GetDC(hwnd);
			a.printexample(hdc);
			ReleaseDC(hwnd, hdc);
			break;
		case ID_SAVE5:
			hFile = CreateFile(FILE_PATH5, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile)
			{
				WriteFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
				CloseHandle(hFile);
			}
			else
				MessageBox(hwnd, ("Невозможно открыть файл"), ("Ошибка"), MB_ICONWARNING | MB_OK);
			break;
		case ID_LOAD5:
			hFile = CreateFile(FILE_PATH5, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile)
			{
				ReadFile(hFile, a.a, sizeof(a.a), &NumberOfBytesRead, NULL);
				CloseHandle(hFile);
			}
			else
				MessageBox(hwnd, ("Невозможно открыть файл"), ("Ошибка"), MB_ICONWARNING | MB_OK);
			hdc = GetDC(hwnd);
			a.printexample(hdc);
			ReleaseDC(hwnd, hdc);
			break;






		default:
			break;
		}

	case WM_KEYDOWN:
		switch (wParam)
		{
		case 49:case 50:case 51: //клавиши от 1 до 9
		case 52:case 53:case 54:
		case 55:case 56:case 57:

			text[0] = (char)wParam;
			hdc = GetDC(hwnd);
			SelectObject(hdc, font);
			TextOut(hdc, a.count_x(mousex, atoi(text)) - 10, a.count_y(mousey, atoi(text)) - 17, text, 1);
			//a.iferror();
			ReleaseDC(hwnd, hdc);
			error = 0;
			error=a.iferror(atoi(text));
			if (error == 1)
				MessageBeep(MB_ICONHAND);
			if (a.solved() == 1)MessageBox(hwnd, "Победа!", "Cудоку решено!", MB_OK);
			break;
		case 8: case 46:// backspace delete
			hdc = GetDC(hwnd);

			SelectObject(hdc, hPen2);
			Rectangle(hdc, lastx - sx / 18, lasty - sy / 18 + 4, lastx + sx / 18 - 5, lasty + sy / 18);

			a.clear_cell(mousex, mousey);

			ReleaseDC(hwnd, hdc);
		default:
			break;
		}break;
	case WM_LBUTTONDOWN:

		mousex = LOWORD(lParam);
		mousey = HIWORD(lParam);

		hdc = GetDC(hwnd);
		if (a.count_x(mousex) != lastx || a.count_y(mousey) != lasty)
		{
			SelectObject(hdc, hPen2);
			SelectObject(hdc, GetStockObject(NULL_BRUSH));
			Rectangle(hdc, lastx - sx / 18 - 1, lasty - sy / 18 + 3, lastx + sx / 18 - 4, lasty + sy / 18 + 1);
			
		}

		SelectObject(hdc, hPen3);
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
		Rectangle(hdc, a.count_x(mousex) - sx / 18 - 1, a.count_y(mousey) - sy / 18 + 3, a.count_x(mousex) + sx / 18 - 4, a.count_y(mousey) + sy / 18 + 1);
		

		lastx = a.count_x(mousex); lasty = a.count_y(mousey);

		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);


		//------------------------------------DrawingField--------------------------------

		SelectObject(hdc, hPen);
		for (int i = 0; i < 9; i++)
		{
			if (i % 3 == 0) SelectObject(hdc, hPen1);
			MoveTo(hdc, sx - (sx / 9)*i, 0);
			LineTo(hdc, sx - (sx / 9)*i, sy);
			SelectObject(hdc, hPen);
		}
		for (int i = 0; i < 9; i++)
		{
			if (i % 3 == 0) SelectObject(hdc, hPen1);
			MoveTo(hdc, 0, sy - (sy / 9)*i);
			LineTo(hdc, sx, sy - (sy / 9)*i);
			SelectObject(hdc, hPen);
		}
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
		Rectangle(hdc, 0, 0, sx, sy);

		//---------------------------------------------------------------------------------


		EndPaint(hwnd, &ps); // Указание конца pаскpаски в Wnd
		return 0;

	case WM_DESTROY: // Случай поступления сообщения WM_DESTROY
		PostQuitMessage(0); // Напpавление сообщения wm_Quit в ответ на сообщение wm_Destroy
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam); // Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)
}
