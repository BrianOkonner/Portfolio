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
		cout << "������� ����� �� ������� ������ ���������:" << endl;
		cin >> a;
		A *= a;
		cout << "������ � ����� ��������� �� �����: "<<A<< endl;
		A.push_back(123);
		cout << "������ ����� ���������� �������� � ����� : " << A << endl;
		A.pop_back();
		cout << "������ A ����� �������� ���������� �������� : " << A << endl;
		cout << "������ ������� - " << A.front() << endl << endl;
		cout << "��������� �������� - " << A.back() << endl;
		cout << "������ ������� �:" << A.getSize() << endl;
		if (A.isEmpty())
		{
			cout << "������ ������!" << endl << endl;
		}
		else cout << "������ �� ������!" << endl;
		Vector C;
		cout << "������� ������ C :" << endl;
		cin >> C;
		Vector D(C);
		cout << "D : " << D << endl;
		Vector G = C + D;
		cout << "C + D : " << G  << endl;
		Vector E;
		cout << "������� ������ � :" << endl;
		cin >> E;
		G = D - E;
		cout << "D - E : " << G << endl << endl;

	}
	catch (Bad_dimensions)
	{
		cout << "������ �����������!" << endl;
	}
	
	system("pause");
}