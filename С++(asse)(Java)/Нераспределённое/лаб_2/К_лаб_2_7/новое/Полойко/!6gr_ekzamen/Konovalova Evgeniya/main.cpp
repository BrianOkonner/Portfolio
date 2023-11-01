#include <iostream>
#include <cstdio>
#include <cstring>
#include <functionsnames.h>
using namespace std;
char razd[]="*:.,";
int main()
{
	freopen("input.txt","r",stdin);
	FILE *out= fopen("output.txt","w");
	char *buffer = new char [100];
	char *tmp;
	queue numb={NULL,NULL};

	while (gets(buffer))
	{
		tmp= strtok(buffer,razd);
		while (tmp!=NULL)
		{
			int a= atoi(tmp );
			push(&numb,a);
			tmp=strtok(NULL,razd);
		}
	}
//-----------------------------------------------
	/*int **matr= new int *[100];
	for (int i=0;i<100;i++)
		matr[i]= new int [4];
	int *sortmatr=new int[100];*/

	int **matr=(int**)calloc(100,sizeof(int*));
	for (int i=0;i<100;i++)
		matr[i]=(int*)calloc(100,sizeof(int));
	int *sortmatr=(int*)calloc(100,sizeof(int));


	int t=0;
	while(numb.head!=NULL)
	{
		matr[t][0]=pop(&numb);
		sortmatr[t]=matr[t][0];
		prov(matr,t,matr[t][0]);
		t++;
	}
		matr[t][0]=0;
		matr[t][1]=0;
		matr[t][2]=0;
		matr[t][3]=0;
	for(int i=0;i<t;i++)
	{
		matr[t][0]+=matr[i][0];
		matr[t][1]+=matr[i][1];
		matr[t][2]+=matr[i][2];
		matr[t][3]+=matr[i][3];
	}
	
	
	qsort(sortmatr,t,sizeof(int),comp);
	for (int i=0;i<t;i++)
		matr[t+1][i]=sortmatr[i];
	fprintf (out,"Matrix ma\n");
	for (int i=0;i<=t;i++)
		fprintf(out,"%d %d %d %d\n",matr[i][0],matr[i][1],matr[i][2],matr[i][3]);

	for (int i=0;i<t;i++)
		fprintf(out,"%d ",matr[t+1][i]);
//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------
	for (int i=0;i<100;i++)
		free(matr[i]);

	free(matr);
	free(sortmatr);

	/*delete (sortmatr);
	for (int i=0;i<100;i++)
	delete (matr[i]);
    delete (matr);*/
	return 0;
}