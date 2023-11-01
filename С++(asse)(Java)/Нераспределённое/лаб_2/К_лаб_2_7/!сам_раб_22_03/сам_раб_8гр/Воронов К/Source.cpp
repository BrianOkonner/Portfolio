#include<iostream>
#include<fstream>
#include"Stack.h"
#include<queue>

using namespace std;
void main() {
	int z;
	queue <int> B;
	Stack A;
	ifstream in("Input.txt");
	ofstream out("Output.txt");
	int a;
	while (!in.eof()) {
		in >> a;
		A.Push(a);
	}
	A.del(A.Min());
	A.del(A.Max());
	while (!A.IsEmpaty()) {
		z=A.Top();
		A.Pop();
		B.push(z);
		out << z << ' ';

	}

	system("pause");
}