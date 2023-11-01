#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
void main()
// Нахождение частного и остатка c+b/b-a 
{
    int ed=1;
    int  a,b,c;
    int  ndiv,nmod;
   

cout<<"input a b c";
cin >>a>>b>>c;

cout<< a<<' '<<b<<" "<<c<<endl;
_asm
{
	//  c+b/b-a 
     mov  eax,c
     add  eax,b  //  c+b
     mov  ebx,b
     sub  ebx,a  //  b-a
     JZ  m4     //a=b
     mul ed
     div ebx
     mov ndiv,eax
     mov nmod,edx
m4:
};
cout<<ndiv<<' '<<nmod<<endl;


}
