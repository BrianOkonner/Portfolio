/*		������ ����������
8 ������

���������� ������ 4 + ���. ������

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��� ������

1 - ��������������� ����� �������
2 - ������� �����������
3 - ������� ������
4 - �������� �����
5 - ������ ������� ������
*/


#include "Header.h"



int main() {
	setlocale(LC_ALL, "rus");
	int size, choice = 0;
	try {
		do {
			cout << "�������� ������ :" << endl;
			cout << "1. ������ ��� ������ ������" << endl;
			cout << "2. ���� ������" << endl;
			cout << "3. ������" << endl;
			cout << "0 - �����" << endl;
			choice = _getch() - '0';
			system("cls");
			switch (choice) {
			case 0: {
				cout << "��������� ���������" << endl << endl;
				return 0;
			}
			case 1: {
				Flavii();
				break;
			}
			case 2: {
				PaperSheet();
				break;
			}
			case 3: {
				Road();
				break;
			}
			default: {
				system("cls");
				throw 4;
			}
			}
		} while (true);
	}
	catch (int a) {
		cout << "���-�� ����� �� ���....\n";
		cout << "����� ������ - " << a << endl << endl;
	}

	system("pause");
	return 0;
}

