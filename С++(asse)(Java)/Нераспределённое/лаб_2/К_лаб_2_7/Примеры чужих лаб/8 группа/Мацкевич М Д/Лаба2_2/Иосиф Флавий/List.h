
#include <iostream>
#include <fstream>
using namespace std;
class List
{
struct Node 
{
	 int  value;
    Node* next, * prev;
};
Node * head;
Node *tail;
public:
List();
~List();
void Push_front(int);
void Push_back(int);
int Pop_front();
int Pop_back();
int Front();
int Back();
bool isEmpty();
//int resh(Node*);
//bool Find(int );
//void Print(ostream  & out);
};