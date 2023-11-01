/*

��������� ������ �������������
���� 1
������ 8


�3. 

3.	����  ���  ����������� ������� X=(xi),i=1..n, n<=10,  � Y=(yi),i=1..m, m<=10. �����  ��  "�����������",
�.�. ������  Z, ���������� ������ �� �����  ��������. ����� �������� ������� m+n.


�� ������� ����������� �� ���������� ��� ����� ��������. �.�. ������ ������ �������� ������ ������� � ������������ � ���������� �������.
����� ������ � ��� �����.

�����:
������ 1: 1 2 5 13
������ 2: 2 4 13 22 25 26 30 31 33
����� ��������: 2 13
���������� ������: 13
����� ����������� ���������� �� ������: 0.001 ������
*/
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include "functions.h"
using namespace std;


extern "C" int PER(int*ARR1, int*ARR2, int *Result, int len1, int len2, int&level);
//int Peresechinie(int *ARR1,int *ARR2,int *Result,int len1,int len2,int &level)
//{
//	int level1 = 0;
//	int count = 0;
//	int len = len1 + len2;
//	_asm
//	{
//		xor esi, esi
//		xor edi, edi
//		xor ecx, ecx
//		//xor eax,eax
//		mov ebx, ARR1
//		mov edx, ARR2
//		mov esi, Result
//		add ecx, len
//		//-------------
//
//again:	mov eax,[ebx]
//		inc level1
//		cmp eax,[edx]
//		je point1
//		jl point2
//		jg point3
//
//point1: add ebx,4
//		add edx,4
//		mov [esi],eax
//		add esi,4
//		sub ecx,2
//		inc count
//		cmp ecx,0
//		je finish
//		jmp again
//
//point2: add ebx,4
//		dec ecx
//		cmp ecx,0
//		je finish
//		jmp again
//
//point3: add edx,4
//		dec ecx
//		cmp ecx,0
//		je finish
//		jmp again
//finish:		
//	}
//	level = level1;
//	return count;
//}
int main()
{
	setlocale(0, "");
	ifstream f1;
	ofstream f2;
	f1.open("input.txt");
	if (!f1.is_open())
	{
		cerr << "Open file failed." << endl;
		//system("pause");
		//return 0;
	}
	f2.open("output.txt");
	srand(time(NULL));
	unsigned int start_time = clock();
	int l, n1, n2, k = 0, count=0;
	f1 >> n1>> n2;
	int *mas1 = new int[n1];
	int *mas2 = new int[n2];
	int *result = new int[10];
	f2 << "������ 1: ";
	for (int i = 0; i < n1; i++)
	{
		f1 >> mas1[i];
		f2 <<mas1[i]<<" ";
	}
	f2 << endl;
	f2 << "������ 2: ";
	for (int i = 0; i < n2; i++)
	{
		f1 >> mas2[i];
		f2 << mas2[i]<<" ";
	}
	f2 << endl;
	int n=0;
	int level = 0;
    n =	PER(mas1, mas2, result, n1, n2,level);

	f2 << "����� ��������: ";
	for (int i = 0; i < n; i++)
	{
		f2 << result[i] << " ";
	}
	f2 << "\n���������� ������: " << level << endl;
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	f2 << "����� ����������� ���������� �� ������: " << search_time / 1000. << " ������" << endl;
	f2.close();
	system("pause");
	return 0;
}


