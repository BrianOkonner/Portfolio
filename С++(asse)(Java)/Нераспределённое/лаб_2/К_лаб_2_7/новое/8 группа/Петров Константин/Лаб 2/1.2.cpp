/*	������ ����������
8 ������

1.2 ������� ���������, ������� ������������ ���������� ��������� �����, � ������� ���������� ������

��������

��������� ���� ���������� �������. ���� � ����� ������ ��� �����, ��������� ���������. ���� � ����� ������ 3 �����, ���������� 1 � 3,
������� ���������. ���� � ����� ������ ���� �����, ����� ������ ��� �����, ���������� ������� � ������� ��������, ����� ������ ����������
������, ������ ������, � ������ ������� �� �����. ���������, ���� ���� �� ����. ��� ������ ���� ����, ����������
������� �������������� ��������. ������� ���������.

�����
1 2 3 4 5 -1     // 0
2 2 2 2 2 -1     // 3
2 1 2 1 3 -1     // 2
*/

#include <iostream>
using namespace std;

struct Node {
	double val;
	Node *prev;
};

class MyDoubleStack {
	Node *first;
public:
	void StackPush(double a);
	double StackPop();
	bool IsEmpty();
	MyDoubleStack();
	~MyDoubleStack();

};

void MyDoubleStack :: StackPush(double a) {
	Node *temp = new Node;
	temp->val = a;
	temp->prev = first;
	first = temp;
}
double MyDoubleStack :: StackPop() {
	Node *temp = new Node;
	temp = first;
	first = first->prev;
	double z = temp->val;
	delete temp;
	return z;
}
inline bool MyDoubleStack :: IsEmpty() {
	return (first == NULL) ? true : false;
}
inline MyDoubleStack :: MyDoubleStack() {
	first = NULL;
}
inline MyDoubleStack :: ~MyDoubleStack() {
	delete first;
}

int main() {
	MyDoubleStack Stack;

	setlocale(LC_ALL, "rus");
	cout << "������� �������� �����(-1 - �����)" << endl;
	double c = 0;
	int i = 0;   //������� ���������� ��������� �����
	do {
		cin >> c;
		if (c != -1) { Stack.StackPush(c); ++i; }
	} while (c != -1);

	if (i <= 2) {
		cout << "��������� � ����������� �������� ���" << endl;
		exit(0);
	}
//-----------------------------------------------------------------------------
	int num = 0;
	double a1, a2, a3;
	// ������� ������ ��� ��������
	a1 = Stack.StackPop();
	a2 = Stack.StackPop();
	a3 = Stack.StackPop();
	if (Stack.IsEmpty() == true) {  //���� ��������� ������ 3
		if (a3 == a1) {
			cout << "���������� ��������� ����� � ����������� �������� ����� - 1" << endl;
			exit(0);
		}
		else {
			cout << "���������� ��������� ����� � ����������� �������� ����� - 0" << endl;
			exit(0);
		}
	}
	do {   // ���� ��������� >3
		if (a1 == a3) ++num;
		a1 = a2;
		a2 = a3;
		a3 = Stack.StackPop();
	} while (Stack.IsEmpty() == false);

	if (a1 == a3) ++num; //�������� ������� �������������� ������� �����

	cout << "���������� ��������� ����� � ����������� �������� ����� - " << num << endl;
//-----------------------------------------------------------------------------
	return 0;
}
