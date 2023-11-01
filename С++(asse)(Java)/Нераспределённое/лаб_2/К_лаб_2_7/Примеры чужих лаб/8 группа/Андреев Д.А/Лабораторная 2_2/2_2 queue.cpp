/*
Андреев Дмитрий 8 группа

Задание 2_2 2  Создать  две очереди,  в первой – простые числа, во второй - палиндромы.
Построить новую очередь, включив в нее по одному  разу элементы, которые входят хотя бы в
одну из очередей Queue1 или Queue2. Результат записать в текстовый  файл.
*/

#include <iostream>
#include <fstream>

using namespace std;
ofstream out;


struct Node {
	int val;
	Node* next;
};

class MyQueue {
	Node *head;
	Node *tail;
public:
	void push(int a);
	bool empty();
	void pop();
	void print();
	MyQueue();
	~MyQueue();
};

void MyQueue::push(int a) {
	tail->next = new Node;
	tail = tail->next;
	tail->val = a;
	tail->next = NULL;
}
inline bool MyQueue::empty() {
	return (head == tail) ? true : false;
}
inline void MyQueue::pop() {
	Node *temp = head;
	head = head->next;
	delete temp;
}

void MyQueue::print() {
	
	//вывод без потери очереди

	Node * temp;
	temp = head;
	while (temp->next) {
		cout << temp->next->val << ' ';
		out << temp->next->val << ' ';
		temp = temp->next;
	}
	
	//вывод с потерей очереди
	
	/*while (head->next) {

		cout << head->next->val << ' ';
		head = head->next;
	}*/
}

MyQueue::MyQueue() {
	head = new Node;
	head->next = NULL;
	tail = head;
}
MyQueue :: ~MyQueue() {
	while (!empty()) {
		pop();
	}
	delete head;
}


bool prost(int n){
	if (n == 1) return false;
	for (int d = 2; d*d <= n; d++){
		if (n%d == 0) return false;
	}
	return true;
}

int palindrom(int n){

	int s1 = n;
	int s = 0;
	while (n != 0){
		s = s * 10 + n % 10; n = n / 10;
	}
	if (s1 == s) return 1;
	return 0;
}


int main(){

	MyQueue q3, q1, q2;
	setlocale(LC_ALL, "rus");
	ifstream in;
	
	in.open("input.txt");
	out.open("output.txt");

	int a = NULL;

	while (cin.good()) {

		if (a != NULL) {
			if (prost(a)) q1.push(a);
			if (palindrom(a)) q2.push(a);
			if (prost(a) || palindrom(a)) q3.push(a);
		}
			cin >> a;
	}

	//=========вывод===================
	cout << "Очередь 1 (простых чисел): ";
	out << "Очередь 1 (простых чисел): ";
	q1.print();
	cout << endl;
	out << endl;
	cout << "Очередь 2 (палиндромов): ";
	out << "Очередь 2 (палиндромов): ";
	q2.print();
	cout << endl;
	out << endl;
	cout << "Очередь 3 (вхождений в 1 и 2): ";
	out << "Очередь 3 (вхождений в 1 и 2): ";
	q3.print();
	cout << endl;
	cout << "*Сохранено в \"output.txt\"." << endl;

	system("pause");

	return 0;
}