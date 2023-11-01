#define _CRT_SECURE_NO_WARNINGS
#include "MyFunctions.h"
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

void readF(char *str)
{
	
	ifstream fin("Input.txt");
	while (!fin.eof())
	{
		fin.getline(str, 255);
		moveWords(str);
	}

}

int strlen(char* s)
{
	int x;
	_asm
	{
		xor ecx, ecx
		push edi
		xor eax, eax
		cld
		dec ecx
		mov edi, s
		repne scasb
		not ecx
		pop edi
		lea eax, [ecx - 1]
		mov x, eax
	}
	return x;
}

void moveWords(char *str)
{
	char *tmp = new char[strlen(str) + 2];
	char *word = new char[strlen(str) + 2];
	int counter = 0;
	word[0] = '\0';
	tmp[0] = '\0';


	char *ptr = strtok(str, " :;,!-.");

	while (ptr != 0)
	{
		counter++;
		if (isupper(ptr[0]))
		{
			strcat(word,ptr);
			strcat(word, " ");
		}
		else
		{
			strcat(tmp, ptr);
			strcat(tmp, " ");
		}
		
		ptr = strtok(0, " :;,!-.");
	}

	strcat(word, tmp);
	cout << "Uppercase sort complite, see Output.txt"<< endl;
	//������ �����
	ofstream fout("Output.txt", ios::app);
	fout << word;
	fout.close();

	//������ ���������� 
	sortInit(word, counter);
	
	//������� ������
	delete[] word;
	delete[]tmp;
}
void swap_str_ptrs(char *&a, char *&b)
{
	char *t = a;
	a = b;
	b = t;
}


void quicksort_strs(char** a, int l, int r)
{
	int i = l, j = r;
	char *x = a[rand() % (r - l + 1) + l];

	do {
		while (strlen(a[i]) < strlen(x)) i++;
		while (strlen(a[j]) > strlen(x)) j--;

		if (i <= j) {
			swap_str_ptrs(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < r)
		quicksort_strs(a, i, r);
	if (l < j)
		quicksort_strs(a, l, j);

}

void sortInit(char *word,  int length)
{
	//������������� �������
	char **array = new char*[length];
	for (int i = 0; i<length; i++)
	{
		array[i] = new char[60];
	}
	//����� �������������
	//���������� ������� �������
	int j = 0;
	char *ptr = strtok(word, " :;,!-.");

	while (ptr != 0)
	{
		array[j] = ptr;
		ptr = strtok(0, " :;,!-.");
		j++;
	}

	//����������
	quicksort_strs(array, 0,length-1);
	cout << "QuickSort complite, see Output_sort.txt" << endl;
	//������ � ����
	for (int i= 0; i<length; i++)
	{
		
		ofstream fout("Output_sort.txt", ios::app);
		fout << array[i]<<" ";
		fout.close();
	}
}


void strcat(char *str1, char *str2)
{
	_asm
	{
			mov edi, str1
			push    edi; //����� str1
			mov edi, str2
			mov esi, edi
			not ecx//�����  str2
			pop edi
			rep movsb; //����������t �����
			xor al, al
			stosb
			mov eax, str1;
			ret
			xor ecx, ecx
			mov al, cl
			dec ecx
			repne   scasb
			dec edi
	}
}