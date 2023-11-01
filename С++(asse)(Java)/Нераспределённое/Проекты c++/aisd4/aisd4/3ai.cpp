#include <fstream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
int main(void)
{
	ifstream inq("input.txt");
	ofstream outq("output.txt");
	setlocale(LC_ALL,".1251");
	int n,*k;
	double f;
	stack <int> st;
	inq>>n;
	k=new int[n];   //Создание строк
	for (int i=0;i<n;i++)
	{
		inq>>f>>f>>k[i];
		if(st.empty()||st.top()!=k[i])
			st.push(k[i]);
		else
			if(st.top()==k[i]||st.empty())
				st.pop();
	}
	if(st.empty())
		outq<<"Yes";
	else
		outq<<"No";
	return 0;
}