#include <windows.h>
#include <vector>
#include <string>
#include <time.h>
#include <sstream>
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

	WNDCLASSEX  WndCls;
	static TCHAR szAppName[] = TEXT(" рот");
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

	CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
		szAppName, TEXT(" рот"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, 1920,1080,
		NULL, NULL, hInstance, NULL);

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
	int shir=1920,vis=1080,j;
	HDC         hDC;
	PAINTSTRUCT Ps;
	HFONT	    font;
	RECT r;
	HPEN hPen;
	POINT Pt[3];
	srand(time(NULL));
	int lvl = 1;
	int time=6;
    std::basic_stringstream<TCHAR> ss;
	std::basic_string<TCHAR> s;
	/* generate secret number: */
	int RED = (int)rand() % 255 + 1;
	int YE = (int)rand() % 255 + 1;
	int BL = (int)rand() % 255 + 1;

	switch (Msg)
	{
		int x,y;
		case WM_PAINT:
			hDC = BeginPaint(hWnd, &Ps);
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
			TextOut(hDC,shir-(46*3),(vis/3)-56,TEXT("“вой счЄт"),9);
			SelectObject(hDC,hPen);
			Rectangle(hDC,shir-300,vis/3,shir+300,vis);
			SelectObject(hDC, font);
			TextOut(hDC,shir-(46*2),vis*2-((vis/3)*2)-56,TEXT("”ровень"),9);
            ss << lvl;
            ss >> s;
            TextOut(Ps.hdc, shir,vis*2-((vis/3))-56, s.c_str(), s.size());
			TextOut(Ps.hdc, shir-(46),vis*2-56,TEXT("¬рем€") ,6);
			for(int i=0; i<s.size();++i)s[i]='\0';
			ss << time;
            ss >> s;
            TextOut(Ps.hdc, shir,vis*2+((vis/3))-56, s.c_str(), s.size());
			EndPaint(hWnd, &Ps);
			break;
		case WM_LBUTTONDOWN :
			hDC=GetDC(hWnd);
			x=LOWORD(lParam);
			y=HIWORD(wParam);
			break;
		case WM_TIMER :
			MessageBox(hWnd, TEXT("ќстановишь мен€?"),TEXT("—ообщение от тјйм≈ра"), MB_OK|MB_ICONQUESTION);
		    r.left=2; //левый верхний угол
			r.top=2; 
			r.right=30; //правый нижний
			r.bottom=30;
			FillRect(hDC, &r, (HBRUSH)CreateSolidBrush(RGB(255,0,0)));
			break;
	    case WM_DESTROY :
			PostQuitMessage (0) ;
            break; ;
	} 
	return DefWindowProc (hWnd, Msg, wParam, lParam) ;
     }
