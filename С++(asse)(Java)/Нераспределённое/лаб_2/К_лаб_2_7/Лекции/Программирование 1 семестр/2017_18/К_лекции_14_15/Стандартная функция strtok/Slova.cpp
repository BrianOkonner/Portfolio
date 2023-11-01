
#include <iostream.h>
#include <stdio.h>
#include <string.h>
//Разбор строки на слова(лексемы)
void main()
{
//	char  str[ ] = "12 34,ab:cd;56";
	char* str;
	str= new char[20];
	cin>>str;  //Ввод  строки до пробела
	char *p;
	p = strtok(str, ";,: ");
	while (p)
	{
		cout<<p<<endl;
			/* печатает в столбик значения слов */
		p = strtok(NULL, ";,: ");
	}

}
