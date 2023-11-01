/*
*   программа написана Щипановым Сергеем
*    1 курс 5 группа
* 
*   21 января 2010
*/



#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "LList.h"



/*
* функция взятия квадратов
*/
int *Quadred(int *a,int n)
{
	int *mtx=new int [n];
	for (int i=0; i<n;i++){
		int s=0,b=a[i],n=1;

	for(;;)
	{
		while(b)
		{
		s+=(b%10)*(b%10);
		b/=10;
		}
		if(s==4){
		mtx[i]=n;
		break;
		}
			
		if(s==1){
		a[i]=0;
			break;
		};
		b=s;
		s=0;
		n++;
	}

	}
return mtx;
}


/*
*рекурсивная функция
*/
int sear(int a)
{
if(!a)return 0;
int b=a%10;
if (b%2==0) return 1 + sear(a/10);
if (b%2) return 0 + sear(a/10);
}



/*
* указательная функция сортировки 
*/
int sort(const void *a, const void *b)
{
int n = *(int*)a;
n=sear(n);
int m =*(int*)b;
m=sear(m);
return n-m;
}





using namespace std;




void main()
{

	/*потоки файлов*/
ifstream fin("input.txt");
ofstream fout("output1.txt");
LList Quie;
int a;
bool four=true;
while (!fin.eof())
{
fin>>a;
Quie.push(a);
}

int eax=Quie.count();
int *matrix = new int [eax];
int *matrix1 = new int [eax];

for (int i=0;i<eax;i++)
{matrix[i]=Quie.pop();
 matrix1[i]=matrix[i];
};

for (int i=0; i<eax;i++)

qsort(matrix,eax,4,sort);

cout<<endl;
fout<<"Source num      "<<"Sorted num"<<endl;
for (int i=0; i<eax;i++)
fout<<matrix1[i]<<"               "<<matrix[i]<<endl;
int *ebx=Quadred(matrix1,eax);

ofstream fout2("output2.txt");
fout2<<"Source num          "<<"repet        "<<"Sorted num"<<endl;
for (int i=0; i<eax;i++)
if(matrix1[i]!=0) fout2<<matrix1[i]<<"                   "<<ebx[i]<<"               "<<matrix[i]<<endl;;

fin.close();
fout.close();
fout2.close();
return;
}