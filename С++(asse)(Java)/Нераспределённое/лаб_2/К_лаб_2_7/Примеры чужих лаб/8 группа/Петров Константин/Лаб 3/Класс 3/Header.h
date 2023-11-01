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
	char name[10];									// ��� ��������
	int num;										// ����� ������
	double grade;									// ������� ���� 
};

bool operator < (const Student &L, const Student &R);

class StudContainer
{
	int size;										// ����������� �������
	Student* p;										// ������ ������� � ���������
	int count;										// ���������� ��������� � ����������
public:
	StudContainer(int& _n);							// �����������
	StudContainer(const StudContainer& c);			// ����������� �����������
	~StudContainer();								// ����������
	bool Insert(const Student& s);					// ��������� �������� � ���������
	bool Delete(char* name);						// ���������� �������� �� ����������
	void SortByName();								// ���������� ������� �� ������
	Student FindByName(char* name);					// ����� �������� �� �����
	void SortByGroupAndName();						// ���������� �� �������, ������
	void Report(ostream& out);						// ������� ����� � ����
	void Print(ostream& out);						// ����������� ������ ���������
	int ShowSize();									// ���������� ������ ����������
	int ShowCount();								// ���������� ���������� ������� � ����������
	bool IsFull();
	bool IsEmpty();
};

void Func1(StudContainer A);
void Func2(StudContainer A);
void Func3(StudContainer A);
void Func4(StudContainer A);
void Func5(StudContainer &A);
void Func6(StudContainer &A);