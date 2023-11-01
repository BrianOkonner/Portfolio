#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <search.h>
#include <string>
using namespace std;

int asmStrlen(const char *s)
{
	int x;
	_asm
	{
		xor ecx, ecx
		xor eax, eax
		cld
		dec ecx
		mov edi, s
		repne scasb
		not ecx
		lea eax, [ecx - 1]
		mov x, eax
	}
	return x;

}
void asmStrcpy(char *str1, const char* str2)
{
	int x = asmStrlen(str2);
	_asm
	{
		cld
		mov esi, str2
		mov edi, str1
		mov ecx, x
		inc ecx
		rep movsb
	}
}
void asmStrcat(char *str1, const char* str2)
{
	int x = asmStrlen(str2);
	int y = asmStrlen(str1);
	_asm
	{
		cld
		mov esi, str2
		mov edi, str1
		add edi, y
		mov ecx, x
		inc ecx
		rep movsb
	}
}
void single_spaces(char* str, char *seps)
{
	int i, k, string_length = asmStrlen(str);
	i = 0;
	while (i<asmStrlen(str) - 1) // ��� ����������� �������� �� ��������� �������
	{
		if (strchr(seps, str[i]))
		{
			if (strchr(seps, str[i + 1]))
			{
				for (k = i; k<string_length; k++)
				{
					str[k] = str[k + 1];
				}
				string_length--;
			}
			else
			{
				str[i] = ' ';
				i++;
			}
		}
		else
			i++;
	}
}

void string_recover(char* str, int string_length)
{
	for (int i = 0; i<string_length; i++)
		if (str[i] == '\0')
			str[i] = ' ';
}

char *search_word(char *str, char *word)// ����� ����� � ������
{
	char *tmp = strtok(str, " ");
	while (tmp)
	{
		if (!strcmp(tmp, word))
			return tmp;
		tmp = strtok(NULL, " ");
	}
	return NULL;
}

char *search_word_from_n(char *str, char *word, int n)// ����� ����� � ������,  �������  � �������� �������;
{
	int k = 0;
	if (n == 0)
		return search_word(str, word);
	if (str[n - 1] == ' ')
		return search_word(str + n, word);
	else
	{
		while (str[n + k] != ' ' && str[n + k] != '\0')
			k++;
		if (str[n + k] == '\0' )
			return NULL;
		else
			return search_word(str + k + n + 1, word);
	}

}
char *delete_word(char *str, char *word)
{
	char* s2;
	int i, string_length = asmStrlen(str);
	s2 = new char[string_length - asmStrlen(word)];
	s2[0] = '\0';
	char *tmp = search_word(str, word);
	string_recover(str, string_length);
	for (i = 0; i<string_length - asmStrlen(tmp); i++)
		s2[i] = str[i];
	for (i = string_length - asmStrlen(tmp); i<string_length - asmStrlen(word); i++)
		s2[i] = str[i + asmStrlen(word) + 1];
	s2[string_length - asmStrlen(word)] = '\0';
	return s2;
}

char* delete_word_from_n(char *str, char *word, int string_length, int n)
{
	char *tmp = search_word_from_n(str, word, n);
	string_recover(str, string_length);
	if (tmp)
	{
		for (int j = 0; j<string_length - asmStrlen(word) - 1; j++)
		{
			tmp[j] = tmp[j + asmStrlen(word) + 1];
		}
		str[string_length - asmStrlen(word) - 1] = '\0';
	}
	return str;
}

int is_palindrom(char *word)
{
	int word_length = asmStrlen(word);
	for (int i = 0; i<word_length / 2; i++)
	{
		if (word[i] != word[word_length - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

char *insert_word_after_given_word(char *str, char *word, char *given_word)
{
	int i = 0, j, string_length = asmStrlen(str);
	char *tmp = search_word(str, given_word);
	string_recover(str, string_length);
	if (!tmp)
	{
		cout << "No such word in the string" << endl; return str;
	}
	else
	{
		string_length += asmStrlen(word) + 1;
		while (tmp[i] != ' ')
			i++;
		i++;

		for (j = string_length; j >= string_length - asmStrlen(tmp + i) + asmStrlen(word) + 1; j--)
		{
			str[j] = str[j - asmStrlen(word) - 1];
		}
		for (j = 0; j<asmStrlen(word); j++)
		{
			tmp[i + j] = word[j];
		}
		tmp[i + asmStrlen(word)] = ' ';
		str[string_length] = '\0';
	}
	return str;
}

char *swap_words(char *str, char *word_1, char *word_2, int word_1_length, int word_2_length)
{
	int i;
	char *w1 = new char[word_1_length + 1];
	char *w2 = new char[word_2_length + 1];
	for (i = 0; i<word_1_length; i++)
		w1[i] = word_1[i];
	w1[word_1_length] = '\0';
	for (i = 0; i<word_2_length; i++)
		w2[i] = word_2[i];
	w2[word_2_length] = '\0';
	str = insert_word_after_given_word(str, w1, w2);
	str = insert_word_after_given_word(str, w2, w1);
	str = delete_word_from_n(str, w1, asmStrlen(str), word_1 - str);
	str = delete_word_from_n(str, w2, asmStrlen(str), word_2 - str + word_2_length - word_1_length);
	return str;
}

char *change_words(char *str, char *word_1, int word_1_length, char *new_word)
{
	int i;
	char *w1 = new char[word_1_length + 1];
	for (i = 0; i<word_1_length; i++)
		w1[i] = word_1[i];
	w1[word_1_length] = '\0';
	str = insert_word_after_given_word(str, new_word, w1);
	str = delete_word_from_n(str, w1, asmStrlen(str), word_1 - str);
	return str;
}

void search_word_number(char *str, char *str_2)
{
	char *space1 = new char[2];
	space1[0] = ' ';
	space1[1] = '\0';
	int string_length = asmStrlen(str);
	char *tmp = strtok(str, " ");
	while (tmp)
	{
		int flag = 1;
		for (int i = 0; i<asmStrlen(tmp); i++)
			if (tmp[i]<'0' || tmp[i]>'9')
			{
				flag = 0;
				break;
			}
		if (flag)
		{
			strcat(str_2, tmp); strcat(str_2, space1);
		}
		tmp = strtok(NULL, " ");
	}
	string_recover(str, string_length);
	str_2[asmStrlen(str_2) - 1] = '\0';
}

int is_word_number(char* tmp)
{
	int flag = 1;
	for (int i = 0; i<asmStrlen(tmp); i++)
		if (tmp[i]<'0' || tmp[i]>'9')
		{
			flag = 0;
			break;
		}
	return flag;
}

int comparator(const void *word_1, const void *word_2)
{
	return strcmp((char *)word_1, (char *)word_2);
}

void my_sort_with_qsort(char *str, char *str_2)
{
	int str_length = asmStrlen(str);
	int k = 0, max_length = 0, i, j;
	char *tmp = strtok(str, " ");
	while (tmp)
	{
		k++;
		if (max_length<asmStrlen(tmp))
			max_length = asmStrlen(tmp);
		tmp = strtok(NULL, " ");
	}
	string_recover(str, str_length);
	char **mass;
	mass = new char*[k];
	for (i = 0; i<k; i++)
		mass[i] = new char[max_length];
	tmp = strtok(str, " ");
	for (i = 0; i<asmStrlen(tmp); i++)
	{
		mass[0][i] = tmp[i];
	}
	for (i = asmStrlen(tmp); i<max_length; i++)
	{
		mass[0][i] = ' ';
	}
	for (j = 1; j<k; j++)
	{
		tmp = strtok(NULL, " ");
		for (i = 0; i<asmStrlen(tmp); i++)
		{
			mass[j][i] = tmp[i];
		}
		for (i = asmStrlen(tmp); i<max_length; i++)
		{
			mass[j][i] = ' ';
		}
	}
	string_recover(str, str_length);
	char *mass_for_qsort = new char[k*max_length];
	for (j = 0; j<k; j++)
		for (i = 0; i<max_length; i++)
			mass_for_qsort[j*max_length + i] = mass[j][i];
	qsort((void *)mass_for_qsort, k, max_length, comparator);
	for (j = 0; j<k; j++)
		for (i = 0; i<max_length; i++)
			mass[j][i] = mass_for_qsort[j*max_length + i];
	int c = 0;
	for (j = 0; j<k; j++)
	{
		for (i = 0; i<max_length; i++)
		{
			if (mass[j][i] != ' ')
				str_2[c++] = mass[j][i];
		}
		str_2[c++] = ' ';
	}
	str_2[c - 1] = '\0';

	for (i = 0; i<k; i++)
		delete[] mass[i];
	delete[] mass;
}

void sort_by_number_of_digits(char *str, char *str_2)
{
	char *space1 = new char[2];
	space1[0] = ' ';
	space1[1] = '\0';
	int str_length = asmStrlen(str);
	int k = 0, max_length = 0, i, j;
	char *tmp = strtok(str, " ");
	while (tmp)
	{
		k++;
		if (max_length<asmStrlen(tmp))
			max_length = asmStrlen(tmp);
		tmp = strtok(NULL, " ");
	}
	string_recover(str, str_length);
	int **mass;
	mass = new int *[k];
	for (i = 0; i<k; i++)
		mass[i] = new int[3];
	tmp = strtok(str, " ");
	int c = 0;
	for (j = 0; j<asmStrlen(tmp); j++)
	{
		if (tmp[j] >= '0' && tmp[j] <= '9')
			c++;
	}
	mass[0][0] = c;
	mass[0][1] = tmp - str;
	mass[0][2] = asmStrlen(tmp);
	for (i = 1; i<k; i++)
	{
		tmp = strtok(NULL, " ");
		int c = 0;
		for (j = 0; j<asmStrlen(tmp); j++)
		{
			if (tmp[j] >= '0' && tmp[j] <= '9')
				c++;
		}
		mass[i][0] = c;
		mass[i][1] = tmp - str;
		mass[i][2] = asmStrlen(tmp);
	}
	for (i = 0; i <= max_length; i++)
	{
		for (j = 0; j<k; j++)
			if (mass[j][0] == i)
			{
				strcat(str_2, str + mass[j][1]);
				strcat(str_2, space1);
			}
	}
	for (i = 0; i<k; i++)
		delete[] mass[i];
	delete[] mass;
}
