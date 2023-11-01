/*												Задача L6
	Программу написал Владислав Владимирович Перевязчиков.( Специальность: прикладная матнмематика. Группа 8).
	Условие : 
	Краткий алгоритм :(Будем считать что у отличников оценки 4 5 а неудовлитворительные оценки это 3 (хотя это не логично))
	Тесты :*/
struct spisokst
{
	char sname[20];
	int group;
	int num_zach;
	int mark_man;
	int mark_geo;
	int mark_prg;
};
struct spisokst_gen
{
	char sname[20];
	int group;
	int num_zach;
	double mark_aver;
};
struct excellentp
{
	char sname[20];
	int group;
	int num_zach;
};
struct badp
{
	char sname[20];
	int group;
	int num_zach;
};
#include <iostream>
#include "fun_h.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio>  
using namespace std;
void main()
{
	setlocale(LC_ALL,".1251");
	int t,k=0,i=0,j,m=0; 
	double o=0;
	spisokst stmp,*xls;
	spisokst_gen *gen;
	badp *bd;
	excellentp *ex;
	ifstream in("inputl6.txt");
	ofstream out("OutОll.txt"),out2("OutN.txt"),out3("OutO.txt");
	in.seekg(0,in.end);
	t=in.tellg();
	in.seekg(0,in.beg);
	if(t!=0)
	{
		for(k=0;!in.eof();k++)
			in>>stmp.sname>>stmp.group>>stmp.num_zach>>stmp.mark_man>>stmp.mark_geo>>stmp.mark_prg;	
		xls=new spisokst[k];
		gen=new spisokst_gen[k];
		bd=new badp[k];
		ex=new excellentp[k];
		in.clear();
		in.seekg(0,in.beg);
		t=0;
		for(i=0;i<k-1;i++)
		{
			in>>xls[i].sname>>xls[i].group>>xls[i].num_zach>>xls[i].mark_man>>xls[i].mark_geo>>xls[i].mark_prg;
			for(j=0;xls[i].sname[j]!='\0';j++)
				gen[i].sname[j]=xls[i].sname[j];
			gen[i].sname[j]='\0';
			gen[i].group=xls[i].group;
			gen[i].num_zach=xls[i].num_zach;
			if(xls[i].mark_man>=4&&xls[i].mark_geo>=4&&xls[i].mark_prg>=4)
			{
			for(j=0;xls[i].sname[j]!='\0';j++)
				ex[m].sname[j]=xls[i].sname[j];
			ex[m].sname[j]='\0';
			ex[m].group=xls[i].group;
			ex[m].num_zach=xls[i].num_zach;
			m++;
			}
			else
			{
			for(j=0;xls[i].sname[j]!='\0';j++)
				bd[t].sname[j]=xls[i].sname[j];
			bd[t].sname[j]='\0';
			bd[t].group=xls[i].group;
			bd[t].num_zach=xls[i].num_zach;
			t++;
		}
	}
	for(i=0;i<k-1;i++)
	{
//	cout<<"Средний балл студента c фамилией "<<xls[i].sname<<" равен: "
//	<<setprecision(3)<<(double)(xls[i].mark_geo+xls[i].mark_man+xls[i].mark_prg)/3<<endl;
	o=o+(double)(xls[i].mark_geo+xls[i].mark_man+xls[i].mark_prg)/3;
	gen[i].mark_aver=(double)(xls[i].mark_geo+xls[i].mark_man+xls[i].mark_prg)/3;
	}
	cout<<"    Общий средний балл равен: "<<o/(k-1)<<endl;
	out<<"    Общий средний балл равен: "<<o/(k-1)<<endl;
	cout<<"    Общий список:"<<endl;
	for(i=0;i<k-1;i++)
	{
		cout<<setw(15)<<gen[i].sname<<setw(15)<<gen[i].group<<setw(15)<<gen[i].num_zach<<setw(15)<<gen[i].mark_aver<<endl;
		out<<setw(15)<<gen[i].sname<<setw(15)<<gen[i].group<<setw(15)<<gen[i].num_zach<<setw(15)<<gen[i].mark_aver<<endl;
	}
	cout<<"    C неудовлетворительными оценками:"<<endl;
	for(i=0;i<t;i++)
	{
		cout<<setw(15)<<bd[i].sname<<setw(15)<<bd[i].group<<setw(15)<<bd[i].num_zach<<endl;
		out2<<setw(15)<<bd[i].sname<<setw(15)<<bd[i].group<<setw(15)<<bd[i].num_zach<<endl;
	}
	cout<<"    Отличники:"<<endl;
	for(i=0;i<m;i++)
	{
		cout<<setw(15)<<ex[i].sname<<setw(15)<<ex[i].group<<setw(15)<<ex[i].num_zach<<endl;
		out3<<setw(15)<<ex[i].sname<<setw(15)<<ex[i].group<<setw(15)<<ex[i].num_zach<<endl;
	}
	_fcloseall();
	}
	system("pause");
}