#include <fstream>
#include <cstdlib>
 using namespace std;
struct Tree
{
    int   val;
    Tree* left;
    Tree* right;
	int lp;
	int rp;
};
inline Tree* InsertNode(Tree* node, int val);
inline void  PrintNode(ostream& _out, const Tree* node);
inline void bubble_srt(int *a,int n);
inline void WalkZNode(Tree* node);
inline void WalkZ2Node(Tree* node,int kz[],int *i);
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
	ifstream inq("tst.in");
	ofstream outq("tst.out");
    Tree* tree = NULL;
	setlocale(LC_ALL,".1251");
	long buf=0;
	int i=0,*kz;
	while(!inq.eof())
	{
		inq>>buf;
		i++;
		tree = InsertNode(tree, buf);
	}
	kz=new int[i+3];
	i=0;
	WalkZNode(tree);
	WalkZ2Node(tree,kz,&i);
	if(i%2==0);
	else
		tree = DeleteNode(tree, kz[i/2]);
    PrintNode(outq, tree);
    return 0;
}
inline Tree* InsertNode(Tree* node, int val){
    if(node == NULL)
	{
        node = new Tree();
        if(node != NULL)
		{
            node->val  = val;
            node->left = node->right = NULL;
        }
        return node;
    }
    if(val < node->val)
        node->left  = InsertNode(node->left, val);
    if(val > node->val)
        node->right = InsertNode(node->right, val);
    return node;
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
inline void WalkZNode(Tree* node)
{
    if(node != NULL)
	{
        WalkZNode(node->left);
        WalkZNode(node->right);
		if(node->left==0)
			node->lp=0;
		else
			node->lp=(node->left->lp+node->left->rp+1);
		if(node->right==0)
			node->rp=0;
		else
			node->rp=(node->right->rp+node->right->lp+1);
    }
}
inline void WalkZ2Node(Tree* node,int kz[],int *i)
{
    if(node != NULL)
	{
        WalkZ2Node(node->left,kz,i);
		if(abs((node->rp)-(node->lp))==1)
		{
			kz[*i]=node->val;
			(*i)++;
		}
        WalkZ2Node(node->right,kz,i);
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
}