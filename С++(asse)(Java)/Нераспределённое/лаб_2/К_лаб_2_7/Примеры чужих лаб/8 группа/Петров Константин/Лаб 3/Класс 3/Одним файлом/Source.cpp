/*
		������ ����������
			8 ������
		����� 3

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~�����~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ������ � ����� ������ ���� �������� � ������� ��� ������ ���� 
 ����� �� ����������
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					��� ������

1 - ��������� ������������. ���������� �������� ����� �������
2 - ��������� ����. ���������� ������� �������
3 - .FindByName ������ �������� ��� � ����������
4 - ������ ������ � ����


*/


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

bool operator < (const Student &L, const Student &R) {
	if (strcmp(L.name, R.name) == -1) return true;
	else return false;
}

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

StudContainer::StudContainer(int& _n) {
	p = new Student[_n * sizeof(Student)];
	this->size = _n;
	this->count = 0;
	for (int i = 0; i < this->size; ++i) {
		p->name[0] = '\0';
		p->grade = 0;
		p->num = 0;
	}
}

StudContainer::StudContainer(const StudContainer& c) {
	p = new Student[c.size * sizeof(Student)];
	this->size = c.size;
	this->count = c.count;
	for (int i = 0; i < this->count; ++i)
		p[i] = c.p[i];
}

StudContainer::~StudContainer() {
	this->size = 0;
	this->count = 0;
	delete[]p;
}

bool StudContainer::Insert(const Student &s) {
	if (IsFull()) {
		throw 1;
	}
	else {
		p[count] = s;
		count++;
		return 1;
	}
}

bool StudContainer::Delete(char* name) {
	if (IsEmpty()) {
		throw 2;
	}
	else {
		bool flag = false;
		for (int i = 0; i < count; ++i) {
			if (strcmp(p[i].name, name) == 0) {
				flag = true;
				for (int k = i; k < count - 1; k++)
					p[k] = p[k + 1];
				p[count - 1].grade = 0;
				p[count - 1].name[0] = '\0';
				p[count - 1].num = 0;
				count--;
				break;
			}
		}
		if (flag == false) { cout << "There is no such student\n"; return 0; }
		return 1;
	}
}

int StudContainer::ShowSize() {
	return size;
}

int StudContainer::ShowCount() {
	return count;
}

bool StudContainer::IsFull() {
	return (size == count);
}

bool StudContainer::IsEmpty() {
	return (count == 0);
}

void StudContainer::Print(ostream& out) {
	out << left << setw(9) << "Name" << " " << left << setw(9) << "Group" << " " << left << setw(9) << "Grade" << endl << endl;
	for (int i = 0; i < ShowCount(); i++)
		out << left << setw(9) << p[i].name << " " << left << setw(9) << p[i].num << " " << left << setw(9) << p[i].grade << endl;
	out << endl;
}

Student StudContainer::FindByName(char *name) {
	Student s;
	bool flag = false;
	for (int i = 0; i < ShowCount(); ++i) {
		if (strcmp(name, p[i].name) == 0) {
			flag = true;
			s = p[i];
			break;
		}
	}
	if (flag == false) {
		throw 3;
	}
	return s;
}

void StudContainer::SortByName() {
	sort(p, p + count);
}

void StudContainer::SortByGroupAndName() {
	for (int i = 0; i < ShowCount(); i++) {
		for (int j = 0; j < ShowCount() - 1; j++) {
			if (strcmp(p[j].name, p[j + 1].name) == 1) {
				Student temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}	 //���������� �� �����
	
	for (int i = 0; i < ShowCount(); i++) {
		for (int j = 0; j < ShowCount() - 1; j++) {
			if (p[j].num > p[j + 1].num) {
				Student temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}	 // ���������� �� ������
}

void StudContainer::Report(ostream& out) {
	out << left << setw(9) << "Name" << " " << left << setw(9) << "Group" << " " << left << setw(9) << "Grade" << endl << endl;
	for (int i = 0; i < ShowCount(); i++)
		out << left << setw(9) << p[i].name << " " << left << setw(9) << p[i].num << " " << left << setw(9) << p[i].grade << endl;
}

void Func1(StudContainer A);
void Func2(StudContainer A);
void Func3(StudContainer A);
void Func4(StudContainer A);
void Func5(StudContainer &A);
void Func6(StudContainer &A);

int main() {
	try {
		ifstream fin("Input.txt");
		char *Buff = new char[10];
		const char R[] = "!:; ";
		fin.getline(Buff, 81);
		char *b = strtok(Buff, R);
		int num = atoi(b);
		delete[]Buff;

		StudContainer Stud(num);
		int count = 0;
		while (!fin.eof()) {
			char Buff[81]; Buff[0] = '\0';
			Student s;
			fin.getline(Buff, 81);
			char *b = strtok(Buff, R);
			strcpy(s.name, b);
			b = strtok(NULL, R);
			s.num = atoi(b);
			b = strtok(NULL, R);
			s.grade = (double)atof(b);
			Stud.Insert(s);
			count++;
		}
		fin.close();
		do {
			cout << "0 - Exit." << endl;
			cout << "1 - Display student's average grade in each group." << endl;
			cout << "2 - Sort by name & display." << endl;
			cout << "3 - Sort by name & group number. Display." << endl;
			cout << "4 - Find student & display." << endl;
			cout << "5 - Add student." << endl;
			cout << "6 - Delete student's info" << endl;
			switch (_getch() - '0') {
			case 1: {
				system("cls");
				Func1(Stud);
				break;
			}
			case 2: {
				system("cls");
				Func2(Stud);
				break;
			}
			case 3: {
				system("cls");
				Func3(Stud);
				break;
			}
			case 4: {
				system("cls");
				Func4(Stud);
				break;
			}
			case 5: {
				system ("cls");
				Func5(Stud);
				break;
			}
			case 6: {
				system("cls");
				Func6(Stud);
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
		cout << "Exception\n";
		cout << "Code - " << y << endl;
	}
	return 0;
}

void Func1(StudContainer A) {
	A.Print(cout);
	system("pause");
	system("cls");
}

void Func2(StudContainer A) {
	A.SortByName();
	A.Print(cout);
	system("pause");
	system("cls");
}

void Func3(StudContainer A) {
	A.SortByGroupAndName();
	A.Print(cout);
	system("pause");
	system("cls");
}

void Func4(StudContainer A) {
	char Name[10]; Name[0] = '\0';
	cout << "Enter student's name - ";
	cin >> Name;
	Student S = A.FindByName(Name);
	cout << endl << "Student found" << endl << endl;
	cout << "Name       - " << S.name << endl << "Group num  - " << S.num << endl << "Avg. grade - " << S.grade << endl << endl << endl;
	cout << endl;
	system("pause");
	system("cls");
}
void Func5(StudContainer &A) {
	char Name[10]; Name[0] = '\0';
	Student S;
	cout << "Enter student's name - ";
	cin >> Name;
	strcpy(S.name, Name);
	cout << "Enter student's group - ";
	cin >> S.num;
	cout << "Enter student's avg. grade - ";
	cin >> S.grade;

	A.Insert(S);
	cout << endl << "Student added" << endl << endl;
	system("pause");
	system("cls");
}

void Func6(StudContainer &A) {
	char Name[10]; Name[0] = '\0';
	cout << "Enter student's name - ";
	cin >> Name;

	A.Delete(Name);
	cout << endl << "Info deleted" << endl << endl;
	system("pause");
	system("cls");
}