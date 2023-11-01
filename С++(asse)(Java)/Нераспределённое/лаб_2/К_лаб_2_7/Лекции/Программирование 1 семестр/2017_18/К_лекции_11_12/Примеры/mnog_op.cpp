// Многозначные вычисления 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int  maxsize=100;
void RndArray(int *a,int  *n, int lim)
{   //Заполнение массива случаными числами
   printf("Enter count number");
   scanf("%d",n);
   
   for( int i=0;i<*n;i++)                  
     a[i]=rand()%lim;
}
void WriteArray(int *a,int n)
{   //Вывод чисел массива 
   for( int i=0;i<n;i++)                 
     printf("%d",a[i]);
   printf("\n");
}
 void Revers(int *a,int n)
{   
  int k;        
  // Обмен элементов  массива                       
 for (int i=0;i<n/2;i++)
 {
   k=a[i];
   a[i]=a[n-i-1];
   a[n-i-1]=k; 
 } 
 }
int Eq(int a[maxsize],int b[maxsize],int n, int m)
{
  int i;
     if (n<m) return -1;
     if (n>m) return 1;
     if (m==n)
	{
		i=0;
         while (i<n && a[i] == b[i]) 
			 i++;
         if (i == n)  return 0;
		 else 
            if (a[i]<b[i])  return -1;
		    else return 1;	 
	 }

}
         

void  AddLong (int a[maxsize],int b[maxsize],int c[maxsize],int n, int m, int *k)
// Сложение многозначных
{ int i,tmp;
 for(i=0;i<maxsize;i++)
    c[i]=0;
 for( i=n;i<maxsize;i++)
    a[i]=0;
 for( i=m;i<maxsize;i++)
    b[i]=0;
 Revers(a,n);
 Revers(b,m);
 if (n>m) tmp=n;
 else tmp=m;

 for ( i=0;i<tmp;i++)
 { 
  c[i]=c[i]+a[i]+b[i];
  if (c[i]>10)
  {
    c[i+1]=c[i+1]+1;
	c[i]=c[i] % 10;
  }
}           
  if (c[tmp] != 0) tmp++; 
  Revers(c,tmp);
  *k=tmp; 
}

void  MulLong (int a[maxsize],int b[maxsize],int c[maxsize],int n, int m, int *k)
// Сложение многозначных
{ int i,j,tmp;
 for(i=0;i<maxsize;i++)
    c[i]=0;
 for( i=n;i<maxsize;i++)
    a[i]=0;
 for( i=m;i<maxsize;i++)
    b[i]=0;
 Revers(a,n);
 Revers(b,m);

 tmp=n+m;

 for ( i=0;i<n;i++)
   for (  j=0;j<m;j++)
    c[i+j]=c[i+j]+a[i]*b[j];

 for ( i=0;i<tmp-1;i++)
   {
     c[i+1]=c[i+1]+	c[i]/10;
	 c[i]=c[i] % 10;
   }           

 while (c[tmp] == 0)  
 	 tmp--; 
   *k=tmp+1; 
   Revers(c,*k);
 
}

void  SubLong (int a[maxsize],int b[maxsize],int c[maxsize],int n, int m, int *k)
// Вычитание многозначных
{ int i,tmp;
 for(i=0;i<maxsize;i++)
    c[i]=0;
 for( i=n;i<maxsize;i++)
    a[i]=0;
 for( i=m;i<maxsize;i++)
    b[i]=0;
 Revers(a,n);
 Revers(b,m);

 if (n>m) tmp=n;
 else tmp=m;

for ( i=0;i<tmp;i++)
   c[i]=a[i]-b[i];
 
for ( i=0;i<tmp;i++)	
  if (c[i]<0)
  {
    c[i+1]=c[i+1]-1;
	c[i]=c[i] + 10;
  }
 //if (c[tmp] == 0) tmp--;  
  Revers(c,tmp);
  *k=tmp; 
}
    

void  SubLongZ (int a[maxsize],int b[maxsize],int c[maxsize],int n, int m, int *k)
//  Вычитание с проверкой многозначных
{ int i,tmp,tmp1;
 for(i=0;i<maxsize;i++)
    c[i]=0;
 for( i=n;i<maxsize;i++)
    a[i]=0;
 for( i=m;i<maxsize;i++)
    b[i]=0;
 
 tmp1=Eq(a,b,n,m);
 Revers(a,n);
 Revers(b,m);
 
 if (n>m) tmp=n;
 else tmp=m;

if (tmp1 == 0) tmp = 1;
else 
  if (tmp1 == -1) 
  {
	  for ( i=0;i<tmp;i++)
	  c[i]=b[i]-a[i];
  }
  else
  {
	  for ( i=0;i<tmp;i++)
	  c[i]=a[i]-b[i];
  }
 
for ( i=0;i<tmp;i++)
 { 
  if (c[i]<0)
  {
    c[i+1]=c[i+1]-1;
	c[i]=c[i] + 10;
  }
}           
 Revers(c,tmp);
  *k=tmp; 
}
    

void  pown_m(int *a,int n, int m)
/*	Возведение числа M в степень N  */
{  int i,j;
 for(i=0;i<maxsize;i++)
    a[i]=0;
 a[maxsize-1]=1;
 for( i=0;i<n;i++)
 {
  int  per=0; 
   for(  int j=maxsize-1; j>0;j--)
   {
     int k=a[j]*m+per;
     per=k / 10;
     a[j]=k % 10;
   }
 }
  i=maxsize;
  Revers (a,maxsize);

 while (a[i]==0)
	 i--; 

 
  for( j=i;j<i;j++)
	  printf("%d",a[j]);

 
}


 void main (void)
 {

 int a[maxsize],b[maxsize],c[maxsize];
 int i,j,k,n,m,per;
 
 
 RndArray(a,&n,10);
 RndArray(b,&m,10);
   
 WriteArray(a,n);
 WriteArray(b,m);

 
 int r= Eq (a,b,n,m);	

//AddLong (a,b,c,n,m,&k);
//WriteArray(c,k);
//if (r==-1 )
//   SubLongZ (a,b,c,n,m,&k);
// else
 //  SubLong (a,b,c,n,m,&k);
//WriteArray(c,k);

MulLong (a,b,c,n,m,&k);
WriteArray(c,k);


  pown_m(a,5,  5);
//	  WriteArray(c,k);
 printf("\n");

 
 }
