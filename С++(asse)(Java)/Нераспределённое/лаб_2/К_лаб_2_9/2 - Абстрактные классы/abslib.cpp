#include "abslib.h"


St1::St1()
{
	name[0] = '\0'; 
	price = 0;
}

St1::St1(const char *n_name, int n_price)
{
	strcpy_s(name, MAXLEN, n_name);	
	price = n_price;
}

St1::St1(const St1& stud)
{
	strcpy_s(name, MAXLEN, stud.name);
	price = stud.price;
}

ostream& operator << (ostream& out, const St1& stud)
{
	out << stud.name << "\t" << stud.price;
	return out;
}

istream& operator >> (istream& in, St1& stud)
{
	in.getline(stud.name, MAXLEN);
	in >> stud.price;
	if (in.peek() == '\n') in.get();
	return in;
}

St2::St2()
{
	name[0] = '\0';
}

St2::St2(const char* n_name)
{
	strcpy_s(name, MAXLEN, n_name);
}

St2::St2(const St2& stud)
{
	strcpy_s(name, MAXLEN, stud.name);
}

ostream& operator << (ostream& out, const St2& stud)
{
	out << stud.name;
	return out;
}

istream& operator >> (istream& in, St2& stud)
{
	in.getline(stud.name, MAXLEN);
	return in;
}

St3::St3()
{
	name[0] = '\0';
	date[0] = '\0';
	price = 0;
}

St3::St3(const char* n_name, const char* n_date, int n_price)
{
	strcpy_s(name, MAXLEN, n_name);
	strcpy_s(date, MAXLEN, n_date);
	price = n_price;
}

ostream& operator << (ostream& out, const St3& stud)
{
	out << stud.name << "\t" << stud.date << "\t" << stud.price;
	return out;
}

istream& operator >> (istream& in, St3& stud)
{
	in.getline(stud.name, MAXLEN);
	in.getline(stud.date, MAXLEN);
	in >> stud.price;
	if (in.peek() == '\n') in.get();
	return in;
}

ABS_LIB::ABS_LIB(int n)
{
	if (n < 0) throw WrongSize();
	size = n;
}

ABS_LIB::ABS_LIB(const ABS_LIB& l)
{
	size = l.size;
}

Stud2::Stud2(int s) : ABS_LIB(s)
{
	if (s == 0) nodes = NULL;
	else nodes = new St2[size];
}

Stud2::Stud2(const Stud2 &s) : ABS_LIB(s)
{
	if (size == 0) {nodes = NULL; return;}
	nodes = new St2[size];
	for (int i = 0; i < size; i++) nodes[i] = s.nodes[i];
}

Stud2::~Stud2()
{
	if (size) delete[] nodes;
}

Stud2& Stud2::operator =(const Stud2 &s)
{
	if (size) delete[] nodes;
	size = s.size;
	if (size == 0) {nodes = NULL; return *this;}
	nodes = new St2[size];
	for (int i = 0; i < size; i++) nodes[i] = s.nodes[i];
	return *this;
}

St2& Stud2::operator [](int n) const
{
	if (n < 0 || n >= size) throw WrongIndex();
	return nodes[n];
}

void Stud2::PutData(ostream& out)
{
	out << (*this);
}

void Stud2::GetData(istream& in)
{
	in >> (*this);
}

void Stud2::BinRead(std::istream& in)
{
	int tmp = in.tellg();
	in.seekg(0,ios::end);
	int n = in.tellg();
	n -= tmp;
	in.seekg(tmp);
	if (n % sizeof(St2)) throw CorruptedFile();
	delete[] nodes;
	size = n/sizeof(St2);
	nodes = (St2*)new char[n];
	in.read((char*)nodes,n);
}

void Stud2::BinWrite(std::ostream &out)
{
	out.write((char*)nodes,sizeof(St2)*size);
}

void Stud2::ListBoxPrint(CListBox* L)
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
void Stud2::Difference(ABS_LIB &l1, ABS_LIB &l2)//сделать вот тут
{
	bool flag;
	int j, k = 0;
	Stud2* s1 = (Stud2*)&l1;
	Stud2* s2 = (Stud2*)&l2;
	int* arr = new int[s1->GetCount()];
	for (int i = 0; i < s1->GetCount(); i++)
	{
		flag = false;
		j = s2->GetCount() - 1;
		while (j+1 && !flag) if (!strcmp((*s1)[i].name, (*s2)[j--].name)) flag = true;
		if (!flag) arr[k++] = i;
	}
	delete[] nodes;
	size = k;
	nodes = new St2[k];
	for (int i = 0; i < k; i++)
	{
		strcpy_s(nodes[i].name, MAXLEN, (*s1)[arr[i]].name);
//		strcpy_s(nodes[i].date, MAXLEN, "21 июня 2007 г.");
//		nodes[i].price = (*s1)[arr[i]].price;
	}
}

//-----------------------Сортировка по фамилиям в порядке, обратном алфавитному
int studcmp2(const void* s1, const void* s2)
{
	return strcmp(((St2*)s1)->name, ((St2*)s2)->name);
}

void Stud2::SortName()
{
	qsort(nodes, size, sizeof(St2), studcmp2);
}

Stud1::Stud1(int s) : ABS_LIB(s)
{
	if (s == 0) nodes = NULL;
	else nodes = new St1[size];
}

Stud1::Stud1(const Stud1 &s) : ABS_LIB(s)
{
	if (size == 0) {nodes = NULL; return;}
	nodes = new St1[size];
	for (int i = 0; i < size; i++) nodes[i] = s.nodes[i];
}

Stud1::~Stud1()
{
	if (size) delete[] nodes;
}

Stud1& Stud1::operator =(const Stud1 &s)
{
	if (size) delete[] nodes;
	size = s.size;
	if (size == 0) {nodes = NULL; return *this;}
	nodes = new St1[size];
	for (int i = 0; i < size; i++) nodes[i] = s.nodes[i];
	return *this;
}

St1& Stud1::operator [](int n) const
{
	if (n < 0 || n >= size) throw WrongIndex();
	return nodes[n];
}

void Stud1::PutData(ostream& out)
{
	out << (*this);
}

void Stud1::GetData(istream& in)
{
	in >> (*this);
}

void Stud1::BinRead(std::istream& in)
{
	int tmp = in.tellg();
	in.seekg(0,ios::end);
	int n = in.tellg();
	n -= tmp;
	in.seekg(tmp);
	if (n % sizeof(St1)) throw CorruptedFile();
	delete[] nodes;
	size = n/sizeof(St1);
	nodes = (St1*)new char[n];
	in.read((char*)nodes,n);
}

void Stud1::BinWrite(std::ostream &out)
{
	out.write((char*)nodes,sizeof(St1)*size);
}

void Stud1::ListBoxPrint(CListBox* L)
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
void Stud1::Difference(ABS_LIB &l1, ABS_LIB &l2)//сделать вот тут
{
	bool flag;
	int j, k = 0;
	Stud1* s1 = (Stud1*)&l1;
	Stud2* s2 = (Stud2*)&l2;
	int* arr = new int[s1->GetCount()];
	for (int i = 0; i < s1->GetCount(); i++)
	{
		flag = false;
		j = s2->GetCount() - 1;
		while (j+1 && !flag) if (!strcmp((*s1)[i].name, (*s2)[j--].name)) flag = true;
		if (!flag) arr[k++] = i;
	}
	delete[] nodes;
	size = k;
	nodes = new St1[k];
	for (int i = 0; i < k; i++)
	{
		strcpy_s(nodes[i].name, MAXLEN, (*s1)[arr[i]].name);
//		strcpy_s(nodes[i].date, MAXLEN, "21 июня 2007 г.");
		nodes[i].price = (*s1)[arr[i]].price;
	}
}

//-----------------------Сортировка по фамилиям в порядке, обратном алфавитному
int studcmp1(const void* s1, const void* s2)
{
	return strcmp(((St1*)s1)->name, ((St1*)s2)->name);
}

void Stud1::SortName()
{
	qsort(nodes, size, sizeof(St1), studcmp1);
}

Stud3::Stud3(int s) : ABS_LIB(s)
{
	if (s == 0) nodes = NULL;
	else nodes = new St3[size];
}

Stud3::Stud3(const Stud3 &s) : ABS_LIB(s)
{
	if (size == 0) {nodes = NULL; return;}
	nodes = new St3[size];
	for (int i = 0; i < size; i++) nodes[i] = s.nodes[i];
}

Stud3::~Stud3()
{
	if (size) delete[] nodes;
}

Stud3& Stud3::operator =(const Stud3 &s)
{
	if (size) delete[] nodes;
	size = s.size;
	if (size == 0) {nodes = NULL; return *this;}
	nodes = new St3[size];
	for (int i = 0; i < size; i++) nodes[i] = s.nodes[i];
	return *this;
}

St3& Stud3::operator [](int n) const
{
	if (n < 0 || n >= size) throw WrongIndex();
	return nodes[n];
}

void Stud3::PutData(ostream& out)
{
	out << (*this);
}

void Stud3::GetData(istream& in)
{
	in >> (*this);
}

void Stud3::BinRead(std::istream& in)
{
	int tmp = in.tellg();
	in.seekg(0,ios::end);
	int n = in.tellg();
	n -= tmp;
	in.seekg(tmp);
	if (n % sizeof(St3)) throw CorruptedFile();
	delete[] nodes;
	size = n/sizeof(St3);
	nodes = (St3*)new char[n];
	in.read((char*)nodes,n);
}

void Stud3::BinWrite(std::ostream &out)
{
	out.write((char*)nodes,sizeof(St3)*size);
}

void Stud3::ListBoxPrint(CListBox* L)
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
void Stud3::Difference(ABS_LIB &l1, ABS_LIB &l2)//сделать вот тут
{
	bool flag;
	int j, k = 0;
	Stud1* s1 = (Stud1*)&l1;
	Stud2* s2 = (Stud2*)&l2;
	int* arr = new int[s1->GetCount()];
	for (int i = 0; i < s1->GetCount(); i++)
	{
		flag = false;
		j = s2->GetCount() - 1;
		while (j+1 && !flag) if (!strcmp((*s1)[i].name, (*s2)[j--].name)) flag = true;
		if (!flag) arr[k++] = i;
	}
	delete[] nodes;
	size = k;
	nodes = new St3[k];
	for (int i = 0; i < k; i++)
	{
		strcpy_s(nodes[i].name, MAXLEN, (*s1)[arr[i]].name);
		strcpy_s(nodes[i].date, MAXLEN, "21 июня 2007 г.");
		nodes[i].price = (*s1)[arr[i]].price;
	}
}

//-----------------------Сортировка по фамилиям в порядке, обратном алфавитному
int studcmp3(const void* s1, const void* s2)
{
	return strcmp(((St3*)s1)->name, ((St3*)s2)->name);
}

void Stud3::SortName()
{
	qsort(nodes, size, sizeof(St3), studcmp3);
}