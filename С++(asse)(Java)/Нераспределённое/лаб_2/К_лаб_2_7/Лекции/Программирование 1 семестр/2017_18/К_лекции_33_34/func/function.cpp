#include <stdlib.h> 
#include <string.h> 
#include <math.h>
extern double sin(double);
extern double cos(double);
extern double tan(double);
char *names[] =
{ "sin","cos","tan",NULL};         // ������ ���� (��������� �� ������)

double (*pf[])(double) =
{ sin, cos, tan};                    // ������ ������� (������ �������)

//---- ����� ������� �� ����� �� ��������� ������
double call_by_name(char *pn, double arg) 
{
for ( int i=0; names[i]!=NULL; i++)
          if (strcmp(names[i],pn) == 0) { // ��� ������� -
     return ((*pf[i])(arg));     // ����� ������� �� i-��
     }                            // ��������� � ������� pf
return 0.;
}			
int* AddI(int *x, int *y)
{ int *p;
  p= (int*)malloc(4) ;
   *p=(*x+*y);
	return p;
}
double* AddD(double *x, double *y)
{ double *p;
  p= (double*)malloc(8) ;
   *p=(*x+*y);
	return p;
}
double addD(double x, double y)
{ return(x+y);}
int addI(int x, int y)
{ return(x+y);}

