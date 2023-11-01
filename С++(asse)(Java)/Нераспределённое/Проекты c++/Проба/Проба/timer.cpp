#include<windows.h>

//������ �������� ������� ����
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//��������� ��� ���������
char szProgName[]="��� ���������";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
HWND hWnd;
MSG lpMsg;
WNDCLASS w; //������ ��������� ��������� WNDCLASS
//� �������� � ���������
w.lpszClassName=TEXT("V"); //��� ��������� - ��������� ����
w.hInstance=hInstance; //������������� �������� ����������
w.lpfnWndProc=WndProc; //��������� �� ������� ����
w.hCursor=LoadCursor(NULL, IDC_ARROW); //��������� ������
w.hIcon=0; //������ � ��� �� ����� ����
w.lpszMenuName=0; //� ���� ���� �� �����
w.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH); //���� ���� ����
w.style=CS_HREDRAW|CS_VREDRAW; //����� - ���������������� �� � � �� �
w.cbClsExtra=0;
w.cbWndExtra=0;

//���� �� ������� ���������������� ����� ���� - �������
if(!RegisterClass(&w))
return 0;

//�������� ���� � ������, �������� ��������� CreateWindow
hWnd=CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
		TEXT("M"), TEXT("����"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, 1920,1080,
		NULL, NULL, hInstance, NULL); //���������� �������������� ����������

//������� ���� �� ������ �� �����
ShowWindow(hWnd, nCmdShow);
//������� ���������� ����
UpdateWindow(hWnd);

//��������� ������ � ���������� 1 ���
SetTimer(hWnd, 1, 100, NULL);

//���� ��������� ���������

while(GetMessage(&lpMsg, NULL, 0, 0)) { //�������� ��������� �� �������
TranslateMessage(&lpMsg); //����������� ��������� ������ � �������
DispatchMessage(&lpMsg); //������� ��������� ��������������� ������� ����
}
return(lpMsg.wParam); 
}

//������� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, 
WPARAM wParam, LPARAM lParam)
{
HDC hdc; //������ �������� ����������
PAINTSTRUCT ps; //������ ��������� ��������� ������������ ������

//���� ��������� ���������
switch(messg)
{

//��������� �������
case WM_TIMER:
//����� ���������� ����
MessageBox(hWnd, TEXT("���������� ����?"),TEXT("��������� �� �������"), MB_OK|MB_ICONQUESTION);
break;


//��������� ������ - ���������� ����
case WM_DESTROY:
PostQuitMessage(0); //�������� ��������� ������ � ����� 0 - ���������� ����������
KillTimer(hWnd, 1); //"�������" ������
break;

default:
return(DefWindowProc(hWnd, messg, wParam, lParam)); //����������� ������� ���������� �� �������������
}
return 0;
}