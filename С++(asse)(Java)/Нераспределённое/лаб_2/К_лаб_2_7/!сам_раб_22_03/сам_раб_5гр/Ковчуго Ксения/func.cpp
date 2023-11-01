#include "Header.h"

void MyStack::push(int data) {
	Node *tmp = new Node;
	tmp->Num = data;
	if (Size == 0) {
		tmp->Prev = NULL;
		Top = tmp;
	}
	else {
		tmp->Prev = Top;
		Top = tmp;
	}
	Size++;
}

int MyStack::pop() {
	int tmp = -1;
	Node * tmpTop;
	if (Size > 0) {
		tmp = Top->Num;
		tmpTop = Top;
		Top = Top->Prev;
		delete tmpTop;
		Size--;
	}
	return tmp;
}
int MyStack::FindMax() {
	int tmp;
	Node * tmpNode = Top->Prev;
	tmp = Top->Num;
	do {
		if (tmpNode->Num > tmp) tmp = tmpNode->Num;
		tmpNode = tmpNode->Prev;
	} while (tmpNode != NULL);
	return tmp;
}

int MyStack::FindMin() {
	int tmp;
	Node * tmpNode = Top->Prev;
	tmp = Top->Num;
	do {
		if (tmpNode->Num < tmp) tmp = tmpNode->Num;
		tmpNode = tmpNode->Prev;
	} while (tmpNode != NULL);
	return tmp;
}

