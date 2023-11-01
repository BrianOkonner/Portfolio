//: C16:TStack.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// The Stack as a template
#ifndef TSTACK_H
#define TSTACK_H
#include <iostream>
using namespace std;

template<class T>
class Stack {
  struct Link {
    T* data;
    Link* next;
    Link(T* dat,Link* nxt): data(dat), next(nxt) {}
  }* head;
public:
  Stack() : head(0) {}
  ~Stack();
  void push(T* dat) {
    head = new Link(dat,head); //, head);
  }
  T* peek() const;
  T* pop(){
    if(head == 0) return 0;
    T* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
  }
	friend std::ostream& operator<<(std::ostream& out, const Stack& s)
	{
		Link* temp=s.head;
		while(temp)
		{	out<<*(temp->data)<<endl;
			temp=temp->next;
		}	
		return out;
	}
};

template<class T>
T* Stack<T>::peek() const {
    return head ? head->data : 0; 
  }
template<class T>
Stack<T>::~Stack(){ 
    while(head)
      delete pop();
  }
#endif // TSTACK_H ///:~
