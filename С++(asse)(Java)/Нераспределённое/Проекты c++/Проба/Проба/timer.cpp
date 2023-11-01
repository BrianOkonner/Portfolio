#include<windows.h>

//Создаём прототип функции окна
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//объявляем имя программы
char szProgName[]="Имя программы";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
HWND hWnd;
MSG lpMsg;
WNDCLASS w; //создаём экземпляр структуры WNDCLASS
//И начинаем её заполнять
w.lpszClassName=TEXT("V"); //имя программы - объявлено выше
w.hInstance=hInstance; //идентификатор текущего приложения
w.lpfnWndProc=WndProc; //указатель на функцию окна
w.hCursor=LoadCursor(NULL, IDC_ARROW); //загружаем курсор
w.hIcon=0; //иконки у нас не будет пока
w.lpszMenuName=0; //и меню пока не будет
w.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH); //цвет фона окна
w.style=CS_HREDRAW|CS_VREDRAW; //стиль - перерисовываемое по х и по у
w.cbClsExtra=0;
w.cbWndExtra=0;

//Если не удалось зарегистрировать класс окна - выходим
if(!RegisterClass(&w))
return 0;

//Создадим окно в памяти, заполнив аргументы CreateWindow
hWnd=CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
		TEXT("M"), TEXT("Крот"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, 1920,1080,
		NULL, NULL, hInstance, NULL); //отсутствие дополнительных параметров

//Выводим окно из памяти на экран
ShowWindow(hWnd, nCmdShow);
//Обновим содержимое окна
UpdateWindow(hWnd);

//Установим таймер с интервалом 1 сек
SetTimer(hWnd, 1, 100, NULL);

//Цикл обработки сообщений

while(GetMessage(&lpMsg, NULL, 0, 0)) { //Получаем сообщение из очереди
TranslateMessage(&lpMsg); //Преобразует сообщения клавиш в символы
DispatchMessage(&lpMsg); //Передаёт сообщение соответствующей функции окна
}
return(lpMsg.wParam); 
}

//Функция окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, 
WPARAM wParam, LPARAM lParam)
{
HDC hdc; //создаём контекст устройства
PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода

//Цикл обработки сообщений
switch(messg)
{

//Сообщение таймера
case WM_TIMER:
//Вызов дилогового окна
MessageBox(hWnd, TEXT("Остановишь меня?"),TEXT("Сообщение от тАймЕра"), MB_OK|MB_ICONQUESTION);
break;


//сообщение выхода - разрушение окна
case WM_DESTROY:
PostQuitMessage(0); //Посылаем сообщение выхода с кодом 0 - нормальное завершение
KillTimer(hWnd, 1); //"Убиваем" таймер
break;

default:
return(DefWindowProc(hWnd, messg, wParam, lParam)); //освобождаем очередь приложения от нераспознаных
}
return 0;
}