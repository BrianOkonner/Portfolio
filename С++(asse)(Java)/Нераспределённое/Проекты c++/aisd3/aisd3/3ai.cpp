#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
void binary_sorting(int *Array, int b, int N)
{
       int left = b; int right = N;
       int oporniy = *(Array + (left + right) / 2);
       while (left <= right)
       {
             while (*(Array + left) > oporniy)
                    left++;
             while (*(Array + right) < oporniy)
                    right--;
             if (left <= right)
             {
                    int temp = *(Array + left);
                    *(Array + left) = *(Array + right);
                    *(Array + right) = temp;
                    left++;
                    right--;
             }
       }
       if (b < right)
             binary_sorting(Array, b, right);
       if (N > left)
             binary_sorting(Array, left, N);
}
int main(void)
{
	ifstream inq("input.txt");
	ofstream outq("output.txt");
	setlocale(LC_ALL,".1251");
	void *y;
	int a,b,c,i=0,j;
	inq>>a;
	inq>>b;
	y=malloc(a*4);
	int *y1=(int*)y;
	for(j=0;j<a;j++)
		y1[j]=0;
	for(j=0;j<b;j++)
	{
		inq>>i;
		inq>>c;
		y1[i-1]=y1[i-1]+1;
		y1[c-1]=1+y1[c-1];
	}
	binary_sorting(y1,0,a);
	outq<<y1[0];
	for(j=1;j<a;j++)
		outq<<" "<<y1[j];
	delete y;
	return 0;
}
