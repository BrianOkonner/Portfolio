#include "gstring.h"
void main()
{
	GString  A,B;
	A="asdfg";
	B=A+A;
	cout<<A<<"    "<<B<<"    "<<B+"000"<<"    "<<(A<B);
	cin>>A;
	cout<<A;
}