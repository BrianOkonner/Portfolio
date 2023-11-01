#include <iostream.h>

class Set{
private:
	int*p;
	int count;
	void sort();
public:
	Set();	
	Set(const Set&s);
	Set(int*,int);
	bool include(int);

	friend Set operator + (const Set &s1, const int n);
	friend Set operator - (const Set &s1, const int n);
	friend bool operator == (const Set&s1,const Set&s2);
	friend bool operator != (const Set&s1,const Set&s2);
	friend bool operator > (const Set&s1,const Set&s2);
	friend bool operator < (const Set&s1,const Set&s2);
	friend bool operator >= (const Set&s1,const Set&s2);
	friend bool operator <= (const Set&s1,const Set&s2);	

	Set operator * (const Set&s1);
	Set operator + (const Set&s1);
	Set operator - (const Set&s1);
    Set& operator += (const int);
	Set& operator -= (const int);
	Set& operator *= (const Set&s1);
	Set& operator += (const Set&s1);
	Set& operator -= (const Set&s1);
	
	friend ostream& operator << (ostream &out,const Set &s);
	friend istream& operator >> (istream &in, Set &s);
};
