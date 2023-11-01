#include <iostream>
#include "H19.h"
using namespace std;

	MyDeque::MyDeque()
	{
		Deque = new int[30];
		tail = 0;
		head = 0;
	}
	MyDeque::MyDeque(int SIZE)
	{
		tail = 0;
		head = 0;
		Deque = new int[SIZE];
	}

	void MyDeque::printDeque()
	{
		for (int i = tail; i <= head; i++)
			cout << Deque[i] << "   ";
		cout << endl;
	}

	void MyDeque::push_back(int num)
	{

		head++;
		for (int i = head - 1; i > tail; i--)
		{
			Deque[i + 1] = Deque[i];
		}
		Deque[tail] = num;
	}

	void MyDeque::pop_front()
	{
		head--;
	}

	void MyDeque::push_front(int num)
	{
		head++;
		Deque[head] = num;
	}

	void MyDeque::pop_back()
	{
		for (int i = tail; i < head; i++)
		{
			Deque[i] = Deque[i + 1];
		}
		head--;
	}

	int MyDeque::size()
	{
		int s = 0;
		for (int i = tail; i < head; i++)
			s++;
		return s;
	}

	int MyDeque::front()
	{
		return Deque[head];
	}

	int MyDeque::back()
	{
		return Deque[tail];
	}

	bool MyDeque::isEmpty()
	{
		if (head == 0) return true;
		else return false;
	}

	MyDeque::~MyDeque()
	{
		delete[] Deque;
	}
