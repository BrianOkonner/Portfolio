/*2. Класс множество, элементами которого являются 
 целые числа.. Интерфейс класса разработать самостоятельно.
 При реализации класса нужно учесть, что в последующем
 будет реализован шаблон класса множество. То есть реализация
 должна быть, как можно более общей, чтобы её можно было
 перенести на множество, элементы которого имеют тип отличный 
 от integer.*/

#include "Set.h"
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <exception>

int* renew(int*ip,int oldn,int newn)
{
	int*p=NULL;
	try
	{
	    p=new int[newn];
	    for(int t=0;t<oldn;++t)
	     	p[t]=ip[t];
    }
	catch(exception)
	{
		delete(p);
		return NULL;
	}
	return p;
}

Set::Set():p(NULL),count(0)
{
}  

Set::Set(const Set&s)
{
	count=s.count;
	p=renew(s.p,s.count,s.count);	
}

Set::Set(int*r,int n)
{
  try
  {
	  p=renew(r,n,n);
	  count=n;
	  sort();
  }
  catch(exception)
  {
	  Set();
	  delete(p);
  }
}

void Set::sort()
{
	for(int t=0;t<count-1;++t)
		for(int h=count-1;h>t;--h)
		   if(p[h]<p[h-1])
		   {
			   int d=p[h-1];
			   p[h-1]=p[h];
			   p[h]=d;
		   }		
}
	
bool Set::include(int n)
{
    bool ind=false;
	for(int t=0;t<count;++t)
		if(p[t]==n)ind=true;
    return ind; 
}


Set operator + (const Set &s1 ,const int n)
{
	Set s;
	bool ind=true;
	for(int t=0;t<s1.count;++t)
		if(s1.p[t]==n)ind=false;
    if(ind)
	{
		s.p=renew(s1.p,s1.count,s1.count+1);
		s.count=s1.count+1;
		s.p[s.count-1]=n;
		s.sort();
	}
	else
	    s=s1;
    return s; 	    
}

Set operator - (const Set &s1 ,const int n)
{
	Set s;
	int ind=-1;
	for(int t=0;t<s1.count;++t)
		if(s1.p[t]==n)ind=t;
    if(ind!=-1)
	{
		
		for(int t=0;t<s1.count;++t)
		  if(t!=ind)s=s+s1.p[t];
	}
	else
	    s=s1;
    return s; 
}

Set Set:: operator + (const Set&s1)
{
	Set s(s1);
	for(int t=0;t<count;++t)
	{
	    bool ind=false;	
		for(int h=0;h<s1.count;++h)
		  if(p[t]==s1.p[h])ind=true;
        if(!ind)s=s+p[t];
    }
	return s;
}

Set Set:: operator * (const Set&s1)
{
	Set s;
	for(int t=0;t<count;++t)
	{
	    bool ind=false;	
		for(int h=0;h<s1.count;++h)
		  if(p[t]==s1.p[h])ind=true;
        if(ind)s=s+p[t];
    }
	return s;
}

Set Set:: operator - (const Set&s1)
{
	Set s(*this);
	for(int t=0;t<count;++t)
	{
	    bool ind=false;	
		for(int h=0;h<s1.count;++h)
		  if(p[t]==s1.p[h])ind=true;
        if(ind)s=s-p[t];
    }
	return s;
}


Set& Set::operator *= (const Set&s1)
{
  *this=*this*s1;
  return *this;
}

Set& Set::operator += (const Set&s1)
{
  *this=*this+s1;
  return *this;
}

Set& Set::operator -= (const Set&s1)
{
  *this=*this-s1;
  return *this;
}

Set& Set::operator += (const int n)
{
	*this=*this+n;
	return *this;
}

Set& Set::operator -= (const int n)
{
	*this=*this-n;
	return *this;
}


bool operator == (const Set&s1,const Set&s2)
{
	if(s1.count!=s2.count)return false;
	for(int t=0;t<s1.count;++t)
		if(s1.p[t]!=s2.p[t])return false;
	return true;	
}

bool operator != (const Set&s1,const Set&s2)
{
	if(s1.count!=s2.count)return true;
	for(int t=0;t<s1.count;++t)
		if(s1.p[t]!=s2.p[t])return true;
	return false;	
}

bool operator > (const Set&s1,const Set&s2)
{
	for(int t=0;t<s2.count;++t)
	{
		bool ind=false;
		for(int j=0;j<s1.count;++j)
			if(s2.p[t]==s1.p[j])ind=true;
        if(!ind)return false;
	}
	if(s1.count==s2.count)return false;
	return true;
}

bool operator >= (const Set&s1,const Set&s2)
{
	for(int t=0;t<s2.count;++t)
	{
		bool ind=false;
		for(int j=0;j<s1.count;++j)
			if(s2.p[t]==s1.p[j])ind=true;
        if(!ind)return false;
	}	
	return true;
}

bool operator < (const Set&s2,const Set&s1)
{
	for(int t=0;t<s2.count;++t)
	{
		bool ind=false;
		for(int j=0;j<s1.count;++j)
			if(s2.p[t]==s1.p[j])ind=true;
        if(!ind)return false;
	}
	if(s1.count==s2.count)return false;
	return true;
}

bool operator <= (const Set&s2,const Set&s1)
{
	for(int t=0;t<s2.count;++t)
	{
		bool ind=false;
		for(int j=0;j<s1.count;++j)
			if(s2.p[t]==s1.p[j])ind=true;
        if(!ind)return false;
	}	
	return true;
}


ostream& operator << (ostream &out,const Set&s)
{
	for(int t=0;t<s.count;++t)
		out<<s.p[t]<<" ";
	out<<'\n';
	return out;
}

istream& operator >> (istream &in, Set &s)
{
	try
	{
		cout<<"@.count=";
		in>>s.count;
		if(s.count<0)return in;
		delete(s.p);
		s.p=new int[s.count];
		cout<<"@.elements:\n";
		for(int t=0;t<s.count;++t)
				in>>s.p[t];
		s.sort();
	}
	catch(exception)
	{
		free(s.p);
		s.p=NULL;
		s.count=0;
	}
	return in;
}