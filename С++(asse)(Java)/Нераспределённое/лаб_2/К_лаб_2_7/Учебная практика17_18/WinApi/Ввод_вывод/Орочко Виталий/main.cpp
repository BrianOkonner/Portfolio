#undef UNICODE
#include <windows.h>
//*****LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LPSTR szClassName = "WINAPI";
LPSTR szWindowNAme = "Window";

struct Bad_Size{};

bool STR(char *str, int l)
{
	if (str[0] == 48) return false;
	while (l--)
	if ((str[l]<48) || (str[l]>57))
		return false;
	return true;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow){

	HWND hWnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;    //   Отвечают за перерисовку при изменении размеров окна
	wndclass.lpfnWndProc = WndProc;    //Устанавливаем оконную процедуру
	wndclass.cbClsExtra = 0;    // Резервирования байтов памяти для Windows
	wndclass.cbWndExtra = 0;    //
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_INFORMATION); //Устанавливаем значёк для всех окон созданых на основе этого класса
	wndclass.hIconSm = LoadIcon(NULL, IDI_INFORMATION); //Описатель значка
	wndclass.hCursor = LoadCursor(NULL, IDC_IBEAM);  //Описатель курсора
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //Фон рабочей области окна Белого цвета
	wndclass.lpszMenuName = 0; //меню класса окна, меню отсутствует
	wndclass.lpszClassName = szClassName;
	wndclass.cbSize = sizeof(wndclass);

	RegisterClassEx(&wndclass);

	hWnd = CreateWindow(szClassName, szWindowNAme, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, iCmdShow);

	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam){
	static HWND hwnded_1, hwnded_2, hwndbutton;
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;
	int list_1,list_2,a,c;
	char *str1,*str2, *mes, *rmes;
	switch (iMsg)
	{
	case WM_CREATE:
		hwndbutton = CreateWindow("button", "RESULT", WS_CHILD | WS_VISIBLE | BS_HOLLOW, 0, 0, 0, 0, hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hwnded_1 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 0, 0, 0, 0, hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hwnded_2 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 0, 0, 0, 0, hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect); //для rect инициализации
		TextOut(hDC,rect.right / 2 -15,rect.bottom/2-45,"ADD",4);
		EndPaint(hwnd, &ps);
		break;
	case WM_SIZE:
		GetClientRect(hwnd, &rect);
		MoveWindow(hwndbutton, rect.right / 2 - 100, rect.bottom/2-15, 200, 30, TRUE);
		MoveWindow(hwnded_1, rect.right / 2 - 100, rect.bottom / 2 - 50, 80, 25, TRUE);
		MoveWindow(hwnded_2, rect.right / 2 +20, rect.bottom / 2 - 50, 80, 25, TRUE);

		break;
	case WM_COMMAND:
		if (HIWORD(wParam) == BN_CLICKED)
		{
			GetClientRect(hwnd, &rect);
			try{
			list_1 = GetWindowTextLength(hwnded_1);
			str1 = new char[list_1 + 1];
			GetWindowText(hwnded_1, str1, list_1 + 1);
			a = atoi(str1);
			if (!STR(str1, list_1))
				throw Bad_Size();
			list_2 = GetWindowTextLength(hwnded_2);
			str2 = new char[list_2 + 1];
			GetWindowText(hwnded_2, str2, list_2 + 1);
			c = atoi(str2);
			if (!STR(str2, list_2))
				throw Bad_Size();
		}
			catch (Bad_Size)
			{
				MessageBox(hwnd, "Error", "WARNING", MB_OK | MB_ICONINFORMATION);
			}
			char* rmes = new char[list_1 + list_2 + 1];
			itoa(a + c, rmes, 10);
			MessageBox(hwnd, rmes, "Сумма", MB_OK | MB_ICONINFORMATION);
		
			if (LOWORD(wParam) == 1)
			if (HIWORD(wParam) == EN_ERRSPACE || HIWORD(wParam) == EN_MAXTEXT)
				MessageBox(hwnd, "Edit control out of space.", "Сумма", MB_OK | MB_ICONSTOP);

		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}
	return 0;
}