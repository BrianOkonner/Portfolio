/*  Казанцев Павел Сергеевич
	1 курс 8 группа
	Стек на массиве

	Код ошибки
1 - Размер массива < 0
2 - Массив полный. Невозможно добавить элемент
3 - Стек пуст
4 - Ошибка выбора


*/

#include "Stack.h"

int main() {
	setlocale(LC_ALL, "rus");
	int choice = 0;
	do {
		cout << "Выберите задачу: " << endl << endl;
		cout << "1 - Соседи " << endl;
		cout << "2 - Лист бумаги" << endl;
		cout << "3 - Дорога" << endl;
		cout << "0 - Выход" << endl;
		choice = _getch() - '0';
		switch (choice) {
			case 1: {
				Neighbors();
				break;
			}
			case 2: {
				Paper();
				break;
			}
			case 3: {
				Road();
				break;
			}
			case 0: {
				system("cls");
				cout << "Программа завершена" << endl;
				return 0;
			}
			default:{
				system("cls");
				throw 4;
			}

		}
	} while (true);
	return 0;
}




