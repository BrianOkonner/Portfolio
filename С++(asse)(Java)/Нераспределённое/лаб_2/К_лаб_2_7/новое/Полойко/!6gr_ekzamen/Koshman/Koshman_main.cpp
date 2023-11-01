/*Кошман Екатерина, 1 курс 6 группа, 19.01.2010*/

#include "stdafx.h"
#include "conio.h"
#include "iostream"
#include "stdlib.h"
#include "string.h"
using namespace std;
//#include "Spisok.h"

int c10=10;
//extern "C" int _cdecl Array(int);
//struct elem
//{
//	elem *next;
//	int *value;
//	elem *prev;
//};
//public struct List
//{
//	elem *head, *tail;
//}list;
int sumkub_asm(int a)
{
	int rez,t;
	_asm
	{
		mov		eax, a
		mov		ecx, 0
while1: cmp	eax, 0
		je endw
		cdq
		div		c10
		mov		t, eax
		mov		eax, 1
		mov		ebx, edx
		mul		ebx
		mul		ebx
		mul		ebx
		add		ecx, eax
		mov		eax, t
		jmp		while1
endw:	mov		rez, ecx

	}
	return rez;
}
int sumkub(int a)
{
	if (a==0)
		return 0;
	int c=a%10;
	return (c*c*c+sumkub(a/10));

}
void posled(int A, FILE*output)
{
	int mass[20], n=0;
	int a=A;
	do
	{
		a=sumkub(a);
		mass[n++]=a;
	}
	while(a != 153);
	fprintf(output, "%d %d ", n, A);
	for (int i=0; i<n; i++)
		fprintf(output, "%d ", mass[i]);
	fprintf(output, "\n");
}
int sravn(const void*q1, const void*q2)
{
	int a=(* ((int *)q1))%10;
	int b=(* ((int *)q2))%10;
	return a-b;
}

struct elem
{
	elem *next;
	int value;
	elem *prev;
};

//struct List
//{
//	elem *head, *tail;
//	void InitList() /* конструктор */
//	{
//		head = 0;
//		tail = 0;
//	}
//
//	void RemoveList() /* деструктор */
//	{
//		while(head != 0)
//		{
//			elem* tmp = head;
//			head = head->next;
//			delete tmp;
//		}
//		head = 0;
//		tail = 0;
//	}
//
//	void add_front(int newst) /* включить элемент в начало списка */
//	{
//		elem* tmp = new elem;
//		tmp->value = newst;
//		tmp->prev = 0;
//		tmp->next = head;
//		if(head)
//			head->prev = tmp;
//		else
//			tail = tmp;
//			head = tmp;
//	}
//
//	void add_back(int newst) /* включить элемент в конец списка */
//	{
//		elem* tmp = new elem;
//		tmp->value = newst;
//		tmp->next = 0;
//		tmp->prev = tail;
//		if(tail)
//			tail->next = tmp;
//		else
//			head = tmp;
//		tail = tmp;
//	}
//
//	void del_front() /* исключить элемент из начала списка */
//	{
//		if(head)
//		{
//			elem *tmp = head;
//			if(head->next)
//				head->next->prev = 0;
//			else
//				tail = 0;
//			head = head->next;
//			delete tmp;
//		}
//	}
//	int get_front()
//	{
//		return head->value;
//	}
//	void del_back() /* исключить элемент из конца списка */
//	{
//		if(tail)
//		{
//			elem *tmp = tail;
//			if(tail->prev)
//				tail->prev->next = 0;
//			else
//				head = 0;
//			tail = tail->prev;
//			delete tmp;
//		}
//	}
//	int get_back()
//	{
//		return tail->value;
//	}
//
//	void insert(int data, int pos) /* вставить в позицию pos+1 */
//	{
//		elem* tmp = new elem;
//		tmp->value = data;
//		elem* ptmp = head;
//		if(ptmp == 0)
//		{
//			tmp->next = 0;
//			tmp->prev = 0;
//			head = tmp;
//			tail = tmp;
//			return;
//		}
//		int i = 0;
//		while ((i<pos)&&(ptmp->next))
//		{
//			ptmp = ptmp->next;
//			i++;
//		}
//		if (ptmp->next == 0)
//		{
//			ptmp->next = tmp;
//			tmp->prev = ptmp;
//			tmp->next = 0;
//			tail = tmp;
//			return;
//		}
//		ptmp->next->prev = tmp;
//		tmp->next = ptmp->next;
//		ptmp->next = tmp;
//		tmp->prev = ptmp;
//	}
//
//	void del_poz(int pos) /* удалить элемент c позиции pos*/
//	{
//		elem* ptmp = head;
//		for(int i = 1; i<pos; i++)
//		{			
//			ptmp = ptmp->next;
//			if(ptmp == 0)
//				return;
//		}
//		if (ptmp->next!=0)
//			ptmp->next->prev = ptmp->prev;
//		else
//			tail=ptmp->prev;
//		if(ptmp->prev != 0)
//			ptmp->prev->next = ptmp->next;
//		else
//			head=ptmp->next;
//		delete ptmp;
//	}
//	int get_pos(int pos)
//	{
//		elem* ptmp = head;
//		for(int i = 1; i<pos; i++)
//		{
//			if(ptmp == 0)
//				return 0;
//			ptmp = ptmp->next;
//		}
//		return ptmp->value;
//	}
//
//	bool isEmpty() /* пустой список? */
//	{
//		return head == 0;
//	}
//} list;

char *separ=" ,.;:";
bool is_count(char* a)
//rabotaet
{
	for (int i=0; i<strlen(a); i++)
		if ((a[i]>'9' )||(a[i]<'0'))
			return false;
	return true;
}
void main()
{
	setlocale(LC_ALL, ".1251");
	list.InitList();
	char *string=new char[80], *str=new char[10];
	FILE *input, *output;
	fopen_s(&input, "Input.txt", "r");
	fopen_s(&output, "Out.txt", "w");
	int n=0;


	while (fgets(string, 80, input)!=NULL)
	{
		str=string;
		strtok(string, separ);
		if (is_count(string))
		{
			list.add_back(atoi(string));/////////////////
			n++;
		}
		while ((str=strtok(NULL,separ))!=0)
		{
			if (str[strlen(str)-1]==10)
				str[strlen(str)-1]='\0';
			if (is_count(str))
			{
				list.add_back(atoi(str));///////////////
				n++;
			}
		}

	}
	int ntri=0;
	for (int i=1; i<=n; i++)
	{
		
		if ((list.get_pos(i))%3==0)////////////////
		{
			printf( "%d ", list.get_pos(i));//////////////
			ntri++;
		}
	}
	

	/*char ***Matr=new char**[ntri+4];
	char *sss="Матрица Matr состоит из ";
	strcpy(string, "");
	strcat(string, _itoa(3, ntri+3, 10));
	strcat(string, " строк");
	*Matr= new char*;
	**Matr=string;
	fprintf(output, string);*/

	int *mass=new int[ntri];
	int im=0;
    fprintf(output, "Матрица Matr состоит из %d строк\n", ntri+3);
	for (int i=1; i<=n; i++)
	{
		fprintf(output, "%d ",list.get_pos(i)); ///////////////
		if ((list.get_pos(i))%3==0)
		{
			mass[im++]=list.get_pos(i);
		}
	}
	fprintf(output, "\n");
	for(int i=0; i<im; i++)
		fprintf(output, "%d ", mass[i]);
	fprintf(output, "\n");
	qsort(mass, ntri, sizeof(int), sravn);
	for (int i=0; i<ntri; i++)
		fprintf(output, "%d ", mass[i]);
	fprintf(output, "\n");
	for (int i=0; i<im; i++)
		posled(mass[i], output);

	

	_getch();
	delete[]string;
	delete[]str;
	delete[]mass;
	fclose(input);
	fclose(output);
	list.RemoveList();
	}

