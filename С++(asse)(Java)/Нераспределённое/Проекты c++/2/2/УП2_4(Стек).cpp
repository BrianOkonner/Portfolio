/*-----------------------------------------
  Очередь Перевязчиков Владислав 1 курс 8 группа
  -----------------------------------------*/
#include "MineQueue.h"
#include <windows.h>
 HWND        hEdit;
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "BlokOut1" ;
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

     hwnd = CreateWindow (szAppName, "Queue",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;

     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
 //
CreateWindow("button", "Push", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20, 20, 80, 30, hwnd, (HMENU)10001, hInstance, NULL);

CreateWindow("button", "Pop", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20, 60, 80, 30, hwnd, (HMENU)10002, hInstance, NULL);

CreateWindow("button", "Front", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20, 100, 80, 30, hwnd, (HMENU)10003, hInstance, NULL);

CreateWindow("button", "isEmpty?", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20, 140, 80, 30, hwnd, (HMENU)10004, hInstance, NULL);
hEdit=CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILD | WS_VISIBLE | ES_CENTER,
       200, 10, 80, 30, hwnd, (HMENU)10000, hInstance, NULL);
 



     while (GetMessage (&msg, NULL, 0, 0))
          {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
          }
     return msg.wParam;
     }


LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
     {static Mqueue A;
 static int t=5,x=600,y=20,a,size_x,size_y;

 static char s[50]="/0",s1[50]="";
	
   //  static BOOL  fBlocking, fValidBox ;
    // static POINT ptBeg, ptEnd, ptBoxBeg, ptBoxEnd ;
     HDC          hdc ;
     PAINTSTRUCT  ps ;
     switch (iMsg)
{    case WM_SIZE:
            //Запоминаем текущие размеры окна.
            size_x = LOWORD(lParam); 
            size_y = HIWORD(lParam);
            break;

	 case  WM_COMMAND:        //Обрабатываем Кнопки
    //if(LOWORD(wParam)==10001)
	//{}
		
      if(LOWORD(wParam)==10001)
	  {SendMessage(hEdit,EM_GETLINE,0,(LPARAM)s);
	  int *l=new int;
	      *l=atoi(s);
		 A.push(l);
		 a=*(int*)A.back();
	  t=1;
	  InvalidateRect(hwnd,NULL,FALSE);	
	  }
	  if (LOWORD(wParam)==10002)
	  {
		  if (!A.empty())
		  {
		   a=*( int *)A.pop();
		   t=2;
		   InvalidateRect(hwnd,NULL,FALSE);	
		  }
		  else
		   {
		      MessageBox(hwnd,"Стек Пуст!","Ошибка",MB_OK )  ;             // t=0;
		                       // InvalidateRect(hwnd,NULL,FALSE);	
		   }
	  
	  
	  }
        if (LOWORD(wParam)==10003)
	    if (!A.empty())
		  {
			  a=*(int*)A.front();
		   t=3;
		   InvalidateRect(hwnd,NULL,FALSE);	
		  }
		  else
		   {
		    MessageBox(hwnd,"Очередь Пуста!","Ошибка",MB_OK )  ;   //  t=0;
		                                                         //   InvalidateRect(hwnd,NULL,FALSE);	
		   }
	 
	  if(LOWORD(wParam)==10004)
	  { 
       a=A.empty();
	   t=4;
	   InvalidateRect(hwnd,NULL,FALSE);	
	  }
	  break;

	 case WM_PAINT:  

		  hdc = BeginPaint(hwnd, &ps);
          itoa(a,s,10);
          TextOut(hdc,220,50,"Ввод",4) ;
		  strcpy(s1,"\0");
	     switch (t)
	     {
		  case 1:

			  strcat(s1,"Добавили в Очереди ");
              strcat(s1,s);
			TextOut(hdc,x,y,s1,strlen(s1)) ;

          break;

       	  case 2:	
            strcat(s1,"Извлекли из Очереди ");
             strcat(s1,s);
		TextOut(hdc,x,y,s1,strlen(s1)) ;
	       break;


		  case 3:  
			strcat(s1,"Значение на верхушке Очереди ");
            strcat(s1,s);
            TextOut(hdc,x,y,s1,strlen(s1)) ;
			break;

		   case 4:    
           if (a) TextOut(hdc,x,y,"Стек Пустой",11);
		   else   TextOut(hdc,x,y,"Стек не пуст",12);
			break;
	     }
       // Заканчиваем рисование.
     EndPaint(hwnd, &ps);
     y+=20;	 
	 if (y>size_y) 
	 {
	 InvalidateRect(hwnd,NULL,TRUE);
	 y=20; 
	 }
     break;

	 case WM_CLOSE:
	 if (IDOK==MessageBox(hwnd,"Вы уверены ,что хотите выйти","?",MB_OKCANCEL ))
       SendMessage(hwnd, WM_DESTROY, NULL, NULL);   
   break;
          case WM_DESTROY :
               PostQuitMessage (0) ;
               return 0 ;
          }
     return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
     }
	 