/*	Щелко А 8 группа

1.2 Описать процедуру, которая подсчитывает количество элементов стека, у которых одинаковые соседи

Тесты
4 5 2 3 7 8     // 0
3 3 3 3 3 6     // 3
1 3 1 3 2 4     // 2
*/

#include <iostream>
#include <string.h>
using namespace std;

struct Stack {
	double val;
	Stack *prev;
};

Stack *top;

class Class {
Stack *first;
public: 
		void MyFunc();
		void StackPush(double a);
		double StackPop();
		bool IsEmpty();
		Class();
		~Class();
	};

inline Class::Class() {
	first = NULL;
}

inline Class::~Class() {
	delete first;
}

Class S;

int main() {
	top = NULL;
	setlocale(LC_ALL, "rus");
	cout << "Vvedite elementi stacka(-1 - выход)" << endl;
	double c = 0;
	int i = 0;
	do {
		cin >> c;
		if (c != -1) { S.StackPush(c); ++i; }
	} while (c != -1);

	if (i <= 2) {
		cout << "Net takih elementov" << endl;
		exit(0);
	}
	//S.Input();
	S.MyFunc();
	system("pause");
	return 0;
}

void Class::MyFunc() {
	int num = 0;
	double a1, a2, a3;
	a1 = S.StackPop();
	a2 = S.StackPop();
	a3 = S.StackPop();
	if (S.IsEmpty() == true) {  //Если элементов только 3
		if (a3 == a1) {
			cout << "Kol-vo elementov stacka s odinak sosedami ravno - 1" << endl;
			exit(0);
		}
		else {
			cout << "Kol-vo elementov s odinak sosedami ravno - 0" << endl;
			exit(0);
		}
	}
	do {   // Если элементов >3
		if (a1 == a3) ++num;
		a1 = a2;
		a2 = a3;
		a3 = S.StackPop();
	} while (S.IsEmpty() != true);

	if (a1 == a3) ++num;

	cout << "Kol-vo elementov s odinak sosedami ravno - " << num << endl;
}

void Class::StackPush(double a) {
	Stack *temp = new Stack;
	temp->val = a;
	temp->prev = first;
	first = temp;
}
double Class::StackPop() {
	Stack *temp = new Stack;
	temp = first;
	first = first->prev;
	double z = temp->val;
	delete temp;
	return z;
}
inline bool Class::IsEmpty() {
	bool res = false;
	if (first == NULL)
		res = true;
	return res;
}


