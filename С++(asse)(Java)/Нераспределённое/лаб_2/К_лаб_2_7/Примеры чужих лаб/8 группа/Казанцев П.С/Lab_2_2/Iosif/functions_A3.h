class MyList
{
	struct Note
	{
		int number;
		Note *next;
	} *head;
public:
	MyList(int N);
	void show_list_n(int n);
	void delete_from_list();
	int iosif_task(int N, int M);
};