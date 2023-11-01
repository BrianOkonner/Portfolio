//mmmmmmm/
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <cmath>
#include <clocale>

bool Number(char *str,int l)
{
	if(str[0]==48) return false;
	while(l--)
		if((str[l]<48)||(str[l]>57))
			return false;
	return true;
}

__int64 sum_del(int n)
{
	__int64 count=1;
	for (int i=2; i<sqrt((double)n); i++)
		if (n%i==0)
			count=count+i+n/i;
	return count;
}

static TCHAR szWindowClass[] = _T("win32app");

static TCHAR szTitle[] = _T("Является ли число совершенным");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }

    hInst = hInstance;
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        400, 225,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
	static HWND button, edit;
	HFONT hFont = CreateFont(32,0,0,0,0,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, DEFAULT_PITCH,NULL);
    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
		SelectObject(hdc,hFont);
        TextOut(hdc,
            93, 15,
            TEXT("Введите число"), strlen("Введите число"));
        EndPaint(hWnd, &ps);
        break;
	case WM_CREATE:
		button=CreateWindow(TEXT("button"),TEXT("Проверить"),WS_CHILD|WS_VISIBLE,40,125,300,40,hWnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		edit=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,40,65,300,40,hWnd,(HMENU) 1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		break;
	case WM_COMMAND:
		if(HIWORD(wParam)==BN_CLICKED)
		{
			TCHAR *str;
			__int64 n;
			int l;
			l=GetWindowTextLength(edit);
			str=new TCHAR[l+1>20?20:l+1];
			GetWindowText(edit,str,l+1>20?20:l+1);
			n=_wtoi64(str);
			if (n==0)
				MessageBox(hWnd, TEXT("Введенная строка не является числом"), TEXT("Ошибка"), MB_OK|MB_ICONINFORMATION);
			else
			{
				char *mes=new char [150], *d=new char [20], *e=new char [20];
				_i64toa_s(sum_del(n), d, 20, 10);
				_i64toa_s(n, e, 20, 10);
				strcpy_s(mes, 150, "Введенное число = ");
				strcat_s(mes, 150, e);
				strcat_s(mes, 150, "\nСумма делителей числа = ");
				strcat_s(mes, 150, d);
				if (sum_del(n)==n)
					strcat_s(mes, 150, "\nДанное число совершенное");
				else
					strcat_s(mes, 150, "\nДанное число не является совершенным");
				TCHAR *res=new TCHAR[150];
				size_t size=0;
				setlocale(LC_ALL, "Russian");
				mbstowcs_s(&size, res, 150, mes, _TRUNCATE);
				MessageBox(hWnd, res, TEXT("Результат"), MB_OK|MB_ICONINFORMATION);
			}
		}
		if(LOWORD(wParam)==1)        
			if(HIWORD(wParam)==EN_ERRSPACE||HIWORD(wParam)==EN_MAXTEXT)
				MessageBox(hWnd,TEXT("Превышен размер ввода"),TEXT("Ошибка"),MB_OK|MB_ICONSTOP);
			break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}