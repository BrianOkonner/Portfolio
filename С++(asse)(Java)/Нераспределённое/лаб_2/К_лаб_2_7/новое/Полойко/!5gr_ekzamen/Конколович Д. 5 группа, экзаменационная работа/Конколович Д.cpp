//���������� ������� 5 ������
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


void find_max_char_in_list(listWithWords *list);
void main(){
	setlocale(LC_ALL, ".1251");//������� ���� ��� ���������
	
	char *word;//��������� �� ������, ������� ����� ��������� ������� ,���������� ��������
	listWithWords *head,*currert,*list;
	currert=NULL;
	list=NULL;
	char mas[]={' ','-',',','.',';',':','!'};//������ ������������ ��� �������

	FILE* fileWithText;
	if(!(fileWithText=fopen("input.txt","r"))){
		cout<<"���� �� ��������!"<<endl;}
	else{
		while(!(feof(fileWithText))){
			char *str=new char[81];//�.�. � ������ ������ �� ����� 80 ��������, �� �������� ������ ��� 81(��������� ��� '\0')
			fgets(str,81,fileWithText);
			word=strtok(str,mas);//������ ��� ������ ����������
		while(word){
					list=new(struct listWithWords);
					list->word=word;
					
					//������ ������, ����� ������ ���� ������� find_max_char_in_list(listWithWords *list), �� �� ��� � ����� ����, ������ ��� ����� ������

	{char *tsymbol;//��� ������� ��� ���������� �������� � ������ �����, ������� ��������� �� �������. �������� ����, ����� ����� ���� ����� ���������
	tempList *tcurrert, *tList, *ttList,*ttAdress;
	tcurrert=NULL;
	tsymbol=list->word;//����������� ������ ������ �����, �.�. ������ ������� �������
	int max=0;
	bool induk_sovpadeniya=false,induk_tt=false;

	for(int i=0;i<(strlen(list->word));i=i+1){

	*tsymbol=*(list->word+i);
		if(induk_sovpadeniya==true){
			ttList=tcurrert;
			while(ttList!=NULL)
			{
			if(ttList->symbol==*tsymbol){
				ttList->length+=1;//���� ��������� ��� ���������� � ������ ������, �� ����������� ������� ����� �� 1
				induk_tt=true;}
				if(ttList->length>max){
					max=ttList->length;
					ttAdress=ttList;}//���� ���������� �������� ������ �������� ������, ������� �������� ���������� � ������ ��� �������
				ttList=ttList->next;}}
	induk_sovpadeniya=false;

	if(induk_sovpadeniya==false && induk_tt==false){//������� ������� ������, � ������� ������� ������ ������
	tList=new(struct tempList);
	tList->symbol=*tsymbol;
	tList->length=1;
	tList->symbol_number=i+1;
	tList->next=tcurrert;
	tcurrert=tList;}
	
	induk_sovpadeniya=true;//������� �������� ���������� ������� � ����� ������������� ��� ��������� ��������
	induk_tt=false;//��������� � ���������� �������
	}
	list->length=ttAdress->length;
	list->number=ttAdress->symbol_number;
	list->symbol=ttAdress->symbol;}//������ ������ �����, ��� ����� ������������������, ����� ������� � ��� ������ � ������� ������




					list->next=currert;
					currert=list;
			word=strtok(NULL,mas);}}}//������ � ����������� ���� ���������� ������ � ��� �������� ������ ��������
	
	head=currert;
	list=head;

	
/*
	fclose(fileWithText);
	FILE* fileForText;
	fileForText=fopen("Result1.txt","w");
	
	int k=1;
	while(list!=NULL){
		fprintf(fileForText,"%-10d %10s %10s %10d %10d\n",k,list->word,list->symbol,list->length,list->number);
		list=list->next;
	k=k+1;}//��� �� ������ ��� ������ � ����, ����� �� ���� ����� :( 
				fclose(fileForText); */
}