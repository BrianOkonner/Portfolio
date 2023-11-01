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

//�������-�����������
char seps[] = {'(',')','-',',','.','!','?',' ',';',':',10,13,0};
char *R = seps;

bool allUpper;

int main( void ){
	FILE *fin, *fout, *fout_sort;

	char *pS, *pN, *pU;		// �������, ��� �� ��������� � ��������������� �������

	char *S = new char[MAX_LEN];	// S - ����������� ������
	char *NewS = new char[MAX_LEN];	// NewS - ������ ��� ���� �� ��������� ����
	char *Upp = new char[MAX_LEN];	// Upp - ����� �� ��������� ����

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
			 //������� ��� ��������� ��������� �� ������ �����
			mov eax, S
			mov pS, eax

			mov eax, NewS
			mov pN, eax

			mov eax, Upp
			mov pU, eax

			while_S:
				mov eax, pS
				cmp byte ptr [eax], 0	// ���� p - �� ����� ������ 
										//(p �� ��������� �� ������� ������)
				je end_while_S				
								
				push dword ptr R
				push dword ptr pS				
				call strspn // ������� ���������� ��������-������������, ��������� � eax
				pop ebx
				pop ebx

				mov ecx, eax 
				mov esi, pS
				mov edi, pN
				rep movsd // �������� ��� ����������� � �������������� ������

				add pN, eax //������� ���������
				add pS, eax

				//������� ���������� �������� � �����, ��������� � ecx
				mov ecx, 0
				mov allUpper, 1

				word_while:
					mov eax, pS
					push ecx //���������� ecx
					mov ebx, dword ptr [eax][ecx]
					and ebx, 0xFF					
					push ebx
					call isalpha
					pop ebx
					pop ecx		//���������� ecx
					cmp eax, 0	//��������� - ��������� ������ - �����?
					je end_word_while	//���� ��� - ������� �� �����

					//���� �����, ���������, ��� ���������?
					mov eax, pS
					push ecx	//���������� ecx
					mov ebx, [eax][ecx]
					and ebx, 0xFF					
					push ebx
					call isupper
					pop ebx 
					pop ecx		//���������� ecx
					cmp eax, 1

					je upper

					//���� �� ���������, ��������, ��� ����� ������� �� ������ �� ���������
					mov allUpper, 0 

				upper:
					inc ecx //��������� � ����. �������
					jmp word_while

				end_word_while:

				//���������, ��� �� ��������� �����
				cmp allUpper, 1
				je wordUpper 
				jne wordNotUpper

				wordUpper:
					cmp ecx, 0		// ���� ����� ����� 0
					je nextStep		// �� �� �������� �����, ������ ������� �� ����. ��������
									// ���� ��� ���������, ����� ���������� � Upp				
					mov eax, ecx	//���������� ��������
					mov esi, pS		//��������
					mov edi, pU		//��������
					rep movsd	//�������� �����
					add pS, eax	// ������� ��������� ������
					add pU, eax
					mov eax, pU
					mov byte ptr [eax], ' ' //������ �����������
					inc pU
					// ������� � ���� ��������
					jmp nextStep

				wordNotUpper:
					// ���� ���� � �������� �����, �������� � NewS
					mov eax, ecx	//���������� ��������
					mov esi, pS		//��������
					mov edi, pN		//��������
					rep movsd		//�������� �����
					add pN, eax		//������� ���������
					add pS, eax

				nextStep:
					jmp while_S

			end_while_S:
				mov eax, pN //���������� � ���������� ������� ������� ����� ������
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
		fprintf(fout, "%s", Upp);		//������� ������� ����� ������ �� ��������� ����
		fprintf(fout, "%s", NewS);	//����� ��� ���������
	}

	free(S); free(NewS); free(Upp);
	fclose(fin);
	fclose(fout);
	fclose(fout_sort);
}
