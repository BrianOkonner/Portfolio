#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <algorithm>
#include <locale.h>
#include <windows.h>
#include <iomanip>
using namespace std;

struct Student {
	char name[10];									// Имя студента
	int group;										// Номер группы
	double grade;									// Средний балл 
};

class StudContainer
{
	int size;										// Размерность массива
	Student* p;										// Массив записей о студентах
	int count;										// Количество студентов в контейнере
public:
	StudContainer(int& n);							// Конструктор
	StudContainer(const StudContainer& c);			// Конструктор копирования
	~StudContainer();								// Деструктор
	bool Insert(const Student& s);					// Включение студента в контейнер
	bool Delete(char* name);						// Исключение студента из контейнера
	void SortByName();								// Сортировка записей по именам
	Student FindByName(char* name);					// Поиск студента по имени
	void SortByGroupAndName();						// Сортировка по группам, именам
	void Average_grade_in_group();
	void Report(ostream& out);						// Вывести отчет в файл
	void Print(ostream& out);						// Распечатать список студентов
	int ShowSize();									// Возвращает размер контейнера
	int ShowCount();								// Возвращает количество записей в контейнере
	bool IsFull();
	bool IsEmpty();
};

void Print_to_console(StudContainer A);
void Print_sorted_by_name(StudContainer A);
void Print_sorted_by_name_and_group(StudContainer A);
void Find_student(StudContainer A);
void Add_student_info(StudContainer &A);
void Delete_student_info(StudContainer &A);
void Average_grade_in_group(StudContainer A);