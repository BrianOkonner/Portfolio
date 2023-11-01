#include <stdio.h>


struct Spisok	
{
	int data;
	Spisok *p;
};

void push ( Spisok **top, int data )	
{
	Spisok *prev = new Spisok;
	prev -> data = data;
	prev -> p = *top;
	*top = prev;
}

/*Spisok* first( int data )	
{
	Spisok *prev = new Spisok;
	prev -> data = data;
	prev -> p = 0;
	return prev;
}
*/
int pop( Spisok **top )	
{
	int item = ( *top ) -> data;
	Spisok *prev = *top;
	*top = ( *top ) -> p;
	delete prev;
	return item;
}
void* peek ()
{
	if (!isEmpty ())
		return *top -> data;
	else return 0;
}