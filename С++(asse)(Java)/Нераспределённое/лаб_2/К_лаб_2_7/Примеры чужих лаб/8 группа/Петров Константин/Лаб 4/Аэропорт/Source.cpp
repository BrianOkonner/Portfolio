/*
	������ ����������
		8 ������
	��� 4 - ����� ��������
*/

#include"Airport.h"

int main(void) {
	setlocale(LC_ALL, "rus");
	Airport Data;
	do {
		system("cls");
		cout << "1 - ������� �������" << endl;
		cout << "2 - �������� ������ ���������� �� ��������� �����" << endl;
		cout << "0 - �����" << endl;
		switch (_getch() - '0') {
		case 1: {
			system("cls"); 
			Func1(Data);
			break;
		}
		case 2: {
			system("cls");
			Func2(Data);
			break;
		}

		case 0: {
			system("cls");
			cout << "��������� ���������" << endl;
			return 0;
		}
		default: {
			system("cls");
			break;
		}
		}
	} while (true);

	return 0;
}