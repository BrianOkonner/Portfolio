#include "iostream";
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	char b[] = "������",a[]="� ���� ���";
	int len = 6;
	_asm
	{
		mov ecx, 6
		inc len
			lea esi, b
			lea edi, a
			movsb // ���������� �� esi � edi � ����������� esi � edi �� 1(�.�. movsB)
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
