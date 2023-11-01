//Tyrsa Maksym
//8-th group
#include <iostream>
#include <string>
using namespace std;
int mas[100];
int findnum(char*st)
{
	char num[]={"0123456789"};
	char set[100];
	char*tmp;
	char str[80];
	int i=0;
	strcpy(str,st);
	tmp=strtok(st,num);
	set[0]='\0';
	while(tmp)
	{
		strcat(set,tmp);
		tmp=strtok(NULL,num);
	}
	tmp=strtok(str,set);
	while(tmp)
	{
		mas[i]=atoi(tmp);
		tmp=strtok(NULL,set);
		i++;
	}
	return i;
}

void main ()
{
	FILE*IN,*OUT;

	char s[81];
	char*st=s;
	int i;
	if((IN=fopen("input.txt","rt"))==NULL)
	{
		cout<<"The file cannot be opened\n";
		return ;
	}
	OUT=fopen("OutputIn.txt","wt");
	fgets(s,80,IN);
	i=findnum(s);
	for(int j=0;j<i;j++)
		fprintf(OUT,"%i \n",mas[j]);
	while(!feof(IN))
	{
		fgets(s,80,IN);		
		i=findnum(s);
		for(int j=0;j<i;j++)
			fprintf(OUT,"%i \n",mas[j]);
	}

	fclose(IN);
	fclose(OUT);
	
}
