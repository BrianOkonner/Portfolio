//вар 7
// Козловский
#include <iostream>
#include "Header.h"
#include <list>
#include <fstream>
using namespace std;

void main() {
	ifstream a("input.txt");
	if (!a.is_open()) {
		throw "Can't open file.";
	}
	Queue b(100);
	while (!a.eof()) {
		int c;
		a >> c;
		b.push(c);
	}
	list<int> e;
	while (!b.is_empty()) {
		int c = b.pop();
		if ((c & 1)&&(!e.empty())) {
			int d = e.back();
			if (d & 1) {
				e.pop_back();
				e.push_back(c);
				e.push_back(d);
			}
			else {
				e.push_back(c);
			}

		}
		else {
			e.push_back(c);
		}
	}
	a.close();
	ofstream z("Output.txt");
	while (!e.empty()) {
		z << e.front() << " ";
		e.pop_front();
	}
	system("pause");
}