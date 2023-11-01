#include <iostream>
using namespace std;
void maxstr(char* word, char& msym, int& mlen, int& mnum)
{
	int len=strlen(word);
	msym=word[0];
	mlen=1;
	mnum=1;
	int tnum=1;
	char tsym=word[0];
	int tlen=1;
	for (int i=1; i<len; i++)
	{
		if (word[i]==word[i-1]) {tlen++;}
		else
		{
			if (tlen>mlen)
			{
				mlen=tlen;
				msym=tsym;
				mnum=tnum;
			}
			tsym=word[i];
			tlen=1;
			tnum=i+1;
		}
	}
	if (tlen>mlen)
		{
			mlen=tlen;
			msym=tsym;
			mnum=tnum;
		}
}