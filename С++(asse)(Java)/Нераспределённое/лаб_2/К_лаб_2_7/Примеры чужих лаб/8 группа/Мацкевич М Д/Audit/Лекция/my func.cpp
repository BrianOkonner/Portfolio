#include "Stack.h"

Stack::Link::Link(void* data, Link* next)      //����������� ��� link
{
	this->data = data;
	this->next = next;
}

Stack::Link:: ~Link() {}              //���������� ��� link

Stack::Stack()                        //����������� ��� Stack
{
	head = 0;
}

bool Stack::isEmpty()                          
{
	return !head;
}

void* Stack::Top()
{
	if (!isEmpty())               // ���� ���� �� ������ �� ���������� �������� �������� �����
		return head->data;
	return 0;
}

void Stack::Push(void* dat)
{
	head = new Link(dat, head);    
}
void Stack::Pop()
{
	if (!isEmpty())
	{
		Link* tmp = head;    //��������� ������ ��� ��������
		if (head->next)
			head = head->next;     //  ������ ������
		else head = 0;       
		delete tmp;         //������� �������
	}
}

Stack::~Stack()                     // ���������� ��� Stack
{
	while (!isEmpty())
		Pop();
}
