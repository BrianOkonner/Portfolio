#ifndef STACK10
#define STACK10
class Mstack
{
	void *data;
	Mstack *next;
public:
	Mstack();
	Mstack(void *dat,Mstack *nxt);
	~Mstack(void);
	void *pop();
	void push(void *dat);
	void *top();
	int size();
	bool empty();
};
#endif

