#include <iostream>
#include <string.h>
using namespace std;
struct listWithWords{//наш список
	int length;//длина последовательности
	int number;
	char symbol;//символ
	char *word; 
	listWithWords *next;};
struct tempList{//вспомогательный список, куда будем вносить данные о каждом символе данного слова списка ListWithWords
	char symbol;
	int symbol_number;
	int length;
	tempList *next;};
void find_max_char_in_list(listWithWords *list){
	char *symbol;
	tempList *currert, *tList, *ttList,*ttAdress;
	currert=NULL;
	symbol=list->word;//присваиваем адресс начала слова, т.е. адресс первого символа
	int max=0;
	bool induk_sovpadeniya=false,induk_tt=false;

	for(int i=0;i<(strlen(list->word));i=i+1){

		if(induk_sovpadeniya==true){
			ttList=currert;
			while(ttList!=NULL){
			if(ttList->symbol==*(symbol+i)){
				ttList->length+=1;}//если встретили уже записанный в списке символ, то увеличиваем счетчик длины на 1
				induk_tt=true;
				if(ttList->length>max){
					max=ttList->length;
					ttAdress=ttList;}}//этой переменной присвоим адресс элемента списка, который содержит информацию о нужном нам символе
			ttList=ttList->next;}

	if(induk_sovpadeniya==false && induk_tt==false){//создаем элемент списка, в который заносим первый символ
	tList=new(struct tempList);
	tList->symbol=*(symbol+i);
	tList->length=1;
	tList->symbol_number=i+1;}
	tList->next=currert;
	currert=tList;

	induk_sovpadeniya=true;//вызовет проверку совпадения символа с ранее встречавшимся при очередной итерации
	induk_tt=false;//переходим к следующему символу
	}
	list->length=ttAdress->length;
	list->number=ttAdress->symbol_number;
	list->symbol=ttAdress->symbol;

}