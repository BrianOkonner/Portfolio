// main.cpp : Defines the entry point for the console application.
//Степкова Анастасия 6 группа

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
	int item;
	node *next;
	node *prev;
};
node *head;
node *tail;
void init()
{
	head = NULL;
	tail = NULL;
}
bool is_empty()
{
	if(head==0)
		return true;
	else return false;
}
void push_front(int a)
{
	node *tmp;
	tmp=new node;
	tmp->item = a;
	tmp->next = head;
	tmp->prev = NULL;
	if(head)
		head->prev = tmp;
	else
		tail = tmp;
	head = tmp;
}
void push_back(int a)
{
	node *tmp;
	tmp = new node;
	tmp->item = a;
	tmp->next = NULL;
	tmp->prev = tail;
	if(tail)
		tail->next = tmp;
	else
		head = tmp;
	tail = tmp;
}
void insert(int a,int pos)
{
	node *tmp;
	tmp = new node;
	tmp->item = a;
	node *ptmp = head;
	if(ptmp==NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		head = tmp;
		tail = tmp;
	}
	for(int i=1;(i<pos-1)&&(ptmp->next);i++)
		ptmp = ptmp->next;
	if(ptmp->next==NULL)
	{
		ptmp->next = tmp;
		tmp->prev = head;
		tmp->next = NULL;
		tail = tmp;
	}
	ptmp->next->prev = tmp;
	tmp->next = ptmp->next;
	ptmp->next = tmp;
	tmp->prev = ptmp;
}
int remove(int pos)
{
	//node *tmp = tail;
	node *tmp = head;
	for(int i=0; i<pos; i++)
	{
		if(tmp==NULL)
			return 0;
		tmp = tmp->prev;
	}
	tmp->next->prev  = tmp->prev;
	if(tmp->prev!=0)
		tmp->prev->next = tmp->next;
	int res = tmp->item;
	delete tmp;
	return res;
}
int pop_front()
{
	if(head)
	{
		int res = head->item;
		node *tmp = head;
		if(head->next)
			head->next->prev = NULL;
		else
			tail = NULL;
		head = head->next;
		delete tmp;
		return res;
	}
	else
		return 0;
}
int pop_back()
{
	if(tail)
	{
		int res = tail->item;
		node *tmp = tail;
		if(tail->prev)
			tail->prev->next = NULL;
		else
			head = NULL;
		tail = tail->prev;
		delete tmp;
		return res;
	}
	return 0;
}

int sum_kybi(int a)
{
	int b = 0, c, k;
	while(a)
	{
		c = a%10;
		k = c;
		for(int i=1; i<3; i++)
			k*=c;
		b+=k;
		a/=10;
	}
	return b;
}
int* sort(int *mas, int k)
{
	int **matr;
	int *tmp;
	int m = 0, n = 0, ch, i = 0, j, z;
	tmp = (int*)malloc(100*sizeof(int));
	matr = (int**)malloc(20*sizeof(int*));
		for(z=0; z<20; z++)
			matr[z] = (int*)malloc(20*sizeof(int));
	
	for(i=0; i<k; i++)
	{
		matr[i][0] = mas[i];
		matr[i][1] = mas[i]%10;
	}
	for(i=0; i<k; i++)
		for(j=k-1; j>i; j--)
			if(matr[j][1]<matr[j-1][1])
			{
				tmp = matr[j];
				matr[j] = matr[j-1];
				matr[j-1] = tmp;
			}
	for(i=0; i<k; i++)
	{
		tmp[i] = matr[i][0];
	}
	for(z=0; z<20; z++)
		delete[]matr[z];
	delete[]matr;
	free(tmp);
	return tmp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	FILE *in;
	FILE *out;
	char *str, *s;
	char *str2 = " ,.;:";
	char **L;
	int **Matr;
	int *K;
	int i, flag = 1, ch, k, a, A, B = 0, m = 0, n = 0, p, r = 2, cnt = 0, z, l = 0, t=0;
	
	str = (char*)malloc(90*sizeof(char));
	s = (char*)malloc(200*sizeof(char));
	K = (int*)malloc(100*sizeof(int));
	Matr = (int**)malloc(20*sizeof(int*));
		for(z=0; z<20; z++)
			Matr[z] = (int*)malloc(20*sizeof(int));
	L = (char**)malloc(20*sizeof(char*));
	for(z=0; z<20; z++)
		L[z] = (char*)malloc(20*sizeof(char));
	if(!fopen_s(&in, "Input.txt", "r+"))
	{
		fopen_s(&out, "Output.txt", "w+");
		while(!feof(in))
		{
			fgets(str, 85, in);
			s = strtok(str, str2);
			for(i=0; s[i]!='\0'; i++)
				if((s[i]>='0')&&(s[i]<='9'))
					flag = 1;
				else
					flag =0;
			if(flag == 1)
			{
				ch = atoi(s);
				fputs(s, out);
				fputc(' ', out);
				push_front(ch);
				Matr[m][n++] = ch;
			}
			s=strtok(NULL,str2);
			while(s)
			{
				if(s[i]!='\0')
				{
					for(i=0; s[i]!='\0'; i++)
						if((s[i]>='0')&&(s[i]<='9'))
							flag = 1;
						else
						{
							flag =0;
							break;
						}
				if(flag == 1)
				{
					ch = atoi(s);
					fputs(s, out);
					fputc(' ', out);
					push_front(ch);
					Matr[m][n++] = ch;
				}
				i = 0;
				s=strtok(NULL,str2);
				}
			}	
			
		}
	}
	else
		printf("Невозможно открыть исходный файл!!!!");
	m++;
	n = 0;
	p = m+2;
	fputs("\n", out);
	while(!is_empty())
	{
		a = pop_back();
		if(a%3==0)
		{
			K[l++] = a;
			Matr[m][n++] = a;
			A = a;
			Matr[p][1] = a;
			while(B!=153)
			{
				B = sum_kybi(A);
				A = B;
				cnt++;
				Matr[p][r++] = A;
				Matr[p][0] = cnt;
			}
			Matr[p][r] = sum_kybi(A);
			p++;
			r = 0;
		}
	}
	Matr[2] = sort(Matr[1], n);

	
		
	free(str);
	free(s);
	free(K);
	fclose(in);
	fclose(out);
	for(z=0; z<20; z++)
		delete[]Matr[z];
	delete[]Matr;
	for(z=0; z<20; z++)
		delete[]L[z];
	delete[]L;
	_getch();
	return 0;
}

