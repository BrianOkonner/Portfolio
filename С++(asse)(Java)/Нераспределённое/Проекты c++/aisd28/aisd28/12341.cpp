#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
 using namespace std;
 static int hop=0,hip=0,massi=-1,*mfs;
struct Tree
{
    int   val;
    Tree* left;
    Tree* right;
	int rp;
	int lp;
};
inline Tree* InsertNode(Tree* node, int val);
inline void  PrintNode(ostream& _out, const Tree* node);
//inline void bubble_srt(int *a,int n);
//inline void WalkZNode(Tree* node);
inline void WalkZ3Node(Tree* node,Tree* node2);
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
	Tree* tree = NULL,*tree2=NULL;
	setlocale(LC_ALL,".1251");
	long buf=0,rt;
	long *mfs;
	string s;
	int i=0;
	try
	{
		while(!inq.eof())
		{
			getline(inq,s);
			buf=stoi(s);
			if(i==0)
			{
				rt=buf;
			}
			i++;
			tree = InsertNode(tree, buf);
			if(i==1)
				tree->rp=-1;
		}
		mfs=new long[i];
		mfs[0]=-1;
		WalkZ3Node(tree,tree2);
		for(i=0;i<hop;i++)
			tree2=InsertNode(tree2,mfs[i]);
		PrintNode(outq, tree2);
	}
	catch(invalid_argument)
	{
		return 0;
	}
	/*{
		tree = DeleteNode(tree, rt);
		i=0;
		while(!inq.eof())
		{
			getline(inq,s);
			buf=stoi(s);
			if(i==0)
			{
				rt=buf;
			}
			i++;
			tree2 = InsertNode(tree2, buf);
		}
		tree2 = DeleteNode(tree2, rt);
		WalkZNode(tree);
		WalkZNode(tree2);
		WalkZ2Node(tree,tree2,i);
		if(i==0)
		{
			outq<<"NO";
			return 0;
		}
		else
		{
			outq<<"YES"<<endl;
			PrintNode(outq, tree);
			outq <<endl;
			PrintNode(outq, tree2);
			outq <<endl;
			return 0;
		}
	}*/
}
inline Tree* InsertNode(Tree* node, int val)
{
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
		_out <<node->val<<" ";
        PrintNode(_out, node->left);
        PrintNode(_out, node->right);
    }
}
/*inline void WalkZNode(Tree* node)
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
}*/
inline void WalkZ3Node(Tree* node,Tree* node2)
{
    if(node != NULL)
	{
        WalkZ3Node(node->left,node2);
        WalkZ3Node(node->right,node2);
		if(node->left==0)
			hip++;
		if(node->right==0)
			hip++;
		if(hip==2)
		{
			hip=0;
			node2=InsertNode(node2,node->val);
		}
		else
		{	
			hip=0;
			massi++;
			if(massi>hop-1)
				hop=massi+1;
			if(node->hp==-1)
				return;
			if(mfs[massi]!=-1)
			{
				node2=InsertNode(node2,mfs[massi]);
				mfs[massi]=node->val;
			}
		}
	}
}
/*inline void WalkZ4Node(Tree* node,Tree* node2)
{
    if(node != NULL)
	{
        WalkZNode(node->left);
        WalkZNode(node->right);
		if(node->left==0)
			node->lp=0;
		else
			node->lp=(node->left->lp+1);
		if(node->right==0)
		{
			if(node->lp==0)
				node2=InsertNode(node2,node->val);
			node->rp=0;
		}
		else
			node->rp=(node->right->rp+node->right->lp+1);
    }
}*/
/*inline void WalkZ2Node(Tree* node,Tree* node2,int& answ)
{
    if(node != NULL&&node2 != NULL)
	{
		if(node == NULL||node2 == NULL)
		{
			answ=0;
			return;
		}
		Tree* buf=node,*buf2=node2;
		while(buf != NULL&&buf2 != NULL)
		{
			if(buf->lp==buf2->rp&&buf2->lp==buf->rp)
			{
				buf=buf->left;
				buf2=buf2->right;
			}
			else
			{
				answ=0;
				return;
			}
		}
		buf=node;
		buf2=node2;
		while(buf != NULL&&buf2 != NULL)
		{
			if(buf->lp==buf2->rp&&buf2->lp==buf->rp)
			{
				buf=buf->right;
				buf2=buf2->left;
			}
			else
			{
				answ=0;
				return;
			}
		}
		answ=1;
	}
	else
	{
		answ=1;
	}
}*/
/*inline void ClearNode(Tree* node)
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
