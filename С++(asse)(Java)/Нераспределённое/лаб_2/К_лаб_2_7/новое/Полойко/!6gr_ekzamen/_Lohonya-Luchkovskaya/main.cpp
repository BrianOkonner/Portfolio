//Lohonya-Luchkovskaya, 6group

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


bool sovpadenie (char *a, int k)
{
	for(int i=0; a[i]!=NULL; ++i)
		if((a[i]>='0')&&(a[i]<='9'))
			return true;
		else
			return false;
}


struct node						/* элемент списка */
	{
		int  item;					/* данные */
		node*  next;				/* указатель на следующий элемент */
		node*  prev;				/* указатель на предыдущий элемент */
	};
	/* указатели на первый и последний элементы в списке */
	node *head, *tail;


void InitList()							/* конструктор */
{
	head = 0;
	tail = 0;
}

void Push_front(int n)			/* включить элемент в начало списка */
{
	node* tmp = new node;
	tmp->item = n;
	tmp->prev = 0;
	tmp->next = head;
	if(head)
		head->prev = tmp;
	else
		tail = tmp;
	head = tmp;
}

void Print ()			//Печать содержимого 
{
	node* temp = head;
	
	while (temp)
	{
		cout<<temp->item<<endl;
		temp = temp->next;
	}
}



int main()
{
    setlocale(LC_ALL,".1251");

	char*string;
	string=new char[100];

	char **Array=new char*[100];
    for( int z=0; z<100; ++z)
		Array[z]=new char[100];

	int sovp; //dlia proverki na chislo

    FILE *fin = fopen("Input.txt","r");
    FILE *fout = fopen("Out.txt","w");

	if ((!fin)||(!fout))
    {
		printf("файл не открывается\n");
        return 1;
    }

	fputs("матрица состоит из 8 строк:\n", fout);

 
	int k; //k=kol-vo vsex slov


	int	**A, n=20;
	int i1, j1;
	int n1=10;

	A =  (int**)malloc(n1 * sizeof(int*));
	/* если ошибка, то выходим из программы */
	if (!A)
	{
		printf("ошибка");
		return 0;
	}
	/* выделяем память для строк */
	for (i1 = 0; i1 < n1; ++i1)
	{
		A[i1] = (int*)malloc(n1 * sizeof(int));
		/* если ошибка, то освобождаем память
		 и выходим из программы */
		if (!A[i1])
		{
			for (j1 = 0; j1< i1; ++j1)
				free(A[j1]);
			free(A);
			printf("ошибка\n");

			return 1;
		}
		
	}


	int	**Matr, v=20;
	int i, j;

	Matr =  (int**)malloc(v * sizeof(int*));
	/* если ошибка, то выходим из программы */
	if (!Matr)
	{
		printf("Error: there is no memory.");
		return 0;
	}
	/* выделяем память для строк */
	for (i = 0; i <v; ++i)
	{
		Matr[i] = (int*)malloc(v * sizeof(int));
		/* если ошибка, то освобождаем память
		 и выходим из программы */
		if (!Matr[i])
		{
			for (j = 0; j < i; ++j)
				free(Matr[j]);
			free(Matr);
			printf("Error: there is no memory.\n");

			return 1;
		}
	}


	char seps[]   =" ,.;:";

	while(!feof(fin))  
	{
		fgets(string, 100, fin);

		char*p;
		p=strtok(string, seps);
	    Array[0]=p;
	    k=1;
		int sch=1;  //dlia spiska
        
		while(p=strtok(NULL, seps))
		{
			Array[k++]=p;
			int k1=k-2;
			int len_word=strlen(Array[k1]);
			if(sovp=sovpadenie(Array[k1], len_word))
			{
				fputs(Array[k1], fout);
			    fputs("\n", fout);
				int chislo = atoi(Array[k1]);   //chislo
                    
				int t=0;
				Matr[0][t]=chislo;
				t++;
                
				int N=0;



               // if (chislo%3==0)
				//{
				//	int chislo1=chislo;
				//	while (chislo1>0)
				//	{
				//		=chislo1 % 10;
//
				//	}
//
//
//
//				}

				//Push_front(chislo);
				//Print();
				//fputs("/n", fout);
				//Push_front(chislo);
				//cout<<Peek();
				sch++;
				printf("%d\n", chislo);
			}
		}
		//while(sch)
		//{
		//	Print();
		//	sch--;
		//}

     }

    for(int l=0; l<v; ++l)
	{
		for(int f=0; f<v; ++f)
			fscanf(fout, "%5d", Matr[l][f]);
		fscanf(fout,"\n");
		//printf("%5d", Matr[l][f]);
		//printf("\n");
	}

	delete string;
	/*for (int r=0; r<100; ++r)
	{
		delete[]Array[r];
		delete[]Array;
	}*/

	/*(for(int r=0; r<20; ++r)
		free(A[r]);
	free(A);*/

	for(int r=0; r<20; ++r)
		free(Matr[r]);
	free(Matr);

return 0;
}