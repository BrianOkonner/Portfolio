#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
struct Student
{
	char  name[80];					// ôàìèëèÿ ñòóäåíòà
	int   num;								// íîìåð ãðóïïû
	double  grade;							// ñðåäíèé áàë
};

class StudContainer
{
	enum { _Size = 100 };
	int size;								// ðàçìåðíîñòü ìàññèâà
	Student* p;								// ìàññèâ çàïèñåé î ñòóäåíòàõ
	int count;					// êîëè÷åñòâî ñòóäåíòîâ â êîíòåéíåðå
public:

	StudContainer(int& _n);					// êîíñòðóêòîð
	StudContainer(const StudContainer& c);	// êîíñòðóêòîð êîïèðîâàíèÿ
	~StudContainer();						// äåñòðóêòîð
	bool insert(Student s);			// âêëþ÷åíèå ñòóäåíòà â êîíòåéíåð
	bool del(char* name);					// èñêëþ÷åíèå ñòóäåíòà èç êîíòåéíåðà
	void sortByName();						// ñîðòèðîâêà çàïèñåé ïî èìåíàì
	Student* findByName(char* name);		// ïîèñê ñòóäåíòà ïî èìåíè
	void sortByGroupAndName();				// ñîðòèðîâêà ïî ãðóïïàì, èìåíàì
	void report(ostream& out);				// âûâåñòè îò÷åò î ñðåäíåì áàëëå
	void print(ostream& out);				// ðàñïå÷àòàòü ñïèñîê ñòóäåíòîâ
	int Size();								// âîçâðàùàåò ðàçìåð êîíòåéíåðà
	int Count();							// âîçâðàùàåò êîëè÷åñòâî çàïèñåé â êîíòåéíåðå
};
Student Read_Write_file(istream&, ostream&);
//int StudContainer::count = 0;
