/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: Дано натуральное n.Подсчитать  количество  решений неравенства  x*x + y*y < n в натуральных (неотрицательных целых) числах
не используя действий с вещественными числами.

Сначала рассматриваем все у, такие что х*х+у*у<n при х=0, затем при х=1 и т.д.

Условие     Вывод
10          11
50          45
123456      97307

*/

#include <iostream>
using namespace std;

int main()
{
	int n, t = 0, t_x = 0, t_y = 0, x = 0, y = 0, c = 0;
	setlocale(LC_ALL, ".1251");
	cout << "insert n" << endl;
	cin >> n;
	_asm
	{
	begin1:	mov esi,t_x
			mov edi,n
			cmp esi,edi		// аналог while (t_x<n)
			jns end2			//
			mov y,0
			mov esi,t_x
			mov t,esi
	begin2:	mov esi,t
			mov edi,n
			cmp esi,edi	
			jns end1
			inc c
			inc y
			mov eax,y
			mov edx,0
			imul y
			mov t_y,eax
			add eax,t_x
			mov t,eax
			loop begin2
	end1:	inc x
			mov eax,x
			mov edx,0
			imul x
			mov t_x,eax
			loop begin1
	end2:
	}

	cout << c << endl;
	return 0;
}
