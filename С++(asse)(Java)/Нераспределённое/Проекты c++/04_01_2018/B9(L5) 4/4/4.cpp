// 4.cpp: определяет точку входа для консольного приложения.
/*												Задача №B9
Программу написал Владислав Владимирович Перевязчиков.( Специальность: прикладная матнмематика. Группа 8).
Условие :Задан текстовый файл Input.txt, состоящий  из слов и некоторое предложение.
Разделителями между словами является некоторое множество знаков препинания.
Найти  строки, в которых встречается данное предложение, продублировать первое и последнее слова предложений.
Результат записать  в новый файл Output.txt. Упорядочить слова  в искомых предложениях по  убыванию длин слов, результат сортировки
записать в файл Out_sort.txt.
Краткий алгоритм :(Предложение должно начинаться от точки и пробела(если в середине) и заканчиваться ею а также начинаться
с заглавной буквы)
Тесты :*/
// file_read.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio>
#include<cstring>
//#include "conio.h" //для ch=getch(); старая версия

using namespace std;
using std::cin;
using std::cout;

// Знаки припинания
/*
!% ^ & * () – + = {} | ~
[] \; ' : " < > ? , . / #


Названия символов  не алфавитных на английском языке

~ (tilde) - тильда
! (exclamation mark) – восклицательный знак
@ (at) – собачка
# (number или hash) – решетка, диез
$ (dollar) – доллар
% (percent) – процент
^ (caret) – знак вставки
& (ampersand) – и
* (asterisk) – звездочка
( (open или left parenthesis) – открывающая или левая круглая скобка
) (close или right parenthesis) – закрывающая или правая круглая скобка
_ (underscore или horizontal bar) – нижнее подчеркивание или нижняя черта
+ (plus) – плюс
` (acute) – гравис
- (dash или hyphen) – тире или дефис
= (equals) – знак равенства
{ (open или left curly brace) – открывающая или левая фигурная скобка
} (close или right curly brace) – закрывающая или правая фигурная скобка
| (pipe или vertical bar) – вертикальная черта
[ (open или left square bracket) – открывающая или левая квадратная скобка OpenLSqbracket
] (close или right square bracket) – закрывающая или правая квадратная скобка CloseRSqbracket
\ (reverse solidus или backslash) – обратный слеш/ слэш
/ (solidus или forward slash) – слеш/ слэш
: (colon) – двоеточие
" (quote) – кавычки
; (semi colon) – точка с запятой
´ (apostrophe или single quote) – апостроф
< (less than) – знак меньше
> (greater than) – знак больше
? (question mark) – вопросительный знак
, (comma) – запятая
. (dot, period или full stop) – точка )


*/


// Можно и так задать массив
//‘A’,‘B’,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y, // английский алфавит
//А,Б,В,Г,Д,Е,Ж,З,И,Й,К,Л,М,Н,О,П,Р,С,Т,У,Ф,Х,Ц,Ч,Ш,Щ,Ъ,Ы,Ь,Э,Ю,Я,Ё		// руский

// GLOBAL var
// Удобно менять в одно месте

// Переменные для тестирования CHECK->
int CHECK = 1;  // FOR CHECK=1 Да, CHECK=0 -Нет
//int  iwithoutFindWord;
//char StrTmp[MaxSizeStr];
// <-CHECK 



//char string[100] = "строка";
//массив имеет размер 100 символов, 
//но строка в этом массиве имеет длину всего 11 символов.
//если выполнится оператор sizeof(string)ответ будет 100,
//а если — функция strlen(string), ответ 6.
#define MaxSizeStr 100
#define MaxSizeBuff 200
#define MaxSizeWord 50
#define CTOFFER 100 // число предложений
#define CTWord 20 //число слов
//const int MaxSizeStr=100,MaxSizeBuff=200,MaxSizeWord=80;

//Пунктуация

char Dot = '.';  // dot -  точка
char ExPnt = '!'; // exclamation - point Восклицательный знак exclamation mark
char QstMark = '?'; //  ! question mark -вопросительный знак
char Colon = ':';  //  двойная  точка
char Semicolon = ';';  // точка с запятой
char Dash = '-';  // точка с запятой
char Asterisk = '*';  // Звездочка
char Ampersand = '&';// & ampersand
char At = '@';//  @ (at)– собачка
char Dollar = '$';// $(dollar) – доллар
char Caret = '^';    // ^ знак вставки
char OpenLSqbracket = '[';//   [ square left bracket
char CloseRSqbracket = ']';//   [ square left bracket
char OpenParenthesis = '(';// left parenthesis) – открывающая круглая скобка
char CloseParenthesis = ')';//close  parenthesis) – закрывающая  круглая скобка
char Slash = '/'; //слеш / слэшslash
char Comma = ',';   //   comma – запятая
char Percent = '%'; //percent – процент
char Quote = '"';  //quote – кавычки
char Equals = '='; //equals – знак равенства
char Plus = '+';     // +(plus)– плюс
char Underscore = '_';   //underscoreнижняя черта
char LessThan = '<'; // < (less than) – знак меньше
char GreaterThan = '>'; //> (greater than) – знак больше


char Space = ' ';
char EdnStr = '\0';// конец строки

char Punct[] = { Dot, ExPnt, QstMark, Colon, Semicolon, Dash, Asterisk,
Ampersand, At, Dollar, Caret, OpenParenthesis,
CloseParenthesis, OpenLSqbracket, CloseRSqbracket,
Comma, Percent, Quote, Equals, Plus, Underscore, LessThan,
GreaterThan, EdnStr };

//Символы Конца предложения
char EndOffer[] = { Dot, ExPnt, QstMark, EdnStr };
// Буффер символов ВЕРХНЕГО РЕГИСТРА
char UpLetters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н',
'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ',
'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', 'Ё', '\0' };

//char ARRWORD[CTWord][MaxSizeWord];// CTWord*MaxSizeWord
//текст – это группа предложений
// Педложение начинается на UP Предыдущий Space или  
// 

// Знаки пунктуации . , ? !  и т.д;
// Prototype to functions -->
// Реализация за main
void ClearSTR(char* pline);
int SearchEndPozRightWord(const char* pline, const int i);
int InsetSybmBeforeWord(char* pline, char ch);
int InsetSybmAfterWord(char* pline, char ch);
bool TestSymbolEndOffer(char ch);
bool TestEndOffer(char* pline, const int ipos);
bool TestSymbolBeginOffer(char ch);
bool TestBeginOffer(char* pline, const int ipos, const int  iTab);
bool TestSymbolPunct(char ch);
bool TestSymbolPunctORSpace(char ch);
int  GetWordFromStrOnTwoPoz(const char* pStr, char* pWord, const int ibegpos, const int iendpos);
int  GetWordsFromOffer(const char* Offer, char **ARRFWord);
bool  BladderSortARRWORD(const int CTW, char **ARRFWord);

// Separator разделитель
bool  CollectOffer(char* DistStr, char **ARRFWord, const int CTWords,const char chSep);
// <--Prototype to functions -->


int main()

{
	
	int  i, j; // Для итераций	
	bool Stop, YesBeginOFFER, YesEndOFFER, YesLoadOFFER, YesWord, YesSort;
	// 1 -есть Начальный UP символ в строке предпо-го предложения
	int  iTab;// идет табуляция предложение с отступом
	int  iCTStr = 0; // число прочитанных строк
	int  ilen, isizeOFFER;// длина на строки из файла, длина предложения
	int  ibegin, iend; // начало предложения  , конец предложения 
	int  iCTWords = 0; //Число слов
	char ch;	
	
	char StrSource[MaxSizeStr]; // Строка из файла
	char StrOFFER[MaxSizeStr];   //Строка найденное ПРЕДЛОЖЕНИЕ 

	char StrBuff[MaxSizeBuff];
	
	int  iCTOFFER = -1; // число предложений

	//  динамические  массивы
	// **[CTOFFER][MaxSizeStr]  массив указателей на строки
	char **ARROFFER = new char *[CTOFFER];
	for (int i = 0; i < CTOFFER; i++)
	{
		ARROFFER[i] = new char[MaxSizeStr];
		ClearSTR(ARROFFER[i]);
	}
	
	char **ARRSaveOFFER = new char *[CTOFFER];
	for (int i = 0; i < CTOFFER; i++)
	{
		ARRSaveOFFER[i] = new char[MaxSizeBuff];
		ClearSTR(ARRSaveOFFER[i]);
	}

		
	char **ARRSortStr = new char *[CTOFFER]; // массив отсорт-ых строк предложений
	for (int i = 0; i < CTOFFER; i++)
	{
		ARRSortStr[i] = new char[MaxSizeBuff];
		ClearSTR(ARRSortStr[i]);
	}


	char **ARRWords = new char *[CTWord]; // массив слов
	for (int i = 0; i < CTWord; i++)
	{
		ARRWords[i] = new char[MaxSizeWord];
		ClearSTR(ARRWords[i]);
	}


	setlocale(LC_ALL, "rus");

	//setlocale(LC_ALL,".1251");// корректное отображение Кириллицы
	// Символы конца предложения

	// Сдесь  надо вместо "r" "w" -> ios::in ios::out  т.к std Class
	//ios_base::trunc   – удаление содержимого файла при открытии.
	
	ifstream in("input.txt", ios::in);      //   открыли файл для чтения
	ofstream out("output.txt", ios::out | ios_base::trunc);   //  для записи
	ofstream outs("out_sort.txt", ios::out | ios_base::trunc); //  для записи сорт.

	/*
	for(i='A';i<='Z';i++&&j++) 	UpLetters[j]=i;
	for(i='А';i<='Я';i++&&j++)	UpLetters[j]=i;
	UpLetters[j]='Ё';
	UpLetters[j+1]=EdnStr;
	*/


	// On screen
	cout << "START!" << endl;
	cout << "Press Key!" << endl;
	// Команда задержки экрана
	system("pause >> void");	//ch=getch(); старая версия
	//system("pause >> void"); // новая

	cout << " Массив прописных сиволов:" << endl;
	cout << UpLetters << endl;
	cout << "   " << endl;

	if (!in.is_open() || !out.is_open() || !outs.is_open())	       cout << "Ошибка в открытия файла " << endl;
	else
	{//Open File-->

		while (!in.eof())
		{ // ReadFile-->

			//ARRStr[iCTStr] = new char[MaxSizeStr];

			in.getline(StrSource, MaxSizeStr, '\n');
			ilen = strlen(StrSource);

			iCTStr++; //calc line

			// On screen
			cout << "Строка  № " << iCTStr << endl << StrSource << "   " << endl;
			system("pause >> void");



			ClearSTR(StrOFFER);
			ClearSTR(StrBuff);

		//	ClearSTR(WORDtmp1);
		//	ClearSTR(WORDtmp2);
			

			ibegin = 0;
			iend = 0;
			isizeOFFER = 0;
			YesBeginOFFER = false;
			YesEndOFFER = false;
			YesLoadOFFER = false;
			YesWord = false;
			YesSort = false;
			Stop = false;
			if (StrSource[0] == Space) iTab = 1;
			else iTab = 0;

			for (i = 0; i < ilen && !Stop; i++)
			{ // Cycle FIND OFFER in StrSource-> , 
				//Цикл поиск предложения в строке  input.txt
				// Табуляция
				if (i>0 && iTab == 1)
				{
					if (StrSource[i - 1] = Space)iTab = 1;
					else if (StrSource[i] = Space) continue;
				}

				if (TestBeginOffer(StrSource, i, iTab))
				{ // Find Position End Offer --> 
					cout << "Начало предложния : " << "Символ : " << StrSource[i];
					cout << " Позиция : " << i << endl;
					system("pause >> void");
					YesBeginOFFER = true;
					ibegin = i;
					for (j = i; j < ilen && !YesEndOFFER; j++)
					if (TestEndOffer(StrSource, j))
					{
						YesEndOFFER = true;
						iend = j;
						isizeOFFER = iend - ibegin;
						cout << "Конец предложния : " << "Символ : " << StrSource[j];
						cout << " Позиция : " << j << endl;
						system("pause >> void");
					}
				}//<-- Find  Offer 

				YesLoadOFFER = false;




				if (YesBeginOFFER && YesEndOFFER && GetWordFromStrOnTwoPoz(StrSource, StrOFFER, ibegin, iend)>0)
				{  // Get OFFER-->// Если> 0 - Нашли
					 iCTOFFER++;

					// ARROFFER[iCTOFFER] = new char[MaxSizeStr];  // Предложение  в массив
					// ClearSTR(ARROFFER[iCTOFFER]);
                    
					 strcpy_s(ARROFFER[iCTOFFER], MaxSizeStr, StrOFFER);
					
					// ARRSaveOFFER[iCTOFFER] = new char[MaxSizeStr]; 
					// ClearSTR(ARRSaveOFFER[iCTOFFER]);
					

				  //	 ARRSortStr[iCTOFFER] = new char[MaxSizeBuff];// Предложение  в массив


					YesLoadOFFER = true;
					cout << "Предложение: " << StrOFFER << endl;
					system("pause >> void");

				} //<-- Get OFFER, Есть предложение 

				if (YesLoadOFFER)
				{
					cout << "Начать поиск слов: " << endl;
					system("pause >> void");
					iCTWords = GetWordsFromOffer(StrOFFER, ARRWords);

					if (iCTWords> 0)
					{
						cout << " Число слов: " << iCTWords << endl;
						YesWord = true;

						//сохранить знак в конце прендложения   . !  ? 
						ilen = strlen(StrOFFER);
						ch = StrOFFER[ilen - 1];
						StrOFFER[ilen - 1] = EdnStr;
						
						ClearSTR(StrBuff);
						strcpy_s(StrBuff, MaxSizeBuff, ARRWords[0]);
						cout << "Первое слово : " << ARRWords[0] << endl;
						system("pause >> void");

						InsetSybmAfterWord(StrBuff, ' ');
						strcat_s(StrBuff, MaxSizeBuff, ARRWords[0]);
						strcat_s(StrBuff, MaxSizeBuff, StrOFFER);
						strcpy_s(ARRSaveOFFER[iCTOFFER], MaxSizeBuff, StrBuff);
					
						ClearSTR(StrBuff);
						if (iCTWords > 1)
						{
							strcpy_s(StrBuff, MaxSizeBuff, ARRWords[iCTWords - 1]);
							cout << "Последнее слово: " << ARRWords[iCTWords - 1] << endl;
							system("pause >> void");
							InsetSybmBeforeWord(StrBuff, ' ');
							strcat_s(StrBuff, MaxSizeBuff, ARRWords[iCTWords - 1]);
							//восстановит знак в конце строки 
							InsetSybmAfterWord(StrBuff, ch);
							strcpy_s(ARRSaveOFFER[iCTOFFER], MaxSizeBuff, StrBuff);
						}

						//сортировка 
						YesSort = BladderSortARRWORD(iCTWords, ARRWords);
						cout << "ПАКАЗ Сортировки слов:" << endl;
						for (i = 0; i < iCTWords; i++) cout << ARRWords[i] << endl;
                        
						// Собрать предложение
					
                        CollectOffer(ARRSortStr[iCTOFFER],ARRWords, iCTWords, Space);
						cout << "Отсортированное предложение:" << ARRSortStr[iCTOFFER] << endl;
						
						cout << " " << endl;
						system("pause >> void");
					}

				}
				
				if (YesLoadOFFER) Stop = true;
				
			}  // <- Cycle FIND OFFER in StrSource

		}//<-- ReadFile


		cout << "Предложения до сортировки" << endl;
		for (i = 0; i <iCTOFFER; i++) cout << ARROFFER[i] << endl;
		cout << " - - " << endl;	

        cout << "Предложения после сортировки" << endl;
		for (i = 0; i <iCTOFFER; i++) cout << ARRSortStr[i] << endl;	
        cout << " - - " << endl;

		outs << "Предложения до сортировки" << endl;
		for (i = 0; i <iCTOFFER; i++) outs << ARROFFER[i] << endl;
		outs << " - - " << endl;
			
		outs << "Предложения после сортировки" << endl;
		for (i = 0; i <iCTOFFER; i++) outs << ARRSortStr[i] << endl;


		in.close();
		out.close();
		outs.close();


	}//<-- Open File


	cout << "Освобождение ПАМЯТИ !!!" << endl;
	// ОСВОБОЖДЕНИЕ ПАМЯТИ
	for (int i = 0; i < CTOFFER; i++)  delete[] ARROFFER[i];
		delete [] ARROFFER;

	for (int i = 0; i < CTOFFER; i++)  delete[] ARRSortStr[i];
		delete [] ARRSortStr;

	for (int i = 0; i < iCTWords; i++)  delete[] ARRWords[i];
		delete []ARRWords;


	// On screen
	cout << " - -  " << endl;
	cout << " Конец " << endl;
	cout << " - - - " << endl;
	cout << "Press Key!" << endl;
	system("pause");
	return 0;


}



void ClearSTR(char* pline)
{
	//memset(pline, NULL, sizeof(pline)-1);
	int i;
	int isize;
	isize = sizeof(pline);
	if (isize == 0) return;
	else
	for (i = isize - 1; i >= 0; i--) pline[i] = EdnStr;
}

bool TestSymbolBeginOffer(char ch)
{
	if (ch == Dot || ch == ExPnt || ch == QstMark) return true;
	else return false;
}


bool TestBeginOffer(char* pline, const int ipos, const int  iTab)
{
	int ilen;
	ilen = strlen(pline);
	bool Yes;
	Yes = false;

	if (ipos < ilen && strchr(UpLetters, pline[ipos]) != NULL)
	{
		if (ipos == 0) Yes = true;
		if (ipos == 1 && (pline[ipos - 1] == Space)) Yes = true;

		if (ipos>1)
		{
			if ((iTab > 0) || ((pline[ipos - 1] == Space) &&
				(strchr(EndOffer, pline[ipos - 2]) != NULL))) Yes = true;
		}

	}
	return Yes;
}


bool TestSymbolEndOffer(char ch)
{
	if (strchr(EndOffer, ch) != NULL)return true;
	else return false;

}


bool TestEndOffer(char* pline, const int ipos)
{
	int ilen;
	ilen = strlen(pline);
	bool Yes;
	Yes = false;
	/*isspace(pline[ipos + 1]) требует unsignedchar проблема с UNICODE*/
	if (ipos <= ilen && TestSymbolEndOffer(pline[ipos]))
	{
		if (ipos == ilen)Yes = true;
		else if (TestSymbolEndOffer(pline[ipos]) && (pline[ipos + 1] = Space)) Yes = true;
		//iswspace  для UNICODE
	}
	return Yes;
}




bool TestSymbolPunct(char ch)
{
	// для UNICODE iswpunct   для Multi-Byte (ispunct(ch)	
	//	 ispunct Дает сбой при отрицателном значении
	if (strchr(Punct, ch) != NULL) return true;
	else return false;
	//	if (ispunct(ch) > 0) return true;
	//	else return false;
	// 
}




bool TestSymbolPunctORSpace(char ch)
{
	if (strchr(Punct, ch) != NULL || ch == Space) return true;
	else return false;
}


int InsetSybmBeforeWord(char* pline, char ch)
{
	int i = 1;
	int ilen;
	ilen = strlen(pline);
	if (ilen + 1 > MaxSizeStr) return 0;
	for (i = ilen; i>0; i--) pline[i] = pline[i - 1];
	pline[i] = ch;
	pline[ilen + 1] = EdnStr;
	return ilen + 1;
}

int  InsetSybmAfterWord(char* pline, char ch)
{
	int ilen;
	ilen = strlen(pline);
	if (ilen + 1 > MaxSizeStr) return 0;
	// Set In end str
	pline[ilen] = ch;
	pline[ilen + 1] = EdnStr;
	return ilen + 1;
}


// pStr -исхонная строка / PWord-слово / ibegpos- поз.начала / iendpos- поз.конца
int  GetWordFromStrOnTwoPoz(const char* pStr, char* pWord, const int ibegpos, const int iendpos)
{
	int ilenStr, isize;
	int i, j;
	ilenStr = strlen(pStr);
	isize = sizeof(pWord);
	for (i = isize - 1; i >= 0; i--) pWord[i] = EdnStr;
	//memset(pWord, NULL, sizeof(pWord)-1);

	if (ilenStr = 0 || ibegpos > iendpos) return 0;
	for (i = ibegpos, j = 0; i <= iendpos; i++, j++)  pWord[j] = pStr[i];

	pWord[j++] = EdnStr;
	return strlen(pWord);//
}


int  GetWordsFromOffer(const char* Offer, char **ARRFWord)
{
	int i = 0, j, k; // 
	int iw = 0;      // доступ к строкам массива ARRFWord
	int ilen = strlen(Offer);
	if (ilen == 0) return 0;

	for (i = 0; Offer[i] != EdnStr; i++)
	if (!TestSymbolPunctORSpace(Offer[i]))
	{
		for (j = i, k = 0; !TestSymbolPunctORSpace(Offer[j]) && Offer[j] != EdnStr; j++)
		if (!TestSymbolPunctORSpace(Offer[j])) ARRFWord[iw][k++] = Offer[j];

		ARRFWord[iw][k++] = EdnStr;
		i = j;
		iw++;
	}

	return iw;
}




// ПОКА не использовать НЕ ДОРАБОТАНА 

bool  BladderSortARRWORD(const int CTW, char **ARRFWord)
{
	int i, j;
	char* pstr; //указатель на строку
	if (CTW == 0) return false;
	//пузырковая сортировка 
	for (j = 0; j<CTW - 1; j++) //количество прогонов
	for (i = CTW - 1; i > 0; i--)
		// если нижняя меньше верхней меняем
	if (strlen(ARRFWord[i]) < strlen(ARRFWord[i - 1]))
	{  // Меняем местами указатели
		pstr = ARRFWord[i-1];
		ARRFWord[i-1] = ARRFWord[i];
		ARRFWord[i] = pstr;
	}

	return true;

}



bool  CollectOffer(char* DistStr, char **ARRFWord, const int CTWords,const char chSep)
{
int i;
if (CTWords == 0) return false;
ClearSTR(DistStr);
for (i = 0; i <CTWords; i++)
{
	strcat_s(DistStr, MaxSizeBuff, ARRFWord[i]);
	InsetSybmAfterWord(DistStr, chSep);
}
return true;
}