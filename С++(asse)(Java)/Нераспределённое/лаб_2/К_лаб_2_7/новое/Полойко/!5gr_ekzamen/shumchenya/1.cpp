//Шумченя  5  группа
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
/*struct item
{
	 char* value;
	item* next;

};

void push (item* &head, char* a)
{	char*s=new  char[100];
	s=a;
	item* new_item=new item;
	new_item->next=head;
	new_item->value=s;
	head=new_item;
}

void view (item* &head)
{
	item* temp=head;
	while (temp!=NULL)
	{	
		cout<<(temp->value);
		temp=temp->next;
		cout<<endl;
	}
}*/


int main()
{
//item* head=NULL;
setlocale (LC_ALL,".1251");
ifstream in("input.txt");
ofstream fout("output.txt");

char a[1000];
char**f=new  char*[100];
int i=0; 
while(in.getline(a,1000))
	{

	if (strlen(a)>0)
{
	cout<<"исходная строка "<<a<<endl;
	char *del=new char[7]; 
	strcpy(del," .,;:!-"); 
	 char *d=new  char[100]; 
  		d=strtok(a,del);
		//cout<<f[i]<<endl;
		
		//push (head,d);
  	while (d!=NULL )
		{	f[i]=d;
		cout<<f[i]<<endl;
		i++;
		d=strtok(NULL,del);
		//push (head,d);
			
 		}
	
}
	}
int  r=i;
//view(head);
int m[255];
char v[100];
int j=0,y=0;

for(int i=0;i<256;i++)
m[i]=0;
for(int i=0;i<r;i++)
{	
	for(int j=0;j<sizeof(f[i])-1;j++)
	{v[j]=f[i][j];
		int t=v[j];
		m[t]++;
	}
}
/*for(int i=0;i<255;i++)
{	if(m[i]>0)
		{d[y]=m[i];
		y++;
		}	*/

for(int i=0;i<256;i++)
	{	if(m[i]>0)
			cout<<m[i]<<endl;
	}

}
