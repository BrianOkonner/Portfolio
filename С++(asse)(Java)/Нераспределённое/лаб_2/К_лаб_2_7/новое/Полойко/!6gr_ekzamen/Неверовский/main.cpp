//Неверовского Виталия 6гр

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
//чтение из файла в строку
int ReadChFile(  FILE *in, char* filename, char* Line )
{
	 int i=0;
     int ch;
     if ((in = fopen(filename, "r") ) != NULL) 
	 {
         do 
	  {   
		  ch = getc(in);
		  
		 
			Line[i] = ch;
			i++;
		
	  }
	  while (ch  != EOF);
	  
	 }
	
   else 
   printf (" Файл не открывается\n");
	 Line[i-1]=0;
	 return i;

}
//удаление эл-тов не являющихся числом
void _DelSp(char *Line, int k)
{
	int i =0;
	for(; i <= k+1; i++)
	{
		if(Line[i] < 48 || Line[i] > 57)
			Line[i]=' ';
	}
	Line[i]=0;
}
//из строки в массив
int  conv(char* Line, int* Array, int k)
{
int j=0;
int sum=0;
	for(int i=0; Line[i]!= 0; i++)
	{
		if(Line[i] >= 48 && Line[i] <= 57)
		{
		sum=sum*10+(Line[i]-'0');
			if(Line[i+1] == 32)
			{
				Array[j] = sum;
				j++;
				sum=0;
			}
		}
	}
	return j;
}
// постройка последовательности
int posled(int *Array, int **Matrix, int k)
{
	int some;
	int sum=0;
	int posl;
	int j=0;

		for(int i=0, j=0; i < k; i++ )
			{
				j=0;
				some=0;
				posl = Array[i];
				if(Array[i]%3 == 0)
				{
				 while(some != 153)
				 {
					 sum = posl%10;
					sum = sum*sum*sum;
					some +=sum;
					posl /= 10;
					if(posl <= 0)
					{
						Matrix[i][j] = some;
						j++;
						posl = some;
						if(some == 153)
							continue;
						some = 0;
					}

				}
			}
		
	}
		return j;
}

void OutMatrix(int **Matrix, int j)
{
	int k=0;
	for(int i=0; Matrix[i][k] >= 0 ; i++)
	{
		for(k=0; Matrix[i][k] >= 0 ; k++)
		{
			cout << " " <<Matrix[i][k];

		}
			if(Matrix[i][k] < 0)
			k=0;
		cout <<endl;
	}

}



void main()
{
	int Value;
	int k;
	int j;
	char* input;
	char Line[1000];
	int Array[100];

	FILE *in;
	input = ("input.txt");
	
	in = fopen(input, "r");

	ReadChFile(in, input, Line);

	k=ReadChFile(in, input, Line);

	_DelSp(Line, k);

	conv(Line, Array, k);

	j=conv(Line, Array, k);
	
	int **Matrix;
		Matrix=(int**)malloc(j);
			for(int i=0; i< j; i++)
				Matrix[i] = (int*)malloc(j);

	
	
	Value = posled(Array, Matrix, j);

	posled(Array, Matrix, j);
	

	OutMatrix(Matrix, Value);

	fclose(in);
	free (Matrix[j]);
	for(int i=0; i< j; i++)
	free (Matrix[i]);
	_getch();
}
//j - кол-во эл. которые надо преобр. в последовательность