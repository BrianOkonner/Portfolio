//Разработать программу для вывода на экран компьютера текущей кодовой таблицы

#include "stdafx.h"
#include  <stdio.h>
#include <conio.h>

int main(int argc, char* argv[])
{
   printf("Character Codes:\n");
   for (char i=0;i<=15;++i)
   {
	   for(char j=0;j<=15;++j)   
		   printf("%c ",i*16+j);
	   printf("\n");
   }
   _getch();
  	return 0;
}
