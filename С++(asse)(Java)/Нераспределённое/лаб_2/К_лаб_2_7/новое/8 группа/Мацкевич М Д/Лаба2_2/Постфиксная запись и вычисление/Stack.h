
class Stack
{
struct Node 
{
	 char  value;
    Node* prev;
};
Node* head;
public:
Stack();
~Stack();
void Push(int);
char Pop();
char Top();
bool isEmpty();
int resh(Node*);
};