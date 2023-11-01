//Бовкунович Роман 5 группа
//10 вариант
// не успел доделать, сложное задание

#include <windows.h>
#include <iostream.>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

using namespace std;

class   CircularQueue 
{  private: 

   struct CQNode 
   { 
      int value; 
      CQNode * LeftNode; 
      CQNode * RightNode; 
   } *FirstNode,*LastNode, *Current; 
   int size;
public: 
   CircularQueue() 
   { 
      Current=FirstNode=LastNode=NULL; 
	  size=0;
   } 
   void InsertNode(int buff) 
   { 
      if(!FirstNode) 
      { 
         FirstNode=new CQNode; 
         FirstNode->value=buff; 
         FirstNode->LeftNode=FirstNode->RightNode=NULL; 
         Current=FirstNode; 
      } else 
         if(!LastNode) 
         { 
            LastNode=new CQNode; 
            LastNode->value=buff; 
            LastNode->LeftNode=LastNode->RightNode=FirstNode; 
            FirstNode->LeftNode=FirstNode->RightNode=LastNode; 
         } else 
         { 
            CQNode *current; 
            LastNode->RightNode=new CQNode; 
            current=LastNode->RightNode; 
            current->value=buff; 
            current->LeftNode=LastNode; 
            current->RightNode=FirstNode; 
            LastNode=current; 
         } 
		 size ++;
   } 
   int GetNext() 
   { 
      if(Current) 
      { 
         int temp=Current->value; 
         if(Current->RightNode) Current=Current->RightNode; 
         return temp; 
      }
	  size --;
   } 
   int ssize()
   {
	   return size;
   }
   
};
void main() 
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
    Queue a;
	int b,d,e,f;
	while (!fin.eof()) 
	{
		fin >> b;
		a.push(b);
	}
	int k = a.size();
	if (k<3)
	{
		goto Q;
	}
	b=a.GetNext();
	e=a.GetNext();
	f=a.GetNext();
	for (int i=0; i <k; i++)
	{
	}
Q:
}
