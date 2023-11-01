//5.	Задана целочисленная последовательность A=(ai), i=1..n, n<=100.
//Назовем серией группу подряд идущих одинаковых элементов, 
//а длиной серии — количество этих элементов (длина серии может быть равна 1).
//Вывести массив, содержащий длины всех серий исходного массива.

//Идея алгоритма:
//1) Создаем и вводим массив.
//2) Читаем каждый элемент и сравниваем его со следующим, если элементы равны, счетчик увеличивается на 1,
//если нет, счетчик сбрасывается на 1.

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a[30];
	int lenghth, max = 0, count = 0;
	cout << "Введите длину строки" << endl;
	cin >> lenghth;  // вводим длину массива A
	cout << "введите элементы первого строки" << endl;
	for (int i = 0; i<lenghth; i++) // и каждый его элемент
		cin >> a[i];
	cout << endl;
	cout << "Ваша строка" << endl;
	for (int i = 0; i<lenghth; i++) // и каждый его элемент
		cout << a[i] << " ";
	cout << endl;
	cout << "Длины серий:" << endl;
	count = 1;
	for (int i = 0; i < lenghth - 1; i++)
	{
		if (a[i] < a[i + 1])
			count++;

		if (count > max)
			max = count;

		if (a[i] >= a[i + 1])
		{
			cout << count << endl;
			count = 1;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}