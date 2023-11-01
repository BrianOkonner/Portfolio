#include <iostream.>
#include <string.h>
using namespace std;
struct stack	// стек
{
	int  item;		        // данные 
	struct  stack*  prev;	// указатель на следующий элемент 
};
class AbstractIterator
{
public:
	virtual ~AbstractIterator() {};
	virtual bool InRange() const = 0;	// индекс в допустимых пределах? 
	virtual void Reset() = 0;			// сбросить индекс в начало
	virtual int& operator *() const = 0;// разыменование (чтение элемента)
	virtual void operator ++() = 0;		// сдвиг на элемент
};
class AbstractContainer
{
public:
	virtual ~AbstractContainer() {};
	virtual bool IsEmpty() const = 0;		// контейнер пуст
	virtual bool IsFull()  const = 0;		// контейнер полный
};
class AbstractStack: public AbstractContainer
{
public:
	virtual void push(const int& n) = 0;	// втолкнуть в стек
	virtual void pop(int& n)  = 0;			// вытолкнуть из стека
};
class ArrayStack: public AbstractStack
{
protected:
	int		n;	// размерность массива
	int*	p;		// указатель на массив
	int		top;	// верхушка стека
public:
	ArrayStack(int r = 16);
	ArrayStack(ArrayStack & ob);
	~ArrayStack();
	void push(const int& r);	// втолкнуть в стек
	void pop(int& r);			// вытолкнуть из стека
	bool IsEmpty() const;
	bool IsFull() const ;
	friend class ArrayStackIterator;
};
class ArrayStackIterator: public AbstractIterator
{
	ArrayStack	&a;			// ссылка на стек
	int		it;			// текущая позиция итератора
public:
	ArrayStackIterator(ArrayStack& ob);
	bool InRange() const;			// индекс в допустимых пределах
	void Reset();				// сбросить индекс в начало
	int& operator *() const;		// разыменование (чтение элемента)
	void operator ++();			// сдвиг на элемент
};

