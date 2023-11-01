/*
Андреев Дмитрий 8 группа

Задача 3_3
Студенты

1.	Отсортировать массив по фамилиям студентов. Вывести отсортированный массив на консоль;
2.	Найти в массиве запись о студенте по его фамилии. Фамилия студента вводится с консоли, результат поиска также вывести на консоль.
3.	Отсортировать массив по группам, а внутри одной группы по фамилиям студентов. Вывести отсортированный массив на консоль.
4.	Вывести на консоль отчет о среднем бале студентов в каждой группе.

*/

#include "StudContainer.h"

int main()
{
	setlocale(0, "rus");
	ifstream in("Input.txt");
	
	int n;
	in >> n;

	Student st;

	StudContainer StudC(n);

	for (int i = 0; i < n; i++)
	{
		in >> st.name >> st.num >> st.grade;
		StudC.insert(st);
	}

	int enter;
	do
	{
		cout << "1. Сортировка (имя)\n";
		cout << "2. Поиск\n";
		cout << "3. Сортировка (группы и имена)\n";
		cout << "4. Средний балл\n";
		cout << "5. Выход\n";

		cin >> enter;
		int Name_Len = 100;
		char* name = new char[Name_Len];
		Student* stud;
		switch (enter)
		{
		case 1:
			system("cls");
			StudC.sortByName();
			StudC.print(cout);
			break;
		case 2:
			cout << "Поиск работает только с именами, \nзаписанными латинскими буквами \nИмя: \n";
			cin >> name;
			stud = StudC.findByName(name);
			if (stud)
				cout << (*stud).name << " " << (*stud).num << " " << (*stud).grade << endl;
			else
				cout << "Не найдено\n";
			break;
		case 3:
			StudC.sortByGroupAndName();
			StudC.print(cout);
			break;
		case 4:
			StudC.report(cout);
			break;
		default:
			break;
		}
	} while (enter != 5);


	return 0;
}