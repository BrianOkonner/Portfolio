//������ ������ 
#include <iostream>
#include <list>

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	int n, k, l;
	cout << "���-�� �����: ";
	cin >>n ;
	cout << "����� �����������: ";
	cin >> k;
	list <int> mylist;
	for (int i = 1; i <=n; i++)
		mylist.push_back(i); 
							 
	while (mylist.size() != 1)
	{
		for (int i = 1; i < k; i++)
		{
			l = mylist.front();
			mylist.push_back(l);
			mylist.pop_front();	
		}
		mylist.pop_front();
	}
	cout << "��������� �������: " << mylist.front() << endl;
	system("pause");
}