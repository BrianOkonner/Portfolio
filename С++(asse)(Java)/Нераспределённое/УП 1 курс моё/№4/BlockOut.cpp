
#undef UNICODE
#pragma comment (lib, "winmm.lib")											//Библиотека для поиска помещ. в объектный файл(с пром. представл. части прог.)
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "BlokOut2";
	HWND        hwnd;														// Объявление переменной, содержащей дескриптор окна 
	MSG         msg;														// Переменная для работы с сообщ.
	WNDCLASSEX  wndclass;													//Переменная для хранения инф. об окне

	wndclass.cbSize = sizeof(wndclass);										// Размер в байтах
	wndclass.style = CS_HREDRAW | CS_VREDRAW;								// Установка стиля класса окна
	wndclass.lpfnWndProc = WndProc;											// Установка указателя на функцию окна
	wndclass.cbClsExtra = 0;												// Доп.
	wndclass.cbWndExtra = 0;												//		память
	wndclass.hInstance = hInstance;  										// Установка дескриптора экземпляра приложения
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);						// Установка дескрипотра иконки риложения
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);							// Установка дескриптора курсора для приложения
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);			// Установка дескриптора кисти для закраски окна
	wndclass.lpszMenuName = NULL;											// Меню нет. указатель на меню = 0
	wndclass.lpszClassName = szAppName;                                     // Указатель на строку с именем класса окна
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);						// Установка деск. иконки 

	RegisterClassEx(&wndclass);												// Регистрация класса окна

	hwnd = CreateWindow(szAppName, "Mouse Button & Capture Demo",			// Создание окна
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);										// Ро. окно - меню - пар-тры создания

	ShowWindow(hwnd, iCmdShow);												// Отображение окна
	UpdateWindow(hwnd);														// Перерисовка содержимого окна

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);												// Преобразования сообщения от клавиатуры
		DispatchMessage(&msg);												// Пеpедача сообщения для функции окна
	}
	return msg.wParam;
}

void DrawBoxOutline(HWND hwnd, POINT ptBeg, POINT ptEnd)
{
	HDC hdc;																// Перемення дл яхранения контества уст-ва

	hdc = GetDC(hwnd);														// Получение контекста дисплея

	SetROP2(hdc,															//Определяет, как комб. сущ. и рисуемые объекты
		R2_NOT);															//R2_NOT - цвет заливки - обратный цвету заднего плана
	SelectObject(hdc, GetStockObject(NULL_BRUSH));							// Выбор логического объекта для контекста устройства
	Rectangle(hdc,															// Рисование прямоугольника с заданными параметрами 
		ptBeg.x,															// Коорд. верхнего 
		ptBeg.y,															//		левого угла
		ptEnd.x,															// Коорд. нижнего
		ptEnd.y);															//		правго угла

	ReleaseDC(hwnd, hdc);													// Освобождение контекста устройства
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static BOOL  fBlocking, fValidBox;
	static POINT ptBeg, ptEnd, ptBoxBeg, ptBoxEnd;							// Информация о координатах точки
	HDC          hdc;  
	PAINTSTRUCT  ps;														// Переменная с информацией для рисования 

	switch (iMsg)
	{
	case WM_LBUTTONDOWN:		
		ptBeg.x = ptEnd.x = LOWORD(lParam);									// Вычисление координаты x начала прямоугольника
		ptBeg.y = ptEnd.y = HIWORD(lParam);									// Вычисление координаты y начала прямоугольника

		DrawBoxOutline(hwnd, ptBeg, ptEnd);									// Рисование прямоугольника с использованием растровой операции

		SetCapture(hwnd);													// Запоминает ввод с мыши
		SetCursor(LoadCursor(NULL, IDC_CROSS));								// Устанавливает форму курсора

		fBlocking = TRUE;													// Установка флага, отвечающего за зажатие левой кнопки мыши
		return 0;

	case WM_MOUSEMOVE:
		if (fBlocking)
		{
			SetCursor(LoadCursor(NULL, IDC_CROSS));							// Установка формы курсора

			DrawBoxOutline(hwnd, ptBeg, ptEnd);								// Рисование прямоугольника с использованием растровой операции

			ptEnd.x = LOWORD(lParam);										// Вычисление координаты x конца прямоугольника
			ptEnd.y = HIWORD(lParam);										// Вычисление координаты у конца прямоугольника

			DrawBoxOutline(hwnd, ptBeg, ptEnd); // Рисование прямоугольника с использованием растровой операции
		}
		return 0;

	case WM_LBUTTONUP:
		if (fBlocking)
		{
			DrawBoxOutline(hwnd, ptBeg, ptEnd);						// Рисование прямоугольника с использованием растровой операции

			ptBoxBeg = ptBeg;
			ptBoxEnd.x = LOWORD(lParam);							//вычисление координаты x конца прямоугольника
			ptBoxEnd.y = HIWORD(lParam);							// вычисление координаты y конца прямоугольника

			ReleaseCapture();										// Освобождение заголовка мыши и восстанавление ноpмальной обpаботки ввода
			SetCursor(LoadCursor(NULL, IDC_ARROW));					// Установка формы курсора

			fBlocking = FALSE;										// Установка флага, отвечающего за зажатие левой кнопки мыши
			fValidBox = TRUE;										// Установка флага, отвечающего за указание всех координат прямоугольника

			InvalidateRect(hwnd,									// Добавление Rect к области обновления окна (область пользователя в окне становится недостоверной)
				NULL,												// Обновление всего окна
				TRUE);												// Очистить обовл. область
		}
		return 0;

	case WM_CHAR: 
		if (fBlocking & wParam == '\x1B')							// Проверка нажатие клавиши Esc
		{
			DrawBoxOutline(hwnd, ptBeg, ptEnd);						// Рисование прямоугольника с использованием растровой операции
			ReleaseCapture();										// Освобождение заголовка мыши и восстанавление ноpмальной обpаботки ввода
			SetCursor(LoadCursor(NULL, IDC_ARROW));					// Установка формы курсора

			fBlocking = FALSE;										// Установка флага, отвечающего за зажатие левой кнопки мыши
		}
		return 0;

	case WM_PAINT:										// Случай поступления сообщения WM_PAINT (Рисование прямоугольника)
		hdc = BeginPaint(hwnd, &ps);					// Подготовка окна к pаскpаске в ответ на сообщение wm_Paint

		if (fValidBox)
		{
			SelectObject(hdc, GetStockObject(BLACK_BRUSH)); // Выбор логического объекта для контекста устройства
			Rectangle(hdc, ptBoxBeg.x, ptBoxBeg.y,			// Рисование прямоугольника с заданными параметрами
				ptBoxEnd.x, ptBoxEnd.y);
		}

		if (fBlocking)
		{
			SetROP2(hdc, R2_NOT);								// Установка режима рисования
			SelectObject(hdc, GetStockObject(NULL_BRUSH));		// Выбор логического объекта для контекста устройства
			Rectangle(hdc, ptBeg.x, ptBeg.y, ptEnd.x, ptEnd.y); // Рисование прямоугольника с заданными параметрами
		}

		EndPaint(hwnd, &ps);									// Указание конца pаскpаски в Wnd
		return 0;

	case WM_DESTROY: // Случай поступления сообщения WM_DESTROY
		PostQuitMessage(0); // Напpавление сообщения wm_Quit в ответ на сообщение wm_Destroy
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}// Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)