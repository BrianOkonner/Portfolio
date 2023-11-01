#pragma once
class queue
{
	struct node
	{
		int a;
		node* prev;
	};
	struct node *head;
	public:
		queue();
		~queue();
		bool isempty();
		void push(int a);
		int pop();
		int peek();
};