
#include "MineStack1.h"
template <class T> Mstack<T>::Mstack()
{
	number=20;
	number--;
	head=0;
}
template <class T> Mstack<T>::~Mstack(){}
template <class T> int  Mstack<T>::push(T *el)
{
	if (head==0)
		stack=new T [number];
	else
		stack[head++]=*el;
	if(head==0)
		return 0;
	else 
		return 1;
}
template<class T> T Mstack<T>::top()
{
	return stack[head];
}
template<class T> T* Mstack<T>::pop()
{
	return stack[head--];
}
#endif