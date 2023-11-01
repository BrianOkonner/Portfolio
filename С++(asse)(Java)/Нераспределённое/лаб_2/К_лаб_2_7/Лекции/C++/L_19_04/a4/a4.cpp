#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
// ‘”Ќ ÷»я - ћј —»ћ”ћ ¬ ƒ»Ќјћ»„≈— ќћ ћј——»¬≈
int maxint(int *A,int n, int& num )
{
_asm
{
	mov ecx,n
	dec ecx
	mov esi,A		// адрес массива
	mov edx,0		// дл€ индекса
	mov edi,edx		// дл€ результирующего индекса max эл-та
	mov eax,[esi]	// содержимое элемента, адрес которого в esi
for1:
	add esi,4
	inc edx
	cmp eax,[esi]
	cmovl eax,[esi]	// переслать, если меньше
	cmovl edi,edx
	loop for1
// max - результат в eax	
	mov esi,num		// засылаем адрес результирующего параметра num в esi
	mov [esi],edi	// посылаем по этому адресу индекс мах эл-та
}
}
int main()
{
	srand(time(0));
	int *A,n,Amax,ind;
	cout<<"Dimension? ";
	cin>>n;
	A = new int [n];
	for (int i=0;i<n;i++)
	{
	
			A[i] = rand()%100;
			cout<< setw(6)<<A[i];
	}
	cout<<endl;
	Amax = maxint(A,n,ind);
	cout<<"max = "<<Amax<<"  Index = "<<ind<<endl;
}


