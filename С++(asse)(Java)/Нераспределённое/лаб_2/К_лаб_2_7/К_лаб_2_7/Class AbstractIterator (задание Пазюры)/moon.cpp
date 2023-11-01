#include "header.h"
void main()
{
	try
	{
		ArrayStack st1(5);
		st1.push(3);
		st1.push(7);
		ArrayStackIterator i(st1);
		while (i.InRange())
		{
			cout<<*i<<" ";
			++i;
		}
		i.Reset();
		AbstractStack *ab=&st1;
		ab->push(1);
		i.Reset();
		cout<<*i<<endl;
	}
		catch (const char *p)
	{
		cout<<p<<endl;
	}

	
}
