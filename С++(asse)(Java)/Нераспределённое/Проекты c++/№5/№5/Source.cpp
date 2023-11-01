#include "Vector.h"

void main()
{
	setlocale(LC_ALL, "rus");
	try
	{
	
		Vector A(10), B(11);
		A.setVector();
		cout << "A : " << A << endl << endl;
		int a ;
		cout << "введите число на которое хотите домножить:" << endl;
		cin >> a;
		A *= a;
		cout << "Вектор А после умножения на число: "<<A<< endl;
		A.push_back(123);
		cout << "Вектор после добавления элемента в конец : " << A << endl;
		A.pop_back();
		cout << "Вектор A после удаления последнего элемента : " << A << endl;
		cout << "Первый элемент - " << A.front() << endl << endl;
		cout << "Последний элементы - " << A.back() << endl;
		cout << "Размер вектора А:" << A.getSize() << endl;
		if (A.isEmpty())
		{
			cout << "Пустой вектор!" << endl << endl;
		}
		else cout << "Вектор не пустой!" << endl;
		Vector C;
		cout << "Введите вектор C :" << endl;
		cin >> C;
		Vector D(C);
		cout << "D : " << D << endl;
		Vector G = C + D;
		cout << "C + D : " << G  << endl;
		Vector E;
		cout << "Введите вектор Е :" << endl;
		cin >> E;
		G = D - E;
		cout << "D - E : " << G << endl << endl;

	}
	catch (Bad_dimensions)
	{
		cout << "Плохая размерность!" << endl;
	}
	
	system("pause");
}