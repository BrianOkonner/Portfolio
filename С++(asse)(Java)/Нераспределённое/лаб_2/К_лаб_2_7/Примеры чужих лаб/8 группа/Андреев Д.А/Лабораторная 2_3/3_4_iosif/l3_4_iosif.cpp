/*
������� ������� 8 ������

������� 3_4
������ ������

MS Visual Studio 2017
*/

#include "ArrayQueue.h" 

int main()
{
	setlocale(0, "rus");

	ofstream out;
	out.open("Output.txt");

	int n, m;
	cout << "����������"; cin >> n;
	cout << "���"; cin >> m;

	ArrayQueue  s(n * 2);

	for (int i = 1; i <= n; i++)
		s.push(i);

	int el;
	while (!s.isEmpty())
	{
		for (int i = 1; i<m; i++)
		{
			el = s.del();
			s.push(el);
		}
		s.del();
	}
	if (m == 1) el = n;

	cout << "\n��������� ����� " << el << endl;
	out << "\n��������� ����� " << el << endl;
	system("pause");
	return 0;
}

