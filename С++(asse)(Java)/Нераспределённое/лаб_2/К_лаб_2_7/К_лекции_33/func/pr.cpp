#include <stdio.h>
int main ( int argc, char *argv[], char *argp[])
     {  int i=0;
        printf ("\n Имя программы %s", argv[0]);
        for    (i=1; i<argc; i++)
        printf ("\n аргумент %d равен %s", argv[i]);
        printf ("\n   Параметры операционной системы:");
       while  (*argp)
          {  printf ("\n %s",*argp);
             argp++;
          }
        return (0);
     }