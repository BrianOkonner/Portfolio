#pragma once
template <class T>
class Stack
{
	struct list
	{
		T data;
		list *next;
		list(T y, list *p)
		{
			data = y;
			next = p;
		}
	}*head;
public:
	Stack();
	~Stack() {};
	void push(T data);
	T pop();
	T peek();
	bool empty();
};

template <class T>
Stack <T>::Stack() {
	head = NULL;
	T data;
}
template <class T>
void Stack <T>::push(T data)
{
	list *cur = new list(data, head);
	head = cur;
}
template <class T>
T Stack <T>::pop() {
	T res = head->data;
	list *tmp = head->next;
	delete head;
	head = tmp;
	return res;
}
template <class T>
T Stack <T>::peek()
{
	return head->data;
}
template <class T>
bool Stack <T>::empty() {
	return (head == NULL) ? 1 : 0;
}