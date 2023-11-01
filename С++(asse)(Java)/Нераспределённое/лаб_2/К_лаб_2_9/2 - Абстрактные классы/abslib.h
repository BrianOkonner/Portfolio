#include <iostream>
#include <sstream>
#include <afxwin.h>
using namespace std;

struct WrongSize{};
struct CorruptedFile{};
struct WrongIndex{};

#define MAXLEN 50

class St1	//студенты, взявшие книги в библиотеке
{
public:
	char	name[MAXLEN];	//имя
	int		price;		//цена книг
	St1();
	St1(const char* n_name, int n_price);
	St1(const St1&);
	friend ostream& operator << (ostream& out, const St1& stud);
	friend istream& operator >> (istream& in, St1& stud);
};

//------------------------------------------структура данных St2
class St2
{
public:
	char	name[MAXLEN];	//имя
	St2();
	St2(const char* n_name);
	St2(const St2&);
	friend ostream& operator << (ostream& out, const St2& stud);
	friend istream& operator >> (istream& in, St2& stud);
};


//------------------------------------------структура данных St3
class St3
{
public:
	char name[MAXLEN];
	char date[MAXLEN];
	int price;
	St3();
	St3(const char* n_name, const char* n_date, int n_price);
	St3(const St3&);
	friend ostream& operator << (ostream& out, const St3& stud);
	friend istream& operator >> (istream& in, St3& stud);
};



class ABS_LIB
{
protected:
	int size;
public:
	ABS_LIB(int n);
	ABS_LIB(const ABS_LIB&);
	int GetCount() const {return size;}
	virtual void BinRead(istream&) = 0;
	virtual void BinWrite(ostream&) = 0;
	virtual void PutData(ostream&) = 0;
	virtual void GetData(istream&) = 0;
	virtual void ListBoxPrint(CListBox*) = 0;
	virtual void SortName() = 0;
	virtual void Difference(ABS_LIB&,ABS_LIB&) = 0;

};









class Stud2 : public ABS_LIB
{
	St2*	nodes;
public:
	Stud2(int s = 0);
	Stud2(const Stud2&);
	Stud2& operator = (const Stud2&);
	~Stud2();
	virtual void BinRead(istream&);
	virtual void ListBoxPrint(CListBox*);
	virtual void BinWrite(ostream&);
	virtual void PutData(ostream&);
	virtual void GetData(istream&);
	friend istream& operator >> (istream& in, Stud2& c)
	{
		in >> c.size;
		if (in.peek() == '\n') in.get();
		delete[] c.nodes;
		c.nodes = new St2[c.size];
		for (int i = 0; i < c.size; i++) in >> c.nodes[i];
		return in;
	}
	friend ostream& operator << (ostream& out, const Stud2& c)
	{
		for (int i = 0; i < c.size; i++) out << c.nodes[i] << endl;
		return out;
	}
	St2& operator[] (int n) const;
	virtual void SortName();
	virtual void Difference(ABS_LIB&,ABS_LIB&);
};








class Stud1 : public ABS_LIB
{
	St1*	nodes;
public:
	friend class Stud2;
	Stud1(int s = 0);
	Stud1(const Stud1&);
	Stud1& operator = (const Stud1&);
	~Stud1();
	virtual void BinRead(istream&);
	virtual void ListBoxPrint(CListBox*);
	virtual void BinWrite(ostream&);
	virtual void PutData(ostream&);
	virtual void GetData(istream&);
	friend istream& operator >> (istream& in, Stud1& c)
	{
		in >> c.size;
		if (in.peek() == '\n') in.get();
		delete[] c.nodes;
		c.nodes = new St1[c.size];
		for (int i = 0; i < c.size; i++) in >> c.nodes[i];
		return in;
	}
	friend ostream& operator << (ostream& out, const Stud1& c)
	{
		for (int i = 0; i < c.size; i++) out << c.nodes[i] << endl;
		return out;
	}
	St1& operator[] (int n) const;
	virtual void SortName();
	virtual void Difference(ABS_LIB&,ABS_LIB&);
};








class Stud3 : public ABS_LIB
{
	St3*	nodes;
public:
	Stud3(int s = 0);
	Stud3(const Stud3&);
	Stud3& operator = (const Stud3&);
	~Stud3();
	virtual void BinRead(istream&);
	virtual void ListBoxPrint(CListBox*);
	virtual void BinWrite(ostream&);
	virtual void PutData(ostream&);
	virtual void GetData(istream&);
	friend istream& operator >> (istream& in, Stud3& c)
	{
		in >> c.size;
		if (in.peek() == '\n') in.get();
		delete[] c.nodes;
		c.nodes = new St3[c.size];
		for (int i = 0; i < c.size; i++) in >> c.nodes[i];
		return in;
	}
	friend ostream& operator << (ostream& out, const Stud3& c)
	{
		for (int i = 0; i < c.size; i++) out << c.nodes[i] << endl;
		return out;
	}
	St3& operator[] (int n) const;
	virtual void SortName();
	virtual void Difference(ABS_LIB&,ABS_LIB&);
};

