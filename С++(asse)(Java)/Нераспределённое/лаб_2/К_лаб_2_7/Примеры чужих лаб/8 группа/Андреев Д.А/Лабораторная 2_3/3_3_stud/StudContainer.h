#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student
{
	char  name[10];		// фамилия студента
	int   num;			// номер группы
	double  grade;		// средний бал
};

class StudContainer
{
	int size;	      // размерность массива
	Student* p;	      // массив записей о студентах
	int count;	      // количество студентов в контейнере
public:
	StudContainer(int& _n);	                // конструктор
	StudContainer(const StudContainer& c);  // конструктор копирования
	~StudContainer();						// деструктор
	bool insert(const Student& s);			// включение студента в контейнер
	bool del(char* name);					// исключение студента из контейнера
	void sortByName();						// сортировка записей по именам
	Student* findByName(char* name);		// поиск студента по имени
	void sortByGroupAndName();				// сортировка по группам, именам
	void report(ostream& out);			// вывести отчет в файл
	void print(ostream& out);				// распечатать список студентов
	int Size();								// возвращает размер контейнера
	int Count();							// возвращает количество записей в контейнере
};