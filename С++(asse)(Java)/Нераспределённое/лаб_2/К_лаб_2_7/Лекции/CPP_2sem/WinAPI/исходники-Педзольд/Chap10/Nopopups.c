/*-------------------------------------------------
   NOPOPUPS.C -- Demonstrates No-Popup Nested Menu
                 (c) Charles Petzold, 1996
  -------------------------------------------------*/

#include <windows.h>
#include "nopopups.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "NoPopUps" ;
     HWND        hwnd ;
     MSG         msg ;
     WNDCLASSEX  wndclass ;

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

     hwnd = CreateWindow (szAppName, "No-Popup Nested Menu Demonstration",
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
     static HMENU hMenuMain, hMenuEdit, hMenuFile ;
     HINSTANCE    hInstance ;

     switch (iMsg)
          {
          case WM_CREATE :
               hInstance = (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE) ;

               hMenuMain = LoadMenu (hInstance, "MenuMain") ;
               hMenuFile = LoadMenu (hInstance, "MenuFile") ;
               hMenuEdit = LoadMenu (hInstance, "MenuEdit") ;

               SetMenu (hwnd, hMenuMain) ;
               return 0 ;

          case WM_COMMAND :
               switch (LOWORD (wParam))
                    {
                    case IDM_MAIN :
                         SetMenu (hwnd, hMenuMain) ;
                         return 0 ;

                    case IDM_FILE :
                         SetMenu (hwnd, hMenuFile) ;
                         return 0 ;

                    case IDM_EDIT :
                         SetMenu (hwnd, hMenuEdit) ;
                         return 0 ;

                    case IDM_NEW :
                    case IDM_OPEN :
                    case IDM_SAVE :
                    case IDM_SAVEAS :
                    case IDM_UNDO :
                    case IDM_CUT :
                    case IDM_COPY :
                    case IDM_PASTE :
                    case IDM_DEL :
                         MessageBeep (0) ;
                         return 0 ;
                    }
               break ;

          case WM_DESTROY :
               SetMenu (hwnd, hMenuMain) ;
               DestroyMenu (hMenuFile) ;
               DestroyMenu (hMenuEdit) ;

               PostQuitMessage (0) ;
               return 0 ;
          }
     return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
     }
