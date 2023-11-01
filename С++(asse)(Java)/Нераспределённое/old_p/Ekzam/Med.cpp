#include <fstream>
#include <iostream>
using namespace std;

/* structs  */

struct Items
{
	char Name[35];
	char myDate[8];
	char Section[10];
	int Count;
	/*Items()
	{
		Name[0]=NULL;
		myDate[0]=NULL;
		Section[0]=NULL;
		Count=0;
	}*/
	friend istream& operator >>(istream& in,Items &i)
	{
		in>>i.Name>>i.myDate>>i.Section>>i.Count;
		return in;
	}
	friend ostream& operator <<(ostream& out,Items &i)
	{
		out<<i.Name<<"  "<<i.myDate<<"  "<<i.Section<<"  "<<i.Count;
		return out;
	}
	friend bool operator ==(Items &i,Items &j)
	{
		if(i.Name==j.Name)
			return true;
		else
			return false;
	}
};
struct Price
{
	char Name[35];
	double pr;
	/*Price()
	{
		Name[0]=NULL;
		pr=0;
	}*/
	friend istream& operator >>(istream& in,Price &p)
	{
		in>>p.Name>>p.pr;
		return in;
	}
	friend ostream& operator <<(ostream& out,Price &p)
	{
		out<<p.Name<<"  "<<p.pr;
		return out;
	}
	friend bool operator ==(Price &i,Price &j)
	{
		if(i.Name==j.Name)
			return true;
		else
			return false;
	}
};
struct Med
{
	char Name[35];
	char myDate[8];
	char Section[10];
	double pr;
	int Count;
	/*Med()
	{
		pr=0;
		Section[0]=NULL;
		Name[0]=NULL;
		myDate[0]=NULL;
		Count=0;
	}*/
	friend istream& operator >>(istream& in,Med &m)
	{
		in>>m.Name>>m.myDate>>m.Section>>m.pr>>m.Count;
		return in;
	}
	friend ostream& operator <<(ostream& out,Med &m)
	{
		out<<m.Name<<"  "<<m.myDate<<"  "<<m.Section<<"  "<<m.pr<<"  "<<m.Count;
		return out;
	}
	friend bool operator ==(Med &i,Med &j)
	{
		if(i.Name==j.Name)
			return true;
		else
			return false;
	}
};
int compar(const Items *a,const Items *b)
{
	return strcmp((*a).Name,(*b).Name);
}
int compar1(const Price *a,const Price *b)
{
	return strcmp((*a).Name,(*b).Name);
}
/* classes   */

class ABS_Med
{
public:
	virtual istream& GetMeds(istream&)=0;
	virtual ostream& PutMeds(ostream&)=0;
	virtual void SortUp(){}
	virtual void SortDown(){}
	virtual int Count()=0;
};
class MB1:public ABS_Med
{
	int count;
	Items *M;
public:
	MB1(){count=0;}
	~MB1(){delete M;}
	istream& GetMeds(istream& in)
	{
		in>>count;
		M=new Items[count];
		for(int i=0;i<count;i++)
		{in>>M[i];}
		return in;
	}
	int Count(){return count;}
	ostream& PutMeds(ostream& out)
	{
		for(int i=0;i<count;i++)
		{out<<M[i]<<endl;}
		return out;
	}
	void SortUp()
	{
		qsort(M,count,sizeof(Items),(int(*) (const void *, const void *))compar);
	}
	Items operator [] (int n)
	{
		return M[n];
	}
};
class MB2:public ABS_Med
{
	int count;
	Price *M;
public:
	MB2(){count=0;}
	~MB2(){delete M;}
	int Count(){return count;}
	void SortUp()
	{
		qsort(M,count,sizeof(Price),(int(*) (const void *, const void *))compar1);
	}
	istream& GetMeds(istream& in)
	{
		in>>count;
		M=new Price[count];
		for(int i=0;i<count;i++)
		{in>>M[i];}
		return in;
	}
	ostream& PutMeds(ostream& out)
	{
		for(int i=0;i<count;i++)
		{out<<M[i]<<endl;}
		return out;
	}
	Price operator [] (int n)
	{
		return M[n];
	}
};
class MB3:public ABS_Med
{
	int count;
	Med *M;
public:
	int Count(){return count;}
	MB3(){count=0;}
	~MB3(){delete M;}
/*	MB3 unit(MB2 a,MB3 t)
	{
		M=new Med[a.Count()];
		count=a.Count();
		for(int i=0;i<count
	}*/
	istream& GetMeds(istream& in)
	{
		in>>count;
		M=new Med[count];
		for(int i=0;i<count;i++)
		{in>>M[i];}
		return in;
	}
	ostream& PutMeds(ostream& out)
	{
		for(int i=0;i<count;i++)
		{out<<M[i]<<endl;}
		return out;
	}
	Med operator [] (int n)
	{
		return M[n];
	}
};
/*   main   */

int main()
{
	MB1 M1;MB2 M2;MB3 M3;
	ABS_Med *A1,*A2;
	ifstream in1("in1.txt");
	ifstream in2("in2.txt");
	ofstream out("out.txt");
	A1=&M1;
	A1->GetMeds(in1);
	A1->SortUp();
	A1->PutMeds(out);
	A1->PutMeds(cout);
	system("pause");
	A2=&M2;
	A2->GetMeds(in2);
	A2->SortUp();
	A2->PutMeds(out);
	A2->PutMeds(cout);
	system("pause");
/*	for(int i=0;i<A1->Count();i++)
	{
		for(int j=0;j<A2->Count();j++)
		{
			if(M2[i].Name==M1[j].Name)
				
		}
	}*/
	return 0;
}