/*
������� ������� 8 ������

������ 3_3
��������

1.	������������� ������ �� �������� ���������. ������� ��������������� ������ �� �������;
2.	����� � ������� ������ � �������� �� ��� �������. ������� �������� �������� � �������, ��������� ������ ����� ������� �� �������.
3.	������������� ������ �� �������, � ������ ����� ������ �� �������� ���������. ������� ��������������� ������ �� �������.
4.	������� �� ������� ����� � ������� ���� ��������� � ������ ������.

*/

#include "StudContainer.h"

int main()
{
	setlocale(0, "rus");
	ifstream in("Input.txt");
	
	int n;
	in >> n;

	Student st;

	StudContainer StudC(n);

	for (int i = 0; i < n; i++)
	{
		in >> st.name >> st.num >> st.grade;
		StudC.insert(st);
	}

	int enter;
	do
	{
		cout << "1. ���������� (���)\n";
		cout << "2. �����\n";
		cout << "3. ���������� (������ � �����)\n";
		cout << "4. ������� ����\n";
		cout << "5. �����\n";

		cin >> enter;
		int Name_Len = 100;
		char* name = new char[Name_Len];
		Student* stud;
		switch (enter)
		{
		case 1:
			system("cls");
			StudC.sortByName();
			StudC.print(cout);
			break;
		case 2:
			cout << "����� �������� ������ � �������, \n����������� ���������� ������� \n���: \n";
			cin >> name;
			stud = StudC.findByName(name);
			if (stud)
				cout << (*stud).name << " " << (*stud).num << " " << (*stud).grade << endl;
			else
				cout << "�� �������\n";
			break;
		case 3:
			StudC.sortByGroupAndName();
			StudC.print(cout);
			break;
		case 4:
			StudC.report(cout);
			break;
		default:
			break;
		}
	} while (enter != 5);


	return 0;
}