/*
	������ ����������
		8 ������
		����� 2 + ���. ������ + ������ ������ 
*/

#include "list.h"

int main() {
	setlocale(LC_ALL, "rus");
	List l;
	int m, p;
	cout << "������� ���������� ����� - ";
	cin >> p;
	cout << "������� ��� �������� - ";
	cin >> m;
	if (p < 2 || m < 1){
		cout << "�������� ����!" << endl;
		return 0;
	}
	//----------------------------------------------------------------------------
	for (int i = 1; i <= p; l.push_back(i), i++);
	//----------------------------------------------------------------------------
	while (p != 1){
		for (int j = 1; j <= m; j++) {
			if (j != m) {
				int y = l.front();
				l.remove_head();
				l.push_back(y);
			}
			else {
				l.remove_head();
			}
		}
		--p;
	}
	cout << "�������� - " << l.front() << endl;

	//system("pause");
	return 0;
}