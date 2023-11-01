//Serenkov Boris; 5 gruppa; Zadacha 6;
#include "Header.h"

void main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	Queue a;
	int b;
	while (!fin.eof()) {
		fin >> b;
		a.push(b);
	}
	int k = a.size();
	for (int i = 0; i < k; i++) {
		if (a.front() > 9 || a.front() < -9)
			a.pop();
		else {
			a.push(a.front());
			a.pop();
		}
	}
	stack <int> r;
	k = a.size();
	for (int i = 0; i < k; i++) {
		r.push(a.front());
		fout << a.front() << ' ';
		a.pop();
	}
}