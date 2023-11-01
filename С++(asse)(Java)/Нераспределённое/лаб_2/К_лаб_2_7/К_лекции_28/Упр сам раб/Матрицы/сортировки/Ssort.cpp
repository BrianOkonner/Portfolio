#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream.h>
  void *mid,*t;   //:pchar;
  void  * ra;  
 int   size;
int  count=0;
   
int (*fp) ( const void *x,const void *y); 
// тип функции сравнения двух элементов, заданных 
// своими указателями.
// возвращает -1, если первый "меньше" второго
// возвращает 0 , если первый "равен"  второму
// возвращает +1, если первый "больше" второго
 
int  a[100];
  char *b;
  char **c;
  int   n,i;



int comp(void* x,void* y)
{
	return strcmp(*(char **)x,*(char**)y);
}
void sortwork()
{  int N;
    char **a;
	cout<<"Input N"<<endl; 
    cin>>N;
	a=(char**)malloc(N*sizeof(char*));
		for (int i=0;i<N;i++)
		a[i]=(char*)malloc(sizeof(char*));
	cout<<"Input strings\n";
	for (i=0;i<N;i++) 
		gets(a[i]);
	
qsort(a,N,sizeof(char*),(int (*)(const void*, const  void*))comp);
	for (i=0;i<N;i++)
		puts(a[i]); 
	}



int  Cmpst(const void *s1,const void *s2)	//{ сравнение строк }
{
  return strcmp(*(char **)s1,*(char**)s2);
}

/* функция для сравнения элементов массива */
int Cmpint(const int* e1, const int* e2)
{
	return (*e1 < *e2) ? -1 : ((*e1 == *e2) ? 0 : 1);
}

/* сравнение переменных типа char, переданных с помощью указателей.
При использовании этой функции сортировка будет производиться по 
возрастанию элементов функция для сравнения элементов массива */
int Cmpbytes(const char *c1, const char* c2)
{
	return (*c1 < *c2) ? -1 : ((*c1 == *c2) ? 0 : 1);
}

void  CopyBytes(void *dest,void *source, int count)
{
  //	  побайтное копирование count-байтных полей
  //      из Source в Dest
    _asm
	{
      mov ecx,count
      mov edi,dest
      mov esi,source
      _for:
        mov bl,[esi]
        mov [edi],bl
        inc esi
        inc edi
        loop _for
	}
}
    
  void  QuickSort( int L, int R)
  {
    int  Lo, Hi;
    Lo = L;
    Hi = R;
//    writeln(l:8,r:8);
    CopyBytes((char*)mid,(char*)ra+Lo*size,size);
    do
	{
      while (fp((char*)ra+Lo*size,(char*)mid) <0 )
		   Lo++;	
	  //{использование параметра f - функции сравнения }

      while ( fp((char*)ra+Hi*size,mid)>0) 
		  Hi--;
      if (Lo <= Hi) 
	  {
        CopyBytes ((char*)t,(char*)ra+Lo*size,size);
        CopyBytes ((char*)ra+Lo*size,(char*)ra+Hi*size,size);
        CopyBytes ((char*)ra+Hi*size,(char*)t,size);
        Lo++;
        Hi--;
	  }
	}
    while (Lo <= Hi);
    if (Hi > L) QuickSort(L, Hi);
    if (Lo < R)  QuickSort(Lo, R);
  }

void Sort(  void *pa, int n,int size, int (*fp) (const void *p1, const void *p2))

{

  mid = malloc (size);
  t = malloc (size);
  ra=pa;		// приведение типа указателя к Pchar

  QuickSort(0, n-1);
  free(mid);
   free(t);
}
 void main ()
 {

n=7;
for (i=0;i<n;i++)
{
   a[i]=rand()%10+1;
   printf("%d ",a[i]);
}
printf("\n");
fp=(int (*)(const void*, const void* ))Cmpint;
size = sizeof(int);
Sort(a,n,sizeof(int),(int (*)(const void*, const void* ))Cmpint);

// вызов сортировки массива int
// обратите внимание на передачу параметров
// a - адрес начала массива
// n  - количество элементов
// sizeof(integer) - длина одного элемента
// cmpint - функция сравнения элементов
for (i=0;i<n;i++)
     printf("%d ",a[i]);
printf("\n");
printf("\n");


 n=10;
b = (char*)malloc (n);
 for (i=0;i<n;i++)
{
   b[i]=rand()%12+60;
   printf("%c ",b[i]);
} 
printf("\n");
fp=(int (*)(const void*, const void* ))Cmpbytes;
size = sizeof(char);
 Sort(b,n,sizeof(char),(int (*)(const void*, const void* ))Cmpbytes);  

// вызов сортировки массива byte 

 for (i=0;i<n;i++)
     printf("%c ",b[i]);
printf("\n");
printf("\n");

free(b);

n=3;
	c=(char**)malloc(n*sizeof(char*));
	for (int i=0;i<n;i++)
		c[i]=(char*)malloc(sizeof(char*));
	cout<<"Input strings\n";
	for (i=0;i<n;i++) 
		gets(c[i]);

fp=(int (*)(const void*, const void* ))Cmpst;
size = sizeof(char*);
Sort(c,n,sizeof(int),(int (*)(const void*, const void* ))Cmpst);


// вызов сортировки массива строк 

for (i=0;i<n;i++)
		puts(c[i]); 

 }


