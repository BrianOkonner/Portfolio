/*  �������� ����� ���������
	1 ���� 8 ������
	Class Deque
*/

#include "deque.h"

int main(void) 
{
	setlocale(LC_ALL, "rus");
	try {
		Deque deq;
		int d1 = 17;
		deq.insTail(d1);
		deq.insTail(32);
		deq.ins�ead(56);
		cout << "�������: ";
		deq.show();
		Deque deq_2(deq);
		cout << "����� �������: ";
		deq_2.show();
		system("pause");
	}
	catch (int i) {
		cout << "������ (������� ������)" << endl;
	}
	return 0;
}