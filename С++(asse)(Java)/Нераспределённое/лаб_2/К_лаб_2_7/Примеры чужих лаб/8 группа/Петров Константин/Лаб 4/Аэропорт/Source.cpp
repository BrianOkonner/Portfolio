/*
	Петров Константин
		8 группа
	Лаб 4 - Класс Аэропорт
*/

#include"Airport.h"

int main(void) {
	setlocale(LC_ALL, "rus");
	Airport Data;
	do {
		system("cls");
		cout << "1 - Выбрать самолет" << endl;
		cout << "2 - Получить полную информацию об отдельном рейсе" << endl;
		cout << "0 - Выход" << endl;
		switch (_getch() - '0') {
		case 1: {
			system("cls"); 
			Func1(Data);
			break;
		}
		case 2: {
			system("cls");
			Func2(Data);
			break;
		}

		case 0: {
			system("cls");
			cout << "Программа завершена" << endl;
			return 0;
		}
		default: {
			system("cls");
			break;
		}
		}
	} while (true);

	return 0;
}