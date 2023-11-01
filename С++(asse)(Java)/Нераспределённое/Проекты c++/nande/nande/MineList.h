class Mlist
{
	struct Link
	{
		void *data;
		Link *next;
		Link *prev;
	public:
		Link(void *dat,Link *nxt);
		Link(Link *prv,void *dat);
	}*head,*tail;
public:
	Mlist();
	~Mlist(void);
	void *pop_back();
	void *pop_front();
	void push_back(void *dat);
	void push_front(void *dat);
	void *front();
	void *back();
	int size();
	bool empty();
};