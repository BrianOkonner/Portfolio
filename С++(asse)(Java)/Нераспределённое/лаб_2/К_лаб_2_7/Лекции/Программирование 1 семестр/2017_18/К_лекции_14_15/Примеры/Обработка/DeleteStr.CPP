//Удаление из строки заданного слова(подстроки)
//Автор Глиндзич Дмитрий
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void delstr(const char*,const char*);       //Удаляет подстроку из строки

void main()
{
 printf("Enter your string:");
 char c[80],w[80];
 gets(c);                                   //Ввод строки
 printf("Enter the word:");
 gets(w);                                   //Ввод подстроки
 delstr(c,w);
 puts(c);                                   //Вывод результата
 getch();
}

void delstr(const char*A,const char*B)
{
 char* s;
 int n=strlen(B);                           //Длина подстроки
 while((s=(char*)strstr(A,B))!=NULL)               //Пока в строке есть заданные подстроки:
 {
   while(*(s+n)!=NULL)                      //Сдвигаем всю строку влево
    {                                       //стирая найденную подстроку
     *s=*(s+n);
     s++;
    }
   *s=NULL;                                //Ограничиваем ее
 }
}