#include "Header.h"

using namespace std;


Queue::Queue() {
		m_head = NULL;
		m_tail = NULL;
		m_size = 0;
	}
Queue::~Queue()
	{
		while (!empty())
			pop();
	}

void Queue::push(const int& data)
	{
		Item *item = new Item;
		item->data = data;
		item->next = NULL;
		item->prev = m_tail;
		if (m_head == NULL)
			m_head = item;
		else
			m_tail->next = item;
		m_tail = item;
		m_size++;
	}
void Queue::pop()
	{
		Item *newHead = m_head->next;
		delete m_head;
		m_head = newHead;
		if (m_head == NULL)
			m_tail = NULL;
		m_size--;
	}

int Queue::front() const
	{
		return m_head->data;
	}

bool Queue::empty() const
	{
		return m_head == NULL;
	}

int Queue::size() const
	{
		return m_size;
	}