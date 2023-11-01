//экзаменационная работа
//Макаренко Анастасии
//6 группа

#include <stdio.h>
#include <locale>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "iostream"
#include"1.h"


using namespace std;
struct elem
{
	elem *next;//указатель на следующий
	int value;
	elem *prev;//на предыдущий
};
struct List
{
	elem *head, *tail;//указатель на первый и последний элементы списка
	void InitList() //конструктор
	{
		head = 0;
		tail = 0;
	}

	void RemoveList() //деструктор
	{
		while(head)
		{
			elem* tmp = head;
			head = head->next;
			delete tmp;
		}
		head = 0;
		tail = 0;
	}

	void add_front(int n) //включить в начало списка
	{
		elem* tmp = new elem;
		tmp->value = n;
		tmp->prev = 0;
		tmp->next = head;
		if(head)
			head->prev = tmp;
		else
			tail = tmp;
		head = tmp;
	}

	void add_back(int n) //включить в конец списка
	{
		elem* tmp = new elem;
		tmp->value = n;
		tmp->next = 0;
		tmp->prev = tail;
		if(tail)
			tail->next = tmp;
		else
			head = tmp;
		tail = tmp;
	}

	void del_front() //исключить из начала
	{
		if(head)
		{
			elem *tmp = head;
			if(head->next)
				head->next->prev = 0;
			else
				tail = 0;
			head = head->next;
			delete tmp;
		}
	}
	void del_back() //исключить из конца
	{
		if(tail)
		{
			elem *tmp = tail;
			if(tail->prev)
				tail->prev->next = 0;
			else
				head = 0;
			tail = tail->prev;
			delete tmp;
		}
	}

	void insert(int n, int pos) // вставить на pos+1 
	{
		elem* tmp = new elem;
		tmp->value = n;
		elem* ptmp = head;
		if(!(ptmp))//
		{
			tmp->next = 0;
			tmp->prev = 0;
			head = tmp;
			tail = tmp;
			return;
		}
		int i = 0;
		while ((i<pos)&&(ptmp->next))
		{
			ptmp = ptmp->next;
			i++;
		}
		if (!(ptmp->next))//
		{
			ptmp->next = tmp;
			tmp->prev = ptmp;
			tmp->next = 0;
			tail = tmp;
			return;
		}
		ptmp->next->prev = tmp;
		tmp->next = ptmp->next;
		ptmp->next = tmp;
		tmp->prev = ptmp;
	}

	void del_poz(int pos) // удалить с позиции  pos/
	{
		elem* ptmp = head;
		for(int i = 1; i<pos; i++)
		{			
			ptmp = ptmp->next;
			if(!(ptmp))
				return;
		}
		if (ptmp->next!=0)
			ptmp->next->prev = ptmp->prev;
		else
			tail=ptmp->prev;
		if(ptmp->prev != 0)
			ptmp->prev->next = ptmp->next;
		else
			head=ptmp->next;
		delete ptmp;
	}
	bool isEmpty() //пустой ли cписок
	{
		return head == 0;
	}
	void print (FILE *t)
{
	elem* temp = head;
	while (temp)
	{
		cout<<temp->value<<endl;
		fprintf(t,"%\n",temp->value);
		temp = temp->next;
	}
	
}
} list;
int main()
{
	setlocale(LC_ALL,".1251");
	list.InitList();
	int M=0,l=0;
	FILE* Input,*Out;
	Out=fopen("Out.txt","w");
	fputs("Матрица Matr\n",Out);
	if(Input=fopen("Input.txt","r"))
	{
		int*c=(int*)malloc(sizeof(int)*20);
		char razd[]=" ,.;:";
		char* string=new char[81];
		while (fgets(string,81, Input)!=NULL)//работа с файлом
		{
			char*p=strtok(string, razd);
			while (p)
			{
				if((p[0]>='0')&&(p[0]<='0'+9))
				{
					int a = atoi(p);
					list.add_front(a);
					l++;
				}
				p = strtok(NULL, razd);
			}
		}
		
		fclose(Input);
	int h=0;
	int **a;
	a = (int**)malloc(20*sizeof(int*));
	for(int j=0;j<20;j++)
		a[j]=(int*)malloc(25*sizeof(int));
	int *d=(int*)malloc(sizeof(int)*20);
	
	int cout=0;
	for(int i=0;i<20;i++)
	{
		h=list.head.value;
		list.del_front();
		d[i]=h;
		if(!(h%3))
		{
			cout++;
			c[i]=h;
			//posled(h,a,20,25,i);
		}
	}
	////////////////////////
	
	for(int i=0;i<l;i++)
	{
		a[0][i]=d[i];
		if(i<cout)
		{
			a[1][i]=c[i];
		}
	}
	sort(c,cout);
	for(int i=0;i<cout;i++)
		a[2][i]=c[i];
	int *f=(int*)malloc(sizeof(int)*25);
	int j;
	for(int i=0;i<cout;i++)
	{
		int re=posled(c[0],f,25);
		for(j=0;j<=re;j++)
			a[i][j]=f[j];
	}
	M=j+3;
	for(int i=0;i<20;i++)
	{
		for(int k=0;k<j+2;k++)
			fprintf(Out,"%5d",a[i][k]);
	fprintf(Out,"\n");
	}
	fprintf(Out,"Матрица Matr состоит из %d строк\n",M);
	fclose(Out);
	for(int j=0; j<20; j++)
		free(a[j]);
	free(a);
	free(f);
	free(c);
	printf("%d\n",Sumcub(33));
	delete[]string;
	}
	else 
		printf("Файл не открывается\n");
	return 0;
}
//Макаренко Анастасии