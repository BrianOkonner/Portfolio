/*Щелко Алексей
8 группа

1.		Задано выражение, содержащее числа, знаки операций, круглые скобки.
Записать его в виде обратной польской записи.


*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>

using namespace std;

stack <char> S;
stack <double> S1;

int main() {
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
			if (S.empty()) {
				S.push(temp[0]);
				continue;
			}
				M[0]=S.top();
				//S.pop();
				M[1] = '\0';			
				while (!S.empty()) {
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
	while (!S.empty()) {
		char *T = new char[2];
		T[0]=S.top();
		T[1] = '\0';
		S.pop();
		strcat(Result,T);
		strcat(Result, " ");
	}
	cout << Result << endl;

	system("pause");
	return 0;
}



