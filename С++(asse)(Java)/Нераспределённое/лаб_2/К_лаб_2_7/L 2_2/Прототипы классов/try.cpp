#include "iostream";
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	char b[] = "Кердык",a[]="а черт его";
	int len = 6;
	_asm
	{
		mov ecx, 6
		inc len
			lea esi, b
			lea edi, a
			movsb // перемещает из esi в edi и увеличивает esi И edi на 1(т.к. movsB)
			movsb
			movsb
			movsb
			movsb
			movsb
			movsb
	}
	cout << a;
	return 0;
}
