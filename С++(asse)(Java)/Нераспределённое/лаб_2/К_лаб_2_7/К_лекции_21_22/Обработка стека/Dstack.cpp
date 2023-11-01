// ������������ ����
#include <iostream>
using namespace std;
struct stack
{
	int item;
	stack *prev;
};


	stack *top;
void InitStack ()					
{
	top = NULL;
}

void push (int a)		//������� �  ����
{
	stack *temp;
	temp = new stack;
	temp->prev = top;
	temp->item = a;
	top = temp;
}
int pop ()				//������� �� �����
{
	int res;
	stack *temp;
	temp = top;
	top = top->prev;
	res = temp->item;
	delete temp;
	return res;
}
	
void print ()			//������ ����������� �����
{
	stack *temp;
	temp = top;
	while (temp)
	{
		cout<<temp->item<<endl;
		temp = temp->prev;
	}
}
int peek ()			// ����� �������� �� �������� �����
{
	if (top)
		return top->item;
}
bool is_empty ()			//�������� ���� �� ����
{
	bool res = false;
	if (top == NULL)
		res = true;
	return res;
}
void removestack ()			//������ ����������� �����
{
	stack *temp;
	temp = top;
	while (top)
	{
		temp = top;
		top=top->prev;
		delete temp;
	}
}
	
void main ()
{
	

	if (is_empty())
		cout<<"Stack is empty\n";
	int a;
	
	push(1);
	push(2);
	push(3);
	//s.current();
	print();
	cout<<pop()<<endl;
	cout<<"-***"<<endl;
	print();
	removestack ();	
	if (is_empty())
		cout<<"Stack is empty\n";
}