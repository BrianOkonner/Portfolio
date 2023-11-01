/*
��������� ������ �������������
���� 1
������ 8


3.	����� ��������� ���� Input.txt, ��������� �� ����. ������������� ����� �������
�������� ��������� ��������� ������ ����������. ��� ������ ������, ������� �� ������, 
�������������� �����, ������� ����������� � ������ ������ � �������� ��������� � ����� 
���� Output.txt. ����������� ����� � ���������� ������� �� ����������� ���������� ��������� 
�������� ���� � ������, ��������� ���������� �������� � ���� Out_sort.txt. 

��������:
1) ��������� ������ ������ �� �����
2) ������ ���������� �� ���������� �������
3) ������ ���� ����� �� ������ ������ � ������ ��������� ��� ����� ���������, ���� ����� ����������,
�� ���������(������� ��������� ����� ����� find'�� � ������ ��� � ����� ��������� ��������� ����� �����+1,
� �������� ������ ��� � ����� �����. ��� �����, ������������ ����������� ����� ����� �� ������)
4) ���������� ����������

�����:
Input.txt:
qa4q eg Hello/./. 1234 .,/ /.,//.,./;. world././ !.
Hello./,world!.;sag 1234
qa4q eg Hello/./. 1234 .,/Hello /.,//.,./;.Hello He123llo He world././ !.
Hello/./. 1234 .,/Hello /.,//.,./;.Hello He123llo He world !.;sag 1234 ,.,1234 ,jhvjhvhfhc ufty f 1234 tf yhg jhjhvjhvhfhc ufty f tf yhg jhvjhvjhvhfhc ufty f tf yhg jhvv

Output.txt:
HelloHello./,worldworld!.;sag 12341234
qa4qqa4q egeg HelloHello/./. 12341234 .,/HelloHello /.,//.,./;.HelloHello He123llo He worldworld././ !.
HelloHello/./. 12341234 .,/HelloHello /.,//.,./;.HelloHello He123llo He worldworld !.;sag 12341234 ,.,12341234 ,jhvjhvhfhc ufty f 12341234 tf yhg jhjhvjhvhfhc ufty f tf yhg jhvjhvjhvhfhc ufty f tf yhg jhvv

Out_Sort.txt
12341234 sag HelloHello worldworld
12341234 He He123llo egeg qa4qqa4q HelloHello HelloHello HelloHello worldworld
12341234 12341234 12341234 12341234 f He f f tf tf tf yhg sag yhg yhg ufty He123llo ufty ufty jhvv HelloHello HelloHello HelloHello worldworld jhvjhvhfhc jhjhvjhvhfhc jhvjhvjhvhfhc

*/
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include "Header.h"
using namespace std;
//extern "C" char * COPYSTR(char *,const char *);
int main()
{
	setlocale(0, "");
	string s; // ���� ����� ������ ��������� ������
	unsigned int k = 0,d=0;
	char**masstr = new char*[1000], *context, *context1, delimiter[] = " .,!?:;\/n";
	ifstream f1;
	ifstream file("input.txt"); 
	ofstream f2;
	f2.open("output.txt");
	while (getline(file, s)) // ���� �� ��������� ����� ����� ������ ��������� ������ � ���������� (s)
	{	
		masstr[k] = new char[s.length() + 1];
		COPYSTR(masstr[k], (char*)s.c_str());
		//strcpy_s(masstr[k], s.length() + 1, s.c_str());
		if (d<LenAsm(masstr[k]))
			d = LenAsm(masstr[k]);
		k++;
	}
	file.close();

	//������ ������ char ��� ������ ������
	char **temp = new char*[k];
	for (int q = 0; q <= k; q++)
		temp[q] = new char[d+1];
	COPYSTR(temp[0], (char*)masstr[0]);

	//��������� ������ ������ �� �����, ������� �� � ������ � ������� �� ����������
	int i = 0;
	string *word = new string[500];
	for (char *p = strtok_s(temp[0], delimiter, &context); p != NULL; p = strtok_s(NULL, delimiter, &context), i++)
		word[i] = p;

	//
	char *a;
	int start,pos,count1=0;
	for (int w = 1; w < k; w++)
	{
		string o = string(masstr[w]);
		for (int j = 0; j < i; j++)
		{
			int f = LenAsm(masstr[w]);
			COPYSTR(temp[w], (char*)masstr[w]);
			//strcpy_s(temp[w], f + 1, masstr[w]);//������ ��� �������� �������� temp[w], �.�. ����� strtok ��� ��������
			string str = string(word[j]);
			start = 0;
			a = strtok_s(temp[w], delimiter, &context1);
			int n = 0;
			while (a != NULL)
			{
				string str1 = string(a);
				if (str == str1)
				{
					o.insert(o.find(str, start), str);//��� ������� ��������� str � ������� start
					pos = o.find(str, start); //��� ��� ������ �����, ����� ����� ����������� � ���������� �����
					start = pos + 1+str.size(); // ��� ��� ������ �����, ����� ����� ����������� � ���������� �����
					if (start >= o.size())break; 
				}
				a = strtok_s(NULL, delimiter, &context1);
			}
		}
		f2 << o<<"\n";
	}
	f2.close();
	f1.close();

	//����������
	ifstream f3("output.txt");
	f2.open("Out_sort.txt");
	string st;
	k = 0;
	while (getline(f3, st))
	{	// ���� �� ��������� ����� ����� ������ ��������� ������ � ���������� (st)
		masstr[k] = new char[st.length() + 1];
		COPYSTR(masstr[k], (char*)st.c_str());
		//strcpy_s(masstr[k], st.length() + 1, st.c_str());
		k++;
	}
	for (int r = 0; r < k; r++)
	{
		string *words = new string[500];
		int c = 0;
		// ������� ����� ������ � words, ������������ ������ �� ����������
		for (char *p = strtok_s(masstr[r], delimiter, &context1); p != NULL; p = strtok_s(NULL, delimiter, &context1), c++)
			words[c] += p;
		for (int i = 0; i < c; i++)

			for (int j = 0; j < i; j++)
			{
				if (count(words[i])<count(words[j]))
				{
					string t = words[i];
					words[i] = words[j];
					words[j] = t;
				}
			}
		for (int i = 0; i < c; i++)
			f2 << words[i]<<" ";
		f2 << "\n";
	}
	f1.close();
	f2.close();

	system("pause");
	return 0;
}

