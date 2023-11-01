// динамическая очередь для хранения элементов любого типа
#include <iostream>
#include <string.h>
using namespace std;
struct queue
	{
		void* data;
		queue* next;
	};
	queue* head,*tail;

void InitQueue()
{
	head = 0;
	tail = 0;
}

void* peek()
{
	return head->data;
}

bool isEmpty()
{
	return head == 0 ? true : false;
}
void* pop()
{
  if (!isEmpty())
  {
	queue* tmp = head;
	void* tdata = head->data;
	head = head->next;
	delete tmp;
	return tdata;
  }
  else
   return 0;

}

void push(void* data)
{
	queue* tmp = new queue;
	tmp->data=data;
	tmp->next = 0;
	if(head == 0)
	{
		head = tmp;
		tail = head;
		return;
	}
	tail->next = tmp;
	tail = tmp;
	tail->next=0;
}


bool isPrime(char* s)
{
	int a = atoi(s);
	for(int i = 2; i<a/2; i++)
		if(a%i == 0)
			return false;
	return true;
}

void main()
{   int i, *items;
    for (i=1;i<5;i++)
	{
	  items = new int;
	  *items = i; 
	  push((int*)items);
	}
	while (!isEmpty())
	{
	items = (int*)pop();
	cout<< *items<<endl;
	}


/*
	FILE *input = fopen("Input.txt", "r");
	if(input == 0)
	{
		cout<<"Can't open input file\n";
		return;
	}
	char* string = new char[80];
	Queue();
	while(!feof(input))
	{
		fgets(string, 80, input);
		if(string[ strlen(string) - 1 ] == '\n')
			string[ strlen(string) - 1 ] = '\0';
		
		
		if(isPrime(string))
		{
			int a = atoi(string);
			push(new int(a));
		}
	}
	
	FILE *out = fopen("output.txt", "w");
	while(isEmpty())
	{
		char* str = new char[80];
		str=itoa(*(int*)pop();
		fputs(str, 10, out);
		fputc('\n', out);
	}
	fclose(out);
	*/
}