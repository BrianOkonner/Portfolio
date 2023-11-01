#include <iostream>
#include <fstream>
using namespace std;
class Tree
{
	long data;
	Tree *right;
	Tree *left;
	Tree *root;
public:
	Tree()
	{
		data=0;
		root=0;
		right=0;
		left=0;
	}
	void push(long dat)
	{
		if(root==0)
		{
			root=new Tree();
			root->data=dat;
		}
		else
		{
			int i=0;
			Tree *cur=root;
			while(i==0)
			{
				if(dat<(cur->data))
				{
					if(cur->left==0)
					{
						cur->left=new Tree();
						cur->left->data=dat;
						i=1;
					}
					else
					{
						cur=cur->left;
					}
				}
				else
				{
					if(dat>(cur->data))
					{
						if(cur->right==0)
						{
							cur->right=new Tree();
							cur->right->data=dat;
							i=1;
						}
						else
						{
							cur=cur->right;
						}				
					}
					else
					{
						i=1;
					}
				}
			}
		}
	}
	void outleftstraighttr(ofstream *out,Tree *tr2)
	{
		(*this).outleftstraight(out,tr2->root);
	}
	void outleftstraight(ofstream *out,Tree *cur)
	{
		if(cur==0)
			return;
		*out<<((cur->data))<<endl;
		outleftstraight(out,cur->left);
		outleftstraight(out,cur->right);
	}
};
void main()
{
	ifstream inq("232.txt");
	ofstream outq("output.txt");
	Tree tr;
	setlocale(LC_ALL,".1251");
	long buf=0,i=0;
	while(!inq.eof())
	{
		inq>>buf;
		tr.push(buf);
	}
	tr.outleftstraighttr(&outq,&tr);
}