//��������� ��������
//1 ����
//������ 8
//3.1	������ ������.������ ���������� ����� N �������, �� ������� ������� ������,
//�  ���������  ������������  ��  ������� ������� ������� �� 2 �� N.���������,
//������� � ���� - ��, ����� ���� �� M.�������, �� ������� ����������� ����,
//������� �� �����.���� ������������ �� ���������� �������� � ��� �� ��� ���,
//���� �� ��������� ���� �������.���������� ����� ����������� ��������, 
//���� �������� M � ��, ��� ���� ��������� � ������� ��������.��������� �������� � ���������  ����


// ����1
//vvedite m :
//15
//vvedite kolvo ludey :
//3
//Nomer ostavshegosya :
//2



//���� 2
//vvedite m :
//3
//vvedite kolvo ludey :
//278
//Nomer ostavshegosya :
//125

#include "Header.h"

int main()
{
	List l;
	cout << "vvedite m: " << endl;
	int m;
	cin >> m;
	if (m == 0) { cout << "error"; exit(0); }
	cout << "vvedite kolvo ludey:  " << endl;
	int p;
	cin >> p;
	for (int i = 1; i <= p; l.push_back(i), i++);
	while (p != 1)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j != m)
			{
				int y = l.top();
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
	cout << "Nomer ostavshegosya:" << endl;
	cout << l.top() << endl;
	system("pause");
	return 0;
}