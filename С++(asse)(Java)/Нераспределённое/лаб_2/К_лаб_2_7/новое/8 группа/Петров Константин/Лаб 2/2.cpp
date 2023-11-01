/* Петров Константин
8 группа



2.		Задан текстовый файл Input.txt, в котором есть некоторые числа,
каждое число в отдельной строке. Создать  две очереди,  в первой – простые числа,
во второй _ палиндромы. Построить новую очередь, включив в нее по одному  разу
элементы, которые входят хотя бы в одну из очередей Queue1 или Queue2. Результат
записать в текстовый  файл.

Тесты
Inp  1 2 6 0 3 5 7 7 9 11 13 15 11 17 22 22 88
Outp 1 3 5 7 11 13 17 2 6 0 9 22 88

*/

#include <fstream>
#include <iostream>
using namespace std;

bool IsPrime(int a);
bool IsPalind(int a);
bool IsAdded(int a);

struct Node {
	int val;
	Node* next;

};

class MyQueue {
	Node *first;
	Node *last;
	int size;
public:
	void AddQueue(int a);
	bool IsEmpty();
	void Delete();
	int ShowTop();
	int showSize();
	MyQueue();
	~MyQueue();
};

void MyQueue::AddQueue(int a) {
	last->next = new Node;
	last = last->next;
	last->val = a;
	last->next = NULL;
	size++;
}
inline bool MyQueue::IsEmpty() {
	return (first == last) ? true : false;
}
inline void MyQueue::Delete() {
	Node *temp = first;
	first = first->next;
	size--;
	delete temp;
}
inline int MyQueue::ShowTop() {
	return first->next->val;
}
inline int MyQueue::showSize() {
	return size;
}
MyQueue::MyQueue() {
	first = new Node;
	first->next = NULL;
	last = first;
	size = 0;
}
MyQueue :: ~MyQueue() {
	while (!IsEmpty()) {
		Delete();
	}
	delete first;
}

MyQueue Prime, Palind, Result;

int main() {


	ifstream fin("Input.txt");
	int c;
	while (!fin.eof()) {
		fin >> c;
		if (IsPrime(c) == true) Prime.AddQueue(c);
		if (IsPalind(c) == true) Palind.AddQueue(c);
	}
	fin.close();
	//---------------------------------------------------------------

	while (!Prime.IsEmpty()) {
		int c = Prime.ShowTop();
		Prime.Delete();
		if (!IsAdded(c)) Result.AddQueue(c);
	}
	while (!Palind.IsEmpty()) {
		int c = Palind.ShowTop();
		Palind.Delete();
		if (!IsAdded(c)) Result.AddQueue(c);
	}

	ofstream fout("Output.txt");

	while (!Result.IsEmpty()) {
		int c = Result.ShowTop();
		Result.Delete();
		fout << c << " ";
	}


	fout.close();
	return 0;
}
// 1 3 11 2 22 77 66 
bool IsPrime(int a) {  //Функция проверки числа на простоту
	if (a <= 0 || a == 2) return false;
	bool res = true;
	for (int i = 2; i < a; i++)
		if (a % i == 0) {
			res = false;
			break;
		}
	return res;
}
bool IsPalind(int a) {
	if (a == 0)
		return true;
	if (a < 0) a *= (-1);
	bool res = true;
	int rev = 0, a1 = a;
	while (a1) {
		rev = rev * 10 + a1 % 10;
		a1 /= 10;
	}

	if (rev != a) res = false;
	return res;
}
bool IsAdded(int a) {
	bool res = false;
	for (int i = 0; i < Result.showSize(); i++) {
		int q = Result.ShowTop();
		Result.Delete();
		if (q == a) res = true;
		Result.AddQueue(q);
	}
	return res;
}