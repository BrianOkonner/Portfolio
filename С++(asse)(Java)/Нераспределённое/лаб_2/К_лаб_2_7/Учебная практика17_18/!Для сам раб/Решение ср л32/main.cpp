
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Input(  char s[], char *c )
{
	FILE *in;
//  FILE *in -  указатель на файл 
        if ((in = fopen("input.txt", "r") ) != NULL) 
	  {   *c =(char) getc(in);  // return int 
		
         fgets(s,2,in);        // next line
		 fgets(s,80,in); 
          fclose(in);  /* закрываем фаил */
   }
   else 
   printf (" Файл не открывается\n");
}

void Poisk( char s[], char c, char sn[])
{	
  char *p1=strchr(s,c);
  char *p2=strrchr(s,c);
   strncpy(sn,p1,p2-p1+1);
   sn[p2-p1+1]=0;
}
void PoiskAsm( char s[], char c, char sn[])
{
	int len=strlen(s);
	_asm
{  
//	  search first 
	 push ds
	 pop es
     mov edi,s     //источник: ES:DI
     mov ecx,len
     mov al,c
repne scasb     // ;сравнивает пока СХ<>0 и ZF=0
//	  search last 
     mov esi,edi
   	 dec esi
repne scasb
//	  move 
     mov ecx,edi
	 sub ecx,esi
	 inc ecx
     mov edi,sn
rep  movsb  	 
}   
}
int SumAsm( int a[], int n)
{
	int s;
	_asm
{    mov eax,0     
     mov ecx,n
    mov ebx,a
 //lea  ebx,a 
for1: 
     add eax,[ebx]
	 add ebx,4
	 loop for1
	 mov s,eax
	}
return s;  	 
}


void Convert(  const char *s, int a[],int *n)
{	
	//r=atoi(s4[1]); //ошибка
  char *tail;
  int next;
  next = strtol (s, &tail, 0);
  if (*tail !=0) 
	  printf ("Error\n");
  else
   printf ("%d\n",next);
  *n= strlen (s);
  for (int i=0;i<*n;i++)
	  a[i]=s[i]-'0';

	  // for (int i=0;i<*n;s++,i++) 
       //a[i]=*s-'0';
}
int compare(const int* x, const int* y)
{
	return (*x > *y) ? 1 : (( *x == *y) ? 0 : -1);
}

int comp(const void* a, const  void * b)
{ int *x=(int*)a;
int *y=(int*)b;
	return (*x > *y) ? 1 : (( *x == *y) ? 0 : -1);
}
int compa( int &x,  int &y)
{
	return (x > y) ? 1 : (( x == y) ? 0 : -1);
}
void sort(int a[],int n) 
{
   int t;
	for (int i=0;i<n-1;i++)
		for (int j=n-1;j>i;j--)
			if (a[j]<a[j-1])
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
}


void main()
{
   char *s1,*s2,s3[]="1234567185",s4[]="000000000000";
   char c;
   int i,j;
   s1= (char*) malloc(10);
   s2= (char*) malloc(10);

     int ch='5';
	 unsigned  char ch1;
	 char ch2;

     Input(  s1, &ch2 ) ;
     printf("%c\n",ch2);	
	  printf("%s\n",s1);
	  
  //   Poisk( s3,ch, s4);
	// printf("%s\n",s4);	

	 PoiskAsm( s3,ch, s4);
	 printf("%s\n",s4);	

     int a[10],n;
	 Convert( s4, a,&n);
     for (i=0;i<n;i++)
	   printf("%d ",a[i]);

	 
	//qsort(a, n, sizeof(int), (int(*)(const void*, const void*)) compare);
//qsort(a, n, sizeof(int), comp);
//qsort(a, n, sizeof(int), (int(*)(const void*, const void*)) compa);
	 printf( "The sorted array:\n");
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);


printf("\n");	
int r= SumAsm( a,n);
	printf("%d ", r);
	printf("\n");	
sort(a,n);
 printf( "The sorted array:\n");
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	
	}
