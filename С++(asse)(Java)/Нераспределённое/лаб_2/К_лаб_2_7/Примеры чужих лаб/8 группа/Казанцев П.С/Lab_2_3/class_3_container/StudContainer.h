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
	char name[10];									// ��� ��������
	int group;										// ����� ������
	double grade;									// ������� ���� 
};

class StudContainer
{
	int size;										// ����������� �������
	Student* p;										// ������ ������� � ���������
	int count;										// ���������� ��������� � ����������
public:
	StudContainer(int& n);							// �����������
	StudContainer(const StudContainer& c);			// ����������� �����������
	~StudContainer();								// ����������
	bool Insert(const Student& s);					// ��������� �������� � ���������
	bool Delete(char* name);						// ���������� �������� �� ����������
	void SortByName();								// ���������� ������� �� ������
	Student FindByName(char* name);					// ����� �������� �� �����
	void SortByGroupAndName();						// ���������� �� �������, ������
	void Average_grade_in_group();
	void Report(ostream& out);						// ������� ����� � ����
	void Print(ostream& out);						// ����������� ������ ���������
	int ShowSize();									// ���������� ������ ����������
	int ShowCount();								// ���������� ���������� ������� � ����������
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