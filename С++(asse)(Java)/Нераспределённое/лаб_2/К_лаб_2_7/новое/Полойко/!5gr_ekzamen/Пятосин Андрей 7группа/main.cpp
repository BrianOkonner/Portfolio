//Пятосин Андрей 7группа
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

using namespace std;

int Count ( int n ) // количество цифр числа
{
	int c = 1;
	while ( n > 9 )
	{
		n = ( n - n % 10 ) / 10;
		c ++;
	}
return c;
}


struct Node	//стек
{
	int d;
	Node *p;
};

Node* head=0;

Node * first(int d)	//создание первого элемента
{
	Node *pv = new Node;
	pv->d = d;
	pv->p = 0;
	return pv;
}
void push(Node **top,int d)	//вставка в вершину
{
	Node *pv=new Node;
	pv->d = d;
	pv->p = *top;
	*top = pv;
}
int pop(Node **top)	//извлечение и удаление из вершины
{
	int temp = (*top)->d;
	Node *pv = *top;
	*top = (*top)->p;
	delete pv;
	return temp;
}


int Vozr(int x)//возраствание
{
	int a[4],temp;
	for (int i=0;i<4;i++)
	{
		a[3-i]=x%10;
		x=x/10;
	}
	for (int i=0;i<3;i++)
		for (int j=i+1;j<4;j++)
			if (a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	x=a[0]*1000+a[1]*100+a[2]*10+a[3];
	return x;
}
/*void poisk (char*a) // ПОИСК !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	FILE *out;
	char*r,q;
	char*p=new char[80];
	int count=1,c=0,pos,dlina,i,j;
	out=fopen("Output.txt","a");
	strcpy(p,a);
	for (i=0;i<strlen(p);i++)
	{
		/*if(count>c)
		{
			pos=i;
			dlina=count;
		}/*
		count=1;
		r=strchr(p,a[i]);
		strcpy(p,r);
		for (int j=0;j<strlen(p);j++)
		if (p[j]==p[j+1])
		{
			count++;
		q=p[j];
		}
		else break;
}
cout<<"\n\ndlina="<<count;
fprintf (out,"dlina=%d simvol- %ch\n",count,q);
}*/

void poisk (char*a) // ПОИСК !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	FILE *out;
	char*r,q;
	char*p=new char[80];
	int count=1,c=1,pos,pos1,dlina,i,j;
	out=fopen("Output.txt","a");
	strcpy(p,a);
	for (i=0;i<strlen(p);i++)
	{
	count=1;
	r=strchr(p,a[i]);
	pos1=i;
	
		r=strchr(p,a[i]);
		pos1=i;
		strcpy(p,r);
		for (int j=0;j<strlen(p);j++)
		if (p[j]==p[j+1])
		{
			count++;
			q=p[j];
		}
		else break;
		if (count>c)
		{
			pos=pos1;
			c=count;
		}
	}


cout<<"\n\ndlina= "<<c;
pos+=1;
cout<<" posiciya= "<<pos;
cout<<" simvol- "<<q<<endl;
fprintf (out,"dlina= %d posicia- %d simvol- %c\n",c,pos,q);
}
int rev(int num)// переворот числа
{
    int mun,c,x;
    x=num;
    mun=0;
    do
      {
       c=x%10;
       x=x/10;
       mun=10*mun+c;
      }
    while (x!=0);
    num=mun;
    return num;
}

int main ()
{
	setlocale ( LC_CTYPE, "Russian" );
	char** a = ( char** ) malloc ( sizeof ( char* ) * 100 );	
	char s [ 80 ];
	char* point;
	
	FILE* in,*out;		

	if( ! ( in = fopen("input.txt", "r") ) )
	{
		printf("Open file failed.\n");
		return 1;
	}
	
		int i = -1;


	while (!feof(in))
	{
		i++;
		fgets ( s, 80, in );
		a [ i ] = new char [ 80 ];
		point = strtok ( s, " ,.!:;" );
		strcpy ( a[i], point ); 

		while ( ( point = strtok ( NULL, " ,.!?:;" ) ) && (strncmp ( point, "\n", 1 ))  )
	{
		i++;
		a [ i ] = new char [ 80 ];	
		strcpy ( a [ i ], point);
	}
	}

	for ( int j=0; j <= i; j++ )
		cout<<a[j]<<"\n";



out=fopen("Output.txt","w");
fprintf(out,"Результат выполнения\n");

for (int j=0;j<=i;j++)
poisk(a[j]);

}

















/*
	int k = -1;
	int* m = new int [ i ];
	int c;
	
	for ( int j = 0; j <= i; j++ )
	{
		c = atoi ( a [ j ] );
		if ( ( c ) && ( Count (c) == 4 ) )
		{
			k++;
			m [ k ] = c;
		}
	}

	Node *top=first(m[0]);

	for(int j=1;j<=k;j++)
		push(&top,m[j]);


	for ( int j=0; j <= i; j++ )
		cout<<a[j]<<"\n";

	cout << "\n\n4-х значные числа :\n\n";
	for ( int j=0; j <= k; j++ )
		cout<<m[j]<<"\t";

	cout << "\n\nто что было в стеке : \n\n";
	while(top)
		cout<<pop(&top)<<"\t"<<endl;

*/
/*
	cout<<endl<<endl<<"Результат выполнения задачи:"<<endl;
out=fopen("Output.txt","w");
fprintf(out,"Матрица МА\n");
int kol,w,v;
for (i=0;i<=k;i++)
{
	c=m[i];
	kol=0;
while (c!=6174)
{
  fprintf(out,"%d ",c);
  cout << c<<" ";
  w=Vozr(c);
  fprintf(out,"%d ",w );
  cout << w<<" ";
  v=rev(w);
   while (v<1000)
  {
	  v*=10;
  }
   fprintf(out,"%d ",v );
   cout <<v<<" ";
  c=v-w;
  kol++;
}
     fprintf(out,"%d %d\n",c,kol);
	 cout << c <<" "<<kol<<endl;
}







fclose (in);
return 0;
    }



*/