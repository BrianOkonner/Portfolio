#include "queue.h" 

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream out;
	out.open("Output.txt");
	int N, M;
	cout << "���-�� ������� = "; cin >> N;
	cout << "����� �� �������� ������� ���� = "; cin >> M;

	ArrayQueue  s(N*2);
	for (int i = 1; i <= N; i++)
		s.push(i);

	int x;
	while (!s.isEmpty())
	{
		for (int i = 1; i<M; i++)
		{
			x = s.del();
			s.push(x);
		}
		s.del();
	}
	if (M == 1) x = N;

	cout << "\n����� ����������� �������� = " << x << "\n\n";
	out << "����� ����������� �������� = " << x << "\n\n";
	out.close();
	system("pause");
	return 0;
}

