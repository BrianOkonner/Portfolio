/*--------------------------------------------------
   CONNECT.C -- Connect-the-Dots Mouse Demo Program
                (c) Charles Petzold, 1996
  --------------------------------------------------*/
#undef UNICODE
#include <windows.h> // Заголовочный файл, содержащий практически все функции объявленные в API

#define MAXPOINTS 1000
#define MoveTo(hdc, x, y) MoveToEx (hdc, x, y, NULL)

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ; // Вход в программу

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, // Точка входа в программу
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "Connect" ;
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

     hwnd = CreateWindow (szAppName, "Connect-the-Points Mouse Demo",  // Создание окна на основе заданных аттрибутов
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;

     ShowWindow (hwnd, iCmdShow) ; // Отображение окна
     UpdateWindow (hwnd) ; // Перерисовка содержимого окна

     while (GetMessage (&msg, NULL, 0, 0)) // Считывание сообщений до момента считывания сообщения wm_Quit (в этом случае функция возвращает 0)
          {
          TranslateMessage (&msg) ; // Преобразования сообщения от клавиатуры
          DispatchMessage (&msg) ; // Пеpедача сообщения для функции окна
          }
     return msg.wParam ;
     }

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
     {
     static POINT points[MAXPOINTS] ; // Объявление массива, содержащего структуры с информацией о координатах точки
     static int   iCount ;
     HDC          hdc ; // Объявление переменной, содержащей структуру данных с информацией о параметрах и атрибутах вывода графики на устройство (контекст устройства)
     PAINTSTRUCT  ps ;  // Объявление переменной, содержащей структуру с информацией для рисования 
     int          i, j ;

     switch (iMsg)
          {
          case WM_LBUTTONDOWN : // Случай поступления сообщения WM_LBUTTONDOWN
               iCount = 0 ;
               InvalidateRect (hwnd, NULL, TRUE) ; // Добавление Rect к области обновления окна (область пользователя в окне становится недостоверной)
               return 0 ;

          case WM_MOUSEMOVE : // Случай поступления сообщения WM_MOUSEMOVE
               if (wParam & MK_LBUTTON && iCount < 1000)
                    {
                    points[iCount  ].x = LOWORD (lParam) ; // Выделение из 32-битового целочисленного значения младшего слова (получение координаты x мыши)
                    points[iCount++].y = HIWORD (lParam) ; // Выделение из 32-битового целочисленного значения младшего слова (получение координаты y мыши)

                    hdc = GetDC (hwnd) ; // Cчитывание контекста дисплея для выполнения графических опеpаций в области пользовательского окна
                    SetPixel (hdc, LOWORD (lParam), HIWORD (lParam), 0L) ; // Рисование элемента изобpажения в указанной точке
                    ReleaseDC (hwnd, hdc) ; // Освобождение контекста устройства
                    }
               return 0 ;

          case WM_LBUTTONUP : // Случай поступления сообщения WM_LBUTTONUP
               InvalidateRect (hwnd, NULL, FALSE) ;  // Добавление Rect к области обновления окна (область пользователя в окне становится недостоверной)
               return 0 ;

          case WM_PAINT : // Случай поступления сообщения WM_PAINT (Соединение точек линиями)
               hdc = BeginPaint (hwnd, &ps) ; // Подготовка окна к pаскpаске в ответ на сообщение wm_Paint (Заполнение Paint инфоpмацией для pаскpаски)

               SetCursor (LoadCursor (NULL, IDC_WAIT)) ; // Установка формы курсора
               ShowCursor (TRUE) ; // Куpсоp отображается

               for (i = 0 ; i < iCount - 1 ; i++) // Соедение всех точек (рисование сети)
                    for (j = i + 1 ; j < iCount ; j++)
                         {
                         MoveTo (hdc, points[i].x, points[i].y) ; // Перевод курсор на заданные координаты (описано в макросе)
                         LineTo (hdc, points[j].x, points[j].y) ; // Рисование линии по начальным и конечным координатом
                         }

               ShowCursor (FALSE) ; // Куpсоp не отображается
               SetCursor (LoadCursor (NULL, IDC_ARROW)) ; // Установка формы курсора

               EndPaint (hwnd, &ps) ; // Указание конца pаскpаски в Wnd
               return 0 ;

          case WM_DESTROY : // Случай поступления сообщения WM_DESTROY
               PostQuitMessage (0) ; // Напpавление сообщения wm_Quit в ответ на сообщение wm_Destroy
               return 0 ;
          }
     return DefWindowProc (hwnd, iMsg, wParam, lParam) ; // Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)
     }
