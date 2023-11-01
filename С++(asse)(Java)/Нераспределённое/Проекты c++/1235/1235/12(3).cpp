#include <iostream>
#include <fstream>
using namespace std;
class Tree
{
public:
	long *data;
	Tree *right;
	Tree *left;
	Tree *root;
	Tree()
	{
		data=0;
		root=0;
		right=0;
		left=0;
	}
};
inline void push(long *dat,Tree *tr)
{
	if(tr->root==0)
	{
		tr->root=new Tree();
		tr->root->data=dat;
	}
	else
	{
		int i=0;
		Tree *cur=tr->root;
		while(i==0)
		{
			if(*dat<*(cur->data))
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
				if(*dat>*(cur->data))
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
inline void outleftstraight(ofstream *out,Tree *cur)
{
	if(cur==0)
		return;
	*out<<(*(cur->data))<<endl;
	outleftstraight(out,cur->left);
	outleftstraight(out,cur->right);
}
inline void outleftstraighttr(ofstream *out,Tree *tr2)
{
	outleftstraight(out,tr2->root);
}
void main()
{
	ifstream inq("232.txt");
	ofstream outq("Queue.txt");
	Tree tr;
	setlocale(LC_ALL,".1251");
	long *buf,o,i=0,n=0;
	while(!inq.eof())
	{
		inq>>o;
		n++;
	}
	inq.clear();
	inq.seekg(ios::beg);
	buf=new long[n-1];
	for(i=0;i<n-1;i++)
	{
		inq>>buf[i];
		push(&buf[i],&tr);
	}
	outleftstraighttr(&outq,&tr);
	inq.close();
	outq.close();
}