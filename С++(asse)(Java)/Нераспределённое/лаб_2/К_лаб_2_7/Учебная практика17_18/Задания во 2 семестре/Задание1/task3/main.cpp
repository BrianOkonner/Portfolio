/*
==============================================================
������� ��������
������� 2.0
������� B1
--------------------------------------------------------------
�������� ������� 1 ����� 8 ������
���������� �������
--------------------------------------------------------------
�������: ����� ��������� ���� Input.txt, ���������  �� ����.
������������� ����� ������� �������� ��������� ��������� 
������ ����������. �� ������ ������ ������� �����, �����
������� ������ ����� ���������� ����� ���� ������ � 
�������� ��� ������ � ����� ���� Output.txt.
����������� ����� � ���������� ������� �� ����������� ����, 
��������� ���������� �������� � ���� Out_sort.txt. 
����������� ������� strcmp �� ����� ���������� ��������� ���������� �������.
--------------------------------------------------------------
��������� � �������:

������ �� ����� ������ � ������ ����� ���������� �����, �����
����� ����������� ������ ����������� � ������ ������ ����� �����,
��������� ��� � ����� ������. ������� ����� ������. ����������� �����
� ����� ������ � ������� � ������ ���� ����� ������.
--------------------------------------------------------------
������ �1:

input.txt:
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
-------------
output.txt:
Lorem ipsum dolor sit amet elit sed do tempor ut labore et dolore magna aliqua
Ut enim ad quis nisi ut ex ea Duis aute
irure dolor in in velit esse cillum dolore eu fugiat nulla pariatur
sint non sunt in culpa qui officia mollit anim id est laborum
-------------
Out_sort.txt:
Lorem aliqua amet do dolor dolore elit et ipsum labore magna sed sit tempor ut
Duis Ut ad aute ea enim ex nisi quis ut
cillum dolor dolore esse eu fugiat in in irure nulla pariatur velit
anim culpa est id in laborum mollit non officia qui sint sunt
==============================================================
*/

#include <iostream>
#include <fstream>
#include <locale.h>
#include <string.h>

/*������������ ����� ������*/
#define MAXLENGTH 1000
/*������������ ���-�� ���� � ������*/
#define MAXWORDCOUNT 1000

using namespace std;


bool isLetter(char c) // �������� ��� ������ C ��� �����
{
	if (((c >= 'A') && (c <= 'Z')) ||
		((c >= 'a') && (c <= 'z')) ||
		((c >= '�') && (c <= '�')) ||
		((c >= '�') && (c <= '�')))
		return 1;
	return 0;
}

int strcmp2(char *a, char *b)
{
	int lenA = strlen(a), lenB = strlen(b), ans = 0;
	_asm
	{
		mov ecx, lenA
		cmp ecx, lenB
		jl comp
		mov ecx, lenB
	comp:
		mov esi, a
		mov edi, b
		repe cmpsb
		je _eq
		dec esi
		dec edi
	_eq:
		xor eax, eax
		mov al, [esi]
		sub al, [edi]
		cbw
		cwde
		mov ans, eax	
	}
	return ans;
}

void addWord(char **words, char *s, int st, int en, int &wordCount)
{
	/*���� ������ ������ �� �����, ������ ��� �� �����*/
	if (!isLetter(s[st])) return;

	words[wordCount] = new char[en - st + 2];

	/*�������� ������*/
	char *p = words[wordCount];
	int start = st;

	_asm
	{
		mov esi, s
		mov edi, p
		mov eax, start
		add esi, eax
		mov ecx, en
		sub ecx, eax
		inc ecx
		rep movsb
	}

	/*��������� 0 ������*/
	words[wordCount][en - st + 1] = '\0';

	wordCount++;

	return;
}

void swap(char *&a, char *&b)
{
	char *t = a;
	a = b;
	b = t;
}

void qsortt(char** a, int l, int r)
{
	int i = l, j = r;
	char *x = a[rand() % (r - l + 1) + l];

	do {
		while (strlen(a[i]) < strlen(x)) i++;
		while (strlen(a[j]) > strlen(x)) j--;

		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < r)
		qsortt(a, i, r);
	if (l < j)
		qsortt(a, l, j);

}

void out_words(ofstream &fout, char **words, int wordCount)
{
	for (int i = 0; i < wordCount; i++)
		fout << words[i] << " ";
	fout << endl;
}

void solve(ifstream &fin, ofstream &fout, ofstream &fsort)
{

	char *s, **words;
	int wordCount = 0, len, j, i, endLen;
	// s - ������� ������
	// words - ������ ����
	// wordCount - ���������� ����
	// len - ����� ������
	// j - ��������� �� ������ ����� �����
	// i - ��������� �� ��������� ����� �����
	// endLen - ����� ���������� �����


	/*��������� ������*/
	words = new char*[MAXWORDCOUNT];
	s = new char[MAXLENGTH];

	while (fin.getline(s, MAXLENGTH))
	{
		len = strlen(s);

		/*����� ���������� �����*/
		i = len - 1;
		while ((i >= 0) && (!isLetter(s[i]))) i--;
		if (i < 0) continue;
		j = i;
		while ((j >= 0) && (isLetter(s[j]))) j--;
		endLen = i - j;

		/*����� ����*/
		wordCount = 0;
		j = 0;
		for (i = 0; i <= len; i++)
		{
			/*���� �����*/
			while ((i < len) && (isLetter(s[i]))) i++;
			/*���� ����� ����� ������ ����� ���������� �����*/
			if (i - j <= endLen) addWord(words, s, j, i - 1, wordCount);
			/*���������� �����������*/
			while ((i < len) && (!isLetter(s[i]))) i++;
			j = i;
		}

		/*����� ����*/
		out_words(fout, words, wordCount);

		/*���������� ���� � ������*/
		qsortt(words, 0, wordCount - 1);

		/*����� ��������������� ����*/
		out_words(fsort, words, wordCount);

		/*������������ ������ ��� �����*/
		for (i = 0; i < wordCount; i++)
			delete[] words[i];

	}

	/*������������ ������, �������� ������*/
	delete[] words;
	delete[] s;
	fin.close();
	fout.close();
	fsort.close();

}


int main()
{
	setlocale(LC_ALL,"rus");
	ifstream fin;
	ofstream fout, fsort;

	/*�������� ������*/
	fin.open("input.txt");
	if (!fin)
	{
		cout << "Error: ������ �������� ����� \"input.txt\". ��������� ��� ������� � ����� � ����������";
		system("pause");
		exit(0);
	}
	fout.open("output.txt");
	fsort.open("Out_sort.txt");

	/*�����*/
	solve(fin, fout, fsort);

	/*�������� ����� ������� STRCMP*/
	char a[100], b[100];
	cout << "������� ��� ������ ������� �� ������ ��������: " << endl;
	cin.getline(a, 80);
	cin.getline(b, 80);
	cout << "��������� ���������: " << strcmp2(a, b) << endl;

	return 0;
}