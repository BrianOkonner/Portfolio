#include <windows.h>
#pragma comment(lib,"winmm.lib")
#define ID_BUTTON1 3001
HINSTANCE hInstance;
 /*static COLORREF cl1;
  static COLORREF cl2;
  cl1=GetSysColor(COLOR_HIGHLIGHTTEXT);
  cl2=GetSysColor(COLOR_HIGHLIGHTTEXT);*/

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

char szAppName[] = "PopPad1" ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
     {
     HWND       hwnd ;
     MSG        msg ;
     WNDCLASSEX wndclass ;

     wndclass.cbSize        = sizeof (wndclass) ;
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;
     wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;
     RegisterClassEx (&wndclass) ;

     hwnd = CreateWindow (szAppName, szAppName,
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;

     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ; 

     while (GetMessage (&msg, NULL, 0, 0))
          {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
          }
     return msg.wParam ;
     }

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
     {
     static HWND hwndEdit ;
char ch[80]="empty";
     switch (iMsg)
          {
          case WM_CREATE :
			   
               hwndEdit = CreateWindow ("edit", NULL,
                         WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL |
                              WS_BORDER | ES_LEFT | ES_MULTILINE |
                              ES_AUTOHSCROLL | ES_AUTOVSCROLL,
                         100, 100, 100, 100,
                         hwnd, (HMENU) 1,
                         ((LPCREATESTRUCT) lParam) -> hInstance, NULL) ;
			   CreateWindow("button","������� ������",WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,320,330,250,30,hwnd,(HMENU) ID_BUTTON1,hInstance,NULL);
               return 0 ;

          case WM_SETFOCUS :
               SetFocus (hwndEdit) ;
               return 0 ;

          case WM_SIZE : 
               MoveWindow (hwndEdit, 100, 100, 200,
                                           500, TRUE) ;
               return 0 ;

          case WM_COMMAND :
                 switch(LOWORD(wParam))
				 {case 1:
                    if (HIWORD (wParam) == EN_ERRSPACE ||
                        HIWORD (wParam) == EN_MAXTEXT)
                              MessageBox (hwnd, "Edit control out of space.",
                                          szAppName, MB_OK | MB_ICONSTOP) ;
					return 0;
		  case ID_BUTTON1:
			  {
				//  HDC w;w=GetDC(hwnd);COLORREF q;
				//  q=SetTextColor(w,q);
				  MessageBox(hwnd,"������ �������","message",MB_OK);
					
					SendMessage((HWND)lParam,BM_SETSTATE,FALSE,0);
					SendMessage(hwndEdit,EM_GETLINE,FALSE,(LPARAM)ch);

					strcat(ch,"111");
					//->SetTextColor(RGB(255, 0, 0));


					SetWindowText(hwndEdit,ch);
			  }}
               return 0 ;
          case WM_DESTROY :
               PostQuitMessage (0) ;
               return 0 ;
          }
     return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
     }
