/*------------------------------------------------------------
//���������
   HELLOWIN.C -- Displays "Hello, Windows 95!" in client area
                 (c) Charles Petzold, 1996
  ------------------------------------------------------------*/
#undef UNICODE

#include <windows.h> // ������������ ����, ���������� ����������� ��� ������� ����������� � API
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
	 static HWND hButton2;
	



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
 {
			  CreateWindow("button","������ ������",WS_CHILD|WS_VISIBLE|BS_GROUPBOX,200,300,390,120,hwnd,(HMENU)0,hInstance,NULL);
			  CreateWindow("button","������� ������",WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,220,330,250,30,hwnd,(HMENU) ID_BUTTON1,hInstance,NULL);
			  CreateWindow("button","������ ������",WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,220,380,150,30,hwnd,(HMENU) ID_BUTTON2,hInstance,NULL);
			  
              return 0 ;
			  }

          

		  case WM_COMMAND:
			  {
				  switch(LOWORD(wParam))
				  {case ID_BUTTON1:
				//  hdc=GetDC(hwnd);
				//	LineTo(hdc,line,line+100);
				//	line=line+100;
					{MessageBox(hwnd,"������ �������","message",MB_OK);
					
					SendMessage((HWND)lParam,BM_SETSTATE,FALSE,0);
					
					return 0;	
					}


					case ID_BUTTON2:
					{int i=5;
					
					MessageBox(hwnd,"������ ������","message",MB_OK);
					SendMessage((HWND)lParam,BM_SETSTATE,FALSE,0);
					
					return 0;	
					}







					}





			  }

	       
          case WM_DESTROY : // ������ ����������� ��������� WM_DESTROY
               PostQuitMessage (0) ; // ���p������� ��������� wm_Quit � ����� �� ��������� wm_Destroy
               return 0 ;
          }

     return DefWindowProc (hwnd, iMsg, wParam, lParam) ; // ����������� ���������� ��������� ��������� (������������ ������p���� ��p������ ��������� ��� ���������, ����p�� ���� �� ��p����������� �p�������� �������)
     }
