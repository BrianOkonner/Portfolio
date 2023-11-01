struct node          //структура элемента очереди
{
	node *next,*prev;
	int number;
};
struct queue
{
	node *head,*tail;
};
void push(queue *a,int n);
int pop(queue*a);
int nod(int a,int b);
void prov(int **matr,int q,int a);
int NOD(int a,int b);
int comp(const void *x,const void *y);
extern "C" int _cdecl vsprost(int,int );
//int vsprost(int x,int y);
//int Node(int x,int y,int z);
//int nod (int x,int y);
