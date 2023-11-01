//Бондарчук Владимир
//Группа 8, курс 1
//лаб 5
//
//2. Задан текстовый файл Input.txt, состоящий  из слов.
//Разделителями между словами являются некоторое множество знаков препинания.
//Удалить из каждой строки, начиная со второй слова,
//которые встречаются в первой строке и  записать результат  в новый файл Output.txt.
//Упорядочить слова  в полученных  строках по  возрастанию количества цифр в словах,
//результат сортировки записать в файл Out_sort.txt.
//
//
//
//Алгоритм:
//записываем первую строку в динамический массив указателей.
//В цикле записываем следущие строки в массив указателей и проверяем на совпадение слов,
//если слово совпадает то, его не записываем в результирующую строку. 
//Далее сортируем слова по количеству цифр в слове.
//
//тесты:
//Input.txt :
//voi12d, ma4in; in5t!i890f.vi5su7al ? vs4 doub6le123 : so4rt
//inc21lude1111 in5t.do3, vs4!for; strtok
//if st33rcpy!vi5su7al ? while12 brea3k
//got3o do3 i890f::re4t3urn : !br422ea2k
//st22rtok ? .swap4 ? .iostream doub6le123

//Output.txt:
//inc21lude1111 do3 for strtok
//if st33rcpy while12 brea3k
//got3o do3 re4t3urn br422ea2k
//st22rtok swap4 iostream

//Out_Sort.txt
//for strtok do3 inc21lude1111
//if brea3k st33rcpy while12
//got3o do3 re4t3urn br422ea2k
//iostream swap4 st22rtok


#define _CRT_SECURE_NO_WARNINGS
#include  <fstream>
#include <iostream>
#include <cstring>
using namespace std;
int STRLEN(char* a);
int NUMCOUNT(char* s);//нахождение количества цифр в слове
void STRCPY(char *s1, char *s2);
void STRCAT(char *a, char *b);
void proverka(int j, int i, char **matr1, char **matr2, char *res);//проверка на совпадение слов
void sort(int j, char **matr2); //сортировка по количеству цифр в слове
int main()
{
	int i, j, q, z;
	char str1[81]; str1[0] = '\0';
	char str2[81]; str2[0] = '\0';
	char R[] = " ,.;:!?";
	char res[81];
	char res2[81];
	res[0] = '\0';
	res2[0] = '\0';

	// Потоки ввода и вывода
	ifstream fin;
	fin.open("Input.txt");
	ofstream fout;
	fout.open("Output.txt");
	ofstream fout2;
	fout2.open("Out_sort.txt");

	fin.getline(str1, 81);
	//Запись 1-ой строки в динамический массив указателей
	char *word1 = strtok(str1, R);
	char **matr1 = new char*[20];
	for (i = 0; word1 != '\0'; i++)
	{
		matr1[i] = word1;
		word1 = strtok(NULL, R);
	}
	while (!fin.eof())  //пока не кончтся строки
	{
		res[0] = '\0';
		res2[0] = '\0';
		int Flag = 0;
		fin.getline(str2, 81);

		//Запись n-ой строки в динамический массив указателей
		char **matr2 = new char *[20];
		char *word2 = strtok(str2, R);
		for (j = 0; word2 != '\0'; j++)
		{
			matr2[j] = word2;
			word2 = strtok(NULL, R);
		}
		proverka(j, i, matr1, matr2, res); //проверка на совпадение элементов 1-ой и n-ой строки (запись результата в res)
		fout << res << endl;               //запись в Output.txt
		sort(j, matr2);                    //сортировка слов по количеству цифр (запись результата в res 2)
		proverka(j, i, matr1, matr2, res2);//проверка на совпадение элементов 1-ой и n-ой строки (запись результата в res2)
		fout2 << res2 << endl;		       //запись в Out_sort.txt
	}
	fout2.close();
	fout.close();
	fin.close();
	system("pause");
	return 0;
}
void proverka(int j, int i, char **matr1, char **matr2, char *res) //проверка на совпадение слов
{
	int Flag = 0;
	for (int q = 0; q < j; q++)
	{
		for (int z = 0; z < i; z++)
			if (strcmp(matr1[z], matr2[q]) == 0) Flag++;
		if (Flag == 0)
		{
			STRCAT(res, matr2[q]);
			STRCAT(res, " ");
		}
		else Flag = 0;
	}
}
void sort(int j, char **matr2) //сортировка по количеству цифр в слове
{
	int h;
	char *temp;
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (h = 0; h < j - 1; h++)
		{
			if (NUMCOUNT(matr2[h])> NUMCOUNT(matr2[h + 1]))
			{
				temp = matr2[h];
				matr2[h] = matr2[h + 1];
				matr2[h + 1] = temp;
				exit = false;
			}
		}
	}
}
int STRLEN(char* a)
{
	int i;
	_asm
	{
		cld

		mov eax, 0 // eax = 0
		mov ecx, 0
		dec ecx  
		mov edi, a 
		repne scasb // идем побайтово по edi , пока не встретим 0
		not ecx      // инвертируем побайтово ecx
		dec ecx
		mov i, ecx
	}
	return i;
}
int NUMCOUNT(char* s) //нахождение количества цифр в слове
{
	int i = 0;
	_asm
	{
		mov esi, s
		mov edi, 0
		METKA1: mov al, byte ptr[esi]

				cmp[esi], '\0'
				je METKA2
				inc esi
				cmp al, '0'
				jb METKA1
				cmp al, '9'
				ja METKA1
				inc edi
				cmp[esi], '\0'
				jne METKA1
				METKA2:
				mov i, edi
			
	}
	return i;
}
void STRCPY(char *s1, char *s2)
{
	int c = STRLEN(s2);
	_asm
	{
		cld
		mov ecx, c
		inc ecx
		mov esi, s2
		mov edi, s1
		rep movs    
	}
}
void STRCAT(char *a, char *b)
{
	int l1 = STRLEN(b);
	int l2 = STRLEN(a);
	_asm
	{
		cld
		mov ecx, l1
		inc ecx
		mov esi, b
		mov edi, a
		add edi, l2
		rep movsb // перекидывает побайтово из esi в edi
	}
}






