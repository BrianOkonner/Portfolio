#include "header.h"

void menu()
{
	int flag; char f;
L1:
	system("cls");
	cout << "������� ����� ������ ����:\n";
	cout << "1. ���������� ��������� � ��������� ����� ������ \n";
	cout << "2. ������� ���������, ������� ������������ ���������� ��������� �����, � ������� ������ \"������\".  \n";
	cout << "3. ���������� � �������. \n";
	cout << "4. ������ ������ ������.\n";
	cout << "5. �����.\n";
	cin >> flag;
	switch (flag)
	{
	case 1:
case1:
		system("cls");
		cout << setw(5) << " ***********���������� ��������� � ��������� ����� ������*********** \n";
		cout << "1. ��������� ���������\n2. ����������� �������\n";
		cin >> flag;
		switch (flag)
		{
		case 1:
			char str_infix[100]; 	char str_postfix[MAX_LEN];
			system("cls");
			cout << setw(5) << " ***********���������� ��������� � ��������� ����� ������*********** \n";
			cout << "������� ���� ��������� ���������:";
			cin>>str_infix;
			PostfixNotation(str_infix, str_postfix);
			cout <<"��������� � ����������� �����: "<< str_postfix << endl;
			cout << "��������� ����������: " << calculation(str_postfix, str_infix) << endl;
			cout << "������ ������ ������? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; }
		case 2:
			condition1();
			cout << "\n��������� �����? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto case1; }
			else { break; }
		default:
			system("cls");
			cout << "�� ������� �������� �������. " << endl;
			cout << "����������� �����? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; };
			exit(EXIT_FAILURE);
		}


		break;
	case 2:
		system("cls");
		cout << setw(5) << " ***********������� ���������, ������� ������������ ���������� ��������� �����, � ������� ������ \"������\"*********** \n";
		cout << "1. ��������� ���������\n";
		cin >> flag;
		switch (flag)
		{
		case 1:
			int n, number; char str_infix[100]; 	char str_postfix[MAX_LEN];
			system("cls");
			cout << setw(5) << " ***********������� ���������, ������� ������������ ���������� ��������� �����, � ������� ������ \"������\"*********** \n";
			cout << "�������� ������������������ ��������� � ����� input.txt. ��������� ��������� � ������� ��������: ";
			sosedi();
			
			cout << "������ ������ ������? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; }
		default:
			system("cls");
			cout << "�� ������� �������� �������. " << endl;
			cout << "����������� �����? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; };
			exit(EXIT_FAILURE);
		}
		break;
	case 3:
		system("cls");
		cout << setw(5) << " ***********���������� � �������*********** \n";
		cout << "1. ��������� ���������\n";
		cin >> flag;
		switch (flag)
		{
		case 1:
			int n, number; char str_infix[100]; 	char str_postfix[MAX_LEN];
			system("cls");
			cout << setw(5) << " ***********���������� � �������*********** \n";
			cout << "�������� ������������������ ��������� � ����� input.txt. ";
			queue_func();

			cout << "������ ������ ������? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; }
		default:
			system("cls");
			cout << "�� ������� �������� �������. " << endl;
			cout << "����������� �����? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; };
			exit(EXIT_FAILURE);
		}
		break;
	case 4:
case4:
		system("cls");
		cout << setw(5) << " ***********������ ������ ������*********** \n";
		cout << "1. ��������� ���������\n2. ����������� �������\n";
		cin >> flag;
		switch (flag)
		{
		case 1:
			int n, number;
			system("cls");
			cout << setw(5) << " ***********������ ������ ������*********** \n";
			cout << "������� ���������� �������: "; cin >> n; cout << "������� ����� �����������: "; cin >> number;

			Josef(n, number);
			
			cout << "������ ������ ������? Y/N";
			cin >> f; if (f == 'y'||f=='Y') { goto L1; }
			else { break; }
		case 2:
			condition();
			cout << "��������� �����? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto case4; }
			else { break; }
		default:
			system("cls"); 
			cout << "�� ������� �������� �������. " << endl;
			cout << "����������� �����? Y/N";
			cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
			else { break; };
			exit(EXIT_FAILURE);
		}

		break;
	case 5:
		break;
	default:
		system("cls");
		cout << "�� ������� �������� �������. " << endl;
		cout << "����������� �����? Y/N";
		cin >> f; if (f == 'y' || f == 'Y') { goto L1; }
		else { break; };
		exit(EXIT_FAILURE);
	}
}

