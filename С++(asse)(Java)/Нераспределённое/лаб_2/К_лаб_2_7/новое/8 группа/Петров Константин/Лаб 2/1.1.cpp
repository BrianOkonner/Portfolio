/*	Петров Константин
8 группа

1.1	Задано выражение (инфиксная форма, например (5+45)*(55-5))  содержащее числа (любого типа),
знаки операций, круглые скобки. Записать его в виде обратной польской записи (постфиксная форма) и вычислить его значение.

	Тесты 
	(4+3)^2  4 3 + 2 ^    49
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <cstdlib>
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
	double Top();
	void  ShowAll();
	MyDoubleStack();
	~MyDoubleStack();

};
void MyDoubleStack::StackPush(double a) {
	Node *temp = new Node;
	temp->val = a;
	temp->prev = first;
	first = temp;
}
double MyDoubleStack::StackPop() {
	Node *temp = new Node;
	temp = first;
	first = first->prev;
	double z = temp->val;
	delete temp;
	return z;
}
inline bool MyDoubleStack::IsEmpty() {
	return (first == NULL) ? true : false;
}
inline MyDoubleStack::MyDoubleStack() {
	first = NULL;
}
inline MyDoubleStack :: ~MyDoubleStack() {
	delete first;
}
inline double MyDoubleStack::Top() {
	return first->val;
}
void MyDoubleStack::ShowAll() {
	Node *temp = first;
	while (temp != NULL)
	{
		cout << temp->val;
		temp = temp->prev;
	}
}

struct Node2 {
	char oper;
	Node2 *prev;
};
class OppStack {
	Node2 *first1;
public:
	void push(char operation);
	char pop();
	char element();
	void show();
	bool IsEmpty();
	OppStack();
	~OppStack();
};
void OppStack::push(char operation) {
	Node2 *temp = new Node2;
	temp->oper = operation;
	temp->prev = first1;
	first1 = temp;
}
char OppStack::pop() {
	char temp = first1->oper;
	Node2 *tmp = first1;
	first1 = first1->prev;
	delete tmp;
	return temp;
}
inline char OppStack::element() {
	return first1->oper;
}
void OppStack::show() {
	Node2 *temp = first1;
	while (temp != NULL) {
		cout << temp->oper;
		temp = temp->prev;
	}
}
inline bool OppStack::IsEmpty() {
	return (first1 == 0) ? true : false;
}
inline OppStack::OppStack() {
	first1 = NULL;
}
inline OppStack :: ~OppStack() {
	delete first1;
}

int isNumber(char *word);

int main() {
	setlocale(LC_ALL, "rus");
	MyDoubleStack S1;
	OppStack S2;

	ifstream fin("Input.txt");
	char *str = new char[81];
	fin >> str;
	fin.close();

	char *strP = new char[strlen(str)];
	strP[0] = '\0';
//----------------------------------------------------------------------------------
	int i, number = 0;

	for (i = 0; i < strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			number = number * 10 + (str[i] - '0');
			continue;
		}
		else {
			char temp_number[80];
			sprintf(temp_number, "%d", number);

			if (i != 0 && (str[i - 1] >= '0' && str[i - 1] <= '9')) {
				strcat(strP, temp_number);
				strcat(strP, " ");
			}

			number = 0;
			//------------------------------------------------------------
			switch (str[i]) {
			case '+': {
				while (!S2.IsEmpty()) {
					if (S2.element() == '*' || S2.element() == '/' || S2.element() == '^' || S2.element() == '+' || S2.element() == '-') {
						char *tSymb = new char[2];
						tSymb[0] = S2.pop();
						tSymb[1] = '\0';
						strcat(strP, tSymb);
						strcat(strP, " ");
					}
					else
						break;
				}
				S2.push(str[i]);
				break;
			}
					  //--------------------------------------------------------
			case '-': {
				if (i == 0 || str[i - 1] == '(')
					strcat(strP, "0 ");

				while (!S2.IsEmpty()) {
					if (S2.element() == '*' || S2.element() == '/' || S2.element() == '^' || S2.element() == '+' || S2.element() == '-') {
						char *tSymb = new char[2];
						tSymb[0] = S2.pop();
						tSymb[1] = '\0';
						strcat(strP, tSymb);
						strcat(strP, " ");
					}
					else
						break;
				}
				S2.push(str[i]);
				break;
			}
					  //------------------------------------------------------------
			case '*':
			case '/': {
				while (!S2.IsEmpty()) {
					if (S2.element() == '*' || S2.element() == '/' || S2.element() == '^') {
						char *tSymb = new char[2];
						tSymb[0] = S2.pop();
						tSymb[1] = '\0';
						strcat(strP, tSymb);
						strcat(strP, " ");
					}
					else
						break;
				}
				S2.push(str[i]);
				break;
			}
					  //------------------------------------------------------------
			case '^': {
				while (!S2.IsEmpty()) {
					if (S2.element() == '^') {
						char *tSymb = new char[2];
						tSymb[0] = S2.pop();
						tSymb[1] = '\0';
						strcat(strP, tSymb);
						strcat(strP, " ");
					}
					else
						break;
				}
				S2.push(str[i]);
				break;
			}
					  //------------------------------------------
			case '(': {
				S2.push(str[i]);
				break;
			}
					  //--------------------------------------------
			case ')': {
				while (!S2.IsEmpty()) {
					if (S2.element() != '(') {
						char *tSymb = new char[2];
						tSymb[0] = S2.pop();
						tSymb[1] = '\0';
						strcat(strP, tSymb);
						strcat(strP, " ");
					}
					else {
						char z = S2.pop();
						break;
					}
				}
				break;
			}
					  //-------------------------------------------------
			default: {
				cout << "Incorrect input" << endl;
				exit(0);
			}
			}
		}
	}
//----------------------------------------------------------------------------------
	if (str[strlen(str) - 1] >= '0' && str[strlen(str) - 1] <= '9') {
		char tNum[81];
		sprintf(tNum, "%d", number);
		strcat(strP, tNum);
		strcat(strP, " ");
	}
//----------------------------------------------------------------------------------
	while (!S2.IsEmpty()) {
		char *tSymb = new char[2];
		tSymb[0] = S2.pop();
		tSymb[1] = '\0';
		strcat(strP, tSymb);
		strcat(strP, " ");
	}
	cout << strP << endl;
//----------------------------------------------------------------------------------
	char *tmp1 = strtok(strP, " ");
	while (tmp1) {
		if (isNumber(tmp1))
			S1.StackPush(atoi(tmp1));
		else {
			switch (tmp1[0]) {
				case '+':{
						S1.StackPush(S1.StackPop() + S1.StackPop());
						break;
				}
				case '-': {
					S1.StackPush(S1.StackPop() - S1.StackPop());
					break;
				}
				case '*': {
					S1.StackPush(S1.StackPop() * S1.StackPop());
					break;
				}
				case '/': {
					S1.StackPush(1 / S1.StackPop() * S1.StackPop());
					break;
				}
				case '^': {
					double tNum = S1.StackPop();
					S1.StackPush(pow(S1.StackPop(), tNum));
					break;
				}
			}
		}
		tmp1 = strtok(NULL, " ");
	}
//----------------------------------------------------------------------------------
	cout << "Значение выражения равно " << S1.StackPop() << endl;

	return 0;
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