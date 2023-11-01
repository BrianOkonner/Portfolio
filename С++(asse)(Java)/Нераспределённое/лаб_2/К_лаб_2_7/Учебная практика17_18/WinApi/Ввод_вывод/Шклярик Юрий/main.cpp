/*
Учебная практика: лабораторная работа №3

Выполнил: Шклярик Ю. Н. (7 группа, 1 курс)


*/
#undef UNICODE
#pragma comment (lib, "winmm.lib")
#include <windows.h>

bool Number(char *str,int l)
{
	if(str[0]==48) return false;
	while(l--)
		if((str[l]<48)||(str[l]>57))
			return false;
	return true;
}

struct Bad_Par{};

struct Bad_Size
{
	char str[10];
	Bad_Size(char* str1)
	{
		strcpy(str,str1);
	}
};

struct
{
	long style;
	char* str;
}

button = {BS_HOLLOW,"Считать"}; 

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
char szAppName[] = "Сумма" ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
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

     hwnd = CreateWindow (szAppName, "Сумма двух чисел", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 350, 210, NULL, NULL, hInstance, NULL);
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
	 static HWND  hwndedit1,	
				  hwndedit2,
				  hbutton;	
     RECT         rect ;
	 HDC          hdc;
	 int		  l1,
				  l2,
				  a,
				  c;
	 char         *str1,
				  *str2,			//Текст, водимый пользователем в поля редактирования;
		          *mes,				//Текст для исключения;
				  *rmes;			//Текст результата;
	 PAINTSTRUCT  ps;			
	
	 switch (iMsg)
          {
          case WM_CREATE :		
			  hbutton=CreateWindow("button",button.str,WS_CHILD|WS_VISIBLE|button.style,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  hwndedit1=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  hwndedit2=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  return 0 ;

	      case WM_SETFOCUS:
			  SetFocus(hwndedit1);					                        
			  return 0;

		  case WM_SIZE:
			  GetClientRect (hwnd, &rect);
			  MoveWindow(hwndedit1, rect.right*2/9, rect.bottom/2, 70, 22, TRUE);
			  MoveWindow(hwndedit2, rect.right*7/9-70, rect.bottom/2, 70, 22, TRUE);
			  MoveWindow(hbutton, rect.right/2-35, rect.bottom*4/5, 70, 22, TRUE);
			  return 0;

		  case WM_COMMAND:			 
			  if(HIWORD(wParam)==BN_CLICKED)
			  {
				  GetClientRect (hwnd, &rect);
				  try
				  {
					  l1=GetWindowTextLength(hwndedit1);
					  str1=new char[l1+1];
					  GetWindowText(hwndedit1,str1,l1+1);
					  a=atoi(str1);
					  if(!Number(str1,l1))
						  throw Bad_Size(str1);
					  l2=GetWindowTextLength(hwndedit2);
					  str2=new char[l2+1];
					  GetWindowText(hwndedit2,str2,l2+1);
					  c=atoi(str2);
					  if(!Number(str2,l2))
						  throw Bad_Size(str2);
				  }
				  catch(Bad_Size b)
				  {
					  mes=new char[25];
					  strcpy(mes,b.str);
					  strcat(mes," не является натуральным числом.");
					  MessageBox(hwnd,mes,szAppName,MB_OK|MB_ICONSTOP);
					  return 0;
				  }
				  catch(Bad_Par)
				  {
					  MessageBox(hwnd," Выход за пределы области видимости.\nВведите другие параметры.",szAppName,MB_OK|MB_ICONSTOP);
					  return 0;
				  }
				  char* rmes=new char[l1+l2+1];
				  itoa(a+c, rmes, 10);
				  MessageBox(hwnd, rmes, szAppName, MB_OK|MB_ICONINFORMATION);
			  }

			  if(LOWORD(wParam)==1)        
				  if(HIWORD(wParam)==EN_ERRSPACE||HIWORD(wParam)==EN_MAXTEXT)
					  MessageBox(hwnd,"Edit control out of space.",szAppName,MB_OK|MB_ICONSTOP);
			  return 0;
          

          case WM_PAINT :
			  {

			   hdc = BeginPaint(hwnd,&ps);
			   GetClientRect (hwnd, &rect);

			   Rectangle(hdc,rect.right/9, rect.bottom/4, rect.right*8/9, rect.bottom*3/4);
			   HFONT newFont = CreateFont(27,27,0,0,0,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,("Arial"));
			   SelectObject(hdc, newFont);
			   TextOut (hdc,rect.right/2-18, rect.bottom/2, "+", 1);
			   EndPaint(hwnd,&ps);
			   return 0;
			  }

          case WM_DESTROY :			 
               PostQuitMessage (0) ;
               return 0 ;
          }

     return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}