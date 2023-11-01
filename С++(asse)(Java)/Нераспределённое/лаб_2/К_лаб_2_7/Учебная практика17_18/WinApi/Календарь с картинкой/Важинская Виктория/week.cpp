/* Важинская Виктория, 1-й курс, 7-я группа, 2-й семестр
   УП
   Лабораторная работа №3
*/
#undef UNICODE
#include <windows.h>

bool is_number(const char *s)
{
	char* a="0987654321";
	if(strspn(s,a)==strlen(s)) 
		return true;
	else
	return false;
}

struct Bad_day
{};
struct Bad_month
{};
struct Bad_edit
{};
struct Wr_data
{};

struct
{
	long style;
	char* str;
}

button = {BS_HOLLOW,"Найти"}; 

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
char szAppName[] = "День недели" ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
     HWND        hwnd ;// объявление переменной, содержащей дескриптор окна (уникальный номер экземпляра окна программы)
     MSG         msg ;// объявление переменной, содержащую структуру для работы с сообщениями в ОС
     WNDCLASSEX  wndclass ;// объявление переменной, содержащей структуру, в которой хранится информация об окне
	 
	 // Регистрация класса окна 
    // Заполнение структуры WNDCLASS 
     wndclass.cbSize        = sizeof (wndclass) ; 
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (0) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ; 
     wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;
     
     RegisterClassEx (&wndclass) ; //регистрация окна
    
     hwnd = CreateWindow (szAppName, "День недели", WS_OVERLAPPEDWINDOW, 490, 350, 450, 300, NULL, NULL, hInstance, NULL);// создаёт окно, возвращает объект HWND, являющийся дескриптором окна
	 // показать окно 
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     // цикл  обработки сообщений для прослушивания отправляемых ОС сообщений
     while (GetMessage (&msg, NULL, 0, 0))
          {
			  TranslateMessage (&msg) ;
			  DispatchMessage (&msg) ;
          }
     return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)// функция оконной процедуры
     {
		
	 static HWND  edit1,  	
				  edit2,
				  edit3,
				  hbutton;	
     RECT         rect ;
	 HDC          hdc, hCompatibleDC;
	 HANDLE       hBitmap, hOldBitmap;
	 int		  l1, l2,l3,day,month, year, res, a, y, m;
	 char         *s1,*s2,			
				  *s3,
		          *mess,				
				  *week;			   
	BITMAP Bitmap;// экземпляр структуры BITMAP, которая содержит все данные об изображении
	 PAINTSTRUCT  ps;//  содержит информации для приложения
	static int nHDif = 0, nVDif = 0, nHPos = 0, nVPos = 0;
	int k, g=1, error=0;
	
	 switch (iMsg)
          { 
	        case WM_PAINT ://отправляется тогда, когда система или другое приложение делают запрос, чтобы окрасить часть окна приложения (обрабатывается первым)
			  {
               hdc = BeginPaint(hwnd,&ps);// получить контекст устройства   
			   hBitmap = LoadImage(NULL, "pic.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);// загрузить bitmap, который будет отображаться в окне из файла 
            if ( !hBitmap )
			{
                MessageBox(NULL, "File not found!", "Error", MB_OK);
                return 0;
            }         
            GetObject(hBitmap, sizeof(BITMAP), &Bitmap);// получить размерность изображения            
            hCompatibleDC = CreateCompatibleDC(hdc);// создать совместимый с контекстом окна контекст в памяти             
            hOldBitmap = SelectObject(hCompatibleDC, hBitmap);// делаем загруженную картинку текущей в совместимом контексте
               GetClientRect (hwnd, &rect);// определить размер рабочей области окна 
			 BitBlt(hdc, 0, 0, rect.right, rect.bottom, hCompatibleDC,nHPos, nVPos, SRCCOPY); //выполняет передачу битовых блоков данных о цвете, соответствующих 
			                                                                                 //прямоугольнику пикселей из заданного исходного контекста устройства в целевой контекст устройства  
            DeleteDC(hCompatibleDC);// освободить основной контекст, завершая перерисовку рабочей области окна            
            HFONT newFont = CreateFont(0,0,0,0,700,0,0,0,RUSSIAN_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,PROOF_QUALITY , DEFAULT_PITCH | FF_DECORATIVE,("Arial"));
			   SelectObject(hdc, newFont); // выбирает объект в заданный контекст устройства (DC)
			   // в главном окне выводим текст
			   TextOut (hdc,60, 110, "день", 4); // записывает строку символов в заданном месте, используя текущий выбранный шрифт, цвет фона и цвет текста
               TextOut (hdc,200, 110, "месяц", 5);
               TextOut (hdc,340, 110, "год", 3);
			   EndPaint(hwnd,&ps); //  отмечает конец окрашивания в заданном окне
			   
			   return 0;
			  }
          case WM_CREATE : // отправляется тогда, когда программа запрашивает, какое окно будет создаваться вызовом функции  CreateWindow.		
			  hbutton=CreateWindow("button",button.str,WS_CHILD|WS_VISIBLE|button.style,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);// кнопка "найти" 
			  edit1=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);// прямоугольное дочернее окно для ввода данных (день)
			  edit2=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  edit3=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  return 0;

	      case WM_SETFOCUS: // отправляется окну после того, как оно получило фокус клавиатуры
			  SetFocus(edit1);					                        
			  return 0;

		  case WM_SIZE: // отправляется окну после того, как изменился его размер
			  GetClientRect (hwnd, &rect); // возвращает координаты клиентской области окна
			  MoveWindow(edit1, rect.right*1/5-45, rect.bottom/2, 90, 22, TRUE); // изменяет позицию и габариты определяемого окна
			  MoveWindow(edit2, rect.right*5/9-60, rect.bottom/2, 90, 22, TRUE);
			  MoveWindow(edit3, rect.right*8/9-80, rect.bottom/2, 90, 22, TRUE);
			  MoveWindow(hbutton, rect.right*5/9-67, rect.bottom*4/5, 100, 22, TRUE);
			  return 0;

		  case WM_COMMAND: 		 
			  if(HIWORD(wParam)==BN_CLICKED)// если кнопка нажата
			  {
				  GetClientRect (hwnd, &rect);
				  try
				  {
					  l1=GetWindowTextLength(edit1); 
					  s1=new char[l1+1];
					  GetWindowText(edit1,s1,l1+1); // копирует символы из edit1 в s1  
					  day=atoi(s1);
					  if(!is_number(s1))
						  throw Bad_edit();
					  if((day>31)||(day<1)) throw Bad_day();
					  l2=GetWindowTextLength(edit2);
					  s2=new char[l2+1];
					  GetWindowText(edit2,s2,l2+1);
					  month=atoi(s2);
					  if(!is_number(s2))
						  throw Bad_edit();
					  if((month>12)||(month<1)) throw Bad_month();
					  l3=GetWindowTextLength(edit3);
					  s3=new char[l3+1];
					  GetWindowText(edit3,s3,l3+1);
					  year=atoi(s3);
					  if(!is_number(s3))
						  throw Bad_edit();
					  k=day*100+month;
					  if (year%400==0) g=0; // если год кратен 400, то он високосный, и тогда переменная g принимает значение 0
	                  else if ((year%4==0) && (year%100!=0)) g=0; // если год не кратен 400, но кратен 4 и не кратен 100, то он 
	                                           // тоже високосный, и g принимает значение 0
	                 if ((k==2902) && (g!=0)) // если год не високосный, но есть 29 февраля,	               
	                  error++;             //  и значение переменной error увеличевается на единицу
	                  if ((k==3002) || (k==3102)) // 30 февраля вообще не существует	                 
	                  error++; 
	                  if (k==3104) // в апереле только 30 дней	                
	                  error++; 
	                  if (k==3106) // в июне только 30 дней
	                  error++;
	                  if (k==3109) // в сентябре только 30 дней	               
	                  error++; 
					  if(error>0) throw Wr_data();
				  }
				  catch(Bad_edit)
				  {
					  mess=new char[40];
					  strcpy(mess,"Error: должно быть натуральным числом!");
					  MessageBox(hwnd,mess,szAppName,MB_OK|MB_ICONSTOP); //создает, показывает на экране и использует окно сообщения
					  return 0;
				  }				  
				  catch(Bad_day)
				  {
                     MessageBox(hwnd,"Error: день должен быть от 1 до 31!",szAppName,MB_OK|MB_ICONSTOP);
					 return 0;
				  }
				  catch (Bad_month)
				  {
                      MessageBox(hwnd,"Error: месяц имеет порядковый номер от 1 до 12!",szAppName,MB_OK|MB_ICONSTOP);
					 return 0;
				  }
				  catch (Wr_data)
				  {
					  MessageBox(hwnd,"Error: допущена логическая ошибка!",szAppName,MB_OK|MB_ICONSTOP);
					 return 0;
				  }
				  char* week=new char[15];
                  a=(14-month)/12; // a - вспомогательная переменная  
                  y=year-a;  // y - вспомогательная переменная  
	              m=month+(12*a)-2; // m - вспомогательная переменная
                  res=(7000+day+y+(y/4)-(y/100)+(y/400)+(31*m)/12)%7;
                   switch (res)
                 { 
	             case 1: strcpy(week,"понедельник"); break;
	             case 2: strcpy(week,"вторник"); break;
	             case 3: strcpy(week,"среда");break;
	             case 4:  strcpy(week,"четверг");break;
	             case 5: strcpy(week,"пятница");break;
	             case 6: strcpy(week,"суббота");break;
                 case 0: strcpy(week,"воскресенье");break;
	             }
				  MessageBox(hwnd, week, szAppName, MB_OK|MB_ICONASTERISK); //создает, показывает на экране и использует окно сообщения
			  }

			  return 0;
               case WM_DESTROY :// отправляется тогда, когда окно разрушается			 
               PostQuitMessage (0) ; 
               return 0 ;
          }

     return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}