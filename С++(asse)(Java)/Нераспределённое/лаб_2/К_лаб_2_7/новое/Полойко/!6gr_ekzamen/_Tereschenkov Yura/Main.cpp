// Терещенков Юрий 6 группа. Экзаменационная работа.


#include <string.h>
#include "stdio.h"
#include "conio.h"
#include "funkc.h"
#include "iostream"
#include "math.h"
using namespace std;



int main()
{   

  
	int chislo,a,c=0 ,n=0,m=0,A[100], B[100];
	printf ("Vvedite 4islo:\n");
	scanf ("%d", &chislo);
	//printf ("chislo = %d\n",chislo); 
	
	if (chislo % 3 ==0)
		printf ("chislo delitsia na 3\n\n");
	else 
		printf ("\tne delitsia na 3\n");
while (chislo != 153)
{
	while (chislo !=0 )
	{
		a = chislo % 10;
	    A[n]=a;
		chislo = (chislo - a)/10;
		//printf("%d\t", A[n]);
		n++;
    }
	for (int i = 0;i < n;i++)
	{
		c =c+stepen(A[i]);
        
	}
	//printf ("novoe  = %d\n", c);
	
	    B[m] = c;
		m++;
		
	    chislo = c;
	    
		n = 0;
		c = 0;
		
}
printf ("posledovatel'nost' = \n");
for (int k=0;k<m;k++)
{
printf ("%d\t\n", B[k]);
}	
printf ("\n");
printf ("N = %d\n", m);



	

	return 0;

	
}

