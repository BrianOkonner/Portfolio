// функции

#include <iostream>
using namespace std;

int stepen(int ch)
{
	int rezult=1;
	int n=3;
	
	while (n>0)
	{
		rezult*=ch;
		n--;
	}
	
	return rezult;


}
void sort(int m[],int c)
{
 for (int i = 0;i < c;i++)
  {
   int min = m[i];
   for (int j = i;j < c;j++)
    {
     if (m[j] < min)
      {
       int s = m[j];
       m[j] = min;
       min = s;
      }
    }
   m[i] = min;
  }
}
