// TestGetWords.cpp: определяет точку входа для консольного приложения.
//
// GetWords.cpp : Defines the entry point for the console application.

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

using namespace std;
using std::cin;
using std::cout;

//Знаки пунктуации это . , ? ! ' -

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
#define CTWord 10 //число сло
//const int MaxSizeStr=100,MaxSizeBuff=200,MaxSizeWord=80;

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

//Пунктуация

char Dot = '.';  // dot -  точка
char ExPnt = '!'; // exclamation - point Восклицательный знак exclamation mark
char QstMark = '?'; //  ! question mark -вопросительный знак
char Colon = ':';  //  двойная  точка
char Semicolon = ';';  // точка с запятой
char Dash = '-';  // точка с запятой
char Asterisk = '*';  // Звездочка
char Ampersand='&';// & ampersand
char At = '@';//  @ (at)– собачка
char Dollar = '$';// $(dollar) – доллар
char Caret='^';    // ^ знак вставки
char OpenLSqbracket = '[';//   [ square left bracket
char CloseRSqbracket = ']';//   [ square left bracket
char OpenParenthesis = '(';// left parenthesis) – открывающая круглая скобка
char CloseParenthesis = ')';//close  parenthesis) – закрывающая  круглая скобка
char Slash= '/' ; //слеш / слэшslash
char Comma = ',';   //   comma – запятая
char Percent= '%'; //percent – процент
char Quote= '"';  //quote – кавычки
char Equals = '='; //equals – знак равенства
char Plus='+';     // +(plus)– плюс
char Underscore = '_';   //underscoreнижняя черта
char LessThan = '<'; // < (less than) – знак меньше
char GreaterThan = '>'; //> (greater than) – знак больше


char Space = ' ';
char EdnStr = '\0';// конец строки

//End Offer - Конец предложения
char EndOffer[] = { Dot, ExPnt, QstMark, EdnStr };
//char UpLetters[MaxSizeStr];
//Буффер символов Пунктуации
char Punct[] = { Dot, ExPnt, QstMark, Colon, Semicolon, Dash, Asterisk, 
                 Ampersand, At, Dollar, Caret, OpenParenthesis, 
				 CloseParenthesis, OpenLSqbracket, CloseRSqbracket,
				 Comma, Percent, Quote, Equals, Plus, Underscore, LessThan, 
				 GreaterThan,EdnStr };

// Буффер символов ВЕРХНЕГО РЕГИСТРА
char UpLetters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н',
'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ',
'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', 'Ё', '\0' };



char ARRWORD[CTWord][MaxSizeWord + 1];
//текст – это группа предложений
// Педложение начинается на UP Предыдущий Space или  

// Prototype to functions -->
// Realization for main ,Реализация за main
void ClearSTR(char* pline);
//int TestSymbolEndOffer(char ch);
int SearchEndPozRightWord(const char* pline, const int i);
int InsetSybmBeforeWord(char* pline, char ch);
int InsetSybmAfterWord(char* pline, char ch);

bool TestSymbolEndOffer(char ch);
bool TestEndOffer(char* pline, const int ipos);

//int FindOffer(char* pline, const int ipos, const int  iTab);

bool TestSymbolBeginOffer(char ch);
bool TestBeginOffer(char* pline, const int ipos, const int  iTab);

bool TestSymbolPunct(char ch);
bool TestSymbolPunctORSpace(char ch);


// pStr -исхонная строка / PWord-слово / ibegpos- поз.начала / iendpos- поз.конца
int  GetWordFromStrOnTwoPoz(const char* pStr, char* pWord, const int ibegpos, const int iendpos);

int  GetWordsFromOffer(const char* Offer);
//int  GetWordsFromOffer(const char* Offer);
//int  SearchPosEndWord(const char* pline, const int curpos);

/*
int  SearchEndPozLeftWord(const char* pline, const int i);

// pStr -исхонная строка / PWord-слово / ibegpos- поз.начала
// первое слово с позиции поиск влево
int  GettWordFromStrOnPozLeft(const char* pStr,char* pWord,const int ibegpos);

// pStr -исхонная строка / PWord-слово / iendpos- поз.конца сипроки
int  GetWordFromStrOnPozRight(const char* pStr,char* pWord,const int iendpos);
*/
// <--Prototype to functions -->


int main()

{
	//bool Stop, YesBeginOFFER, YesEndOFFER, YesLoadOFFER, 
	//bool 	YesWord;//, YesWord2; // Для итераций 1=true  0=false
	// 1 -есть Начальный UP символ в строке предпо-го предложения
//	int  iTab;// идет табуляция предложение с отступом
	int  iCTStr = 0; // число прочитанных строк
	char StrSource[MaxSizeStr]; // Строка из файла
	char StrFind[MaxSizeStr];   //Строка Find/ найденное ПРЕДЛОЖЕНИЕ 
	char StrSave[MaxSizeBuff];


	// Для ОТЛАДКИ -->
	//char StrBag[MaxSizeStr+1]; 

	char WORDtmp1[MaxSizeWord], WORDtmp2[MaxSizeWord]; // Слова с Space до и после слова
	//  массив слов

	int  ilen;// , isizeOFFER;// длина на строки из файла, длина предложения
//	int  ibegin, iend; // начало предложения  , конец предложения 
	int iCTWords = 0;
	char ch;
int  i=0, j=0; // Для итераций	

	//setlocale(LC_ALL, "rus");
	setlocale(LC_ALL,".1251");// корректное отображение Кириллицы
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
	//ch=getch(); старая версия
	//system("pause >> void"); // новая



	cout << " Массив прописных сиволов:" << endl;
	cout << UpLetters << endl;
	cout << "   " << endl;
	//system("pause >> void");


	
	for (i = 0; i <= CTWord; i++)  ClearSTR(ARRWORD[i]);


	if (!in.is_open() || !out.is_open() || !outs.is_open())
		cout << "Ошибка в открытия файла " << endl;
	else
	{//Open File-->
		while (!in.eof())
		{ // ReadFile-->
			iCTStr++; //calc line
			ClearSTR(StrSource);
			ClearSTR(StrFind);
			ClearSTR(WORDtmp1);
			ClearSTR(WORDtmp2);
			ClearSTR(StrSave);

			in.getline(StrSource, 100, '\n');
			ilen = strlen(StrSource);



			// On screen
			cout << "Строка  № " << iCTStr << endl << StrSource << "   " << endl;
		//	system("pause >> void");

			cout << "StrFind " << StrFind << "   " << endl;
			//	system("pause >> void");
			strcpy_s( StrFind,StrSource);




					// On screen
					cout << "СТАРТ " << endl;
					cout << "Test разбора на слова 	" << StrFind << endl;
									//system("pause >> void"); 
					
					//<--TEST ERROR BLOK-->	
					    int iw=0 ;    // доступ к строка массива ARRWORD
					
						/*
					      //int ib=0,ie,
							int k=0 ;// ; // i begin  , j end Word
							
							//int iCT = 0;  // число слов
							//int isize=0; // длина слова
							//bool YesBeg,YesEnd;

							int ilen = strlen(StrFind);
							iCTWords = 0;
							 iw = 0;
							 for (i = 0; StrFind[i] != EdnStr; i++)
							 if (!TestSymbolPunctORSpace(StrFind[i]))
							 {
								 //char word[256] = "\0", pchars[256] = ".,!";
								// ClearSTR(ARRWORD[iw]);
								 for (j = i, k = 0; !TestSymbolPunctORSpace(StrFind[j]) && StrFind[j] != EdnStr; j++)
								 if (!TestSymbolPunctORSpace(StrFind[j])) ARRWORD[iw][k++] = StrFind[j];//Bufffer[k++] = StrFind[j];
								 ARRWORD[iw][k++] = EdnStr;

								// cout << "Bufffer:" << "["<<Bufffer <<"]" << endl;
								 //  system("pause >> void");
								  cout << "ARRWORD:" << ARRWORD[iw] << endl;
								  system("pause >> void");
								 i = j;
								 iCTWords++;
								 iw++;
							   }

*/
					
						iCTWords=GetWordsFromOffer(StrFind);
				//<--TEST ERROR BLOK	
						cout << " Число слов: " << iCTWords << endl;
						system("pause >> void");
						if (iCTWords > 0)
						{
							//сохранить знак в конце строки . !  ? ..
							ch = StrFind[ilen - 1];
							StrFind[ilen - 1] = EdnStr;
            				// strcpy -старая Эта функция может быть небезопасной.
							strcpy_s(WORDtmp1,ARRWORD[0]);
							cout << "Первое слово:" << "[" << WORDtmp1 << "]" << endl;

							system("pause >> void");

							InsetSybmAfterWord(WORDtmp1,Space);
							strcat_s(StrSave, WORDtmp1);
							strcat_s(StrSave,StrFind);
							if (iCTWords > 1)
							   {
								strcpy_s(WORDtmp2,ARRWORD[iCTWords -1]);
								cout << "Последнее слово:" <<"[" << WORDtmp2 <<"]"<< endl;
								system("pause >> void");
								InsetSybmBeforeWord(WORDtmp2,Space);
								
								strcat_s(StrSave, WORDtmp2);
                              //восстановит знак в конце строки 
		  					  InsetSybmAfterWord(StrSave, ch);
        
       							   }


					      }

	
						/*
		        if (iCTWords==0)
				{
					cout << " Ошибка поиска слов" << StrSave << endl;
					cout << "   " << endl;
					  system("pause >> void");
				}
			*/
			cout << "SAVE output.txt :" << endl;
			system("pause >> void");

			if (iCTWords>0)
			{
			  cout << "Слова: ";
			  for (i = 0; i <= iCTWords - 1; cout << "[" << ARRWORD[i] << "]", i++);
		        cout << endl;
   			    cout << "  "<<"Слово1+Предложение+Слово2:" << StrSave << endl;
				out << StrSave << endl;
				cout << "   " << endl;
				system("pause >> void");
			}
			else
			{
				//On screen
				cout << "SAVE- Исходную строку: " << StrSource << endl;
				out << StrSource << endl;
				cout << "   " << endl;
				system("pause >> void");
                
			}


		}//<-- ReadFile


		in.close();
		out.close();
		outs.close();
	}//<-- Open File

	// On screen
	cout << " - -  " << endl;
	cout << " Конец " << endl;
	cout << " - - - " << endl;
	//system("pause");	
	return 0;


} //<- main




void ClearSTR(char* pline)
{
	//memset(pline, NULL, sizeof(pline)-1); // попробовать EdnStr
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

	if (ipos <= ilen && TestSymbolEndOffer(pline[ipos]))
	{
		if (ipos == ilen)Yes = true;
		else if (TestSymbolEndOffer(pline[ipos]) && isspace(pline[ipos + 1])) Yes = true;
	}
	return Yes;
}


/*
int FindOffer(char* pline, const int ipos, const int  iTab)
{
int i=0,j=0, ilen,iPos=0;
//bool result;
ilen = strlen(pline);

if (ilen == 0) iPos = 0;
else
{
for (i = 0; i <= ilen; i++) pline[i + 1] = pline[i];

if (ipos >= ilen)iPos = 0;
else {
if (strchr(UpLetters, pline[ipos]) != NULL)
{
if (ipos == 0) result = true;
else if ((ipos == 1) && (pline[ipos - 1] == Space)) result = true;
else if ((ipos>1) && ((iTab>0) || ((pline[ipos - 1] == Space) &&
(strchr(EndOffer, pline[ipos - 2]) != NULL))))result = true;
}
else result = false;
}

return iPos;
}
*/


bool TestSymbolPunct(char ch)
{
	if (strchr(Punct, ch) != NULL) return true;
	else return false;
}

/*	
ispunct(ch) --Дает сбой при отрицателном значении
if (ispunct(ch) > 0) return true;
	else return false;
*/




bool TestSymbolPunctORSpace(char ch)
{
	if ( strchr(Punct, ch) != NULL || ch == Space) return true;
	else return false;

/*	if (((ispunct(ch) > 0) || (ch == Space)))return true;
	else return false;
*/
}


int InsetSybmBeforeWord(char* pline, char ch)
{
	int i = 1;
	int ilen;
	ilen = strlen(pline);
	if (ilen + 1 > MaxSizeStr) return 0;
	for (i = ilen; i>0; i--) pline[i] = pline[i-1];
	pline[i] = ch;
    pline[ilen+1] = EdnStr;
	return ilen + 1;

	/* алгоритм
	for (i = strlen(s); i > 0; i--)
		s[i] = s[i - 1];
	s[i] = ' ';
	*/
}

int  InsetSybmAfterWord(char* pline, char ch)
{
	char *StrTmp = new char[MaxSizeStr];
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

/*
iCTWords = 0;
iw = 0;
for (i = 0; StrFind[i] != EdnStr; i++)
if (!TestSymbolPunctORSpace(StrFind[i]))
{
//char word[256] = "\0", pchars[256] = ".,!";
// ClearSTR(ARRWORD[iw]);
for (j = i, k = 0; !TestSymbolPunctORSpace(StrFind[j]) && StrFind[j] != EdnStr; j++)
if (!TestSymbolPunctORSpace(StrFind[j])) ARRWORD[iw][k++] = StrFind[j];//Bufffer[k++] = StrFind[j];
ARRWORD[iw][k++] = EdnStr;

// cout << "Bufffer:" << "["<<Bufffer <<"]" << endl;
//  system("pause >> void");
cout << "ARRWORD:" << ARRWORD[iw] << endl;
system("pause >> void");
i = j;
iCTWords++;
iw++;
}
*/

//char ARRWORD[CTWord][MaxSizeWord + 1]
int  GetWordsFromOffer(const char* Offer)
//int  GetWordsFromOffer(const char* Offer)
{
	int i = 0, j, k; // 
	int iw = 0;    // доступ к строка массива ARRWORD
	int iCT = 0;  // число слов
	int ilen = strlen(Offer);
	if (ilen = 0) return 0;

	for (i = 0; Offer[i] != EdnStr; i++)
	if (!TestSymbolPunctORSpace(Offer[i]))
	{
		for (j = i, k = 0; !TestSymbolPunctORSpace(Offer[j]) && Offer[j] != EdnStr; j++)
		if (!TestSymbolPunctORSpace(Offer[j])) ARRWORD[iw][k++] = Offer[j];
		ARRWORD[iw][k++] = EdnStr;
		i = j;
		iCT++;
		iw++;
	}

	return iCT;
}

/*
int SearchPosEndWord(const char* pline, const int curpos)
{
int i = curpos;
int ilen = strlen(pline);
if ((ilen = 0) || (i>ilen) || (pline[i] == EdnStr)) return 0;
while ( (i <= ilen) && (!TestSymbolPunctORSpace(pline[i]) ) )i++;
return i;

}

*/
/*
char Space =' ';
char Dot ='.';  // dot -  точка
char ExPnt='!'; // exclamation - point Восклицательный знак
char QstMark='?'; //  ! question mark -вопросительный знак
char EdnStr='\0';// конец строки
*/
/*
int SearchEndPozLeftWord(const char* pline, const int i)
{
//  WORD
//	^  ^
// i___j
int j = i;
int ilen;
ilen=strlen(pline);
// Clear WORD
if ( (ilen==0)|| (i>ilen)||(pline[i] ==EdnStr) ) return 0;

//if (strchr(EndOffer,pline[i])!=null)return j=j-1;
if (pline[i]==Space||pline[i]==ExPnt||pline[i]==QstMark) return j=j-1;
while(pline[j]!=' '&& j<=ilen )j++;

return j;
}


// pStr -исхонная строка / PWord-слово / ibegpos- поз.начала строки
int  GettWordFromStrOnPozLeft(const char* pStr, char* pWord, const int ibegpos)
{
int ilen,ilenWord;
int i,j, iendpos;

ilen=strlen(pStr);
// Clear WORD
for(i=ilen-1;i>=0;i--) pWord[i]=EdnStr;
if ( (ilen==0)|| (ibegpos>ilen)||(pStr[ibegpos] ==EdnStr) ) return 0;
else
{
i=ibegpos;
iendpos=ibegpos;
while(pStr[j]!=' '&& j<=ilen )iendpos++;
if (iendpos-ibegpos>=0) for(i=ibegpos,j=0;i<=ibegpos;i++,j++)  pWord[j]=pStr[i];
pWord[j+1]=EdnStr;
ilenWord=strlen(pStr);
}
return ilenWord;
}

int SearchEndPozRightWord(const char* pline, const int i)
{
//  WORD
//	^  ^
// j___i
int j = i;
int ilen;

ilen=strlen(pline);
if (i!=ilen) return 0;
while(pline[j]!=' ' && j>=0)j--;
return j;
}

// pStr -исхонная строка / PWord-слово / iendpos- поз.конца сипроки
int  GetWordFromStrOnPozRight(const char* pStr, char* PWord, const int iendpos)
{
int ilen,ilenWord;
int i,j, ibegpos;

ilen=strlen(pStr);
// Clear WORD
for(i=ilen-1;i>=0;i--) PWord[i]=EdnStr;
if ( (ilen==0)|| (iendpos>ilen)||(pStr[iendpos] ==EdnStr) ) return 0;
else
{
i=iendpos;
ibegpos=iendpos;
while(pStr[j]!=' '&& j>=0) ibegpos--;
if (iendpos-ibegpos>=0) for(i=ibegpos,j=0;i<=iendpos;i++,j++)  PWord[j]=pStr[i];
PWord[j+1]=EdnStr;
ilenWord=strlen(pStr);
}
return ilenWord;
}
*/