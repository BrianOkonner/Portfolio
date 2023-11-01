//Класс стек-итератор
#include <iostream>
using namespace std;

class IntStack
{
	enum {ssize=100};
	int stack[ssize];
	int top;
public:
IntStack():top(0){};
	void push(int i)
	{
		if (top>=ssize) exit(1); 
    	stack[top++]=i;
	}
	int pop()
	{
		if (top==0) exit(1);
		return stack[--top];
	}
	class iterator;
	friend class iterator;
	class iterator
	{
		IntStack &s;
		int index;
	public:
		iterator(IntStack &is):s(is),index(0){}
		iterator(IntStack&is,bool):s(is),index(s.top){}
		int operator ++()
		{
			if (index>=s.top) exit(3);
			return s.stack[++index];
		}
		int operator++(int)
		{
			if (index>=s.top) exit(3);
			return s.stack[index++];
		}
		int operator --()
		{
			if (index<=0) exit(3);
			return s.stack[--index];
		}
		int operator--(int)
		{
			if (index<=0) exit(3);
			return s.stack[index--];
		}
		bool operator == (const iterator& it2)
		{ return (this->index == it2.index);}
		
		bool operator != (const iterator& it2)
		{ return (this->index != it2.index);}
		
		int current()const
              		  {                 return s.stack[index];    }
		
		friend ostream& operator << (ostream& os, const iterator& it)
		{
			os<<it.current()<<" ";
			return os;
		}
                               };
		iterator begin()
{return iterator(*this);}
		iterator end()
{return iterator(*this,true);}

};
int main()
{
	IntStack is;
	for(int i=0;i<10;i++) is.push(i);
	IntStack::iterator start = is.begin(),
	end = is.end();
	while(start!=end)
		cout<<--end;
	return 0;
}
