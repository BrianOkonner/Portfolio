#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
using namespace std;

int main()
{

	int  arr[]= {2, 3, 4, 6, 6, 6, 6, 9, 9, 9};
	vector <int> v (arr, arr+10);
	vector <int> :: iterator it;
	it=lower_bound(v.begin(), v.end(),6);
	cout<<"Index>=6: "<<it-v.begin()<<endl;
	it=upper_bound(v.begin(), v.end(),6);
	cout<<"Index>6: "<<it-v.begin()<<endl;

	pair<vector<int>::iterator, vector<int>::iterator> pair_it;
	pair_it=equal_range (v.begin(), v.end(),6);
	cout<<"Index>=6: "<<pair_it.first-v.begin()<< " Index>6: "<<pair_it.second-v.begin() <<endl;
	return 0;
}
