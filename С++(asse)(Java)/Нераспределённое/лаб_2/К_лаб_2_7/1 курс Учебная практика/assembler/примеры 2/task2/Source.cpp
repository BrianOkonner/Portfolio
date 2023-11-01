/*
Евгений Поздняков ПМ 8, 1 курс
8.	Вычислить   S=sum from (n-1) to m ((1+ArcTanhx)/(1+n^3))*cos2nx при заданном m,если  х изменяется от a до b с шагом h. Результаты получить в виде таблицы.

Test________________________________________
Input----------------------------------------
| X0= -0.99| X1=  0.99| m= 15| spacing=  0.1
Output---------------------------------------
|      x      | my function  | std. function|
--------------------------------------------
| -0.99       |  -1.93394    |  -1.93394    |
| -0.89       | -0.515683    | -0.515683    |
| -0.79       |-0.0909243    |-0.0909244    |
| -0.69       |  0.102315    |  0.102315    |
| -0.59       |  0.360651    |  0.360651    |
| -0.49       |  0.119149    |  0.119149    |
| -0.39       |   0.74964    |   0.74964    |
| -0.29       |  0.306383    |  0.306383    |
| -0.19       |  0.758852    |  0.758852    |
| -0.09       |  0.630283    |  0.630283    |
|  0.01       |  0.691763    |  0.691763    |
|  0.11       |  0.888234    |  0.888234    |
|  0.21       |  0.710299    |  0.710299    |
|  0.31       |  0.855758    |  0.855758    |
|  0.41       |   3.98811    |   3.98811    |
|  0.51       |  0.360677    |  0.360677    |
|  0.61       |  0.858761    |  0.858761    |
|  0.71       |   1.19596    |   1.19596    |
|  0.81       |    2.3265    |    2.3265    |
|  0.91       |   2.95906    |   2.95906    |
--------------------------------------------
total runtime = 25.941 sec
runtime of the code = 0.141 sec
Проверяю введенные углы и границы промежтка, чтобы они подходили под ограничение AtanH.Создаю функции косинуса и арктангенса, которые считаются через ряд Тейлора. Передаю их в ф-цию Sum,
которая функция считает сумму из m элеметнов для одного X. 
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

#include "MyFunctions.h"
using namespace std;

int main()

{

	double x0=0, x1=0, spacing=0;
	int m=0;
	char numoperation;
	cout << "Type F to read from file or K to read from keyboard" << endl; //чтение либо с клавиатуры, либо из файла
	cin >> numoperation;
	switch (numoperation)
	{
	case 'F':
	{
		ifstream file("Input.txt", ios::binary);
		if (!file)	//если файл отсутствует, переход к вводу с клавиатуры
			cout << "Can't open Input.txt you'll be forwarded to keyboard input\r\n";
		else
		{
			ifstream fin;
			fin.open("Input.TXT");
			fin >> x0 >> x1 >> m >> spacing;
			cout << "The bottom margin: " << x0 << endl;
			if ((x0 >= 1) || (x0 <= -1) ||(x1>=1) ||(x1<=-1)) //проверка границ (-1;1) 
			{
				cout << "Error! Margins should be from -1 to 1. Please correct data and relaunch the programm \n";
				system("pause");
				return 0;
			}
			cout << "The top margin: " << x1 << endl;
			cout << "The number of elements of sum (m): " << m << endl;
			cout << "The spacing: " << spacing << endl;
			
			break;
		}
		
			
	}
	case 'K':
	{
		cout << "Enter the bottom margin: \n";
		cin >> x0;
		if ((x0 >= 1) || (x0 <= -1)) //пока число не входит в границы, выдается сообщение об ошибке и запрос на повторный ввод
			do
			{
			cout << "Error! Enter the bottom margin from -1 to 1 \n";
			cin >> x0;
			} while ((x0 >= 1) || (x0 <= -1));

		cout << "Enter the top margin: ";
		cin >> x1;
		if ((x1 >= 1) || (x1 <= -1)) //пока число не входит в границы, выдается сообщение об ошибке и запрос на повторный ввод
			do
			{
			cout << "Error! Enter the top margin from -1 to 1 \n";
			cin >> x1;
			} while ((x1 >= 1) || (x1 <= -1));

		cout << "Enter the number of elements of sum (m): \n";
		cin >> m;
		if (m<0) //пока число не входит в границы, выдается сообщение об ошибке и запрос на повторный ввод
			do
			{
			cout << "Error! The number of elements of sum shoud be >0 \n";
			cin >> m;
			} while (m<0);

		cout << "Enter the spacing \n";
		cin >> spacing;
		
	}
	}
	
	unsigned int start_time = clock();// Запуск счетчика времени для определения времени выполнения кода
	output(x0, x1, m, spacing);
	
	unsigned int end_time = clock(); // Конечное время
	unsigned int search_time = end_time - start_time; //Нахождение времени работы кода
	cout << "total runtime = " << clock() / 1000.0<<" sec"<< endl; //Полное время выполнения программы
	cout << "runtime of the code = " << search_time / 1000.0 << " sec" << endl; //Время выполнения ф-ции кода без учета времени, затраченного на ввод данных
	system("pause");
}
