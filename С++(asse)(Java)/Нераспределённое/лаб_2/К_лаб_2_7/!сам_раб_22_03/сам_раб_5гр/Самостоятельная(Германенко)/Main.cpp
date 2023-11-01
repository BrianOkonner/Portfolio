/*Германенко Артём 
Условие: 4. В файле input.txt задан набор целых чисел.
            Записать их в память используя свой стек_массив.  
            Просматривая по парам, удалить один из них, если они одинаковые.
			Pезультат записать в стандартный список и вывести в файл Output.txt*/

#include<iostream>
#include"Header.h"
#include<List>
#include<fstream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	list <int> C;
	my_stack A,B;
	ofstream out;
	ifstream in;
	int max, tmp, a, b;

	in.open("Input.txt");
	out.open("Output.txt");
	cout << "Стек до изменения: ";
	while (!in.eof())
	{
	    in >> tmp;
		A.push(tmp);
		cout << tmp << " ";
	}
	
	a = A.top();
	A.pop();
	b = A.top();
	A.pop();
	B.push(a);

	cout << endl << "Стек после изменения: ";

    while (!A.empty())
	{
		if (a != b)
			B.push(b);
		a = b;
		b = A.top();
		A.pop();
	}
	while (!B.empty())
	{
		tmp=B.top();
		B.pop();
		C.push_front(tmp);
		cout << tmp << " ";
	}
	out << "Элементы в стандартном списке: ";
	cout << endl << "Элементы в стандартном списке: ";
	while (!C.empty())
	{
		tmp = C.back();
		C.pop_back();
		out << tmp << " ";
		cout << tmp << " ";
    }
	cout << endl;
	in.close();
	out.close();
	system("pause");
}