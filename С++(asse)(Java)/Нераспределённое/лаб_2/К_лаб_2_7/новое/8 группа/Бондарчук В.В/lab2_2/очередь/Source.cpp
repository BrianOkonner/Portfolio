#include"Header.h"
Queue Queue1;
Queue Queue2;
Queue Queue3;
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int a;
	int count1 = 0, count2 = 0;
	while (!fin.eof())
	{
		fin >> a;
		if (prost(a))
		{
			Queue1.push(a);
		}
		if (palindrom(a))
		{
			Queue2.push(a);
		}
	}

	count2 = Queue2.size();
	count1 = Queue1.size();
	for (int i = 0; i < count1; i++)
	{
		int k = Queue1.front();
		Queue3.push(k);
		for (int j = 0; j < count2; j++)
		{
			int p = Queue2.front();
			if (k == p)
			{
				Queue2.pop();
				break;
			}
			Queue2.pop();
			Queue2.push(p);
		}
		Queue1.pop();
		Queue1.push(k);
	}
	count2 = Queue2.size();
	for (int i = 0; i < count2; i++)
	{
		int a = Queue2.front();
		Queue2.pop();
		Queue3.push(a);
	}
	int count3 = Queue3.size();
	for (int i = 0; i <count3; i++)
	{

		int c = Queue3.front();
		cout << c << endl;
		fout << c << endl;
		Queue3.pop();
	}
	system("pause");
}