/*
8 группа, 1 курс
Севрюкова Л.

1.	Использование (динамического) стека.
Задано выражение (инфиксная форма, например (5+45)*(55-5).... )содержащее числа (любого типа),
знаки операций, круглые скобки.
Записать его в виде обратной польской записи (постфиксная форма) и вычислить его значение.

тесты:

Исходное выражение:

(5+45)*(55-5)

Постфиксная запись:

5 45 + 55 5 - *

Результат:

2500



*/
/*
8 группа, 1 курс
Севрюкова Л.

1.	Использование (динамического) стека.
Задано выражение (инфиксная форма, например (5+45)*(55-5).... )содержащее числа (любого типа),
знаки операций, круглые скобки.
Записать его в виде обратной польской записи (постфиксная форма) и вычислить его значение.

тесты:

Исходное выражение:

(5+45)*(55-5)

Постфиксная запись:

5 45 + 55 5 - *

Результат:

2500



*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include "Stack.h"
using namespace std;


bool chislo(char* sl)
{
	char *er;
	strtol(sl, &er, 0);
	if (*er == 0)
		return true;
	else
		return false;
}



int main()
{
	setlocale(LC_ALL, "rus");
	ifstream in;
	in.open("Input.txt");
	if (!in.is_open())cout << "File is not found";
	cout << " Исходное выражение: " << "\n\n";
	char str[100];
	in >> str;
	cout << str << endl;
	in.close();

	Stack s;

	char *res = new char[strlen(str)];
	res[0] = '\0';

	int  n;
	for (int i = 0, j = 0; i <= (int)strlen(str); i++)
		if (str[i] >= '0' && str[i] <= '9')
		{
			res[j] = str[i];
			j++;
		}
		else
		{
			if (res[j - 1] != ' ')
			{
				res[j] = ' '; j++;
			}

			if (s.isEmpty()) s.Push(str[i]);
			else

				switch (str[i])
				{
				case '(':

					s.Push(str[i]); break;

				case ')':
					while (s.Peek() != '(')
					{
						res[j] = s.Peek();
						s.Pop();
						j++;
						res[j] = ' '; j++;
					}
					s.Pop();
					break;


				case '+':
				case '-':
					while (!s.isEmpty())
					{
						if (s.Peek() == '-' || s.Peek() == '*' || s.Peek() == '/' || s.Peek() == '+')
						{
							res[j] = s.Peek();  s.Pop(); j++;
							res[j] = ' '; j++;
						}

						else break;
					}

					s.Push(str[i]);
					break;

				case '*':
				case '/':

					while (!s.isEmpty())
					{
						char a = s.Peek();
						if (a == '*' || a == '/')
						{
							res[j] = a;  s.Pop(); j++;
							res[j] = ' '; j++;
						}
						else break;
					}

					s.Push(str[i]);
					break;

				default: break;
				}
			n = j;
		}

	while (!s.isEmpty())
	{
		res[n] = s.Peek();  s.Pop();
		n++;
		res[n] = ' '; n++;
	}

	res[n] = '\0';

	cout << "\n Постфиксная запись: \n";
	cout << "\n" << res << "\n\n";


	StackInt s2;
	n = 0;
	char *er;
	char *sl = strtok(res, " ");

	while (sl)
	{
		if (chislo(sl))
		{
			n = strtol(sl, &er, 0);
			s2.Push(n);
		}

		else
		{
			switch (sl[0])
			{

			case '+':

				n = s2.Peek(); s2.Pop();
				n += s2.Peek(); s2.Pop();
				s2.Push(n);

				break;
			case '-':
				n = s2.Peek()*(-1); s2.Pop();
				n += s2.Peek(); s2.Pop();
				s2.Push(n);
				break;
			case '*':
				n = s2.Peek(); s2.Pop();
				n *= s2.Peek(); s2.Pop();
				s2.Push(n);

				break;
			case '/':
				int c = s2.Peek(); s2.Pop();
				n = s2.Peek() / c; s2.Pop();
				s2.Push(n);

				break;
			}

		}

		sl = strtok(0, " ");
	}

	cout << " Результат:\n\n" << s2.Peek() << "\n\n";

	system("pause");
	return 0;
}

