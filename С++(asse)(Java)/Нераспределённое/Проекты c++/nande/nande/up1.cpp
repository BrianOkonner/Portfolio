#include <iostream>
#include <fstream>
#include "fun_h.h"
#include "MineList.h"
#include "stdafx.h"
using namespace std;
void main()
{
/*	char *s,*c;
	c=new char(20);
	s=new char(20);
	c="goods";
	_asm
	{
		mov ax,ds
		mov es,ax
		cld
		lea si,c
		lea di,s
		mov ecx,6
		rep movsb
		lea dx,s

	}*/
	Mlist s;
	int j=5,h=8;
	s.push_front(&j);
	s.push_front(&h);
	/*char h='(';
	s.push(&h);
	if(*(char*)s.top()!='(')
		cout<<*(char*)s.pop();
	else
		cout<<"fuck";*/
}