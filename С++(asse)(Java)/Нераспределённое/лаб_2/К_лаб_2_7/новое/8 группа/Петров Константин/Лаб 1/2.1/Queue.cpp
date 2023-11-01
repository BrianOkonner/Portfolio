/*	Петров Кнстантин 
		8 группа
	
	Задача про очередь
	!!!Входные числа в файле должны быть записаны в стобик
*/

#include <fstream>
#include <queue>
#include <iostream>
using namespace std;
bool IsPrime(int a);
bool IsPalind(int a);
bool IsAdded(int c);

queue <int> Prime, Palind, Result;

int main() {
	setlocale(LC_ALL, "rus");
//----------------------------------------------------
	ifstream fin("Input.txt");
	while (!fin.eof()) {
		int c;
		fin >> c;
		if (IsPrime(c))		
		    Prime.push(c);
		if (IsPalind(c))
		    Palind.push(c);
	}
	fin.close();
//----------------------------------------------------
	int z = Prime.size();
	while (z) {
		int c = Prime.front();
		Prime.pop();
		if (!IsAdded(c)) Result.push(c);
		z--;
	}
	
	z = Palind.size();
	while (z) {
		int c = Palind.front();
		Palind.pop();
		if (!IsAdded(c)) Result.push(c);
		z--;
	}
//----------------------------------------------------
	ofstream fout("Output.txt");

	z = Result.size();
	while (z) {
		int c = Result.front();
		Result.pop();
		cout << c << endl;
		fout << c << endl;
		z--;
	}

	fout.close();

	return 0;
}

bool IsPrime(int a) {
	if (a <= 0 || a == 1) return false;
	bool flag = true;
	for (int i = 2; i < a; i++) 
		if (a % i == 0) {
			flag = false;
			break;
		}
	return flag;
}

bool IsPalind(int a) {
	int a1 = a;
	int Result = 0;
	while (a) {
		Result = Result * 10 + a % 10;
		a /= 10;
	}
	return (a1 == Result);
}
bool IsAdded(int c) {
	int q = Result.size();
	bool flag = false;
	while (q) {
		int val = Result.front();
		Result.pop();
		Result.push(val);
		if (val == c)
			flag = true;
		q--;
	}
	return flag;
}