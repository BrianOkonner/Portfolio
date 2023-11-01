#include <Windows.h>
#include <iostream>
using namespace std;
struct myPair
{
	int* mass;
	int result;
	int result2;
	double avg;
	int index2;
	int index;
	int n;
};
DWORD WINAPI min_max(LPVOID iNum)
{
	int rez1=0,rez2=0;
	for(int j=0;j<(myPair*)iNum)->n;j++)
	{
		if(((myPair*)iNum)->mass[j]>((myPair*)iNum)->mass[j])
		{
			rez1=((myPair*)iNum)->mass[j];
			((myPair*)iNum)->index=j;
		}
		Sleep(70);
	}
	printf("Максимальный элемент: %i\n",((myPair*)iNum)->index,rez1);
	for (int i=0;i<((myPair*)iNum)->n;i++)
	{
		if(((myPair*)iNum)->mass[i]<((myPair*)iNum)->mass[i])
		{
			rez2=((myPair*)iNum)->mass[i];
			((myPair*)iNum)->index2=i;
		}
		Sleep(7);
	}
	}
	printf("Минимальный элемент: %i\n",((myPair*)iNum)->index,rez2);
	((myPair*)iNum)->result;
	((myPair*)iNum)->result2;
	return 0;
}
DWORD WINAPI average(LPVOID iNum)
{
	double rez1=0;
	for(int j=0;j<((myPair*)iNum)->n;j++)
	{
		rez1+=(double)(((myPair*)iNum)->mass[j])/(double)(((myPair*)iNum)->n);
		Sleep(7);
	}
	((myPair*)iNum)->avg=rez1;
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
	HANDLE*  hThreadMulArray = new HANDLE[n];
	int result=0,result2=0;
	myPair *myPairArray = new myPair[n];
	cout<<"Введите массив\n";
	for (int i=0;i<n;i++)
		cin>>mass[i];
	cout<<endl;
	myPairArray=new myPair();
	myPairArray->n=n;
	myPairArray->result=result;
	myPairArray->result2=result2;
	myPairArray->mass=mass;
	DWORD IDThreadMul;
	hThreadMulArray = CreateThread(NULL,0,min_max,(void*)myPairArray,0,&IDThreadMul);
	WaitForSingleObject(min_max,INFINITE);
	hThreadMulArray = CreateThread(NULL,0,average,(void*)myPairArray,0,&IDThreadMul);
	WaitForSingleObject(average,INFINITE);
	CloseHandle(hThreadMulArray);
	myPairArray->mass[myPairArray->index]=mass[myPairArray->index2]=myPairArray->avg;
	cout<<"Полученный массив целых значений:";
	for(int i=0;i<n;i++)
		cout<<mass[i]<<" ";
	CloseHandle(hThreadMulArray);
	system("pause");
	return 0;
}
