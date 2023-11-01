/*---------------------------------------------------
   BLOKOUT2.C -- Mouse Button & Capture Demo Program
                 (c) Charles Petzold, 1996
  ---------------------------------------------------*/
#undef UNICODE
#pragma comment (lib, "winmm.lib")
#include <windows.h>  // ������������ ����, ���������� ����������� ��� ������� ����������� � API

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;   // ���� � ���������

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,   // ����� ����� � ���������
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "BlokOut2" ; 
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

     hwnd = CreateWindow (szAppName, "Mouse Button & Capture Demo", // �������� ���� �� ������ �������� ����������
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;

     ShowWindow (hwnd, iCmdShow) ; // ����������� ����
     UpdateWindow (hwnd) ; // ����������� ����������� ����

     while (GetMessage (&msg, NULL, 0, 0)) // ���������� ��������� �� ������� ���������� ��������� wm_Quit (� ���� ������ ������� ���������� 0)
          {
          TranslateMessage (&msg) ; // �������������� ��������� �� ����������
          DispatchMessage (&msg) ;  // ��p����� ��������� ��� ������� ����
          }
     return msg.wParam ;
     }

void DrawBoxOutline (HWND hwnd, POINT ptBeg, POINT ptEnd)
     {
     HDC hdc ; // ���������� ����������, ���������� ��������� ������ � ����������� � ���������� � ��������� ������ ������� �� ���������� (�������� ����������)

     hdc = GetDC (hwnd) ; // C��������� ��������� ������� ��� ���������� ����������� ���p���� � ������� ����������������� ����

     SetROP2 (hdc, R2_NOT) ; // ��������� ������ ���������
     SelectObject (hdc, GetStockObject (NULL_BRUSH)) ; // ����� ����������� ������� ��� ��������� ����������
     Rectangle (hdc, ptBeg.x, ptBeg.y, ptEnd.x, ptEnd.y) ; // ��������� �������������� � ��������� �����������

     ReleaseDC (hwnd, hdc) ; // ������������ ��������� ����������
     }

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
     {
     static BOOL  fBlocking, fValidBox ;
     static POINT ptBeg, ptEnd, ptBoxBeg, ptBoxEnd ; // ���������� ����������, ���������� ��������� � ����������� � ����������� �����
     HDC          hdc ; // ���������� ����������, ���������� ��������� ������ � ����������� � ���������� � ��������� ������ ������� �� ���������� (�������� ����������)
     PAINTSTRUCT  ps ; // ���������� ����������, ���������� ��������� � ����������� ��� ��������� 

     switch (iMsg)
          {
          case WM_LBUTTONDOWN : // ������ ����������� ��������� WM_LBUTTONDOWN (�������� ���� �������������)
               ptBeg.x = ptEnd.x = LOWORD (lParam) ; // ��������� �� 32-�������� �������������� �������� �������� ����� (���������� ���������� x ������ ��������������)
               ptBeg.y = ptEnd.y = HIWORD (lParam) ; // ��������� �� 32-�������� �������������� �������� �������� ����� (���������� ���������� y ������ ��������������)

               DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // ��������� �������������� � �������������� ��������� ��������

               SetCapture (hwnd) ; // ������� ����� ����� �� ��p��p� � ���� Wnd
               SetCursor (LoadCursor (NULL, IDC_CROSS)) ; // ��������� ����� �������

               fBlocking = TRUE ; // ��������� �����, ����������� �� ������� ����� ������ ����
               return 0 ;

          case WM_MOUSEMOVE : // ������ ����������� ��������� WM_MOUSEMOVE (��������� ��������������)
               if (fBlocking)
                    {
                    SetCursor (LoadCursor (NULL, IDC_CROSS)) ; // ��������� ����� �������

                    DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // ��������� �������������� � �������������� ��������� ��������

                    ptEnd.x = LOWORD (lParam) ; // ��������� �� 32-�������� �������������� �������� �������� ����� (���������� ���������� x ����� ��������������)
                    ptEnd.y = HIWORD (lParam) ; // ��������� �� 32-�������� �������������� �������� �������� ����� (���������� ���������� y ����� ��������������)

                    DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // ��������� �������������� � �������������� ��������� ��������
                    }
               return 0 ;

          case WM_LBUTTONUP : // ������ ����������� ��������� WM_LBUTTONUP (���������� ��������� ���� � ������������� ��������� ��� ������ ��������������)
               if (fBlocking)
                    {
                    DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // ��������� �������������� � �������������� ��������� ��������

                    ptBoxBeg   = ptBeg ;
                    ptBoxEnd.x = LOWORD (lParam) ; // ��������� �� 32-�������� �������������� �������� �������� ����� (���������� ���������� x ����� ��������������)
                    ptBoxEnd.y = HIWORD (lParam) ; // ��������� �� 32-�������� �������������� �������� �������� ����� (���������� ���������� y ����� ��������������)

                    ReleaseCapture () ; // ������������ ��������� ���� � �������������� ��p������� ��p������ �����
                    SetCursor (LoadCursor (NULL, IDC_ARROW)) ; // ��������� ����� �������

                    fBlocking = FALSE ; // ��������� �����, ����������� �� ������� ����� ������ ����
                    fValidBox  = TRUE ; // ��������� �����, ����������� �� �������� ���� ��������� ��������������

                    InvalidateRect (hwnd, NULL, TRUE) ; // ���������� Rect � ������� ���������� ���� (������� ������������ � ���� ���������� �������������)
                    }
               return 0 ;

          case WM_CHAR : // ������ ����������� ��������� WM_CHAR (������� �� �������)
               if (fBlocking & wParam == '\x1B')  // �������� ������� ������� Esc
                    {
                    DrawBoxOutline (hwnd, ptBeg, ptEnd) ; // ��������� �������������� � �������������� ��������� ��������
                    ReleaseCapture () ; // ������������ ��������� ���� � �������������� ��p������� ��p������ �����
                    SetCursor (LoadCursor (NULL, IDC_ARROW)) ; // ��������� ����� �������

                    fBlocking = FALSE ; // ��������� �����, ����������� �� ������� ����� ������ ����
                    }
               return 0 ;

          case WM_PAINT : // ������ ����������� ��������� WM_PAINT (��������� ��������������)
               hdc = BeginPaint (hwnd, &ps) ; // ���������� ���� � p���p���� � ����� �� ��������� wm_Paint (���������� Paint ����p������ ��� p���p����)

               if (fValidBox)
                    {
                    SelectObject (hdc, GetStockObject (BLACK_BRUSH)) ; // ����� ����������� ������� ��� ��������� ����������
                    Rectangle (hdc, ptBoxBeg.x, ptBoxBeg.y, // ��������� �������������� � ��������� �����������
                                    ptBoxEnd.x, ptBoxEnd.y) ;
                    }

               if (fBlocking)
                    {
                    SetROP2 (hdc, R2_NOT) ; // ��������� ������ ���������
                    SelectObject (hdc, GetStockObject (NULL_BRUSH)) ; // ����� ����������� ������� ��� ��������� ����������
                    Rectangle (hdc, ptBeg.x, ptBeg.y, ptEnd.x, ptEnd.y) ; // ��������� �������������� � ��������� �����������
                    }

               EndPaint (hwnd, &ps) ; // �������� ����� p���p���� � Wnd
               return 0 ;

          case WM_DESTROY : // ������ ����������� ��������� WM_DESTROY
               PostQuitMessage (0) ; // ���p������� ��������� wm_Quit � ����� �� ��������� wm_Destroy
               return 0 ;
          }
	 return DefWindowProc (hwnd, iMsg, wParam, lParam) ; }// ����������� ���������� ��������� ��������� (������������ ������p���� ��p������ ��������� ��� ���������, ����p�� ���� �� ��p����������� �p�������� �������)