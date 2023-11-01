
#include<fstream>
#include<iomanip>
#include<iostream>
using namespace std;
void DivAsm()// ������ �� ������� �� ������ ��� �����
{ int  a=-100,b=-40,c=-5,d; 
_asm
{
mov eax, a
cdq
mov  ecx,10
idiv b
imul ecx
cdq
idiv c
mov d, eax
}
cout<<"��������� DivAsm "<<a<<' '<<b<<' '<<c<<' '<<d; 
}

int logOP()//������ ��� ����� ���������� ���������  sum
{
	int sum;
	_asm
	{ mov eax, 100b
	mov ebx, 10b
	mov ecx, 10b
	and eax, 10// 0
	or  ebx, 100// 01100100  10-> 01100110- 66  = 102
	shl ecx,3 //- >2*8=16 =118
	add eax,ebx 
	add eax,ecx 
	mov sum,eax
	}
return sum; 


}

//����� ������������� �������� 
int PoiskMax(int *A, int n)
	{
		int Amax;  
_asm
{    mov ecx,n
	dec ecx
	mov esi,A		// ����� �������
	mov eax,[esi]	// ���������� ��������, ����� �������� � esi
for1:
	add esi,4
	cmp eax,[esi]
	cmovl eax,[esi]	// ���������, ���� ������
	loop for1
	mov Amax,eax 
}
return Amax;
}


//��������������� ������� 
void Revers(int *A, int n)
	{
		
_asm
{    mov ecx,n
	 mov ebx,n
	 dec ebx
	 shr ecx,1  //n=n/2->ecx
	 shl ebx,2  //(n-1)*4
	mov esi,A   // ����� �������
	mov edi,A
	add edi,ebx //edi ����� ���������� �������� �������  
	
for1:
	mov eax,[esi]	// ���������� ��������, ����� �������� � esi
	mov edx,[edi]
	mov [esi],edx
	mov [edi],eax
	add  esi,4
	sub  edi,4
	loop for1
}
}


void sort_ob(int *a,int n)        //���������� ������� ������
{
   int t;
	for (int i=0;i<n-1;i++)
		for (int j=0;j<n-1;j++)
			if (a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
}

void  sort_Asm (int *array,int n)
{
_asm{
		 mov ecx,n
		 dec ecx
loop1:  push ecx
	     mov esi,array
loop2:  mov eax,[esi]
        cmp eax,[esi+4]  
        jle then
	    xchg eax,[esi+4]
        mov [esi],eax
  then:   add esi,4
	     loop  loop2
	     pop  ecx
         loop loop1    
       } 
}

int SUMM(int n,int m)
{ //����� ����������� �������

 	int A[5][5];
	 int i,j,s=0;
	 for (i=0;i<n;i++)
	 {for ( j=0;j<m;j++)
	 {A[i][j] = rand()%2;
	    cout<< setw(6)<<A[i][j];
	 }
	 cout<<endl;
	 }
	 _asm
	 {
		 lea edi,A   
		 // ��� �����
		     mov ebx,m
			 shl ebx,2
		    mov ecx,n
for1:      push ecx  
			 mov ecx,m   
			 xor esi,esi     //��� ��������
 for2:

		 mov eax,dword ptr[esi][edi]   
	     add s,eax  
		 add esi,4               //�� ������ 
		 loop for2    
		 
		 add edi,ebx 
		 pop ecx  
		 loop for1
		 

	 }
        return s;
}
void  _cdecl print(int a)
{	cout<<a<<endl;
}
int SUMMDin(int **A, int n,int m)//����� ���� ������������ �������
{ int s=0;
_asm
{  
	  mov ebx,A        // ��� �����
      mov ecx,n
	 
	  
for1:
       
	  push ecx
      mov ecx,m
      	      //��� ��������
      mov esi,[ebx]   //����� ������ ������ �������  
for2:
      mov eax,[esi]
      add s,eax
      add esi,4       //�� ������
      loop for2
      add ebx,4		  //����� ������
      pop ecx
      loop for1
  
}
return s;}

void main()
	{
		 setlocale(LC_ALL,".1251");
		int i,j;
		int sum=logOP();
		cout<<endl;
		cout<<"��������� logOP "<<sum<<endl;
		DivAsm();
		cout<<endl;
		int a[]={5,2,6,7,1,3,5};
		int n=7;
				sort_ob(a,n);
		cout<<"��������� ���������� ��"<<endl;
		for (int i=0;i<7;i++)
			cout<<a[i]<<' ';
		cout<<endl;
		int b[]={5,2,6,7,1,3,5};
				sort_Asm(b,n);
		cout<<"��������� ���������� ASm"<<endl;
		for (int i=0;i<n;i++)
			cout<<b[i]<<' ';
		cout<<endl;
       int max=PoiskMax(a,7);
		cout<<"���������� �������="<<max<<endl;
		Revers(a,n);
		cout<<"��������� ���������������"<<endl;
		for (int i=0;i<n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
		int s=SUMM(5,5);
		
		cout<<"��������� ����� ����������� ������� "<<s<<endl;
	n=5;
     int **B;
	  B=new int*[n];
	 for (i=0;i<n;i++)
		 B[i]=new int [n];
	 for (i=0;i<n;i++)
	   {for ( j=0;j<n;j++)
	     {B[i][j] = rand()%2;
	       cout<< setw(3)<<B[i][j];
	       }
	  cout<<endl;
	    }
	 cout<<endl;
		s= SUMMDin(B, n,n);
		cout<<"��������� ����� ������������  ������� "<<s<<endl;
		system("pause");
	}