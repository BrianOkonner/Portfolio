#include "iostream"
#include "List.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int len = 6;
	List i,o;
	if(i.isEmpty())
			i.ins(9);
	i.ins(8);
	if(i.isEmpty())
	i.ins(1);
	while(!i.isEmpty())
		cout<<i.del()<<"  ";
	return 0;
}