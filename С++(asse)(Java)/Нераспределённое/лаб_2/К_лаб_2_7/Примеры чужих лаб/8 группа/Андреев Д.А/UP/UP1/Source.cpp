/*
������� ������� 8 ������

������� 1: ����� ��������� ���� Input.txt, ���������  �� ����. ������������� ����� �������
�������� ��������� ��������� ������ ����������. �� ������ ������ ������� �����, ����� �������
������ ����� ���������� ����� ���� ������ �  �������� ��� ������  � ����� ���� Output.txt.
����������� �����  � ����������  ������� ��  ����������� ����, ��������� ���������� ��������
� ���� Out_sort.txt.

C���� ���������� MS Visual Studio 2017
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

struct word_t {
	char *_word;
	size_t length;
};


//����� ������ ���������
int strlena(char st[1000]) {
	char s[1000];
	strcpy(s, st);
	int b = 0;
	int typeSize = sizeof(char);
	
	
	__asm {

		xor esi, esi	//�������
		xor ecx, ecx
		beginasm :
		cmp s[esi], 0	//���� ������
			je endasm

			inc ecx
			add esi, typeSize
			jmp beginasm
			endasm :
		mov b, ecx
	}
	return b;
}



//����� ���������� ����� � ������ (��)
/*char *lastword(char *string) {

	char *secondstr[300], *strcheck[300];
	*secondstr = strtok(string, " ,.-;\n");

	while (*secondstr != NULL) {
		*strcheck = strtok(NULL, " ,.-;\n");
		if (*strcheck == NULL) return *secondstr;
		*secondstr = strtok(NULL, " ,.-;\n");
		if (*secondstr == NULL) return *strcheck;
	}
}*/

//����� ���������� ����� � ������ (���������)
char *lastword(char *sk) {

	int typeSize = sizeof(char);
	char s1[1000];
	char s2[1000] = { 0 };


	int b, k=0;
	b = strlena(sk);

	strcpy(s1, sk);

	_asm {
		mov ecx, b		//����� - ���������� loop
		lea esi, s1		//�������� ������
		add esi, ecx	//� �����
		dec esi	
		lea edi, s2		//��������� ����� �����
		std				//����������� � 1 (������ ������)

		

		//*****���� ������ ��������� ���������*****
		point4:
		lodsb
			cmp al, '\n'
			je point4

			cmp al, ' '
			jne point3

			dec ecx
			dec b
			jmp point4
		//******************************************

			m_beg :

		lodsb
		    cmp al, ' '	//���� ��������� ������
			je here
			//**
			point3 :
			//**
			loop m_beg	;����� ��������� ecx
			here : 
		cld; ����������� � 0 (����� �������)
			
			lodsb		//������������ � ������ ������� �����
			lodsb
			cmp al, ' '	//���� �������� ����� ������� ���������
			jne point2
			point:
			lodsb
				point2:
				cmp al, '\n'		//���� �����
				je done
			mov byte ptr[edi], al	//� ��, ��� ����� �������� � ������ ������ ������� � ���������
			inc edi
					inc ecx			//���� �� �����, ��� ������, ����� ������� ��� ����
					cmp ecx, b
					je done
			
			jmp point
				done:
	}

	return s2;

}

//������������ ����� �� ���������� ����
char *newstring(int n, char *inistring, int length) {
	int flag = 0;
	char *str3 = new char[300];
	char *str4 = new char[300];
	//�������������� �����
	while (strlena(inistring) != length) inistring[strlena(inistring)] = ' ';

	//-------------------------------------------------------------------
	str3 = strtok(inistring, " ,.-;\n");
	if (strlena(str3) <= n) { strcpy(str4, str3); flag = 1; } //���� ��� str4, ����� strcat �� ��������� ��-�� ������������� �����������
	while (str3 != NULL) {
		str3 = strtok(NULL, " ,.-;\n");
		if (str3 == NULL) break;	//��� ���� � ���������� �����, �� ����� �������� �� �����
									//		cout << "str3 = " << str3 << endl;
		if (strlena(str3) <= n && flag != 0) { strcat(str4, " "); strcat(str4, str3); }	//������ �� str4
		else if (strlena(str3) <= n && flag == 0) { strcpy(str4, str3); flag = 1; };
		//	cout << "str4 = " << str4 << endl;
	}


	return str4;
}

//��� ����������
void _swap(word_t &w1, word_t &w2) {
	word_t tmp = w1;
	w1 = w2;
	w2 = tmp;
}

void main() {
	setlocale(0, "rus");
	FILE *in;
	in = fopen("input.txt", "r");
	char **str = new char*[1500]; //������������ ���������� �����
	char *str2 = new char[3000];
	int n = 0;
	while (!feof(in)) {
		str[n] = new char[3000];  //������������ ���������� �������� � ������
		fgets(str[n], 3000, in);
		n++;
	}

	int i, k = 0, len, length, j; char *p;
	word_t words[300];

	for (i = 0; i < n; i++) cout << str[i];

	ofstream out;
	out.open("output.txt");

	ofstream out_sort;
	out_sort.open("out_sort.txt");

	for (i = 0; i < n; i++) {
		length = strlena(str[i]);
		///////////////
		str2 = lastword(str[i]);

		len = strlena(str2);
		str2 = newstring(len, str[i], length);
		out << str2 << endl;
		//����������
		for (p = strtok(str2, " ,.-;\n"); p; p = strtok(NULL, " ,.-;\n")) {
			words[k]._word = new char[strlena(p) + 1];
			strcpy(words[k]._word, p);
			words[k++].length = strlena(p);
		}

		//=======������������=======
		for (int k1 = 0; k1 < k; ++k1)
			for (j = k1; j < k; ++j)
				if (words[k1].length > words[j].length)
					_swap(words[k1], words[j]);

		for (j = 0; j < k; ++j) {
			out_sort << words[j]._word << ' ';
		}
		k = 0; //���� ������, ����������� ����� �� ���� �������
		out_sort << endl;
	}
	system("pause");
}