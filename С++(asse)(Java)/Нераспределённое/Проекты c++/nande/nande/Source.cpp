/*
Петров Константин
Лаб.4
*/
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>
#include<fstream>
using namespace std;

bool IsPrime(int a);
bool IsPalind(int a);
bool IsAdded(int a);

struct Node {
	int val;
	Node* next;

};

class MyQueue {
	Node *first;
	Node *last;
	int size;
public:
	void AddQueue(int a);
	bool IsEmpty();
	void Delete();
	int ShowTop();
	int showSize();
	MyQueue();
	~MyQueue();
};

void MyQueue::AddQueue(int a) {
	last->next = new Node;
	last = last->next;
	last->val = a;
	last->next = NULL;
	size++;
}
inline bool MyQueue::IsEmpty() {
	return (first == last) ? true : false;
}
inline void MyQueue::Delete() {
	Node *temp = first;
	first = first->next;
	size--;
	delete temp;
}
inline int MyQueue::ShowTop() {
	return first->next->val;
}
inline int MyQueue::showSize() {
	return size;
}
MyQueue::MyQueue() {
	first = new Node;
	first->next = NULL;
	last = first;
	size = 0;
}
MyQueue :: ~MyQueue() {
	while (!IsEmpty()) {
		Delete();
	}
	delete first;
}

MyQueue Prime, Palind, Result;


static TCHAR szWindowClass[] = _T("WinApp");
static TCHAR szTitle[] = _T("MyFirstWinApp");
static TCHAR Res[] = _T("Итоговая очередь:");
static TCHAR PalindQ[] = _T("Очередь с палиндромами:");
static TCHAR PrimeQ[] = _T("Очередь с простыми числами:");
int *Queue, Alen = 0;
HINSTANCE hInst;
long lfHeight;
HFONT hFont;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
) {
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	ifstream fin("Input.txt");
	int c;
	while (!fin.eof()) {
		fin >> c;
		if (IsPrime(c) == true) Prime.AddQueue(c);
		if (IsPalind(c) == true) Palind.AddQueue(c);
	}
	fin.close();

	int PrimeSize = Prime.showSize();
	while (PrimeSize) {
		int c = Prime.ShowTop();
		Prime.Delete();
		if (!IsAdded(c)) Result.AddQueue(c);
		PrimeSize--;
		Prime.AddQueue(c);
	}

	int PalindSize = Palind.showSize();
	while (PalindSize) {
		int c = Palind.ShowTop();
		Palind.Delete();
		if (!IsAdded(c)) Result.AddQueue(c);
		PalindSize--;
		Palind.AddQueue(c);
	}

	Queue = new int[Result.showSize()];
	while (!Result.IsEmpty()) {
		int q = Result.ShowTop();
		Result.Delete();
		Queue[Alen++] = q;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int DispWidth = GetSystemMetrics(SM_CXSCREEN);
	int DispHeight = GetSystemMetrics(SM_CYSCREEN);

	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = CreateSolidBrush(RGB(95, 255, 77));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	RegisterClassEx(&wcex);

	hInst = hInstance;

	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		0, 0,
		DispWidth / 2, DispHeight - 40,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Выполнил Петров Константин!");
	int  i = 0, y = 0;
	TCHAR Buff[5];
	switch (message) {
	case WM_CREATE:
		hdc = GetDC(NULL);
		lfHeight = -MulDiv(12, GetDeviceCaps(hdc, LOGPIXELSY/*Кол-во пикселей на дюйм кв.*/), 72);
		ReleaseDC(NULL, hdc);
		hFont = CreateFont(lfHeight, 10, 0, 0, 0, TRUE, FALSE, FALSE, 0, 0, 0, DEFAULT_QUALITY, FF_MODERN, (LPCWSTR)"");
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SelectObject(hdc, hFont);
		SetBkColor(hdc, RGB(95, 240, 77));
		SetTextColor(hdc, RGB(33, 0, 100));
		TextOut(hdc,
			0, 0,
			greeting, _tcslen(greeting));
		//-----------------------------------------------------------
		TextOut(hdc,
			0, 40,
			Res, _tcslen(Res)
		);
		for (int z = 0; z < Alen; z++) {
			int q = Queue[z];
			TextOut(hdc,
				i, 60 + y,
				Buff,
				wsprintf(Buff, TEXT("%d"), q)
			);
			i += 40;
			if (i >= 400) { i = 0; y += 20; }
		}
		//-----------------------------------------------------------
		y += 100;
		i = 0;
		TextOut(hdc,
			0, y,
			PrimeQ, _tcslen(PrimeQ)
		);
		y += 20;

		while (!Prime.IsEmpty()) {
			int z = Prime.ShowTop();
			Prime.Delete();
			TextOut(hdc,
				i, y,
				Buff,
				wsprintf(Buff, TEXT("%d"), z)
			);

			i += 40;
			if (i >= 400) { i = 0; y += 20; }
		}
		//-----------------------------------------------------------
		y += 20;
		i = 0;
		TextOut(hdc,
			0, y,
			PalindQ, _tcslen(PalindQ)
		);
		y += 20;

		while (!Palind.IsEmpty()) {
			int t = Palind.ShowTop();
			Palind.Delete();
			TextOut(hdc,
				i, y,
				Buff,
				wsprintf(Buff, TEXT("%d"), t)
			);
			i += 40;
			if (i >= 400) { i = 0; y += 20; }
		}

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		DeleteObject(hFont);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

bool IsPrime(int a) {  //Функция проверки числа на простоту
	if (a <= 0 || a == 2) return false;
	bool res = true;
	for (int i = 2; i < a; i++)
		if (a % i == 0) {
			res = false;
			break;
		}
	return res;
}
bool IsPalind(int a) {
	if (a == 0)
		return true;
	if (a < 0) a *= (-1);
	bool res = true;
	int rev = 0, a1 = a;
	while (a1) {
		rev = rev * 10 + a1 % 10;
		a1 /= 10;
	}

	if (rev != a) res = false;
	return res;
}
bool IsAdded(int a) {
	bool res = false;
	for (int i = 0; i < Result.showSize(); i++) {
		int q = Result.ShowTop();
		Result.Delete();
		if (q == a)
			res = true;
		Result.AddQueue(q);
	}
	return res;
}
