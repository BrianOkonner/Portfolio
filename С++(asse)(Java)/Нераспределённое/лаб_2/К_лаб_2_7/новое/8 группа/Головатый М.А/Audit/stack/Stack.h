#ifndef STACK
#define STACK // ��������� ��������� �������� h-�����

class Stack
{//���� ��� ����������� ������� ������ private
	struct Link // ��������� � ����� ��������� �� ������� �������� ������
	{
		void* data;
		Link* next;
		Link(void*, Link*);
		~Link();
	} *head; // ��������� �� �������� �����
public:
	Stack(); // ����������� �� ���������
	~Stack(); // 
	void Push(void*); 
	void* Top();//Peek
	bool isEmpty();
	void Pop();
};

#endif