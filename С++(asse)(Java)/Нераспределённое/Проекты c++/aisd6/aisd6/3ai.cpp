#include <fstream>
#include <cstdlib>
#include <algorithm> 
using namespace std;
//inline Tree* InsertNode(ifstream& in,Tree* node);
inline void  BinarySearchOut(int** mtr,int ndata,int nkey,int *key,int *data,ofstream& out);
int main(void)
{
	ifstream inq("стандартный ввод");
	ofstream outq("стандартный вывод");
	int a,c,*f,*g,**s;
	inq>>a;
	f=new int[a];
	for(int i=0;i<a;i++)
		inq>>f[i];
	inq>>c;
	g=new int[c];
	s=new int*[a];
	for(int i=0;i<a;i++)
		s[i]=new int[a];
	for(int i=0;i<c;i++)
		inq>>g[i];
	s=new int*[c];   //Создание строк
	for (int i=0;i<c;i++)
		s[i]=new int[c]; 
	BinarySearchOut(s,a,c,g,f,outq);
	return 0;
}
/*inline Tree* InsertNode(ifstream& in,Tree* node)
{
	node=new Tree();
	int q, *w, e, *r;
	in >> q;
	node->ndata = q;
	w = new int[q];
	for (int i = 0; i < q; i++)
	{
		in>>w[i];
	}
	node->data=w;
	in >> e;
	node->nkey = e;
	r = new int[e];
	for (int i = 0; i < e; i++)
	{
		in >> r[i];
	}
	node->key = r;
	return node;
}*/
inline void BinarySearchOut(int** mtr,int ndata,int nkey,int *key,int *data,ofstream& out)
{
	for (int j = 0; j <nkey; j++)
	{
		mtr[j][0]=(ndata+1)/2;
		if(ndata==1)
		{
			if(data[0]>key[j])
			{
				mtr[j][0]=0;
				mtr[j][1]=0;
				mtr[j][2]=0;
				continue;
			}
			if(data[0]<key[j])
			{
				mtr[j][0]=0;
				mtr[j][1]=1;
				mtr[j][2]=1;
				continue;
			}
			else
			{
				mtr[j][0]=1;
				mtr[j][1]=0;
				mtr[j][2]=1;
				continue;
			}
		}
		//mtr[j][0]=(2*(s.ndata+1))/4ddd;
		while(data[mtr[j][0]-1]!=key[j])
		{
			if(data[mtr[j][0]-1]<key[j])
				mtr[j][0]=mtr[j][0]/2+(2*(mtr[j][0]+1))/4;
			if(data[mtr[j][0]-1]==key[j])
			{
				mtr[j][0]=1;
				goto m;
			}
			else
				if(data[mtr[j][0]-1]>key[j])
					mtr[j][0]=(2*(mtr[j][0]+1))/4;
				if(data[mtr[j][0]-1]==key[j])
					{
						mtr[j][0]=1;
						goto m;
					}
			if(mtr[j][0]==1)
			{
				mtr[j][0]=0;
				mtr[j][1]=1;
				mtr[j][2]=1;
				break;
			}
			else
				if(mtr[j][0]==(ndata))
				{
					mtr[j][0]=0;
					mtr[j][1]=0;
					mtr[j][2]=0;
					break;;
				}
			m:
			if(mtr[j][0]==1)
			{
				mtr[j][1]=1;
				mtr[j][2]=2;
				continue;
			}
			if(mtr[j][0]==ndata)
			{
				mtr[j][1]=mtr[j][0]-1;
				mtr[j][2]=mtr[j][0]-1;
				mtr[j][0]=0;
				continue;
			}
			else
			{
				mtr[j][1]=mtr[j][0]-1;
				mtr[j][2]=mtr[j][0]-1;
				mtr[j][0]=mtr[j][0];
				continue;
			}
		}
		/*int o=0;
		mtr[j][1]=mtr[j][0]-1;
		while(s.data[mtr[j][0]+o-1]==s.key[j])
		{
			mtr[j][2]=mtr[j][0]+o-1;
			o++;
		}
		mtr[j][1]=mtr[j][0];
		if(mtr[j][0]!=0)
			mtr[j][0]=1;
	}
	*/
	}
	for (int j = 0; j < nkey-1; j++)
	{
		out<<mtr[j][0];
		for(int i=1;i<3;i++)
		{
			out<<" "<<mtr[j][i];
		}
		out<<endl;
	}
	out<<mtr[nkey-1][0];
	out<<" "<<mtr[nkey-1][1];
	out<<" "<<mtr[nkey-1][2];
}