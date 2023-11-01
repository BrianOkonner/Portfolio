#include <iostream>
#include <fstream>
using namespace std;
struct Tree 
{
	long *data;
	long *key;
};
inline Tree* InsertNode(ofstream *out);
inline void  PrintNode(ostream& _out, const Tree* node);
inline Tree* DeleteNode(Tree* node, int val)
{
    if(node == NULL)
        return node;
    if(val == node->val)
	{
        Tree* tmp;
        if(node->left == NULL)
            tmp = node->right;
		else
		{
			if(node->right == NULL)
				tmp = node->left;
			else 
			{
				Tree* ptr = node->right;
				if(ptr->left == NULL)
				{
					ptr->left = node->left;
					tmp = ptr;
				} 
				else
				{
					Tree* pmin = ptr->left;
					while(pmin->left != NULL)
					{
						ptr  = pmin;
						pmin = ptr->left;
					}
					ptr->left   = pmin->right;
					pmin->left  = node->left;
					pmin->right = node->right;
					tmp = pmin;
				}
			}
			delete node;
			return tmp;
		}
		delete node;
		return tmp;
	}
	else
		if(val < node->val)
			node->left  = DeleteNode(node->left, val);
		else
			node->right = DeleteNode(node->right, val);
    return node;
} 
int main(void)
{
	ifstream inq("input.txt");
	ofstream outq("output.txt");
    Tree* tree = NULL;
	setlocale(LC_ALL,".1251");
	long buf=0,o=0,i=0;
	inq>>o;
	while(!inq.eof())
	{
		inq>>buf;
		tree = InsertNode(tree, buf);
	}
	tree = DeleteNode(tree, o);
    PrintNode(outq, tree);
    return 0;
}
inline Tree* InsertNode(ifstream *in)
{
	long q,*w,e,*r;
	*in>>q;
	w=new long[q];
	*in>>e;
	r=new long[e];
}
inline void PrintNode(ostream& _out, const Tree* node)
{
    if(node != NULL)
	{
        _out <<node->val<<endl;
        PrintNode(_out, node->left); 
        PrintNode(_out, node->right);
    }
}
inline void ClearNode(Tree* node)
{
    if(node != NULL)
	{
        if(node->left != NULL)
            ClearNode(node->left);
        if(node->right != NULL)
            ClearNode(node->right);
        delete node;
    }
}*/