/* ��������� ��������, 1-� ����, 7-� ������, 2-� �������
   ��
   ������������ ������ �3
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

button = {BS_HOLLOW,"�����"}; 

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
char szAppName[] = "���� ������" ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
     HWND        hwnd ;// ���������� ����������, ���������� ���������� ���� (���������� ����� ���������� ���� ���������)
     MSG         msg ;// ���������� ����������, ���������� ��������� ��� ������ � ����������� � ��
     WNDCLASSEX  wndclass ;// ���������� ����������, ���������� ���������, � ������� �������� ���������� �� ����
	 
	 // ����������� ������ ���� 
    // ���������� ��������� WNDCLASS 
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
     
     RegisterClassEx (&wndclass) ; //����������� ����
    
     hwnd = CreateWindow (szAppName, "���� ������", WS_OVERLAPPEDWINDOW, 490, 350, 450, 300, NULL, NULL, hInstance, NULL);// ������ ����, ���������� ������ HWND, ���������� ������������ ����
	 // �������� ���� 
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     // ����  ��������� ��������� ��� ������������� ������������ �� ���������
     while (GetMessage (&msg, NULL, 0, 0))
          {
			  TranslateMessage (&msg) ;
			  DispatchMessage (&msg) ;
          }
     return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)// ������� ������� ���������
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
	BITMAP Bitmap;// ��������� ��������� BITMAP, ������� �������� ��� ������ �� �����������
	 PAINTSTRUCT  ps;//  �������� ���������� ��� ����������
	static int nHDif = 0, nVDif = 0, nHPos = 0, nVPos = 0;
	int k, g=1, error=0;
	
	 switch (iMsg)
          { 
	        case WM_PAINT ://������������ �����, ����� ������� ��� ������ ���������� ������ ������, ����� �������� ����� ���� ���������� (�������������� ������)
			  {
               hdc = BeginPaint(hwnd,&ps);// �������� �������� ����������   
			   hBitmap = LoadImage(NULL, "pic.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);// ��������� bitmap, ������� ����� ������������ � ���� �� ����� 
            if ( !hBitmap )
			{
                MessageBox(NULL, "File not found!", "Error", MB_OK);
                return 0;
            }         
            GetObject(hBitmap, sizeof(BITMAP), &Bitmap);// �������� ����������� �����������            
            hCompatibleDC = CreateCompatibleDC(hdc);// ������� ����������� � ���������� ���� �������� � ������             
            hOldBitmap = SelectObject(hCompatibleDC, hBitmap);// ������ ����������� �������� ������� � ����������� ���������
               GetClientRect (hwnd, &rect);// ���������� ������ ������� ������� ���� 
			 BitBlt(hdc, 0, 0, rect.right, rect.bottom, hCompatibleDC,nHPos, nVPos, SRCCOPY); //��������� �������� ������� ������ ������ � �����, ��������������� 
			                                                                                 //�������������� �������� �� ��������� ��������� ��������� ���������� � ������� �������� ����������  
            DeleteDC(hCompatibleDC);// ���������� �������� ��������, �������� ����������� ������� ������� ����            
            HFONT newFont = CreateFont(0,0,0,0,700,0,0,0,RUSSIAN_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,PROOF_QUALITY , DEFAULT_PITCH | FF_DECORATIVE,("Arial"));
			   SelectObject(hdc, newFont); // �������� ������ � �������� �������� ���������� (DC)
			   // � ������� ���� ������� �����
			   TextOut (hdc,60, 110, "����", 4); // ���������� ������ �������� � �������� �����, ��������� ������� ��������� �����, ���� ���� � ���� ������
               TextOut (hdc,200, 110, "�����", 5);
               TextOut (hdc,340, 110, "���", 3);
			   EndPaint(hwnd,&ps); //  �������� ����� ����������� � �������� ����
			   
			   return 0;
			  }
          case WM_CREATE : // ������������ �����, ����� ��������� �����������, ����� ���� ����� ����������� ������� �������  CreateWindow.		
			  hbutton=CreateWindow("button",button.str,WS_CHILD|WS_VISIBLE|button.style,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);// ������ "�����" 
			  edit1=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);// ������������� �������� ���� ��� ����� ������ (����)
			  edit2=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  edit3=CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  return 0;

	      case WM_SETFOCUS: // ������������ ���� ����� ����, ��� ��� �������� ����� ����������
			  SetFocus(edit1);					                        
			  return 0;

		  case WM_SIZE: // ������������ ���� ����� ����, ��� ��������� ��� ������
			  GetClientRect (hwnd, &rect); // ���������� ���������� ���������� ������� ����
			  MoveWindow(edit1, rect.right*1/5-45, rect.bottom/2, 90, 22, TRUE); // �������� ������� � �������� ������������� ����
			  MoveWindow(edit2, rect.right*5/9-60, rect.bottom/2, 90, 22, TRUE);
			  MoveWindow(edit3, rect.right*8/9-80, rect.bottom/2, 90, 22, TRUE);
			  MoveWindow(hbutton, rect.right*5/9-67, rect.bottom*4/5, 100, 22, TRUE);
			  return 0;

		  case WM_COMMAND: 		 
			  if(HIWORD(wParam)==BN_CLICKED)// ���� ������ ������
			  {
				  GetClientRect (hwnd, &rect);
				  try
				  {
					  l1=GetWindowTextLength(edit1); 
					  s1=new char[l1+1];
					  GetWindowText(edit1,s1,l1+1); // �������� ������� �� edit1 � s1  
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
					  if (year%400==0) g=0; // ���� ��� ������ 400, �� �� ����������, � ����� ���������� g ��������� �������� 0
	                  else if ((year%4==0) && (year%100!=0)) g=0; // ���� ��� �� ������ 400, �� ������ 4 � �� ������ 100, �� �� 
	                                           // ���� ����������, � g ��������� �������� 0
	                 if ((k==2902) && (g!=0)) // ���� ��� �� ����������, �� ���� 29 �������,	               
	                  error++;             //  � �������� ���������� error ������������� �� �������
	                  if ((k==3002) || (k==3102)) // 30 ������� ������ �� ����������	                 
	                  error++; 
	                  if (k==3104) // � ������� ������ 30 ����	                
	                  error++; 
	                  if (k==3106) // � ���� ������ 30 ����
	                  error++;
	                  if (k==3109) // � �������� ������ 30 ����	               
	                  error++; 
					  if(error>0) throw Wr_data();
				  }
				  catch(Bad_edit)
				  {
					  mess=new char[40];
					  strcpy(mess,"Error: ������ ���� ����������� ������!");
					  MessageBox(hwnd,mess,szAppName,MB_OK|MB_ICONSTOP); //�������, ���������� �� ������ � ���������� ���� ���������
					  return 0;
				  }				  
				  catch(Bad_day)
				  {
                     MessageBox(hwnd,"Error: ���� ������ ���� �� 1 �� 31!",szAppName,MB_OK|MB_ICONSTOP);
					 return 0;
				  }
				  catch (Bad_month)
				  {
                      MessageBox(hwnd,"Error: ����� ����� ���������� ����� �� 1 �� 12!",szAppName,MB_OK|MB_ICONSTOP);
					 return 0;
				  }
				  catch (Wr_data)
				  {
					  MessageBox(hwnd,"Error: �������� ���������� ������!",szAppName,MB_OK|MB_ICONSTOP);
					 return 0;
				  }
				  char* week=new char[15];
                  a=(14-month)/12; // a - ��������������� ����������  
                  y=year-a;  // y - ��������������� ����������  
	              m=month+(12*a)-2; // m - ��������������� ����������
                  res=(7000+day+y+(y/4)-(y/100)+(y/400)+(31*m)/12)%7;
                   switch (res)
                 { 
	             case 1: strcpy(week,"�����������"); break;
	             case 2: strcpy(week,"�������"); break;
	             case 3: strcpy(week,"�����");break;
	             case 4:  strcpy(week,"�������");break;
	             case 5: strcpy(week,"�������");break;
	             case 6: strcpy(week,"�������");break;
                 case 0: strcpy(week,"�����������");break;
	             }
				  MessageBox(hwnd, week, szAppName, MB_OK|MB_ICONASTERISK); //�������, ���������� �� ������ � ���������� ���� ���������
			  }

			  return 0;
               case WM_DESTROY :// ������������ �����, ����� ���� �����������			 
               PostQuitMessage (0) ; 
               return 0 ;
          }

     return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}