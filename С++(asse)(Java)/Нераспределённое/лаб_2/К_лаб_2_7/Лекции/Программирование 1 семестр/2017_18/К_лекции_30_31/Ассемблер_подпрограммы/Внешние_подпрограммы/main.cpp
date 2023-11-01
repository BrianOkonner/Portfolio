
 #include <stdio.h>
 #include <stdlib.h>
#include "func.h"
extern	"C" int	_cdecl SubInt(int, int);
extern	"C" int	_cdecl SumAInt(int[], int,int*);

 void main()
{
int x,y;
printf ("Enter 2 number");
scanf("%d%d",&x,&y);
int r=SubInt(x, y);
//  в стеке сначала y потом x
printf ("difference=%d\n",r); 
int *a,b[20],n,i,k;
Rnd_array(b, &n);
Print_array(b, n);
SumAInt(b,n,&k);
printf ("summa=%d\n",k); 
 }