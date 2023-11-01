#include <iostream>
#include "(int)Stack.h"
using namespace std;

Stack::Stack(void){}
Stack::~Stack() {
	while (head) pop();
};
void Stack::push(int dat) {
	link *tmp = new link;
	tmp->data = dat;
	tmp->next = head;
	head = tmp;
}
int Stack::pop() {
	if (head) {
		int res = head->data;
		link*old = head;
		head = head->next;
		delete old;
		return res;
	}
	else return 0;
}
int Stack::peek() {
	if (head) {
		return head->data;
	}
	else {
		cout << "Empty." << endl;
		return 0;
	}
}
bool Stack::empty() {
	if (head) return false;
	else return true;
}