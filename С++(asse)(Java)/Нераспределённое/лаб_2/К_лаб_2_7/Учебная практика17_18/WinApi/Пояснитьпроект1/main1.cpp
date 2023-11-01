//
//Вывод графической информации с использованием WinAPI осуществляется с помощью контекста устройства (тип HDC, Handle of Device Context):
//1 получаем контекст вывода нашей формы;
//2 создаем совместимый контекст на который будем выводить изображение (используется для двойной буферизации);
//3 создаем кисть для закраски фона нужным цветом;
//4 закрашиваем клиентскую область цветом фона;
//5 удаляем созданную кисть;
//6 рисуем на теневом контексте (hCmpDC);
//7 копируем изображение на реальный контекст вывода ‘цвет в цвет’;
//8 освобождаем созданные системные объекты.

//Прим. Важно не забывать разрушать созданные кисти (brush), карандаши (pen), регионы (region) и прочие графические объекты, т.к. это ведет к сбою работы программы.	
#include <windows.h>
#undef UNICODE
#pragma comment (lib, "winmm.lib")
// Функция простой отрисовки изображения
void DrawImage(HDC hDC,     // Дескриптор контекста где рисуем
        HBITMAP hBitmap,    // Дескриптор изображения, который рисуем
        int x,              // Координаты отрисовки
        int y)
{
    // Создаем контекст для отрисовываемого изображения
    HDC     hBDC        = CreateCompatibleDC(hDC);
    // Назначаем изображение в этот контекст, сохраняем предыдущее изображение в hOldBitmap
    HGDIOBJ hOldBitmap  = SelectObject(hBDC, hBitmap);
    // Объявляем переменную типа струкрура BITMAP
    BITMAP bInfo;
    // Записываем в поля переменной bInfo информацию об изображении.
    // Нас интересует ширина и высота
    GetObject(hBitmap, sizeof(bInfo), &bInfo);
    // Копирование содержимого контекста изображения (hBDC) в целевой контекст(hDC)
    BitBlt(hDC,                                 // Дескриптор целевого контекста (куда рисуем)
            x,y,bInfo.bmWidth,bInfo.bmHeight,   // Прямоуглоьная область целевого контекста
            hBDC,                               // Дескриптор исходного контекста (который рисуем)
            0,0,                                // Координаты левого верхнего угла исходного контекста
            SRCCOPY);                           // Тип наложения (SRCCOPY - замена пикселей целевого на пиксели исходного контекстов)
    // Восстанавливаем предыдущее изображение в созданный контекст
    SelectObject(hBDC, hOldBitmap);
    // Удаляем контекст изображения - он больше не нужен
    DeleteDC(hBDC);
}
const double PI = 3.141592653;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

char szClassName[] = "CG_WAPI_Template";

////////////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
      HWND hWnd;  
      MSG lpMsg;
      WNDCLASS wc;

      // Заполняем структуру класса окна
      wc.style         = CS_HREDRAW | CS_VREDRAW;
      wc.lpfnWndProc   = WndProc;
      wc.cbClsExtra    = 0;
      wc.cbWndExtra    = 0;
      wc.hInstance     = hInstance;
      wc.hIcon         = NULL;      
      wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
      wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
      wc.lpszMenuName  = NULL;
      wc.lpszClassName = szClassName;
 
      // Регистрируем класс окна
      if (!RegisterClass(&wc))
      {
            MessageBox(NULL, "Не могу зарегистрировать класс окна!", "Ошибка", MB_OK);
            return 0;
      }

      // Создаем основное окно приложения
      hWnd = CreateWindow( 
            szClassName,                // Имя класса                    
            "Шаблон WinAPI приложения", // Текст заголовка 
            WS_OVERLAPPEDWINDOW,        // Стиль окна                                              
            50,   50,                   // Позиция левого верхнего угла   
            600,  600,                  // Ширина и высота окна     
            (HWND) NULL,                // Указатель на родительское окно NULL     
            (HMENU) NULL,               // Используется меню класса окна               
            (HINSTANCE)hInstance,       // Указатель на текущее приложение
            NULL    );                  // Передается в качестве lParam в событие WM_CREATE

      if (!hWnd) 
      {
            MessageBox(NULL, "Не удается создать главное окно!", "Ошибка", MB_OK);
            return 0;
      }

      // Показываем наше окно
      ShowWindow(hWnd, nCmdShow); 
      UpdateWindow(hWnd);

      // Выполняем цикл обработки сообщений до закрытия приложения
      while (GetMessage(&lpMsg, NULL, 0, 0))  
      {
            TranslateMessage(&lpMsg);
            DispatchMessage(&lpMsg);
      }
      return (lpMsg.wParam);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
      PAINTSTRUCT ps;
      RECT Rect;
      HDC hdc, hCmpDC;
      HBITMAP hBmp;

      switch (messg)
      {
            case WM_PAINT:

                 GetClientRect(hWnd, &Rect);
                  hdc = BeginPaint(hWnd, &ps);

                  // Создание теневогоs контекста для двойной буфферизации
                  hCmpDC = CreateCompatibleDC(hdc);
                  hBmp = CreateCompatibleBitmap(hdc, Rect.right - Rect.left,
                        Rect.bottom - Rect.top);
                  SelectObject(hCmpDC, hBmp);
 
                  // Закраска фоновым цветом
                  LOGBRUSH br;
                  br.lbStyle = BS_SOLID;
                  //br.lbColor = 0xEECCCC;
				   br.lbColor = 0xEE0001;
                  HBRUSH brush;
                  brush = CreateBrushIndirect(&br);
                  FillRect(hCmpDC, &Rect, brush);
                  DeleteObject(brush);

                  // Здесь рисуем на контексте hCmpDC

                  // Копируем изображение из теневого контекста на экран
                  SetStretchBltMode(hdc, COLORONCOLOR);
					
				  for (int a=1; a<200;a+=10)
				  {
                  BitBlt(hdc,					// Дескриптор целевого контекста (куда рисуем)
					  a, a, a+10,a+10,			// Прямоуглоьная область целевого контекста
                        hCmpDC,				    // Дескриптор исходного контекста (который рисуем)
						0, 0,				    // Координаты левого верхнего угла исходного контекста
						SRCCOPY);	}			// Тип наложения (SRCCOPY - замена пикселей целевого на пиксели исходного контекстов)
     // ИЛИ ТАК
	/*			     BitBlt(hdc,												// Дескриптор целевого контекста (куда рисуем)
					  0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top,// Прямоуглоьная область целевого контекста
                        hCmpDC,										      // Дескриптор исходного контекста (который рисуем)
						0, 0,											 // Координаты левого верхнего угла исходного контекста
						SRCCOPY);					// Тип наложения (SRCCOPY - замена пикселей целевого на пиксели исходного контекстов)
   

*/
    
                         
    // Восстанавливаем предыдущее изображение в созданный контекст      SelectObject(hBDC, hOldBitmap);
    // Удаляем контекст изображения - он больше не нужен                DeleteDC(hBDC);

                  // Удаляем ненужные системные объекты
                  DeleteDC(hCmpDC);
                  DeleteObject(hBmp);
                  hCmpDC = NULL; 

                  EndPaint(hWnd, &ps);
                  break;

            case WM_DESTROY:
                  PostQuitMessage(0);
                  break;

            default:
                  return (DefWindowProc(hWnd, messg, wParam, lParam));
      }
      return (0);
}