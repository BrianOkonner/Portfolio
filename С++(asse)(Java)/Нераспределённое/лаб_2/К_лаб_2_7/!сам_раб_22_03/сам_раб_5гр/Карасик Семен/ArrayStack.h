//Karasik Simon, group 5, 2017, lab 3_1, ArrayStack.h
#ifndef _ARRAY_STACK_H_

class ArrayStack		/* стек на массиве */
{
public:
    ArrayStack(const int size);  /* конструктор */
    ArrayStack(const ArrayStack& s);  // конструктор копирования
    ~ArrayStack();	        /* деструктор */
    void push(const int n);  /* втолкнуть элемент в стек */
    int top();
    int pop();	              /* вытолкнуть элемент из стека */
    bool isEmpty();	        /* пустой стек? */
    bool isFull();	        /* полный стек? */
	int size() const;

private:    
    int  m_size;	/* размерность массива */
    int* m_p;	/* указатель на массив */
    int  m_top;	/* верхушка стека */
};

#endif // _ARRAY_STACK_H_
