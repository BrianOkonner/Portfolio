#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <ctype.h>
#include <iostream>
//using namespace std;
void main ()
{
   FILE* f;
   f=fopen("Input.txt","r+");
   
   char* h;
   h=(char*)malloc(256*sizeof(char));
   if(!f)
   {
	   printf("Open file foiled.\n");
   }
   int q[20];
   int w=0;
   while (!feof(f))
   {
   int z=256;
	   fgets(h,256,f);
	   while(z!=0)
	   {
		   int u=0;
           while(!isalnum(h[u]))
			   u++;
		   for (int y=0;y<z-u;y++)
				   h[y]=h[y+u]; 
		   int i=0;
		   if (isalnum(h[i]))
		   {
			   
			   int g=0,j=1+i;
			   while (g==0)
			   {
				   if (isalnum(h[j]))
					   j++;
				   else g=1;
			   }
			   z=z-j;
			   char* l;
			   l=(char*)malloc(80*sizeof(char));
			   strncpy(l,h,j-i);
			   int p=atoi(l);
			   printf("%d ",p);
			  for (int y=0;y<z-j;y++)
				   h[y]=h[y+j];
			   q[w]=p;
			   w++;
			   
		   }
	   }
   }
}
/*программа получает массив чисел Типа интеджер, которые находятся в файле input.