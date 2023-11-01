#include <iostream>
using namespace std;

char *Fread(FILE* fread)
//  считывание файла
{
	int i;
	char *str;
	str = new char[10000];
	for(i=0;!feof(fread);i++)
	{
		str[i]=fgetc(fread);
	}
	str[i-1]=NULL;
	return str;
}

char *slova_chisla(char* str)
//   Нахождение чисел и запись в строку DArray
{
	char *DArray;
	DArray = new char[1000];
	int i, j;
for(i=0, j=0; str[i]!=NULL; i++)
	{
		if((str[i]>='0')&&(str[i]<='9'))
		{
			if(i==1)
				DArray[j++]=str[i];
			else
				if((str[i-1]<'0')||(str[i-1]>'9'))
					DArray[j++]=str[i];

				else
					if((str[i-1]>='0')&&(str[i-1]<='9'))
						DArray[j++]=str[i];
		}
		else
			if((str[i-1]>='0')&&(str[i-1]<='9'))
				DArray[j++]=' ';
	}
	DArray[j]=NULL;
	return DArray;
}

void sort_int(int *a,int n)        //сортировка методом обмена
{
   int t,i,f,j;
   i=0;
     do
	 {
      f=0;
	    for (j=0; j<n-1; j++)
			if ((a[j]%10)>(a[j+1]%10))
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			    f=1;
			}
      i++;
	 }
	  while (i<n && f);
}


int sum_cub(int g)
{	
	int a=0;
	for(int i=0; g!=0 ;i++)
	{
		a = a + (g%10)*(g%10)*(g%10);
		g = g/10;
	}
	return a;
}
