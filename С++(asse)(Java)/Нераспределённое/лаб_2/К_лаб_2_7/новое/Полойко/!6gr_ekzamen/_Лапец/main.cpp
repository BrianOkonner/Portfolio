/*Лапец */
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int powint(int c, int n)
{int i=1;
for(i;i<n;i++)
c=c*c;
return c;
}
int main()
{
char a[80];
char *r;
char raz[]=" ,.;:";
int s[100],n,t=0,i=0,N,h=0,j=0;
int B[100];
int A[100];
int **Matr;
FILE* in;
if(!(in = fopen("input.txt", "r")))
	{
		printf("Open file failed.\n");
		return 1;
    }
FILE* out;
if(!(out = fopen("output.txt", "w")))
	{
		printf("Open file failed.\n");
		return 1;
	}
do
{
a[t]=fgetc(in);
t++;
r=strtok(a,raz);
s[j]=atoi(r);
}
while(!feof(in));
i=0;
while(i<j)
{
s[i]=t;
if (s[i]%3==0)
{
while (h!=153)
{
while (t!=0)
{
B[i]=t-t/10;
t=t/10;
n++;
i++;
} 
for(n,i=0;n>0;n--,i++)
h=h+powint(B[n-1],3);
A[i]=h;
}
N=i+1;
}
}
Matr=new int*[50];
for(i=0;i<50;i++)
Matr[i]=new int[50];
fclose(in);
fclose(out);
return 0;
}



   