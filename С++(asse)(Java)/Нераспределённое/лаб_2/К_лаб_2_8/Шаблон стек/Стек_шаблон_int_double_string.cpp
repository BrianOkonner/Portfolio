by Зираэль&Гвинблейд */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
 #include <string>
using namespace std;
struct EmptyStack {}EmptyStack_Exception;

template<class T> class ArrayStack		/* стек на массиве */
{
	int current_capacity;
	int _size;
	T* stack;
	T*  head;	/* верхушка стека */
public:
	ArrayStack();
	ArrayStack(const int _size);  /* конструктор */
	ArrayStack(const ArrayStack& s);  // конструктор копирования
	~ArrayStack();	        /* деструктор */
	bool isEmpty();
	void push(const T& n);  /* втолкнуть элемент в стек */
	void pop();	              /* вытолкнуть элемент из стека */
	T top();				/*возврат верхнего*/
	typedef T* iterator;
	typedef const T* const_iterator;
	iterator begin()
        { return _size ? (&stack[0]) : 0; }

	const_iterator begin() const 
       { return _size ? (&stack[0]) : 0; }

	iterator end() { return head; }
	const_iterator end() const 
        { return head; }
	int size() { return _size; }
	 ArrayStack& operator= (const ArrayStack&);
	template <typename T>
        friend ostream& operator<<(ostream&, const ArrayStack&);
           };

template<class T>

        ArrayStack<T>::ArrayStack(const int size) {
	current_capacity = max(100, 1.5*size);
	stack = new T[current_capacity];
	size = 0;
	head = 0;
}

template<class T>
ArrayStack<T>::ArrayStack() {
	current_capacity = 100;
	stack = new T[current_capacity];
	_size = 0;
	head = 0;
}

template<class T>
ArrayStack<T>::ArrayStack(const ArrayStack& s) {
	if (this != &s)
	{
		current_capacity = s.current_capacity;
		_size = s._size;
		stack = new T[current_capacity];
		stack = (T*)memcpy(stack, s.stack, current_capacity * sizeof(T));
		head = &stack[_size];
	}
}

template<class T>
ArrayStack<T>::~ArrayStack() {
	delete[] stack;
}

template<class T>
bool ArrayStack<T>::isEmpty() {
	return !(_size);
}

template<class T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack& a) {
	if (_size)
		delete[] stack;
	current_capacity = a.current_capacity;
	_size = a._size;
	stack = new T[current_capacity];
	stack = (T*)memcpy(stack, a.stack, current_capacity * sizeof(T));
	head = &stack[_size];
	return *this;
}


template<class T>
void ArrayStack<T>::push(const T& n) {
	if (++_size >= current_capacity)
	{
		current_capacity *= 2;
		stack = (T*)realloc((void*)stack, size_t(current_capacity*sizeof(T)));
	}
	stack[_size - 1] = n;
	head = &stack[_size];
}

template<class T>
void ArrayStack<T>::pop() {
	if (_size)
	{
		--_size;
		head = &stack[_size];
	}
	else
		throw EmptyStack_Exception;
}

template<class T>
T ArrayStack<T>::top() {
	return _size ? stack[_size - 1] : throw EmptyStack_Exception;
}

template<class T>
ostream& operator << (ostream& os, const ArrayStack<T>& a) {
	for (auto i : a)
		os << i << ' ';
	return os;
}

bool isnum(const string& a) {
	int tch = 0;
	for (char i : a) {
		if (i == '.')
			++tch;
		else {
			if (!isdigit(i))
				return false;
		}
	}
	return tch <= 1;
}

void main()
{
	/*ArrayStack<int> a;
	for (int i = 0; i < 2000;)
	{
		a.push(++i);
	}
	ArrayStack<int> b(a), c;
	c = b;	*/
	ifstream fin("input.txt");
	string a;
	ArrayStack<double>d;
	ArrayStack<int>in;
	ArrayStack<string>s;
	while (fin >> a) {
		if (!isnum(a)) {
			s.push(a);
		}
		else
			if (a.find('.') != a.npos)
				d.push(atof(a.c_str()));
			else
				in.push(atoi(a.c_str()));
	}
	cout << "INTS:\n" << in << "\nDOUBLES:\n" << d << "\nstrings:\n" << s;
}
