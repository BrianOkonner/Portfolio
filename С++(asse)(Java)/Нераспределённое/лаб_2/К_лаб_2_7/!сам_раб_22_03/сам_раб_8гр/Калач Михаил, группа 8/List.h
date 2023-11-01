#pragma once

class List
{
	struct item					//Элемент списка 
	{
		int value;				//Данные
		item*  next;			//Указатель на следующий элемент
	};
	item *first, *last;			//Указатель на первый элемент в списке
	int N;
public:
	List();						//Конструктор
	List(const List& Obj);		//Конструктор копирования
	~List();					//Деструктор
	bool isEmpty();				//Проверка на пустоту
	int size();					//Количество элементов в списке
	int remove_head();			//Исключить элемент из начала списка
	int remove_tail();			//Исключить элемент из конца списка
	int search();				//Найти первый чётный элемент
	int remove(int POS);		//Удаляет на позиции
	int search_min();	    	//Поиск min
	void push_head(int X);		//Включить элемент в начало списка
	void push_back(int X);		//Включить элемент в конец списка
	void print();				//Печать содержимого списка
	void del_even();			//Удаление с четными номерами
	void invert();				//Инвертировать элементы первой половины списка
};
