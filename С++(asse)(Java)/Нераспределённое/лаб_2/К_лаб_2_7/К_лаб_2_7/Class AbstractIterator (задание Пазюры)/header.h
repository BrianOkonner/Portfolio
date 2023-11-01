#include <iostream.>
#include <string.h>
using namespace std;
struct stack	// ����
{
	int  item;		        // ������ 
	struct  stack*  prev;	// ��������� �� ��������� ������� 
};
class AbstractIterator
{
public:
	virtual ~AbstractIterator() {};
	virtual bool InRange() const = 0;	// ������ � ���������� ��������? 
	virtual void Reset() = 0;			// �������� ������ � ������
	virtual int& operator *() const = 0;// ������������� (������ ��������)
	virtual void operator ++() = 0;		// ����� �� �������
};
class AbstractContainer
{
public:
	virtual ~AbstractContainer() {};
	virtual bool IsEmpty() const = 0;		// ��������� ����
	virtual bool IsFull()  const = 0;		// ��������� ������
};
class AbstractStack: public AbstractContainer
{
public:
	virtual void push(const int& n) = 0;	// ��������� � ����
	virtual void pop(int& n)  = 0;			// ���������� �� �����
};
class ArrayStack: public AbstractStack
{
protected:
	int		n;	// ����������� �������
	int*	p;		// ��������� �� ������
	int		top;	// �������� �����
public:
	ArrayStack(int r = 16);
	ArrayStack(ArrayStack & ob);
	~ArrayStack();
	void push(const int& r);	// ��������� � ����
	void pop(int& r);			// ���������� �� �����
	bool IsEmpty() const;
	bool IsFull() const ;
	friend class ArrayStackIterator;
};
class ArrayStackIterator: public AbstractIterator
{
	ArrayStack	&a;			// ������ �� ����
	int		it;			// ������� ������� ���������
public:
	ArrayStackIterator(ArrayStack& ob);
	bool InRange() const;			// ������ � ���������� ��������
	void Reset();				// �������� ������ � ������
	int& operator *() const;		// ������������� (������ ��������)
	void operator ++();			// ����� �� �������
};

