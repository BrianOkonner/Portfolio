struct list
{
	int number;
	list *next;
};

extern list *start;

void create_cycled_list(int N);
void show_list_n(int n);
void delete_from_list();
int iosif_task(int N, int M);