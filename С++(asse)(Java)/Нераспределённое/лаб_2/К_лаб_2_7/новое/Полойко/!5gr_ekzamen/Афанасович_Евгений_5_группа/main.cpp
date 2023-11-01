#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct slovechko
{
	char slovo[30];
	slovechko *next;
};

bool proverka_na_razd(char ch)
{
	char mass[7]={' ' , ',' , ';' , ':' , '!' ,'-','.'};
	int i;
	i=0;
	bool induk;
	induk=true;

	while(i<7 && induk)
	{
		if(ch==mass[i])
		{
			induk=false;
		}
		i=i+1;
	
	}
	return induk;
}




slovechko* razdelenie()
{
	ifstream in("input.txt");
	int i;
	char str[30];
	char ch;
	slovechko *head,*current,*prev;
	in.get(ch);
	i=0;
	while(in && proverka_na_razd(ch))
	{
		str[i]=ch;
		in.get(ch);
		i=i+1;
		
	}
	str[i]='\0';

	head=new slovechko;
	strcpy_s(head->slovo,str);
	head->next=NULL;
	prev=head;

	in.get(ch);
	while(in)
	{
		
		i=0;
		while(in && proverka_na_razd(ch))
		{
			str[i]=ch;
			in.get(ch);
			i=i+1;
			
		}
		str[i]='\0';

		current=new slovechko;
		strcpy_s(current->slovo,str);
		current->next=NULL;
		prev->next=current;
		prev=current;
		in.get(ch);
		
		
	}
	return head;

}

void podschet(char str[30],int nomer)
{
	int massiv[256];
	int i,kod,kod_2;
	i=0;
	while(i<256)
	{
		massiv[i]=0;
		i=i+1;
	}

	int j,k;
	char ch;


	ch=str[0];
	i=0;
	k=1;
	int u;
	

	
	while(i<30)
	{
		
	kod_2=(int)ch;
	kod=(int)str[i];


	
	if(kod==kod_2)
	{
		k=k+1;
	}
	else
	{
		
		if(massiv[kod_2]<k)
		{
			massiv[kod_2]=k;
			cout<<massiv[kod_2]<<" "<<kod_2<<endl;
		}
		k=1;
	}

	ch=str[i];
	i=i+1;
	
	}



}



void main()
{
    slovechko *head,*current;
	head=razdelenie();	
	
	
	int i;
	i=0;
	current=head;
	while(current!=NULL)
	{
		cout<<current->slovo<<endl;//показывает то,что считано с файла
		podschet(current->slovo,i);
		current=current->next;
		i=i+1;
	}


	
}