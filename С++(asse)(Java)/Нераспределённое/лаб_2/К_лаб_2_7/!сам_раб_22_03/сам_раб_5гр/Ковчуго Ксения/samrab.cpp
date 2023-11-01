//������� ������ 5 ������ 16 �������
#include "Header.h"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main()
{
	MyStack Stack;
	ofstream out("Output.txt");
	int data;
	ifstream in("input.txt");     //��������� ���� ��� ������
	while (!in.eof())
	{
		in >> data;
		Stack.push(data);
	}
	int max = Stack.FindMax();
	int min = Stack.FindMin();
	queue <int> outqueue;
	while (Stack.size() > 0) {
		int num = Stack.pop();
		if (num != max && num != min) outqueue.push(num);
	}
	while (outqueue.size() > 0) {
		out << outqueue.front() << ' ';
		outqueue.pop();
	}
	system("pause");
	return 0;
}