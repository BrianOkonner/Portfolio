#include "Header.h"




void Stack228::push(char c) {
	Node *tmp1 = new Node;
	tmp1->val = c;
	tmp1->prev = first;
	first = tmp1;
}

char Stack228::pop() {
	char z;
	Node *fold = new Node;
	fold = first;
	first = first->prev;
	z = fold->val;
	delete fold;
	return z;
}

Stack228::Stack228() {
	first = NULL;
}

Stack228::~Stack228() {
	delete first;
}

char Stack228::top() {
	return first->val;
}

bool Stack228::Empty() {
	bool res = false;
	if (first == NULL)
		res = true;
	return res;
}




int isNumber(char *word) {
	int l1;
	char *tmp;
	l1 = strtol(word, &tmp, 0);
	if (*tmp == 0)
		return 1;
	double l2;
	l2 = strtod(word, &tmp);
	if (*tmp == 0)
		return -1;
	return 0;
}
