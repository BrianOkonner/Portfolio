//Karasik Simon, group 5, 2017, lab 3_1, ArrayStack.cpp
#include "ArrayStack.h"

ArrayStack::ArrayStack(const int size)
{
    m_size = size;
    m_p = new int[size];
    m_top = 0;
}

ArrayStack::ArrayStack(const ArrayStack& s)
{
    m_size = s.m_size;
    m_top = s.m_top;
    m_p = new int[m_size];
    for (int i = 0; i < m_top; i++)
        m_p[i] = s.m_p[i];
}

ArrayStack::~ArrayStack()
{
    delete[] m_p;
}

void ArrayStack::push(const int n)
{
    if (isFull())
        return;
    m_p[m_top++] = n;
    //m_top++;
}

int ArrayStack::top()
{
    return m_p[m_top - 1];
}

int ArrayStack::pop()
{
    if (isEmpty())
        return 0;
    return m_p[--m_top];
}

bool ArrayStack::isEmpty()
{
    return m_top == 0;
}

bool ArrayStack::isFull()
{
    return m_top == m_size;
}

int ArrayStack::size() const
{
	return m_top;
}