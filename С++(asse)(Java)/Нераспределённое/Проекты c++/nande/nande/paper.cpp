#include <fstream>
#include <iostream>
#include "ArrayStack.h"
int main()
{
	ifstream in("inputpaper.txt");
	ofstrean out("outpaper.txt");
	ArrayStack ox(100), oy(100);
	int j,i,n,m,**pap,x,y,k=0;
	in>>n>>m;
	pap=new int*[n];
	for (i=0;i<n;i++)
		pap[i]=new int[m];
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++) 
		{
			in>>pap[i][j];
			out<<setw(4)<<pap[i][j] << " ";
		}
		out<<endl;
	}
	for (i=0;i<n;i++)
		for (j=0;j<m;j++) 
			if(pap[i][j]==0)
			{
				ox.push(i);
				oy.push(j);
				k++;
				if(pap[i+1][j]==0)
					pap[i+1][j]=1;
				if(pap[i][j+1]==0)
					pap[i][j+1]=1;
			}
