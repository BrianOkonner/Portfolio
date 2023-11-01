#include "Airport.h"
Airport::AirCraft::AirCraft(string A, string B, string C) {
	cName = C;
	sTown = A;
	dTown = B;
	price =rand() % 2000;
	ID = rand() % 1000;
	date.dd = rand() % 30 + 1;
	date.mm = rand() % 2 + 3;
	type = rand() % 2 + 1;		//	1 - ��������� 2 - ������� 3 - �������
	if (type == 1) {
		acCapacity = 50;
		econNum = 40;
		vipNum = 10;
	}
	else if (type == 2) {
		acCapacity = 100;
		econNum = 70;
		vipNum = 30;
	}
	else {
		acCapacity = 200;
		econNum = 100;
		vipNum = 100;
	}
	econSeats = rand() % econNum;
	vipSeats = rand() % vipNum;

}
Airport::Company::Company(string N, int a) {
	Name = N;
	Rep = a;
}
Airport::Airport() {
	//---------������ ���� �������------------
	ifstream fin("Towns");
	while (!fin.eof()) {
		string temp;
		getline(fin, temp);
		Towns.push_back(temp);
	}
	fin.close();
	//-----------��������� ��������------------
	ifstream fin1("Companies");
	while (!fin1.eof()) {
		string temp;
		getline(fin1, temp);
		Companies.push_back(Company(temp, rand() % 5));
	}
	fin1.close();
	//-----���������� ���������� � ��������-----
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		int x = rand() % Towns.size(), y;
		do {
			y = rand() % Towns.size();
		} while (x == y);
		AC.push_back(AirCraft(Towns[x], Towns[y], Companies[rand() % Companies.size()].Name));
	}
}
void Airport::Print(string A, string B, Date C, string D, int l, int u) {
	cout << left << setw(15) << "�����������" << left << setw(15) << "����������" << left << setw(7) << "���� " << left << setw(8) << "      " << left << setw(8) << "����  " << left << setw(9) << "      " << left << setw(8) << "��� ����." << endl << endl;
	for (int i = 0; i < AC.size(); i++) {
		if ((AC[i].sTown == A || A == "ALL") && (AC[i].dTown == B || B == "ALL") && (AC[i].cName == D || D == "ALL") && ((AC[i].date.dd == C.dd && AC[i].date.mm == C.mm) || (C.dd == 0 && C.mm == 0)) && ((l == 0 && u == 15000) || (AC[i].price >= l && AC[i].price <= u))) {
			cout << left << setw(15) << AC[i].sTown << left << setw(15) << AC[i].dTown << right << setw(2) << AC[i].date.dd << "." << left << setw(4) << AC[i].date.mm << right << setw(2) << "  " << " " << left << setw(4) << "  " << " " << left << setw(7) << AC[i].price << " " << left << setw(9) << "   " << left << setw(10) << AC[i].cName << endl;
		}
	}
}
void Airport::Fprint(string A, string B, Date C, string D, int l, int u) {
	ofstream fout("Otput.txt");
	
	fout << left << setw(15) << "�����������" << left << setw(15) << "����������" << left << setw(7) << "���� " << left << setw(8) << "      " << left << setw(8) << "����  " << left << setw(9) << "      " << left << setw(8) << "��� ����." << endl << endl;
	for (int i = 0; i < AC.size(); i++) {
		if ((AC[i].sTown == A || A == "ALL") && (AC[i].dTown == B || B == "ALL") && (AC[i].cName == D || D == "ALL") && ((AC[i].date.dd == C.dd && AC[i].date.mm == C.mm) || (C.dd == 0 && C.mm == 0)) && ((l == 0 && u == 15000) || (AC[i].price >= l && AC[i].price <= u))) {
			fout << left << setw(15) << AC[i].sTown << left << setw(15) << AC[i].dTown << right << setw(2) << AC[i].date.dd << "." << left << setw(4) << AC[i].date.mm << right << setw(2) << "  " << " " << left << setw(4) << "  " << " " << left << setw(7) << AC[i].price << " " << left << setw(9) << "   " << left << setw(10) << AC[i].cName << endl;
		}
	}
	fout.close();
}
void Airport::PrintAll() {
	cout << left << setw(15) << "�����������" << left << setw(15) << "����������" << left << setw(7) << "���� " << left << setw(8) << "      " << left << setw(8) << "����  " << left << setw(9) << "      " << left << setw(8) << "��� ����." << endl << endl;
	for (int i = 0; i < AC.size(); i++)
		cout << left << setw(15) << AC[i].sTown << left << setw(15) << AC[i].dTown <<right<<setw(2)<< AC[i].date.dd << "." << left << setw(4) << AC[i].date.mm<<right<<setw(2) << "  " << " " << left << setw(4) << "  " << " " << left << setw(7) << AC[i].price << " " << left << setw(9) << "   " << left << setw(10) << AC[i].cName << endl;
}
void Airport::Menu1() {
	string dest, start, cName;
	int lower, upper;
	Date first;
	
	start = "ALL";
	dest = "ALL";
	cName = "ALL";
	lower = 0;
	upper = 15000;
	first.dd = 0;
	first.mm = 0;


	bool flag = false;
	
	do {
		cout << "1 - �������� ����� �����������" << endl;
		cout << "2 - �������� ����� ����������" << endl;
		cout << "3 - �������� ���� ������" << endl;
		cout << "4 - �������� ����������� ����" << endl;
		cout << "5 - �������� ������������ ����" << endl;
		cout << "6 - �������� ��� ��������" << endl;
		cout << "7 - �������� ��� ���������" << endl;
		cout << "8 - �����" << endl << endl;

		cout << "+ - ������� ��������� �� ����������" << endl;
		cout << endl << endl;
		
		if (!flag) {
			PrintAll();
			flag = true;
		}
		
		switch (_getch() - '0') {
		case 1: {
			system("cls");
			cout << "������� ����� �����������" << endl;
			cin >> start;
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			cout << "������� ����� ����������" << endl;
			cin >> dest;
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			cout << "������� ���� ������" << endl;
			cout << "����  - "; cin >> first.dd;
			cout << "����� - "; cin >> first.mm;
			cout << endl;
			if (first.dd >= 32 || first.dd <= 0 || first.mm >= 13 || first.mm <= 0) {
				system("cls");
				cout << "�������� ����" << endl;
				exit(0);
			}
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			cout << "������� ����������� ����" << endl;
			cin >> lower;
			system("cls");
			break;
		}
		case 5: {
			system("cls");
			cout << "������� ������������ ����" << endl;
			cin >> upper;
			system("cls");
			break;
		}
		case 6: {
			system("cls");
			cout << "�������� ��� ��������" << endl;
			cin >> cName;
			system("cls");
			break;
		}
		case 7: {
			system("cls");
			cout << "�������� ��� ���������" << endl;
			flag = 0;
			Sleep(3000);
			system("cls");
			system("cls");
			break;
		}
		case 8: {
			system("cls");
			return;
		}
		case(-5):{
			Print(start, dest, first, cName, lower, upper);

			cout << endl << "������� � ���� ���������?" << endl;
			cout << "1 - ��" << endl << "0 - ���" << endl;
			int a;
			cin >> a;
			if (a == 1) 
				Fprint(start, dest, first, cName, lower, upper);
			else if (a == 0) {}
			else {
				system("cls");
				cout << "�������� �����" << endl;
				exit(0);
			}
			
			cout << "�������� �������� ��������(-��)?" << endl;
			cout << "1 - ��" << endl << "0 - ���" << endl;
			int b;
			cin >> b;
			if (b == 1)
				ShowPar(start, dest, first, cName, lower, upper);
			else if (b == 0) {}
			else {
				system("cls");
				cout << "�������� �����" << endl;
				exit(0);
			}
			system("cls");
			start = "ALL";
			dest = "ALL";
			cName = "ALL";
			lower = 0;
			upper = 15000;
			first.dd = 0;
			first.mm = 0;
			break;
		}
		default:{
			system("cls");
			cout << "�������� �����" << endl;
			system("cls");
			return;
		}
		}
	} while (true);
}
void Airport::ShowPar(string A, string B, Date C, string D, int l, int u) {
	cout << left << setw(6) << "��" << left << setw(15) << "�����������" << left << setw(15) << "��������" <<left<<setw(5)<<"�����"<< endl;
	for (int i = 0; i < AC.size(); i++) {
		if ((AC[i].sTown == A || A == "ALL") && (AC[i].dTown == B || B == "ALL") && (AC[i].cName == D || D == "ALL") && ((AC[i].date.dd == C.dd && AC[i].date.mm == C.mm) || (C.dd == 0 && C.mm == 0)) && ((l == 0 && u == 15000) || (AC[i].price >= l && AC[i].price <= u))) {
			cout << left << setw(6) << AC[i].ID << left << setw(15) << AC[i].sTown << left << setw(15) << AC[i].dTown << left << setw(5) << AC[i].type << endl;
		}
	}
	cout << endl << endl;
	system("pause");
	system("cls");
}
void Airport::FindAndShow(int a, string b) {
	cout << endl;
	int q, h;
	for (int i = 0; i < AC.size(); i++) {
		if (AC[i].ID == a && AC[i].sTown == b) {
			q = i;
			cout << "����� �����������     - " << AC[i].sTown << endl;
			cout << "����� ����������      - " << AC[i].dTown << endl;
			cout << "���� ������           - " << AC[i].date.dd << "." << AC[i].date.mm << endl;
			cout << "���� ��               - " << AC[i].price << endl;
			cout << "����������� ��������  - " << AC[i].acCapacity << endl;
			cout << "���������� VIP ����   - " << AC[i].vipNum << endl;
			cout << "��������� VI� ����    - " << AC[i].vipSeats << endl;
			cout << "��������� ������ ���� - " << AC[i].econSeats << endl;

			cout << "��� ��������          - " << AC[i].cName << endl;			for (int j = 0; j < Companies.size(); j++) {
				if (Companies[j].Name == AC[i].cName) {
					h = j;
					break;
				}
			}
			cout << "������� ��������      - " << Companies[h].Rep << endl;
			break;
		}
	}
	cout << endl;
	cout << "������� ���������� � �������� � ����?" << endl;
	cout << "1 - ��       0 - ���" << endl;

	int c;
	cin >> c;
	if (c == 1) {
		ofstream fout2("Flight.txt");
		fout2 << "����� �����������     - " << AC[q].sTown << endl;
		fout2 << "����� ����������      - " << AC[q].dTown << endl;
		fout2 << "���� ������           - " << AC[q].date.dd << "." << AC[q].date.mm << endl;
		fout2 << "���� ��               - " << AC[q].price << endl;
		fout2 << "����������� ��������  - " << AC[q].acCapacity << endl;
		fout2 << "���������� VIP ����   - " << AC[q].vipNum << endl;
		fout2 << "��������� VI� ����    - " << AC[q].vipSeats << endl;
		fout2 << "��������� ������ ���� - " << AC[q].econSeats << endl;

		fout2 << "��� ��������          - " << AC[q].cName << endl;
		fout2 << "������� ��������      - " << Companies[h].Rep << endl;
		fout2.close();
		system("cls");
	}
	else if(c == 2){}
	else {
		cout << "�������� �����" << endl;
		return;
	}
}
void Airport::Menu2() {
	cout << "������� ID �������� � ����� �����������" << endl;
	int id;
	string town;
	cin >> id;
	cin >> town;
	FindAndShow(id, town);
	system("pause");
}