//���������� ������ ���� 
//3 �������
#undef UNICODE
#pragma comment (lib, "winmm.lib")

#include <windows.h> // ������������ ����, ���������� ����������� ��� ������� ����������� � API
#include <stack>
#include <math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <clocale>
#include <tchar.h>
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;


extern "C" int  __cdecl PR1(int ,int );


int strlen1(char*s)
{
	int x;
	_asm
	{
		xor ecx,ecx
			push edi
			xor eax,eax
			cld //����� ����� df 
			dec ecx
			mov edi,s
			repne scasb
			not ecx
			pop edi
			lea eax,[ecx-1]
		mov x,eax
	}
	return x;
}


void  preobr1(char *str,int pos,char *str1,int nam)
{
	int l =strlen1(str);
	int k=l-pos+1;
	nam--;
	_asm
	{
		xor esi,esi
			xor edi,edi
			xor ecx,ecx
			mov esi,str
			mov edi,str1
			mov ecx,pos
			cld
						
			rep lods
			stos

			mov ecx,nam
			cmp ecx,0
			je end1

loop1:
		lods
		stos

		loop loop1
			
end1:
		mov eax,0
		stos


	}




}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "win32_app" ;
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
                   600,       
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
	 static HWND button, edit,editzap,chislo,koren;
	 HFONT hFont = CreateFont(32,0,0,0,0,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, DEFAULT_PITCH,NULL);
     switch (Message)
     {
		 
case WM_CREATE : // ������ ����������� ��������� WM_CREATE
		button=CreateWindow(TEXT("button"),TEXT("���������"),WS_CHILD|WS_VISIBLE,40,125,300,40,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		edit=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,40,65,300,40,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		editzap=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,40,200,300,40,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		chislo=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,40,300,300,40,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		koren=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,40,400,300,40,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			
		return 0 ;
          
case WM_COMMAND:
		if(HIWORD(wParam)==BN_CLICKED)
		{
			TCHAR *str,*str1;
			int n;
			int len;
			len=GetWindowTextLength(edit);
			
			str=new TCHAR[len+1];
     		str1=new TCHAR[len+1];
			GetWindowText(edit,str,len+1);
			int nams=strlen1(str)/2+1;
		    char c[2] ;
			c[0]=str[nams-1];
			int nam=atoi(c);


			 preobr1(str,nams,str1,nam);

			 n = atoi(str1) ;
			 double n1=n;
			
			 double nrez;
			n= PR1(n,len);
			 _asm
			 {
				 finit 
				 fld n1
				 fsqrt
				 fstp nrez
			 }

			 char mes[30];
			 sprintf(mes, "%d", n);


			
			if (len!=0)
			{
				SetWindowText(editzap, str1);
				SetWindowText(chislo, mes);

				sprintf(mes, "%f", nrez);
				SetWindowText(koren, mes);

				
				TCHAR *res=new TCHAR[150];
				
				size_t size=0;
				setlocale(LC_ALL, "Russian");
				
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
            TEXT("������� ������"), strlen("������� ������"));
		EndPaint (hwnd, &ps) ; // �������� ����� p���p���� � Wnd
			return 0 ;

		case WM_DESTROY : // ������ ����������� ��������� WM_DESTROY
			PostQuitMessage (0) ; // ���p������� ��������� wm_Quit � ����� �� ��������� wm_Destroy
			return 0 ;
      }

     return DefWindowProc (hwnd, Message, wParam, lParam) ; // ����������� ���������� ��������� ��������� (������������ ������p���� ��p������ ��������� ��� ���������, ����p�� ���� �� ��p����������� �p�������� �������)
     }
