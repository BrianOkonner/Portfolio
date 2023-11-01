#pragma once
#include "Header.h"
#define Name_Len 10


struct Student
{
	char  name[Name_Len];					// ������� ��������
	int   num;								// ����� ������
	double  grade;							// ������� ���
};

class StudContainer
{
	enum { _Size = 100 };
	int size;								// ����������� �������
	Student* p;								// ������ ������� � ���������
	int count;					// ���������� ��������� � ����������
public:
	
	StudContainer(int& _n);					// �����������
	StudContainer(const StudContainer& c);	// ����������� �����������
	~StudContainer();						// ����������
	bool insert(Student s);			// ��������� �������� � ���������
	bool del(char* name);					// ���������� �������� �� ����������
	void sortByName();						// ���������� ������� �� ������
	Student* findByName(char* name);		// ����� �������� �� �����
	void sortByGroupAndName();				// ���������� �� �������, ������
	void report(ostream& out);				// ������� ����� � ������� �����
	void print(ostream& out);				// ����������� ������ ���������
	int Size();								// ���������� ������ ����������
	int Count();							// ���������� ���������� ������� � ����������
};
Student Read_Write_file(istream&In, ostream&Out);
void StudContainerFunc();
//int StudContainer::count = 0;