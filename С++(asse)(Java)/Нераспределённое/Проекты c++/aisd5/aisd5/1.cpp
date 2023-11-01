#include <fstream>
#include <cstdlib>
using namespace std;
struct Tree
{
	int * data;
	int* key;
	int nkey;
	int ndata;
};
inline Tree* InsertNode(ifstream& in,Tree* node);
inline void  BinarySearchOut(int** mtr,Tree s,ofstream& out);
int main(void)
{
	ifstream inq("стандартный ввод");
	ofstream outq("стандартный вывод");
	Tree* tree=0;
	tree=InsertNode(inq,tree);
	setlocale(LC_ALL, ".1251");
	int **mtr;
	mtr = new int*[tree->nkey];
	for(int i=0;i<tree->nkey;i++)
		mtr[i] = new int[3];
	BinarySearchOut(mtr,*tree,outq);
	return 0;
}
inline Tree* InsertNode(ifstream& in,Tree* node)
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
}
inline void BinarySearchOut(int** mtr,Tree s,ofstream& out)
{
	for (int j = 0; j < s.nkey; j++)
	{
		mtr[j][0]=(2*(s.ndata+1))/4;
		if(s.ndata==1)
			if(s.data[mtr[j][0]-1]<s.key[j])
			{
				mtr[j][0]=mtr[j][0]+1;
				goto m;
			}
		//mtr[j][0]=(2*(s.ndata+1))/4;
		while(s.data[mtr[j][0]-1]!=s.key[j])
		{
			if(s.data[mtr[j][0]-1]<s.key[j])
				mtr[j][0]=mtr[j][0]/2+(2*(mtr[j][0]+1))/4;
			else
				if(s.data[mtr[j][0]-1]>s.key[j])
					mtr[j][0]=(2*(mtr[j][0]+1))/4;
			if(mtr[j][0]==0)
				break;
			else
				if(mtr[j][0]==(s.ndata))
					break;
		}
		m:
		if(mtr[j][0]==0)
		{
			mtr[j][1]=mtr[j][0];
			mtr[j][2]=mtr[j][0];
			continue;
		}
		if(mtr[j][0]==s.ndata+1)
		{
			mtr[j][1]=mtr[j][0]-1;
			mtr[j][2]=mtr[j][0]-1;
			mtr[j][0]=0;
			continue;
		}
		int o=0;
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
	for (int j = 0; j < s.nkey; j++)
	{
		for(int i=0;i<3;i++)
		{
			int g=mtr[j][i];
			out<<mtr[j][i]<<" ";
		}
		out<<endl;
	}
}
