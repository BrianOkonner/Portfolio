//Karasik Simon, group 5, 2017, lab 3_1, ArrayStack.h
#ifndef _ARRAY_STACK_H_

class ArrayStack		/* ���� �� ������� */
{
public:
    ArrayStack(const int size);  /* ����������� */
    ArrayStack(const ArrayStack& s);  // ����������� �����������
    ~ArrayStack();	        /* ���������� */
    void push(const int n);  /* ��������� ������� � ���� */
    int top();
    int pop();	              /* ���������� ������� �� ����� */
    bool isEmpty();	        /* ������ ����? */
    bool isFull();	        /* ������ ����? */
	int size() const;

private:    
    int  m_size;	/* ����������� ������� */
    int* m_p;	/* ��������� �� ������ */
    int  m_top;	/* �������� ����� */
};

#endif // _ARRAY_STACK_H_
