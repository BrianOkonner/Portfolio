#include <iostream>
#include <string.h>
using namespace std;
struct listWithWords{//��� ������
	int length;//����� ������������������
	int number;
	char symbol;//������
	char *word; 
	listWithWords *next;};
struct tempList{//��������������� ������, ���� ����� ������� ������ � ������ ������� ������� ����� ������ ListWithWords
	char symbol;
	int symbol_number;
	int length;
	tempList *next;};
void find_max_char_in_list(listWithWords *list){
	char *symbol;
	tempList *currert, *tList, *ttList,*ttAdress;
	currert=NULL;
	symbol=list->word;//����������� ������ ������ �����, �.�. ������ ������� �������
	int max=0;
	bool induk_sovpadeniya=false,induk_tt=false;

	for(int i=0;i<(strlen(list->word));i=i+1){

		if(induk_sovpadeniya==true){
			ttList=currert;
			while(ttList!=NULL){
			if(ttList->symbol==*(symbol+i)){
				ttList->length+=1;}//���� ��������� ��� ���������� � ������ ������, �� ����������� ������� ����� �� 1
				induk_tt=true;
				if(ttList->length>max){
					max=ttList->length;
					ttAdress=ttList;}}//���� ���������� �������� ������ �������� ������, ������� �������� ���������� � ������ ��� �������
			ttList=ttList->next;}

	if(induk_sovpadeniya==false && induk_tt==false){//������� ������� ������, � ������� ������� ������ ������
	tList=new(struct tempList);
	tList->symbol=*(symbol+i);
	tList->length=1;
	tList->symbol_number=i+1;}
	tList->next=currert;
	currert=tList;

	induk_sovpadeniya=true;//������� �������� ���������� ������� � ����� ������������� ��� ��������� ��������
	induk_tt=false;//��������� � ���������� �������
	}
	list->length=ttAdress->length;
	list->number=ttAdress->symbol_number;
	list->symbol=ttAdress->symbol;

}