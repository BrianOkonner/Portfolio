#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
	char name[10];									// Имя студента
	int num;										// Номер группы
	double grade;									// Средний балл 
};

bool operator < (const Student &L, const Student &R);

class StudContainer
{
	int size;										// Размерность массива
	Student* p;										// Массив записей о студентах
	int count;										// Количество студентов в контейнере
public:
	StudContainer(int& _n);							// Конструктор
	StudContainer(const StudContainer& c);			// Конструктор копирования
	~StudContainer();								// Деструктор
	bool Insert(const Student& s);					// Включение студента в контейнер
	bool Delete(char* name);						// Исключение студента из контейнера
	void SortByName();								// Сортировка записей по именам
	Student FindByName(char* name);					// Поиск студента по имени
	void SortByGroupAndName();						// Сортировка по группам, именам
	void Report(ostream& out);						// Вывести отчет в файл
	void Print(ostream& out);						// Распечатать список студентов
	int ShowSize();									// Возвращает размер контейнера
	int ShowCount();								// Возвращает количество записей в контейнере
	bool IsFull();
	bool IsEmpty();
};

void Func1(StudContainer A);
void Func2(StudContainer A);
void Func3(StudContainer A);
void Func4(StudContainer A);
void Func5(StudContainer &A);
void Func6(StudContainer &A);