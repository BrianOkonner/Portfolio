
#include "human.h"
LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

//void CALLBACK proc(HWND, UINT, UINT, DWORD);
#define NUMBER 7
#define ID_ATTACK_1 1001
#define ID_ATTACK_2 1002
#define ID_ATTACK_3 1003
#define ID_ATTACK_4 1004
#define ID_ATTACK_5 1005
#define ID_ATTACK_6 1006
#define ID_ATTACK_7 1007
//SYSTEMTIME st;
char pBuffer[50];// буфер для хранения данных из файла
HFONT oldFont, newFont;


void info(HWND hwnd, creature hero)
{
	MessageBox(hwnd, itoa(hero.gethp(),pBuffer,10), "name", 1);
}
//-----------------WinMain-------------------

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS w;
	memset(&w, 0, sizeof(WNDCLASS));
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc;
	w.hInstance = hInstance;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.lpszClassName = "My Class";
	RegisterClass(&w);
	hwnd = CreateWindow("My Class", "My title", WS_OVERLAPPEDWINDOW,
		500, 300, 500, 400, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	//SetTimer(hwnd, 1, 1000, NULL);
	//SetTimer(hwnd, 2, 2000, NULL);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//KillTimer(hwnd, 1);
	return msg.wParam;
}

//-----------------WndProc-------------------

LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	static int x, y;// Статические переменные для центра рисуемого круга.
	static int size_x, size_y, block_height, block_width; // Статические переменные для размера окна. 
	int click_x, click_y;// Переменные для координат щелчка мыши.
	static int interval = 2000; // Статическая переменная для интервала таймера.
	static int k;// Число попаданий.
	static HWND Attack1, Attack2, Attack3, Attack4, Attack5, Attack6, Attack7;
	//GetStockObject(DEFAULT_GUI_FONT);


	//------------------variables--------------------
	char name[10];
	static creature hero("maksim");
	static creature ennemy1(1, "ennemy1");
	static creature ennemy2(4, "ennemy2");
	static creature ennemy3(7, "ennemy3");
	static creature ennemy4(12, "ennemy4");
	static creature ennemy5(16, "ennemy5");
	static creature ennemy6(25, "ennemy6");
	static creature BOSS(60, "BOSS");
	HDC hdc;
	PAINTSTRUCT ps;

	//--------------------program---------------------
	switch (Message)
	{
	case WM_SIZE:
		size_x = LOWORD(lparam); //Запоминаем текущие размеры окна.
		size_y = HIWORD(lparam);
		break;

	case WM_PAINT:
		
		hdc = BeginPaint(hwnd, &ps);
		
		//-------------------font-------------------

		SetTextColor(hdc, RGB(255, 0, 0));
		SetBkColor(hdc, RGB(255, 255, 255));
		newFont = CreateFont(12, 8, 1, 0, 20, 10, 0, 0, NULL, NULL, NULL, NULL,
			NULL, ("Arial"));
		oldFont = (HFONT)SelectObject(hdc, newFont);

		//------------------------------------------

		block_height = size_y / NUMBER;
		block_width = size_x / 4;
		for (int i = 0; i < NUMBER; i++)
		{
			Rectangle(hdc, 0, i*block_height, block_width, (i + 1)*block_height);
			TextOut(hdc, block_width / 2, i*block_height + block_height / 2, itoa(i + 1, name, 10), 1);
		}
		Rectangle(hdc, size_x/1.4, 0, size_x,block_height*2);
		TextOut(hdc, (size_x+size_x/1.25)/2- hero.getthename().length()*5, 1, hero.getthename().c_str(), hero.getthename().length());
		pBuffer[0] = '\0';

		strcpy(pBuffer, "lvl: ");
		strcat(pBuffer, itoa(hero.getlvl(), name, 10));
		TextOut(hdc, (size_x / 1.4)+3, 20,  "hello world"  , 20);
		pBuffer[0] = '\0';

		strcpy(pBuffer, "exp: ");
		strcat(pBuffer, itoa(hero.getxp(), name, 10));
		strcat(pBuffer, "/");
		strcat(pBuffer, itoa(hero.getlvl()*40, name, 10));
		TextOut(hdc, (size_x / 1.4) + 3, 32, pBuffer, strlen(pBuffer));
		pBuffer[0] = '\0';

		strcpy(pBuffer, "health: ");
		strcat(pBuffer, itoa(hero.gethp(), name, 10));
		TextOut(hdc, (size_x / 1.4) + 3, 44, pBuffer, strlen(pBuffer));
		pBuffer[0] = '\0';

		strcpy(pBuffer, "attack: ");
		strcat(pBuffer, itoa(hero.getattack(), name, 10));
		TextOut(hdc, (size_x / 1.4) + 3, 56, pBuffer, strlen(pBuffer));
		pBuffer[0] = '\0';

		strcpy(pBuffer, "defence: ");
		strcat(pBuffer, itoa(hero.getdefence(), name, 10));
		TextOut(hdc, (size_x / 1.4) + 3, 68, pBuffer, strlen(pBuffer));
		pBuffer[0] = '\0';

		EndPaint(hwnd, &ps);
		break;
	
	case WM_LBUTTONDOWN:
	{
		click_x = LOWORD(lparam); // Получаем место, в котором щелкнули мышкой.
		click_y = HIWORD(lparam);
		if (click_x < block_width) // Если попали.
		{
			switch (click_y / block_height)
			{
			case 0:
				DestroyWindow(Attack2); DestroyWindow(Attack3); DestroyWindow(Attack4); DestroyWindow(Attack5); DestroyWindow(Attack6); DestroyWindow(Attack7);
				Attack1 = CreateWindow("button", "Attack", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_BORDER, size_x / 2, size_y / 2, 100, 50, hwnd, (HMENU)ID_ATTACK_1, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd, "1");
				break;
			case 1:
				DestroyWindow(Attack1); DestroyWindow(Attack3); DestroyWindow(Attack4); DestroyWindow(Attack5); DestroyWindow(Attack6); DestroyWindow(Attack7);
				Attack2 = CreateWindow("button", "Attack", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, size_x / 2, size_y / 2, 100, 50, hwnd, (HMENU)ID_ATTACK_2, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd, "2");
				break;
			case 2:
				DestroyWindow(Attack1); DestroyWindow(Attack2); DestroyWindow(Attack4); DestroyWindow(Attack5); DestroyWindow(Attack6); DestroyWindow(Attack7);
				Attack3 = CreateWindow("button", "Attack", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, size_x / 2, size_y / 2, 100, 50, hwnd, (HMENU)ID_ATTACK_3, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd, "3");
				break;
			case 3:
				DestroyWindow(Attack1); DestroyWindow(Attack2); DestroyWindow(Attack3); DestroyWindow(Attack5); DestroyWindow(Attack6); DestroyWindow(Attack7);
				Attack4 = CreateWindow("button", "Attack", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, size_x / 2, size_y / 2, 100, 50, hwnd, (HMENU)ID_ATTACK_4, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd, "4");
				break;
			case 4:
				DestroyWindow(Attack1); DestroyWindow(Attack2); DestroyWindow(Attack3); DestroyWindow(Attack4); DestroyWindow(Attack6); DestroyWindow(Attack7);
				Attack5 = CreateWindow("button", "Attack", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, size_x / 2, size_y / 2, 100, 50, hwnd, (HMENU)ID_ATTACK_5, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd, "5");
				break;
			case 5:
				DestroyWindow(Attack1); DestroyWindow(Attack2); DestroyWindow(Attack3); DestroyWindow(Attack4); DestroyWindow(Attack5); DestroyWindow(Attack7);
				Attack6 = CreateWindow("button", "Attack", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, size_x / 2, size_y / 2, 100, 50, hwnd, (HMENU)ID_ATTACK_6, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd, "6");
				break;
			case 6:
				DestroyWindow(Attack1); DestroyWindow(Attack2); DestroyWindow(Attack3); DestroyWindow(Attack4); DestroyWindow(Attack5); DestroyWindow(Attack6);
				Attack7 = CreateWindow("button", "Attack", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, size_x / 2, size_y / 2, 100, 50, hwnd, (HMENU)ID_ATTACK_7, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd, "7");
				break;
			default:
				break;
			}
		}
		break;
	}
	case WM_COMMAND:
	{
		
		hdc = BeginPaint(hwnd,&ps);
		switch (LOWORD(wparam))
		{

		case ID_ATTACK_1:
			ennemy1.attacked1(hero);
			if (hero.attacked(ennemy1, hdc) == true) { TextOut(hdc, size_x / 2, size_y / 2 - 100, "Nice!", strlen("Nice!")); }
			
			InvalidateRect(hwnd, NULL, TRUE);	
			UpdateWindow(hwnd); 
			if (hero.gethp() <= 0)
				if (IDOK == MessageBox(hwnd, "you died", "you died", MB_OK))
			SendMessage(hwnd, WM_CLOSE, wparam, lparam);
			break;
		case ID_ATTACK_2:
			if (hero.attacked(ennemy2,hdc) == true) {}
			else ennemy2.attacked1(hero);
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
			if (hero.gethp() <= 0)
				if (IDOK == MessageBox(hwnd, "you died", "you died", MB_OK))
			SendMessage(hwnd, WM_CLOSE, wparam, lparam);
			break;
		case ID_ATTACK_3:
			if (hero.attacked(ennemy3, hdc) == true) {}
			else ennemy3.attacked1(hero);
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
			if (hero.gethp() <= 0)
				if (IDOK == MessageBox(hwnd, "you died", "you died", MB_OK))
					SendMessage(hwnd, WM_CLOSE, wparam, lparam);
			break;
		case ID_ATTACK_4:
			if (hero.attacked(ennemy4, hdc) == true) {}
			else ennemy4.attacked1(hero);
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
			if (hero.gethp() <= 0)
				if (IDOK == MessageBox(hwnd, "you died", "you died", MB_OK))
			SendMessage(hwnd, WM_CLOSE, wparam, lparam);
			break;
		case ID_ATTACK_5:
			if (hero.attacked(ennemy5, hdc) == true) {}
			else ennemy5.attacked1(hero);
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
			if (hero.gethp() <= 0)
				if (IDOK == MessageBox(hwnd, "you died", "you died", MB_OK))
			SendMessage(hwnd, WM_CLOSE, wparam, lparam);
			break;
		case ID_ATTACK_6:
			if (hero.attacked(ennemy6, hdc) == true) {}
			else ennemy6.attacked1(hero);
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
			if (hero.gethp() <= 0)
				if (IDOK == MessageBox(hwnd, "you died", "you died", MB_OK))
			SendMessage(hwnd, WM_CLOSE, wparam, lparam);
			break;
		case ID_ATTACK_7:
			if (hero.attacked(BOSS, hdc) == true) {}
			else BOSS.attacked1(hero);
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
			if (hero.gethp() <= 0)
				if(IDOK==MessageBox(hwnd, "you died", "you died", MB_OK))
					SendMessage(hwnd, WM_CLOSE, wparam, lparam);
			break;

		default:
			break;
		}

		break;
		EndPaint(hwnd, &ps);
	}
	
	case WM_CLOSE:
		PostQuitMessage(0);
		DestroyWindow(hwnd);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		DestroyWindow(hwnd);
		return 0;
	default:
		return DefWindowProc(hwnd, Message, wparam, lparam);
	}
	return 0;
}





//сделать обновление каждые пару секунд с помощью таймера
//сделать восстановление здоровья со временем с помощью таймера
// сделать удобное переключение между клавишами с помощью клавиатуры



//VOID CALLBACK proc(HWND hwnd, UINT, UINT, DWORD)
//{
//	static BOOL b = FALSE;
//	if (b)
//	{
//		SetWindowText(hwnd, "Title 1");
//	}
//	else
//	{
//		SetWindowText(hwnd, "Title 2");
//	}
//	b = !b;
//}