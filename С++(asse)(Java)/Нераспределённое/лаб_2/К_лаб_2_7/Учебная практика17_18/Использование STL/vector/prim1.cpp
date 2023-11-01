#include <iostream>
#include <vector>
using namespace std;
int main()
{
	    setlocale(LC_ALL,".1251");
	/*vector<int> v(10);
	for(int i = 0; i < 10; i++) 
		cin>>v[i];
	for(int i = 0; i < 10; i++) 
	{
		v[i] = (i+1)*(i+1);
	}
	for(int i = 0; i < 10; i++) 
		cout<<v[i]<<endl;
	for(int i = 9; i > 0; i--) 
	{
	v[i] -= v[i-1];
	}
	for(int i = 0; i < 10; i++) 
		cout<<v[i]<<endl;*/
	vector<int> v(25);
	for(int i = 0; i < 20; i++) 
	{
		v[i] = i+1;
	}
	//v.resize(25);
	//for(int i = 0; i < 25; i++) 
	//{
	//	v.push_back(i*2); // Запись производится в элементы 
 //                     // [25..30), а не [20..25) !
	//}
	v.insert(v.begin()+10,1000);	
	v.insert(v.begin()+10,5,5000);	
	v.erase(v.begin()+15);
	v.erase(v.begin()+25,v.end());
	vector<int> v2(20,-1);
	v2.swap(v);
	for(int i = 0; i < v.size(); i++) 
		cout<<i<<" "<<v[i]<<" "<<v2[i]<<endl;
	v.clear();
	if (v.empty()) cout<<"пусто"<<endl;


}