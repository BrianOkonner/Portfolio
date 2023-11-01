#ifndef DECK_H
#define DECK_H

#include <cstddef> //NULL

class Deck
{
public:
    Deck();
    Deck(const Deck&);
    ~Deck();

    Deck& operator=(const Deck&);
    void push_front(int);
    void push_back(int);
    void pop_front();
    void pop_back();
    int front();
    int back();
    int size() const;
    bool empty() const;
    void clear();

private:
    struct Item
    {
        int data;
        Item *prev, *next;
        Item(int _data, Item *_prev, Item *_next)
        {
            data = _data;
            prev = _prev;
            next = _next;
        }
    } *m_head, *m_tail;
    int m_size;
};

#endif

