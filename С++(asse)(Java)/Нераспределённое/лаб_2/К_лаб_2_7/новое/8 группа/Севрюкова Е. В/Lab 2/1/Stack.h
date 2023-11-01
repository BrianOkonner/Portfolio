class Stack
{
	struct Link
	{
		char data;
		Link* next;
		Link(char dat, Link*nxt);
		~Link();
	} *head;
public:
	Stack();
	~Stack();
	void Push(char dat);
	char Peek();
	bool isEmpty();
	void Pop();
};

class StackInt
{
	struct Link
	{
		int data;
		Link* next;
		Link(int dat, Link*nxt);
		~Link();
	} *head;
public:
	StackInt();
	~StackInt();
	void Push(int dat);
	int Peek();
	bool isEmpty();
	void Pop();
};