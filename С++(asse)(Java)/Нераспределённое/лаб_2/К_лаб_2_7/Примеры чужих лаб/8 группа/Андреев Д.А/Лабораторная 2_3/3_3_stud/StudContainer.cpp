#include "StudContainer.h"

StudContainer::StudContainer(int& _n)		// конструктор
{
	p = new Student[(_n > 100 ? _n : 100) * sizeof(Student)];
	count = 0;
	size = _n > 100 ? _n : 100;
}
StudContainer::StudContainer(const StudContainer& c)	// конструктор копирования
{
	p = (Student*)malloc(c.size * sizeof(Student));
	size = c.size;

	for (count = 0; count < c.count; count++)
	{
		p[count] = c.p[count];
	}
}
StudContainer::~StudContainer()	// деструктор
{
	count = 0;
	size = 0;
	delete[]p;
	p = 0;
}

bool StudContainer::insert(const Student& s)
{
	if (count <= size)
	{
		p[count] = s;
		count++;
		return 1;
	}
	return 0;
}

bool StudContainer::del(char* name)
{
	if (count>0)
		for (int i = 0; i < count; i++)
		{
			if (strcmp(p[i].name, name) == 0)
			{
				for (int j = i; j < count - 1; j++)
					p[j] = p[j + 1];
				count--;
				return 1;
			}
		}
	cout << "Не найден\n";
	return 0;
}

int StudNameCmp(Student* s1, Student* s2)
{
	return strcmp((*s1).name, (*s2).name);
}
void StudContainer::sortByName()
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
void StudContainer::sortByGroupAndName()
{
	qsort(p, this->count, sizeof(Student), (int(*)(const void*, const void*))
		(StudGroupAndNameCmp));
}



int StudContainer::Size()
{
	return this->size;
}


int StudContainer::Count()
{
	return this->count;
}


void StudContainer::print(ostream& out)
{
	out << "Студент         группа         балл " << endl;
	out << "----------------------------------- " << endl;
	for (int i = 0; i < count; i++)
		out << left << setw(12) << p[i].name << right << setw(8) << p[i].num << setw(12) << p[i].grade << endl;
}


Student* StudContainer::findByName(char* name)
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

void StudContainer::report(ostream& out)
{
	double bal = 0;
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			bal += p[i].grade;
		}
		bal /= count;
		out << "\nСредний балл студентов: " << bal << endl;
	}
}