// Щелко Алексей 8 группа
// 1.1	Задано выражение (инфиксная форма, например (5+45)*(55-5))  содержащее числа
// (любого типа), знаки операций, круглые скобки. Записать его в виде обратной польской
// записи (постфиксная форма) и вычислить его значение. 

#include "Header.h"


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
