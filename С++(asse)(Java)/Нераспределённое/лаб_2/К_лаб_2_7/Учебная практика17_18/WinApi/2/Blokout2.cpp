/*---------------------------------------------------
   BLOKOUT2.C -- Mouse Button & Capture Demo Program
                 (c) Charles Petzold, 1996
  ---------------------------------------------------*/
#undef UNICODE
#pragma comment (lib, "winmm.lib")
#include <windows.h>  // Заголовочный файл, содержащий практически все функции объявленные в API

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;   // Вход в программу

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,   // Точка входа в программу
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "BlokOut2" ; 
     HWND        hwnd ;       // Объявление переменной, содержащей дескриптор окна (уникальный номер экземпляра окна программы)
     MSG         msg ;        // Объявление переменной, содержащую структуру для работы с сообщениями в ОС
     WNDCLASSEX  wndclass ;   // Объявление переменной, содержащей структуру, в которой хранится информация об окне

	 wndclass.cbSize        = sizeof (wndclass) ;                     // Установка размера структуры wndclass
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;               // Установка стиля класса окна
     wndclass.lpfnWndProc   = WndProc ;                               // Установка указателя на функцию окна
     wndclass.cbClsExtra    = 0 ;                                     // Установка дополнительной памяти в байтах для класса окна
     wndclass.cbWndExtra    = 0 ;                                     // Утановка дополнительной памяти для каждого окна этого класса
     wndclass.hInstance     = hInstance ;  					          // Установка дескриптора экземпляра приложения
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;      // Установка дескрипотра пиктограммы приложения
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;          // Установка дескриптора курсора для приложения
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ; // Установка дескриптора кисти для закраски окна
     wndclass.lpszMenuName  = NULL ;                                  // Установка указателя на строку с именем меня окна
     wndclass.lpszClassName = szAppName ;                             // Установка указателя на строку с именем класса окна
	 wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;      // Установка дескриптора малой пиктограммы

     RegisterClassEx (&wndclass) ; // Регистрация класса окна, атрибуты которого содержатся в переменной wndclass

     hwnd = CreateWindow (szAppName, "Mouse Button & Capture Demo", // Создание окна на основе заданных аттрибутов
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;

     ShowWindow (hwnd, iCmdShow) ; // Отображение окна
     UpdateWindow (hwnd) ; // Перерисовка содержимого окна

     while (GetMessage (&msg, NULL, 0, 0)) // Считывание сообщений до момента считывания сообщения wm_Quit (в этом случае функция возвращает 0)
          {
          TranslateMessage (&msg) ; // Преобразования сообщения от клавиатуры
          DispatchMessage (&msg) ;  // Пеpедача сообщения для функции окна
          }
     return msg.wParam ;
     }

void DrawBoxOutline (HWND hwnd, POINT ptBeg, POINT ptEnd)
     {
     HDC hdc ; // Объявление переменной, содержащей структуру данных с информацией о параметрах и атрибутах вывода графики на устройство (контекст устройства)

     hdc = GetDC (hwnd) ; // Cчитывание контекста дисплея для выполнения графических опеpаций в области пользовательского окна

     SetROP2 (hdc, R2_NOT) ; // Установка режима рисования
     SelectObject (hdc, GetStockObject (NULL_BRUSH)) ; // Выбор логического объекта для контекста устройства
     Rectangle (hdc, ptBeg.x, ptBeg.y, ptEnd.x, ptEnd.y) ; // Рисование прямоугольника с заданными параметрами

     ReleaseDC (hwnd, hdc) ; // Освобождение контекста устройства
     }

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
     {
     static BOOL  fBlocking, fValidBox ;
     static POINT ptBeg, ptEnd, ptBoxBeg, ptBoxEnd ; // Объявление переменной, содержащей структуру с информацией о координатах точки
     HDC          hdc ; // Объявление переменной, содержащей структуру данных с информацией о параметрах и атрибутах вывода графики на устройство (контекст устройства)
     PAINTSTRUCT  ps ; // Объявление переменной, содержащей структуру с информацией для рисования 

     switch (iMsg)
          {
          case WM_LBUTTONDOWN : // Случай поступления сообщения WM_LBUTTONDOWN (Указание угла прямоугльника)
               ptBeg.x = ptEnd.x = LOWORD (lParam) ; // Выделение из 32-битового целочисленного значения младшего слова (вычисление координаты x начала прямоугольника)
               ptBeg.y = ptEnd.y = HIWORD (lParam) ; // Выделение из 32-битового целочисленного значения младшего слова (вычисление координаты y начала прямоугольника)

               DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // Рисование прямоугольника с использованием растровой операции

               SetCapture (hwnd) ; // Посылка всего ввода от куpсоpа в окно Wnd
               SetCursor (LoadCursor (NULL, IDC_CROSS)) ; // Установка формы курсора

               fBlocking = TRUE ; // Установка флага, отвечающего за зажатие левой кнопки мыши
               return 0 ;

          case WM_MOUSEMOVE : // Случай поступления сообщения WM_MOUSEMOVE (Рисование прямоугольника)
               if (fBlocking)
                    {
                    SetCursor (LoadCursor (NULL, IDC_CROSS)) ; // Установка формы курсора

                    DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // Рисование прямоугольника с использованием растровой операции

                    ptEnd.x = LOWORD (lParam) ; // Выделение из 32-битового целочисленного значения младшего слова (вычисление координаты x конца прямоугольника)
                    ptEnd.y = HIWORD (lParam) ; // Выделение из 32-битового целочисленного значения младшего слова (вычисление координаты y конца прямоугольника)

                    DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // Рисование прямоугольника с использованием растровой операции
                    }
               return 0 ;

          case WM_LBUTTONUP : // Случай поступления сообщения WM_LBUTTONUP (Сохранение координат мыши и генерирование сообщения для вывода прямоугольника)
               if (fBlocking)
                    {
                    DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // Рисование прямоугольника с использованием растровой операции

                    ptBoxBeg   = ptBeg ;
                    ptBoxEnd.x = LOWORD (lParam) ; // Выделение из 32-битового целочисленного значения младшего слова (вычисление координаты x конца прямоугольника)
                    ptBoxEnd.y = HIWORD (lParam) ; // Выделение из 32-битового целочисленного значения младшего слова (вычисление координаты y конца прямоугольника)

                    ReleaseCapture () ; // Освобождение заголовка мыши и восстанавление ноpмальной обpаботки ввода
                    SetCursor (LoadCursor (NULL, IDC_ARROW)) ; // Установка формы курсора

                    fBlocking = FALSE ; // Установка флага, отвечающего за зажатие левой кнопки мыши
                    fValidBox  = TRUE ; // Установка флага, отвечающего за указание всех координат прямоугольника

                    InvalidateRect (hwnd, NULL, TRUE) ; // Добавление Rect к области обновления окна (область пользователя в окне становится недостоверной)
                    }
               return 0 ;

          case WM_CHAR : // Случай поступления сообщения WM_CHAR (Нажатие на клавишу)
               if (fBlocking & wParam == '\x1B')  // Проверка нажатие клавиши Esc
                    {
                    DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // Рисование прямоугольника с использованием растровой операции
                    ReleaseCapture () ; // Освобождение заголовка мыши и восстанавление ноpмальной обpаботки ввода
                    SetCursor (LoadCursor (NULL, IDC_ARROW)) ; // Установка формы курсора

                    fBlocking = FALSE ; // Установка флага, отвечающего за зажатие левой кнопки мыши
                    }
               return 0 ;

          case WM_PAINT : // Случай поступления сообщения WM_PAINT (Рисование прямоугольника)
               hdc = BeginPaint (hwnd, &ps) ; // Подготовка окна к pаскpаске в ответ на сообщение wm_Paint (Заполнение Paint инфоpмацией для pаскpаски)

               if (fValidBox)
                    {
                    SelectObject (hdc, GetStockObject (BLACK_BRUSH)) ; // Выбор логического объекта для контекста устройства
                    Rectangle (hdc, ptBoxBeg.x, ptBoxBeg.y, // Рисование прямоугольника с заданными параметрами
                                    ptBoxEnd.x, ptBoxEnd.y) ;
                    }

               if (fBlocking)
                    {
                    SetROP2 (hdc, R2_NOT) ; // Установка режима рисования
                    SelectObject (hdc, GetStockObject (NULL_BRUSH)) ; // Выбор логического объекта для контекста устройства
                    Rectangle (hdc, ptBeg.x, ptBeg.y, ptEnd.x, ptEnd.y) ; // Рисование прямоугольника с заданными параметрами
                    }

               EndPaint (hwnd, &ps) ; // Указание конца pаскpаски в Wnd
               return 0 ;

          case WM_DESTROY : // Случай поступления сообщения WM_DESTROY
               PostQuitMessage (0) ; // Напpавление сообщения wm_Quit в ответ на сообщение wm_Destroy
               return 0 ;
          }
	 return DefWindowProc (hwnd, iMsg, wParam, lParam) ; }// Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)