#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
using namespace std;
bool str_compare (const char* a_, const char* b_)
{
  return ::strcmp (a_, b_) < 0 ? 1 : 0;
}

char* names[] = { "Graham", "Brett",  "Jack", "Mike", "Todd" };

int main ()
{
	const unsigned namesCt = sizeof (names)/sizeof (names[0]);
	ostream_iterator <char*> iter (cout, "\n");
	copy(names,names+5, iter);
	cout<<endl;
	cout <<"min_element "<< *min_element (names, names + namesCt, str_compare) << endl;
	cout <<"max_element "<< *max_element (names, names + namesCt, str_compare) << endl;
	return 0;
}