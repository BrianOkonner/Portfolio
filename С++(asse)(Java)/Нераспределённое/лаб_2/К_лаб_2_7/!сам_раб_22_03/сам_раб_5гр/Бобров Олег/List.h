#pragma once
#include <iostream>
#include <list>

using namespace std;

class LIST
{
	struct item
	{
		int n;
		item *next, *prev;
	};
	item *head, *tail;
public:
	LIST();
	LIST(LIST&);
	~LIST();

	void push_head(int);
	void push_back(int);
	int remove_head();
	int remove_tail();
	void print(ostream&);
	void change();
	void copy_to_list(list<int> &);
};