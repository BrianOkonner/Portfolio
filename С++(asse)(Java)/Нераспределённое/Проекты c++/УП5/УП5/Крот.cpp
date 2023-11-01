#include <windows.h>
#include <vector>
#include <string>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include <dos.h>
using namespace std;
LRESULT CALLBACK WindProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
	{
		MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
		return LineTo(hdc, x2, y2);
	} 
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX  WndCls;
	static TCHAR szAppName[] = TEXT("Крот");
	MSG         Msg;


	WndCls.cbSize = sizeof(WndCls);
	WndCls.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	WndCls.lpfnWndProc = WindProcedure;
	WndCls.cbClsExtra = 0;
	WndCls.cbWndExtra = 0;
	WndCls.hInstance = hInstance;
	WndCls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndCls.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndCls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndCls.lpszMenuName = NULL;
	WndCls.lpszClassName = szAppName;
	WndCls.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	RegisterClassEx(&WndCls);

	hWnd=CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
		szAppName, TEXT("Крот"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, 1920,1080,
		NULL, NULL, hInstance, NULL);
	//Выводим окно из памяти на экран
	ShowWindow(hWnd, nCmdShow);
	//Обновим содержимое окна
	UpdateWindow(hWnd);
	
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return static_cast<int>(Msg.wParam);
}

LRESULT CALLBACK WindProcedure(HWND hWnd, UINT Msg,
	WPARAM wParam, LPARAM lParam)
{
	int shir=1920,vis=1080,j,x,y,timer=6;
	static int begpnt,scr,rnd1,rnd2,lvlup;
	HDC         hDC;
	PAINTSTRUCT Ps;
//	HFONT	    font;
	static HFONT fontchange,font;
	static HFONT* currentfont = &fontchange;
	RECT r;
	HPEN hPen;
	POINT Pt[3];
	COLORREF clr;
	srand(time(NULL));
    std::basic_stringstream<TCHAR> ss;//,ss1;
	std::basic_string<TCHAR> s=TEXT("/0"),s1;
	/* generate secret number: */
	int RED = (int)rand() % 6+ 1;
	int YE = (int)rand() % 255 + 1;
	int BL = (int)rand() % 255 + 1;
//	static bool ispoint;
	switch (Msg)
	{
		case WM_PAINT:
			hDC = BeginPaint(hWnd, &Ps);
			if(begpnt==0)
			{
				begpnt=1;
				scr=1;
				SetTimer(hWnd , 1, 1000, NULL);
			}
			if(begpnt==1)
			{
//				ispoint=false;
				hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
				SelectObject(hDC,hPen);
				for(int i=1;i<=(vis-60);i=i+30)
				{
					for (j=1;j<=(vis-60);j=j+30)
						Rectangle(hDC,j,i,j+30,i+30);
				}
				shir=j+(shir-j)/2;
				vis=vis/3;
				font = CreateFont(46, 28, 0, 0,
				FW_NORMAL, FALSE, FALSE, FALSE,
				ANSI_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH | FF_ROMAN,
				TEXT("Times New Roman"));
				SelectObject(hDC, font);
				TextOut(hDC,shir-(46*3),(vis/3)-56,TEXT("Твой счёт"),9);
				SelectObject(hDC,hPen);
				Rectangle(hDC,shir-300,vis/3,shir+300,vis);
				SelectObject(hDC, font);
				TextOut(hDC,shir-(46*2),vis*2-((vis/3)*2)-56,TEXT("Уровень"),9);
				ss << scr;
				ss >> s;
				TextOut(Ps.hdc, shir-46,(vis/3)*2-14, s.c_str(), s.size());
				//TextOut(Ps.hdc, shir,vis*2-((vis/3))-56, s.c_str(), s.size());
				TextOut(Ps.hdc, shir-(46),vis*2-56,TEXT("Время") ,6);
			}
			/*if(ispoint==true)
			{
				ss.str(std::basic_string<TCHAR>());
				lvl=1066;
				ss << lvl;
				ss >> s;
				hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
				SelectObject(hDC,hPen);
				for(int i=1;i<=(vis-60);i=i+30)
				{
					for (j=1;j<=(vis-60);j=j+30)
						Rectangle(hDC,j,i,j+36,i+30);
				}
				font = CreateFont(46, 28, 0, 0,
				FW_NORMAL, FALSE, FALSE, FALSE,
				ANSI_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH | FF_ROMAN,
				TEXT("Times New Roman"));
				SelectObject(hDC, font);
				TextOut(Ps.hdc, shir,vis*2-((vis/3))-56, s.c_str(), s.size());
				TextOut(Ps.hdc, shir-(46),vis*2-56+100,TEXT("Время") ,6);
			}*/
			EndPaint(hWnd, &Ps);
			break;
		case WM_LBUTTONDOWN :
			hDC=GetDC(hWnd);
			x=LOWORD(lParam);
			y=HIWORD(lParam);
			clr=GetPixel(hDC,x,y);
			if (clr==RGB(255,0,0))
			{
				KillTimer(hWnd, 1);
				lvlup+=61,25;
				scr++;
//				ispoint=true;
				InvalidateRect(hWnd,NULL,false);
				SetTimer(hWnd,1,1000-lvlup,NULL);
			}
			break;
		case WM_TIMER :
			hDC=GetDC(hWnd);
			r.left=2+rnd1; //левый верхний угол
			r.top=2+rnd2; 
			r.right=29+rnd1; //правый нижний
			r.bottom=29+rnd2;
			FillRect(hDC, &r, (HBRUSH)CreateSolidBrush(RGB(255,255,255)));
			rnd1=(rand()%34)*30;
			rnd2=(rand()%34)*30;
			r.left=2+rnd1; //левый верхний угол
			r.top=2+rnd2; 
			r.right=29+rnd1; //правый нижний
			r.bottom=29+rnd2;
			FillRect(hDC, &r, (HBRUSH)CreateSolidBrush(RGB(255,0,0)));
			//Sleep(1000);
			/*rnd1=(rand()%34)*30;
			rnd2=(rand()%34)*30;
			/*r.left=2+rnd1; //левый верхний угол
			r.top=2+rnd2; 
			r.right=29+rnd1; //правый нижний
			r.bottom=29+rnd2;*/
			//FillRect(hDC, &r, (HBRUSH)CreateSolidBrush(RGB(255,255,255)));
			ReleaseDC(hWnd,hDC);
			break;
	    case WM_DESTROY :
			PostQuitMessage (0) ;
            break; ;
	} 
	return DefWindowProc (hWnd, Msg, wParam, lParam) ;
     }
