/*------------------------------------------------------------
   HELLOWIN.C -- Displays "Hello, Windows 95!" in client area
                 (c) Charles Petzold, 1996
  ------------------------------------------------------------*/
#undef UNICODE
#pragma comment (lib, "winmm.lib")

#include <windows.h> // ������������ ����, ���������� ����������� ��� ������� ����������� � API

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "HelloWin" ;
     HWND        hwnd ;       // ���������� ����������, ���������� ���������� ���� (���������� ����� ���������� ���� ���������)
     MSG         msg ;        // ���������� ����������, ���������� ��������� ��� ������ � ����������� � ��
     WNDCLASSEX  wndclass ;   // ���������� ����������, ���������� ���������, � ������� �������� ���������� �� ����

	 wndclass.cbSize        = sizeof (wndclass) ;                     // ��������� ������� ��������� wndclass
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;               // ��������� ����� ������ ����
     wndclass.lpfnWndProc   = WndProc ;                               // ��������� ��������� �� ������� ����
     wndclass.cbClsExtra    = 0 ;                                     // ��������� �������������� ������ � ������ ��� ������ ����
     wndclass.cbWndExtra    = 0 ;                                     // �������� �������������� ������ ��� ������� ���� ����� ������
     wndclass.hInstance     = hInstance ;  					          // ��������� ����������� ���������� ����������
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;      // ��������� ����������� ����������� ����������
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;          // ��������� ����������� ������� ��� ����������
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ; // ��������� ����������� ����� ��� �������� ����
     wndclass.lpszMenuName  = NULL ;                                  // ��������� ��������� �� ������ � ������ ���� ����
     wndclass.lpszClassName = szAppName ;                             // ��������� ��������� �� ������ � ������ ������ ����
	 wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;      // ��������� ����������� ����� �����������

     RegisterClassEx (&wndclass) ; // ����������� ������ ����, �������� �������� ���������� � ���������� wndclass

     hwnd = CreateWindow (szAppName,  // �������� ���� �� ������ �������� ����������
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

     ShowWindow (hwnd, iCmdShow) ; // ����������� ����
     UpdateWindow (hwnd) ; // ����������� ����������� ����

     while (GetMessage (&msg, NULL, 0, 0)) // ���������� ��������� �� ������� ���������� ��������� wm_Quit (� ���� ������ ������� ���������� 0)
          {
          TranslateMessage (&msg) ; // �������������� ��������� �� ����������
          DispatchMessage (&msg) ;  // ��p����� ��������� ��� ������� ����
          }
     return msg.wParam ;
     }

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
     {
     HDC         hdc ; // ���������� ����������, ���������� ��������� ������ � ����������� � ���������� � ��������� ������ ������� �� ���������� (�������� ����������)
     PAINTSTRUCT ps ; // ���������� ����������, ���������� ��������� � ����������� ��� ���������
     RECT        rect ; // ���������� ����������, ���������� ��������� � ����������� � ��������������

     switch (iMsg)
          {BOOL xx;
          case WM_CREATE : // ������ ����������� ��������� WM_CREATE
               xx=PlaySound ("Hellowin.wav", NULL, SND_FILENAME | SND_ASYNC) ; // ������������ ��������� ���������
               return 0 ;
          

          case WM_PAINT :  // ������ ����������� ��������� WM_PAINT (
	       hdc = BeginPaint (hwnd, &ps) ; // ���������� ���� � p���p���� � ����� �� ��������� wm_Paint (���������� Paint ����p������ ��� p���p����)

               GetClientRect (hwnd, &rect) ; // ���������� ���p����� ������� ������� ����
               
               DrawText (hdc, "Hello, Windows!", -1, &rect, // ��������� ������
                         DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;

	       EndPaint (hwnd, &ps) ; // �������� ����� p���p���� � Wnd
               return 0 ;

          case WM_DESTROY : // ������ ����������� ��������� WM_DESTROY
               PostQuitMessage (0) ; // ���p������� ��������� wm_Quit � ����� �� ��������� wm_Destroy
               return 0 ;
          }

     return DefWindowProc (hwnd, iMsg, wParam, lParam) ; // ����������� ���������� ��������� ��������� (������������ ������p���� ��p������ ��������� ��� ���������, ����p�� ���� �� ��p����������� �p�������� �������)
     }
