#ifndef QUEUE10
#define QUEUE10
class Mqueue
{
	void *data;
	Mqueue *next;
public:
	Mqueue();
	Mqueue(void *dat,Mqueue *nxt);
	Mqueue(Mqueue *nxt);
	~Mqueue(void);
	void *pop();
	void push(void *dat);
	void *front();
	void *back();
	int size();
	bool empty();
};
#endif