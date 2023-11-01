/*
		Петров Констнатин
			8 группа
			Класс 3

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ВАЖНО~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Данные в файле должны быть записаны в формате Имя Группа Балл 
 Имена на английском
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					Код ошибки

1 - Контейнер переполненен. Невозможно добавить новый элемент
2 - Контейнер пуст. Невозможно удалить элемент
3 - .FindByName Такого студента нет в контейнере
4 - Ошибка выбора в меню


*/

#include "Header.h"

int main() {
	try {
		ifstream fin("Input.txt");
		char *Buff = new char[10];
		const char R[] = "!:; ";
		fin.getline(Buff, 81);
		char *b = strtok(Buff, R);
		int num = atoi(b);
		delete[]Buff;

		StudContainer Stud(num);
		int count = 0;
		while (!fin.eof()) {
			char Buff[81]; Buff[0] = '\0';
			Student s;
			fin.getline(Buff, 81);
			char *b = strtok(Buff, R);
			strcpy(s.name, b);
			b = strtok(NULL, R);
			s.num = atoi(b);
			b = strtok(NULL, R);
			s.grade = (double)atof(b);
			Stud.Insert(s);
			count++;
		}
		fin.close();
		do {
			cout << "0 - Exit." << endl;
			cout << "1 - Display student's average grade in each group." << endl;
			cout << "2 - Sort by name & display." << endl;
			cout << "3 - Sort by name & group number. Display." << endl;
			cout << "4 - Find student & display." << endl;
			cout << "5 - Add student." << endl;
			cout << "6 - Delete student's info." << endl;
			switch (_getch() - '0') {
			case 1: {
				system("cls");
				Func1(Stud);
				break;
			}
			case 2: {
				system("cls");
				Func2(Stud);
				break;
			}
			case 3: {
				system("cls");
				Func3(Stud);
				break;
			}
			case 4: {
				system("cls");
				Func4(Stud);
				break;
			}
			case 5: {
				system ("cls");
				Func5(Stud);
				break;
			}
			case 6: {
				system("cls");
				Func6(Stud);
				break;
			}
			case 0: {
				system("cls");
				cout << " " << endl;
				return 0;
			}
			default: {
				system("cls");
				throw 4;
			}
			}

		} while (true);
	}
	catch (int y) {
		cout << "Exception\n";
		cout << "Code - " << y << endl;
	}
	return 0;
}
