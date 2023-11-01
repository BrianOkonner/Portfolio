/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: Поменять местами первое и последнее слова в строке.

Test:

mama papa tata dada rara
rara papa tata dada mama
Vremya vipolneniya: 0.047

*/
#include "functions_h.h"
#include "functions.cpp"


int main(void)
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    char *s="mama papa tata dada rara";
    const int n=strlen(s);
    cout<<s<<endl;
    int i=0,b_1=0,b_2=0;
    while(s[i]!=' ')
    {
        i++;
        b_1++;
    }
    i=n-1;
    while(s[i]!=' ')
    {
        b_2++;
        i--;
    }
    char s1[n+1];
    for(i=0;i<b_2;i++)
        s1[i]=s[n-b_2+i];
    for(i=0;i<n-b_2-b_1;i++)
        s1[b_2+i]=s[b_1+i];
    for(i=0;i<b_1;i++)
        s1[n-b_1+i]=s[i];
    s1[n]='\0';
    cout<<s1<<endl;
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
