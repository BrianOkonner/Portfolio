//КОНКОЛОВИЧ ДМИТРИЙ 5 ГРУППА
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


void find_max_char_in_list(listWithWords *list);
void main(){
	setlocale(LC_ALL, ".1251");//русский язык для сообщений
	
	char *word;//указатель на строку, которая будет содержать лексему ,выделенную стртоком
	listWithWords *head,*currert,*list;
	currert=NULL;
	list=NULL;
	char mas[]={' ','-',',','.',';',':','!'};//массив разделителей для стртока

	FILE* fileWithText;
	if(!(fileWithText=fopen("input.txt","r"))){
		cout<<"Файл не открылся!"<<endl;}
	else{
		while(!(feof(fileWithText))){
			char *str=new char[81];//т.к. в каждой строке не более 80 символов, то выделяем память под 81(последний для '\0')
			fgets(str,81,fileWithText);
			word=strtok(str,mas);//первый раз стрток используем
		while(word){
					list=new(struct listWithWords);
					list->word=word;
					
					//вообще говоря, здесь должна идти функция find_max_char_in_list(listWithWords *list), но ее код я вынес сюда, потому что искал ошибку

	{char *tsymbol;//это функция для нахождения сведений о каждом слове, которые требуются по условию. поставил сюда, чтобы легче было дебаг проводить
	tempList *tcurrert, *tList, *ttList,*ttAdress;
	tcurrert=NULL;
	tsymbol=list->word;//присваиваем адресс начала слова, т.е. адресс первого символа
	int max=0;
	bool induk_sovpadeniya=false,induk_tt=false;

	for(int i=0;i<(strlen(list->word));i=i+1){

	*tsymbol=*(list->word+i);
		if(induk_sovpadeniya==true){
			ttList=tcurrert;
			while(ttList!=NULL)
			{
			if(ttList->symbol==*tsymbol){
				ttList->length+=1;//если встретили уже записанный в списке символ, то увеличиваем счетчик длины на 1
				induk_tt=true;}
				if(ttList->length>max){
					max=ttList->length;
					ttAdress=ttList;}//этой переменной присвоим адресс элемента списка, который содержит информацию о нужном нам символе
				ttList=ttList->next;}}
	induk_sovpadeniya=false;

	if(induk_sovpadeniya==false && induk_tt==false){//создаем элемент списка, в который заносим первый символ
	tList=new(struct tempList);
	tList->symbol=*tsymbol;
	tList->length=1;
	tList->symbol_number=i+1;
	tList->next=tcurrert;
	tcurrert=tList;}
	
	induk_sovpadeniya=true;//вызовет проверку совпадения символа с ранее встречавшимся при очередной итерации
	induk_tt=false;//переходим к следующему символу
	}
	list->length=ttAdress->length;
	list->number=ttAdress->symbol_number;
	list->symbol=ttAdress->symbol;}//вносим данные такие, как длина последовательности, номер символа и сам символ в элемент списка




					list->next=currert;
					currert=list;
			word=strtok(NULL,mas);}}}//второй и последующие разы используем стрток и уже обнуляем первый параметр
	
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
	k=k+1;}//где то ошибка при выводе в файл, никак не могу найти :( 
				fclose(fileForText); */
}