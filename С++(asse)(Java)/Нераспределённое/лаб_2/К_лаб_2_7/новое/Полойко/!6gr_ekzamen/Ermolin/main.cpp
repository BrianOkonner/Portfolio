// main.cpp : Defines the entry point for the console application.
//Ермолин Владислав 6 группа

#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;
struct node						
	{
		int  item;					
		node*  next;				
		node*  prev;				
	};
	node *head, *tail;
void InitList()							
{
	head = 0;
	tail = 0;
}

void RemoveList()							
{
	while(head != 0)
	{
		node* tmp = head;
		head = head->next;
		delete tmp;
	}
	head = 0;
	tail = 0;
}

void push_front(int n)			
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

void push_back(int n)				
{
	node* tmp = new node;
	tmp->item = n;
	tmp->next = 0;
	tmp->prev = tail;
	if(tail)
		tail->next = tmp;
	else
		head = tmp;
	tail = tmp;
}

int pop_front()					
{
	if(head)
	{
		int res = head->item;
		node *tmp = head;
		if(head->next)
			head->next->prev = 0;
		else
			tail = 0;
		head = head->next;
		delete tmp;
		return res;
	}
	return 0;
}

int pop_back()					
{
	if(tail)
	{
		int res = tail->item;
		node *tmp = tail;
		if(tail->prev)
			tail->prev->next = 0;
		else
			head = 0;
		tail = tail->prev;
		delete tmp;
		return res;
	}
	return 0;
}

void insert(int data, int pos)	/* вставить в позицию pos+1 */
{
	node* tmp = new node;
	tmp->item = data;
	node* ptmp = head;
	if(ptmp == 0)
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
    if  (ptmp->next == 0)
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

int remove(int pos)			/* удалить элемент c позиции pos*/
{
	node* ptmp = head;
	for(int i = 0; i<pos; i++)
	{
		if(ptmp == 0)
		{
			return 0;
		}
		ptmp = ptmp->next;
	}
	ptmp->next->prev = ptmp->prev;
	if(ptmp->prev != 0)
		ptmp->prev->next = ptmp->next;
	int res = ptmp->item;
	delete ptmp;
	return res;
}

bool isEmpty()					
{
	return head == 0;
}
void print ()			
{
	node* temp = head;
	
	while (temp)
	{
		cout<<temp->item<<"\n";
		temp = temp->next;
	}
}


/*список*/

int LenghtW(char *p)
{
	int i,k=0;
	for(i=0;;++i)
	{
		if(((*(p+i)<=122) && (*(p+i)>=97)) || ((*(p+i)<=90) && (*(p+i)>=65)) || ((*(p+i)<=57) && (*(p+i)>=48)))
			++k;
		else return k;
	}
} //вычисление длины солва
bool ChisloSlovo2(char *p)
{
	int j,k=0;
	bool flag=false;
		if ((*(p)<=57) && (*(p)>=48))
		{
			for(j=0;j<LenghtW(p);++j)
				if ((*(p+j)<=57) && (*(p+j)>=48))
					++k;
			if (k==LenghtW(p))
			{
				flag=true;
				return flag;
			}
		}
	return flag;
} //проверка на число-слово
int Znachenie(char* c)
{
	int i,k=0;
	for(i=0;i<LenghtW(c);++i)
		k=k*10+((int)*(c+i)-48);
	return k;
} //вычисление значения числа-слова
int RecSum2(int a)
{
	int g=1,temp,k;
	k=0;
	while(a!=0)
	{
		temp=a%10;
		k=k+(temp*temp*temp);
		a=a/10;
	}
	if (k==153)
		return g;
	else
		g+=RecSum2(k);
}/*вычисляет количество элементов необходимой по условию последовательности*/
int RecSum(int *m, int a)
{
	int k=a,temp;
	k=0;
	while(a!=0)
	{
		temp=a%10;
		k=k+(temp*temp*temp);
		a=a/10;
	}
	if (k==153)
	{
		*m=k;
		return k;
	}
	else RecSum( m+1,k);
	*m=k;
} /*вычисляет необходимую последовательность и заносит в массив*/
int Compare(int a, int b)
{
	int k;
	if ((a%10)==(b%10))
		k=0;
	else if ((a%10)>(b%10))
		k=1;
	else if((a%10)<(b%10))
		k=-1;
	return k;
} //функция сравнения двух чисел (по возрастанию последней цифры)
int _tmain(int argc, _TCHAR* argv[])
{
	FILE* stream, *stream1;
	char *s, s1[100];
	int **matr,*f,l[30],i,temp,g=0,k=0,j=0;
	InitList();
	stream1=fopen("Output.txt","w");
	stream=fopen("Input.txt","r");
	while(feof(stream)==0) //заношу слова-числа в список
	{
		s=fgets(s1,100,stream);
		for(i=0;*(s+i)!='\0';)
		{
			if ((*(s+i)<=57) && (*(s+i)>=48) && ChisloSlovo2(s+i))
			{
				push_back(Znachenie(s+i));
				++g;
				i+=LenghtW(s+i);
			}
			else if ((*(s+i)<=57) && (*(s+i)>=48) && !ChisloSlovo2(s+i))
			{
				i+=LenghtW(s+i);
			}
			else if (((*(s+i)<=122) && (*(s+i)>=97)) || ((*(s+i)<=90) && (*(s+i)>=65)))
			{
				i+=LenghtW(s+i);
			}
			else 
				++i;
		}
	}
	matr=(int**)malloc(3*sizeof(int*)); //выделение память для строк матрицы (для 3 строк указателей, возможно надо больше)
	matr[0]=(int*)malloc(g*sizeof(int));
	matr[1]=(int*)malloc(1*sizeof(int));
	for(i=0;i<g;++i) //заполнение первой строки матрицы числоми из списка
	{
		matr[0][i]=pop_back();
	}
	for(i=0;i<g;++i)
	{
		if(matr[0][i]%3==0)
		{
			++k;
			realloc(matr[1],k*sizeof(int));
			matr[1][k-1]=matr[0][i];
		}
	}
	
	matr[2]=(int*)malloc(k*sizeof(int));
	for(i=0;i<k;++i) //копирование в 3 строку матрицы, второй строки
	{
		matr[2][i]=matr[1][i];
	}
	j=k-1;
	while(j!=0) //сортировка элементов 3 строки по возрастанию последней цифры числа (можно сделать отдельной функцией)
	{
		for(i=0;i<j;++i)
		{
			if (Compare(matr[2][i],matr[2][i+1])==1)
			{
				temp=matr[2][i+1];
				matr[2][i+1]=matr[2][i];
				matr[2][i]=temp;
			}
		}
		--j;
	}
	j=0;
	f=new int[3+k]; //выделение памяти под массив, хранящий количество элементов каждой строки динамической матрицы
	f[0]=g;
	f[1]=k;
	f[2]=k;
	cout<<"\n";
	
	while(j<k) //заполнение оставшихся строк динамической матрицы, необходимыми последовательностями
	{
		temp=RecSum2(matr[2][j]);
		matr[3+j]=(int*)malloc(temp*sizeof(int));
		RecSum(l,matr[2][j]);
		for(i=0;i<temp;++i)
			matr[3+j][i]=l[i];
		f[3+j]=temp;
		++j;
	}
	j=0;
	while(j!=3+k) //вывод матрицы на экран
	{
		for(i=0;i<f[j];++i)
		{
			cout<<matr[j][i]<<" ";
			fprintf(stream1, "%d ", matr[j][i]);
		}
		fprintf(stream1,"\n");
		cout<<"\n";
		++j;
	}
	fclose(stream);
	fclose(stream1);
	RemoveList();
	delete [] f;
	_getch();
	return 0;
}

