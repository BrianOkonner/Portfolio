//������ ������ 8 ������
//������ "������" � �������������� ������������ �����

#include <iostream>
#include <stack>
using namespace std;
//������� �������� ��������� � ����������� ��������
int main() {
	setlocale(LC_ALL, "rus");
	stack <int> s1, s2, s3;
	int amount, elem, counter = 0;
	cout << "\t���������� �����\n������� ���������� ��������� �����: "; cin >> amount;
	cout << "������� �������� �����: ";
	for (int i = 0; i < amount; i++) {
		cin >> elem;
		s1.push(elem);
	}
	int tmp;
	while (1) 
	{
		s2.push(s1.top()); // �������� ������
		s1.pop();
		s3.push(s1.top()); // ������
		s1.pop();
		if (!s1.empty()) {
			s2.push(s1.top()); // ������
			s1.pop();

			// ��������
			tmp = s2.top();
			s2.pop();

			if (s2.top() == tmp) counter++;

			s1.push(s2.top());
			s2.pop();
			s1.push(s3.top());
			s3.pop();
		}
		else break;
	}
	cout << "���������� ��������� ����� � ����������� �������� �����: " << counter << endl;
	system("pause");
}