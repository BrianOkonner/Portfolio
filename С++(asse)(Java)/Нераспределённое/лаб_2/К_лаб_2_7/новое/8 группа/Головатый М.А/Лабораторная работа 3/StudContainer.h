#pragma once
#include "Header.h"
#define Name_Len 10


struct Student
{
	char  name[Name_Len];					// фамилия студента
	int   num;								// номер группы
	double  grade;							// средний бал
};

class StudContainer
{
	enum { _Size = 100 };
	int size;								// размерность массива
	Student* p;								// массив записей о студентах
	int count;					// количество студентов в контейнере
public:
	
	StudContainer(int& _n);					// конструктор
	StudContainer(const StudContainer& c);	// конструктор копирования
	~StudContainer();						// деструктор
	bool insert(Student s);			// включение студента в контейнер
	bool del(char* name);					// исключение студента из контейнера
	void sortByName();						// сортировка записей по именам
	Student* findByName(char* name);		// поиск студента по имени
	void sortByGroupAndName();				// сортировка по группам, именам
	void report(ostream& out);				// вывести отчет о среднем балле
	void print(ostream& out);				// распечатать список студентов
	int Size();								// возвращает размер контейнера
	int Count();							// возвращает количество записей в контейнере
};
Student Read_Write_file(istream&In, ostream&Out);
void StudContainerFunc();
//int StudContainer::count = 0;