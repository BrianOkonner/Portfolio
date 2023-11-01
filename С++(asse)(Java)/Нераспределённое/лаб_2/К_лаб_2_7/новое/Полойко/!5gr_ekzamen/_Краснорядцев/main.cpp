//Краснорядцев 7группа;
#include <iostream>
#include <stdio.h>
using namespace std;
const int razmer=500;
char sh[]="Номер слова    Слово       Символ  Длинна  Номер символа";
int n;
struct Word
{
	char *str;
};
Word word[100];
#define SWAP(A, B) {A = A ^ B; B = A ^ B; A = A ^ B;}
void bubblesortB(int *a, int n)
{
  int i, j,A=0,B=0,k,e;
  
  for (i = n - 1; i > 0; i--)
  {
    for (j=0;j<i;j++)
    {
		k=a[j];
		e=a[j+1];
		A=k%2;
		while (k>0)
		{
			if (k%2==1)
				A++;
			k=k/2;
		}
		while (e>0)
		{
			if (e%2==1)
				B++;
			e=e/2;
		}
		if (A>B) 
        SWAP(a[j],a[j+1]);
    }
  }
}
	
	void Words (char *Str)
{
	char razdel[]=" .,-:;!?";
	char *token;
	int *matr;
	matr=(int*)malloc(3*sizeof(int));
	int i=0;
	token=strtok(Str,razdel);
    while (token!= NULL)
    {
		word[i].str=token;
		token=strtok(NULL,razdel);
		i++;
	}
	n=i;
	int **MATR;
	MATR=new int*[3];
	for(int i=0;i<3;i++)
		MATR[i]=new int[n];
	char *character;
	character=new char[n];
	int T,B=0,C=0,A=0,max=0;
	FILE *out1;
	if ((out1=fopen("Result1.txt","a"))!=NULL) 
	{
		for(int i=0;i<n;i+=2)
		{
			T=strlen(word[i].str);
			for(int j=0;j<T-1;j++)
			{
				if (word[i].str[j]==word[i].str[j+1])
					A++;
				if (A>max)
					max=A;
				if(word[i].str[j]!=word[i].str[j+1])
					A=0;
			}
			if (max==0)
			{
				max=1;
				i=1;
				B=1;
			}
			cout<<max<<" ";
			B=max;
			MATR[0][i]=i;
			MATR[1][i]=max;
			MATR[2][i]=B;
			character[i]=word[i].str[B];
			A=0;
			max=0;
			
		}
	/*		max=0;
			fputs(word[i].str,out);
			fprintf(out,"-");
			fputs (word[i+1].str,out);
			
		}
*/}
	/*for (int i=0;i<n;i++)
		cout<<word[i].str<<"  ";
	*/
	}



void main()
{
setlocale(LC_ALL,".1251");
	FILE *out1;
	out1=fopen("Result1.txt","w"); 
	fclose(out1);
	FILE *in;
	char *Str;
	const int razmer=500; 
	
	Str=(char*)malloc(razmer*sizeof(char));
	if ((in = fopen("Input.txt", "r") ) != NULL) 
	{
          if (feof(in)) return;
		  while(!feof(in))
		  { 
			  fgets(Str,razmer,in);
			  Words(Str);
			  
		  }
		  fclose(in);
	}
	else
	{
		cout<<"Error"<<"\n";
	}
	
	
}
	
	
	