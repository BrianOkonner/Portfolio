
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
int Pop();
int Top();
bool isEmpty();
int resh(Node*);
};