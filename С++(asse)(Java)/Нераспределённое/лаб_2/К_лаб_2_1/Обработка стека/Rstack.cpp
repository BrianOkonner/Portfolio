// Динамический стек
#include <iostream>
using namespace std;
struct stack
{
	int item;
	stack *prev;
};



stack* InitStack (stack *top)					
{
	top = NULL;
	return top;
}

stack* push (int a,stack *top)		//Занести в  стек
{
	stack *temp;
	temp = new stack;
	temp->prev = top;
	temp->item = a;
	top = temp;
return top;
}
int pop (stack *top)				//Извлечь из стека
{
	int res;
	stack *temp;
	temp = top;
	top = top->prev;
	res = temp->item;
	delete temp;
	return res;
}
	
void print (stack *top)			//Печать содержимого стека
{
	stack *temp;
	temp = top;
	while (temp)
	{
		cout<<temp->item<<endl;
		temp = temp->prev;
	}
}
int peek (stack *top)			// Выбор элемента из верхушки стека
{
	if (top)
		return top->item;
}
bool is_empty (stack *top)			//Проверка пуст ли стек
{
	bool res = false;
	if (top == NULL)
		res = true;
	return res;
}
void removestack (stack *top)			//Печать содержимого стека
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
	stack *top;
    top=new stack;
	top=InitStack (top);	
		int a;
	
	top=push(1,top);
	top=push(2,top);
	top=push(3,top);
	print(top);
/*	//s.current();
	print();
	cout<<pop()<<endl;
	cout<<"-***"<<endl;
	print();
	removestack ();	
	if (is_empty())
		cout<<"Stack is empty\n";
		*/
}