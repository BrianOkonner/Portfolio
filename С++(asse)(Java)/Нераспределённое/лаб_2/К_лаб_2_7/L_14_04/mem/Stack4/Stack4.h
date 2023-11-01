//: C06:Stack4.h
// —тек с конструктором и деструктором
#ifndef STACK4_H
#define STACK4_H
#include <iosfwd>
#include <iostream>
using std::ostream;
using std::istream;

class Stack {
  struct Link {
    int data;
    Link* next;
    Link(int dat, Link* nxt);
    ~Link();
  }* head;
  void copy(Stack&);
public:
  Stack();
  Stack(Stack&);
  ~Stack();
  Stack& operator=(Stack&);
  friend ostream& operator<<(ostream&,Stack&);
  friend istream& operator>>(istream&,Stack&);
  void push(int dat);
  int peek();
  int pop();
};
#endif // STACK4_H ///:~