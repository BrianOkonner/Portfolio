#include <iostream>
#include <fstream>
#include <list>
/*
Андреев Дмитрий 8 группа

Задача Иосифа:  Вокруг считающего стоит N человек, из которых выделен первый, а  остальные  занумерованы  по  часовой стрелке
числами от 2 до N. Считающий, начиная с кого-то, ведет счет до M. Человек, на котором остановился счет, выходит из круга. Счет
продолжается со следующего человека и так до тех пор, пока не останется один человек.  Определить номер оставшегося человека,
если известно M и то, что счет начинался с первого человека. Результат записать в текстовый  файл.
*/

using namespace std;

void main(){

	setlocale(0, "rus");

	ofstream out;
	out.open("output.txt");

	int n, m, i, j, el;

	cout << "Kоличество: ";
	cin >> n;
	out << "Kоличество: " << n << endl;
	cout << "Шаг: ";
	cin	>> m;
	out << "Шаг: " << m << endl;

	if (m == 1){	//иначе сбивается при m=1;
		cout << "Останется элемент "<< n << endl;
		out << "Останется элемент " << n;
	}

	else {

		list <int> lists;
		for (i = 1; i <= n; i++) lists.push_front(i);


		for (i = 1; i < n; i++) {

			for (j = 1; j < m; j++) {
				el = lists.back();
				lists.pop_back();
				lists.push_front(el);
			}
			lists.pop_back();
		}

		cout << "Останется номер " << lists.front() << endl << "*сохранено в output.txt"<< endl;
		out << "Останется номер " << lists.front();
	}
	out.close();
	system("pause");
}