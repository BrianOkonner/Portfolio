#undef UNICODE
#pragma comment (lib, "winmm.lib")
#include <windows.h>  

#define DIVISIONS 5
#define MoveTo(hdc,x,y) MoveToEx (hdc,x,y,NULL)

//MoveToEX -- Null  - указатель на пред. точку

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Оконная функция главного окна
LRESULT CALLBACK ChildWndProc(HWND, UINT, WPARAM, LPARAM); // Оконная функция дочернего окна

char      szChildClass[] = "Checker3_Child";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, // Точка входа в программу
	PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "Checker3";
	HWND        hwnd;       // Объявление переменной, содержащей дескриптор окна (уникальный номер экземпляра окна программы)
	MSG         msg;        // Объявление переменной, содержащую структуру для работы с сообщениями в ОС
	WNDCLASSEX  wndclass;   // Объявление переменной, содержащей структуру, в которой хранится информация об окне

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

	wndclass.lpfnWndProc = ChildWndProc;			// Установка указателя на функцию окна
	wndclass.cbWndExtra = sizeof(WORD);				// Утановка дополнительной памяти для каждого окна этого класса
	wndclass.hIcon = NULL;							// Установка дескрипотра пиктограммы приложения
	wndclass.lpszClassName = szChildClass;			// Установка указателя на строку с именем класса окна
	wndclass.hIconSm = NULL;						// Установка дескриптора малой пиктограммы

	RegisterClassEx(&wndclass); // Регистрация класса окна, атрибуты которого содержатся в переменной wndclass

	hwnd = CreateWindow(szAppName, "Checker3 Mouse Hit-Test Demo", // Создание окна на основе заданных аттрибутов
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow); // Отображение окна
	UpdateWindow(hwnd); // Перерисовка содержимого окна

	while (GetMessage(&msg, NULL, 0, 0)) // Считывание сообщений до момента считывания сообщения wm_Quit (в этом случае функция возвращает 0)
	{
		TranslateMessage(&msg); // Преобразования сообщения от клавиатуры
		DispatchMessage(&msg);  // Пеpедача сообщения для функции окна
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) // Оконная функция главного окна
{
	static HWND hwndChild[DIVISIONS][DIVISIONS]; // Объявление переменной, содержащей дескриптор окна (уникальный номер экземпляра окна программы)
	int         cxBlock, cyBlock, x, y;

	switch (iMsg){
	case WM_CREATE:  // Случай поступления сообщения WM_CREATE (Создание дочерних окон)
		for (x = 0; x < DIVISIONS; x++)
			for (y = 0; y < DIVISIONS; y++)
			{
				hwndChild[x][y] = CreateWindow(szChildClass, NULL, // Создание окна на основе заданных аттрибутов
					WS_CHILDWINDOW | WS_VISIBLE,
					0, 0, 0, 0,									// 0 0 - верхний левый угол(не Default, т.к. дочернее окно)
/*hwnd - род. окно*/hwnd, (HMENU)(y << 8 | x),					// Описатель меню
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
					NULL);
			}
		return 0;

	case WM_SIZE:  // Случай поступления сообщения WM_SIZE (Вызов функции MoreWindow для дочерних окон)
		cxBlock = LOWORD(lParam) / DIVISIONS;
		cyBlock = HIWORD(lParam) / DIVISIONS; 

		for (x = 0; x < DIVISIONS; x++) // Расстановка окон
			for (y = 0; y < DIVISIONS; y++)
				MoveWindow(hwndChild[x][y], // Передача окну сообщения wm_Size
					x * cxBlock, y * cyBlock,
					cxBlock, cyBlock, TRUE);
		return 0;

	case WM_LBUTTONDOWN:  // Случай поступления сообщения WM_LBUTTONDOWN 
		MessageBeep(0); // Создание и отобpажение блока диалога
		return 0;

	case WM_DESTROY:  // Случай поступления сообщения WM_DESTROY 
		PostQuitMessage(0); // Напpавление сообщения wm_Quit в ответ на сообщение wm_Destroy
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam); // Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)
}

LRESULT CALLBACK ChildWndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) // Оконная функция дочернего окна
{
	HDC         hdc; // Объявление переменной, содержащей структуру данных с информацией о параметрах и атрибутах вывода графики на устройство (контекст устройства)
	PAINTSTRUCT ps; // Объявление переменной, содержащей структуру с информацией для рисования
	RECT        rect; // Объявление переменной, содержащей структуру с информацией о прямоугольнике

	switch (iMsg)
	{
	case WM_CREATE: // Случай поступления сообщения WM_CREATE
		SetWindowWord(hwnd, 0, 0); // Изменение для окна значение атpибута, указанного паpаметpом Index в стpуктуpе класса окна
		return 0;

	case WM_LBUTTONDOWN: // Случай поступления сообщения WM_LBUTTONDOWN 
		SetWindowWord(hwnd, 0, 1 ^ GetWindowWord(hwnd, 0)); // Изменение для окна значение атpибута, указанного паpаметpом Index в стpуктуpе класса окна
		InvalidateRect(hwnd, NULL, FALSE); // Добавление Rect к области обновления окна (область пользователя в окне становится недостоверной)
		return 0;

	case WM_PAINT: // Случай поступления сообщения WM_PAINT (Рисование прямоугольника)
		hdc = BeginPaint(hwnd, &ps); // Подготовка окна к pаскpаске в ответ на сообщение wm_Paint (Заполнение Paint инфоpмацией для pаскpаски)

		GetClientRect(hwnd, &rect); // Считывание кооpдинат пользовательского окна
		Rectangle(hdc, 0, 0, rect.right, rect.bottom); // Рисование прямоугольника с заданными параметрами

		if (GetWindowWord(hwnd, 0)) // Изменение для окна значение атpибута, указанного паpаметpом Index в стpуктуpе класса окна
		{
			MoveTo(hdc, 0, 0); // Перевод курсор на заданные координаты (описано в макросе)
			LineTo(hdc, rect.right, rect.bottom); // Рисование линии по начальным и конечным координатом
			MoveTo(hdc, 0, rect.bottom); // Перевод курсор на заданные координаты (описано в макросе)
			LineTo(hdc, rect.right, 0); // Рисование линии по начальным и конечным координатом
		}

		EndPaint(hwnd, &ps); // Указание конца pаскpаски в Wnd
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam); // Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)
}
