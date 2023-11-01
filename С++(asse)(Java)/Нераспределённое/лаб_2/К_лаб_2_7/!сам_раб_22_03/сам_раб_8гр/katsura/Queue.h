
#include <iostream>

using namespace std;

class Queue
{
public:
	struct node
	{
		int n;
		node *next, *prev;

		node (int _n)
		{
			n = _n;
			next = NULL;
			prev = NULL;
		}
	};

private:

	node *head, *tail;
	int count;

public:
	Queue();

	int Count ();

	void Add(int n);

	node* Get (int ind);

	void Insert (int ind, int val);
};
