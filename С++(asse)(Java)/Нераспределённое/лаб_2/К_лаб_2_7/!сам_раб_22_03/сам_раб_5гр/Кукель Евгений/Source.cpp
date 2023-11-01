#include "List.h"
#include <iostream>
#include <cctype>
using namespace std;
List::List() {
	head = NULL;
}
List::List(const List& a) {
	head = new node();
	node* headt = head;
	node* temp = a.head;
	while (temp != NULL) {
		headt->item = temp->item;
		headt->p = new node();
		headt = headt->p;
		temp = temp->p;
	}
	delete headt;
}
List::~List() {
	while (head != NULL) {
		node* temp = head;
		head = head->p;
		delete temp;
	}
}
void List::ins(const int& a) {
	node* b = new node();
	b->item = a;
	b->p = head;
	head = b;
}
int List::del() {
	if (isEmpty()) throw "Empty list.";
	node* a = head;
	head = head->p;
	int b = a->item;
	delete a;
	return b;
}


