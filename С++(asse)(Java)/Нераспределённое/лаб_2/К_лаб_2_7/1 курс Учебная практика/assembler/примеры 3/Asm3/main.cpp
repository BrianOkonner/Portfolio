
 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
#include "func.h"
extern	"C" int	_cdecl SubInt(int, int,int*,int*);
extern	"C" int	_cdecl SumAInt(int[], int,int*);
using  namespace std;
 void main()
{
int x,y,k1,k2;
printf ("Enter 2 number");
scanf("%d%d",&x,&y);
int r=SubInt(x, y,&k1,&k2);
//  в стеке сначала y потом x
cout<<"difference="<<r; 
cout<<k1<<"="<<k2<<endl; 
int *a,b[20],n,i,k;
Rnd_array(b, &n);
Print_array(b, n);
SumAInt(b,n,&k);
printf ("summa=%d\n",k); 
 }