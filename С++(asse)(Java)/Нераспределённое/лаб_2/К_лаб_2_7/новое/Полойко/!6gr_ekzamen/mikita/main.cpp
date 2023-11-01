//Микита 
#include <stdio.h>;
#include <string.h>;
#include <stdlib.h>;
#include "Spisok.h";
int cub(int &n)
{
	int k,s=0,d;
	k=n;
	while(k>0)
	{
		d=k%10;
		s=s+d*d*d;
		k=k/10;
	}
	return s;
}
bool is_count(char*s)
{
	int l=strlen(s);
	for (int i=0; i<l; ++i)
		if (s[i]<48 || s[i]>57)
			return false;
	return true;
}
int main()
{
	FILE* Input,*Out;
	Out=fopen("Out.txt","w");
	Input=fopen("Input.txt","r");
	int** Matr;
	char* s;
	int d;
	char *p;
	char** a;
	int i=-1,l=-1,z=0,ch,n=3,m;
	int k=0;
	Matr=(int**)malloc(8*sizeof(int*));
	for (int j=0;j<8;j++)
		Matr[j]=(int*)malloc(30*sizeof(int));
	a=(char**)malloc(200*sizeof(char*));
	s=(char*)malloc(80*sizeof(char));
	InitList();	
	while(!feof(Input))
	{
		fgets(s,80,Input);
		p = strtok(s, " ,.;:");
		a[++i]=p;
		if(is_count(a[i]))
		{
			d=atoi(a[i]);
			push_front(d);
			Matr[0][++l]=d;
			z++;
			printf("%d ",Matr[0][l]);
		}
		p = strtok(NULL, " ,.;:");
		while (p)
		{
			
			a[++i]=p;
			if(is_count(a[i]))
				{
					d=atoi(a[i]);
					push_front(d);
					Matr[0][++l]=d;
					z++;
					
				}
			p = strtok(NULL, " ,.;:");
		}
		
	}
	int sp=i;
	l=-1;
	for (int i=0;i<z;i++)
	{
		ch=pop_back();
		if(ch%3==0)
		{
			Matr[1][++l]=ch;
			
		}
	}
	m=2;
	for (int i=0;i<l;i++)
	{
		n=2;
		Matr[m][1]=Matr[1][i];
		
		Matr[m][i+n]=cub(Matr[1][i]);
		
		while (cub(Matr[m][i+n])!=153)
		{
			n++;
			Matr[m][i+n]=cub(Matr[m][i+n-1]);
			
		}
		n++;
		Matr[m][i+n]=cub(Matr[m][i+n-1]);
		Matr[m][0]=n-3;
		m++;
	}
		
		strcpy(s,"\0");
		itoa(m,s,10);
		fputs("Матрица Matr состоит из ",Out);
		fputs(s,Out);
		fputs(" строк\n",Out);
		for (int i=0;i<sp;i++)
		{
			itoa(Matr[0][i],s,10);
			fputs(s,Out);
			fputs(" ",Out);
		}
		fputs("\n",Out);
		for (int i=0;i<l;i++)
		{
			itoa(Matr[1][i],s,10);
			fputs(s,Out);
			fputs(" ",Out);
		}
		fputs("\n",Out);
		int min=10,lk,lkc;
		for (int i=0;i<l;i++)
		{
			lk=i;
			if (Matr[2][i]%3==0)
			{
				if (Matr[2][i]%10<min)
				{
					min=Matr[2][i]%10;
					lk=i;
				}

			}
			if (lk!=i)
			{
				lkc=Matr[2][i];
				Matr[2][i]=Matr[2][lk];
				Matr[2][lk]=lkc;
			}
		}
		for (int i=2;i<m;i++)
		{
			for (int j=0;j<(Matr[i][0]+2);j++)
			{
				itoa(Matr[i][j],s,10);
				fputs(s,Out);
				fputs(" ",Out);
			}
			fputs("\n",Out);
		};
	free (s);
	free (a);
	free (Matr);
	RemoveList();
	fclose(Input);
	return 1;
}
//Микита