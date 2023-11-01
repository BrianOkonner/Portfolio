/*���������� ������� ������� ����� 8 ������ 
������ ���� 
�������� :
������ ��������� ����������� �������� ���������
� �������� �������� ������  � ������� ��� ��������*/


#undef UNICODE
#pragma comment (lib, "winmm.lib")

#include <windows.h> // ������������ ����, ���������� ����������� ��� ������� ����������� � API
#include <stack>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <clocale>
#include <tchar.h>
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

double preobr(char *string, char *string2);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "win32_app_�������� ������" ;
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

     //RegisterClassEx (&wndclass) ; // ����������� ������ ����, �������� �������� ���������� � ���������� wndclass
	 if (!RegisterClassEx (&wndclass))
    {
        MessageBox(NULL,
            "Call to RegisterClassEx failed!",
            "Win32 Guided Tour",
            NULL);

        return 1;
    }

     hwnd = CreateWindow (szAppName,  // �������� ���� �� ������ �������� ����������
		     szAppName, 
                   WS_OVERLAPPEDWINDOW,
                   CW_USEDEFAULT, 
                   CW_USEDEFAULT,      
                   500,        
                   300,       
                   NULL,             
                   NULL,            
                   hInstance,            
		   NULL) ;		   

	  if (!hwnd)
    {
        MessageBox(NULL,
            "Call to CreateWindow failed!",
            "Win32 Guided Tour",
            NULL);

        return 1;
    }

     ShowWindow (hwnd, iCmdShow) ; // ����������� ����
     UpdateWindow (hwnd) ; // ����������� ����������� ����

     while (GetMessage (&msg, NULL, 0, 0)) // ���������� ��������� �� ������� ���������� ��������� wm_Quit (� ���� ������ ������� ���������� 0)
          {
          TranslateMessage (&msg) ; // �������������� ��������� �� ����������
          DispatchMessage (&msg) ;  // ��p����� ��������� ��� ������� ����
          }
     return msg.wParam ;
     }

LRESULT CALLBACK WndProc (HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
 {
     HDC         hdc ; // ���������� ����������, ���������� ��������� ������ � ����������� � ���������� � ��������� ������ ������� �� ���������� (�������� ����������)
     PAINTSTRUCT ps ; // ���������� ����������, ���������� ��������� � ����������� ��� ���������
     RECT        rect ; // ���������� ����������, ���������� ��������� � ����������� � ��������������
	 static HWND button, edit,editrez,editzap;
	 HFONT hFont = CreateFont(32,0,0,0,0,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, DEFAULT_PITCH,NULL);
     switch (Message)
     {
		 
		case WM_CREATE : // ������ ����������� ��������� WM_CREATE
			button=CreateWindow(TEXT("button"),TEXT("���������"),WS_CHILD|WS_VISIBLE,40,125,300,40,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		edit=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,40,65,300,40,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		editrez=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,350,65,90,40,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		editzap=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,40,200,300,40,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			return 0 ;
          
			case WM_COMMAND:
		if(HIWORD(wParam)==BN_CLICKED)
		{
			TCHAR *str,*str1;
			__int64 n;
			int len,lenstr;
			len=GetWindowTextLength(edit)+10;
			lenstr=GetWindowTextLength(edit);

			str=new TCHAR[len+1];
			str1=new TCHAR[len+1];
			GetWindowText(edit,str,len+1);
			//double rez=preobr(str,str1);
			char *rez=new char[11];
				char *rezs=new char[11];

			strcpy(rezs,str);
			strcat(rezs,str);
			int len2=lenstr*2;
			//wsprintf(rezs, TEXT("%i"), rez);
			sprintf(rez, "%d", len2);
			
			if (len!=0)
			{
				char *mes=new char [150];
				
				strcpy_s(mes, 150, "��������� = ");
				SetWindowText(editrez, rezs);
				//strcpy_s(mes, 150, "��������� = ");
				//strcat_s(mes, 150, rez);
				
			//	strcat_s(mes, 150, "\n�������� ������ - ");
				SetWindowText(editzap, rez);
			//	strcat_s(mes, 150, rez);
				
				TCHAR *res=new TCHAR[150];
				
				size_t size=0;
				setlocale(LC_ALL, "Russian");
				
			//	MessageBox(hwnd, mes, TEXT("���������"), MB_OK|MB_ICONINFORMATION);
			}
			
		}
		if(LOWORD(wParam)==1)        
			if(HIWORD(wParam)==EN_ERRSPACE||HIWORD(wParam)==EN_MAXTEXT)
				MessageBox(hwnd,TEXT("�������� ������ �����"),TEXT("������"),MB_OK|MB_ICONSTOP);
			return 0;

		case WM_PAINT :  // ������ ����������� ��������� WM_PAINT (
		hdc = BeginPaint (hwnd, &ps) ; // ���������� ���� � p���p���� � ����� �� ��������� wm_Paint (���������� Paint ����p������ ��� p���p����)

			
		SelectObject(hdc,hFont);
        TextOut(hdc,
            93, 15,
            TEXT("������� ���������"), strlen("������� ���������"));
		EndPaint (hwnd, &ps) ; // �������� ����� p���p���� � Wnd
			return 0 ;

		case WM_DESTROY : // ������ ����������� ��������� WM_DESTROY
			PostQuitMessage (0) ; // ���p������� ��������� wm_Quit � ����� �� ��������� wm_Destroy
			return 0 ;
      }

     return DefWindowProc (hwnd, Message, wParam, lParam) ; // ����������� ���������� ��������� ��������� (������������ ������p���� ��p������ ��������� ��� ���������, ����p�� ���� �� ��p����������� �p�������� �������)
     }


