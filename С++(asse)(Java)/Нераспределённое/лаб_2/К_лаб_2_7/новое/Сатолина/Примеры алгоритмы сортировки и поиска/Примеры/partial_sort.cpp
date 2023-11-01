#include <deque>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
using namespace std;

struct str
{
	string s;
	int a;
	str(string s1="", int b=0):s(s1), a(b){}
	friend ostream & operator<<(ostream &os,const str&a)
	{
		os<<a.s<<' '<<a.a;
		return os;
	}
};
bool string_less(const str& a, const str& b)
{
	return(a.s<b.s);
}


str letters[6] = {str("bb",1), str("aa",1), str("ll",11), str("aa",2), str("bb",2), str("cc",4) };

int main ()
{
	deque <str> d(letters,letters+6);
	for (int i = 0; i < 6; i++)
		cout << letters[i] <<endl;
	cout << endl;
	partial_sort (d.begin(), d.begin()+3, d.end(),string_less);
	cout<<"partial_sort 3"<<endl;
	deque <str>::iterator it;
	for (it=d.begin(); it!=d.end(); it++)
		cout << *it <<endl;
	cout << endl;
	return 0;
}