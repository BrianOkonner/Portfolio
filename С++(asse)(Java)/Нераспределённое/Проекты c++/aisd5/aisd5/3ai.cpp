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
	queue <int> st,res;
	inq>>n>>m;
	k=new int*[n];   //Создание строк
	for (int i=0;i<n;i++)
		k[i]=new int[n];
	for(j=0;j<n;j++)
		for(i=0;i<n;i++)//проверить
			inq>>k[j][i];
	for(j=0;j<m;j++)
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
			y=res.front();
			res.pop();
			h=res.front();
			res.pop();
			if(k[y-1][h-1]==0)
			{
				res.push(y);
				res.push(h);
				break;
			}
			else
			{
				res.push(k[y-1][h-1]);
			}
		}
	}
	outq<<res.front();
	res.pop();
	while(!res.empty())
	{
		outq<<" "<<res.front();
		res.pop();
	}
	return 0;
}