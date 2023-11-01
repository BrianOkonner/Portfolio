/*
������� ������� 8 ������

������� 2_2 2  �������  ��� �������,  � ������ � ������� �����, �� ������ - ����������.
��������� ����� �������, ������� � ��� �� ������  ���� ��������, ������� ������ ���� �� �
���� �� �������� Queue1 ��� Queue2. ��������� �������� � ���������  ����.
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
	
	//����� ��� ������ �������

	Node * temp;
	temp = head;
	while (temp->next) {
		cout << temp->next->val << ' ';
		out << temp->next->val << ' ';
		temp = temp->next;
	}
	
	//����� � ������� �������
	
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

	//=========�����===================
	cout << "������� 1 (������� �����): ";
	out << "������� 1 (������� �����): ";
	q1.print();
	cout << endl;
	out << endl;
	cout << "������� 2 (�����������): ";
	out << "������� 2 (�����������): ";
	q2.print();
	cout << endl;
	out << endl;
	cout << "������� 3 (��������� � 1 � 2): ";
	out << "������� 3 (��������� � 1 � 2): ";
	q3.print();
	cout << endl;
	cout << "*��������� � \"output.txt\"." << endl;

	system("pause");

	return 0;
}