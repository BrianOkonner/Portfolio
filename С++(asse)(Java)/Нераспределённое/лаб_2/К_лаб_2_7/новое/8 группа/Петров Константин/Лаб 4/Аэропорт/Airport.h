#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <conio.h>
using namespace std;

class Airport {
	struct Date {
		int dd, mm;
	};
	struct AirCraft {
		int ID;
		int type;
		string cName;
		int acCapacity;						// ����������� ��������
		int econNum;						// ���������� ���� � ������ ������
		int vipNum;							//		-//-		 ������ ������
		int econSeats;						// ����� ������ ������
		int vipSeats;						// ����� ��� ������
		string sTown;						// ��������� �����
		string dTown;						// ����� ����������
		int price;							// ���� �������
		Date date;							// ���� �����
		AirCraft(string, string, string);
	};
	struct Company {
		int Rep;
		string Name;
		Company(string, int);
	};
	vector<Company> Companies;
	vector<string> Towns;
	vector<AirCraft> AC;
public:
	Airport();
	void Fprint(string, string, Date, string, int, int);
	void Print(string, string, Date, string, int, int);
	void Menu1();
	void Menu2();
	void PrintAll();
	void ShowPar(string, string, Date, string, int, int);
	void FindAndShow(int, string);

};

void Func2(Airport A);
void Func1(Airport A);