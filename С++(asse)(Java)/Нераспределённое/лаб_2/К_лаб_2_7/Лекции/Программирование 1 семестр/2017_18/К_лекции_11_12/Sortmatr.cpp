
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
using namespace std;
int sum(int n)
{
	int s=0;
	while (n>0)
      {
	  s++;
      n/=10;
	  }
	return s;
}

int MaxArray (int *a, int n)
{//Поик наибольшего в массиве
	int max=a[0];
    for (int i = 0;i<n; i++)
	  if (a[i] >max)  
      max=a[i];
      return max;
}  

void ChangeRows (  int  **ma, int  n, int m ,int k, int t) 
{   //Обмен строк матрицы
	int d;
			  	for ( int j = 0; j < m; j++)  
				{ d = ma[k][j];
				  ma[k][j] = ma[t][j];
				  ma[t][j] = d;
				 }
}


void SortRows (  int  *a, int  size,int **ma,int n,int m) 
{//Сортировка строк
 int i, j;
  for( i=0; i < size; i++) 
    // i - номер прохода
    for( j = 0; j<size-i-1; j++ ) 
     // внутренний цикл прохода
      if ( a[j] > a[j+1] )
	  {
       swap( a[j], a[j+1] );
       ChangeRows(ma,n,m,j,j+1);
	  }

}    

void rnd_matr (int **ma, int n, int m)
{	int i,j;	
          	for (i=0;i<n;i++) 
	        	for (j=0;j<m;j++)
	            ma[i][j]=rand()%100;   
}

void print_matr ( int **ma,   int n,int m)
{int i, j; 
      for (i=0;i<n;i++) 
{	
             for (j=0;j<m;j++)
	        cout<<setw(5)<<ma[i][j]; 
			             cout<<endl;
}
}
 void printarray (int *a,int n)
 {
		int i; 
      for (i=0;i<n;i++) 
	        cout<<setw(5)<<a[i]; 
            cout<<endl;

}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int i,j,n,m;
	int **ma;
	int *max;
	cout<< "enter n m";  
	cin>>n>>m; 
	max= new int [m]; 
    ma= new int *[n]; 
    for ( i=0;i<m;i++)
      ma[i]= new int [m];	

	rnd_matr (ma, n, m);
	print_matr (ma, n, m);
	
   for ( i=0;i<n;i++)
      max[i]=  MaxArray (ma[i], m);
   printarray ( max,   n);
   cout<<endl;

   SortRows (  max,n , ma,n, m) ;

   printarray ( max,   n);
   print_matr (ma, n, m);
// Сам работа  лекции 15_10 
   __int64 M,k=0;
   int *b;
   b=new int[20];
   cout<<"M=";
   cin>>M;
   int count=sum(M);
   int p=pow(10.,count-1);
   for (i=0;i<count/2;i++)
   {  
	   b[i]=M/p;
	   M=M%p;
	   p=p/10;
	   b[count-i-1]=M/p;
	    M=M%p;
	   p=p/10;
   }
    printarray ( b,  count);
   }
