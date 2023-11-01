/*

Калач Михаил, группа 8.

22. В файле input.txt задан набор целых чисел.
Записать их в память используя свой однонаправленный динамический список.
Просматривая список, поменять у каждой тройки второй увеличить на первый, третий на второй не измененный
Результат записать в стандартный стек и вывести в файл Output.txt

*/

#include <fstream>
#include <stack>
#include "List.h"

using namespace std;

int main()
{
	ifstream Fin("Input.txt");
	ofstream Fout("Output.txt");
	List A;
	while(Fin)
	{
		int x; 
		Fin >> x; 
		A.push_back(x);
	}
	int k = 1, n = A.size();
	while (A.size() >= 3 * k++) 
	{
		int x1 = A.remove_head(), 
			x2 = A.remove_head(), 
			x3 = A.remove_head();
		x3 += x2;
		x2 += x1;
		A.push_back(x1);
		A.push_back(x2);
		A.push_back(x3);
	}
	while (A.size() >= n)
	{
		A.remove_tail();
	}
	for (int i = 0; i < A.size() - 3 * (k - 2); i++)
	{
		A.push_back(A.remove_head());
	}
	stack <int> St, F;
	while (A.size())
	{
		St.push(A.remove_head());
		Fout << St.top() << " ";
	}
	while (St.size())
	{
		F.push(St.top());
		St.pop();
	}
	return 0;
}