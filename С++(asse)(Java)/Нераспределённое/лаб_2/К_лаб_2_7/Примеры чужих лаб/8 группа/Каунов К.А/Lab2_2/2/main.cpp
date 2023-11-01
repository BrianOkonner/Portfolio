#include"funkh.h"
Queue Pr;
Queue Pl;
Queue Res;
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int a;
	int c1, c2;
	while (!fin.eof())
	{
		fin >> a;
		if (Prost(a))
		{
			Pr.push(a);
		}
		if (Palind(a))
		{
			Pl.push(a);
		}
	}

	c2 = Pl.size();
	c1 = Pr.size();
	for (int i = 0; i < c1; i++)
	{
		int k = Pr.front();
		Res.push(k);
		for (int j = 0; j < c2; j++)
		{
			int p = Pl.front();
			if (k == p)
			{
				Pl.pop();
				break;
			}
			Pl.pop();
			Pl.push(p);
		}
		Pr.pop();
		Pr.push(k);
	}
	c2 = Pl.size();
	for (int i = 0; i < c2; i++)
	{
		int a = Pl.front();
		Pl.pop();
		Res.push(a);
	}
	int count3 = Res.size();
	for (int i = 0; i <count3; i++)
	{
		int c = Res.front();
		cout << c << endl;
		fout << c << endl;
		Res.pop();
	}
	system("pause");
	return 0;
}
