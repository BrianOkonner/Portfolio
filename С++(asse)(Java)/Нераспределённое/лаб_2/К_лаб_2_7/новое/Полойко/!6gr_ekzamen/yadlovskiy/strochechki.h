//yadlovskiy
#include "conio.h"
#include "stdio.h"
#include "iostream"


int end_str (char ch)
{
	if ((ch=='\n')||(ch=='\0'))
		return 1;
	return 0;
}


int razd (char ch)
{
	if (end_str(ch))
		return 1;
	char i=-1, str[]={" ,.;:\n"};
	while (!end_str(str[++i]))
		if (ch==str[i])
			return 1;
	return 0;
}


int digit (char ch)
{
	if (('0'<=ch)&&(ch<='9'))
		return 1;
	return 0;
}

int alfa_ru (char ch)
{
	if (('à'<=ch)&&(ch<='ÿ'))
		return 1;
	if (('À'<=ch)&&(ch<='ß'))
		return 1;
	return 0;
}

int alfa_en (char ch)
{
	if (('a'<=ch)&&(ch<='z'))
		return 1;
	if (('Z'<=ch)&&(ch<='Z'))
		return 1;
	return 0;
}

int alfa (char ch)
{
	if (alfa_ru(ch) || alfa_en(ch))
		return 1;
	return 0;
}


int letter (char ch)
{
	// if razd not been
/*	if ( digit(ch) || alfa(ch) )
		return 1;
	return 0;
*/
	
	if (!razd(ch))
		return 1;
	return 0;
	
}

int end_word (char ch)
{
	if (!letter(ch))
		return 1;
	return 0;
	
	/*
	if (end_str(ch))
		return 1;
	if (razd(ch))
		return 1;
	return 0;
	*/
}


int word_digit (char *str)
{
	int i=-1;
	while (letter(str[++i]))
		if (!digit(str[i]))
			return 0;
	return 1;
}
int word_to_int (char *str)
{
	int i=-1, k=0;
	while (digit(str[++i]))
		k=k*10+str[i]-'0';
	return k;
}
int len_word (char *str)
{
	int k=-1;
	while (letter(str[++k]));
	return k;
}
void del_let (char *str)
{
	int i=-1;
	while (!end_str(str[++i]))
		str[i]=str[i+1];
}
void add_let (char *str, char ch)
{
	char i=-1, tt=ch, rr;
	while (!end_str(str[++i]))
	{
		rr=str[i];
		str[i]=tt;
		tt=rr;
	}
	str[i+1]=str[i];
	str[i]=tt;
}
void del_word (char *str)
{
	while (letter(*str))
		del_let(str);
}
void add_word (char *str, char *stt)
{
	char i=0, *word;
	word = new char [1+len_word(stt)];
	*word=*stt;
	while (!end_word(str[i++]))
		word[i]=stt[i];
	i=-1;
	while (letter(str[i++]))
		add_let(str+i, word[i]);
	delete [] word;
}
void x_change (char *str, int ii, int jj)
{
	int k, i=ii, j=jj;
	if (j<i)
	{
		k=j;
		j=i;
		i=k;
	}
/*	char *word;
	word = new char [1+len_word(stt)];
	*word=*(str+j);
	while (!end_word(str[i++]))
		word[i]=stt[i];
*/
}
int mymain ()
{
	setlocale(LC_ALL,".1251");
	return 0;
}
//yadlovskiy