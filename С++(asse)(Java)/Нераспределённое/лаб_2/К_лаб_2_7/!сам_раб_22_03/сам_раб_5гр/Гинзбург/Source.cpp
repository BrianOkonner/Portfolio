//Гинзбург 1 курс 5 группа 8 вариант
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <istream>
#include <stack>
#include "Header.h";
using namespace std;
queue::queue()
{
	head = NULL;
}
queue::~queue()
{
	while (head != NULL)
	{
		node *temp = head->prev;
		delete head;
		head = temp;
	}
}
bool queue::isempty()
{
	if (head==NULL)
		return true;
	else
		return false;
}
void queue::push(int a)
{
	node *temp = new node;
	temp->a = a;
	temp->prev = head;
	head = temp;
}

int queue::pop() 
{
	int k = head->a;
	node *temp = head->prev;
	delete head;
	head = temp;
	return k;
}
int queue::peek()
{
	int k = head->a;
	return k;
}
void main()
{
	int u;
	queue q;
	queue q2;
	int n;
	cout << "Number of elements is";
	cin >> n;
	int *a;
	a = new int[n];
	cout << "Enter your numbers";
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
		q.push(a[i]);
	while (!q.isempty())
		if (q.peek() < 10 || q.peek() >= 100)
			q2.push(q.pop());
		stack <int> st;
	while (!q2.isempty())
		st.push(q2.pop());
	ofstream fout;
	fout.open("Output.txt");
	while (!st.empty())
	{
		fout << st.top()<<" ";
		st.pop();
	}
	fout.close();
}
