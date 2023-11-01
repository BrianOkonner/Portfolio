#include<iostream>
using namespace std;

int main()
{
	//ввод массива
	setlocale(LC_ALL, "rus");
	int a[100], n, Amax;
	cout << " Введите длину массива" << endl;
	cin >> n;
	cout << "\nДлина массива n=" << n << endl << endl;

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
		mov eax, [a+esi*4]	// содержимое элемента, адрес которого в esi
	for1:
		inc esi
		cmp eax, [a][esi*4]
		cmovl eax, [a][esi*4]	// переслать, если меньше
		loop for1
		mov Amax, eax
	}

	//вывод

	cout << "Максимальный элемент = " << Amax<<endl<<endl;
	system("pause");
	return 0;
}
