/*  �������� ����� ���������
	1 ���� 8 ������
	���� �� �������

	��� ������
1 - ������ ������� < 0
2 - ������ ������. ���������� �������� �������
3 - ���� ����
4 - ������ ������


*/

#include "Stack.h"

int main() {
	setlocale(LC_ALL, "rus");
	int choice = 0;
	do {
		cout << "�������� ������: " << endl << endl;
		cout << "1 - ������ " << endl;
		cout << "2 - ���� ������" << endl;
		cout << "3 - ������" << endl;
		cout << "0 - �����" << endl;
		choice = _getch() - '0';
		switch (choice) {
			case 1: {
				Neighbors();
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
			case 0: {
				system("cls");
				cout << "��������� ���������" << endl;
				return 0;
			}
			default:{
				system("cls");
				throw 4;
			}

		}
	} while (true);
	return 0;
}




