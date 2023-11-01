/*
�������� ����� ���������
1 ����
������ ��-8

�������:   B5. ����� ��������� ���� Input.txt, ���������  �� ����. ������������� ����� ������� �������� ��������� ��������� ������ ����������.
����� � ������ ������  ������ ����� (��� �����, ��������� ������ �� ����), ��������  �� ������,  ������ ����� ���� ����� �����������.
��������� ��������  � ����� ���� Output.txt.
����������� �����  � ����������  ������� ��  ����������� ���������� ���� � ������, ��������� ���������� �������� � ���� Out_sort.txt.

���� Input.txt

qwert tuert uert uert u ertu ertuertu ert ue rt ue rtu er tu er u
se rhse rh ser hs erh se rh sf hsd fh sd ry ewy qweryqwey
qwey qweyqweyqwyeqweyqwef  qeh sdfh sdf hsdfh sd
2 3523 253 h weyh df shsf hsd s 4634 6;34.62 34  sdfg rt3463 rt
346 2r yfdsh dfh s54 sfh eryserfhsdfhse4534 s fgs 346s fu 45764  hds se
346 346 234utruj dfyser yser ysery sery34 fgh45745 45 745 xfh
67 5 a1 b11 c111 d111111 e11111 f1111
abd abc abcd adfab sgq qgww a gsadgaweg aAsfasf aBasfasg aafc


���� Output.txt

qwert tuert uert uert u ertu ertuertu ert ue rt ue rtu er tu er u
se rhse rh ser hs erh se rh sf hsd fh sd ry ewy qweryqwey
qwey qweyqweyqwyeqweyqwef qeh sdfh sdf hsdfh sd
2 13 10 h weyh df shsf hsd s 17 6 7 8 7 sdfg rt3463 rt
13 2r yfdsh dfh s54 sfh eryserfhsdfhse4534 s fgs 346s fu 26 hds se
13 13 234utruj dfyser yser ysery sery34 fgh45745 9 16 xfh
13 5 a1 b11 c111 d111111 e11111 f1111
abd abc abcd adfab sgq qgww a gsadgaweg aAsfasf aBasfasg aafc

���� Out_sort.txt

qwert tuert uert uert u ertu ertuertu ert ue rt ue rtu er tu er u
se rhse rh ser hs erh se rh sf hsd fh sd ry ewy qweryqwey
qwey qweyqweyqwyeqweyqwef qeh sdfh sdf hsdfh sd
h weyh df shsf hsd s sdfg rt 2 6 7 8 7 13 10 17 rt3463
yfdsh dfh sfh s fgs fu hds se 2r 13 s54 26 346s eryserfhsdfhse4534
dfyser yser ysery xfh 9 13 13 sery34 16 234utruj fgh45745
5 a1 13 b11 c111 f1111 e11111 d111111
abd abc abcd adfab sgq qgww a gsadgaweg aAsfasf aBasfasg aafc

*/
#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <search.h>
#include <string>
using namespace std;

int main(void)
{
	setlocale(LC_ALL, ".1251");
	unsigned int clk;
	ifstream in;
	ofstream out;

	char *seps = new char[12];
	seps[0] = ' ';
	seps[1] = ',';
	seps[2] = '.';
	seps[3] = '_';
	seps[4] = '!';
	seps[5] = '?';
	seps[6] = ':';
	seps[7] = ';';
	seps[8] = '+';
	seps[9] = '-';
	seps[10] = '\0';
	in.open("Input.txt");
	out.open("Output.txt");
	string str;

	while (getline(in, str)) // ���� �� ��������� ����� ����� ������ ��������� ������ � ���������� (s)
	{ 		
		char *space1 = new char[2];
		space1[0] = ' ';
		space1[1] = '\0';
		const char *const_str = str.c_str();
		char *str_tmp = new char[asmStrlen(const_str) + 1];
		asmStrcpy(str_tmp, const_str);
		single_spaces(str_tmp, seps);
		char *str_tmp_2 = new char[asmStrlen(str_tmp) + 1];
		str_tmp_2[0] = '\0';
		char* tmp = strtok(str_tmp, " ");

		while (tmp)
		{
			if (!is_word_number(tmp))
			{
				asmStrcat(str_tmp_2, tmp);
				asmStrcat(str_tmp_2, space1);
			}
			else
			{
				int number = atoi(tmp);
				int k = 0;
				char *numb = new char[80];
				numb[0] = '\0';
				while (number)
				{
					k += number % 10;
					number /= 10;
				}
				asmStrcat(str_tmp_2, _itoa(k, numb, 10));
				asmStrcat(str_tmp_2, space1);
				delete[] numb;
			}

			tmp = strtok(NULL, " ");
		}

		out << str_tmp_2 << endl;
	}
	in.close();
	out.close();

	in.open("Output.txt");
	out.open("Out_sort.txt");

	while (getline(in, str)) // ���� �� ��������� ����� ����� ������ ��������� ������ � ���������� (s)
	{ 
		const char *const_str = str.c_str();
		char *str_tmp = new char[asmStrlen(const_str) + 1];
		asmStrcpy(str_tmp, const_str);
		single_spaces(str_tmp, seps);
		char *str_tmp_2 = new char[asmStrlen(str_tmp) + 1];
		str_tmp_2[0] = '\0';
		sort_by_number_of_digits(str_tmp, str_tmp_2);
		out << str_tmp_2 << endl;
	}

	in.close();
	out.close();
	clk = clock();
	cout << "Vremya vipolneniya: " << clk / 1000.0 << endl;
	return 0;
}
