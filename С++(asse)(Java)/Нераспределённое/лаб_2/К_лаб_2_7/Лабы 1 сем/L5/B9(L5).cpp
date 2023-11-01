// B9(L5).cpp : Defines the entry point for the console application.
/*												������ �B9
	��������� ������� ��������� ������������ ������������.( �������������: ���������� ������������. ������ 8).
	������� :����� ��������� ���� Input.txt, ���������  �� ���� � ��������� �����������.
������������� ����� ������� �������� ��������� ��������� ������ ����������.
�����  ������, � ������� ����������� ������ �����������, �������������� ������ � ��������� ����� �����������. 
��������� ��������  � ����� ���� Output.txt. ����������� �����  � ������� ������������ ��  �������� ���� ����, ��������� ����������
�������� � ���� Out_sort.txt. 
	������� �������� :(����������� ������ ���������� �� ����� � �������(���� � ��������) � ������������� �� � ����� ����������
� ��������� �����) 
	����� :*/
// file_read.cpp: ���������� ����� ����� ��� ����������� ����������.
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio>
#include "conio.h" 
using namespace std;
// ����� � ��� ������ ������
//�A�,�B�,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y, // ���������� �������
//�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�,�		// ������

// GLOBAL var
// ������ ������ � ���� �����
 
// ���������� ��� ������������ CHECK->
int CHECK=1;  // FOR CHECK=1 ��, CHECK=0 -���
//int  iwithoutFindWord;
//char StrTmp[MaxSizeStr];
// <-CHECK 

#define MaxSizeStr 100
#define MaxSizeBuff 200
#define MaxSizeWord 50
#define CTWord 20 //����� ���
//const int MaxSizeStr=100,MaxSizeBuff=200,MaxSizeWord=80;
char Space =' ';
char Dot ='.';  // dot -  �����
char ExPnt='!'; // exclamation - point ��������������� ����
char QstMark='?'; //  ! question mark -�������������� ����
char EdnStr='\0';// ����� ������
//End Offer - ����� �����������
char EndOffer[]={Dot,ExPnt,QstMark,EdnStr}; 
// ������ �������� �������� ��������
char UpLetters[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
	            'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
				'�','�','�','�','�','�','�','�','�','�','�','�','�','�',
				'�','�','�','�','�','�','�','�','�','�','�','�',
				'�','�','�','�','�','�','�','\0'};

//����� � ��� ������ �����������
// ���������� ���������� �� UP ���������� Space ���  
// 

// ����� ���������� . , ? ! ;
// Prototype to functions -->
// Realization for main ,���������� �� main
void ClearSTR(char* pline); 
//int TestSymbolEndOffer(char ch);
int SearchEndPozRightWord(const char* pline, const int i);
int InsetSubmBeforeWord(char* pline,char ch);
int InsetSubmAfterWord(char* pline,char ch);
// pStr -�������� ������ / PWord-����� / ibegpos- ���.������ / iendpos- ���.�����
int  GetWordFromStrOnTwoPoz(const char* pStr,char* PWord,const int ibegpos,const int iendpos);
int  SearchEndPozLeftWord(const char* pline, const int i);

// pStr -�������� ������ / PWord-����� / ibegpos- ���.������ 
// ������ ����� � ������� ����� �����
int  GettWordFromStrOnPozLeft(const char* pStr,char* PWord,const int ibegpos);

// pStr -�������� ������ / PWord-����� / iendpos- ���.����� ������� 
int  GetWordFromStrOnPozRight(const char* pStr,char* PWord,const int iendpos);
// <--Prototype to functions -->


int main()
{
int  i,j,YesOFFER,iYesWord1,iYesWord2; // ��� ��������
int  iYesUPsybmFirstOFFER;
int  iTab;// ���� ��������� ����������� � ��������
int  iCTStr=0; // ����� ����������� �����
char StrSource[MaxSizeStr+1]; // ������ �� ����� +1 �� EdnStr
char StrFind[MaxSizeStr+1];   //������ Find/ ��������� ����������� 
char StrSave[MaxSizeBuff+1];


// ��� ������� -->
char StrBag[MaxSizeStr+1]; 


//char UpLetters[100]; 
//char *StrFind=new char [MaxSizeStr];// �����������
//char *StrTmp=new char [MaxSizeStr];
//char *StrSave=new char [MaxSizeBuff];

char WORD1[MaxSizeWord+1],WORD2[MaxSizeWord+1]; // ����� 1, ����� 2 
char WORDtmp1[MaxSizeWord+1],WORDtmp2[MaxSizeWord+1]; // ����� � Space �� � ����� �����
//  ������ ����
char ARRWORD[CTWord] [MaxSizeWord+1];// CTWord*MaxSizeWord

int  ilen,isizeOFFER;// ����� �� ������ �� �����, ����� �����������
int  ibegin,iend; // ������ �����������  , ����� ����������� 
char ch;

	setlocale(LC_ALL, "rus"); 
    //setlocale(LC_ALL,".1251");// ���������� ����������� ���������
  	// ������� ����� �����������

   // �����  ���� ������ "r" "w" -> ios::in ios::out  �.� std Class
	//ios_base::trunc   � �������� ����������� ����� ��� ��������.
	ifstream in("input.txt",ios::in);      //   ������� ���� ��� ������
	ofstream out("output.txt",ios::out |ios_base::trunc);   //  ��� ������
	ofstream outs("out_sort.txt",ios::out|ios_base::trunc); //  ��� ������ ����.
	
	/*
	for(i='A';i<='Z';i++&&j++) 	UpLetters[j]=i;
	for(i='�';i<='�';i++&&j++)	UpLetters[j]=i;
	UpLetters[j]='�';
	UpLetters[j+1]=EdnStr;
	*/

	// On screen
	cout<<"START!"<<endl;
	cout<<"Press Key!"<<endl;
	ch=getch(); // ������� �������� ������
   
	/*cout<<" ������ ��������� ������� 1� �������" <<endl;
	cout<<up <<endl;
	cout<<"   " <<endl;
	*/
    cout<<" ������ ��������� �������:" <<endl;
	cout<<UpLetters<<endl;
	cout<<"   " <<endl;
    ch=getch(); 

 if(in==NULL||out==NULL||outs==NULL)    cout<<"������ � �������� ����� "<<endl;
	else 
	{//Open File-->

 		while(!in.eof())
		{ // ReadFile-->
			
			iCTStr++; //calc line
			
			in.getline(StrSource,100,'\n');
		    ilen=strlen(StrSource);
		       // On screen
			cout<<"   ������  � "<<iCTStr<<endl<<StrSource<<"   "<<endl;
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
			  { // Cycle FIND OFFER in StrSource-> , ���� ����� ����������� � ������  input.txt
 
				  // ���������
			   if (iTab=1 && StrSource[i]==Space ) iTab=1;
			   else iTab=0;

				iYesUPsybmFirstOFFER=0;
			     if (strchr(UpLetters,StrSource[i])!=NULL)
			      {
					 // Find First UPSubmol , ������ ��������� ������
	  		        if (CHECK=1) { cout<<"UP ������ : "<<StrSource[i]<<endl;  ch=getch(); }
				
	    		    if  ( i==0)  iYesUPsybmFirstOFFER=1;
			            else if ( (iTab=1)	 ||  ( i>1 && (StrSource[i-1]==Space) 
				 	           && ((strchr(EndOffer,StrSource[i-2])!=NULL) || (iTab=1)) ) ) iYesUPsybmFirstOFFER=1;   
			       }//<-Find First UP Offer Submol
     

			 if (iYesUPsybmFirstOFFER>=0)
		      { // Find Position End Offer --> 
			    ibegin=i;
			//	if (CHECK=1){  cout<<"���� ������ �����: "<<ibegin<<endl;  ch=getch(); }
				
				for(j=i;j<=ilen && YesOFFER!=1 ;j++)
		        if (strchr(EndOffer,StrSource[j])!=NULL)//������� ����� �����������
				     {
		                if  ( j==ilen ||  (i<ilen && isspace(StrSource[j+1]) ))   iend=j;	// ������� ����� �����������
   		                isizeOFFER=iend-ibegin;
		  	            if (isizeOFFER>0) YesOFFER=1;
					       {
					         isizeOFFER=iend-ibegin;
						    if (CHECK=1){  cout<<"Yes End: "<<iend<<endl;  ch=getch(); }
					       }
				      }
			   }//<- Find Position End Offer
			  
			       
	  	     if( (YesOFFER ) && (GetWordFromStrOnTwoPoz(StrSource,StrFind,ibegin,iend) >0)) 
			     {  // Get OFFER-->// ����> 0 - �����
			   // On screen
				   cout<<" �����������: ";
				   if (CHECK=1) {cout<<" ibegin: "<<ibegin<<" iend : "<<iend<<endl;}
                   if (CHECK=1) {cout<<" ������ ����������� "<<isizeOFFER<<endl;}
 
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
	
			 } //<-- Get OFFER, ���� ����������� 

       }  // <- Cycle FIND OFFER in StrSource

     if (isizeOFFER>0) 
	 {
	  
		 //���� ���������� �� ���������
	cout<<"WORD 1  OFFER WORD 2:"<<endl;
 	// ��� �������-->
	 out<<StrBag<<endl;
	//  out<<StrSave<<endl;
    //<-- ��� �������
	  ch=getch();   
	  }
	 else 
	 {
       	//On screen
		cout<<"SAVE- �������� ������: "<<iCTStr<<' '<<StrSource<<endl;
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
	cout<<" ����� "<<endl;
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


// pStr -�������� ������ / PWord-����� / ibegpos- ���.������ / iendpos- ���.�����
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


// pStr -�������� ������ / PWord-����� / ibegpos- ���.������ ������
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

// pStr -�������� ������ / PWord-����� / iendpos- ���.����� ������� 
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
