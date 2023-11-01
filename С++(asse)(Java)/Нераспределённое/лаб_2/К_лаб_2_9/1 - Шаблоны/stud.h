#include <fstream>
#include <sstream>
#include <iostream>
#include <afxwin.h>
using namespace std;

#define MAXLEN 50
struct WrongSize{};	//в конструкторе при неправильном размере
struct WrongIndex{};	//в операторе индексирования при неправильном индексе
struct CorruptedFile{};	//в бинарном чтении файла при его неверном размере

//------------------------------------------структура данных Stud1
class Stud1	//студенты, взявшие книги в библиотеке
{
public:
	char	name[MAXLEN];	//имя
	char	address[MAXLEN];	//адрес
	int		price;		//цена книг
	Stud1();
	Stud1(const char* n_name, const char* n_address, int n_price);
	Stud1(const Stud1&);
	friend ostream& operator << (ostream& out, const Stud1& stud);
	friend istream& operator >> (istream& in, Stud1& stud);
};

Stud1::Stud1()
{
	name[0] = '\0'; 
	address[0] = '\0'; 
	price = 0;
}

Stud1::Stud1(const char *n_name, const char *n_address, int n_price)
{
	int n = min(strlen(n_name), MAXLEN);
	for (int i = 0; i < n; i++) name[i] = n_name[i];	
	n = min(strlen(n_address), MAXLEN);
	for (int i = 0; i < n; i++) address[i] = n_address[i];
	price = n_price;
}

Stud1::Stud1(const Stud1& stud)
{
	for (int i = 0; i < MAXLEN; i++) name[i] = stud.name[i];
	for (int i = 0; i < MAXLEN; i++) address[i] = stud.address[i];
	price = stud.price;
}

ostream& operator << (ostream& out, const Stud1& stud)
{
	out << stud.name << "\t" << stud.address << "\t" << stud.price;
	return out;
}

istream& operator >> (istream& in, Stud1& stud)
{
	in.getline(stud.name, MAXLEN);
	in.getline(stud.address, MAXLEN); 
	in >> stud.price;
	if (in.peek() == '\n') in.get();
	return in;
}

//------------------------------------------структура данных Stud2
class Stud2
{
public:
	char	name[MAXLEN];	//имя
	Stud2();
	Stud2(const char* n_name);
	Stud2(const Stud2&);
	friend ostream& operator << (ostream& out, const Stud2& stud);
	friend istream& operator >> (istream& in, Stud2& stud);
};

Stud2::Stud2()
{
	name[0] = '\0';
}

Stud2::Stud2(const char* n_name)
{
	int n = min(strlen(n_name), MAXLEN);
	for (int i = 0; i < n; i++) name[i] = n_name[i];
}

Stud2::Stud2(const Stud2& stud)
{
	for (int i = 0; i < MAXLEN; i++) name[i] = stud.name[i];
}

ostream& operator << (ostream& out, const Stud2& stud)
{
	out << stud.name;
	return out;
}

istream& operator >> (istream& in, Stud2& stud)
{
	in.getline(stud.name, MAXLEN);
	return in;
}

//------------------------------------------структура данных Stud3
class Stud3
{
public:
	char name[MAXLEN];
	char address[MAXLEN];
	char date[MAXLEN];
	int price;
	Stud3();
	Stud3(const char* n_name, const char* n_address, const char* n_date, int n_price);
	Stud3(const Stud3&);
	friend ostream& operator << (ostream& out, const Stud3& stud);
	friend istream& operator >> (istream& in, Stud3& stud);
};

Stud3::Stud3()
{
	name[0] = '\0';
	address[0] = '\0';
	date[0] = '\0';
	price = 0;
}

Stud3::Stud3(const char* n_name, const char* n_address, const char* n_date, int n_price)
{
	int n = min(strlen(n_name), MAXLEN);
	for (int i = 0; i < n; i++) name[i] = n_name[i];	
	n = min(strlen(n_address), MAXLEN);
	for (int i = 0; i < n; i++) address[i] = n_address[i];
	n = min(strlen(n_date), MAXLEN);
	for (int i = 0; i < n; i++) date[i] = n_date[i];
	price = n_price;
}

ostream& operator << (ostream& out, const Stud3& stud)
{
	out << stud.name << "\t" << stud.address << "\t" << stud.date << "\t" << stud.price;
	return out;
}

istream& operator >> (istream& in, Stud3& stud)
{
	in.getline(stud.name, MAXLEN);
	in.getline(stud.address, MAXLEN);
	in.getline(stud.date, MAXLEN);
	in >> stud.price;
	if (in.peek() == '\n') in.get();
	return in;
}

//------------------------------------------структура данных STUD
template <class T>
class STUD
{
	int	size;
	T*	nodes;
public:
	STUD(int s = 0);
	STUD(const STUD&);
	STUD& operator = (const STUD&);
	~STUD();
	void BinRead(istream&);
	void ListBoxPrint(CListBox*);
	void BinWrite(ostream&);
	friend istream& operator >> (istream& in, STUD& c)
	{
		in >> c.size;
		if (in.peek() == '\n') in.get();
		delete[] c.nodes;
		c.nodes = new T[c.size];
		for (int i = 0; i < c.size; i++) in >> c.nodes[i];
		return in;
	}
	friend ostream& operator << (ostream& out, const STUD& c)
	{
		for (int i = 0; i < c.size; i++) out << c.nodes[i] << endl;
		return out;
	}
	T& operator[] (int n) const;
	int GetCount() const {return size;}
	void SortName();
};

template <class T>
STUD<T>::STUD(int s = 0)
{
	if (s < 0) throw WrongSize();
	size = s;
	if (s == 0) nodes = NULL;
	else nodes = new T[size];
}

template <class T>
STUD<T>::STUD(const STUD<T> &s)
{
	size = s.size;
	if (size == 0) {nodes = NULL; return;}
	nodes = new T[size];
	for (int i = 0; i < size; i++) nodes[i] = s.nodes[i];
}

template <class T>
STUD<T>::~STUD()
{
	if (size) delete[] nodes;
}

template <class T>
STUD<T>& STUD<T>::operator =(const STUD<T> &s)
{
	if (size) delete[] nodes;
	size = s.size;
	if (size == 0) {nodes = NULL; return *this;}
	nodes = new T[size];
	for (int i = 0; i < size; i++) nodes[i] = s.nodes[i];
	return *this;
}

template <class T>
T& STUD<T>::operator [](int n) const
{
	if (n < 0 || n >= size) throw WrongIndex();
	return nodes[n];
}

template <class T>
void STUD<T>::BinRead(std::istream& in)
{
	int tmp = in.tellg();
	in.seekg(0,ios::end);
	int n = in.tellg();
	n -= tmp;
	in.seekg(tmp);
	if (n % sizeof(T)) throw CorruptedFile();
	delete[] nodes;
	size = n/sizeof(T);
	nodes = (T*)new char[n];
	in.read((char*)nodes,n);
}

template <class T>
void STUD<T>::BinWrite(std::ostream &out)
{
	out.write((char*)nodes,sizeof(T)*size);
}

template <class T>
void STUD<T>::ListBoxPrint(CListBox* L)
{
	int l;
	char* k;
	L->ResetContent();
	for (int i = 0; i < size; i++)
	{
		stringstream str;
		str << nodes[i];
		str.seekg(0,ios::end);
		l = str.tellg();
		str.seekg(0,ios::beg);
		k = new char [l + 1];
		str.read(k,l);
		k[l] = '\0';
		L->AddString(k);
		delete[] k;
	}
}

//----------------------------Получение списка студентов-должников
STUD<Stud3> StudDebt(const STUD<Stud1>& s1, const STUD<Stud2>& s2)
{
	bool flag;
	int j, k = 0;
	int* arr = new int[s1.GetCount()];
	for (int i = 0; i < s1.GetCount(); i++)
	{
		flag = false;
		j = s2.GetCount() - 1;
		while (j+1 && !flag) if (!strcmp(s1[i].name, s2[j--].name)) flag = true;
		if (!flag) arr[k++] = i;
	}
	STUD<Stud3> A(k);
	for (int i = 0; i < k; i++)
	{
		strcpy_s(A[i].address, MAXLEN, s1[arr[i]].address);
		strcpy_s(A[i].name, MAXLEN, s1[arr[i]].name);
		//A[i].date[0] = '\0';
		strcpy_s(A[i].date, MAXLEN, "21 июня 2007 г.");
		A[i].price = s1[arr[i]].price;
	}
	return A;
}

//-----------------------Сортировка по фамилиям в порядке, обратном алфавитному
template <class T>
int studcmp(const void* s1, const void* s2)
{
	return -(strcmp(((T*)s1)->name, ((T*)s2)->name));
}

template <class T>
void STUD<T>::SortName()
{
	qsort(nodes, size, sizeof(T), studcmp<T>);
}