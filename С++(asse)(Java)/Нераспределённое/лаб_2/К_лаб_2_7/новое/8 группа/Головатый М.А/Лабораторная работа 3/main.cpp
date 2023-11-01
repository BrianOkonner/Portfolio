#include "ArrayStack.h"
#include "Header.h"
#include "List.h"
#include "StudContainer.h"
#include "ArrayQueue.h"
#include "Deque.h"

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Choose:\n";
	cout << "1.ArrayStack\n2.List\n3.StudContainer\n4.ArrayQueue\n5.DeQueue\n";
	int choose,n=10,&k=n; ArrayStack a(n); List b; ArrayQueue c(10);
	cin >> choose;
	switch (choose)	
	{
	case 1: goto ArrayStack;
	case 2: goto List;
	case 3: goto StudContainer;
	case 4: goto ArrayQueue;
	case 5: goto Deque;
	default:
		break;
	}
	//--------------ArrayStack---------------
	ArrayStack:
	cout << "\n------------Stack----------\n";
	for (int i = 0; i < n; i++)
		a.push(i);
	for (int i = 0; i < n; i++)
		cout << a.pop();
	system("pause");
	return 0;
	//-----------------list------------------
	List:
	cout << "\n------------List----------\n";
	
	for (int i = n; i >= 1; i--)
		b.ins(i);
	b.print();
	b.invert();
	b.remove_head();
	b.print();
	cout << "\nmin: " << b.smin()<<"\n";
	system("pause");
	return 0;
	//-------------StudContainer-------------
	StudContainer:
	StudContainerFunc();
	system("pause");
	return 0;

	//---------------ArrayQueue--------------

	ArrayQueue:
	cout << "\n---------ArrayQueue-------\n";
	for (int i = 0; i < 10; i++)
		c.push(i);
	c.printQueue(cout);
	c.del();
	cout <<"Ïóñòî?="<< c.isEmpty();
	cout << " Íå ïóñòî?="<< c.isFool()<<"\n";
	c.printQueue(cout);
	system("pause");
	return 0;
	//-----------------DeQueue---------------
	Deque:
	cout << "\n----------DeQueue---------\n";
	Deque d;
	for (int i = 1; i < 10; i++)
	{
		d.insTail(i);
	}
	d.insTail(2);
	d.insÍead(21);
	d.delTail();
	d.print(cout);
	system("pause");
	return 0;
}