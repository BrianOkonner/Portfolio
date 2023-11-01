class List
{
	class item
	{
	public:
		int number;
		item *next;
		item *prev;
		item(int, item *, item *);
		~item();
	}*head, *tail;
public:
	List();
	~List();
	bool empty();
	void push_back(int);
	void pop_front();
	int front();
};
