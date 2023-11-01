//Loban Yana 5 gr
#include <iostream>
#include <fstream>
using namespace std;
int func1(char** ma)
{
	int i=0;
	char* s=new char[100];
	char* sl;//строка куда будут помещаться выделенные лексемы
	ifstream in("input.txt");
	ofstream out("Result1.txt");
	if(!in.is_open())
		cout<<"fail ne sozdan!"<<endl;
	cout<<"Leksemu"<<endl;
	out<<"Leksemu:"<<endl<<endl;
	while(in.getline(s,100))
	{
		sl=strtok(s," -.,;:!");
        if(!sl)
			break;
		while(sl)
		{
			cout<<sl<<endl;
			out<<sl<<endl;
			strcpy(ma[i],sl);
		    ++i;
			sl=strtok(NULL," -.,;:!");
			if(!sl)
				break;
		}
	}
	int n=i;
    in.close();
	return n;
}
void func2(char** ma,int n,char* ar1,int* ar2,int* ar3)
{
	int k=0;
	ofstream out("Result1.txt",ios::app);
	for(int i=0;i<n;++i)//вместо 1 н
	{
		int m=strlen(ma[i]);
        for(int j=0;j<m-1;++j)
		{
		    if(ma[i][j]==ma[i][j+1])
			{
				k++;
			    ar1[i]=ma[i][j];
			    ar2[i]=k+1;
			}
		}
		k=0;
	}
	cout<<endl<<endl;
	out<<endl<<endl<<"Simvol Dlina"<<endl;
    for(int i=0;i<n;++i)
	{
		cout<<ar1[i]<<" - "<<ar2[i]<<endl;
		out<<ar1[i]<<"   -   "<<ar2[i]<<endl;
	}
		out.close();
}
int compa( int &x,  int &y)
{
	return (x > y) ? 1 : (( x == y) ? 0 : -1);
}
void func3(int* ar2,int n)
{
	qsort(ar2,n , sizeof(int), (int(*)(const void*, const void*)) compa);
	cout<<endl<<"Sort. massiv dlin"<<endl;
	for(int i=0;i<n;++i)
		cout<<ar2[i]<<" ";
}

void main()
{
	int end;
	char** ma=new char*[100];
	for(int i=0;i<100;++i)
		ma[i]=new char[100];
	char* ar1=new char[100];
	int* ar2=new int[100];
	int* ar3=new int[100];
	int n=func1(ma);
	func2(ma,n,ar1,ar2,ar3);
	func3(ar2,n);
	cin>>end;
}