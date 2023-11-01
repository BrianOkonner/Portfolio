#pragma once
class ArrayStack		/* стек на массиве */
{
	int  size;	/* размерность массива */
	int** p;  	/* указатель на массив */
	int  top;	/* верхушка стека */
public:
	ArrayStack(const int& _size);     /* конструктор */
	ArrayStack(const ArrayStack& s);  // конструктор копирования
	~ArrayStack();	          /* деструктор */
	void push(const int& n1, const int& n2);  /* втолкнуть элемент в стек */
	void pop();/* вытолкнуть элемент из стека */
	void topel(int* n1, int* n2);	//верхний элемент
	bool isEmpty();	          /* пустой стек? */
	bool isFull();	          /* полный стек? */
};



