#include "Stack.h"

Stack::Link::Link(void* data, Link* next)      //Конструктор для link
{
	this->data = data;
	this->next = next;
}

Stack::Link:: ~Link() {}              //Деструктор для link

Stack::Stack()                        //Конструктор для Stack
{
	head = 0;
}

bool Stack::isEmpty()                          
{
	return !head;
}

void* Stack::Top()
{
	if (!isEmpty())               // Если стек не пустой то возвращаем значение верхушки стека
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
		Link* tmp = head;    //сохраняем голову для удаления
		if (head->next)
			head = head->next;     //  Меняем голову
		else head = 0;       
		delete tmp;         //Удаляем элемент
	}
}

Stack::~Stack()                     // Деструктор для Stack
{
	while (!isEmpty())
		Pop();
}
