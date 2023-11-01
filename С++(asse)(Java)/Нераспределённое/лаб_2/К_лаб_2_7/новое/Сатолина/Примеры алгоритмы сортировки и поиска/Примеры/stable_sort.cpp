#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
using namespace std;
//сортировка с сохранением относительного порядка
//одинаковых элементов

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
	str l[6];
	copy(letters, letters+6,l);
	for (int i = 0; i < 6; i++)
		cout << letters[i] <<endl;
	cout << endl;
	stable_sort (letters, letters + 6, string_less);
	cout<<"stable_sort"<<endl;
	for (int i = 0; i < 6; i++)
		cout << letters[i] <<endl;
	cout << endl;

	sort (l, l + 6, string_less);	
	cout<<"sort"<<endl;
	for (int i = 0; i < 6; i++)
		cout << l[i] <<endl;
	cout << endl;
  return 0;
}