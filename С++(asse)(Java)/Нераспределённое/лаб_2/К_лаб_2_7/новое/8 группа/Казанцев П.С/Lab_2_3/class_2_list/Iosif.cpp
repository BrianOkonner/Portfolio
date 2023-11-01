#include "list.h"
using namespace std;

void Iosif()
{
	List l;
	ifstream in;
	//ofstream out;
	in.open("Iosif.txt");
	int m, p;
	in >> p >> m;
	in.close();
	if (p < 2 || m < 1)
	{
		cout << "Incorrect input !" << endl;
		throw 2;
	}
	for (int i = 1; i <= p; l.push_back(i), i++);
	while (p != 1)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j != m)
			{
				int y = l.front();
				l.remove_head();
				l.push_back(y);
			}
			else
			{
				l.remove_head();
			}
		}
		p--;
	}
	//out.open("Iosif_Output.txt");
	//out << "Last Man Standing : " << l.front() << endl;
	cout << "Last Man Standing : " << l.front() << endl;
	system("pause");
	system("cls");
}