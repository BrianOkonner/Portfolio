
#undef UNICODE
#include <windows.h> // Заголовочный файл, содержащий практически все функции объявленные в API

#define MAXPOINTS 1000
#define MoveTo(hdc, x, y) MoveToEx (hdc, x, y, NULL)

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Вход в программу

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, // Точка входа в программу
	PSTR szCmdLine, int iCmdShow)
{
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
	wndclass.lpszMenuName = NULL;                              
	wndclass.lpszClassName = szAppName;                       
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);  

	RegisterClassEx(&wndclass); 
	hwnd = CreateWindow(szAppName, "Connect-the-Points Mouse Demo",  
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
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

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam){  // wparam для int and handle // lparam - pointers
	static POINT points[MAXPOINTS];						// Объявление массива, содержащего структуры с информацией о координатах точки
	static int   iCount;							
	HDC          hdc;	
	PAINTSTRUCT  ps;	
	int          i, j;	

	switch (iMsg){
	case WM_LBUTTONDOWN: // Случай поступления сообщения WM_LBUTTONDOWN
		iCount = 0;
		InvalidateRect(hwnd, NULL, TRUE); // Добавление Rect к области обновления окна (область пользователя в окне становится недостоверной)
		return 0;

	case WM_MOUSEMOVE: // Случай поступления сообщения WM_MOUSEMOVE
		if (wParam & MK_LBUTTON && iCount < 1000){
			points[iCount].x = LOWORD(lParam); // Выделение из 32-битового целочисленного значения младшего слова (получение координаты x мыши)
			points[iCount++].y = HIWORD(lParam); // Выделение из 32-битового целочисленного значения младшего слова (получение координаты y мыши)

			hdc = GetDC(hwnd); 
			SetPixel(hdc, LOWORD(lParam), HIWORD(lParam), 0L); // Рисование элемента изобpажения в указанной точке ///  0L - цвет точки
			ReleaseDC(hwnd, hdc); // Освобождение контекста устройства
		}
		return 0;

	case WM_LBUTTONUP: // Случай поступления сообщения WM_LBUTTONUP
		InvalidateRect(hwnd, NULL, FALSE);  // Добавление Rect к области обновления окна (область пользователя в окне становится недостоверной)
		return 0;

	case WM_PAINT: // Случай поступления сообщения WM_PAINT (Соединение точек линиями)
		hdc = BeginPaint(hwnd, &ps); // Подготовка окна к pаскpаске в ответ на сообщение wm_Paint (Заполнение Paint инфоpмацией для pаскpаски)

		SetCursor(LoadCursor(NULL, IDC_WAIT)); // Установка формы курсора
		ShowCursor(TRUE); // Куpсоp отображается

		for (i = 0; i < iCount - 1; i++) // Соедение всех точек (рисование сети)
			for (j = i + 1; j < iCount; j++){
				MoveTo(hdc, points[i].x, points[i].y); // Перевод курсор на заданные координаты (описано в макросе)
				LineTo(hdc, points[j].x, points[j].y); // Рисование линии по начальным и конечным координатом
			}

		ShowCursor(FALSE); // Куpсоp не отображается
		SetCursor(LoadCursor(NULL, IDC_ARROW)); // Установка формы курсора

		EndPaint(hwnd, &ps); // Указание конца pаскpаски в Wnd
		return 0;

	case WM_DESTROY: // Случай поступления сообщения WM_DESTROY
		PostQuitMessage(0); // Напpавление сообщения wm_Quit в ответ на сообщение wm_Destroy
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam); // Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)
}
