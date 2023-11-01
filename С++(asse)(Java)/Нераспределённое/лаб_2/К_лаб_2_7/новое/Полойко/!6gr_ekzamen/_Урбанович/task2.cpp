#include <iostream>
#include <math.h>

//Urbaovich

using namespace std;

int main () {
int a;
int zn;
int i=0;
int mas[10];

cout<<"input a"<<endl;
cin>>a;
int d=3;
if (a%d==0) {
	while(a!=0) {
		mas[i++]=pow(a%10, 3.0);
		a/=10;
		i=i-1;
		//for (int i=0;i<=mas[i];i++)
			


			while(i!=0) {
			cout<<mas[i]<<", ";
			i--;
			}
				
		cout<<mas[i]<<" ";
		}
	}
else 
	cout<<"nekratnoe chislo"<<endl;
}






//Urbanovich