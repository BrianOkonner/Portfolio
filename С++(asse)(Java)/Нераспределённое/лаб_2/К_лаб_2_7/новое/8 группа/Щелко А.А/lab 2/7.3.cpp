/*	Щелко А	8 группа

3	Задача Иосифа Флавия
Вокруг считающего стоит N человек, из которых выделен первый, а остальные занумерованы по часовой стрелке
числами от 2 до N. Считающих, начиная с кого - то, ведет счет до M. Человек, на котором остановился счет, выходит.
Счет продолжается со следующего человека, и так до тех пор, пока не останется 1 человек. Определить номер оставшегося человека,
если известно M и  то, что счет начинается с первого человека. Результат записать в текстовый файл

Тесты
10 - 2 - 5
14 - 17 - 9
*/
#include <fstream>
#include <iostream>
using namespace std;

struct Node {
	int Number;
	Node *next;
};

Node *head;
Node *tail;

class Class {
public:	void Input(int &N, int &M);
		void MyFunction(int M);
		void ListFilling(int a);
		void ListPush(int k);

};
Class S;

void Class::Input(int &N, int &M) {
	cout << "Число участников" << endl;
	cin >> N;
	cout << "Шаг удаления " << endl;
	cin >> M;

	if (M == 1) {
		cout << N << endl;
		exit(0);
	}
	if (M == 0) {
		cout << "Неверно" << endl;
		exit(0);
	}
	cout <<"Оставшийся человек под номером - ";
}

void Class::MyFunction(int M) {
	Node *t = head->next;
	tail->next = head->next;
	for (int k = 1; t != t->next; t = t->next, k++) {
		if (k == M - 1) {
			t->next = t->next->next;
			k = 0;
		}
	}
	cout << t->Number << endl;
}

void Class::ListFilling(int a) {
	int k = 1;
	while (k <= a) {
		S.ListPush(k);
		k++;
	}
}

void Class::ListPush(int k) {
	Node *tCell = new Node;
	tCell->next = NULL;
	tCell->Number = k;
	tail->next = tCell;
	tail = tCell;
}

int main() {
	setlocale(LC_ALL, "rus");
	int N, M;
	head = new Node;
	tail = head;
	S.Input(N, M);
	S.ListFilling(N);
	S.MyFunction(M);
	system("pause");
	return 0;
}
