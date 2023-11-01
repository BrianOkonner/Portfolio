/*		Петров Констнатин
8 группа

Реализация класса 4 + доп. задачи

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Код ошибки

1 - Неположительная длина очереди
2 - Очередь переполнена
3 - Очередь пустая
4 - Неверный выбор
5 - Ошибка входных данных
*/


#include "Header.h"



int main() {
	setlocale(LC_ALL, "rus");
	int size, choice = 0;
	try {
		do {
			cout << "Выберите задачу :" << endl;
			cout << "1. Задача про Иосифа Флавия" << endl;
			cout << "2. Лист бумаги" << endl;
			cout << "3. Дорога" << endl;
			cout << "0 - выход" << endl;
			choice = _getch() - '0';
			system("cls");
			switch (choice) {
			case 0: {
				cout << "Программа завершена" << endl << endl;
				return 0;
			}
			case 1: {
				Flavii();
				break;
			}
			case 2: {
				PaperSheet();
				break;
			}
			case 3: {
				Road();
				break;
			}
			default: {
				system("cls");
				throw 4;
			}
			}
		} while (true);
	}
	catch (int a) {
		cout << "Что-то пошло не так....\n";
		cout << "Номер ошибки - " << a << endl << endl;
	}

	system("pause");
	return 0;
}

