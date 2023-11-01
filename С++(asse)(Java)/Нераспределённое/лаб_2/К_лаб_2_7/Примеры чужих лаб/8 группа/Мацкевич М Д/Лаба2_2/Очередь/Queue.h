
#include <iostream>
#include <fstream>
using namespace std;
class Queue
{
struct Node 
{
	 int  value;
    Node* next;
};
Node* head;
Node *tail;
public:
Queue();
~Queue();
void Push(int);
char Pop();
char Front();
char Back();
bool isEmpty();
int resh(Node*);
bool Find(int );
void Print(ostream  & out);
};