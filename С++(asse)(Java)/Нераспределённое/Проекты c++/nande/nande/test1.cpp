#include "iostream"
#include "ArrayStack.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	ArrayStack o(8),m(o);
	if(o.isEmpty())
	o.push(8);
	if (o.isFull())
	o.push(8);
	if (o.isEmpty())
	o.push(9);
	o.push(11);
	o.push(11);
	o.push(11);
	o.push(11);
	o.push(11);
	o.push(11);
	o.push(12);
	if (!o.isFull())
		o.push(8);
	o.pop();
	if (!o.isFull())
		o.push(8);
	ArrayStack q(o);
	cout<<"Первый стек: ";
	while(!o.isEmpty())
		cout<<o.pop()<<" ";
	cout<<endl<<"Второй стек(скопированный): ";
	while(!q.isEmpty())
		cout<<q.pop()<<" ";
	return 0;
}
