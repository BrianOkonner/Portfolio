#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
// ������� - �������� � ������������ �������
int maxint(int *A,int n, int& num )
{
_asm
{
	mov ecx,n
	dec ecx
	mov esi,A		// ����� �������
	mov edx,0		// ��� �������
	mov edi,edx		// ��� ��������������� ������� max ��-��
	mov eax,[esi]	// ���������� ��������, ����� �������� � esi
for1:
	add esi,4
	inc edx
	cmp eax,[esi]
	cmovl eax,[esi]	// ���������, ���� ������
	cmovl edi,edx
	loop for1
// max - ��������� � eax	
	mov esi,num		// �������� ����� ��������������� ��������� num � esi
	mov [esi],edi	// �������� �� ����� ������ ������ ��� ��-��
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


