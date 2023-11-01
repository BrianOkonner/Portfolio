#include <fstream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
int main(void)
{
	ifstream inq("input.in");
	ofstream outq("output.out");
	setlocale(LC_ALL,".1251");
	unsigned long long a,b,c,buf=1;
	int **k,n,m,tr,i,j;
	stack <int> res;
	queue <int> st;
	inq>>n>>m;
	k=new int*[n];   //Создание строк
	for (int i=0;i<n;i++)
		k[i]=new int[n];
	for(j=0;j<n;j++)
		for(i=0;i<n;i++)//проверить*
			inq>>k[j][i];
	for(j=0;j<n;j++)
	{
		inq>>i;
		st.push(i);
	}
	res.push(st.front());
	st.pop();
	while(!st.empty())
	{
		res.push(st.front());
		st.pop();
		while(res.size()>=2)
		{
			int y,h;
			y=res.top();
			res.pop();
			h=res.top();
			res.pop();
			if(k[y-1][h-1]==0)
			{
				res.push(h);
				res.push(y);
				break;
			}
			else
			{
				res.push(k[y-1][h-1]);
			}
		}
	}
	outq<<res.top();
	res.pop();
	while(!res.empty())
	{
		outq<<" "<<res.top();
		res.pop();
	}
	return 0;
}