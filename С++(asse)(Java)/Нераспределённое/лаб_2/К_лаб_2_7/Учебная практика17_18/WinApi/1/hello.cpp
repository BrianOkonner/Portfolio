/*------------------------------------------------------------
   HELLOWIN.C -- Displays "Hello, Windows 95!" in client area
                 (c) Charles Petzold, 1996
  ------------------------------------------------------------*/
#undef UNICODE
#pragma comment (lib, "winmm.lib")

#include <windows.h> // Заголовочный файл, содержащий практически все функции объявленные в API

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "HelloWin" ;
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

     hwnd = CreateWindow (szAppName,  // Создание окна на основе заданных аттрибутов
		     "The Hello Program", 
                   WS_OVERLAPPEDWINDOW,
                   CW_USEDEFAULT, 
                   CW_USEDEFAULT,      
                   CW_USEDEFAULT,         
                   CW_USEDEFAULT,       
                   NULL,             
                   NULL,            
                   hInstance,            
		   NULL) ;		   

     ShowWindow (hwnd, iCmdShow) ; // Отображение окна
     UpdateWindow (hwnd) ; // Перерисовка содержимого окна

     while (GetMessage (&msg, NULL, 0, 0)) // Считывание сообщений до момента считывания сообщения wm_Quit (в этом случае функция возвращает 0)
          {
          TranslateMessage (&msg) ; // Преобразования сообщения от клавиатуры
          DispatchMessage (&msg) ;  // Пеpедача сообщения для функции окна
          }
     return msg.wParam ;
     }

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
     {
     HDC         hdc ; // Объявление переменной, содержащей структуру данных с информацией о параметрах и атрибутах вывода графики на устройство (контекст устройства)
     PAINTSTRUCT ps ; // Объявление переменной, содержащей структуру с информацией для рисования
     RECT        rect ; // Объявление переменной, содержащей структуру с информацией о прямоугольнике

     switch (iMsg)
          {BOOL xx;
          case WM_CREATE : // Случай поступления сообщения WM_CREATE
               xx=PlaySound ("Hellowin.wav", NULL, SND_FILENAME | SND_ASYNC) ; // Проигрывание звукового сообщения
               return 0 ;
          

          case WM_PAINT :  // Случай поступления сообщения WM_PAINT (
	       hdc = BeginPaint (hwnd, &ps) ; // Подготовка окна к pаскpаске в ответ на сообщение wm_Paint (Заполнение Paint инфоpмацией для pаскpаски)

               GetClientRect (hwnd, &rect) ; // Считывание кооpдинат рабочей области окна
               
               DrawText (hdc, "Hello, Windows!", -1, &rect, // Рисование текста
                         DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;

	       EndPaint (hwnd, &ps) ; // Указание конца pаскpаски в Wnd
               return 0 ;

          case WM_DESTROY : // Случай поступления сообщения WM_DESTROY
               PostQuitMessage (0) ; // Напpавление сообщения wm_Quit в ответ на сообщение wm_Destroy
               return 0 ;
          }

     return DefWindowProc (hwnd, iMsg, wParam, lParam) ; // Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)
     }
