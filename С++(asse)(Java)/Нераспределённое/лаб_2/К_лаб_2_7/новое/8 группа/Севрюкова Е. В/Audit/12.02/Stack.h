class Stack
{
	struct Link
	{
		void* data;
		Link* next;
		Link(void*dat, Link*nxt);
		~Link();
	} *head;
public:
	Stack();
	~Stack();
	void Push(void*dat);
	void* Peek();
	bool isEmpty();
	void Pop();
};

