#include <iostream>
using namespace std;
extern	"C" int	_cdecl Step(int, int);

void main()
{
	setlocale(LC_ALL, "Russian");
	int a, n;
	cout << "������� �����: ";
	cin >> a;
	cout << "������� �������: ";
	cin >> n;
	int res = Step(a, n);
	cout << "���������: "<<res;
}