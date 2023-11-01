
#undef UNICODE
#pragma comment (lib, "winmm.lib")
#include"point.h"
#include"cub.h"
#include <windows.h>

bool Number(char *str,int l)
{//являются ли вводимые параметры натуральными числами?
	if(str[0]==48) return false;
	while(l--)
		if((str[l]<48)||(str[l]>57)) return false;
	return true;
}

struct Bad_Par{};

struct Bad_Size
{//для длины ребра
	char str[10];
	Bad_Size(char* str1)
	{
		strcpy(str,str1);
	}
};

struct Bad_Coord
{//для координат
	char str[10];
	Bad_Coord(char* str1)
	{
		strcpy(str,str1);
	}
};

struct
{
	long style;
	char* str;
}
button = {BS_HOLLOW,"Рисовать"}; 

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
char szAppName[] = "Cub" ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
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

     hwnd = CreateWindow (szAppName,        // window class name
		     "The Cub Program",   // window caption
                   WS_OVERLAPPEDWINDOW,     // window style
                   CW_USEDEFAULT,           // initial x position
                   CW_USEDEFAULT,           // initial y position
                   CW_USEDEFAULT,           // initial x size
                   CW_USEDEFAULT,           // initial y size
                   NULL,                    // parent window handle
                   NULL,                    // window menu handle
                   hInstance,               // program instance handle
		   NULL) ;		   // creation parameters

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
	 static HWND  hwndedit,//длина
		          hwndedit1,//х
				  hwndedit2,//у
				  hbutton; //кнопка
     RECT         rect ;
	 HDC          hdc;
	 int          a,  //ребро
		          i,  //х
				  j,  //у
				  l;  //длина вводимых параметров (количество цифр)
	 static Point p,PtPush;  //точка нажатия кнопки мыши
	 Point        PtMove,p1;
	 static Cub   C;
	 char         *str,  //данные, вводимые пользователем
		          *mes;  //тексты сообщений, выбрасываемых исключениями
	 PAINTSTRUCT  ps;
	 static bool  able,   //можно ли рисовать(есть ли данные)
		          fBlocking,  //перемещение куба
				  fBlocking2;	//изменение размеров  

     switch (iMsg)
          {
		   case WM_RBUTTONDOWN :
			   PtPush.x=LOWORD(lParam);
			   PtPush.y=HIWORD(lParam);
			   if((PtPush.x>=p.x+C.size-2)&&(PtPush.x<=p.x+C.size+2)&&(PtPush.y>=p.y-2)&&(PtPush.y<=p.y+2))
			   {//если нажатие в нужном месте, захватываем
				   SetCapture(hwnd);
				   SetCursor (LoadCursor (NULL, IDC_SIZENESW)) ;
				   fBlocking2 = TRUE ;
			   }
			   return 0 ;


		   case WM_LBUTTONDOWN :
			   PtPush.x=LOWORD(lParam);
			   PtPush.y=HIWORD(lParam);
			   if((PtPush.x>=p.x)&&(PtPush.x<=p.x+C.size+C.sdvig)&&
				   (PtPush.y>=p.y-C.sdvig)&&(PtPush.y<=p.y+C.size))
			   {//если в пределах фигуры, захватываем
				   SetCapture(hwnd);
				   SetCursor (LoadCursor (NULL, IDC_SIZEALL)) ;
				   fBlocking = TRUE ;
			   }
			   return 0 ;

		   case WM_MOUSEMOVE :
               if (fBlocking)
			   {				   
				   SetCursor (LoadCursor (NULL, IDC_SIZEALL)) ;
				   C.Draw(hwnd);
				   PtMove.x=LOWORD(lParam); PtMove.y=HIWORD(lParam);
				   p1=p;
				   p1+=(PtMove-PtPush);   //смещение мышки
				   GetClientRect (hwnd, &rect);
				   Cub C2(p1,C.size);
				   if(C2.CanDraw(rect))
				   {//если остались в рабочей области, рисуем
					   C=C2;p=p1;
					   PtPush=PtMove;
					   C.Draw(hwnd);
				   }
			   }
			   else if(fBlocking2)
			   {
				   SetCursor (LoadCursor (NULL, IDC_SIZENESW)) ;
				   C.Draw(hwnd);
				   PtMove.x=LOWORD(lParam); PtMove.y=HIWORD(lParam);				   
				   p1=PtMove-PtPush;
				   GetClientRect (hwnd, &rect);
				   if((p1>0)||(p1<0))  //смещения, вызывающие изменение размеров
				   {
					   Cub C2(C);
					   C2.ChangeSize(p1);
					   if(C2.CanDraw(rect))
				   {//если остались в рабочей области, рисуем
					   C=C2;p=p1;
					   p.x=C.x; p.y=C.y;
					   PtPush.x=C.x+C.size; PtPush.y=C.y;
					   C.Draw(hwnd);
				   }
				   }
			   }
			   return 0;

		    case WM_LBUTTONUP :
               if (fBlocking)
			   {				   
				   C.Draw(hwnd);
				   ReleaseCapture () ;
				   fBlocking = FALSE ;				   
			   }
			   return 0;

		    case WM_RBUTTONUP :
               if (fBlocking2)
			   {				   
				   C.Draw(hwnd);
				   ReleaseCapture () ;
				   fBlocking2 = FALSE ;				   
			   }
			   return 0;

          case WM_CREATE :			   
			  hbutton=CreateWindow("button",button.str,WS_CHILD|WS_VISIBLE|button.style,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  hwndedit=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  hwndedit1=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  hwndedit2=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  return 0 ;

	      case WM_SETFOCUS:
			  SetFocus(hwndedit);
			  return 0;

		  case WM_SIZE:
			  
			  MoveWindow(hbutton,LOWORD(lParam)-100,160,70,22,TRUE);
			  MoveWindow(hwndedit,LOWORD(lParam)-80,30,30,22,TRUE);
			  MoveWindow(hwndedit1,LOWORD(lParam)-80,80,30,22,TRUE);
			  MoveWindow(hwndedit2,LOWORD(lParam)-80,130,30,22,TRUE);
			  return 0;

		  case WM_COMMAND:			 
			  if(HIWORD(wParam)==BN_CLICKED)
			  {
				  GetClientRect (hwnd, &rect);
				  try
				  {//ввод значений параметров и их обработка
					  l=GetWindowTextLength(hwndedit); str=new char[l+1];GetWindowText(hwndedit,str,l+1);a=atoi(str);
					  if(!Number(str,l)) throw Bad_Size(str);
					  l=GetWindowTextLength(hwndedit1);str=new char[l+1];GetWindowText(hwndedit1,str,l+1);i=atoi(str);
					  if(!Number(str,l)) throw Bad_Coord(str);
					  l=GetWindowTextLength(hwndedit2);str=new char[l+1];GetWindowText(hwndedit2,str,l+1);j=atoi(str);
					  if(!Number(str,l)) throw Bad_Coord(str);
					  p.x=i;p.y=j;
					  Cub C1(p,a);C=C1;
					  able=TRUE;
					  if(!C.CanDraw(rect))
						  throw Bad_Par();
					  C.Draw(hwnd);
				  }
				  catch(Bad_Size b)
				  {
					  mes=new char[25];
					  strcpy(mes,b.str);strcat(mes," is a bad size");
					  MessageBox(hwnd,mes,szAppName,MB_OK|MB_ICONSTOP);
				  }
				  catch(Bad_Coord c)
				  {
					  mes=new char[25];
					  strcpy(mes,c.str);strcat(mes," is a bad coordinate");
					  MessageBox(hwnd,mes,szAppName,MB_OK|MB_ICONSTOP);
				  }
				  catch(Bad_Par)
				  {
					  MessageBox(hwnd,"   Running out of space\n(input other parameters)",szAppName,MB_OK|MB_ICONSTOP);
				  }
			  }

			  if(LOWORD(wParam)==1) 
				  if(HIWORD(wParam)==EN_ERRSPACE||HIWORD(wParam)==EN_MAXTEXT)
					  MessageBox(hwnd,"Edit control out of space.",szAppName,MB_OK|MB_ICONSTOP);
			  return 0;
          

          case WM_PAINT :

		   srand(time(0)); 
	       hdc = BeginPaint(hwnd,&ps);
		   GetClientRect (hwnd, &rect);
		   TextOut (hdc,rect.right-135,380, "Автор:",6) ;
		   TextOut (hdc,rect.right-120,400, "Кунец Татьяна",15) ;
		       SetTextColor(hdc,RGB(rand()%256,rand()%256,rand()%256));
			   TextOut (hdc,rect.right-120,10, "Длина ребра",11) ;SetTextColor(hdc,RGB(rand()%256,rand()%256,rand()%256));
			   TextOut (hdc,rect.right-120,60, "Координата x",12) ;SetTextColor(hdc,RGB(rand()%256,rand()%256,rand()%256));
			   TextOut (hdc,rect.right-120,110, "Координата y",12) ;SetTextColor(hdc,RGB(rand()%256,rand()%256,rand()%256));
			   TextOut (hdc,rect.right-120,190, "Все параметры -",15) ;
			   TextOut (hdc,rect.right-135,210, "натуральные числа",17) ;SetTextColor(hdc,RGB(rand()%256,rand()%256,rand()%256));
			   TextOut (hdc,rect.right-135,240, "    Перемещение -",17) ;
			   TextOut (hdc,rect.right-135,260, "левая кнопка мыши",17) ;SetTextColor(hdc,RGB(rand()%256,rand()%256,rand()%256));
			   TextOut (hdc,rect.right-135,290, "Изменение размера",17) ;
			   TextOut (hdc,rect.right-135,310, "- правая кнопка в",17) ;
			   TextOut (hdc,rect.right-135,330, "правую верхнюю",14) ;
			   TextOut (hdc,rect.right-135,350, "ближнюю вершину",15) ;
			   Rectangle(hdc,rect.left,rect.top,rect.right-140,rect.bottom);
			   EndPaint(hwnd,&ps);
			   if(able)
				   C.Draw(hwnd);	   
	      
               return 0 ;

          case WM_DESTROY :			 
               PostQuitMessage (0) ;
               return 0 ;
          }

     return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
     }