#include "Header.h"


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
	}	 //Сортировка по имени

	for (int i = 0; i < ShowCount(); i++) {
		for (int j = 0; j < ShowCount() - 1; j++) {
			if (p[j].num > p[j + 1].num) {
				Student temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}	 // Сортировка по группе
}

void StudContainer::Report(ostream& out) {
	out << left << setw(9) << "Name" << " " << left << setw(9) << "Group" << " " << left << setw(9) << "Grade" << endl << endl;
	for (int i = 0; i < ShowCount(); i++)
		out << left << setw(9) << p[i].name << " " << left << setw(9) << p[i].num << " " << left << setw(9) << p[i].grade << endl;
}

bool operator < (const Student &L, const Student &R) {
	if (strcmp(L.name, R.name) == -1) return true;
	else return false;
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

