#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student
{
	char  name[10];		// ������� ��������
	int   num;			// ����� ������
	double  grade;		// ������� ���
};

class StudContainer
{
	int size;	      // ����������� �������
	Student* p;	      // ������ ������� � ���������
	int count;	      // ���������� ��������� � ����������
public:
	StudContainer(int& _n);	                // �����������
	StudContainer(const StudContainer& c);  // ����������� �����������
	~StudContainer();						// ����������
	bool insert(const Student& s);			// ��������� �������� � ���������
	bool del(char* name);					// ���������� �������� �� ����������
	void sortByName();						// ���������� ������� �� ������
	Student* findByName(char* name);		// ����� �������� �� �����
	void sortByGroupAndName();				// ���������� �� �������, ������
	void report(ostream& out);			// ������� ����� � ����
	void print(ostream& out);				// ����������� ������ ���������
	int Size();								// ���������� ������ ����������
	int Count();							// ���������� ���������� ������� � ����������
};