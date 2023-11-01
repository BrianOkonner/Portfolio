#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern "C" size_t strspn(const char*, const char *);
extern "C" int isupper(int);
extern "C" int isalpha(int);

#pragma warning (disable : 4996)
#pragma warning (disable : 4273)

#include "sort.h"

const int MAX_LEN = 256;

//символы-разделители
char seps[] = {'(',')','-',',','.','!','?',' ',';',':',10,13,0};
char *R = seps;

bool allUpper;

int main( void ){
	FILE *fin, *fout, *fout_sort;

	char *pS, *pN, *pU;		// позиции, где мы находимся в соответствующих строках

	char *S = new char[MAX_LEN];	// S - прочитанная строка
	char *NewS = new char[MAX_LEN];	// NewS - строка без слов из заглавных букв
	char *Upp = new char[MAX_LEN];	// Upp - слова из заглавных букв

	if(!(fin = fopen("Input.txt", "r")) ){
		printf("Failed to open file \"Input.txt\"\n");
		return 0;
	}

	fout = fopen("Output.txt", "w");
	fout_sort = fopen("Output_Sort.txt", "w");
	
	while (true){		
		fgets(S, MAX_LEN, fin);
		if(feof(fin))break;
		_asm{
			 //вначале все указатели указывают на начала строк
			mov eax, S
			mov pS, eax

			mov eax, NewS
			mov pN, eax

			mov eax, Upp
			mov pU, eax

			while_S:
				mov eax, pS
				cmp byte ptr [eax], 0	// пока p - не конец строки 
										//(p не указывает на нулевой символ)
				je end_while_S				
								
				push dword ptr R
				push dword ptr pS				
				call strspn // находим количество симоволв-разделителей, результат в eax
				pop ebx
				pop ebx

				mov ecx, eax 
				mov esi, pS
				mov edi, pN
				rep movsd // копируем все разделители в результирующую строку

				add pN, eax //двигаем указатели
				add pS, eax

				//находим количество символов в слове, результат в ecx
				mov ecx, 0
				mov allUpper, 1

				word_while:
					mov eax, pS
					push ecx //запоминаем ecx
					mov ebx, dword ptr [eax][ecx]
					and ebx, 0xFF					
					push ebx
					call isalpha
					pop ebx
					pop ecx		//вспоминаем ecx
					cmp eax, 0	//проверяем - следующий символ - буква?
					je end_word_while	//если нет - выходим из цикла

					//если буква, проверяем, она заглавная?
					mov eax, pS
					push ecx	//запоминаем ecx
					mov ebx, [eax][ecx]
					and ebx, 0xFF					
					push ebx
					call isupper
					pop ebx 
					pop ecx		//вспоминаем ecx
					cmp eax, 1

					je upper

					//если не заглавная, помечаем, что слово состоит не только из заглавных
					mov allUpper, 0 

				upper:
					inc ecx //двигаемся к след. символу
					jmp word_while

				end_word_while:

				//проверяем, все ли заглавные буквы
				cmp allUpper, 1
				je wordUpper 
				jne wordNotUpper

				wordUpper:
					cmp ecx, 0		// если длина слова 0
					je nextStep		// то не копируем слово, просто прыгаем на след. итерацию
									// если все заглавные, будем копировать в Upp				
					mov eax, ecx	//количество символов
					mov esi, pS		//источник
					mov edi, pU		//приемник
					rep movsd	//копируем слово
					add pS, eax	// двигаем указатели вперед
					add pU, eax
					mov eax, pU
					mov byte ptr [eax], ' ' //ставим разделитель
					inc pU
					// прыгаем к след итерации
					jmp nextStep

				wordNotUpper:
					// если есть и строчные буквы, копируем в NewS
					mov eax, ecx	//количество символов
					mov esi, pS		//источник
					mov edi, pN		//приемник
					rep movsd		//копируем слово
					add pN, eax		//двигаем указатели
					add pS, eax

				nextStep:
					jmp while_S

			end_while_S:
				mov eax, pN //дописываем к полученным строкам символы конца строки
				mov byte ptr [eax], 0
				mov eax, pU
				mov byte ptr [eax], 0
		}

		char* tmp = strtok(S, seps);
		char* ch;
		int num_words=0, i=0;
		str* words = new str[30];
		while( tmp ){
			ch = new char[strlen(tmp)+1];
			strcpy(ch, tmp);
			words[i].value = strlen(tmp);
			words[i].word = ch;
			num_words++;
			i++;
			tmp = strtok(0, seps);
		}
		sort_asm(words, num_words);

		for(i=0; i<num_words; i++)
			fprintf(fout_sort, "%s ", words[i].word);
		fprintf(fout_sort, "\n");
		fprintf(fout, "%s", Upp);		//выводим сначала слова только из заглавных букв
		fprintf(fout, "%s", NewS);	//потом все остальное
	}

	free(S); free(NewS); free(Upp);
	fclose(fin);
	fclose(fout);
	fclose(fout_sort);
}
