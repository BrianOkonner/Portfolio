#include "StudContainer.h"

StudContainer::StudContainer(int& n) {
	p = new Student[n * sizeof(Student)];
	this->size = n;
	this->count = 0;
	for (int i = 0; i < this->size; ++i) {
		p->name[0] = '\0';
		p->grade = 0;
		p->group = 0;
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

bool operator < (const Student &L, const Student &R)
{
	if (strcmp(L.name, R.name) == -1)
		return true;
	else
		return false;
}

bool StudContainer::Insert(const Student &s) {
	if (IsFull()) {
		throw 1;
	}
	else {
		p[count] = s;
		count++;
		return true;
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
				p[count - 1].group = 0;
				count--;
				break;
			}
		}
		if (flag == false)
		{
			cout << "Такого студента нет в списке!\n";
			return false;
		}
		return true;
	}
}

int StudContainer::ShowSize() {
	return size;
}

int StudContainer::ShowCount() {
	return count;
}

bool StudContainer::IsFull() {
	return (count == size);
}

bool StudContainer::IsEmpty() {
	return (count == 0);
}

void StudContainer::Print(ostream& out) {
	out << left << setw(15) << "Имя " << left << setw(15) << "Группа " << left << setw(15) << "Средний балл" << endl << endl;
	for (int i = 0; i < ShowCount(); i++)
		out << left << setw(15) << p[i].name << " " << left << setw(15) << p[i].group << " " << left << setw(15) << p[i].grade << endl;
	out << endl;
}

Student StudContainer::FindByName(char *name) {
	Student s;
	bool flag = false;
	for (int i = 0; i < ShowCount(); ++i)
	{
		if (strcmp(name, p[i].name) == 0)
		{
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
	for (int i = 0; i < ShowCount(); i++)
	{
		for (int j = 0; j < ShowCount() - 1; j++)
		{
			if (strcmp(p[j].name, p[j + 1].name) == 1)
			{
				Student temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}	 //Сортировка по имени

	for (int i = 0; i < ShowCount(); i++)
	{
		for (int j = 0; j < ShowCount() - 1; j++)
		{
			if (p[j].group > p[j + 1].group)
			{
				Student temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}	 // Сортировка по группе
}

void StudContainer::Report(ostream& out) {
	out << left << setw(15) << "Имя " << left << setw(15) << "Группа " << left << setw(15) << "Средний балл" << endl << endl;
	for (int i = 0; i < ShowCount(); i++)
		out << left << setw(15) << p[i].name << " " << left << setw(15) << p[i].group << " " << left << setw(15) << p[i].grade << endl;
}

void Print_to_console(StudContainer A) {
	A.Print(cout);
	system("pause");
	system("cls");
}

void Print_sorted_by_name(StudContainer A) {
	A.SortByName();
	A.Print(cout);
	system("pause");
	system("cls");
}

void Print_sorted_by_name_and_group(StudContainer A) {
	A.SortByGroupAndName();
	A.Print(cout);
	system("pause");
	system("cls");
}

void Find_student(StudContainer A) {
	char Name[10]; Name[0] = '\0';
	cout << "Введите имя студента - ";
	cin >> Name;
	Student S = A.FindByName(Name);
	cout << endl << "Студент найден!" << endl << endl;
	cout << "Имя          - " << S.name << endl << "Номер группы - " << S.group << endl << "Средний балл - " << S.grade << endl;
	cout << endl;
	system("pause");
	system("cls");
}
void Add_student_info(StudContainer &A) {
	char Name[10]; Name[0] = '\0';
	Student S;
	cout << "Введите имя студента - ";
	cin >> Name;
	strcpy(S.name, Name);
	cout << "Введите номер группы - ";
	cin >> S.group;
	cout << "Введите средний балл - ";
	cin >> S.grade;

	A.Insert(S);
	cout << endl << "Информация о студенте добавлена!" << endl << endl;
	system("pause");
	system("cls");
}

void Delete_student_info(StudContainer &A) {
	char Name[10]; Name[0] = '\0';
	cout << "Введите имя студента - ";
	cin >> Name;

	A.Delete(Name);
	cout << endl << "Информация удалена" << endl << endl;
	system("pause");
	system("cls");
}

void StudContainer::Average_grade_in_group()
{
	int i;
	SortByGroupAndName();
	double sum = 0, count = 0;
	for (i = 0; i < ShowCount(); i++)
	{
		if (i == 0 || p[i].group == p[i - 1].group)
		{
			sum += p[i].grade;
			count++;
			continue;
		}
		else
		{
			cout << "Средний балл в группе номер " << p[i - 1].group << " равен  " << sum / count << endl;
			sum = p[i].grade;
			count = 1;
		}
	}

	cout << "Средний балл в группе номер " << p[i - 1].group << " равен  " << sum / count << endl << endl;
	system("pause");
	system("cls");
}