#include "Deck.h"

Deck::Deck()
{
    m_head = NULL;
    m_tail = NULL;
    m_size = 0; 
}

Deck::Deck(const Deck & other)
{
    m_head = m_tail = NULL;
    m_size = 0;
    *this = other;
}

Deck::~Deck()
{
    clear();
}

Deck & Deck::operator=(const Deck & other)
{
    clear();
    Item *it = other.m_head;
    while (it)
    {
        push_back(it->data);
        it = it->next;
    }
    return *this;
}

void Deck::push_front(int x)
{
    Item *it = new Item(x, NULL, m_head);
    if (empty())
    {
        m_head = m_tail = it;
    }
    else
    {
        m_head->prev = it;
        m_head = it;
    }
    m_size++;
}

void Deck::push_back(int x)
{
    Item *it = new Item(x, m_tail, NULL);
    if (empty())
    {
        m_head = m_tail = it;
    }
    else
    {
        m_tail->next  = it;
        m_tail = it;
    }
    m_size++;
}

void Deck::pop_front()
{
    Item *it = m_head->next;
    delete m_head;
    if (it == NULL)
    {
        m_head = m_tail = NULL;
    }
    else
    {
        it->prev = NULL;
        m_head = it;
    }
    m_size--;
}

void Deck::pop_back()
{
    Item *it = m_tail->prev;
    delete m_tail;
    if (it == NULL)
    {
        m_head = m_tail = NULL;
    }
    else
    {
        it->next = NULL;
        m_tail = it;
    }
    m_size--;
}

int Deck::front()
{
    return m_head->data;
}

int Deck::back()
{
    return m_tail->data;
}

int Deck::size() const
{
    return m_size;
}

bool Deck::empty() const
{
    return m_size == 0;
}

void Deck::clear()
{
    while (!empty())
        pop_back();
}
