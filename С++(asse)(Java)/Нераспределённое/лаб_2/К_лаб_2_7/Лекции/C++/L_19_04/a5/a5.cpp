#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
// поиск мах и min  
void maxmin(int a,int b, int & imax, int & imin)
{
	// результирующие параметры - по ссылке
_asm
{
	mov esi,imax
	mov edi,imin
	mov eax,a
	mov edx,eax
	cmp eax,b
	cmovl edx,b
	cmovg eax,b
	mov [esi],edx
	mov [edi],eax
}
}
void maxmin2(int a,int b, int* imax, int* imin)
{
	// результирующие параметры - по указателю
	// ассемблерный код ничем не отличается!

_asm
{
	mov esi,imax
	mov edi,imin
	mov eax,a
	mov edx,eax
	cmp eax,b
	cmovl edx,b
	cmovg eax,b
	mov [esi],edx
	mov [edi],eax
}
}
int main()
{
	srand(time(0));
	int x,y,max,min;
	cout<<" Two integer? ";
	cin>>x>>y;
	maxmin(x,y,max,min);
	cout<<"MAX = "<<max<<endl;
	cout<<"MIN = "<<min<<endl;
	maxmin2(x,y,&max,&min);
	cout<<"MAX2 = "<<max<<endl;
	cout<<"MIN2 = "<<min<<endl;

}