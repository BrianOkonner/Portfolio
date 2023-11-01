/*
Андреев Дмитрий 8 группа

Задание 2_2 1: 1.2	Описать процедуру, которая подсчитывает количество элементов стека, у которых равные "соседи"


*/

#include <iostream>

using namespace std;

//***************************** собственно класс *************************************
struct Node {
	int value;
	Node * prev;
};

class Stack {
private:
	Node * head;
public:
	Stack();
	~Stack();
	void push(int);
	int pop();
	int top();
	bool empty();
};
//***************************** функции класса ***************************************
Stack::Stack() {	//инициализация
	head = NULL;
}

void Stack::push(int a)		//запихнуть в стек
{
	Node* temp = new Node;
	temp->prev = head;
	temp->value = a;
	head = temp;
}
int Stack::pop()		//достать из стека
{
	char a;
	Node * temp = head;
	if (empty())
		return NULL;
	else
		a = temp->value;
	head = head->prev;
	delete temp;
	return a;
}
int Stack::top()		//прочитать элемент
{
	if (!empty())
		return head->value;
	else
		return NULL;
}
bool Stack::empty()		//проверка на пустоту
{
	if (head == NULL)
		return true;
	else
		return false;
}
Stack::~Stack()		//деструктор
{
	Node * temp;
	while (head)
	{
		temp = head;
		head = head->prev;
		delete temp;
	}
}

//*************************************************************************

using namespace std;

void main() {		//не менялось с прошлой лабы. А зачем?

	setlocale(0, "rus");

	cout << "Введите элементы. Для окончания ввода нажмите ctrl+z:" << endl;

	Stack s;
	int b = 2;
	while (cin.good()) {
		cin >> b;
		s.push(b);
	}

	s.pop();

	int a1, a2, i = 1, k = 0;

	Stack s2;

	a1 = s.top();
	s.pop();
	a2 = s.top();
	s.pop();

	while (!s.empty()) {


		if (i % 2 != 0) {
			if (s.top() == a1) k++;
			a1 = s.top();
		}
		else {

			if (s.top() == a2) k++;
			a2 = s.top();
		}
		i++;
		s.pop();
	}

	cout << "Равные соседи у " << k << " элементов." << endl;

	system("pause");
}