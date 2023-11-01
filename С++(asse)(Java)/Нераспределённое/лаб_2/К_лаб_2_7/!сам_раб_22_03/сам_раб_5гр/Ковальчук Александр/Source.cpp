/*22. В файле input.txt задан набор целых чисел.

Записать их в память используя свой однонаправленный динамический список.

Просматривая список, поменять у каждой тройки второй увеличить на первый, третий на второй не измененнй

Результат записать в стандартный стек и вывести в файл Output.txt*/
#include"List.h"
#include<fstream>
#include <stack>

using namespace std;

void main() {
	ifstream in("input.txt");
	List a;
	stack<int> st;
	if(in)
		while (!in.eof()) {
			int b; in >> b; a.push_back(b);
		}
	int k = 1;
	while (a.s() >= 3 * (k++)) {
		int x1 = a.remove_head(), x2 = a.remove_head(), x3 = a.remove_head();
		x3 += x2;
		x2 += x1;
		st.push(x1); st.push(x2); st.push(x3);
		a.push_back(x1); a.push_back(x2); a.push_back(x3);
	}
	for (int i = 0; i < a.s() - 3 * (k - 2); i++) {
		int z = a.remove_head();
		a.push_back(z);
		st.push(z);
	}
	stack<int> st2;
	while (st.size()) {
		st2.push(st.top());
		st.pop();
	}
	
	ofstream out("Output.txt");
	while (st2.size()) {
		out << st2.top() << ' ';
		st2.pop();
	}
}