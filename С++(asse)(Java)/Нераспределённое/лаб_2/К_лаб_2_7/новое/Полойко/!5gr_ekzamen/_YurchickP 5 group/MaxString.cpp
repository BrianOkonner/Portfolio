#include<iostream>
#include<fstream>
#include<stdio.h>
#include"list.h"

using namespace std;

void vvod_dannyh(spisok_slov* uk)
{
	int j=0;
	uk->simvol=uk->slovo[j];
	int dl=1;
	int dl_now=1;
	char c;
	c=uk->simvol;
	uk->dl=1;
	uk->pos=1;
	j=1;
	while (uk->slovo[j]!='\0')
	{
		while (uk->slovo[j]==c)
		{
			j=j+1;
			dl_now=dl_now+1;
		}
		if (dl_now>dl)
		{
			uk->dl=dl_now;
			uk->pos=j-dl_now+1;
			dl=dl_now;
			uk->simvol=c;
		}
		dl_now=1;
		c=uk->slovo[j];
		j=j+1;
	}
}