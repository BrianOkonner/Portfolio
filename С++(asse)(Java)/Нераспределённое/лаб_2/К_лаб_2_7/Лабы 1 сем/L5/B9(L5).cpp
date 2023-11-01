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
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio>
#include "conio.h" 
using namespace std;
// Можно и так задать массив
//‘A’,‘B’,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y, // английский алфавит
//А,Б,В,Г,Д,Е,Ж,З,И,Й,К,Л,М,Н,О,П,Р,С,Т,У,Ф,Х,Ц,Ч,Ш,Щ,Ъ,Ы,Ь,Э,Ю,Я,Ё		// руский

// GLOBAL var
// Удобно менять в одно месте
 
// Переменные для тестирования CHECK->
int CHECK=1;  // FOR CHECK=1 Да, CHECK=0 -Нет
//int  iwithoutFindWord;
//char StrTmp[MaxSizeStr];
// <-CHECK 

#define MaxSizeStr 100
#define MaxSizeBuff 200
#define MaxSizeWord 50
#define CTWord 20 //число сло
//const int MaxSizeStr=100,MaxSizeBuff=200,MaxSizeWord=80;
char Space =' ';
char Dot ='.';  // dot -  точка
char ExPnt='!'; // exclamation - point Восклицательный знак
char QstMark='?'; //  ! question mark -вопросительный знак
char EdnStr='\0';// конец строки
//End Offer - Конец предложения
char EndOffer[]={Dot,ExPnt,QstMark,EdnStr}; 
// Буффер символов ВЕРХНЕГО РЕГИСТРА
char UpLetters[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
	            'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
				'А','Б','В','Г','Д','Е','Ж','З','И','Й','К','Л','М','Н',
				'О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ',
				'Ъ','Ы','Ь','Э','Ю','Я','Ё','\0'};

//текст – это группа предложений
// Педложение начинается на UP Предыдущий Space или  
// 

// Знаки пунктуации . , ? ! ;
// Prototype to functions -->
// Realization for main ,Реализация за main
void ClearSTR(char* pline); 
//int TestSymbolEndOffer(char ch);
int SearchEndPozRightWord(const char* pline, const int i);
int InsetSubmBeforeWord(char* pline,char ch);
int InsetSubmAfterWord(char* pline,char ch);
// pStr -исхонная строка / PWord-слово / ibegpos- поз.начала / iendpos- поз.конца
int  GetWordFromStrOnTwoPoz(const char* pStr,char* PWord,const int ibegpos,const int iendpos);
int  SearchEndPozLeftWord(const char* pline, const int i);

// pStr -исхонная строка / PWord-слово / ibegpos- поз.начала 
// первое слово с позиции поиск влево
int  GettWordFromStrOnPozLeft(const char* pStr,char* PWord,const int ibegpos);

// pStr -исхонная строка / PWord-слово / iendpos- поз.конца сипроки 
int  GetWordFromStrOnPozRight(const char* pStr,char* PWord,const int iendpos);
// <--Prototype to functions -->


int main()
{
int  i,j,YesOFFER,iYesWord1,iYesWord2; // Для итераций
int  iYesUPsybmFirstOFFER;
int  iTab;// идет табуляция предложение с отступом
int  iCTStr=0; // число прочитанных строк
char StrSource[MaxSizeStr+1]; // Строка из файла +1 на EdnStr
char StrFind[MaxSizeStr+1];   //Строка Find/ найденной ПРЕДЛОЖЕНИЕ 
char StrSave[MaxSizeBuff+1];


// Для ОТЛАДКИ -->
char StrBag[MaxSizeStr+1]; 


//char UpLetters[100]; 
//char *StrFind=new char [MaxSizeStr];// предложение
//char *StrTmp=new char [MaxSizeStr];
//char *StrSave=new char [MaxSizeBuff];

char WORD1[MaxSizeWord+1],WORD2[MaxSizeWord+1]; // Слово 1, Слово 2 
char WORDtmp1[MaxSizeWord+1],WORDtmp2[MaxSizeWord+1]; // Слова с Space до и после слова
//  массив слов
char ARRWORD[CTWord] [MaxSizeWord+1];// CTWord*MaxSizeWord

int  ilen,isizeOFFER;// длина на строки из файла, длина предложения
int  ibegin,iend; // начало предложения  , конец предложения 
char ch;

	setlocale(LC_ALL, "rus"); 
    //setlocale(LC_ALL,".1251");// корректное отображение Кириллицы
  	// Символы конца предложения

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
	ch=getch(); // Команда задержки экрана
   
	/*cout<<" Массив прописных сиволов 1й вариант" <<endl;
	cout<<up <<endl;
	cout<<"   " <<endl;
	*/
    cout<<" Массив прописных сиволов:" <<endl;
	cout<<UpLetters<<endl;
	cout<<"   " <<endl;
    ch=getch(); 

 if(in==NULL||out==NULL||outs==NULL)    cout<<"Ошибка в открытии файла "<<endl;
	else 
	{//Open File-->

 		while(!in.eof())
		{ // ReadFile-->
			
			iCTStr++; //calc line
			
			in.getline(StrSource,100,'\n');
		    ilen=strlen(StrSource);
		       // On screen
			cout<<"   Строка  № "<<iCTStr<<endl<<StrSource<<"   "<<endl;
            ch=getch();
		    
			ibegin=-1;
            iend=-1;
		    isizeOFFER=0;
			
			YesOFFER=0;
			iYesWord1=0;
			iYesWord2=0;
			iTab=1;
			//for(i=0;i<=ilen && iend==-1 && StrSource[i]!='\0';i++)
		   
			
			for(i=0;i<=ilen && YesOFFER==0 ;i++) 
			  { // Cycle FIND OFFER in StrSource-> , Цикл поиск предложения в строке  input.txt
 
				  // Табуляция
			   if (iTab=1 && StrSource[i]==Space ) iTab=1;
			   else iTab=0;

				iYesUPsybmFirstOFFER=0;
			     if (strchr(UpLetters,StrSource[i])!=NULL)
			      {
					 // Find First UPSubmol , Первый ЗАГЛАВНЫЙ символ
	  		        if (CHECK=1) { cout<<"UP Символ : "<<StrSource[i]<<endl;  ch=getch(); }
				
	    		    if  ( i==0)  iYesUPsybmFirstOFFER=1;
			            else if ( (iTab=1)	 ||  ( i>1 && (StrSource[i-1]==Space) 
				 	           && ((strchr(EndOffer,StrSource[i-2])!=NULL) || (iTab=1)) ) ) iYesUPsybmFirstOFFER=1;   
			       }//<-Find First UP Offer Submol
     

			 if (iYesUPsybmFirstOFFER>=0)
		      { // Find Position End Offer --> 
			    ibegin=i;
			//	if (CHECK=1){  cout<<"Цикл поиска конца: "<<ibegin<<endl;  ch=getch(); }
				
				for(j=i;j<=ilen && YesOFFER!=1 ;j++)
		        if (strchr(EndOffer,StrSource[j])!=NULL)//Символы конца предложения
				     {
		                if  ( j==ilen ||  (i<ilen && isspace(StrSource[j+1]) ))   iend=j;	// позиция конца предложения
   		                isizeOFFER=iend-ibegin;
		  	            if (isizeOFFER>0) YesOFFER=1;
					       {
					         isizeOFFER=iend-ibegin;
						    if (CHECK=1){  cout<<"Yes End: "<<iend<<endl;  ch=getch(); }
					       }
				      }
			   }//<- Find Position End Offer
			  
			       
	  	     if( (YesOFFER ) && (GetWordFromStrOnTwoPoz(StrSource,StrFind,ibegin,iend) >0)) 
			     {  // Get OFFER-->// Если> 0 - Нашли
			   // On screen
				   cout<<" Предложение: ";
				   if (CHECK=1) {cout<<" ibegin: "<<ibegin<<" iend : "<<iend<<endl;}
                   if (CHECK=1) {cout<<" Размер предложения "<<isizeOFFER<<endl;}
 
				   cout<<" StrFind: "<<StrFind<<endl;
				   if (CHECK=1) {cout<<" Start Find Word 1 "<<endl;  ch=getch();}
	  
				   strcpy(StrBag,StrFind);
		
				   /*
				   if (GetWordFromStrOnPozRight(StrFind,WORD1,0)>0) 
						  { // Get WORD1->
							 iYesWord1=1;
							 ch=getch(); 
							 strcpy(WORDtmp1,WORD1);
						     InsetSubmAfterWord(WORDtmp1,' ');
							 cout<<"WORD 1 :"<<WORD1<<endl;
							 ch=getch();   
						  } // <- Get WORD1

				   if (CHECK=1) {cout<<" Start Find Word 2 "<<endl;  ch=getch();}

					if (GettWordFromStrOnPozLeft(StrFind,WORD2,isizeOFFER)>0 )
						  { // Get WORD2->
		  				    iYesWord2=1;
							strcpy(WORDtmp2,WORD2);
						    InsetSubmBeforeWord(WORDtmp2,' ');
							cout<<"WORD 2 :"<<WORD2<<endl;
							
							if (CHECK=1){ch=getch();}
							  
						   } // <- Get WORD2
				          
			
					if( iYesWord1=1)
					{
						strcpy(WORDtmp1,WORD1);
						InsetSubmAfterWord(WORDtmp1,' ');
                        strcat(StrSave,WORDtmp1);
					}
					if( iYesWord2=1 )
					{
						strcpy(WORDtmp2,WORD2);
						InsetSubmBeforeWord(WORDtmp2,' ');
                        strcat(StrSave,StrFind);
                        strcat(StrSave,WORDtmp2);
					 }
						   
						   cout<<"Fefor break  :"<<endl;
						   ch=getch(); 
					*/	  
						//   if (YesOFFER=1) break;
	
			 } //<-- Get OFFER, Есть предложение 

       }  // <- Cycle FIND OFFER in StrSource

     if (isizeOFFER>0) 
	 {
	  
		 //ПОКА СОХРАНЯЕТЯ не правильно
	cout<<"WORD 1  OFFER WORD 2:"<<endl;
 	// ДЛЯ ОТЛАДКИ-->
	 out<<StrBag<<endl;
	//  out<<StrSave<<endl;
    //<-- ДЛЯ ОТЛАДКИ
	  ch=getch();   
	  }
	 else 
	 {
       	//On screen
		cout<<"SAVE- Исходную строку: "<<iCTStr<<' '<<StrSource<<endl;
		out<<StrSource<<endl;
		ch=getch();
	 }
	
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
 int i;
 int ilen;
 ilen=strlen(pline);
 if (ilen==0) return ;
 else for(i=ilen-1;i>=0;i--) pline[i]=EdnStr;
}

/*
int TestSymbolEndOffer(char ch)
{
 if ( ch==Dot||ch==ExPnt||ch==QstMark) return 1;
 else 0;
}
*/

int InsetSubmBeforeWord(char* pline,char ch)
{
char *StrTmp=new char [MaxSizeStr];
int i=0 ;
int j=0 ;
int ilen;
ilen=strlen(pline);
if (ilen+1>MaxSizeStr) return 0;
// With end str
pline[ilen+1]=EdnStr;
for(i=ilen;i<=1;i--) pline[i+1]=pline[i];
pline[0]=ch;
return ilen+1;
}

int  InsetSubmAfterWord(char* pline,char ch)
{
char *StrTmp=new char [MaxSizeStr];
int ilen;
ilen=strlen(pline);
if (ilen+1>MaxSizeStr) return 0;
// Set In end str
pline[ilen]=ch;
pline[ilen+1]=EdnStr;
return ilen+1;
}


// pStr -исхонная строка / PWord-слово / ibegpos- поз.начала / iendpos- поз.конца
int  GetWordFromStrOnTwoPoz(const char* pStr,char* PWord,const int ibegpos,const int iendpos)
{
int ilenStr,ilenWord;
int i,j;	
ilenStr=strlen(pStr);
for(i=ilenStr-1;i>=0;i--) PWord[i]=EdnStr;
if (ilenStr=0 ||ibegpos>iendpos) return 0;
for(i=ibegpos,j=0;i<=iendpos;i++,j++)  PWord[j]=pStr[i];
PWord[j+1]=EdnStr;
ilenWord=strlen(pStr);
return ilenWord;
}



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

//if (strchr(EndOffer,pline[i])!=NULL)return j=j-1;
if (pline[i]==Space||pline[i]==ExPnt||pline[i]==QstMark) return j=j-1;
while(pline[j]!=' '&& j<=ilen )j++;

return j;
}


// pStr -исхонная строка / PWord-слово / ibegpos- поз.начала строки
int  GettWordFromStrOnPozLeft(const char* pStr,char* PWord,const int ibegpos)
{
int ilen,ilenWord;
int i,j, iendpos;

ilen=strlen(pStr);
// Clear WORD
for(i=ilen-1;i>=0;i--) PWord[i]=EdnStr;
if ( (ilen==0)|| (ibegpos>ilen)||(pStr[ibegpos] ==EdnStr) ) return 0;
else
 {
  i=ibegpos;
  iendpos=ibegpos;
  while(pStr[j]!=' '&& j<=ilen )iendpos++;
  if (iendpos-ibegpos>=0) for(i=ibegpos,j=0;i<=ibegpos;i++,j++)  PWord[j]=pStr[i];
  PWord[j+1]=EdnStr;
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
int  GetWordFromStrOnPozRight(const char* pStr,char* PWord,const int iendpos)
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
