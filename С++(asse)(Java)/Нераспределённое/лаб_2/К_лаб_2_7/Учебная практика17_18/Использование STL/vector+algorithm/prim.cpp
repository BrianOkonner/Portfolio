#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


bool prov( int n)
{
    return (n %5 == 0) ;
}

int main()
{
	std::ifstream fin("masiv1.txt");
	std::ofstream fout("masiv2.txt");
	setlocale(LC_ALL,".1251");
	int n,x;
	fin>>n;
	n=10;
	vector<int> v;
	for(int i = 0; i < n; i++) 
	{
		fin>>x;
		v.push_back(x);
	}
	//поиск элемента в массиве
	cout<<"chto ischem"<<endl;
	cin>>x;
	int k = find(v.begin(), v.end(), x) - v.begin();
    if(k < v.size()) 
		cout<<"chislo na meste "<<k<<endl;
	else
		cout<<"net chisla"<<endl;
	
	//поиск по условию: число кратно 5
	k = find_if(v.begin(), v.end(), prov) - v.begin();
    if(k < v.size()) 
		cout<<"chislo "<<v[k]<<" na meste "<<k<<endl;
	else
		cout<<"net chisla"<<endl;
	
	//поиск минимального и максимального
	int k_min = min_element(v.begin(), v.end()) - v.begin(); 
	cout<<"min element="<<v[k_min]<<" na meste - "<<k_min<<endl;
	int k_max = max_element(v.begin(), v.end()) - v.begin(); 
	cout<<"max element="<<v[k_max]<<" na meste - "<<k_max<<endl;

	//сортировка в порядке убывания
	sort(v.rbegin(),v.rend());
	
	for(int i = 0; i < v.size(); i++) 
		fout<<v[i]<<endl;

}