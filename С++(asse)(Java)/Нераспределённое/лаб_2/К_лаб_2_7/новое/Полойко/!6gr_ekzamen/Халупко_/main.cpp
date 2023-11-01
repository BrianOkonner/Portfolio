//Халупко А.И.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>
int CUB(int** M,int m,int y,int a,int b)
{
	if(M[a-1][b-1]=153)
		return 0;
	for(int j=10;y>0;j*=10)
	{
		m+=y%j;
		y=(y-y%10/10);
		m=m*m*m;
		M[a][b++]=m;
	}
	CUB(M,0,m,a,b);
return 0;
}
int comp_int(const int* e1, const int* e2)
{
	return (*e1 < *e2) ? -1 : ((*e1 == *e2) ? 0 : 1);
}
int main()
{
/*char* s=" ,.;:";
char* z="123456789";
int n=0;
int* M;
int u=0;
M=(int*)malloc(10*sizeof(int));
char** S;
S=(char**)malloc(10*sizeof(char));
for(int i=0;i<10;i++)
	S[i]=(char*)malloc(40*sizeof(char));
FILE* in;
in=fopen("Input.txt","r+");
in= fopen("Input.txt", "r+");
	if(!in)
	{
		printf("Open file failed.\n");
		return NULL;
	}
char* h;
char* g;
char* f;
char* b;
int l=0;
f=(char*)malloc(1*sizeof(char));
h=(char*)malloc(256*sizeof(char));
fgets(f,256,in);
int i=0;
while(!feof(in))
{
fgets(h,256,in);
if(*f==*h)
{
	if(!strpbrk(h,s))
	{
		l=strlen(h)-1;
		if(feof(in))
		{
			l++;
		}
	}
	else
		l=strpbrk(h,s)-h;
	b=(char*)malloc(l*sizeof(char));
	strncpy(b,h,l);
	b[l]=0;
	S[i]=b;
	i++;
}
	while((g=strpbrk(h,s)))
	{
	if(*f==*(g+1))
	{
		if(!strpbrk(g+1,s))
		{
		l=strlen(g+1)-1;
		if(feof(in))
		{
			l++;
		}
		}
		else
			l=strpbrk(g+1,s)-g-1;
			b=(char*)malloc(l*sizeof(char));
		strncpy(b,g+1,l);
		b[l]=0;
		S[i]=b;
		if((strpbrk(S[i],z))!=0)
		{
			M[u]=atoi(S[i]);
			printf("%d", M[u]);
		}
		u++;
		i++;
	}
	h=g+1;
	}
}*/
	FILE* out;
	out=fopen("Output.txt","r+");
	int* M;
	int* S;
	int n;
	int no;
	int y=0;
	int** Matr;
	Matr=(int**)malloc(10*sizeof(int));
	for(int i=0;i<10;i++)
		Matr[i]=(int*)malloc(10*sizeof(int));
	printf("Vvedite kolichestvo elemtov:\n");
	scanf("%d",&n);
	M=(int*)malloc(n*sizeof(int));
	S=(int*)malloc(n*sizeof(int));
	printf("Input %d numbers for massive:\n", n);
	int z=0;
	int l=3;
	int u=0;
	int r=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&M[i]);
		Matr[0][i]=M[i];
		if((M[i]%3)==0)
		{
			int m=0;
			Matr[1][u++];
			y=M[i];			
		}
		if((M[i]%3)==0)
		{
			for(;l<u;l++)
			CUB(Matr,0,y,l,r);
		}
	}
		for(int i=0;i<u;i++)
	{
		M[i]=Matr[1][i]%10;
		S[i]=M[i];
	}
	qsort(M,u,sizeof(int),(int (*)(const void*, const void*))comp_int);
	for(int i=0;i<u;i++)
	{
	for(int j=0;j<n;j++)
		{
		if(S[i]=M[j])
		{
			Matr[2][j]=Matr[1][i];
		}
		}
	}
fprintf(out,"Матрница Matr состоит из %d строк\n",l);
for(int i=0;i<n;i++)
{
fprintf(out,"%d", Matr[0][i]);
}
for(int i=0;i<u;i++)
{
fprintf(out,"%d",Matr[1][i]);
}
for(int i=0;i<u;i++)
{
fprintf(out,"%d",Matr[2][i]);
}
	return 0;
}
