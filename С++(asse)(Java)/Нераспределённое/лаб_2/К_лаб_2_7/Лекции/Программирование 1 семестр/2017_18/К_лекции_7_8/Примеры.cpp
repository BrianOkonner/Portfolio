#include <iostream>
#include <math.h>
#include <stdio.h>

#include <stdlib.h>//Для вызова функций srand и rand
#include <time.h>//Для вызова функций srand и rand

using namespace std;

int Step(int x,int n)
// Функция для возведение хn ,используя алгоритм представления степени в 2 с/с   
{int r=1;
  while  (n != 0)
 {
	if (n % 2 == 1) r=r*x;
    x=x*x;
	n=n / 2;
 }
  return r;
}


//Поиск количества цифр у числа
 int  count( int  n)
{ 
 int c=0;
 while  (n > 0) 
 {   n = n / 10; 
      c++;  
  } 
return c;
}

// Переворачивание  целого числа. 
int ReversNumber (int b)
{	 setlocale(LC_ALL,".1251");
int  ost ,rev=0;
while(b>0)
{
  ost=b%10;
  b=b/10;
  rev=rev*10+ost;
}
return rev;
}



int CnmR( int n, int m)
 //рекурсивная функция вычисления С из n по m
{
  if (m == 1) 
    return n;
  else
   return CnmR(n, m - 1)*(n - m + 1) / m;
}
int Cnm( int n, int m)
// вычисления С из n по m
{	
 int S=1;
 	for ( int i = 1; i <= m; i++)
		S = S * (n - i + 1) / i;
	return S;
}


int SumDigit (int a)
//Найти количество различных цифр  
//у заданного натурального числа (не используя массивов).
{     int b,c rc=0;
		    for(int i = 0; i<10; ++i)
	 {      c = 0;	b = a;
		while(b>0)
		{
			if(b%10 == i)   c++;
			b /=10;
		}
		if(c!=0) rc++;
	 }
	return rc;       }




void SumDigit (int a)
// Найти количество повторений каждой цифры  
//у заданного натурального числа (не используя массивов).
{
        setlocale(LC_ALL,".1251"); //Для вывода русского текста
	int b = a;
	int c;
	printf ("Повторение цифр у числа %d\n", a);
    for(int i = 0; i<10; ++i)
	 {
		c = 0;
		a = b;
		while(a>0)
		{
			if(a%10 == i)   c++;
			a /=10;
		}
		if(c!=0)
			printf ("%d => %d\n", i, c);
	 }   
}



int BinaryNod(int x,int y)
// Бинарный алгоритм Евклида
//вычисляет наибольший общий делитель двух натуральных чисел
/*
свойства  НОД 
НОД(2m,2n) = 2 НОД(m ,n),
НОД(2m,2n+1) = НОД(m,2n+1),
НОД(-m,n) = НОД(m,n)

Алгоритм

НОД(0, n) = n; НОД(m, 0) = m; 

Если m,n чётные, тогда НОД(m, n) = 2*НОД(m/2, n/2)

Если m чётная, тогда НОД(m, n) = НОД(m/2, n)
 
Если n чётная, тогда НОД(m, n) = НОД(m, n/2). 
Если m,n нечётные и m > n, тогда НОД(m, n) = НОД(m - n, n) 

Если m,n нечётные и m < n, тогда НОД(m, n) = НОД(n - m, m)

Если m = n, тогда НОД(m, n) = m; */
 {
     setlocale(LC_ALL,".1251");//Для вывода русского текста
	 int shift;  int nod;
	//НОД(0, x) = x; НОД(y, 0) = y; 
      if (x == 0 || y == 0)
       return x | y;
      /*  shift = наибольшая степень 2 такая, чтобы  x и y разделились на  2    в этой степени . */
     for (shift = 0; ((x | y) & 1) == 0; ++shift) 
     { 
         x >>= 1;
         y >>= 1;
      }		
while ((x & 1) == 0)
       x >>= 1;
      /* пока  x не станет нечетным */
     do {
         while ((y & 1) == 0)  /* Loop X */
           y >>= 1;
          /* Now x and v are both odd, so diff(u, v) is even.
            Let x = min(u, v), v = diff(u, v)/2. */
         if (x < y) {
             y -= x;
         }
else {
             unsigned int diff = x - y;
             x = y;
             y = diff;
         }
         y >>= 1;
     } while (y != 0);
 
     nod = x << shift;
	 return nod;
 }


int Prime (int a)
// Простые числа.
{ 
 int i, n,flag; 
    double r;
     if ((a==2)||(a==3))
 	  flag =1;
     else
	 {
	  i=2;
	  flag =1; 
	  r=a;
	  n= (int)floor(sqrt (r)); 
      while ((i <=n) &&  flag )
       if (!(a%i)) flag=0;
       else ++i;
	 }
  return flag;
}



void Number_Mersenne( int m)
/*	Числа Мерсенна
	В XVII веке французский математик М. Мерсенн определил
 последовательность чисел вида:
 Mn = 2 в степени n - 1 
Эта последовательность получила наименование "чисел Мерсенна":
1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, ... 
*/
//поиск  N чисел  Мерсенна
{  
  setlocale(LC_ALL,".1251");
  printf("Числа Мерсенна\n");
for (int i=1;i<=m;i++)
{ 
  int r=1,x=2;
  int n=i;
  while  (n != 0)
   {
    if (n % 2 == 1) r=r*x;
     x=x*x;
    n=n / 2;
    }
 r=r-1;
 printf("%d\n",r);
}
}

/*	6.6. Совершенные числа.
 	Большой  интерес  к простым числам Мерсенна вызван их тесной связью с совершенными
	числами.  
    Натуральное число Р называется совершенным, если оно равно сумме  всех своих делителей
	кроме Р.  
 	Евклид  доказал,  что  если  р  и  2^р-1  -  простые  числа, 
        то  число   Р=2^(р-1)*(2^р-1)(значок ^ здесь означает степень) 
	является совершенным.      
	6 
	28
	496
	8128
	33550336
	8589869056
	137438691328
	2305843008139952128
	*/
void Number_Sover ()
{
int p=2,i=1,n,ch;

 setlocale(LC_ALL,".1251");
 printf("Поиск N совершенных чисел: введи N ");
 scanf("%d",&n);

	while (i<=n)
	{ if (Prost(p)&& Prost(Step(2,p)-1))
	{
		ch=Step(2,p-1)*(Step(2,p)-1);
	    cout <<ch<<endl;
		i++;
	}
		p++;
	}


void main ()
{   int x,y; 
// получение случайных чисел
	srand(time(0));
	x=rand()%100;
	y=rand()%1000;
    //  Бинарный поиск Нод 
	int nod= BinaryNod( x,y); 
	printf("Нод %d и %d = %d \n",x,y,nod);

	//Поиск и вывод первых 10 чисел Мерсенна
	Number_Mersenne(10);

    //Поиск и вывод первых n совершенных чисел
	Number_Sover(); 

    //Поиск числа сочетаний
	// Есть рекурсивная функция поиска числа сочетаний
	 int n=7,m=2;
	int r=Cnm(n,m);
	printf("число сочетаний Cnm из %d  по %d = %d \n",n,m,r);

	//Поиск количества повторений каждой цифры  натурального числа 
	SumDigit (23533819);

    // Переворачивание  целого числа.
	r=12345;
    int rv = ReversNumber (r);
    printf("Число %d= ,его перевертыш =%d\n",r,rv);
}