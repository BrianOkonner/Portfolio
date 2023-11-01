//konovalov dimitry 5 group 
#include <fstream>
#include <cstring>

extern "C" void cmp_asm (int a, int b ,int c);


using namespace std;

const int N =100;
const char separator [10]=" -,.;:!\n";
ifstream in ("input.txt"); ofstream out ("result1.txt"); ofstream out2 ("result2.txt");
char instr [N];
char word[N];


bool find_word (char *st,char *word,int &newpos)
{
	int pos=0;
	while (st[pos]!='\0' && strchr (separator,st[pos])!=NULL) ++pos;
	if (st[pos]=='\0') return false;

	int start=0;
	while (st[pos]!='\0' && strchr (separator,st[pos])==NULL) word[start++]=st[pos++];
	word[start]='\0';
	newpos=pos;
	return true;
}
struct elem
{
	char word [100];
	char symbol;
	int number_of_symbol;
	int number;
	elem *pred;
};

class steck
{
private:
	int sz;
public:
	elem *head;

	steck () { head=NULL;}
	int size ()
	{
		return sz;
	}

	void insert (char *word)
	{
		elem *nw= new elem;
		for (int i=0; i<=int(strlen (word)); ++i) nw->word[i]=word[i];
		nw->pred=head;
		head=nw;
		++sz;
		
		head->number=1;
		head->number_of_symbol=1;
		head->symbol=word[0];
		char new_sumb=word[0]; int new_num=1,new_of_sym=1;
		for (int i=1; i<=int(strlen (word)); ++i)
		{
			if (head->number<new_num)
			{
				head->number=new_num;
				head->number_of_symbol=new_of_sym;
				head->symbol=new_sumb;
			}
			if (word[i]==new_sumb)
			{
				++new_num;
			}
			else
			{
				new_sumb=word[i];
				new_num=1;
				new_of_sym=i+1;
			}
		}
	}
	void write (elem *head)
	{
		out <<"номер слова  |  Слово  |   Символ   |  Длина   |   Номер символа" << endl;
		int i=1;
		char sep[100]="       ";
		while (head!=NULL) 
		{
			out<< i << sep << head->word << sep << head->symbol << sep << head->number << sep << head->number_of_symbol << endl; 
			head=head->pred;
			++i;
		}
	}
};
int **matr;

void create_matr (int **matr,steck stk)
{
	elem *i=stk.head;
	int k=0;
	while (i!=NULL)
	{
		matr[k][0]=i->symbol;
		matr[k][1]=i->number;
		matr[k++][2]=i->number_of_symbol;
		i=i->pred;
	}
}
bool cmp (int a, int b)
{
	int ak=0,bk=0;
	while (a>0 || b>0)
	{
		ak+=a%2;
		bk+=b%2;
		a=a/2;
		b=b/2;
	}
	return true;
 }

void swap (int & a, int &b)
{
	int m=a;
	a=b;
	b=m;
}

void sort (int **matr,int n)
{
	for (int i=0; i<n; ++i)
		for (int j=n-2; j>=i; --j)
			if (cmp (matr[j+1][1],matr[j][1])) 
				swap (matr[j+1][1],matr[j][1]);
}

steck words;
int newpos;
char *a;

int main ()
{

	while (in.getline (instr,N))
	{
		a=instr;
		while (find_word (a,word,newpos)) 
		{
			words.insert (word);
			a=a+newpos;

		}
	}


	words.write (words.head);


	/* next */

	matr= new int * [words.size()+2];
	for (int i=0; i<words.size(); ++i)
		matr[i]= new int [3];

	create_matr (matr,words);
	sort (matr,words.size());

	out2 << "номер слова | Символ | Длина | Номер | символа" << endl;
	for (int i=0; i <words.size(); ++i) 
	{
		out2 << i+1 << " " << char (matr[i][0]) << " " << matr[i][1] << " " << matr[i][2] << endl;
	}

/*
	g=1; a=3; b=2;
	cmp_asm (a,b,g);
*/

	return 0;
}