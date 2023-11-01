/*------------------------------------------------------------
//Коваленко
   HELLOWIN.C -- Displays "Hello, Windows 95!" in client area
                 (c) Charles Petzold, 1996
  ------------------------------------------------------------*/
#undef UNICODE

#include <windows.h> // Заголовочный файл, содержащий практически все функции объявленные в API
#pragma comment (lib, "winmm.lib")
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
#define ID_BUTTON1 3001
#define ID_BUTTON2 3002
HINSTANCE hInstance;
 static int line;

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
	 static HWND hButton2;
	



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
 {
			  CreateWindow("button","группа кнопок",WS_CHILD|WS_VISIBLE|BS_GROUPBOX,200,300,390,120,hwnd,(HMENU)0,hInstance,NULL);
			  CreateWindow("button","верхняя кнопка",WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,220,330,250,30,hwnd,(HMENU) ID_BUTTON1,hInstance,NULL);
			  CreateWindow("button","нижняя кнопка",WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,220,380,150,30,hwnd,(HMENU) ID_BUTTON2,hInstance,NULL);
			  
              return 0 ;
			  }

          

		  case WM_COMMAND:
			  {
				  switch(LOWORD(wParam))
				  {case ID_BUTTON1:
				//  hdc=GetDC(hwnd);
				//	LineTo(hdc,line,line+100);
				//	line=line+100;
					{MessageBox(hwnd,"нажата верхняя","message",MB_OK);
					
					SendMessage((HWND)lParam,BM_SETSTATE,FALSE,0);
					
					return 0;	
					}


					case ID_BUTTON2:
					{int i=5;
					
					MessageBox(hwnd,"нажата нижняя","message",MB_OK);
					SendMessage((HWND)lParam,BM_SETSTATE,FALSE,0);
					
					return 0;	
					}







					}





			  }

	       
          case WM_DESTROY : // Случай поступления сообщения WM_DESTROY
               PostQuitMessage (0) ; // Напpавление сообщения wm_Quit в ответ на сообщение wm_Destroy
               return 0 ;
          }

     return DefWindowProc (hwnd, iMsg, wParam, lParam) ; // Возвращение результата обработки сообщений (обеспечивает стандаpтную обpаботку сообщений для сообщений, котоpые явно не обpабатываются пpикладной задачей)
     }
