struct Spisok	
{
	int data;
	Spisok *p;
};
void push ( Spisok **top, int data );
int pop( Spisok **top );