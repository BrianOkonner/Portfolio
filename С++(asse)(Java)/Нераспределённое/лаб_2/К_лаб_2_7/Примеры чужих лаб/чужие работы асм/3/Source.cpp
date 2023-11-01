/* Петров Константин
8 группа

В10 	Задан текстовый файл Input.txt, состоящий  из слов и некоторые два числа X и Y.
Разделителями между словами является некоторое множество знаков препинания. Найти строки, в которых есть
слова с длинами равными введенным числам. Слова, длина которых равна Х, переставить в начало строки,
длина которых равна Y, переставить в конец строки. Результат записать в новый файл Output.txt.
Упорядочить слова по убыванию длин слов, результат сортировки записать в файл Out_sort.txt.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int MyStrlen(char* a);
void BubbleSort(char *a);
int MyStrlen1(char *a);
void AsmStrcat(char *a, char *b);


int main() {
	setlocale(LC_ALL, "rus");

	int X, Y;
	const char R[] = ".,:;! ";
	cout << "Введите X и Y " << endl;
	cin >> X >> Y;
	//-------------------------------------------------------------------
	ifstream fin("Input.txt");
	ofstream fout1("Output.txt");
	ofstream fout2("Out_sort.txt");

	while (!fin.eof()) {
		char Buff[81]; Buff[0] = '\0';
		fin.getline(Buff, 81);
		//-----------------------------------------------
		//Буферные строки
		char *LengthX, *LengthY, *Other;
		LengthX = new char[81];
		LengthY = new char[81];
		Other = new char[81];

		LengthX[0] = '\0';
		LengthY[0] = '\0';
		Other[0] = '\0';

		char *b;
		b = strtok(Buff, R);
		while (b) {
			if (MyStrlen(b) == X) {
				AsmStrcat(LengthX, b);
				AsmStrcat(LengthX, " ");
			}
			else if (MyStrlen(b) == Y) {
				AsmStrcat(LengthY, b);
				AsmStrcat(LengthY, " ");
			}
			else {
				AsmStrcat(Other, b);
				AsmStrcat(Other, " ");
			}

			b = strtok(NULL, R);
		}
		//-----------------------------------------------
		char *Result;
		Result = new char[81];
		Result[0] = '\0';

		AsmStrcat(Result, LengthX);
		AsmStrcat(Result, " ");
		AsmStrcat(Result, Other);
		AsmStrcat(Result, " ");
		AsmStrcat(Result, LengthY);

		cout << Result << endl;  //fout1
		//-----------------------------------------------
		BubbleSort(Result);
		fout2 << Result << endl; //fout2
	
		delete[]Result;
		delete[]LengthX;
		delete[]LengthY;
		delete[]Other;
	}
	//-------------------------------------------------------------------

	fout1.close();
	fout2.close();
	system("pause");
	return 0;
}

int MyStrlen(char *a) {
	int l = 0;
	_asm {
		mov esi, a
		mov edi, 0
		A1 : mov al, byte ptr[esi]
			 add esi, 1
			 add edi, 1
			 cmp[esi], '\0'
			 jne A1
			 mov l, edi
	}
	return l;
}
int MyStrlen1(char *a) {
	int l = 0;
	_asm {
		cld
		mov edi, a
		mov esi, edi
		mov ecx, 0ffffffffh
		xor al, al
		repne scasb
		sub edi, esi

		sub edi, 1
		mov l, edi
	}
	return l;
}
void BubbleSort(char *a) {
	// Создание копии строки
	char *Copy, *b;
	Copy = new char[81];
	Copy[0] = '\0';
	strcpy(Copy, a);

	a[0] = '\0';
	int i;

	//Разделение на строки слова и запись их в массив
	char **Ma, *tmpCell;
	Ma = new char*[81];
	b = strtok(Copy, " ");
	for (i = 0; b; i++)
	{
		Ma[i] = b;
		b = strtok(NULL, " ");
	}

	//Сортировка по длине слова пузырьком
	for (int j = 0; j < i - 1; ++j)
		for (int k = i - 1; k > j; --k)
			if (MyStrlen1(Ma[k]) > MyStrlen1(Ma[k - 1]))
			{
				tmpCell = Ma[k];
				Ma[k] = Ma[k - 1];
				Ma[k - 1] = tmpCell;
			}

	//Объединение в одну строку
	for (int j = 0; j < i; j++)
	{
		strcat(a, Ma[j]);
		strcat(a, " ");
	}

	// Очистка памяти
	delete[]Copy;


}
void AsmStrcat(char *a, char *b) {
	int l1 = MyStrlen1(a);
	int l2 = MyStrlen1(b);
	_asm {
		mov ecx, l2
		inc ecx
		mov edi, a
		mov esi, b
		add edi, l1
		rep movsb
	}
}