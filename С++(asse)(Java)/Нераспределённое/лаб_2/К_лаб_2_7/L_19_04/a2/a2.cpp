#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
// ТРАНСПОНИРОВАНИЕ МАТРИЦЫ (ПЕРЕДАЧА ПАРАМЕТРОВ В ФУНКЦИЮ)
void transp(int **A, int n)
{
_asm
{
  pushad
   mov ebx,A      // для строк
   xor eax,eax
   mov ecx,n
      xor edi,edi
for1:
      push ecx
      mov edx,ebx     //для столбцов
      mov esi,[ebx]   //адрес начала строки матрицы

  for2:
      mov edi,[edx]
      push dword ptr [esi][eax]    //обмен
      push dword ptr [edi][eax]
      pop dword ptr [esi][eax]
      pop dword ptr [edi][eax]
      add esi,4               //по строке
      add edx,4               // к следующей строке 
  ef2: loop for2

      add ebx,4
      add eax,4               // диагональный элемент
      pop ecx
ef1: loop for1
  popad
}
/*
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
		{
	        int t = A[i][j];
		    A[i][j]=A[j][i];
			A[j][i]=t;
		}
*/
}
int main()
{
	srand(time(0));
	int **A,n;
	cout<<"Dimension? ";
	cin>>n;
	A = new int * [n];
	for (int i=0;i<n;i++)
	{
		A[i] = new int[n];
		for (int j=0;j<n;j++)
		{
			A[i][j] = rand()%100;
			cout<< setw(6)<<A[i][j];
		}
		cout<<endl;
	}
	transp(A,n);
	cout<<"RESULT"<<endl;
	for ( i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			cout<< setw(6)<<A[i][j];
		cout<<endl;
	}
	for (i=0;i<n;i++)
		delete [] A[i];
	delete []A;

}