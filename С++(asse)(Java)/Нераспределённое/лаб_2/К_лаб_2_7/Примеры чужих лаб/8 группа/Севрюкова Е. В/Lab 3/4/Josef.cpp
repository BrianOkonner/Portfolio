#include "queue.h" 

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream out;
	out.open("Output.txt");
	int N, M;
	cout << "Кол-во человек = "; cin >> N;
	cout << "Число до которого ведется счет = "; cin >> M;

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

	cout << "\nНомер оставшегося человека = " << x << "\n\n";
	out << "Номер оставшегося человека = " << x << "\n\n";
	out.close();
	system("pause");
	return 0;
}

