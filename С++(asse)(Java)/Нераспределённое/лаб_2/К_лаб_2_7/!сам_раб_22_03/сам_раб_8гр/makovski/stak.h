// Маковский Владислав 8 группа
#pragma once
class Stack
{
private:
	int *stackPtr;                      // указатель на стек
	const int size;                   // максимальное количество элементов в стеке
	int top;                          // номер текущего элемента стека
public:
	Stack(int = 100);
	~Stack();                         // деструктор

	void push(const int &a);     // поместить элемент в вершину стека
	int Top();        // получить элемент и удалить его
	void pop();
	bool Empty();
};

