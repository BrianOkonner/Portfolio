#include <stdio.h>
int main ( int argc, char *argv[], char *argp[])
     {  int i=0;
        printf ("\n ��� ��������� %s", argv[0]);
        for    (i=1; i<argc; i++)
        printf ("\n �������� %d ����� %s", argv[i]);
        printf ("\n   ��������� ������������ �������:");
       while  (*argp)
          {  printf ("\n %s",*argp);
             argp++;
          }
        return (0);
     }