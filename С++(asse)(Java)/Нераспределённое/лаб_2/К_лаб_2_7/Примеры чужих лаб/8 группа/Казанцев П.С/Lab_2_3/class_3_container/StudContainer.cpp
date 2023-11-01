/* �������� �����
	1 ����	8 ������
	����� StudContainer
________________________________________________________________________
__________________________�������� ����������___________________________
 ������ � �����  �������� � �������:  ��� ������ ���� 
 !!��������� ����� ������� Lucida Console !!
________________________________________________________________________
					���� ������

1 - ��������� ������������. ���������� �������� ����� �������
2 - ��������� ����. ���������� ������� �������
3 - .FindByName ������ �������� ��� � ����������
4 - ������ ������ � ����


*/

/*#define _CRT_SECURE_NO_WARNINGS
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
*/
#include "StudContainer.h"

int main() {

	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);					// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);
	try {
		ifstream in("Input.txt");
		char *Buff = new char[10];
		const char R[] = "!:; ";
		in.getline(Buff, 81);
		char *b = strtok(Buff, R);
		int current_group = atoi(b);
		delete[]Buff;
		StudContainer Stud(current_group);
		int count = 0;
		while (!in.eof()) {
			char Buff[81]; Buff[0] = '\0';
			Student s;
			in.getline(Buff, 81);
			char *b = strtok(Buff, R);
			strcpy(s.name, b);
			b = strtok(NULL, R);
			s.group = atoi(b);
			b = strtok(NULL, R);
			s.grade = (double)atof(b);
			Stud.Insert(s);
			count++;
		}
		in.close();
		do {
			cout << "0 - �����" << endl;
			cout << "1 - ���������� ��� ���� ���������" << endl;
			cout << "2 - ������ ��������� � ���������� �������" << endl;
			cout << "3 - ������ ��������� �� �������" << endl;
			cout << "4 - ����� ���������� � ��������" << endl;
			cout << "5 - �������� ���������� � �������� � ���������" << endl;
			cout << "6 - ������� ���������� � �������� �� ����������" << endl;
			cout << "7 - ������� ���� �� ������ ������" << endl;
			switch (_getch() - '0') {
			case 1: {
				system("cls");
				Print_to_console(Stud);
				break;
			}
			case 2: {
				system("cls");
				Print_sorted_by_name(Stud);
				break;
			}
			case 3: {
				system("cls");
				Print_sorted_by_name_and_group(Stud);
				break;
			}
			case 4: {
				system("cls");
				Find_student(Stud);
				break;
			}
			case 5: {
				system ("cls");
				Add_student_info(Stud);
				break;
			}
			case 6: {
				system("cls");
				Delete_student_info(Stud);
				break;
			}
			case 7:{
				system("cls");
				Stud.Average_grade_in_group();
				break;
			}
			case 0: {
				system("cls");
				cout << " " << endl;
				return 0;
			}
			default: {
				system("cls");
				throw 4;
			}
			}

		} while (true);
	}
	catch (int y) {
		cout << "����������\n";
		cout << "����� ������ - " << y << endl;
	}
	return 0;
}

