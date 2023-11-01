class MyDeque 
{
	int *Deque;
	int head, tail;

public:
	MyDeque();
	MyDeque(int SIZE);

	void printDeque();

	void push_back(int num);

	void pop_front();

	void push_front(int num);

	void pop_back();

	int size();

	int front();

	int back();

	bool isEmpty();

	~MyDeque();
};