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
inline int WalkZNode(Tree* node,int kz[],int *i);
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
	ifstream inq("in.txt");
	ofstream outq("out.txt");
    Tree* tree = NULL;
	setlocale(LC_ALL,".1251");
	long buf=0;
	int i=0,kz[100];
	while(!inq.eof())
	{
		inq>>buf;
		tree = InsertNode(tree, buf);
	}
	i=WalkZNode(tree,kz,&i);
	bubble_srt(kz,i+1);
	if(i%2==0);
	else
		tree = DeleteNode(tree, kz[i/2+1]);
    PrintNode(outq, tree);
    return 0;
}
inline void change(int *a,int *b)
{
	*a=(*b)+(*a);
	*b=(*a)-(*b);
	*a=(*a)-(*b);
}
inline void bubble_srt(int *a,int n)//Сортировка улучшенным пузырьком
{
	int i,j,d=0,t=1;
	i=1;
	while(i<=n && t!=0)
    {
		t=0;
		for (j=0;j<n-1;j++)
		  if (a[j]>a[j+1])
		  {
			change(&a[j],&a[j+1]);
		    t=1;
		  }
    i++;
	}
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
inline int WalkZNode(Tree* node,int kz[],int *i)
{
    if(node != NULL)
	{
        WalkZNode(node->left,kz,i);
        WalkZNode(node->right,kz,i);
		if(node->left==0)
			node->lp=0;
		else
			node->lp=(node->left->lp+node->left->rp+1);
		if(node->right==0)
			node->rp=0;
		else
			node->rp=(node->right->rp+node->right->lp+1);
		if(abs((node->rp)-(node->lp))==1)
		{
			kz[*i]=node->val;
			(*i)++;
		}
    }
	else
		return *i;
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
