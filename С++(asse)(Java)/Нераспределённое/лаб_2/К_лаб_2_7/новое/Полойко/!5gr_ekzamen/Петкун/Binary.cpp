#include <iostream>
using namespace std;
int count_bits(int num)
{
	int k,s;
	cin>>k;
	_asm
	{
		mov ecx,32
		mov s,0
		xor eax,eax
loop1:	shr k,1
		jnc else_
		inc s
else_:	loop loop1
	}
	cout<<s<<endl;
}