//
//����� ����������� ���������� � �������������� WinAPI �������������� � ������� ��������� ���������� (��� HDC, Handle of Device Context):
//1 �������� �������� ������ ����� �����;
//2 ������� ����������� �������� �� ������� ����� �������� ����������� (������������ ��� ������� �����������);
//3 ������� ����� ��� �������� ���� ������ ������;
//4 ����������� ���������� ������� ������ ����;
//5 ������� ��������� �����;
//6 ������ �� ������� ��������� (hCmpDC);
//7 �������� ����������� �� �������� �������� ������ ����� � ����;
//8 ����������� ��������� ��������� �������.

//����. ����� �� �������� ��������� ��������� ����� (brush), ��������� (pen), ������� (region) � ������ ����������� �������, �.�. ��� ����� � ���� ������ ���������.	
#include <windows.h>
#undef UNICODE
#pragma comment (lib, "winmm.lib")
// ������� ������� ��������� �����������
void DrawImage(HDC hDC,     // ���������� ��������� ��� ������
        HBITMAP hBitmap,    // ���������� �����������, ������� ������
        int x,              // ���������� ���������
        int y)
{
    // ������� �������� ��� ��������������� �����������
    HDC     hBDC        = CreateCompatibleDC(hDC);
    // ��������� ����������� � ���� ��������, ��������� ���������� ����������� � hOldBitmap
    HGDIOBJ hOldBitmap  = SelectObject(hBDC, hBitmap);
    // ��������� ���������� ���� ��������� BITMAP
    BITMAP bInfo;
    // ���������� � ���� ���������� bInfo ���������� �� �����������.
    // ��� ���������� ������ � ������
    GetObject(hBitmap, sizeof(bInfo), &bInfo);
    // ����������� ����������� ��������� ����������� (hBDC) � ������� ��������(hDC)
    BitBlt(hDC,                                 // ���������� �������� ��������� (���� ������)
            x,y,bInfo.bmWidth,bInfo.bmHeight,   // ������������� ������� �������� ���������
            hBDC,                               // ���������� ��������� ��������� (������� ������)
            0,0,                                // ���������� ������ �������� ���� ��������� ���������
            SRCCOPY);                           // ��� ��������� (SRCCOPY - ������ �������� �������� �� ������� ��������� ����������)
    // ��������������� ���������� ����������� � ��������� ��������
    SelectObject(hBDC, hOldBitmap);
    // ������� �������� ����������� - �� ������ �� �����
    DeleteDC(hBDC);
}
const double PI = 3.141592653;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

char szClassName[] = "CG_WAPI_Template";

////////////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
      HWND hWnd;  
      MSG lpMsg;
      WNDCLASS wc;

      // ��������� ��������� ������ ����
      wc.style         = CS_HREDRAW | CS_VREDRAW;
      wc.lpfnWndProc   = WndProc;
      wc.cbClsExtra    = 0;
      wc.cbWndExtra    = 0;
      wc.hInstance     = hInstance;
      wc.hIcon         = NULL;      
      wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
      wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
      wc.lpszMenuName  = NULL;
      wc.lpszClassName = szClassName;
 
      // ������������ ����� ����
      if (!RegisterClass(&wc))
      {
            MessageBox(NULL, "�� ���� ���������������� ����� ����!", "������", MB_OK);
            return 0;
      }

      // ������� �������� ���� ����������
      hWnd = CreateWindow( 
            szClassName,                // ��� ������                    
            "������ WinAPI ����������", // ����� ��������� 
            WS_OVERLAPPEDWINDOW,        // ����� ����                                              
            50,   50,                   // ������� ������ �������� ����   
            600,  600,                  // ������ � ������ ����     
            (HWND) NULL,                // ��������� �� ������������ ���� NULL     
            (HMENU) NULL,               // ������������ ���� ������ ����               
            (HINSTANCE)hInstance,       // ��������� �� ������� ����������
            NULL    );                  // ���������� � �������� lParam � ������� WM_CREATE

      if (!hWnd) 
      {
            MessageBox(NULL, "�� ������� ������� ������� ����!", "������", MB_OK);
            return 0;
      }

      // ���������� ���� ����
      ShowWindow(hWnd, nCmdShow); 
      UpdateWindow(hWnd);

      // ��������� ���� ��������� ��������� �� �������� ����������
      while (GetMessage(&lpMsg, NULL, 0, 0))  
      {
            TranslateMessage(&lpMsg);
            DispatchMessage(&lpMsg);
      }
      return (lpMsg.wParam);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
      PAINTSTRUCT ps;
      RECT Rect;
      HDC hdc, hCmpDC;
      HBITMAP hBmp;

      switch (messg)
      {
            case WM_PAINT:

                 GetClientRect(hWnd, &Rect);
                  hdc = BeginPaint(hWnd, &ps);

                  // �������� ��������s ��������� ��� ������� ������������
                  hCmpDC = CreateCompatibleDC(hdc);
                  hBmp = CreateCompatibleBitmap(hdc, Rect.right - Rect.left,
                        Rect.bottom - Rect.top);
                  SelectObject(hCmpDC, hBmp);
 
                  // �������� ������� ������
                  LOGBRUSH br;
                  br.lbStyle = BS_SOLID;
                  //br.lbColor = 0xEECCCC;
				   br.lbColor = 0xEE0001;
                  HBRUSH brush;
                  brush = CreateBrushIndirect(&br);
                  FillRect(hCmpDC, &Rect, brush);
                  DeleteObject(brush);

                  // ����� ������ �� ��������� hCmpDC

                  // �������� ����������� �� �������� ��������� �� �����
                  SetStretchBltMode(hdc, COLORONCOLOR);
					
				  for (int a=1; a<200;a+=10)
				  {
                  BitBlt(hdc,					// ���������� �������� ��������� (���� ������)
					  a, a, a+10,a+10,			// ������������� ������� �������� ���������
                        hCmpDC,				    // ���������� ��������� ��������� (������� ������)
						0, 0,				    // ���������� ������ �������� ���� ��������� ���������
						SRCCOPY);	}			// ��� ��������� (SRCCOPY - ������ �������� �������� �� ������� ��������� ����������)
     // ��� ���
	/*			     BitBlt(hdc,												// ���������� �������� ��������� (���� ������)
					  0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top,// ������������� ������� �������� ���������
                        hCmpDC,										      // ���������� ��������� ��������� (������� ������)
						0, 0,											 // ���������� ������ �������� ���� ��������� ���������
						SRCCOPY);					// ��� ��������� (SRCCOPY - ������ �������� �������� �� ������� ��������� ����������)
   

*/
    
                         
    // ��������������� ���������� ����������� � ��������� ��������      SelectObject(hBDC, hOldBitmap);
    // ������� �������� ����������� - �� ������ �� �����                DeleteDC(hBDC);

                  // ������� �������� ��������� �������
                  DeleteDC(hCmpDC);
                  DeleteObject(hBmp);
                  hCmpDC = NULL; 

                  EndPaint(hWnd, &ps);
                  break;

            case WM_DESTROY:
                  PostQuitMessage(0);
                  break;

            default:
                  return (DefWindowProc(hWnd, messg, wParam, lParam));
      }
      return (0);
}