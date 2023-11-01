/*{  Программа которая переводит целое число из десятичной системы счисления
в систему счисления с другим основанием(от двоичной до шестнадцатиричной)
с точностью до десяти знаков после запятой.}
*/
 
#include <stdio.h>
#include <math.h>
 void Revers(char *a,int n)
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


 void Psystem(double re, int si ,char s[],int *n)
 {
    int r,i,z=0;
	
    double dre;
      unsigned  char c_c[]="0123456789abcdef";
  
     double y=modf(re,&dre);
	 int x=dre;
	 i=0;
     while (x>=si)
	 {
           r=x % si;
           x=x / si;
           s[i]=c_c[r];
		   i++;
     }
	   s[i++]=c_c[x];
	   Revers(s,i);
      if (y!=0)
	  {
       s[i++]='.';
       z=0;
       do
	   {      re=modf(re,&dre);
              re = re*si;
			  int j=re;
              s[i++]=c_c[j];
              z=z+1;
	   }
	   while (re !=0 && z !=10);
	  }
	  *n=i;
 }
 void main(void)
 {
  double re,dre;
  int si,n;
   char s[100];
  printf("Введите основание системы (2..16) :");
     scanf("%d",&si);
     printf("Введите число : ");
     scanf("%lf",&re);
    Psystem(re,si ,s,&n);
 
	   for (int j=0;j<n;j++)
		   printf("%c",s[j]);
	   printf("\n");
	}
     