/*
==============================================================
Учебная Практика
Задание 2.0
Задание B1
--------------------------------------------------------------
Выполнил студент 1 курса 8 группы
Афанасенко Алексей
--------------------------------------------------------------
Условие: Задан текстовый файл Input.txt, состоящий  из слов.
Разделителями между словами являются некоторое множество 
знаков препинания. Из каждой строки удалить слова, длина
которых больше длины последнего слова этой строки и 
записать эти строки в новый файл Output.txt.
Упорядочить слова в полученных строках по возрастанию длин, 
результат сортировки записать в файл Out_sort.txt. 
Реализовать функцию strcmp на языке ассемблера используя цепочечные команды.
--------------------------------------------------------------
Пояснение к решению:

Пойдем от конца строки и найдем длину последнего слова, затем
будем обрабаывать строку посимвольно и находя каждое новое слово,
добавлять его в новую строку. Выведем новую строку. Отсортируем слова
в новой строке и выведем в другой файл новую строку.
--------------------------------------------------------------
Пример №1:

input.txt:
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
-------------
output.txt:
Lorem ipsum dolor sit amet elit sed do tempor ut labore et dolore magna aliqua
Ut enim ad quis nisi ut ex ea Duis aute
irure dolor in in velit esse cillum dolore eu fugiat nulla pariatur
sint non sunt in culpa qui officia mollit anim id est laborum
-------------
Out_sort.txt:
Lorem aliqua amet do dolor dolore elit et ipsum labore magna sed sit tempor ut
Duis Ut ad aute ea enim ex nisi quis ut
cillum dolor dolore esse eu fugiat in in irure nulla pariatur velit
anim culpa est id in laborum mollit non officia qui sint sunt
==============================================================
*/

#include <iostream>
#include <fstream>
#include <locale.h>
#include <string.h>

/*Максимальная длина строки*/
#define MAXLENGTH 1000
/*Максимальное кол-во слов в строке*/
#define MAXWORDCOUNT 1000

using namespace std;


bool isLetter(char c) // проверка что символ C это буква
{
	if (((c >= 'A') && (c <= 'Z')) ||
		((c >= 'a') && (c <= 'z')) ||
		((c >= 'А') && (c <= 'Я')) ||
		((c >= 'а') && (c <= 'я')))
		return 1;
	return 0;
}

int strcmp2(char *a, char *b)
{
	int lenA = strlen(a), lenB = strlen(b), ans = 0;
	_asm
	{
		mov ecx, lenA
		cmp ecx, lenB
		jl comp
		mov ecx, lenB
	comp:
		mov esi, a
		mov edi, b
		repe cmpsb
		je _eq
		dec esi
		dec edi
	_eq:
		xor eax, eax
		mov al, [esi]
		sub al, [edi]
		cbw
		cwde
		mov ans, eax	
	}
	return ans;
}

void addWord(char **words, char *s, int st, int en, int &wordCount)
{
	/*Если первый символ не буква, значит это не слово*/
	if (!isLetter(s[st])) return;

	words[wordCount] = new char[en - st + 2];

	/*Копируем строку*/
	char *p = words[wordCount];
	int start = st;

	_asm
	{
		mov esi, s
		mov edi, p
		mov eax, start
		add esi, eax
		mov ecx, en
		sub ecx, eax
		inc ecx
		rep movsb
	}

	/*Добавляем 0 символ*/
	words[wordCount][en - st + 1] = '\0';

	wordCount++;

	return;
}

void swap(char *&a, char *&b)
{
	char *t = a;
	a = b;
	b = t;
}

void qsortt(char** a, int l, int r)
{
	int i = l, j = r;
	char *x = a[rand() % (r - l + 1) + l];

	do {
		while (strlen(a[i]) < strlen(x)) i++;
		while (strlen(a[j]) > strlen(x)) j--;

		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < r)
		qsortt(a, i, r);
	if (l < j)
		qsortt(a, l, j);

}

void out_words(ofstream &fout, char **words, int wordCount)
{
	for (int i = 0; i < wordCount; i++)
		fout << words[i] << " ";
	fout << endl;
}

void solve(ifstream &fin, ofstream &fout, ofstream &fsort)
{

	char *s, **words;
	int wordCount = 0, len, j, i, endLen;
	// s - текущей строка
	// words - массив слов
	// wordCount - количество слов
	// len - длина строки
	// j - указатель на первую букву слова
	// i - указатель на последнюю букву слова
	// endLen - длина последнего слова


	/*Выделение памяти*/
	words = new char*[MAXWORDCOUNT];
	s = new char[MAXLENGTH];

	while (fin.getline(s, MAXLENGTH))
	{
		len = strlen(s);

		/*Длина последнего слова*/
		i = len - 1;
		while ((i >= 0) && (!isLetter(s[i]))) i--;
		if (i < 0) continue;
		j = i;
		while ((j >= 0) && (isLetter(s[j]))) j--;
		endLen = i - j;

		/*Поиск слов*/
		wordCount = 0;
		j = 0;
		for (i = 0; i <= len; i++)
		{
			/*Ищем слова*/
			while ((i < len) && (isLetter(s[i]))) i++;
			/*Если длина слова меньше длины последнего слова*/
			if (i - j <= endLen) addWord(words, s, j, i - 1, wordCount);
			/*Пропускаем разделители*/
			while ((i < len) && (!isLetter(s[i]))) i++;
			j = i;
		}

		/*Вывод слов*/
		out_words(fout, words, wordCount);

		/*Сортировка слов в строке*/
		qsortt(words, 0, wordCount - 1);

		/*Вывод отсортированных слов*/
		out_words(fsort, words, wordCount);

		/*Освобождение памяти под слова*/
		for (i = 0; i < wordCount; i++)
			delete[] words[i];

	}

	/*Освобождение памяти, закрытие файлов*/
	delete[] words;
	delete[] s;
	fin.close();
	fout.close();
	fsort.close();

}


int main()
{
	setlocale(LC_ALL,"rus");
	ifstream fin;
	ofstream fout, fsort;

	/*Открытие файлов*/
	fin.open("input.txt");
	if (!fin)
	{
		cout << "Error: ошибка открытия файла \"input.txt\". Проверьте его наличие в папке с программой";
		system("pause");
		exit(0);
	}
	fout.open("output.txt");
	fsort.open("Out_sort.txt");

	/*Вывод*/
	solve(fin, fout, fsort);

	/*ПРОВЕРКА СВОЕЙ ФУНКЦИИ STRCMP*/
	char a[100], b[100];
	cout << "Введите две строки которые вы хотите сравнить: " << endl;
	cin.getline(a, 80);
	cin.getline(b, 80);
	cout << "Результат сравнения: " << strcmp2(a, b) << endl;

	return 0;
}