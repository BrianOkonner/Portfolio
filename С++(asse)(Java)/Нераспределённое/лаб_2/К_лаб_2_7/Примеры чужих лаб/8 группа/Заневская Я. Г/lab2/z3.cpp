//задача иосифа Заневская Яна
#include <iostream>
#include <list>

class List
{
	class item
	{
	public:
		int number;
		item *next;
		item *prev;
		item(int, item*, item*);
		~item();
	}*head, *tail;
public:
	List();
	~List();
	bool empty();
	void push_back(int);
	void pop_front();
	int front();
};
List::item::item(int numb, item * next, item * prev)
{
	this->number = numb;
	this->next = next;
	this->prev = prev;
}

List::item::~item() {}

List::List()
{
	this->head = NULL;
	this->tail = NULL;
}

bool List::empty()
{
	return !head;
}

void List::push_back(int numb)
{
	item *temp = new item(numb, NULL, NULL);
	if (this->head == NULL)
	{
		this->head = temp;
		this->tail = temp;
	}
	else
	{
		this->tail->next = temp;
		this->tail = temp;
	}
}


void List::pop_front()
{
	if (!empty())
	{
		item *temp = this->head;
		if (this->head->next)
			this->head = this->head->next;
		else
			this->head = NULL;
		delete temp;
	}
}

int List::front()
{
	if (!empty())
		return this->head->number;
	return NULL;
}


List::~List()
{
	while (!empty())
		pop_front();
}

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	int n, k, l;
	cout << "кол-во людей: ";
	cin >> n;
	cout << "номер выбывающего: ";
	cin >> k;
	List mylist;
	for (int i = 1; i <= n; i++)
		mylist.push_back(i);

	while (n != 1)
	{
		for (int i = 1; i < k; i++)
		{
			l = mylist.front();
			mylist.push_back(l);
			mylist.pop_front();
		}
		mylist.pop_front();
		n--;
	}
	cout << "Останется человек: " << mylist.front() << endl;
	system("pause");
}