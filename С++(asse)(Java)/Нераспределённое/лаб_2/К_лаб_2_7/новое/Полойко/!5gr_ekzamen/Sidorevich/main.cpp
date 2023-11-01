#include <fstream>
using namespace std;
char sep[]=" .,-:;!";

int us=0;
struct list{
	char *s;
	int nomer;
	int len;
	int code;
	int nomersl;
	list* next;
};
list* begin;
void add(char*  c)
{
	list* r=begin;
	if (!r)
	{
		r=new list;
	r->next=NULL;
	r->nomer=us;
	us++;
	char s=r->s[0];
	int len=0;
	int q=0;
	int n=0;
	r->len=len;
	r->code=0;
	r->nomersl=0;
	r->nomersl=3;
	r->s=new char[strlen(c)+1];
	strcpy(r->s,c);
	r->code=(int)r->s[q];
	}
	else
	{
	while (r->next)
		r=r->next;
	r->next=new list;
	r->next->next=NULL;
	r->nomer=us;
	us++;
	r->next->len=2;
	r->next->nomersl=3;
	r->next->s=new char[strlen(c)+1];
	strcpy(r->next->s,c);
		r->next->code=(int)r->next->s[0];
	}
}
void breakup(char* s)
{
	char t[1000];
	strcpy(t,s);
	char *z=strtok(t,sep);
	add(z);


	while (z!=NULL)
	{
		z=strtok(NULL,sep);
		if (z==NULL)
			return;
		add(z);
	}
}




int main()
{
	char str[1000][81];
	begin=NULL;
	ifstream in("Input.txt");
	ofstream out("Result1.txt");
	int i=0;
	while(!in.eof())
	{
		in>>str[i];
		i++;
	}
	i=1;
	list *r=begin;
	while (r->next)
	{
		r=r->next;
		i++;
	}

	int **m=new int*[3];
	int n=i;
	for (i=0; i<3; i++)
		m[i]=new int[n];
	r=begin;
	i=0;
	while (r->next)
	{

		out<<"1\t"<<r->s<<"\t"<<r->code<<"\t"<<r->len<<"\t"<<r->nomer<<endl;
		m[0][i]=r->nomer;
		m[1][i]=r->len;
		m[2][i]=r->nomersl;
		i++;
	}
	out.close();
	out.open("Result2.txt");
}







