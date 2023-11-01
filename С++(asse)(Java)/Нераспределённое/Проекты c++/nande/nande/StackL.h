#ifndef STACK100
#define STACK100
class StackL
{
	struct Link
	{
		void *data;
		Link *next;
		Link(void *dat,Link *nxt);
		~Link();
	}*head;
public:
	StackL(void);
	~StackL();
	void push(void *dat);
	void *pop();
	void *peek();
};
#endif