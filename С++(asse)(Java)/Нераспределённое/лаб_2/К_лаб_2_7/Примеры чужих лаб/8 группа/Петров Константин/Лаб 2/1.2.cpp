/*	Петров Константин
8 группа

1.2 Описать процедуру, которая подсчитывает количество элементов стека, у которых одинаковые соседи

Алгоритм

Заполняем стек введенными числами. Если в стеке только два числа, завершаем программу. Если в стеке только 3 числа, сравниваем 1 и 3,
выводим результат. Если в стеке больше трех чисел, берем первые три числа, сравниваем соседов у второго элемента, далее второй становится
первым, третий вторым, а третий достаем из стека. Повторяем, пока стек не пуст. Как только стек пуст, сравниваем
соседов предпоследнего элемента. Выводим результат.

Тесты
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
	cout << "Введите элементы стека(-1 - выход)" << endl;
	double c = 0;
	int i = 0;   //Счетчик количества элементов стека
	do {
		cin >> c;
		if (c != -1) { Stack.StackPush(c); ++i; }
	} while (c != -1);

	if (i <= 2) {
		cout << "Элементов с одинаковыми соседями нет" << endl;
		exit(0);
	}
//-----------------------------------------------------------------------------
	int num = 0;
	double a1, a2, a3;
	// Достаем первые три элемента
	a1 = Stack.StackPop();
	a2 = Stack.StackPop();
	a3 = Stack.StackPop();
	if (Stack.IsEmpty() == true) {  //Если элементов только 3
		if (a3 == a1) {
			cout << "Количество элементов стека с одинаковыми соседями равно - 1" << endl;
			exit(0);
		}
		else {
			cout << "Количество элементов стека с одинаковыми соседями равно - 0" << endl;
			exit(0);
		}
	}
	do {   // Если элементов >3
		if (a1 == a3) ++num;
		a1 = a2;
		a2 = a3;
		a3 = Stack.StackPop();
	} while (Stack.IsEmpty() == false);

	if (a1 == a3) ++num; //Проверка соседов предпоследнего элемета стека

	cout << "Количество элементов стека с одинаковыми соседями равно - " << num << endl;
//-----------------------------------------------------------------------------
	return 0;
}
