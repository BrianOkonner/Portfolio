#include<iostream>
using namespace std;

int main()
{
	//���� �������
	setlocale(LC_ALL, "rus");
	int a[100], n, Amax;
	cout << " ������� ����� �������" << endl;
	cin >> n;
	cout << "\n����� ������� n=" << n << endl << endl;

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 20;
		cout << a[i] << " ";
	}
	cout << endl << endl;


	_asm
	{   mov ecx, n
		dec ecx
		xor esi,esi
		mov eax, [a+esi*4]	// ���������� ��������, ����� �������� � esi
	for1:
		inc esi
		cmp eax, [a][esi*4]
		cmovl eax, [a][esi*4]	// ���������, ���� ������
		loop for1
		mov Amax, eax
	}

	//�����

	cout << "������������ ������� = " << Amax<<endl<<endl;
	system("pause");
	return 0;
}
