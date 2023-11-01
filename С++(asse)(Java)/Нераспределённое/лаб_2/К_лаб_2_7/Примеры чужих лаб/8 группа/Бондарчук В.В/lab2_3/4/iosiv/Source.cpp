#include"Header.h"
int main()
{
	try
	{
		int m;
		cout << "vvedite col-vo ludey" << endl;
		cin >> m;
		ArrayQueue l(m);

		cout << "vvedite shag " << endl;
		int n;
		cin >> n;
		if (n < 1 || m < 1)
		{
			cout << "error" << endl;
		}
		for (int i = 1; i <= m; l.push(i), ++i);

		while (m != 1) 
		{
			for (int i = 1; i <= n; i++) 
			{
				if (i == n) int q = l.del();
				else 
				{
					int y = l.del();
					l.push(y);
				}
			}
			m--;
		}
		cout << "posledniy chel - " << l.del() << endl;
	}
	catch (int i)
	{
		if (i == 1) cout << "is full" << endl;
		if (i == 2) cout << "is empty" << endl;
	}
	system("pause");
}