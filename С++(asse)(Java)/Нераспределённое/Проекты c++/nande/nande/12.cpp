#include <iostream>
#include <fstream>
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
	void push(long *dat)
	{
		if(root=0)
		{
			root=new Tree();
			root->data=*dat;
		}
		else
		{
			Tree *cur=root;
			if(*dat<cur->data)
			{
				if(cur->data==0)
				{
					cur->left->data=*dat;
				}
				else
				{
					cur=cur->left;
				}
			}
			if(*dat>cur->data)
			{
				if(cur->data==0)
				{
					cur->right->data=*dat;
				}
				else
				{
					cur=cur->right;
				}
			}
		}
	}
};
using namespace std;
void main()
{
	ifstream inq("Input.txt");
	ofstream outq("Queue.txt");
	Tree tr;
	setlocale(LC_ALL,".1251");
	long *buf,i=0;
	while(!inq.eof())
	{
		buf=new long();
		inq>>*buf;
		tr.push(buf);
	}
}