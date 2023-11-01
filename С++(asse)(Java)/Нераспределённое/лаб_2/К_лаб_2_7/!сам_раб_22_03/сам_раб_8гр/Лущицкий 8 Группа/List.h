class List
{
private:
	struct node
	{
		int n;
		node* next;

		node (int _n)
		{
			n = _n;
			next = NULL;
		}
	};

	node *head, *tail;
	int count;

public:
	List()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	int Count ()
	{
		return count;
	}

	void Add(int n)
	{
		node* temp = new node(n);
		if (tail == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		count++;
	}

	node* GetNode (int ind)
	{
		if (ind >= count)
			throw "Index out of range.";
		node* cur = head;
		for (int i = 0; i < ind; i++)
		{
			cur = cur->next;
		}
		return cur;
	}
};