#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
// �������� � ������������ �������
using namespace std;
int main()
{
	srand(time(0));
	int *A,n,Amax;
	cout<<"Dimension? ";
	cin>>n;
	A = new int [n];
	for (int i=0;i<n;i++)
	{
	
			A[i] = rand()%100;
			cout<< setw(6)<<A[i];
	}
	cout<<endl;

_asm
{
	mov ecx,n
	dec ecx
	mov esi,A		// ����� �������
	mov eax,[esi]	// ���������� ��������, ����� �������� � esi
for1:
	add esi,4
	cmp eax,[esi]
	cmovl eax,[esi]	// ���������, ���� ������
	loop for1
	mov Amax,eax
}
	cout<<"max = "<<Amax<<endl;
}


