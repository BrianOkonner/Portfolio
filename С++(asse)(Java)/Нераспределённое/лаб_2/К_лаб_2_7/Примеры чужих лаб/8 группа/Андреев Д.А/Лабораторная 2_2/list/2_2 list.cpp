/*
������� ������� 8 ������

������� 2_2 3 3.1	������ ������. ������ ���������� ����� N �������, �� ������� ������� ������,
�  ���������  ������������  ��  ������� ������� ������� �� 2 �� N. ���������,  ������� � ����-��, ����� 
���� �� M. �������, �� ������� ����������� ����, ������� �� �����. ���� ������������ �� ���������� ��������
� ��� �� ��� ���, ���� �� ��������� ���� �������.  ���������� ����� ����������� ��������, ���� �������� M
� ��, ��� ���� ��������� � ������� ��������. ��������� �������� � ���������  ����.
*/

#include<iostream>
#include<fstream>
using namespace std;

struct Item {
	Item *next;
	Item *prev;
	int num;
};

class List {
	Item *head;
	Item *tail;
public:
	void push_front(int n);
	void push_back(int n);
	int pop_front();
	int pop_back();
	bool empty();


	List() {
		head = 0;
		tail = 0;
	}


	~List() {
		while (head != 0){
			Item* tmp = head;
			head = head->next;
			delete tmp;
		}
		head = 0;
		tail = 0;
	}
};

void List::push_front(int n) {

	Item* tmp = new Item;
	tmp->num = n;
	tmp->prev = 0;
	tmp->next = head;
	if (head)
		head->prev = tmp;
	else
		tail = tmp;
	head = tmp;
}

void List::push_back(int n) {

	Item* tmp = new Item;
	tmp->num = n;
	tmp->next = 0;
	tmp->prev = tail;
	if (tail)
		tail->next = tmp;
	else
		head = tmp;
	tail = tmp;
}

int List::pop_front() {

	if (head) {
		int res = head->num;
		Item *tmp = head;
		if (head->next)
			head->next->prev = 0;
		else
			tail = 0;
		head = head->next;
		delete tmp;
		return res;
	}
	return 0;
}

int List::pop_back() {
	if (tail) {
		int res = tail->num;
		Item *tmp = tail;
		if (tail->prev)
			tail->prev->next = 0;
		else
			head = 0;
		tail = tail->prev;
		delete tmp;
		return res;
	}
	return 0;
}

bool List::empty() {
	return head == 0;
}

void main() {

	setlocale(0, "rus");

	ofstream out;
	out.open("output.txt");

	int n, m, i, j, el;

	cout << "K���������: ";
	cin >> n;
	out << "K���������: " << n << endl;
	cout << "���: ";
	cin >> m;
	out << "���: " << m << endl;

	if (m == 1) {	//����� ��������� ��� m=1;
		cout << "��������� ������� " << n << endl;
		out << "��������� ������� " << n;
	}

	else {

		List lists;
		for (i = 1; i <= n; i++) lists.push_front(i);


		for (i = 1; i < n; i++) {

			for (j = 1; j < m; j++) {
				el = lists.pop_back();
				lists.push_front(el);
			}
			lists.pop_back();
		}
		el = lists.pop_front();
			cout << "��������� ����� " << el << endl << "*��������� � output.txt" << endl;
		out << "��������� ����� " << el;
	}
	out.close();
	system("pause");
}