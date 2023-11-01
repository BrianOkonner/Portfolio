#include <fstream>
#include <cstdlib>
 using namespace std;
int main(void)
{
	ifstream inq("input.txt");
	ofstream outq("output.txt");
	setlocale(LC_ALL,".1251");
	int a,*b,c,*d,buf;
	int y,i=1;
	inq>>a;
	b=new int[a];
	d=new int[a];
	if(a>=1)
		inq>>(d[0]);
	else
	{
		outq<<-1;
		return 0;
	}
	if(a>=2)
		inq>>(d[1]);
	else
	{
		outq<<d[0];
		return 0;
	}
	b[0]=d[0];
	if(a>=3)
		inq>>b[2];
	else
	{
		outq<<-1;
		return 0;
	}
	if(a>=4)
		inq>>b[3];
	else
	{
		outq<<b[2]+b[0];
		return 0;
	}
	d[2]=b[2]+d[0];
	d[3]=b[3]+d[0];
	if(a>=5)
		inq>>b[4];
	else
	{
		buf=b[0]+b[3];
		outq<<buf;
		return 0;
	}
	d[4]=b[4]+d[2];
	if(a==1||a==2)
	{
		outq<<-1;
		return 0;
	}
	for(int i=5;i<a;i+=1)
	{
		inq>>b[i];
		d[i]=max(d[i-2]+b[i],d[i-3]+b[i]);
	}
	outq<<d[a-1];
	return 0;
}
