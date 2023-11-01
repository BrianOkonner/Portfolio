#include "header.h"

void menu()
{
	int flag; char f;
L1:
	system("cls");
	cout << "Введите номер пункта меню:\n";
	cout << "1. Вычисление выражения в инфиксной форме записи \n";
	cout << "2. Описать процедуру, которая подсчитывает количество элементов стека, у которых равные \"соседи\".  \n";
	cout << "3. Палиндромы и очереди. \n";
	cout << "4. Задача Иосифа Флавия.\n";
	cout << "5. Выйти.\n";
	cin >> flag;
	switch (flag)
	{
	case 1:
case1:
		system("cls");
		cout << setw(5) << " ***********Вычисление выражения в инфиксной форме записи*********** \n";
		cout << "1. Выполнить программу\n2. Просмотреть условие\n";
		cin >> flag;
		switch (flag)
		{
		case 1:
			char str_infix[100]; 	char str_postfix[MAX_LEN];
			system("cls");
			cout << setw(5) << " ***********Вычисление выражения в инфиксной форме записи*********** \n";
			cout << "Введите ваше инфиксное выражение:";
			cin>>str_infix;
			PostfixNotation(str_infix, str_postfix);
			cout <<"Выражение в постфиксной форме: "<< str_postfix << endl;
			cout << "Результат вычисления: " << calculation(str_postfix, str_infix) << endl;
			cout << "Решить другую задачу? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; }
		case 2:
			condition1();
			cout << "\nВернуться назад? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto case1; }
			else { break; }
		default:
			system("cls");
			cout << "Вы выбрали неверный вариант. " << endl;
			cout << "Попробовать снова? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; };
			exit(EXIT_FAILURE);
		}


		break;
	case 2:
		system("cls");
		cout << setw(5) << " ***********Описать процедуру, которая подсчитывает количество элементов стека, у которых равные \"соседи\"*********** \n";
		cout << "1. Выполнить программу\n";
		cin >> flag;
		switch (flag)
		{
		case 1:
			int n, number; char str_infix[100]; 	char str_postfix[MAX_LEN];
			system("cls");
			cout << setw(5) << " ***********Описать процедуру, которая подсчитывает количество элементов стека, у которых равные \"соседи\"*********** \n";
			cout << "Исходная последовательность находится в файле input.txt. Колиество элементов с равными соседями: ";
			sosedi();
			
			cout << "Решить другую задачу? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; }
		default:
			system("cls");
			cout << "Вы выбрали неверный вариант. " << endl;
			cout << "Попробовать снова? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; };
			exit(EXIT_FAILURE);
		}
		break;
	case 3:
		system("cls");
		cout << setw(5) << " ***********Палиндромы и очереди*********** \n";
		cout << "1. Выполнить программу\n";
		cin >> flag;
		switch (flag)
		{
		case 1:
			int n, number; char str_infix[100]; 	char str_postfix[MAX_LEN];
			system("cls");
			cout << setw(5) << " ***********Палиндромы и очереди*********** \n";
			cout << "Исходная последовательность находится в файле input.txt. ";
			queue_func();

			cout << "Решить другую задачу? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; }
		default:
			system("cls");
			cout << "Вы выбрали неверный вариант. " << endl;
			cout << "Попробовать снова? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; };
			exit(EXIT_FAILURE);
		}
		break;
	case 4:
case4:
		system("cls");
		cout << setw(5) << " ***********Задача Иосифа Флавия*********** \n";
		cout << "1. Выполнить программу\n2. Просмотреть условие\n";
		cin >> flag;
		switch (flag)
		{
		case 1:
			int n, number;
			system("cls");
			cout << setw(5) << " ***********Задача Иосифа Флавия*********** \n";
			cout << "Введите количество человек: "; cin >> n; cout << "Введите номер выбывающего: "; cin >> number;

			Josef(n, number);
			
			cout << "Решить другую задачу? Y/N";
			cin >> f; if (f == 'y'||f=='Y') { goto L1; }
			else { break; }
		case 2:
			condition();
			cout << "Вернуться назад? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto case4; }
			else { break; }
		default:
			system("cls"); 
			cout << "Вы выбрали неверный вариант. " << endl;
			cout << "Попробовать снова? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; };
			exit(EXIT_FAILURE);
		}

		break;
	case 5:
		break;
	default:
		system("cls");
		cout << "Вы выбрали неверный вариант. " << endl;
		cout << "Попробовать снова? Y/N";
		cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
		else { break; };
		exit(EXIT_FAILURE);
	}
}

