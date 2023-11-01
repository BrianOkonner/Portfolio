#include <stdio.h>
#include <windows.h>
#include <string.h>


#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 81

typedef int (*pSort)(int*,int);
typedef void (*pDecToByn)(int,int*);
pSort sort;
pDecToByn decToByn;


int bynSum(int*num)
{
	int res=0;
	int i=-1;
	while(num[++i]!=-1)
		res+=num[i];
	return res;
}
/*
int decToByn(int num, int *res)
{
	int i=0;
	_asm
	{
		mov edi,res
		mov eax,num
		mov eax,num
while1:
	
	xor edx,edx
	mov ebx,2
	div ebx
	
	mov [edi],edx

	add edi,4
	
	cmp eax,0
	jne while1
	
	xor eax,eax
	dec eax
	mov [edi],eax


	}
}
*/

/*
void decToByn(int num, int*res)
{
	int i=0;
	
	while(num)
	{
		res[i++]=num%2;
		num/=2;
	}

	res[i]=-1;

}
*/

int count(int*num,int cur)
{
	if(*num==-1)
		return cur;
	else
	return count(num+4,cur+1);
}

int interes(int num, int &nIter)
{
	nIter=0;
	int res=1;
	int *byn;
	while(num!=1)
	{
		nIter++;
		byn = new int[MAX];
		decToByn(num,byn);
		num=bynSum(byn);
		res *=num;
		delete[]byn;
	}

	return res;
}
/*
void sort(int *arr, int len)
{
	int buf;
	int len2;
_asm
{
	mov edi,arr
	xor ecx,ecx
	dec len
for1:
	mov ebx,len
	sub ebx,ecx
	xor edx,edx

	for2:
		
		mov eax,[edi+edx*4]
		cmp eax,[edi+edx*4+4]
		jle endif
		mov eax,[edi+edx*4]
		mov buf,eax
		
		mov eax, [edi+edx*4+4]
		mov [edi+edx*4],eax
		mov eax,buf
		mov [edi+edx*4+4],eax

endif:

		inc edx
		cmp edx,ebx
		jl for2
		


	inc ecx
	cmp ecx,len
	jl for1
}
}
*/
/*
void sort(int *arr, int len)
{
	int buf;
	for(int i=0; i<len-1; i++)
		for(int j=0; j<len-1-i; j++)
		{
			if(arr[j]>arr[j+1])
			{
				buf=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=buf;
			}
		}
}
*/
int arrProd(int *arr)
{
	int res=1;
	int i=0;
	while(arr[++i]!=-1)
	{
		res*=arr[i];
	}
	return res;
}

void main()
{

	HMODULE hModule;
	hModule = LoadLibraryA("dll\\examdll.dll");
	
	sort= (pSort)GetProcAddress(hModule, "sort");
	decToByn=(pDecToByn)GetProcAddress(hModule, "decToByn");


	char *str = new char[MAX];
	ifstream fin("input.txt");
	fin.getline(str,MAX);

	int *source = new int[MAX];
	int *inter = new int[MAX];
	int *reps = new int[MAX];

	
	char *word=NULL;
	word = strtok(str," ,.;:");

	
	int cnt=-1;

	while(word!=NULL)
	{

		source[++cnt] = atoi(word);

		inter[cnt] = interes(source[cnt],reps[cnt]);
		word = strtok(NULL," ,.;:");
		
	}
	fin.close();

	cnt++;
	int *sortedSource = new int[cnt];
	int *sortedInter = new int[cnt];

	for(int i=0; i<cnt; i++)
	{
		sortedSource[i]=source[i];
		sortedInter[i]=inter[i];
	}

	sort(sortedSource,cnt);
	sort(sortedInter,cnt);

	ofstream fout("result1.txt",ios::out);
	
	char*buf = new char[MAX*4];
	fout<<"Chisla          2-chnyi kod         sort chisla\n";
	for (int i=0; i<cnt; i++)
	{
		fout<<source[i]<<"\t"<<itoa(source[i],buf,2)<<"\t"<<sortedSource[i]<<endl;
	}
	
	fout.close();
	fout.open("result2.txt",ios::out);
	fout<<"Inter chisla          povtory         sort inter chisla \n";
	for (int i=0; i<cnt; i++)
	{
		fout<<inter[i]<<"\t"<<reps[i]<<"\t"<<sortedInter[i]<<endl;
	}

	fout.close();

	delete[]source;
	delete[]sortedSource;
	delete[]inter;
	delete[]reps;
	delete[]sortedInter;

}