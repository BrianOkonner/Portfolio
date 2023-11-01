class Queue
{
	class item
	{
	public:
		int number;
		item *next;
		item(int, item *);
		~item();
	}*head, *tail;
public:
	Queue();
	~Queue();
	bool isEmpty();
	void push(int);
	void pop();
	int front();
};
