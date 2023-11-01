// B9(L5).cpp : Defines the entry point for the console application.
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
//#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio>
#include<cstring>
//#include "conio.h" // Команда задержки экрана ch=getch(); старая версия
                     //  новая system("pause >> void");
using namespace std;
using std::cin;
using std::cout;
/*void delete_s_asm(char *s,char *s1);
char * assemStrcat_asm(char *a, char *b);
bool zaglavn_asm(char *s);
void swap_asm(char *a,char *b);
int MyassemStrlen(char *a);
char* assemStrcpy_asm(char *c, char *a);
int assemStrlen_asm(char *s);

*/
void AsmassemStrcat(char *a, char *b);
int MyassemStrlen1(char *a);
int assemStrlen(char*sl)
{
	int l;
	_asm
	{
		mov esi, sl
		dec esi;          
		mov ecx, -1
		m1: inc ecx
			inc esi
			cmp[esi],0
		jnz m1

		mov l, ecx
	}
	return l;
}


void assemassemStrcpy(char*str1, char*str2)
{
	int k;
	_asm
	{
		push str2
		call assemStrlen
		pop edx
		mov k, eax
		mov ecx, k
		add ecx, 1
		mov esi, str2
		mov edi, str1
		rep movsb
	}
}

void assemassemStrcat(char*a, char*b)
{
	int k;
	int t;
	int len = 0;
	_asm {
		push a
		call assemStrlen
		pop edx
		mov k, eax
		push b
		call assemStrlen
		mov t, eax
		pop edx
		mov ecx, t
		add ecx, 1
		mov esi, b
		mov edi, a
		add edi, k
		rep movsb
	}
}

// GLOBAL переменные
// Удобно менять в одно месте

// Visisl Studio настроен на UNICODE 2 byte на символ
// ispunct(ch) требуеи 1byte и плохо работает с UNICODE 
// для UNICODE нужно использовать iswpunct 
// //Visisl Studio при использ. iswpunct  дает предупреждение  Тебует wchar_t

// РЕШЕНИЕ - делаем свой массив
//  Знаков припинания 
/*  МИНИМАЛЬНО ЭТО
 !% ^ & * () – + = {} | ~ [] \; ' : " < > ? , . / #
Названия символов  не алфавитных на английском языке

по максимуиму 
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

//  работа с функцикй assemStrlen(string)
//       пример
//char string[10] = "строка";
//массив имеет размер 10 символов, 
//но строка в этом массиве имеет длину всего 6 символов.
//если выполнится оператор sizeof(string)ответ будет 10,
//а если — функция assemStrlen(string), ответ 6.
// нумерация в массиве начинаеться с 0 заканч-ся assemStrlen-1
// [0] - с 
// [5] или [assemStrlen-1]-  а 
// [assemStrlen] /0  конец строки


#define MaxSizeStr 100
#define MaxSizeBuff 200
#define MaxSizeWord 50
#define CTWord 10 //число слов

//Имена знаков  Пунктуации
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
// 
char Punct[] = { Dot, ExPnt, QstMark, Colon, Semicolon, Dash, Asterisk,
Ampersand, At, Dollar, Caret, OpenParenthesis,
CloseParenthesis, OpenLSqbracket, CloseRSqbracket,
Comma, Percent, Quote, Equals, Plus, Underscore, LessThan,
GreaterThan, EdnStr };

//End Offer - Конец предложения варианты 
char EndOffer[]={Dot,ExPnt,QstMark,EdnStr}; 

//‘A’,‘B’,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y, // английский алфавит
//А,Б,В,Г,Д,Е,Ж,З,И,Й,К,Л,М,Н,О,П,Р,С,Т,У,Ф,Х,Ц,Ч,Ш,Щ,Ъ,Ы,Ь,Э,Ю,Я,Ё		// руский
// Буффер символов ВЕРХНЕГО РЕГИСТРА Англ. и Кирилицы
char UpLetters[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
	            'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
				'А','Б','В','Г','Д','Е','Ж','З','И','Й','К','Л','М','Н',
				'О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ',
				'Ъ','Ы','Ь','Э','Ю','Я','Ё','\0'};

// Для слов предложения
char ARRWORD[CTWord][MaxSizeWord];// CTWord*MaxSizeWord

// Prototype to functions -->
// Realization for main ,Реализация за main
// очистка строк
void ClearSTR(char* pline); 

// проверка символа что это пунктуация
bool TestSymbolPunct(char ch);

// проверка символа  что это пунктуация или пробел
bool TestSymbolPunctORSpace(char ch);

// вставка символа перед словом / строкой
int  InsetSybmBeforeWord(char* pline,char ch);

// вставка символа после слова/ строкой
int  InsetSybmAfterWord(char* pline,char ch);

// проверка что символ м.б. началом предложения 
bool TestSymbolBeginOffer(char ch);

//поиск начала предложения   
bool TestBeginOffer(char* pline, const int ipos, const int  iTab);

// проверка что символ м.б. конецом предложения
bool TestSymbolEndOffer(char ch);

// поиск конца предложения
bool TestEndOffer(char* pline, const int ipos);

// получить слово из предложения по позиции начала и конца 
int  GetWordFromStrOnTwoPoz(char* pStr,char* pWord,const int ibegpos,const int iendpos);

//Получить слова из предложения
int  GetWordsFromOffer(char* Offer);


int  SearchEndPozRightWord(const char* pline, const int i);// поиск 

// Функция Сортировки ПОКА  НЕ ДОРАБОТАНА 
// bool  BladderSortARRWORD(const int CTW, char* pStr); 

// <--Prototype to functions -->


int main()

{

// управляющие переменные
//  Остановка поиска предложения, Есть начало предложения, есть конец предл., 
//  есть загрузка предложение, есть сортировка
bool Stop,YesBeginOFFER,YesEndOFFER,YesLoadOFFER,YesSort; 

char StrSource[MaxSizeStr]; // Строка источник из файла
char StrFind[MaxSizeStr];   //Строка Find/ найденное ПРЕДЛОЖЕНИЕ 
char StrSave[MaxSizeBuff];   // Строка для сохранения в файл output.txt
char StrSort[MaxSizeBuff];   // Строка для сохранения в файл out_sort.txt

//  слова первое и последнее
char WORDtmp1[MaxSizeWord],WORDtmp2[MaxSizeWord]; 
int  ilen,isizeOFFER;// длина на строки из файла, длина предложения
int  ibegin, iend; // начало предложения  , конец предложения 
int  iTab;// идет табуляция предложение с отступом
int  iCTStr=0; // число прочитанных строк
int  iCTWords = 0;  // Число слов в предложении
char ch;
int  i, j; // Для итераций	


setlocale(LC_ALL, "rus"); 
//setlocale(LC_ALL,".1251");// корректное отображение Кириллицы

// Сдесь  надо вместо "r" "w" -> ios::in ios::out  т.к std Class
//ios_base::trunc   – удаление содержимого файла при открытии.
ifstream in("input.txt",ios::in);      //   открыли файл для чтения
ofstream out("output.txt",ios::out |ios_base::trunc);   //  для записи
ofstream outs("out_sort.txt",ios::out|ios_base::trunc); //  для записи сорт.


/*
	for(i='A';i<='Z';i++&&j++) 	UpLetters[j]=i;
	for(i='А';i<='Я';i++&&j++)	UpLetters[j]=i;
	UpLetters[j]='Ё';
	UpLetters[j+1]=EdnStr;
	*/

	// On screen
	cout<<"START!"<<endl;
	cout<<"Press Key!"<<endl;
	// Команда задержки экрана
	system("pause >> void");
	  

    cout<<" Массив прописных сиволов:" <<endl;
	cout<<UpLetters<<endl;
	cout<<"   " <<endl;
	system("pause >> void");


	if ( !in.is_open() || !out.is_open() || !outs.is_open() )	
		               cout << "Ошибка в открытия файла " << endl; 
	 else
	  {//Open File-->
 		while(!in.eof())
		{ // ReadFile-->
			iCTStr++; //calc line
			in.getline(StrSource,100,'\n');
		    ilen=assemStrlen(StrSource);
	    
			// On screen
			cout<<"Строка  № "<<iCTStr<<endl<<StrSource<<"   "<<endl;
			system("pause >> void");
		    

			// очистка строк
	        ClearSTR(StrFind);
			ClearSTR(WORDtmp1);
            ClearSTR(WORDtmp2);
            ClearSTR(StrSave);
			
			ibegin=0;
            iend=0;
		    isizeOFFER=0;			
			YesBeginOFFER=false;
		    YesEndOFFER=false;
			YesLoadOFFER=false;
			YesSort= false;
            Stop = false;
		   if (StrSource[0] == Space) iTab=1;
		   else iTab = 0;
		 


		   for (i = 0; i < ilen && !Stop; i++)
		   { // Cycle FIND OFFER in StrSource-> , 
			   //Цикл поиск предложения в строке  input.txt
		      
			   // Табуляция - пробелы до начала предложения 
			  if( i>0 && iTab == 1)
			   {
				   if (StrSource[i - 1] = Space)iTab = 1;
				   else if (StrSource[i] = Space) continue;
		        }
	 
		   if (TestBeginOffer(StrSource, i, iTab))
			   { // Find Position End Offer --> 
				   cout << "Начало предложния : " << "UP Символ : " << StrSource[i];
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
					   cout << "Конец предложния : " << "UP Символ : " << StrSource[j];
					   cout << " Позиция : " << j << endl;
					   system("pause >> void");
				     }
			      }//<-- Find  Offer 
			      
			       YesLoadOFFER = false;
				   if (YesBeginOFFER && YesEndOFFER && GetWordFromStrOnTwoPoz(StrSource, StrFind, ibegin, iend)>0)
			      {  // Get OFFER-->// Если> 0 - Нашли
   				    YesLoadOFFER = true;
					// On screen
				    cout<<"Предложение: "<< StrFind << endl;
					system("pause >> void"); 
			        } //<-- Get OFFER, Есть предложение 
				   
				   if (YesLoadOFFER)
				   {
					   cout << "Начать поиск слов: " << endl;
					   system("pause >> void");
					   iCTWords = GetWordsFromOffer(StrFind);
					  
					   if (iCTWords> 0)
					   {
						   cout << " Число слов: " << iCTWords << endl;
						   //сохранить знак в конце строки . !  ? ..
						   ilen = assemStrlen(StrFind);
						   ch = StrFind[ilen - 1];
						   StrFind[ilen - 1] = EdnStr;

						   // assemStrcpy -старая Эта функция может быть небезопасной.
						   strcpy_s(WORDtmp1, ARRWORD[0]);
						   cout << "Первое слово: " << WORDtmp1 << endl;
						   system("pause >> void");

						   InsetSybmAfterWord(WORDtmp1, ' ');
						   (StrSave, WORDtmp1);
						   strcat_s(StrSave, StrFind);
					
						if (iCTWords > 1)
						      {
							   strcpy_s(WORDtmp2, ARRWORD[iCTWords - 1]);
							   cout << "Последнее слово: " << WORDtmp2 << endl;
							   system("pause >> void");
							  
							   InsetSybmBeforeWord(WORDtmp2, ' ');
							   strcat_s(StrSave, WORDtmp2);
							   //восстановит знак в конце строки 
							   InsetSybmAfterWord(StrSave, ch);
						     }
			
						   ClearSTR(WORDtmp1);
						    //пузырковая сортировка
					      for (j = 0; j<iCTWords -1; j++) //количество прогонов 
						  for (i = iCTWords - 1; i>=0; i--)
								   // если нижняя меньше верхней меняем
							   if (assemStrlen(ARRWORD[i]) < assemStrlen(ARRWORD[i - 1]))
							   {  // Меняем местами
								   strcpy_s(WORDtmp1, ARRWORD[i - 1]); //верхн сохр.
								   strcpy_s(ARRWORD[i - 1], ARRWORD[i]); // нижнюю на место верхн
								   strcpy_s(ARRWORD[i], WORDtmp1); // сохр. веиз
							   }
							   j++;
					
						    ClearSTR(StrSort); 
					        // Собрать предложение из отсорт. слов
						   for (j = 0; j <= iCTWords - 1; j++)
						       {

								 AsmassemStrcat(StrSort, ARRWORD[j]);
							   InsetSybmAfterWord(StrSort, Space);
 						       }
						   
						  YesSort = true;
						   }

				   }
		               
				   if (YesLoadOFFER && iCTWords==0)
					   {
						   cout << " Ошибка поиска слов" << StrSave << endl;
						   cout << "   " << endl;
						 //  system("pause >> void");
					   }

					   if (YesLoadOFFER) Stop = true;
	

				   
       }  // <- Cycle FIND OFFER in StrSource

    
	 if (iCTWords>0)
	 {
	  cout<<"SAVE output.txt :"<<StrSave<<endl;
		// Слово1 + Предложение + Слово_посл
	  out<<StrSave<<endl;
      cout << "   " << endl;
	  system("pause >> void");
	  }
	 else 
	 {
		//On screen
		cout<<"Предложений не найдено!!! "<<endl;
		cout << "   " << endl;
	    system("pause >> void");
	 }
	
	if (YesSort)
	{
		cout << "Сортировка SAVE out_sort.txt:" << StrSort <<endl;
		outs << StrSort << endl;
		cout << "   " << endl;
		system("pause >> void");
	}
	else cout << "Ошибка сортировки !!!" << StrSort << endl;

	}//<-- ReadFile
	
	
	in.close();
	out.close();
	outs.close();	
   }//<-- Open File
	
	// On screen
	cout<<" - -  "<<endl;
	cout<<" Конец "<<endl;
	cout<<" - - - "<<endl;
	//system("pause");	
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


bool TestSymbolPunct(char ch)
{
// для  UNICODE iswpunct   для Multi-Byte (ispunct(ch)	
//	 ispunct Дает сбой при отрицателном значении
//  iswpunct дает предупреждение, что  Тебует wchar_t
	
	if (strchr(Punct, ch) != NULL) return true;  
	else return false;  
	
	//с Unicode  постоянно вылетает
	//	if (ispunct(ch) > 0) return true;
//	else return false;

//	if (iswpunct(ch) > 0) return true;
//	else return false;

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
	ilen = assemStrlen(pline);
	if (ilen + 1 > MaxSizeStr) return 0;
	for (i = ilen; i>0; i--) pline[i] = pline[i - 1];
	pline[i] = ch;
	pline[ilen + 1] = EdnStr;
	return ilen + 1;
}


int  InsetSybmAfterWord(char* pline, char ch)
{
	int ilen;
	ilen = assemStrlen(pline);
	if (ilen + 1 > MaxSizeStr) return 0;
	// Set In end str
	pline[ilen] = ch;
	pline[ilen + 1] = EdnStr;
	return ilen + 1;
}



bool TestBeginOffer(char* pline, const int ipos,const int  iTab)
{
int ilen;
ilen = assemStrlen(pline);
bool Yes;
Yes = false;

if (ipos < ilen && strchr(UpLetters, pline[ipos]) != NULL)
{
    if (ipos == 0) Yes=true;
    if( ipos == 1 && (pline[ipos - 1] == Space) ) Yes = true;
  
    if (ipos>1)
     {
      if ((iTab > 0) || ((pline[ipos - 1] == Space) &&
		 (strchr(EndOffer, pline[ipos - 2]) != NULL))) Yes=true;
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
ilen = assemStrlen(pline);
bool Yes;
Yes = false;
       /*isspace(pline[ipos + 1]) требует unsignedchar проблема с UNICODE*/
if( ipos <= ilen && TestSymbolEndOffer(pline[ipos]) )
	{
      if (ipos == ilen)Yes=true;
	  else if  (TestSymbolEndOffer(pline[ipos]) && (pline[ipos + 1]=Space)) Yes=true;
	  //iswspace  для UNICODE
}
return Yes;
}



// pStr -исхонная строка / PWord-слово / ibegpos- поз.начала / iendpos- поз.конца
int  GetWordFromStrOnTwoPoz(char* pStr, char* pWord, const int ibegpos, const int iendpos)
{
	int ilenStr, isize;
	int i,j;
	ilenStr = assemStrlen(pStr);
	isize = sizeof(pWord);
	
	for (i = isize-1; i >= 0; i--) pWord[i] = EdnStr;
	//memset(pWord, NULL, sizeof(pWord)-1);

	if (ilenStr = 0 || ibegpos > iendpos) return 0;
	for (i = ibegpos, j = 0; i <= iendpos; i++, j++)  pWord[j] = pStr[i];
	
	pWord[j++] = EdnStr;
	return assemStrlen(pWord);//
}


int  GetWordsFromOffer(char* Offer)
{
int i = 0, j, k; // 
int iw = 0;    // доступ к строка массива ARRWORD
int iCT = 0;  // число слов
int ilen = assemStrlen(Offer);
if (ilen == 0) return 0;

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
/*void AsmassemStrcat(char *a, char *b) {
	int l1 = MyassemStrlen1(a);
	int l2 = MyassemStrlen1(b);
	_asm {
		mov ecx, l2
		inc ecx
		mov edi, a
		mov esi, b
		add edi, l1
		rep movsb
	}
}
int MyassemStrlen1(char *a) {
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
int MyassemStrlen(char *a) {
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
int assemStrlen_asm(char *s)
{int len;
_asm
{      mov esi,s   //в еsi адрес s
       dec esi     
	   mov ecx,-1    
m1:    inc ecx     //В есx длина строки
	   inc esi
       cmp [esi],0   //пока не конец строки
       jnz m1

	   mov len,ecx
}
return len;
}



char* assemStrcpy_asm(char *c, char *a)
{
	_asm
	{  push a
	   call assemStrlen_asm
	   pop edx
	   mov ecx, eax
		
	    inc ecx
		mov ax,ds
		mov es,ax 
		mov esi, a
		mov edi, c
	
	    rep movsb	
	}
	return c;
}

void swap_asm(char *a,char *b)
{char c[100]="";
assemStrcpy_asm(c,a);
assemStrcpy_asm(a,b);
assemStrcpy_asm(b,c);
}

bool zaglavn_asm(char *s)
{bool r; int k;
  _asm
  {
	push s
call assemStrlen_asm
pop edx
mov ecx,eax
mov esi,s
dec esi
beg:
	mov k,ecx     //сохраняем длину строки
	inc esi
	mov ebx,[esi]
	push ebx
	call comp       //проверка буквы на заглавность
	pop edx
	cmp eax,0   //если не прописная
	je end
	mov ecx,k
    loop beg

end: mov r,al
  }
return r;
}


char * assemStrcat_asm(char *a, char *b)
{ int k;
	_asm
     {  push a
        call assemStrlen_asm
        pop edx
        mov k,eax          //k-len a

        push b
        call assemStrlen_asm
        pop edx          //eax-len b


        mov esi,b
        mov edi,a
        add edi,k   //  подготовили esi и edi 

		mov ecx,eax     //  подготовили ecx
		inc ecx

        rep movsb
     }
return a;
 }
void delete_s_asm(char *s,char *s1)
{char *s2=strstr(s,s1);
int k;
_asm
   {    push s2
        call assemStrlen_asm
        pop edx
		mov k,eax
	   
	   
	   push s1
        call assemStrlen_asm
        pop edx
   
        mov edi,s2
        mov esi,s2
        add esi,eax  //esi=s2+assemStrlen(s1)

		mov ecx,k
		inc ecx
        rep movsb

   }
}



int assemStrlen_asm(char *s)
{int len;
_asm
{      mov esi,s   //в еsi адрес s
       dec esi     
	   mov ecx,-1    
m1:    inc ecx     //В есx длина строки
	   inc esi
       cmp [esi],0   //пока не конец строки
       jnz m1

	   mov len,ecx
}
return len;
}



char* assemStrcpy_asm(char *c, char *a)
{
	_asm
	{  push a
	   call assemStrlen_asm
	   pop edx
	   mov ecx, eax
		
	    inc ecx
		mov ax,ds
		mov es,ax 
		mov esi, a
		mov edi, c
	
	    rep movsb	
	}
	return c;
}

void swap_asm(char *a,char *b)
{char c[100]="";
assemStrcpy_asm(c,a);
assemStrcpy_asm(a,b);
assemStrcpy_asm(b,c);
}

bool zaglavn_asm(char *s)
{bool r; int k;
  _asm
  {
	push s
call assemStrlen_asm
pop edx
mov ecx,eax
mov esi,s
dec esi
beg:
	mov k,ecx     //сохраняем длину строки
	inc esi
	mov ebx,[esi]
	push ebx
	call comp       //проверка буквы на заглавность
	pop edx
	cmp eax,0   //если не прописная
	je end
	mov ecx,k
    loop beg

end: mov r,al
  }
return r;
}

int MyassemStrlen(char *a) {
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
char * assemStrcat_asm(char *a, char *b)
{ int k;
	_asm
     {  push a
        call assemStrlen_asm
        pop edx
        mov k,eax          //k-len a

        push b
        call assemStrlen_asm
        pop edx          //eax-len b


        mov esi,b
        mov edi,a
        add edi,k   //  подготовили esi и edi 

		mov ecx,eax     //  подготовили ecx
		inc ecx

        rep movsb
     }
return a;
 }
void delete_s_asm(char *s,char *s1)
{char *s2=strstr(s,s1);
int k;
_asm
   {    push s2
        call assemStrlen_asm
        pop edx
		mov k,eax
	   
	   
	   push s1
        call assemStrlen_asm
        pop edx
   
        mov edi,s2
        mov esi,s2
        add esi,eax  //esi=s2+assemStrlen(s1)

		mov ecx,k
		inc ecx
        rep movsb

   }
}*/

int MyassemStrlen1(char *a) {
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
void AsmassemStrcat(char *a, char *b) {
	int l1 = MyassemStrlen1(a);
	int l2 = MyassemStrlen1(b);
	_asm {
		mov ecx, l2
		inc ecx
		mov edi, a
		mov esi, b
		add edi, l1
		rep movsb
	}
}

// ПОКА не использовать НЕ ДОРАБОТАНА 
/*
bool  BladderSortARRWORD(const int CTW, char* pStr)
{  
	
int i, j;
	char stmp[MaxSizeWord];
	
	ClearSTR(stmp);
    ClearSTR(pStr);
	if (CTW == 0) return false;
	//пузырковая сортировка
	for (j = 0; j<CTW - 1; j++) //количество прогонов 
	for (i = CTW - 1; i >= 0; i--)
		// если нижняя меньше верхней меняем
	if (assemStrlen(ARRWORD[i]) < assemStrlen(ARRWORD[i - 1]))
	{  // Меняем местами
		strcpy_s(stmp, ARRWORD[i - 1]); //верхн сохр.
		strcpy_s(ARRWORD[i - 1], ARRWORD[i]); // нижнюю на место верхн
		strcpy_s(ARRWORD[i], stmp); // сохр. веиз
	}
	j++;

	ClearSTR(stmp);
	// Собрать предложение
	for (j = 0; j <= CTW - 1; j++)
	{
		strcat_s(stmp, ARRWORD[j]);
		InsetSybmAfterWord(stmp, Space);
	}
     // Visisl Studio Ругается
	strncpy(pStr, stmp, assemStrlen(stmp));
	
	return true;
	
} 

*/ 
