#ifndef ITERSTACKTEMPLATE_H
#define ITERSTACKTEMPLATE_H

#include <iostream>
struct Bad
{
	char str[100];
	Bad(){strcpy(str,"Error");}
	Bad(char *S){strcpy(str,S);}
};
template<class T, int ssize=100>
class StackTemplate {
  T stack[ssize];
  int top;
public:
  StackTemplate() : top(0) {}
  void push(const T& i) {
    if(!(top < ssize)) throw Bad( "Too many push()es");
    stack[top++] = i;
  }
  T pop() {
    if (!(top > 0)) throw Bad("Too many pop()s");
    return stack[--top];
  }
  class iterator; // Declaration required
  friend class iterator; // Make it a friend
  class iterator { // Now define it
    StackTemplate& s;
    int index;
  public:
    iterator(StackTemplate& st): s(st),index(0){}
    // To create the "end sentinel" iterator:
    iterator(StackTemplate& st, bool) 
      : s(st), index(s.top) {}
    T operator*() const { return s.stack[index];}
    T operator++() { // Prefix form
      if(!(index < s.top)) throw Bad(
        "iterator moved out of range");
      return s.stack[++index];
    }
    T operator++(int) { // Postfix form
      if(!(index < s.top) )
      throw Bad(  "iterator moved out of range");
      return s.stack[index++];
    }
    // Jump an iterator forward
    iterator& operator+=(int amount) {
      if (!(index + amount < s.top))
      throw Bad(  " StackTemplate::iterator::operator+=() \n tried to move out of bounds");
      index += amount;
      return *this;
    }
    // To see if you're at the end:
    bool operator==(const iterator& rv) const {
      return index == rv.index;
    }
    bool operator!=(const iterator& rv) const {
      return index != rv.index;
    }
    friend std::ostream& operator<<(
      std::ostream& os, const iterator& it) {
      return os << *it;
    }
  };
  iterator begin() { return iterator(*this); }
  // Create the "end sentinel":
  iterator end() { return iterator(*this, true);}
};
#endif // ITERSTACKTEMPLATE_H ///:~