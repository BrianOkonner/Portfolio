/*
Simon Karasik, BSU, FAMCS, 2017
Study practise, task 4
Перевести выражение из префиксной формы в постфиксную и вычислить его значение
*/
#include <windows.h>
#include <string>
#include <cstring>
#include <cstdio>

#include "func.h"
#include <iostream>

using namespace std;

#define ID_INPUT 123
#define ID_BUTTON 124
#define ID_RESULT 125
#define ID_ABOUT 126
#define MAX_BUFFER_SIZE 255

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdShow, int nCmdShow)
{
    MSG msg;
    WNDCLASS wndclass = {0};
    TCHAR CLASS_NAME[] = L"Calculator";
    HWND hWnd;

    wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hInstance = hInstance;
    wndclass.lpfnWndProc = WndProc;
    wndclass.lpszClassName = CLASS_NAME;
    wndclass.style = CS_VREDRAW | CS_HREDRAW;
    RegisterClass(&wndclass);

    hWnd = CreateWindow(CLASS_NAME, L"Calculator",
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    while (GetMessage(&msg, hWnd, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hInput, hButton, hResult, hInputHint, hResultHint;
    static HMENU hMenu, hAbout;
    static int cxClient, cyClient;
    static TCHAR buffer[MAX_BUFFER_SIZE];
    static string expression;

    switch(iMsg)
    {
        case WM_CREATE:
            hInputHint =
                CreateWindow(L"static", L"Expression",
                             WS_VISIBLE | WS_CHILD | SS_CENTER,
                             10, 10,
                             80, 20,
                             hWnd, 0, NULL, NULL);
            hInput =
                CreateWindow(L"edit", NULL,
                             WS_VISIBLE | WS_CHILD | WS_BORDER,
                             100, 10,
                             300, 20,
                             hWnd, (HMENU)ID_INPUT,
                             NULL, NULL);
            hButton =
                CreateWindow(L"button", L"Compute",
                             WS_CHILD | WS_VISIBLE,
                             410, 40,
                             80, 40,
                             hWnd, (HMENU)ID_BUTTON,
                             NULL, NULL);
            hResultHint =
                CreateWindow(L"static", L"Value",
                             WS_CHILD | WS_VISIBLE | SS_CENTER,
                             10, 40,
                             80, 20,
                             hWnd, 0, NULL, NULL);
            hResult =
                CreateWindow(L"edit", NULL,
                             WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY | ES_MULTILINE,
                             100, 40,
                             300, 40,
                             hWnd, (HMENU)ID_RESULT, NULL, NULL);
            hMenu = CreateMenu();
           // hAbout = CreateMenu();
            AppendMenu(hMenu, MF_STRING, ID_ABOUT, L"About");
            SetMenu(hWnd, hMenu);
            SetFocus(hInput);
            return 0;
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case ID_BUTTON:
                    if (HIWORD(wParam) == BN_CLICKED)
                    {
                        char x[MAX_BUFFER_SIZE];
                        GetWindowText(hInput, buffer, MAX_BUFFER_SIZE);
                        wcstombs(x, buffer, MAX_BUFFER_SIZE);
                        expression = x;
                        expression = toPosfix(expression);

                        if (expression.empty())
                            SetWindowText(hResult, L"Error!");
                        
                        else
                        {
                            double value = compute(expression);
                            TCHAR z[MAX_BUFFER_SIZE];
                            mbstowcs(z, expression.c_str(), MAX_BUFFER_SIZE);
                            _swprintf(buffer, L"%s\r\n%0.2f", z, value);
                            SetWindowText(hResult, buffer);
                        }
                        return 0;
                    }
                    case ID_ABOUT:
                        MessageBox(
                            hWnd, 
                            L"Simple expressions calculator.\
                            \r\nTransforms expression to postix notation, supports +,-,*,/,^.\
                            \r\n\By Simon Karasik, BSU, FAMCS, 2017",
                            L"About",
                            MB_OK);
                        return 0;

 
                default:
                    DefWindowProc(hWnd, iMsg, wParam, lParam);
            }
            return 0;


        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hWnd, iMsg, wParam, lParam);
    }
}