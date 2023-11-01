/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие:   B5. Задан текстовый файл Input.txt, состоящий  из слов. Разделителями между словами является некоторое множество знаков препинания.
Найти в каждой строке  слова– числа (это слова, состоящие только из цифр), заменить  их числом,  равным сумме цифр этого слова–числа.
Результат записать  в новый файл Output.txt.
Упорядочить слова  в полученных  строках по  возрастанию количества цифр в словах, результат сортировки записать в файл Out_sort.txt.

Файл Input.txt

qwert tuert uert uert u ertu ertuertu ert ue rt ue rtu er tu er u
se rhse rh ser hs erh se rh sf hsd fh sd ry ewy qweryqwey
qwey qweyqweyqwyeqweyqwef  qeh sdfh sdf hsdfh sd
2 3523 253 h weyh df shsf hsd s 4634 6;34.62 34  sdfg rt3463 rt
346 2r yfdsh dfh s54 sfh eryserfhsdfhse4534 s fgs 346s fu 45764  hds se
346 346 234utruj dfyser yser ysery sery34 fgh45745 45 745 xfh
67 5 a1 b11 c111 d111111 e11111 f1111
abd abc abcd adfab sgq qgww a gsadgaweg aAsfasf aBasfasg aafc


Файл Output.txt

qwert tuert uert uert u ertu ertuertu ert ue rt ue rtu er tu er u
se rhse rh ser hs erh se rh sf hsd fh sd ry ewy qweryqwey
qwey qweyqweyqwyeqweyqwef qeh sdfh sdf hsdfh sd
2 13 10 h weyh df shsf hsd s 17 6 7 8 7 sdfg rt3463 rt
13 2r yfdsh dfh s54 sfh eryserfhsdfhse4534 s fgs 346s fu 26 hds se
13 13 234utruj dfyser yser ysery sery34 fgh45745 9 16 xfh
13 5 a1 b11 c111 d111111 e11111 f1111
abd abc abcd adfab sgq qgww a gsadgaweg aAsfasf aBasfasg aafc

Файл Out_sort.txt

qwert tuert uert uert u ertu ertuertu ert ue rt ue rtu er tu er u
se rhse rh ser hs erh se rh sf hsd fh sd ry ewy qweryqwey
qwey qweyqweyqwyeqweyqwef qeh sdfh sdf hsdfh sd
h weyh df shsf hsd s sdfg rt 2 6 7 8 7 13 10 17 rt3463
yfdsh dfh sfh s fgs fu hds se 2r 13 s54 26 346s eryserfhsdfhse4534
dfyser yser ysery xfh 9 13 13 sery34 16 234utruj fgh45745
5 a1 13 b11 c111 f1111 e11111 d111111
abd abc abcd adfab sgq qgww a gsadgaweg aAsfasf aBasfasg aafc

*/
#include "functions_h.h"
//#include "functions_strings_new.cpp"
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
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    ofstream out;
    char *seps=" ,._!?:;+-";
    in.open("Input.txt");
    out.open("Output.txt");
    string str;
    while(getline(in, str)){ // пока не достигнут конец файла класть очередную строку в переменную (s)
        //cout << str << endl; // выводим на экран
        const char *const_str=str.c_str();
        char *str_tmp=new char[strlen(const_str)+1];
        strcpy(str_tmp,const_str);
        single_spaces(str_tmp,seps);
        char *str_tmp_2=new char[strlen(str_tmp)+1];
        str_tmp_2[0]='\0';
        char* tmp=strtok(str_tmp," ");
        while(tmp)
        {
            if(!is_word_number(tmp))
            {
                strcat(str_tmp_2,tmp);
                strcat(str_tmp_2," ");
            }
            else
            {
                int number=atoi(tmp);
                int k=0;
                char *numb=new char[80];
                numb[0]='\0';
                while(number)
                {
                    k+=number%10;
                    number/=10;
                }
                strcat(str_tmp_2,itoa(k,numb,10));
                strcat(str_tmp_2," ");
                delete[] numb;
            }

        tmp=strtok(NULL, " ");
        }

        out<<str_tmp_2<<endl;
        delete[] str_tmp;
        //delete[] str_tmp_2;
    }
    in.close();
	out.close();

    in.open("Output.txt");
    out.open("Out_sort.txt");

    while(getline(in, str)){ // пока не достигнут конец файла класть очередную строку в переменную (s)
        const char *const_str=str.c_str();
        char *str_tmp=new char[strlen(const_str)+1];
        strcpy(str_tmp,const_str);
        single_spaces(str_tmp,seps);
        char *str_tmp_2=new char[strlen(str_tmp)+1];
        str_tmp_2[0]='\0';
        sort_by_number_of_digits(str_tmp,str_tmp_2);
        out<<str_tmp_2<<endl;
        delete[] str_tmp;
        delete[] str_tmp_2;
    }
    in.close();
    out.close();
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
