// Щелко Алексей 8 группа
// 1.1	Задано выражение (инфиксная форма, например (5+45)*(55-5))  содержащее числа
// (любого типа), знаки операций, круглые скобки. Записать его в виде обратной польской
// записи (постфиксная форма) и вычислить его значение. 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Node {
	double val;
	Node *prev;
};

struct stack1 {
	double c;
	stack1 *prev;
};

stack1 *top;

class Stack228 {
	Node *first;
public:
	void push(char c);
	char pop();
	bool Empty();
	char top();
	Stack228();
	~Stack228();
};

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

inline Stack228::Stack228() {
	first = NULL;
}

inline Stack228::~Stack228() {
	delete first;
}

inline char Stack228:: top() { 
	return first->val;
}

inline bool Stack228::Empty() {  
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

int main() {
	setlocale(LC_ALL, "rus");
	Stack228 S;
	int i = 0;
	char str[50], Result[50];
	Result[0] = '\0';
	cin >> str;
	for (i = 0; str[i] != '\0'; i++) {
		char *temp = new char[2];
		temp[0] = str[i];
		temp[1] = '\0';
		if ((temp[0] >= '0' && temp[0] <= '9') || temp[0] == '.') {
			strcat(Result, temp);
			strcat(Result, " ");
			continue;
		}

		if (temp[0] == '*' || temp[0] == '/') {
			char* M = new char[2];
			if (S.Empty()) {
				S.push(temp[0]);
				continue;
			}
			M[0] = S.top();
			//S.pop();
			M[1] = '\0';
			while (!S.Empty()) {
				if (M[0] == '+' || M[0] == '-') {

					M[0] = S.top();
					M[1] = '\0';
					strcat(Result, M);
					strcat(Result, " ");
					S.pop();
					S.push(temp[0]);
				}
				else S.push(temp[0]);
				break;
			}
			continue;
		}
		if (temp[0] == '+' || temp[0] == '-') {
			S.push(temp[0]);
			continue;
		}
		if (temp[0] == '(') {
			S.push(temp[0]);
			continue;
		}

		if (temp[0] == ')') {
			char T[2];
			while (S.top() != '(') {
				T[0] = S.top();
				T[1] = '\0';
				strcat(Result, T);
				strcat(Result, " ");
				S.pop();
			}
			S.pop();
			continue;
		}
	}
	while (!S.Empty()) {
		char *T = new char[2];
		T[0] = S.top();
		T[1] = '\0';
		S.pop();
		strcat(Result, T);
		strcat(Result, " ");
	}
	cout << Result << endl;

	Stack228 S1;
	char *tmp1 = strtok(Result, " ");
	while (tmp1) {
		if (isNumber(tmp1))
			S1.push(atoi(tmp1));
		else {
			switch (tmp1[0]) {
			case '+': {
				S1.push(S1.pop() + S1.pop());
				break;
			}
			case '-': {
				S1.push(S1.pop() - S1.pop());
				break;
			}
			case '*': {
				S1.push(S1.pop() * S1.pop());
				break;
			}
			case '/': {
				S1.push(1 / S1.pop() * S1.pop());
				break;
			}
			}
		}
		tmp1 = strtok(NULL, " ");
	}
	int c = S1.pop();
	cout << "Значение выражения равно " << c << endl;

	system("pause");
	return 0;
}
