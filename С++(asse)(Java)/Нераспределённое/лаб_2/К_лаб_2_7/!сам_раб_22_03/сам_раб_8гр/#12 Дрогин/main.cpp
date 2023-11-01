#include <fstream>
#include <iostream>
#include "Deck.h"

using namespace std;

void solve(Deck & deck)
{
    Deck even, odd;
    while (!deck.empty())
    {
        int t = deck.front();
        if (t % 2 ==  0)
            even.push_back(t);
        else
            odd.push_back(t);
        deck.pop_front();
    }
    while (!even.empty())
    {
        deck.push_front(even.front());
        even.pop_front();
    }
    while (!odd.empty())
    {
        deck.push_front(odd.front());
        odd.pop_front();
    }
}

int main()
{
    Deck deck;
    ifstream fin("input.txt");
    ofstream fout("Output.txt");

    while (!fin.eof())
    {
        int t;
        fin >> t;
        deck.push_front(t);
    }

   /* while (!deck.empty())
    {
        cout << deck.front() << ' ';
        deck.pop_front();
    }

   */
    solve(deck);
    while (!deck.empty())
    {
        fout << deck.front() << ' ';
        deck.pop_front();
    }

    system("pause");

    return 0;
}