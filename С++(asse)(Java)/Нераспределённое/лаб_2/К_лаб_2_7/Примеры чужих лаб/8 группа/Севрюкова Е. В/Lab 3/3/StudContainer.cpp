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
	for (count = 0; count < c.count;count++)
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
	if(count>0)
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
	cout << "There is no such student\n";
	return 0;
}

int StudNameCmp(Student* s1, Student* s2)
{
	return strcmp((*s1).name, (*s2).name);
}
void StudContainer::sortByName()	// сортировка записей по именам
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
void StudContainer::sortByGroupAndName()	// сортировка по группам, именам
{
	qsort(p, this->count, sizeof(Student), (int(*)(const void*, const void*))
		(StudGroupAndNameCmp));
}



int StudContainer::Size()	// возвращает размер контейнера
{
	return this->size;
}


int StudContainer::Count()	// возвращает количество записей в контейнере
{
	return this->count;
}


void StudContainer::print(ostream& out)	// распечатать список студентов
{
	out << "Student        group         grade " << endl;
	out << "----------------------------------- " << endl;
	for (int i = 0; i < count; i++)
		out << left << setw(12) << p[i].name << right << setw(8) << p[i].num << setw(12) << p[i].grade << endl;
}


Student* StudContainer::findByName(char* name)	// поиск студента по имени
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

//--------------------------------------------
void Create_bin_file()
{
	int n;
	Student info;
	ifstream In("input.txt");
	ofstream Out("output2.bin", ios::binary);
	//fstream Out;
	//Out.open("output.txt", ios::out);
	In >> n;
	while (!In.eof())
	{
		In >> info.name >> info.num >> info.grade;
		Out.write((char*)&info, sizeof(Student));

	}
	Out.close();
}
void Read_bin_file()
{
	Student info;
	ifstream In("output2.bin", ios::binary);
	if (!In.is_open())
	{
		cout << "Can not open file " << endl;
	}
	while (!In.eof())
	{
		In.read((char*)&info, sizeof(info));
		cout << info.name << info.num << info.grade << endl;
		//file.read((char*)&s1, sizeof(s1));
	}
}
void Read_bin_Write_text_file()
{
	Student info;
	fstream In;
	fstream Out;
	In.open("output2.bin", ios::in | ios::binary);
	Out.open("output3.txt", ios::out);
	if (!In.is_open())
	{
		cout << "Can not open file " << endl; return;
	}
	while (!In.eof())
	{
		In.read((char*)&info, sizeof(info));
		Out << info.name << info.num << info.grade << endl;
		cout << info.name << info.num << info.grade << endl;
	}
}
