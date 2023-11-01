/*Условие:1.Разработать адаптер контейнера stack на основе очереди deque. Разработать функции добавления, печати, вычисления суммы элементов стека.
		Написать тестовую программу для типов int, double, char.
		3. Разработать адаптер контейнера stack на основе  списка list. Разработать функции добавления, печати, вычисления произведения элементов стека.
		Написать тестовую программу для типов int, double, char.*/
#include <deque>
#include <list>
#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;
template <class t>
class Dstack
{
	deque <t> ld;
public:
	Dstack(){}
	void push(t f){ld.push_back(f);}
	void pop(){ld.pop_front();}
	t front(){return(ld.front());}
	bool empty(){return ld.empty();}
	void print(ostream& out)
	{
		while(!empty())
		{
			out<<front()<<" ";
			pop();
		}
	}
	t sum()
	{
		t sum;
		sum=front();
		pop();
		while(!empty())
		{
			sum+=front();
			pop();
		}
	return sum;
	}
};
template <> char* Dstack<char*>::sum()
{
	char *sum;
	int s=0;
	for (int i=0;i<ld.size();i++)
	{
		s+=strlen(ld[i]);
	}
	s+=ld.size();
	sum=new char[s];
	for (int i=0;i<ld.size();i++)
	{
		strcat(sum, " ");
		strcat(sum, ld[i]);
	}
	return sum;
}
int main()
{
	ofstream out("Output.txt");
	Dstack<int> ds;
	Dstack<char*> ds1;
	Dstack<double> ds2;
	ds.push(5);
	ds2.push(5.92);
	ds1.push("Hello");
	ds.push(8);
	ds2.push(1.03);
	ds1.push("Bye");
	int s=ds.sum();
	char *s1=ds1.sum();
	double s2=ds2.sum();
	out<<s<<"  "<<s1<<"  "<<s2<<"  ";
	ds.print(out);
	ds1.print(out);
	ds2.print(out);
}