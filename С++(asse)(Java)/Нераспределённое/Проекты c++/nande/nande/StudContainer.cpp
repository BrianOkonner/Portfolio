#include "StudContainer.h"
#include <iomanip>
using namespace std;
StudContainer::StudContainer(int& _n)
{
	p=new Student[_n*sizeof(Student)];
	this->size=_n;
	this->count=0;
}
StudContainer::StudContainer(const StudContainer& c)
{
	p=new Student[c.size*sizeof(Student)];
	this->size=c.size;
	this->count=c.count;
	for (int i=0;i<this->count;i++)
		p[i] = c.p[i];
}
StudContainer::~StudContainer()
{
	this->size=0;
	this->count=0;
	delete p;
}
bool StudContainer::insert(const Student& s)
{
	p[count]=s;
	count++;
	return 1;
}
bool StudContainer::del(char* name)
{
	int f=0;
	for(int i=0;i<count;i++)
		if(p[i].name==name)
		{
			f=1;
			for(i++;i<count;i++)
				p[i-1]=p[i];
			p[count-1].grade=0;
			p[count-1].name[0]='\0';
			p[count-1].num=0;
		}
		return f;
}
void StudContainer::sortByName()
{
	for (int i=0;i<count;i++)
	{
		int fl=0;
		for (int j=0;j<count-1;j++)
			if(strcmp(p[j].name,p[j+1].name)>0)
			{
				Student tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
				fl=1;
			}
		if(fl==0)
			break;
	}
}
Student* StudContainer::findByName(char* name)
{
	int f=0;
	for(int i=0;i<count;i++)
		if(p[i].name==name)
			return &(p[i]);
}
void StudContainer::sortByGroupAndName()
{
	for (int i=0;i<count;i++)
	{
		int fl=0;
		for (int j=0;j<count-1;j++)
			if(strcmp(p[j].name,p[j+1].name)>0)
			{
				Student tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
				fl=1;
			}
		if(fl==0)
			break;
	}
	for (int i=0;i<count;i++)
	{
		int fl=0;
		for (int j=0;j<count-1;j++)
			if(p[j].num>p[j+1].num)
			{
				Student tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
				fl=1;
			}
		if(fl==0)
			break;
	}
}
void StudContainer::report(std::ostream& out)
{
	out<<left<<setw(20)<<"Surname"<<setw(7)<<"Group"<<setw(5)<<"Grade"<<endl;
	for(int i=0;i<count;i++)
		out<<left<<setw(20)<<p[i].name<<setw(7)<<p[i].num<<setw(5)<<setprecision(5)<<p[i].grade<<endl;
}
void StudContainer::print(std::ostream& out)
{
	out<<left<<setw(20)<<"Surname"<<setw(7)<<"Group"<<setw(5)<<"Grade"<<endl;
	for(int i=0;i<count;i++)
		out<<left<<setw(20)<<p[i].name<<setw(7)<<p[i].num<<setw(5)<<setprecision(5)<<p[i].grade<<endl;
}
int StudContainer::Wsize()
{return size;}
int StudContainer::Wcount()
{return count;}




