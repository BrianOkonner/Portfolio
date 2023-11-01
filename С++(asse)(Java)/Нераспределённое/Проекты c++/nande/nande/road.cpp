#include <fstream>
#include <iostream>
#include "ArrayStack.h"
int main()
{
	ifstream in("inputroad.txt");
	ofstrean out("outroad.txt");
	ArrayStack ox(100), oy(100);
	int j,i,n,m,**rd,x1,y1,x2,y2,k=0;
	in>>n>>m;
	rd=new int*[n];
	for (i=0;i<n;i++)
		rd[i]=new int[m];
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++) 
		{
			in>>rd[i][j];
			out<<setw(4)<<rd[i][j] << " ";
		}
		out<<endl;
	}
	in>>x1;
	in>>y1;
	in>>x2;
	in>>y2;
