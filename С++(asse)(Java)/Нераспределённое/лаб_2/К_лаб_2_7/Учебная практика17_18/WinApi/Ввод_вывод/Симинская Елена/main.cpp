
//��������� �����
//
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include <clocale>
#undef UNICODE
#pragma comment (lib, "winmm.lib")


bool Number (char* str, int l)
{
	if (str[0]==48)
		return false;
	while(l--)
		if ((str[l]<48) || (str[l]>57))
			return false;
	return true;
}

int nod (int a, int b)
{
	if (b<a)
	{
		int c=a;
		a=b;
		b=c;
	}
	for (int i=a; i>0; i--)
		if (b%i==0 && a%i==0)
			return i;
}

static char szWindowClass[]=_T("win32app");
static char szTitle[]=_T("win32app");
HINSTANCE hInst;
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, //���������� �������� ���������� ����
					HINSTANCE hPrevInstance, //���������� ����������� ���������� ����
					LPSTR lpCmdLine, //��������� �� ��������� ������
					int nCmdShow) //���������� ��������� ����
{
	WNDCLASSEX wcex; //��������� ������ ����
wcex.cbSize=sizeof (WNDCLASSEX); // �����������
wcex.style = CS_HREDRAW | CS_VREDRAW;  //����� ����
wcex.lpfnWndProc = WndProc;  //��������� �� ������� ���������
wcex.cbClsExtra = 0; //�������������� ����� ����� ������
wcex.cbWndExtra = 0; //�������������� ����� ����� ���������� ����
wcex.hInstance = hInstance; //��������� ����������� ���������� � ���� ��������� WinMain
wcex.hIcon = LoadIcon (hInstance, MAKEINTRESOURCE (IDI_APPLICATION)); //������ ����������
wcex.hCursor = LoadCursor (NULL, IDC_ARROW); ///������ ����������
wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); //���� ����
wcex.lpszMenuName = NULL; //��� ����
wcex.lpszClassName = szWindowClass; //��� ������
wcex.hIconSm = LoadIcon (wcex.hInstance, MAKEINTRESOURCE (IDI_APPLICATION)); // ������ ������� �� ����������
if (!RegisterClassEx(&wcex)) //����������� ����
{
	//�������� �� ������ � ������������ ���� ���������:
	MessageBox (NULL,   //���������� ���� ���������
		_T("Call to RegisterClassEx failed!"), //��������� �� ������
		_T("Win32 Guided Tour"),  //��������� ���� ���������
		NULL); //���������� � ����� ������ ����
	return 1;
}
hInst = hInstance;
HWND hwnd = CreateWindow (	 //�������� �������� ���� ����������
	szWindowClass,	//��� ������
	szTitle, //��� ���� (������������ � ���������)
	WS_OVERLAPPEDWINDOW,	 //����� ����
	CW_USEDEFAULT, CW_USEDEFAULT,	 //���������� �� ����������� �� ������ ���� ������ � �� ��������� �� ��������
	500, 210, //������ � ������ ����
	NULL,	//������������ ����
	NULL,	//��������� ����
	hInstance,	//��������� ����������
	NULL); //��������
if (!hwnd)
{
	MessageBox (NULL,
		_T("Call to CreateWindow failed!"),
		_T("Win32 Guided Tour"),
		NULL);
	return 1;
}
//���������� ��������� ������ ������������� ����:
ShowWindow (hwnd, //���������� ����
			nCmdShow); //��������� ������ ����
UpdateWindow (hwnd); //��������� ������� ������� ��������� ����
MSG  msg;
while (GetMessage (&msg, NULL, 0, 0)) //��������� ��������� �� ������� ��������� � �������� � �������� ���������
{
	TranslateMessage (&msg); //��������� ��������� ����������� ������ � ���������� ���������
	DispatchMessage (&msg);//������������ ��������� ������� ���������
}
return (int) msg.wParam;
}

//��������� ���������:
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	 static HWND  hwndedit1,	
				  hwndedit2,
				  button;	
     RECT         rect ;
	 HDC          hdc;
	 int		  l1,
				  l2,
				  a,
				  c;
	 char  *str1,
		  *str2,		
		  *str3;//�����, ������� ������������� � ���� ��������������;
		char	 *rmes;			//����� ����������;
	 PAINTSTRUCT  ps;			
	
	 switch (message) //���������
          {
          case WM_CREATE :		//������������� ����
			  button=CreateWindow(TEXT("button"),TEXT("�������"),WS_CHILD|WS_VISIBLE,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  hwndedit1=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  hwndedit2=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT,0,0,0,0,hwnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			  return 0 ;
		 case WM_SIZE:
			  GetClientRect (hwnd, &rect); //���������� ���������� ������� ����
			  MoveWindow(hwndedit1, rect.right*2/11, rect.bottom/2, 70, 22, TRUE);
			  MoveWindow(hwndedit2, rect.right*9/11-70, rect.bottom/2, 70, 22, TRUE);
			  MoveWindow(button, rect.right/2-35, rect.bottom*4/5, 70, 22, TRUE);
			  return 0;

		  case WM_COMMAND:			 
			  if(HIWORD(wParam)==BN_CLICKED)
			  {
				  GetClientRect (hwnd, &rect);
					  l1=GetWindowTextLength(hwndedit1);
					  str1=new char[l1+1];
					  GetWindowText(hwndedit1,str1,l1+1);
					  a=atoi(str1);
					  l2=GetWindowTextLength(hwndedit2);
					  str2=new char[l2+1];
					  GetWindowText(hwndedit2,str2,l2+1);
					  c=atoi(str2);
				  char* rmes=new char[l1+l2+1];
				  char * str3=new char [l1+l2+1];
				  itoa(nod(a, c), rmes, 10);
				  size_t len=0;
			//	  mbstowcs_s (&len, str3, strlen (rmes)+1, rmes, _TRUNCATE);
				  MessageBox(hwnd, rmes, TEXT("���������"), MB_OK|MB_ICONINFORMATION);
			  }

			  if(LOWORD(wParam)==1)        
				  if(HIWORD(wParam)==EN_ERRSPACE||HIWORD(wParam)==EN_MAXTEXT)
					  MessageBox(hwnd,TEXT("Edit control out of space."),TEXT("���������"),MB_OK|MB_ICONSTOP);
			  return 0;
          

          case WM_PAINT : //���������� ������� ������� ����
			  {

			   hdc = BeginPaint(hwnd,&ps);
			   GetClientRect (hwnd, &rect);

			   Rectangle(hdc,rect.right/9, rect.bottom/4, rect.right*8/9, rect.bottom*3/4);
			   HFONT newFont = CreateFont(27,27,0,0,0,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,TEXT("Arial"));
			   SelectObject(hdc, newFont);
			   TextOut (hdc,rect.right/2-60, rect.bottom/2, TEXT("���"), 3);
			   EndPaint(hwnd,&ps); 
			   return 0;
			  }

          case WM_DESTROY :			 //������� ������������  ����� �������� ������
               PostQuitMessage (0) ;
               return 0 ;
          }

     return DefWindowProc (hwnd, message, wParam, lParam) ;
	
}