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
Tree* DeleteNode(Tree* node, int ch)
{
    /*Если удаляемый элемент находится в корне текущего поддерева и имеет два дочерних узла,
    то нужно заменить его минимальным элементом из правого поддерева
    и рекурсивно удалить минимальный элемент из правого поддерева.*/
 
    if (node == NULL)
        return node;
 
    if (ch < node->data)
    {
        node->left = DeleteNode(node->left, ch);
    }
    else if (ch > node->data)
    {
        node->right = DeleteNode(node->right, ch);
    }
    else if (node->left != NULL && node->right != NULL)
    {
        node->data = Minimum(node->right)->data;
        node->right = DeleteNode(node, node->right->data);
    }
    else if (node->left != NULL)
    {
        node = node->left;
    }
    else
    {
        node = node->right;
    }
 
    return node;
}
void main()
{
	ifstream inq("232.txt");
	ofstream outq("output.txt");
	Tree tr;
	setlocale(LC_ALL,".1251");
	long buf=0,o=0,i=0;
	char h[12];
	inq>>o;
	inq>>h;
	while(!inq.eof())
	{
		inq>>buf;
		tr.push(buf);
	}
	tr.outleftstraighttr(&outq,&tr,o);
}