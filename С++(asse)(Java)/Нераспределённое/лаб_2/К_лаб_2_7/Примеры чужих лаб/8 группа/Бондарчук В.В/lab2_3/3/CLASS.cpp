#include"CLASS.h"
StudContainer::StudContainer(int& _n)
{
	p = new Student[_n*sizeof(Student)];
	this->size =_n; this->count = 0;
	for (int i = 0; i < _n; i++)
	{
		this->p->name[0] = '/0';
		this->p->num = 0;
		this->p->grade = 0;
	}
}
StudContainer::StudContainer(const StudContainer& c)
{
	p = new Student[c.size* sizeof(Student)];
	this->size = c.size;
	this->count = c.count;
	for (int i = 0; i < c.size; i++)
	{
		this->p[i] = c.p[i];
	}
}
StudContainer::~StudContainer()
{
	delete[]p; this->size = NULL; this->count = NULL;
}
bool StudContainer::insert(const Student& s)
{
		if (this->count == this->size)
		{
			throw 1;
		}
		else
		{
			this->p[this->count] = s; this->count++; return true;
		}
}
bool StudContainer::del(char* name)
{
	if (this->count == 0)
		throw 2;
	else
	{
		int tmp = this->count;
		for (int i = 0; i < this->count; i++)
		{
			if (strcmp(this->p[i].name, name) == 0)
			{
				for (int j = i; this->p[j + 1].name != '\0'; j++)
				{
					this->p[j] = this->p[j + 1];
					p[this->count - 1].grade = 0;
					p[this->count - 1].name[0] = '\0';
					p[this->count - 1].num = 0;
					this->count--;
					break;
				}
			}
		}
		if (tmp == this->count)
			throw 3;
	}
}
void StudContainer::sortByName()
{
	int flag = 1;
	while (flag != 0)
	{
		flag = 0;
		for (int i = 0; i<this->count; i++)
			if (strcmp(p[i].name, p[i + 1].name)>0)
			{
				Student tmp = p[i];
				p[i] = p[i + 1];
				p[i + 1] = tmp;
				flag++;
			}
	}
}
int StudContainer::Count()
{
	int tmp = this->count;
	return tmp;
}
int StudContainer::Size()
{
	return this->size;
}
Student* StudContainer::findByName(char* name)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(name, this->p[i].name) == 0)
		{
			return &this->p[i];
		}
	}
	Student k;
	k.grade = 0;
	k.num = 0;
	k.name[0] = '\0';
	return &k;
	
}
void StudContainer::sortByGroupAndName()
{
	int flag = 1;
	while (flag != 0)
	{
		flag = 0;
		for (int i = 0; i<this->count; i++)
			if (strcmp(p[i].name, p[i + 1].name)>0)
			{
				Student tmp = p[i];
				p[i] = p[i + 1];
				p[i + 1] = tmp;
				flag++;
			}
	}
	int temp = 0;
	bool exit = false;
	while (!exit)
	{
		exit = true;
		for (int i = 0; i< this->count - 1; i++)
			if (p[i].num > p[i + 1].num)
			{

				temp = p[i].num;
				p[i].num = p[i + 1].num;
				p[i + 1].num = temp;
				exit = false;
			}
	}
}
void StudContainer::print(ostream& out)
{
	out << setw(9) << "group" << " " << setw(9) << "name" << " " << setw(9) << "grade" << endl;
	for (int i = 0; i < this->count; i++)
		out << setw(9) << p[i].num << " " <<  setw(9) << p[i].name << " " << setw(9) << p[i].grade << endl;
	out << endl << endl;
}
void StudContainer::report(ostream& out)
{
	out << setw(9) << "group" << " " << setw(9) << "name" << " " << setw(9) << "grade" << endl;
	for (int i = 0; i < this->count; i++)
		out << setw(9) << p[i].num << " " << setw(9) << p[i].name << " " << setw(9) << p[i].grade << endl;
	out << endl << endl;
}
