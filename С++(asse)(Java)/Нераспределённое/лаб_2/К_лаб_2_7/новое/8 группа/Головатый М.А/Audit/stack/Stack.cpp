#include <iostream>
#include "Stack.h"
using namespace std;


Stack::Link::Link(void* data, Link* next) // конструктор для структуры, который заполняет ее поля
{
	this->data = data; // указатель на рассматриваемый элемент структуры
	this->next = next;
}

Stack::Link:: ~Link() {} // пустой деструктор

Stack::Stack() // конструктор по умолчанию
{
	head = NULL; // создаст нулевой элемент списка
}

bool Stack::isEmpty() 
{
	return !head;
}

void* Stack::Top()
{
	if (!isEmpty()) // если стек не пустой возвращаем верхний элемент
		return head->data;
	return NULL;
}

void Stack::Push(void* dat)
{
	head = new Link(dat, head); // выделит память под элемент класса Link, для которого вызывается конструктор
}
void Stack::Pop()
{
	if (!isEmpty()) // освобождать можно только если есть элементы в списке
	{
		Link* tmp = head; // освобождаем указатель на head
		if (head->next)
			head = head->next;
		else head = NULL;
		delete tmp; // удаляем указатель на старый элемент
	}
}

Stack::~Stack()
{
	while (!isEmpty()!=0) // удаляем элементы пока не 
		Pop();
}





