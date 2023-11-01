//*жибрик_5*//
#include <iostream>
using namespace std;
#include <string.h>

int main()
{char raz[6]=('.',' ',',','-',';',':','!');
int sim=1;mas[81];i=0;
FILE * infile=fopen("Input.txt","r+");
while(sim!= NULL)
{
	sim=getc(infile);
	mas[i]=sim;
	i++;
}
i=0;
while(mas[i]!=0)
{
     if (mas[i]==mas[i+1])
	 zu[r]=zu[r]+1;
	 else
	 { r++;
	   i++;
	 }
}
int n=r;
r=0;
int max=zu[r];
r++;
while(r<n)
{
	if(max<zu[r])
		max=zu[r];
	else
		r++;
}
cout<<"max_4islo_povtoreni"<<max<<endl;
fclose(Input);
return 0;}





int a[1000];
int n=0;

void My_push(int x)
{
	a[n]=x;
	n++;
}
int My_pop()
{
	if(n!=0)
	{
		n--;
		return a[n];
	}
}
int My_seek()
{
	return a[n-1];
}

int cmp1(const void *a,const void* b)
{
	char* a1=(char*)a;
	char* b1=(char*)b;
	if(*a1<*b1)
		return -1;
	if(*a1>*b1)
		return 1;
	return 0;
}
int cmp2(const void *a,const void* b)
{
	return -cmp1(a,b);
}
