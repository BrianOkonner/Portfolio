//: C06:Stack3.cpp {O}
// Конструкторы и деструкторы
#include "Stack4.h"
#include "../require.h"
#include <iostream>
using namespace std;

Stack::Link::Link(int dat, Link* nxt) {
  data = dat;
  next = nxt;
}

Stack::Link::~Link() { }

Stack::Stack() { head = 0; }

void Stack::push(int dat) {
  head = new Link(dat,head);
}

int Stack::peek() { 
  require(head != 0, "Stack empty");
  return head->data; 
}

int Stack::pop() {
  if(head == 0) return 0;
  int result = head->data;
  Link* oldHead = head;
  head = head->next;
  delete oldHead;
  return result;
}

Stack::~Stack() {
	
   while (head)
		int x=pop();
} ///:~

void Stack::copy(Stack& r) {
	Stack temp;
    while(r.head)
	{
		temp.push(r.pop());
	}
	head=0;
    while(temp.head)
	{
      int x=temp.pop();
	  r.push(x);
	  push(x);
	}
}
Stack::Stack(Stack& r) {
	copy(r);
}

Stack& Stack::operator=(Stack& r)
{
	if (this != &r) 
	{
	   while (head)
		int x=pop();
	copy(r);
	}
	return *this;
}
  ostream& operator<<(ostream& out,Stack&r)
  {
	  Stack temp(r);
	   while (temp.head)
		out<<temp.pop()<<" ";
	   out<<endl;
	   return out;
  }
  istream& operator>>(istream& in,Stack& r)
  {		int count,x;
	  in>>count;
	  while (r.head)
		 x=r.pop();
	  for(int i=0;i<count;i++)
	  {
		  in>>x;
		  r.push(x);
	  }
	  return in;
  }

