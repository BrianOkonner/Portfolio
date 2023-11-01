#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
class List
{
struct node						
{
	int  _item;					
	node*  next;				
	node*  prev;				
};struct node *head, *tail;
public:
	List();			
	~List();
	void del_nech();
	void insÍead(int n);	
	void insTail(int n);	
	int delHead();	      
	bool isEmpty();		
};
bool nechet(int x);