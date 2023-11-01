//Заневская Яна 8 группа постфикснкая запись




#include <iostream>
#include <fstream>
#include <stack>
#include <clocale>

using namespace std;
class Stack
{
	struct Link
	{
		void* data;
		Link* next;
		Link(void*, Link*);
		~Link();
	} *head;
public:
	Stack();
	~Stack();
	void Push(void*);
	void* Top();//Peek
	bool isEmpty();
	void Pop();
};


Stack::Link::Link(void* data, Link* next)
{
	this->data = data;
	this->next = next;
}

Stack::Link:: ~Link() {}

Stack::Stack()
{
	head = NULL;
}

bool Stack::isEmpty()
{
	return !head;
}

void* Stack::Top()
{
	if (!isEmpty())
		return head->data;
	return NULL;
}

void Stack::Push(void* dat)
{
	head = new Link(dat, head);
}
void Stack::Pop()
{
	if (!isEmpty())
	{
		Link* tmp = head;
		if (head->next)
			head = head->next;
		else head = NULL;
		delete tmp;
	}
}

Stack::~Stack()
{
	while (!isEmpty())
		Pop();
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int i = 0, k = 0;
	char a[100], b[100] = "", c = 'a';
	Stack s;
	ifstream fin("input.txt");
	fin.getline(a, 100);
	s.Push(&c);
	while (i != strlen(a))
	{
		if (isdigit(a[i]))
		{
			b[k] = a[i];
			k++;
		}
		else
			if (a[i] == '(')
				s.Push(&a[i]);
			else
				if (a[i] == '+' || a[i] == '-')
				{
					while (*(char*)s.Top() == '+' || *(char*)s.Top() == '-' || *(char*)s.Top() == '*' || *(char*)s.Top() == '/')
					{
						b[k] = *(char*)s.Top();
						s.Pop();
						k++;
					}
					if (*(char*)s.Top() == '(' || *(char*)s.Top() == c)
						s.Push(&a[i]);
				}



				else
					if (a[i] == '*' || a[i] == '/')
					{
						while (*(char*)s.Top() == '*' || *(char*)s.Top() == '/')
						{
							b[k] = *(char*)s.Top();
							k++;
							s.Pop();
						}
						if (*(char*)s.Top() == '+' || *(char*)s.Top() == '-' || *(char*)s.Top() == '(' || *(char*)s.Top() == c)
							s.Push(&a[i]);
					}



					else
						if (a[i] == ')')
						{
							while (*(char*)s.Top() == '+' || *(char*)s.Top() == '-' || *(char*)s.Top() == '*' || *(char*)s.Top() == '/')
							{
								b[k] = *(char*)s.Top();
								k++;
								s.Pop();
							}
							if (*(char*)s.Top() == '(')
								s.Pop();
						}










		i++;
	}
	ofstream fout("output.txt");
	fout << b;




	system("pause");
}