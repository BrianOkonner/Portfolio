///////////////////////////////////////////////////////////////
// Замечания:
// Интерфейсы и данные-члены можно изменить.
///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
class QueueIterator;
struct QEmpty{};
struct QFull{};
class ArrayQueue
{
protected:
	int		size;			// размерность массива
	int*	p;				// указатель на массив
	int		head;			// индекс первого занятого элемента
	int     tail;			// индекс первого незанятого элемента в конце очереди
	int n;
public:
	ArrayQueue(int size1 = 16)
	{
		size = size1;
		p= new int[size];
		head=-1;
		tail=0;
		n=0;
	}
	ArrayQueue(ArrayQueue &q)
	{
		size = q.size;
		p= new int[size];
		for (int i=0; i<size; i++)
			p[i] = q.p[i];
		head=q.head;
		tail=q.tail;
		n=q.n;

	}
	~ArrayQueue()
	{
		delete [] p;
	}
	void push_back(const int& x)		// втолкнуть в очередь 
	{
		if (IsFull()) throw QFull();
		p[tail] = x;
		if (n==0) head=tail;
		tail = (tail+1) % size;
		n++;
		
	}
	void pop_front(int& x)			// удалить из очереди
	{
		if (IsEmpty()) throw QEmpty();
		x=p[head];
		head= (head+1) % size;
		n--;
		if (n==0)
		{
			head=-1;tail=0;
		}

	}
	bool IsEmpty() const
	{
		if (n==0) 
			return true;
		else return false;
	}
	bool IsFull() const
	{
		if (n==size) 
			return true;
		else return false;

	}
	friend class QueueIterator;
};


// класс Итератор кольцевой очереди
class QueueIterator
{
	ArrayQueue	&a;			// ссылка на очередь
	int		pos;			// текущая позиция итератора
	QueueIterator();
	int num;
public:
	QueueIterator(ArrayQueue& a1):a(a1)
	{
		pos=a.head;
		num=0;

	}
	bool InRange()				// индекс в допустимых пределах
	{
		if (num<a.n)
			return true;
		else
			return false;
	}
	void Reset()				// сбросить индекс в начало
	{
		pos=a.head;
		num=0;
	}
	int& operator *() const		// разыменование (чтение элемента)
	{
		return a.p[pos];
	}
	void operator ++(int)		// сдвиг на элемент
	{
		pos= (pos +1) % a.size;
		++num;
	}
	void operator ++()		// сдвиг на элемент
	{
		pos= (pos +1) % a.size;
		++num;
	}
};
int main()
{
	ArrayQueue q(3);
	QueueIterator it(q);
try
{
	int x;
		q.push_back(0);
		cout <<"push "<<0<<endl;
		q.push_back(2);
		cout <<"push "<<2<<endl;
	for (int i=2; i<10; i++)
	{
		q.push_back(i*2);
		cout <<"push "<<i*2<<endl;
		it.Reset();
		while (it.InRange())
		{
			cout<<*it<<" ";
			++it;
		}
		cout<<endl;
		q.pop_front(x);
		cout <<'\t'<<"pop "<<x<<endl;
		q.pop_front(x);
		cout <<'\t'<<"pop "<<x<<endl;
	}
}
catch (QFull)
{
	cout<< " Queue is Full. Program ends;"<<endl;
}
catch (QEmpty)
{
	cout<< " Queue is Empty. Program ends;"<<endl;
}

	return 0;
}
