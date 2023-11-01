#include "StudContainer.h"
StudContainer::StudContainer(int& _n)		// �����������
{
	p = new Student[(_n > _Size ? _n : _Size) * sizeof(Student)];
	count = 0;
	size = _n > _Size ? _n : _Size;
}
StudContainer::StudContainer(const StudContainer& c)	// ����������� �����������
{
	p = (Student*)malloc(c.size * sizeof(Student));
	size = c.size;
	for (count = 0; count < c.count; count++)
	{
		p[count] = c.p[count];
	}
}
StudContainer::~StudContainer()	// ����������
{
	count = 0;
	size = 0;
	delete[]p;
	p = 0;
}
bool StudContainer::insert(Student s)
{
	/*try
	{
	if (count >= size) throw 1;
	}
	catch (...) { "count >= size"; return 0; }
	*/
	strcpy_s(this->p[count].name, s.name);
	this->p[count].num = s.num;
	this->p[count].grade = s.grade;
	count++;
	return 1;
}
Student Read_Write_file(istream&In, ostream&Out)
{
	Student st;
	In >> st.name >> st.num >> st.grade;
	Out << st.name << " " << st.num << " " << st.grade << endl;
	return st;
}

int StudNameCmp(Student* s1, Student* s2)
{
	return strcmp((*s1).name, (*s2).name);
}
void StudContainer::sortByName()	// ���������� ������� �� ������
{
	qsort(p, count, sizeof(Student), (int(*)(const void*,
		const void*))(StudNameCmp));
}

int StudGroupAndNameCmp(Student* s1, Student* s2)
{
	if ((*s1).num > (*s2).num)
		return 1;
	if ((*s1).num < (*s2).num)
		return -1;
	return strcmp((*s1).name, (*s2).name);
}
void StudContainer::sortByGroupAndName()	// ���������� �� �������, ������
{
	qsort(p, count, sizeof(Student), (int(*)(const void*, const void*))
		(StudGroupAndNameCmp));
}

void StudContainer::report(ostream & out)
{
	double srgrade = 0;
	try
	{
		if (count == 0)throw 1;
	}
	catch (...) { out << "We do not have students"; return; }
	for (int i = 0; i < count; i++)
	{
		srgrade += p[i].grade;
	}
	srgrade /= count;
	out << "\n Average score of student: " << srgrade;
}

void StudContainer::print(ostream& out)	// ����������� ������ ���������
{
	out << "Student        group         grade " << endl;
	out << "----------------------------------- " << endl;
	for (int i = 0; i < count; i++)
		out << left << setw(12) << p[i].name << right << setw(8) << p[i].num << setw(12) << p[i].grade << endl;
}
Student* StudContainer::findByName(char* name)	// ����� �������� �� �����
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(p[i].name, name) == 0)
		{
			return &p[i];
		}
	}
	return 0;
}

int StudContainer::Size()	// ���������� ������ ����������
{
	return size;
}

int StudContainer::Count()	// ���������� ���������� ������� � ����������
{
	return count;
}
