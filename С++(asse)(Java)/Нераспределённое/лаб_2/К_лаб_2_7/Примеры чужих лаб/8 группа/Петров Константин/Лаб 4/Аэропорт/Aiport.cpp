#include "Airport.h"
Airport::AirCraft::AirCraft(string A, string B, string C) {
	cName = C;
	sTown = A;
	dTown = B;
	price =rand() % 2000;
	ID = rand() % 1000;
	date.dd = rand() % 30 + 1;
	date.mm = rand() % 2 + 3;
	type = rand() % 2 + 1;		//	1 - Маленький 2 - Средний 3 - Большой
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
	//---------Запись имен городов------------
	ifstream fin("Towns");
	while (!fin.eof()) {
		string temp;
		getline(fin, temp);
		Towns.push_back(temp);
	}
	fin.close();
	//-----------Генерация компаний------------
	ifstream fin1("Companies");
	while (!fin1.eof()) {
		string temp;
		getline(fin1, temp);
		Companies.push_back(Company(temp, rand() % 5));
	}
	fin1.close();
	//-----Заполнение информации о самолете-----
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
	cout << left << setw(15) << "Отправление" << left << setw(15) << "Назначение" << left << setw(7) << "Дата " << left << setw(8) << "      " << left << setw(8) << "Цена  " << left << setw(9) << "      " << left << setw(8) << "Имя комп." << endl << endl;
	for (int i = 0; i < AC.size(); i++) {
		if ((AC[i].sTown == A || A == "ALL") && (AC[i].dTown == B || B == "ALL") && (AC[i].cName == D || D == "ALL") && ((AC[i].date.dd == C.dd && AC[i].date.mm == C.mm) || (C.dd == 0 && C.mm == 0)) && ((l == 0 && u == 15000) || (AC[i].price >= l && AC[i].price <= u))) {
			cout << left << setw(15) << AC[i].sTown << left << setw(15) << AC[i].dTown << right << setw(2) << AC[i].date.dd << "." << left << setw(4) << AC[i].date.mm << right << setw(2) << "  " << " " << left << setw(4) << "  " << " " << left << setw(7) << AC[i].price << " " << left << setw(9) << "   " << left << setw(10) << AC[i].cName << endl;
		}
	}
}
void Airport::Fprint(string A, string B, Date C, string D, int l, int u) {
	ofstream fout("Otput.txt");
	
	fout << left << setw(15) << "Отправление" << left << setw(15) << "Назначение" << left << setw(7) << "Дата " << left << setw(8) << "      " << left << setw(8) << "Цена  " << left << setw(9) << "      " << left << setw(8) << "Имя комп." << endl << endl;
	for (int i = 0; i < AC.size(); i++) {
		if ((AC[i].sTown == A || A == "ALL") && (AC[i].dTown == B || B == "ALL") && (AC[i].cName == D || D == "ALL") && ((AC[i].date.dd == C.dd && AC[i].date.mm == C.mm) || (C.dd == 0 && C.mm == 0)) && ((l == 0 && u == 15000) || (AC[i].price >= l && AC[i].price <= u))) {
			fout << left << setw(15) << AC[i].sTown << left << setw(15) << AC[i].dTown << right << setw(2) << AC[i].date.dd << "." << left << setw(4) << AC[i].date.mm << right << setw(2) << "  " << " " << left << setw(4) << "  " << " " << left << setw(7) << AC[i].price << " " << left << setw(9) << "   " << left << setw(10) << AC[i].cName << endl;
		}
	}
	fout.close();
}
void Airport::PrintAll() {
	cout << left << setw(15) << "Отправление" << left << setw(15) << "Назначение" << left << setw(7) << "Дата " << left << setw(8) << "      " << left << setw(8) << "Цена  " << left << setw(9) << "      " << left << setw(8) << "Имя комп." << endl << endl;
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
		cout << "1 - Изменить точку отправления" << endl;
		cout << "2 - Изменить точку назначения" << endl;
		cout << "3 - Изменить дату вылета" << endl;
		cout << "4 - Изменить минимальную цену" << endl;
		cout << "5 - Изменить максимальную цену" << endl;
		cout << "6 - Изменить имя компании" << endl;
		cout << "7 - Сбросить все параметры" << endl;
		cout << "8 - Выход" << endl << endl;

		cout << "+ - Вывести результат по параметрам" << endl;
		cout << endl << endl;
		
		if (!flag) {
			PrintAll();
			flag = true;
		}
		
		switch (_getch() - '0') {
		case 1: {
			system("cls");
			cout << "Введите город отправления" << endl;
			cin >> start;
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			cout << "Введите город назначения" << endl;
			cin >> dest;
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			cout << "Введите дату вылета" << endl;
			cout << "День  - "; cin >> first.dd;
			cout << "Месяц - "; cin >> first.mm;
			cout << endl;
			if (first.dd >= 32 || first.dd <= 0 || first.mm >= 13 || first.mm <= 0) {
				system("cls");
				cout << "Неверный ввод" << endl;
				exit(0);
			}
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			cout << "Введите минимальную цену" << endl;
			cin >> lower;
			system("cls");
			break;
		}
		case 5: {
			system("cls");
			cout << "Введите максимальную цену" << endl;
			cin >> upper;
			system("cls");
			break;
		}
		case 6: {
			system("cls");
			cout << "Изменить имя компании" << endl;
			cin >> cName;
			system("cls");
			break;
		}
		case 7: {
			system("cls");
			cout << "Сброшены все параметры" << endl;
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

			cout << endl << "Вывести в файл результат?" << endl;
			cout << "1 - Да" << endl << "0 - Нет" << endl;
			int a;
			cin >> a;
			if (a == 1) 
				Fprint(start, dest, first, cName, lower, upper);
			else if (a == 0) {}
			else {
				system("cls");
				cout << "Неверный выбор" << endl;
				exit(0);
			}
			
			cout << "Показать парметры самолета(-ов)?" << endl;
			cout << "1 - Да" << endl << "0 - Нет" << endl;
			int b;
			cin >> b;
			if (b == 1)
				ShowPar(start, dest, first, cName, lower, upper);
			else if (b == 0) {}
			else {
				system("cls");
				cout << "Неверный выбор" << endl;
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
			cout << "Неверный выбор" << endl;
			system("cls");
			return;
		}
		}
	} while (true);
}
void Airport::ShowPar(string A, string B, Date C, string D, int l, int u) {
	cout << left << setw(6) << "Ид" << left << setw(15) << "Отправление" << left << setw(15) << "Прибытие" <<left<<setw(5)<<"Класс"<< endl;
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
			cout << "Город отправления     - " << AC[i].sTown << endl;
			cout << "Город назначения      - " << AC[i].dTown << endl;
			cout << "Дата вылета           - " << AC[i].date.dd << "." << AC[i].date.mm << endl;
			cout << "Цена от               - " << AC[i].price << endl;
			cout << "Вместимость самолета  - " << AC[i].acCapacity << endl;
			cout << "Количество VIP мест   - " << AC[i].vipNum << endl;
			cout << "Свободных VIР мест    - " << AC[i].vipSeats << endl;
			cout << "Свободных эконом мест - " << AC[i].econSeats << endl;

			cout << "Имя компании          - " << AC[i].cName << endl;			for (int j = 0; j < Companies.size(); j++) {
				if (Companies[j].Name == AC[i].cName) {
					h = j;
					break;
				}
			}
			cout << "Рейтинг компании      - " << Companies[h].Rep << endl;
			break;
		}
	}
	cout << endl;
	cout << "Вывести информацию о самолете в файл?" << endl;
	cout << "1 - Да       0 - Нет" << endl;

	int c;
	cin >> c;
	if (c == 1) {
		ofstream fout2("Flight.txt");
		fout2 << "Город отправления     - " << AC[q].sTown << endl;
		fout2 << "Город назначения      - " << AC[q].dTown << endl;
		fout2 << "Дата вылета           - " << AC[q].date.dd << "." << AC[q].date.mm << endl;
		fout2 << "Цена от               - " << AC[q].price << endl;
		fout2 << "Вместимость самолета  - " << AC[q].acCapacity << endl;
		fout2 << "Количество VIP мест   - " << AC[q].vipNum << endl;
		fout2 << "Свободных VIР мест    - " << AC[q].vipSeats << endl;
		fout2 << "Свободных эконом мест - " << AC[q].econSeats << endl;

		fout2 << "Имя компании          - " << AC[q].cName << endl;
		fout2 << "Рейтинг компании      - " << Companies[h].Rep << endl;
		fout2.close();
		system("cls");
	}
	else if(c == 2){}
	else {
		cout << "Неверный выбор" << endl;
		return;
	}
}
void Airport::Menu2() {
	cout << "Введите ID самолета и город отправления" << endl;
	int id;
	string town;
	cin >> id;
	cin >> town;
	FindAndShow(id, town);
	system("pause");
}