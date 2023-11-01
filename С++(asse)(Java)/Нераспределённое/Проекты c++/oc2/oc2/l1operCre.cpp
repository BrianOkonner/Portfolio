#include <Windows.h>
#include <iostream>
using namespace std;
struct myPair 
{
	int* mass;
	int result;
	int result2;
	int avg;
	int index2;
	int index;
	int n;
};
DWORD WINAPI min_max(LPVOID iNum)
{
	int rez1=0,rez2=0;
	for(int j=0;j<((myPair*)iNum)->n-1;j++)
	{
		if(((myPair*)iNum)->mass[j]>((myPair*)iNum)->mass[j+1])
		{
			rez1=((myPair*)iNum)->mass[j];
			((myPair*)iNum)->index=j;
		}
		Sleep(70);
	}
	for (int i=0;i<((myPair*)iNum)->n-1;i++) 
	{
		if(((myPair*)iNum)->mass[i]<((myPair*)iNum)->mass[i+1])
		{
			rez2=((myPair*)iNum)->mass[i];
			((myPair*)iNum)->index2=i;
		}
		Sleep(7);
	}
	printf("Максимальный элемент: %i\n",((myPair*)iNum)->index,rez1);
	printf("Минимальный элемент: %i\n",((myPair*)iNum)->index,rez2);
	(((myPair*)iNum)->result)=rez1;
	(((myPair*)iNum)->result2)=rez2;
	return 0;
}
DWORD WINAPI average(LPVOID iNum)
{
	int rez1=0;
	for(int j=0;j<((myPair*)iNum)->n;j++) 
	{
		rez1+=(((myPair*)iNum)->mass[j]);
		Sleep(7);
	}
	(((myPair*)iNum)->avg)=rez1/(((myPair*)iNum)->n);
	Sleep(1000000);
	return 0;
}
int main()
{
	setlocale(LC_ALL,"Rus");
	int n,i;
	cout<<"Размерность массива:"<<endl;
	cin>>n;
	int *mass=new int[n];
	HANDLE  hThreadMulArray = new HANDLE();
	int result=0,result2=0;
	myPair *myPairArray = new myPair[n];
	cout<<"Введите массив\n";
	for (int i=0;i<n;i++)
		cin>>mass[i];
	cout<<endl;
	DWORD IDThreadMul;
	myPairArray=new myPair();
	myPairArray->n=n;
	myPairArray->result=result;
	myPairArray->result2=result2;
	myPairArray->mass=mass;
	hThreadMulArray = CreateThread(NULL,0,min_max,(void*)myPairArray,0,&IDThreadMul);
	WaitForSingleObject(min_max,INFINITE); 
	hThreadMulArray = CreateThread(NULL,0,average,(void*)myPairArray,0,&IDThreadMul);
	WaitForSingleObject(average,INFINITE);
	CloseHandle(hThreadMulArray);
	myPairArray->mass[myPairArray->index]=myPairArray->avg;
	mass[myPairArray->index2]=myPairArray->avg;
	cout<<"Полученный массив целых значений:";
	for(int i=0;i<n;i++)
		cout<<mass[i]<<" ";
	system("pause");
	return 0;
}