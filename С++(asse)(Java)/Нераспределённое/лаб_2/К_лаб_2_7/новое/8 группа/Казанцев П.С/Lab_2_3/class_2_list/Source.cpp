/* �������� ����� ���������
   1 ���� 8 ������

���������������� ������ � �������������� ������

������

1 - ������������ �����
2 - ������������ ����
3 - ������������ ��������� � ������
4 - ��� �������� � ����� �������


*/



#include "list.h"
#include <Windows.h>
#include <locale>
#include <conio.h>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "rus");
	int choice = 0;
	try {
		do {
			cout << "�������� ������ :" << endl;
			cout << "1. ������ ������ " << endl;
			cout << "2. ���� ������" << endl;
			cout << "3. ������" << endl;
			cout << "0. �����" << endl;
			choice = _getch() - '0';
			system("cls");
			switch (choice) {
			case 0: {
						cout << "��������� ���������" << endl << endl;
						Sleep(500);
						return 0;
			}
			case 1: {
						Iosif();
						break;
			}
			case 2: {
						Paper();
						break;
			}
			case 3: {
						Road();
						break;
			}
			default: {
						 system("cls");
						 throw 1;
			}
			}
		} while (true);
	}
	catch (int a) {
		cout << "Error!!!....\n";
		cout << "����� ������ - " << a << endl << endl;
	}

	system("pause");
	return 0;
}


/*List list1;
	list1.push_head(1);
	list1.push_head(2);
	list1.push_head(3);
	list1.push_head(4);
	list1.push_back(5);
	list1.push_back(6);
	List list2(list1);
	list2.print();
	List::node *tmp = list1.search();
	cout << "Pervii chetnii "  << tmp->item << endl;
	//list1.remove(tmp);
	//int t = list1.remove(2);
	//cout << t << endl;
	//int m = list1.smin();
	//cout << m << endl;
	list1.invert();
	list1.delchet();
	list1.print();*/