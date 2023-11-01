//3. Функция для вставки слова в строку после заданного слова.
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>

const char* sep=" ,./?!;:\}{][()+-=\n\t";
char str1[80],str2[80],strrez[80],str3[80];

	char* ins_word(char* str1,char* str2,char *str3, const char* sep)
{	

	char str[80]="";
	char p[80]="";
	char mezh[2];
    int i=0;
	strcat(str1," ");
	while (i<strlen(str1))
	{
		if (!strchr(sep,str1[i]))
		{
		
			mezh[0]=str1[i];
	mezh[1]=0;
			strcat(p,mezh);
		}
			else
			{	strcat(str,p);
				if (!strcmp(p,str2))
			{strcat(str," ");
				strcat (str,str3);
				i+=strlen(str3);
				}
			
			mezh[0]=str1[i];
	mezh[1]=0;
			strcat(str,mezh);
				strcpy(p,"");
			}


			i++;
	}

			return str;
					}

	
	
	

	int main()
	{
	
	char** slova;
	cout<<"Input string"<<endl;
	gets(str1);
	cout<<"Input word after which you can insert new word"<<endl;
	gets(str2);
	cout<<"Input new word for inserting"<<endl;
	gets(str3);
	strcpy(strrez,ins_word(str1,str2,str3,sep));
		   puts(strrez);
	}