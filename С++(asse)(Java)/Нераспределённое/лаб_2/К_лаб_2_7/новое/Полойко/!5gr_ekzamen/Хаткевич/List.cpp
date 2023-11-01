#include "list.h"


void cut ( char* s, words* &marker )
{
	bool f=false;
	int k=0;
	for ( int i=0; i<strlen(s); ++i )
	{
		if (((s[i]!=' ')&&(s[i]!=',')&&(s[i]!='-')&&(s[i]!='.')&&(s[i]!=';')&&(s[i]!=':')&&(s[i]!='!'))&&(f==false))
		{
			k=0;
			marker->word[k]=s[i];
			f=true;
			++k;
			continue;
		}
		if (((s[i]!=' ')&&(s[i]!=',')&&(s[i]!='-')&&(s[i]!='.')&&(s[i]!=';')&&(s[i]!=':')&&(s[i]!='!'))&&(f==true))
		{
			marker->word[k]=s[i];
			++k;
			continue;
		}
		if (((s[i]==' ')||(s[i]==',')||(s[i]=='-')||(s[i]=='.')||(s[i]==';')||(s[i]==':')||(s[i]=='!'))&&(f==true))
		{
			marker->word[k]='\0';
			f=false;
			words* temp=new words;
			marker->next=temp;
			marker=marker->next;
			continue;
		}
	}
	marker->word[k]='\0';
	words* temp=new words;
	marker->next=temp;
	marker=marker->next;
}
