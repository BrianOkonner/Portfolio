/*
NamePrizes.txt
1 - сумма денег
2 - кол-во призов
Названия призов

Pricelist.txt
1  - скидка
Фирма (со *)
Товар - цена

*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

struct Prizes {
	char Name[81];
};

struct Item {
	char Name[81];
	int Price;
};

struct Firms {
	char FirmName[81];
	Item Info[100];
	int Amount = 0;
};

int main() {
	setlocale(LC_ALL, "rus");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(866);
//----------------------Чтение из первого файла----------------------
	int GenSum = 0, num1 = 0, Sale = 0;

	ifstream fin1("NamePrizes.txt");

	char Buff2[81]; Buff2[0] = '/0';
	fin1.getline(Buff2, 81);
	GenSum = atoi(Buff2);
	Buff2[0] = '/0';
	fin1.getline(Buff2, 81);
	num1 = atoi(Buff2);

	Prizes *Prize;
	Prize = new Prizes[num1];
	for (int i = 0; i < num1; ++i)
	Prize[i].Name[0] = '\0';

	int k = 0;
	while (!fin1.eof()) {
		fin1.getline(Prize[k].Name, 81);
		k++;
	}

	fin1.close();
//----------------------Чтение из второго файла----------------------
	ifstream fin2("Pricelist.txt");

	Buff2[0] = '\0';
	fin2.getline(Buff2, 81);
	Sale = atoi(Buff2);

	const char R[] = " ";
	int num2 = 0, j = 0;
	bool Flag = false;
	Firms FirmList[100];

	while (!fin2.eof()) {
		char Buff[81]; Buff[0] = '\0';
		fin2.getline(Buff, 81);
		if (Buff[0] == '*') {
			if (Flag == true) {
				++num2;
				j = 0;
			}
			FirmList[num2].FirmName[0] = '\0';
			strcpy(FirmList[num2].FirmName, Buff);
			Flag = true;
		}
		else {
			++FirmList[num2].Amount;
			int counter = 0;
			char Buff3[81]; Buff3[0] = '\0';
			strcpy(Buff3, Buff);
			char *b = strtok(Buff3, R);
			++counter;
			while (b) {
				b = strtok(NULL, R);
				++counter;
			}
			--counter;
			if (counter == 2) {
				char *f = strtok(Buff, R);
				strcpy(FirmList[num2].Info[j].Name, Buff);
				f = strtok(NULL, R);
				char *endptr1;
				int a = strtod(f, &endptr1);
				FirmList[num2].Info[j].Price = a;
				++j;
			}
			else if (counter == 3){
				char *c = strtok(Buff, R);
				strcpy(FirmList[num2].Info[j].Name, c);
				strcat(FirmList[num2].Info[j].Name, " ");
				c = strtok(NULL, R);
				strcat(FirmList[num2].Info[j].Name, c);
				c = strtok(NULL, R);
				char *endptr2;
				int b = strtod(c, &endptr2);
				FirmList[num2].Info[j].Price = b;
				++j;
			}
			else if (counter == 4) {
				char *d = strtok(Buff, R);
				strcpy(FirmList[num2].Info[j].Name, d);
				strcat(FirmList[num2].Info[j].Name, " ");
				d = strtok(NULL, R);
				strcat(FirmList[num2].Info[j].Name, d);
				strcat(FirmList[num2].Info[j].Name, " ");
				d = strtok(NULL, R);
				strcat(FirmList[num2].Info[j].Name, d);
				d = strtok(NULL, R);
				char *endptr3;
				int e = strtod(d, &endptr3);
				FirmList[num2].Info[j].Price = e;
				++j;
			}
			else {
				cout << "Incorrect input\n";
				exit(0);
			}
			counter = 0;
		}
	}
		++num2;
//------------------------Удаление *---------------------------------
	for (int i = 0; i < num2; ++i) {
		int l = 0;
		while (FirmList[i].FirmName[l] != '\0') {
			FirmList[i].FirmName[l] = FirmList[i].FirmName[l + 1];
			++l;
		}
	}
//------------------------Пункт 2------------------------------------


//-------------------------------------------------------------------	
	
	delete Prize;

	return 0;
}