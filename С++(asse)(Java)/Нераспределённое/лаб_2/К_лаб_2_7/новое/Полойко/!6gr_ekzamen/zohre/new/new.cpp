#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	int i,j,n,g[80];
	char **m,*m1,a[80],b[80];
	m= new char* [80];
	int c[100];
FILE*T;  
	if(!(T=fopen("input.txt","r")))
	{
		cout<<"error,not found file"<<endl;
		return 0;
	}
	FILE*R;
	if(!(R=fopen("result.txt","w")))
	{
		cout<<"error,not enough space"<<endl;
		return 0;
	}
	i=0;
	fgets(a,80,T);
	while(!(feof(T)))

	{
		m1=strtok(a," ");
		while(m1!=NULL)
		{
			m[i]=m1;
			m1=strtok(NULL," ");
			
			i++;
		}
		fgets(a,80,T);
	}
	for (j=0;j<i;j++)
	{
		c[j]=atoi(m[j]);
		fputs(m[j],R);
		fputs(" ",R);
	}
	int l=0;
	for(j=0;j<i;j++)
	{
		n=c[j]%3;
		if(n==0)
		{ 
			b[l]=c[j];
			cout<<c[j]<<" ";
			fputs(c[j],R);
			fputs(" ",R);
			l++;
		}
	}
	int s=0,d=0,x,y,p;
	for(j=0;j<l;j++)
	{
		x=b[j];
		while (d!=153)
		{	
			while (y!=0)
			{
				y=x%10;
				if(y==0)
				{
					d=d+(x*x*x);
				}
				d=d+(y*y*y);
				x=x\10;
			}
			g[s]=d;
			x=d;
			s++;
		}
		p=s+1;
		cout<<p<<"  ";
		fputs(p,R);
		fputs("  ",R);
		for(p=0;p<=s;p++)
		{
			cout<<g[p]<<" ";
			fputs(g[p],R);
			fputs(" ",R);
		}
	}
	fclose(T);
	fclose(R);
	cout<<"too see answer please open file result"<<endl;
	return 0;
}