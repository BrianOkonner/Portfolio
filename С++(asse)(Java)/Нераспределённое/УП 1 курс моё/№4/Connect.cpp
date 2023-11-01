
#undef UNICODE
#include <windows.h> // ������������ ����, ���������� ����������� ��� ������� ����������� � API

#define MAXPOINTS 1000
#define MoveTo(hdc, x, y) MoveToEx (hdc, x, y, NULL)

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // ���� � ���������

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, // ����� ����� � ���������
	PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "Connect";
	HWND        hwnd;   
	MSG         msg;      
	WNDCLASSEX  wndclass;   

	wndclass.cbSize = sizeof(wndclass); 
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;          
	wndclass.cbClsExtra = 0;                 
	wndclass.cbWndExtra = 0;                 
	wndclass.hInstance = hInstance;  		
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);  
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
	wndclass.lpszMenuName = NULL;                              
	wndclass.lpszClassName = szAppName;                       
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);  

	RegisterClassEx(&wndclass); 
	hwnd = CreateWindow(szAppName, "Connect-the-Points Mouse Demo",  
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow); 
	UpdateWindow(hwnd); 

	while (GetMessage(&msg, NULL,  // NULL - ������ ��������� 
		0,						   // ����������� �������� ����. �����.	
		0))						   // ������������ �������� ����. �����.
	{
		TranslateMessage(&msg);	   // �������������� ��������� �� ����������
		DispatchMessage(&msg);	   // ��p����� ��������� ��� ������� ����
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam){  // wparam ��� int and handle // lparam - pointers
	static POINT points[MAXPOINTS];						// ���������� �������, ����������� ��������� � ����������� � ����������� �����
	static int   iCount;							
	HDC          hdc;	
	PAINTSTRUCT  ps;	
	int          i, j;	

	switch (iMsg){
	case WM_LBUTTONDOWN: // ������ ����������� ��������� WM_LBUTTONDOWN
		iCount = 0;
		InvalidateRect(hwnd, NULL, TRUE); // ���������� Rect � ������� ���������� ���� (������� ������������ � ���� ���������� �������������)
		return 0;

	case WM_MOUSEMOVE: // ������ ����������� ��������� WM_MOUSEMOVE
		if (wParam & MK_LBUTTON && iCount < 1000){
			points[iCount].x = LOWORD(lParam); // ��������� �� 32-�������� �������������� �������� �������� ����� (��������� ���������� x ����)
			points[iCount++].y = HIWORD(lParam); // ��������� �� 32-�������� �������������� �������� �������� ����� (��������� ���������� y ����)

			hdc = GetDC(hwnd); 
			SetPixel(hdc, LOWORD(lParam), HIWORD(lParam), 0L); // ��������� �������� ����p������ � ��������� ����� ///  0L - ���� �����
			ReleaseDC(hwnd, hdc); // ������������ ��������� ����������
		}
		return 0;

	case WM_LBUTTONUP: // ������ ����������� ��������� WM_LBUTTONUP
		InvalidateRect(hwnd, NULL, FALSE);  // ���������� Rect � ������� ���������� ���� (������� ������������ � ���� ���������� �������������)
		return 0;

	case WM_PAINT: // ������ ����������� ��������� WM_PAINT (���������� ����� �������)
		hdc = BeginPaint(hwnd, &ps); // ���������� ���� � p���p���� � ����� �� ��������� wm_Paint (���������� Paint ����p������ ��� p���p����)

		SetCursor(LoadCursor(NULL, IDC_WAIT)); // ��������� ����� �������
		ShowCursor(TRUE); // ��p��p ������������

		for (i = 0; i < iCount - 1; i++) // �������� ���� ����� (��������� ����)
			for (j = i + 1; j < iCount; j++){
				MoveTo(hdc, points[i].x, points[i].y); // ������� ������ �� �������� ���������� (������� � �������)
				LineTo(hdc, points[j].x, points[j].y); // ��������� ����� �� ��������� � �������� �����������
			}

		ShowCursor(FALSE); // ��p��p �� ������������
		SetCursor(LoadCursor(NULL, IDC_ARROW)); // ��������� ����� �������

		EndPaint(hwnd, &ps); // �������� ����� p���p���� � Wnd
		return 0;

	case WM_DESTROY: // ������ ����������� ��������� WM_DESTROY
		PostQuitMessage(0); // ���p������� ��������� wm_Quit � ����� �� ��������� wm_Destroy
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam); // ����������� ���������� ��������� ��������� (������������ ������p���� ��p������ ��������� ��� ���������, ����p�� ���� �� ��p����������� �p�������� �������)
}
