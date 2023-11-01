#include <iostream>
#include <fstream>
using namespace std;
class Tree
{
public:
	double *data;
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
inline void push(double *dat,Tree *tr)
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
inline void outleftstraight(ofstream *out,Tree *cur,double *dat)
{
	if(cur==0)
		return;
	if(*(cur->data)==*dat)
	{
		delcur();
	}
	*out<<(*(cur->data))<<endl;
	outleftstraight(out,cur->left,dat);
	outleftstraight(out,cur->right,dat);
}
inline void outleftstraighttr(ofstream *out,Tree *tr2,double *dat)
{
	outleftstraight(out,tr2->root,dat);
}
void main()
{
	ifstream inq("232.txt");
	ofstream outq("Queue.txt");
	Tree tr;
	setlocale(LC_ALL,".1251");
	double *buf,o,p,i=0,n=0;
	inq>>o;
	inq>>p;
	while(!inq.eof())
	{
		buf=new double(0.4);
		inq>>*buf;
		if(*buf==0.4)
			break;
		push(buf,&tr);
	}
	outleftstraighttr(&outq,&tr,&o);
	inq.close();
	outq.close();
}
