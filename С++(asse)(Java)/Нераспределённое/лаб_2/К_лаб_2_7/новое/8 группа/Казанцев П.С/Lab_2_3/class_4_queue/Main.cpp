/* �������� ����� ���������
1 ���� 8 ������

���������������� ������ � �������������� ������

������
1 - ������������ �����
2 - ����� ������� <= 0
3 - ������� �����������
4 - ������� ������
5 - ������������ ����
*/

#include "Queue.h"

int main() {
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

