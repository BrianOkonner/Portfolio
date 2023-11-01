#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

extern	"C" int	_cdecl SumAInt(int[], int,int*);
using  namespace std;
void  Rnd_array (int ar[],int *n)
{
	cout<<"Vvedite kolichestvo elementov massiva"<<endl;
	cin>>*n;
	srand(time(0));
   	for (int i=0;i<*n;i++) 
	    ar[i]=rand()%100;  
	 
 }

 void main()
{ 
	int *a,b[20],n,i,k;
	Rnd_array(b, &n);
	SumAInt(b,n,&k);
	for(int i=0; i<n; i++)
	cout<<b[i]<<" ";
	cout<<endl;
	cout<<"Summa elementov massiva = "<<k<<endl; 
 }
