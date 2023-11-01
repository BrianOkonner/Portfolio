/* Казанцев Павел
	1 курс	8 группа
	класс StudContainer
________________________________________________________________________
__________________________ПОЛЕЗНАЯ ИНФОРМАЦИЯ___________________________
 Данные в файле  записаны в формате:  Имя Группа Балл 
 !!ПОСТАВИТЬ ШРИФТ КОНСОЛИ Lucida Console !!
________________________________________________________________________
					Коды ошибок

1 - Контейнер переполненен. Невозможно добавить новый элемент
2 - Контейнер пуст. Невозможно удалить элемент
3 - .FindByName Такого студента нет в контейнере
4 - Ошибка выбора в меню


*/

/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <algorithm>
#include <locale.h>
#include <windows.h>
#include <iomanip>
using namespace std;
*/
#include "StudContainer.h"

int main() {

	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);					// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);
	try {
		ifstream in("Input.txt");
		char *Buff = new char[10];
		const char R[] = "!:; ";
		in.getline(Buff, 81);
		char *b = strtok(Buff, R);
		int current_group = atoi(b);
		delete[]Buff;
		StudContainer Stud(current_group);
		int count = 0;
		while (!in.eof()) {
			char Buff[81]; Buff[0] = '\0';
			Student s;
			in.getline(Buff, 81);
			char *b = strtok(Buff, R);
			strcpy(s.name, b);
			b = strtok(NULL, R);
			s.group = atoi(b);
			b = strtok(NULL, R);
			s.grade = (double)atof(b);
			Stud.Insert(s);
			count++;
		}
		in.close();
		do {
			cout << "0 - Выход" << endl;
			cout << "1 - Информация обо всех студентах" << endl;
			cout << "2 - Список студентов в алфавитном порядке" << endl;
			cout << "3 - Список студентов по группам" << endl;
			cout << "4 - Поиск информации о студенте" << endl;
			cout << "5 - Добавить информацию о студенте в контейнер" << endl;
			cout << "6 - Удалить информацию о студенте из контейнера" << endl;
			cout << "7 - Средний балл по каждой группе" << endl;
			switch (_getch() - '0') {
			case 1: {
				system("cls");
				Print_to_console(Stud);
				break;
			}
			case 2: {
				system("cls");
				Print_sorted_by_name(Stud);
				break;
			}
			case 3: {
				system("cls");
				Print_sorted_by_name_and_group(Stud);
				break;
			}
			case 4: {
				system("cls");
				Find_student(Stud);
				break;
			}
			case 5: {
				system ("cls");
				Add_student_info(Stud);
				break;
			}
			case 6: {
				system("cls");
				Delete_student_info(Stud);
				break;
			}
			case 7:{
				system("cls");
				Stud.Average_grade_in_group();
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
		cout << "Исключение\n";
		cout << "Номер ошибки - " << y << endl;
	}
	return 0;
}

