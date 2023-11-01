/*
Кветко Никита 8-я группа
Лабораторная Работа N7
1.	Использование стека STL.
1.1.	Заданное выражение инфиксной формы
записать в постфиксной форме и вычислить его значение

Тест:	Инфиксная запись: (2+3*9)-3*(9-3)
		Польская нотация: 239*+393-*-
		Результат: 11
*/
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	ifstream in("input.txt");
	ofstream out("output.txt");
	stack <int> operands; stack <char> operations;
	string infix, postfix; char str[81];
	in.getline(str, 81); infix = str;
	for (int i = 0; i < infix.length(); i++)
	{
		if (isdigit(infix[i])) postfix += infix[i]; // если число, то заносим в выходную строку
													// если знак операции, тогда:
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '(' || infix[i] == ')')
		{
			switch (infix[i])
			{
			case '+':
				if ((!operands.empty()) && (operands.top() == '*' || operands.top() == '/'))
				{
					postfix += operands.top();
					operands.pop();
					operands.push(infix[i]);
					continue;
				}
				else
				{
					operands.push(infix[i]);
					continue;
				}
			case '-':
				if ((!operands.empty())&&(operands.top() == '*' || operands.top() == '/'))
				{
					postfix += operands.top();
					operands.pop();
					operands.push(infix[i]);
					continue;
				}
				else
					operands.push(infix[i]);
				continue;
			case '*':
				operands.push(infix[i]); continue;
			case '/':
				operands.push(infix[i]);
				continue;
			case '(':
				operands.push(infix[i]);
				continue;
			case ')':
				while (operands.top() != '(')
				{
					postfix += operands.top();
					operands.pop();
				}
				operands.pop();
				continue;
			}
		}
	}
	while (!operands.empty()) 
	{
		postfix += operands.top();
		operands.pop();
	}
	cout << "Инфиксная запись: " << infix << endl; // Исходное выражение
	cout << "Польская нотация: " << postfix << endl; // Польская запись 
	for (int i = 0, a, b; i < postfix.length(); i++) {
		switch (postfix[i]) {
		case '+':
			a = operations.top();
			operations.pop();
			b = operations.top();
			operations.pop();
			operations.push(b + a);
			continue;
		case '-':
			a = operations.top();
			operations.pop();
			b = operations.top();
			operations.pop();
			operations.push(b - a);
			continue;
		case '/':
			a = operations.top();
			operations.pop();
			b = operations.top();
			operations.pop();
			operations.push(b / a);
			continue;
		case '*':
			a = operations.top();
			operations.pop();
			b = operations.top();
			operations.pop();
			operations.push(b * a);
			continue;
		default: operations.push(postfix[i] - '0');
		}
	}
	double result = operations.top();
	cout << "Результат: " << result << endl;
	system("pause");
}