#define hm1 1
#define hm2 2
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <clocale>

template <class T> class QueueItem{
public:
	T value;
	QueueItem* next;
	QueueItem() :next(NULL){};
	QueueItem(const QueueItem &qi)
	{
		value = qi.value;
		next = qi.next;
	}
};

template <class Type>
class Queue {
public:
	Queue() : front(NULL), back(NULL) { };
	Queue(const Queue&);
	~Queue();
	Type show_front();
	Type pop_front();
	QueueItem<Type> * GetFront()
	{
		return Q1.front;
	}
	Type popped;
	void push_back(Type);
	bool is_empty() const {
		return front == 0;
	}
private:
	QueueItem<Type> *front;
	QueueItem<Type> *back;
};

template <class Type>
void Queue<Type>::push_back(Type T1)
{
	QueueItem<Type> *temp = new QueueItem<Type>[1];
	temp->value = T1;
	temp->next = NULL;
	if (front == 0 && back == 0)
	{
		front = temp;
		back = temp;
	}
	else
	{
		if (front == back)
		{
			front->next = temp;
			back = temp;
		}
		else
		{
			back->next = temp;
			back = temp;
		}
	}
}

template <class Type>
Queue<Type>::Queue(const Queue<Type>& Q1)
{
	if (!Q1.is_empty())
	{
		QueueItem<Type>* temp_item = Q1.front;
		while (temp_item)
		{
			push_back(temp_item->value);
			temp_item = temp_item->next;
		}
	}
	else
	{
		this->front = NULL;
		this->back = NULL;
	}
}

template <class Type>
Type Queue<Type>::pop_front()
{
	if (!is_empty())
	{
		QueueItem<Type> *temp = front;
		Type t = temp->value;
		front = front->next;
		if (is_empty())
			back = NULL;
		delete[] temp;
		return t;
	}
	else
	{
		front = NULL;
		back = NULL;
		return -4323;
	}
}

template <class Type>
Type Queue<Type>::show_front()
{
	if (!is_empty())
	{
		return front->value;
	}
	else
		throw - 1;
}


template <class Type>
Queue<Type>::~Queue()
{
	//cout << "!Destructor" << endl;
	while (!is_empty())
		pop_front();
}

Queue<int> Q1;


static TCHAR szWindowClass[] = _T("Queue");

static TCHAR szTitle[] = _T("CLASS QUEUE");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Q1.push_back(21);
	Q1.push_back(22);
	Q1.push_back(23);
	Q1.push_back(24);
	Q1.push_back(25);
	Q1.push_back(26);

	WNDCLASSEX wcex;
	
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = CreateSolidBrush(RGB(255, 243, 186));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}


	HDC hDC;								// Окно по центру экрана
	hDC = GetDC(0);
	int Width = 600, Height = 400;
	int x, y;								
	x = GetDeviceCaps(hDC, HORZRES);
	y = GetDeviceCaps(hDC, VERTRES);
	ReleaseDC(0, hDC);
	int Left = (x - Width) / 2;
	int Top = (y - Height) / 2;

	hInst = hInstance;
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		Left, Top,
		Width, Height,
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
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	TCHAR *temp_str2 = new TCHAR[7];
	HDC hdc;
	RECT rect = { 0 };
	GetClientRect(hWnd, &rect);
	//int right_position = rect.right - 175;
	int i = 0;
	QueueItem<int>* temp_item = Q1.GetFront();
	static HWND push_button, pop_button, edit;
	HFONT hFont = CreateFont(15, 0, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, NULL);
	switch (message)
	{
	case WM_PAINT:
		GetClientRect(hWnd, &rect);
		hdc = BeginPaint(hWnd, &ps);
		SelectObject(hdc, hFont);
		SetBkColor(hdc, RGB(255, 243, 186));
		TextOut(hdc, rect.left + 35, rect.top + 20, TEXT("Insert number:"), strlen("Insert number:"));
		TextOut(hdc, (rect.left + rect.right) / 4 , rect.top + 20, TEXT("Queue:"), strlen("Queue:"));
		if (!Q1.is_empty())
		{
			while (temp_item)
			{
				TCHAR *temp_str = new TCHAR[7];
				temp_str = _itow(temp_item->value, temp_str, 10);
				TextOut(hdc, (rect.left + rect.right) / 4 + i, rect.top + 40, temp_str, _tcslen(temp_str));
				temp_item = temp_item->next;
				i += 40;
			}
		}
		TextOut(hdc, rect.left + 35 , rect.top + 100, TEXT("Popped number:"), strlen("Popped number:"));
		temp_str2 = _itow(Q1.popped, temp_str2, 10);
		TextOut(hdc, rect.left + 35, rect.top + 120, temp_str2, _tcslen(temp_str2));
		EndPaint(hWnd, &ps);
		break;
	case WM_CREATE:
		push_button = CreateWindow(TEXT("button"), TEXT("Push"), WS_CHILD | WS_VISIBLE, rect.left + 35, rect.top + 65, 100, 20, hWnd, (HMENU) hm1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		edit = CreateWindow(TEXT("Edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, rect.left + 35, rect.top + 40, 100, 20, hWnd, (HMENU) hm1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		pop_button = CreateWindow(TEXT("button"), TEXT("Pop"), WS_CHILD | WS_VISIBLE, rect.left + 35, rect.top + 140, 100, 20, hWnd, (HMENU)hm2, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		break;
	case WM_COMMAND:
		if (wParam == hm2)
		{
			if (!Q1.is_empty())
			{
				Q1.popped = Q1.show_front();
				Q1.pop_front();
			}
			InvalidateRect(hWnd, 0, true);
		}
		else
		{
		
			if (wParam == hm1)
			{
				TCHAR *str;
				__int64 n;
				int l;
				l = GetWindowTextLength(edit);
				str = new TCHAR[l + 1>20 ? 20 : l + 1];
				GetWindowText(edit, str, l + 1>20 ? 20 : l + 1);
				n = _wtoi64(str);
				if (n == 0)
					MessageBox(hWnd, TEXT("Введенная строка не является числом"), TEXT("Ошибка"), MB_OK | MB_ICONINFORMATION);
				else
				{
					Q1.push_back(n);
					InvalidateRect(hWnd, 0, true);
				}
			}
		//if (LOWORD(wParam) == 1)
		//if (HIWORD(wParam) == EN_ERRSPACE || HIWORD(wParam) == EN_MAXTEXT)
		//	MessageBox(hWnd, TEXT("Превышен размер ввода"), TEXT("Ошибка"), MB_OK | MB_ICONSTOP);
		}
		return(DefWindowProc(hWnd, message, wParam, lParam));
		break;
	case WM_DESTROY: //При закрытии приложения
		DeleteObject(hFont);// пользователем
		PostQuitMessage(0); //Завершим приложение
		return 0; //Возврат в Windows
	default: //Остальные сообщения обработать
		//по умолчанию
		return(DefWindowProc(hWnd, message, wParam, lParam));
		break;
	}
	return 0;
}