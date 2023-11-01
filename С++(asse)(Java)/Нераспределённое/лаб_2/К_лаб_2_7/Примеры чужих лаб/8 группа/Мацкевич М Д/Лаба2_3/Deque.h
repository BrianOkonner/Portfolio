#include <fstream>
#include <iostream>
using namespace std;
class Deque		/* äåê – äâóñòîðîííÿ î÷åðåäü */
{
	struct node			/* ýëåìåíò äåêà */
{
	int  item;	/* äàííûå */
	struct  node*  next;  /* óêàçàòåëü íà ñëåäóþùèé ýëåìåíò */
	struct  node*  prev;  /* óêàçàòåëü íà ïðåäûäóùèé ýëåìåíò */
};
/* óêàçàòåëè íà ïåðâûé è ïîñëåäíèé ýëåìåíòû â ñïèñêå */
struct node *head, *tail;
public:
	Deque();			// êîíñòðóêòîð
	Deque(const Deque& d);	// êîíñòðóêòîð êîïèðîâàíèÿ
	~Deque();		/* äåñòðóêòîð */
	void insНead(int n);	/* âêëþ÷èòü ýëåìåíò â ãîëîâó äåêà */
	void insTail(int n);	/* âêëþ÷èòü ýëåìåíò â õâîñò äåêà */
	int delHead();	      /* èñêëþ÷èòü ýëåìåíò èç ãîëîâû äåêà */
	int delTail();	      /* èñêëþ÷èòü ýëåìåíò èç õâîñòà äåêà */
	bool isEmpty();		/* ïóñòîé äåê? */
	void print(ostream&);
}; 
