#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
using namespace std;
//Алгоритм возвращает true, если интервал [first2,last2) является подмножеством интервала [firstl,lastl).
string names[] = {  "Todd", "Mike", "Graham", "Jack", "Brett"};

int main ()
{
	vector <string> v1(names, names+5);
	vector <string> v2 (2);
	v2[0] = "foo";
	v2[1] = "bar";
	sort (v1.begin (), v1.end ());
	sort (v2.begin (), v2.end ());

	bool inc = includes (v1.begin (), v1.end (),
					   v2.begin (), v2.end ());
	cout<<"V1"<<endl;
	ostream_iterator <string> iter (cout, "\n");
	copy (v1.begin (), v1.end (), iter);
	cout<<"\nV2"<<endl;
	copy (v2.begin (), v2.end (), iter);
	cout<<endl;
	if (inc)
		cout << "v1 includes v2" << endl;
	else
		cout << "v1 does not include v2" << endl;
	cout<<endl;
	v2[0] = "Brett";
	v2[1] = "Todd";
	cout<<"V2"<<endl;
	copy (v2.begin (), v2.end (), iter);
	cout<<endl;
	inc = includes (v1.begin (), v1.end (),
				  v2.begin (), v2.end ());
	if (inc)
		cout << "v1 includes v2" << endl;
	else
		cout << "v1 does not include v2" << endl;
	return 0;
}
