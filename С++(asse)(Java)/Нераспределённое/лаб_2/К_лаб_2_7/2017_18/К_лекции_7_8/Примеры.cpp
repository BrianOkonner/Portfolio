#include <iostream>
#include <math.h>
#include <stdio.h>

#include <stdlib.h>//��� ������ ������� srand � rand
#include <time.h>//��� ������ ������� srand � rand

using namespace std;

int Step(int x,int n)
// ������� ��� ���������� �n ,��������� �������� ������������� ������� � 2 �/�   
{int r=1;
  while  (n != 0)
 {
	if (n % 2 == 1) r=r*x;
    x=x*x;
	n=n / 2;
 }
  return r;
}


//����� ���������� ���� � �����
 int  count( int  n)
{ 
 int c=0;
 while  (n > 0) 
 {   n = n / 10; 
      c++;  
  } 
return c;
}

// ���������������  ������ �����. 
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
 //����������� ������� ���������� � �� n �� m
{
  if (m == 1) 
    return n;
  else
   return CnmR(n, m - 1)*(n - m + 1) / m;
}
int Cnm( int n, int m)
// ���������� � �� n �� m
{	
 int S=1;
 	for ( int i = 1; i <= m; i++)
		S = S * (n - i + 1) / i;
	return S;
}


int SumDigit (int a)
//����� ���������� ��������� ����  
//� ��������� ������������ ����� (�� ��������� ��������).
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
// ����� ���������� ���������� ������ �����  
//� ��������� ������������ ����� (�� ��������� ��������).
{
        setlocale(LC_ALL,".1251"); //��� ������ �������� ������
	int b = a;
	int c;
	printf ("���������� ���� � ����� %d\n", a);
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
// �������� �������� �������
//��������� ���������� ����� �������� ���� ����������� �����
/*
��������  ��� 
���(2m,2n) = 2 ���(m ,n),
���(2m,2n+1) = ���(m,2n+1),
���(-m,n) = ���(m,n)

��������

���(0, n) = n; ���(m, 0) = m; 

���� m,n ������, ����� ���(m, n) = 2*���(m/2, n/2)

���� m ������, ����� ���(m, n) = ���(m/2, n)
 
���� n ������, ����� ���(m, n) = ���(m, n/2). 
���� m,n �������� � m > n, ����� ���(m, n) = ���(m - n, n) 

���� m,n �������� � m < n, ����� ���(m, n) = ���(n - m, m)

���� m = n, ����� ���(m, n) = m; */
 {
     setlocale(LC_ALL,".1251");//��� ������ �������� ������
	 int shift;  int nod;
	//���(0, x) = x; ���(y, 0) = y; 
      if (x == 0 || y == 0)
       return x | y;
      /*  shift = ���������� ������� 2 �����, �����  x � y ����������� ��  2    � ���� ������� . */
     for (shift = 0; ((x | y) & 1) == 0; ++shift) 
     { 
         x >>= 1;
         y >>= 1;
      }		
while ((x & 1) == 0)
       x >>= 1;
      /* ����  x �� ������ �������� */
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
// ������� �����.
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
/*	����� ��������
	� XVII ���� ����������� ��������� �. ������� ���������
 ������������������ ����� ����:
 Mn = 2 � ������� n - 1 
��� ������������������ �������� ������������ "����� ��������":
1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, ... 
*/
//�����  N �����  ��������
{  
  setlocale(LC_ALL,".1251");
  printf("����� ��������\n");
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

/*	6.6. ����������� �����.
 	�������  �������  � ������� ������ �������� ������ �� ������ ������ � ������������
	�������.  
    ����������� ����� � ���������� �����������, ���� ��� ����� �����  ���� ����� ���������
	����� �.  
 	������  �������,  ���  ����  �  �  2^�-1  -  �������  �����, 
        ��  �����   �=2^(�-1)*(2^�-1)(������ ^ ����� �������� �������) 
	�������� �����������.      
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
 printf("����� N ����������� �����: ����� N ");
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
// ��������� ��������� �����
	srand(time(0));
	x=rand()%100;
	y=rand()%1000;
    //  �������� ����� ��� 
	int nod= BinaryNod( x,y); 
	printf("��� %d � %d = %d \n",x,y,nod);

	//����� � ����� ������ 10 ����� ��������
	Number_Mersenne(10);

    //����� � ����� ������ n ����������� �����
	Number_Sover(); 

    //����� ����� ���������
	// ���� ����������� ������� ������ ����� ���������
	 int n=7,m=2;
	int r=Cnm(n,m);
	printf("����� ��������� Cnm �� %d  �� %d = %d \n",n,m,r);

	//����� ���������� ���������� ������ �����  ������������ ����� 
	SumDigit (23533819);

    // ���������������  ������ �����.
	r=12345;
    int rv = ReversNumber (r);
    printf("����� %d= ,��� ���������� =%d\n",r,rv);
}