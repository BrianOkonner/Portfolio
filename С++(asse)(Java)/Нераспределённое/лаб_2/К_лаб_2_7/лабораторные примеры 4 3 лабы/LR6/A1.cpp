/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8
*/

struct tSpisok
{
    char surname[20];
    int group;
	int record_book_number;
	int mark_man;
	int mark_geo;
	int mark_prog;
};

#include "functions_h.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <search.h>
#include <string>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "ru");
    unsigned int clk;
    int k=0,i=0,p=0;
    ifstream in_spis;
    ofstream out;
    in_spis.open("input.txt");
    tSpisok spis_tmp;
	in_spis.seekg(0, in_spis.end);
	int length = in_spis.tellg();
	
	in_spis.close();
	in_spis.open("input.txt");
	if (length!=0)
	{
		while (!(in_spis.eof()))
		{
			in_spis >> spis_tmp.surname >> spis_tmp.group >> spis_tmp.record_book_number >> spis_tmp.mark_man >> spis_tmp.mark_geo >> spis_tmp.mark_prog;
			k++;
		}

		tSpisok *students = new tSpisok[k];
		in_spis.close();
		in_spis.open("input.txt");
		while (!(in_spis.eof()))
		{
			in_spis >> students[i].surname >> students[i].group >> students[i].record_book_number
				>> students[i].mark_man >> students[i].mark_geo >> students[i].mark_prog;
			i++;
		}

		qsort(students, k, sizeof(tSpisok), tSpisok_compare);

		out.open("OutAll.txt");
		cout << "OutAll.txt : " << endl;
		out << "Average mark for all students : " << average_mark_all(students, k) << endl;
		cout << "Average mark for all students : " << average_mark_all(students, k) << endl;
		out << "All students : " << endl;
		cout << "All students : " << endl;
		out << setw(20) << left << "Surname" << setw(10) << "Group" << setw(20) << "Record-book" << setw(20) << "Average mark" << endl;
		cout << setw(20) << left << "Surname" << setw(10) << "Group" << setw(20) << "Record-book" << setw(20) << "Average mark" << endl;
		for (i = 0; i < k; i++)
		{
			out << setw(20) << students[i].surname << setw(10) << students[i].group << setw(20) << students[i].record_book_number
				<< setw(20) << average_mark(students[i].mark_man, students[i].mark_geo, students[i].mark_prog) << endl;
			cout << setw(20) << students[i].surname << setw(10) << students[i].group << setw(20) << students[i].record_book_number
				<< setw(20) << average_mark(students[i].mark_man, students[i].mark_geo, students[i].mark_prog) << endl;
		}
		out.close();
		out.open("OutO.txt");
		cout << endl << "OutO.txt : " << endl;
		out << "List of high achievers : " << endl;
		cout << "List of high achievers : " << endl;
		out << setw(20) << left << "Surname" << setw(10) << "Group" << setw(20) << "Record-book" << endl;
		cout << setw(20) << left << "Surname" << setw(10) << "Group" << setw(20) << "Record-book" << endl;
		for (i = 0; i < k; i++)
		{
			if (isHighAchiever(students, i))
			{
				out << setw(20) << students[i].surname << setw(10) << students[i].group << setw(20) << students[i].record_book_number << endl;
				cout << setw(20) << students[i].surname << setw(10) << students[i].group << setw(20) << students[i].record_book_number << endl;
			}
		}
		out.close();


		out.open("OutN.txt");
		cout << endl << "OutN.txt : " << endl;
		out << "List of students with negative mark : " << endl;
		cout << "List of students with negative mark : " << endl;
		out << setw(20) << left << "Surname" << setw(10) << "Group" << setw(20) << "Record-book" << endl;
		cout << setw(20) << left << "Surname" << setw(10) << "Group" << setw(20) << "Record-book" << endl;
		for (i = 0; i < k; i++)
		{
			if (isNegative(students, i))
			{
				out << setw(20) << students[i].surname << setw(10) << students[i].group << setw(20) << students[i].record_book_number << endl;
				cout << setw(20) << students[i].surname << setw(10) << students[i].group << setw(20) << students[i].record_book_number << endl;
			}
		}
	}
	else
	{
		cout << "Empty file! " << endl;
	}
    clk=clock();
    cout << endl << "Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
