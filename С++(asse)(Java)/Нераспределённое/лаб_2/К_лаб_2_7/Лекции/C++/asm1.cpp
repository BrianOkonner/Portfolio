#include <iostream>
using namespace std;
int main()
{
	signed char a;
	short b;
	int c;
	cout<<sizeof(a)<< sizeof(b)<< sizeof(c)<< endl;
	//cin>>a>>b;
   a=-127;
   b=-32768;
   c=a*b;
	cout<<(short)a<<"*"<<b<<"="<<c<<endl;
	c=0;
   _asm
   {
     mov al,a
     cbw
     imul b
     mov word ptr c,ax
     mov word ptr c+2,dx
   }
	cout<<(short)a<<"*"<<b<<"="<<c<<endl;
	c=0;

   _asm
   {
     mov ax,b
     cwde
     mov ebx,eax
     mov al,a
     cbw
     cwde
     imul eax,ebx
     mov c,eax
   }

	cout<<(short)a<<"*"<<b<<"="<<c<<endl;
	return 0;
}