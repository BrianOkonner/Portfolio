#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cstdlib>
#include "fun_h.h"
#include <ctime>
#include "Windows.h"
#include <stdio.h>
#include <time.h> 
using namespace std;
const double pi=3.14159265,e=2.71828182846;
double celayastep(double a,int b)//���������� ����� � ����� �������
{
	double r=1,i;
	if(b==0)
		return 1;
	else
	{
	for(i=1;i<=b;i++)
		r=r*a;
	return r;
	}
}
double tanH(int x) //��������� ��������������� ������� ����� pow
{
	double h=1,k;
	h=pow(e,x);
	k=(h-(1/h))/(h+(1/h));
	return k;
}
unsigned _int64 facial(int n)//��������� ���������
{
	int a,b=1;
	if (n==0)
		return 0;
	for (a=1;a<=n;a++)
		b=b*a;
	return b;
}
double estepx(double x,int o)//��������� � � ������� �
{
	double h=1,s=1; int k;
	for(k=1;k<=o;k++)
		s=s+(celayastep(x,k)/facial(k));
	return s;
}
double tanH(double x,int o)//��������� ��������������� ������� 
{
	double h=1,k,j;
	h=estepx(x,o);
	j=1/h;
	k=(h-(j))/(h+(j));
	return k;
}
long double tanH(double x,unsigned _int64 o)//��������� ��������������� ������� (�������� ���� ����)
{
	double h=1,k,j;
	h=estepx(x,o);
	j=1/h;
	k=(h-(j))/(h+(j));
	return k;
}
void mass_from_file(int *a,int n)//���� ������� ����� ����
{
	int i;
	char h[40];
	ifstream in;
	setlocale(LC_ALL,".1251");
	cout<<"������� ��� ������������ �����: ";
	cin>>h;
	in.open(h);
	for(i=0;i<n;i++)

	{
		in>>a[i];
	}
	in.close();
}
void mass_cel_rand_mil(int *f, int n)//��������� ������ ����� ��������� �������(������ ������������������ � �������� ������������)   
{
	SYSTEMTIME st;
	Sleep(1);
	GetLocalTime(&st);
    srand(st.wMilliseconds);
    for(int i=0;i<n;i++)
    {
        f[i]=rand()%100;
    }
}
void change(int *a,int *b)
{
	*a=(*b)+(*a);
	*b=(*a)-(*b);
	*a=(*a)-(*b);
}
void bubble_srt(int *a,int n)//���������� ���������� ���������
{
	int i,j,d=0,t=1;              
	i=1;
	while(i<=n && t!=0)
    {
		t=0;
		for (j=0;j<n-1;j++)
		  if (a[j]>a[j+1]) 
		  {
			change(&a[j],&a[j+1]);
		    t=1;
		  }
    i++;
	}
}
void bubble_srt_mtr2(int **a,int n,int m)//���������� ���������� ���������
{
	int i=1,j,d=0,t=1,k;              
	for (k=0;k<n;k++)
	{
		while(i<=m && t!=0)
		{
			t=0;
			for (j=0;j<m-1;j++)
				if (a[k][j]>a[k][j+1]) 
				{
					change(&a[k][j],&a[k][j+1]);
					t=1;
				}
		i++;
		}
		t=1;
		i=1;
	}
}
void bubble_srt_A4L4(int **a,int n,int m)//���������� ���������� ���������
{
	int i,j,d=0,t=1,k;              
	for(k=0;k<n-1;k++)
	{
		i=1;
		while(i<=n && t!=0)
		{
			t=0;
			for (j=0;j<m-1;j++)
			  if (a[k][j]>a[k][j+1]) 
			  {
				change(&a[k][j],&a[k][j+1]);
			    t=1;
			  }
		i++;
		}
	}
}
void mass_cel_rand(int *f, int n)//��������� ������ ����� ��������� �������(������ ������������������ � �������� ������������)   
{
    srand(time(NULL));
	Sleep(1000);
    for(int i=0;i<n;i++)
    {
        f[i]=rand()%10;
    }
}
void mass_cel_rand2(int *f, int n)//��������� ������ ����� ��������� �������  
{
    srand(time(NULL));
	Sleep(1000);
    for(int i=0;i<n;i++)
    {
        f[i]=rand()%100;
    }
}
void mass_cel_rand2N(int *f, int n)//��������� ������ ����� ��������� �������  
{
    srand(time(NULL));
	Sleep(1000);
    for(int i=0;i<n;i++)
    {
        f[i]=rand()%100;
    }
}
void mass_cel_rand4N(int *f, int n)//��������� ������ ����� ��������� �������  
{
    srand(time(NULL));
	Sleep(1000);
    for(int i=0;i<n;i++)
    {
        f[i]=rand()%10000;
    }
}
void frm_2ndcrs_to_ncrs(int* a,int *b,int n,int *h)//�� 2 ����������� ������� ������������(������� �������, �� �� ����� �������)
{
	int i=0,j=0,k=0;
	if (a[i]>b[j])//1.���� ��-� �� 1-�� ������� ������ ��-�� 2-�� ������� ����������� ��-�� 3-�� ������� ���������� �� 2-��.
	{
		h[k]=b[j];
		j++;//��������� � ������� ������ ������ ��� ������ ���������(����� ��� �� ����� 3.,8., 9., 10. ).
	}
	else//���� ���
	{	
		if (a[i]<b[j])//2.���� ��-� �� 1-�� ������� ������ ��-�� 2-�� ������� ����������� ��-�� 3-�� ������� ���������� �� 2-��.
		{
			h[k]=a[i];
			i++;
		}
		else
			if(a[i]==b[j])//3.���� ��-� �� 1-�� ������� ����� ��-�� 2-�� ������� ����������� ��-�� 3-�� ������� ����� �� 2-��.
			{
				h[k]=b[j];
				i++;
				j++;//��������� � ������� ������ � �� 2-�� � � 1-�� �������� �.� ��������� �����
			}
	}
	for(;i<n|j<n;)//����� �������� �� ����� ���� �� �������� ��� ��-�� � 2-�� ��������
	{
		if(j>=n)//������� ��� ������ �� ����� ���� i ��� �� ������ n
		{
			if(a[i]>h[k])//4.���� ��-� �� 1-�� ������� ������ ��-�� 3-�� ������� ����������� ��-�� 3-�� ������� ��-� 1-��
			{
				k++;
				h[k]=a[i];
				i++;
			}
			else
			i++;//��� ������ �� �����
		}
		else
		{
			if(i>=n)
			{
				if(b[j]>h[k])//5.���� ��-� �� 2-�� ������� ������ ��-�� 3-�� ������� ����������� ��-�� 3-�� ������� ��-� 2-��
				{
					k++;
					h[k]=b[j];
					j++;
				}
				else
				j++;
			}
			if(a[i]<b[j]&&a[i]>h[k])//6.���� ��-� �� 1-�� ������� ������ ��-�� 2-�� ������� � ������ ��-�� 3-�� ��-�� 3-�� ������� ����������� ��-� �� 1-��.
			{
				k++;
				h[k]=a[i];
				i++;
			}
			else
			{
				if(b[j]<a[i]&&b[j]>h[k])//7.���� ��-� �� 2-�� ������� ������ ��-�� 1-�� ������� � ������ ��-�� 3-�� ��-�� 3-�� ������� ����������� ��-� �� 2-��.
				{
					k++;
					h[k]=b[j];
					j++;
				}
				else
				{
					if(a[i]<b[j]&&a[i]==h[k])//8.���� ��-� �� 1-�� ������� ������ ��-�� 2-�� ������� � ����� ��-�� 3-�� ��������� � ���������� �� 1-��
					i++;
					else
					{
						if(a[i]>b[j]&&b[j]==h[k])//9.���� ��-� �� 2-�� ������� ������ ��-�� 1-�� ������� � ����� ��-�� 3-�� ��������� � ���������� �� 2-��
						j++;
						else
						{
							if(a[i]==b[j]&&b[j]==h[k])//10.���� ��-�� �������� ����� ��������� �� ��������� ��-��� �� 2-�� � 1-�� ��������
							{
								i++;
								j++;
							}
							else//���� ������� �� ��������� ��-�� 3-�� ������� ����������� ����� �� ����
							{
								k++;
								h[k]=a[i];
								i++;
								j++;//��������� ����� � 2-�� ��������
							}
						}
					}
				}
			}
		}
	}
}
void vivod_L3B9(int *a,int *b,int *h,int n)//����� �������� �������� ��� ������ L3(B9)(�� �������� �� � ����� �������� ����� �������)
{
	int i=0;
	cout<<"     �������: "<<endl;
	cout<<left<<setw(20)<<"1-�� �����������"<<left<<setw(20)<<"2-�� �����������"<<left<<setw(20)<<"������������ ������"<<endl;
	while (a[i]>=0&&h[i]>=0&&b[i]>=0)
	{
		cout<<left<<setw(20)<<a[i]<<left<<setw(20)<<b[i]<<left<<setw(20)<<h[i]<<endl;
		i++;
	}
	if(a[i]<0)
	{
	while (h[i]>=0)
		{
			cout<<left<<setw(40)<<" "<<h[i]<<endl;
			i++;
		}
	}
	else
	{
		while (a[i]>=0)
		{
			cout<<left<<setw(20)<<a[i]<<left<<setw(20)<<b[i]<<endl;
			i++;
		}
	}
}
void MoveRight(int *a,int *n,int num)
{
	for(int i=*n;i>=(num);i--)
		a[i]=a[i-1];	
	(*n)++;
}
void DeleteCh(int *a, int *n, int item)// ��������   �� ������� ��������� = item
 { 	
  int i=0; 
  while (i<*n) 
  {   
   if (a[i]==item) 
       MoveLeft(a, n, i);
 //�������� � ������� �������
   else		
   i++;  } 
  }
void DeleteChinmatr(int **a, int *m,int n, int item)// ��������   �� ������� ��������� = item
 { 	
  int i=0; 
  while (i<*m) 
  {   
   if (a[n][i]==item) 
       MoveLeftinmatr2(a, m,n, i);
 //�������� � ������� �������
   else		
   i++;  } 
  }
void MoveLeft(int * a,int *n, int num)//�������� ���  �������� �� 1 ������� ����� ����� ������ num
{  
for (int i=num-1;  i<*n-1;   i++)                 
   a[i]=a[i+1]; 
   *n=*n-1;
} 
void MoveLeftinmatr2(int **a,int *m,int n,int num)//�������� ���  �������� �� 1 ������� ����� ����� ������ num
{  
for (int i=num-1;  i<*m-1;   i++)                 
   a[n][i]=a[n][i+1]; 
   *m=*m-1;
} 
void delreusage(int *a,int *n)
{
	int i=0;
	while(i<*n)
	if(a[i]==a[i+1])
		DeleteCh(a,n,a[i]);
}
void delrowreusage(int *a,int *n)
{
	int i=0;
	while(i<*n-1)
	{
		if(a[i]==a[i+1])
			MoveLeft(a,n,i+1);
		else
			i++;
	}
}
int BinarySearch_L3 (int *a,int n,int x)
{
	int m,i,j,b=0;
	if(n%2==1)
		m=(n/2)+1;
	m=n/2;
	i=m;
	j=m;
	while(j!=-12)
	{	
		if(x<a[m-1]&&m==0)
		{
			return m-1;
			break;
		}
		else
			if(x<a[m-1]&&x>=a[m-2])
			{
				return m-1;
				break;
			}
			else
				if(x>a[m-1])
				{
					if(j%2==1)
						j++;
					b=b+j;
					j=j/2;
					m=b+j;
					cout<<"a"<<m-1<<endl;
				}
				else
				{
					if(j%2==1)
						j++;
					j=j/2;
					m=b+j;
					cout<<"b"<<m-1<<endl;
				}
	}
	return -1;
}
int BinarySearch_L3_inmatr (int **a,int n,int x, int k)//k ��� ������ ������
{
	int m,i,j,b=0;
	if(n%2==1)
		m=(n/2)+1;
	m=n/2;
	i=m;
	j=m;
	while(j!=-12)
	{	
		if(x<a[m-1][k]&&m==0)//m==1
		{
			return m-1;
			break;
		}
		else
			if(x<a[m-1][k-1]&&x>=a[m-2][k])
			{
				return m-1;
				break;
			}
			else
				if(x>a[m-1][k])
				{
					if(j%2==1)
						j++;
					b=b+j;
					j=j/2;
					m=b+j;
				}
				else
				{
					if(j%2==1)
						j++;
					j=j/2;
					m=b+j;
				}
	}
	return -1;
}
void input_matr2_rand2(int **a, int n,int m)
{
	int i,j;
	srand(time(NULL));
	Sleep(1000);
	for(j=0;j<n;j++)
		for(i=0;i<m;i++)
			a[j][i]=rand()%100;
}
void input_matr2_rand2N(int **a, int n,int m)
{
	int i,j;
	srand(time(NULL));
	Sleep(1000);
	for(j=0;j<n;j++)
		for(i=0;i<m;i++)
			a[j][i]=rand()%100+1;
}
void input_matr2_randN(int **a, int n,int m)
{
	int i,j;
	srand(time(NULL));
	Sleep(1000);
	for(j=0;j<n;j++)
		for(i=0;i<m;i++)
			a[j][i]=rand()%10+1;
}
void input_matr2_zer(int **a, int n,int m)
{
	int i,j;
	for(j=0;j<n;j++)
		for(i=0;i<m;i++)
			a[j][i]=0;
}
void vivodmass(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		cout<<left<<setw(4)<<a[i];
	cout<<endl;
}
void vivodmassbig(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		cout<<left<<setw(8)<<a[i];
	cout<<endl;
}
int vvod(int a)
{
	cin>>a;
	return a;
}
void matrB7L3(int **a,int n,int m)
{
	int i,j;
	for(j=0;j<n;j++)
		for(i=0;i<m;i++)
			a[j][i]=j+1+i+1;
}
void vivodmatr2(int **a,int n,int m)
{
	int i,j;
	for(j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
			cout<<left<<setw(4)<<a[j][i];
		cout<<endl;
	}
}
void matrB9L3(int **a,int n)
{
	int i,p=0,o=1,k;
	for(k=n;k>0;k=k-1)
	{
		if (k==1)
		{
			i=n/2;
			a[i][i]=1;
		}
		else
		{
			for (i=p;i<k-1;i++)
			{
				a[p][i]=o;
				o++;
			}
			for (i=p;i<k-1;i++)
			{
				a[i][k-1]=o;
				o++;
			}
			for (i=k-1;i>=p+1;i--)
			{
				a[k-1][i]=o;
				o++;
			}
			for (i=k-1;i>p;i--)
			{
				a[i][p]=o;
				o++;
			}
			o=1;
			p=p+1;
		}
	}
}
int **matr2_dclr(int **a,int n,int m)
{
	a=new int*[n];   //�������� �����
	for (int i=0;i<n;i++)
		a[i]=new int[m];  //�������� ������� ��� ������ ������
	return a;
}
int *mass_dclr(int *a,int n)
{
	a=new int[n];
	return a;
}
void input_matr2_rand(int **a, int n,int m)
{
	int i,j;
	srand(time(NULL));
	Sleep(1000);
	for(j=0;j<n;j++)
		for(i=0;i<m;i++)
			a[j][i]=rand()%10;
}
int matr2_search_least(int **a,int n,int m)
{
	int x,*c=0;
	c=mass_dclr(c,n);
	for (int j=0;j<n;j++)
	{
		c[j]=a[j][0];
		for (int i=1;i<m;i++)
		{
			if (a[j][i]<c[j])
				c[j]=a[j][i];
		}
	}
	x=c[0];
	for (int j=1;j<n;j++)
		if (c[j]<x)
			x=c[j];
	return x;
}
void format_matrC8L4(int **a,int n,int m)
{
	int x,**b=0,k,l,p,i,j;
	b=matr2_dclr(b,3,n);
	for (j=0;j<n;j++)
	{
		b[0][j]=j;//� ������ ������� ������ �����
		b[2][j]=a[j][0];
		b[1][j]=0;
		for (i=1;i<m;i++)
		{
			if (a[j][i]<b[2][j])
			{
				b[2][j]=a[j][i];
				b[1][j]=i;//�� ������ - �������� 
			}
		}
	}
	x=b[2][0];
	l=0;
	for (j=1;j<n;j++)
		if (b[2][j]<x)
		{
			x=b[2][j];
			l=j;
		}
		p=b[0][l];
		k=b[1][l];
		for(i=0;i<m;i++)
		{
			if (p==(n-1))
				break;
			change(&a[p][i],&a[n-1][i]);
		}
		for(i=0;i<n;i++)
		{
			if (k==(m-1))
				break;
			change(&a[i][k],&a[i][m-1]);
		}
}
int** matrA1L4(int **a,int n,int m)
{
	int **b=0,v,i,j,k;
	b=matr2_dclr(a,n,m);
	for(v=0;v<n;v++)
	{
		for (j=0;j<m;j++)
		{
			k=1;
			for (i=1+j;i<m;i++)
			{   
				if (a[v][i]==a[v][j]) 
				{
					k++;
					i++;
				}
				else
					i++;
			} 
			if(k!=1)
				for(i=0;i<k;i++)
				{
					b[v][i]=a[v][j];
					cout<<left<<setw(4)<<b[v][i];
				}
		}
		cout<<endl;
	}
		return b;
}
int** matrA1L4b(int **a,int n,int m)
{
	int **b=0,i,j,k;
	b=matr2_dclr(b,n,m);
	bubble_srt_mtr2(a,n,m);
	for(j=0;j<n;j++)
	{
		k=0;
		if(a[j][0]==a[j][1])
		{
			b[j][k]=a[j][0];
			k++;
		}
		for(i=1;i<m;i++)
			if(a[j][i]==a[j][i-1]||a[j][i]==a[j][i+1])
			{				
				b[j][k]=a[j][i];
				k++;
			}
		for(i=0;i<k;i++)
			cout<<left<<setw(4)<<b[j][i];
		cout<<endl;
	}
	return b;
}
void magicsqr(int **a,int m)
{
	int i=1,j=2,p,q,l;
	p=prv_even(m);
	if (p==1)
		m=m+1;
	p=(m/2);
	l=p-1;
	a[l][p]=1;
	for(q=0;j<=(m*m);q=0)
	{
		if(l-i==-1)
		{
			l=m-1+i;
			q++;
		}
		if(p-i==-1)
		{
			p=m-1+i;
			q++;
		}
		if(p-i==m)
		{
			p=0+i;
			q++;
		}
		if(q==0)
		{
			if(a[l-i][p-i]>0&&a[l-i][p-i]<m*m+1)				
			{
				l=l--;
				p=p++;
				q++;
			}
			if(q==0)
			{
				a[l-i][p-i]=j;
				j++;
				i++;
			}
		}
	}
}
int prv_even(int a)
{
	if(a%2==0)
		return 1;
	else 
		return 0;
}
void inspiral(int **a,int n)
{
	int i,p=0,o=1,k;
	for(k=n;k>0;k=k-1)
	{
		if (k==1)
		{
			i=n/2;
			a[i][i]=n*n;
		}
		else
		{
			for (i=p;i<k-1;i++)
			{
				a[p][i]=o;
				o++;
			}
			for (i=p;i<k-1;i++)
			{
				a[i][k-1]=o;
				o++;
			}
			for (i=k-1;i>=p+1;i--)
			{
				a[k-1][i]=o;
				o++;
			}
			for (i=k-1;i>p;i--)
			{
				a[i][p]=o;
				o++;
			}
			p=p+1;
		}
	}
}
int cmp_int(void*x1,void*x2)   // ������� ��������� ��������� �������
{
  return(*(int*)x1-*(int*)x2);              // ���� ��������� ��������� ����� 0, �� ����� �����, < 0: x1 < x2; > 0: x1 > x2
}
/*void InsStrNum( char*S1,const char*S2,int num)
	//��������� � ������ S1 ������  S2  ����� num
{   int n,n2;
	char* s1,*s2,*s3;             //����� ������ � � ������ �
    n=strlen(S2);         //����� ���������
	  if (strlen(S1)>=num) 
	  {
        n2=strlen(S1)-num;//����� ������ ����� num
	    s2=new char(strlen(S1)+n+1);
		s3=new char(n2+1);
	    strncpy(s2,S1,num);//������  ��  num
		s2[num]='\0';
        strcat(s2," " );
		strcpy(s3,S1+num); //����� ������ ����� num
		strcat(s2,S2);    //��������� �����
		 strcat(s2," " );
		strcat(s2,s3);     
		 
		strcpy(S1,s2);
     }
	  else 
		  strcat(S1,S2);
}*/
/*
{ 	
	int i,j,k,*w=0; 
	w=mass_dclr(w,n);
	for (j=0;j<m;j++)
	{
		for (i=1;j+i<m;i++)
		{   
			if (a[0][j]==a[0][j+i]) 
				
			
		
			else
				i++;
		} 
	}
}*/
//}
/*void matr_ini(int **a,int n)*/
/*void Ungamatr(int *a,int **b,int n)
{
	int j=0,i=0,k=0,o=0,p;
	b[i][j]=a[k];
	k++;
	i++;
	if (b[i][j]<1000&&b[i][j]>-1)
	{
		if (a[k]>b[i][j])
		{
			b[i][j]=a[k];
			k++;
			i++;
			o++;
		}
		else
		{
			p=BinarySearch_L3 (**b,o,a[k],j);
			
	}
}*/





/*void Qsort(void *base,int n,int size,int (*cmp)(void *e1,void *e2))//���������� ���������� ���������
{
	int i,j,d=0,t=1;              
	i=1;
	while(i<=n && t!=0)
    {
		t=0;
		for (j=0;j<n-1;j++)
		  //if (&cmp(base[j],&base[j+1])>0)//(a[j]>a[j+1]) 
		  {
			//change(&base[j],&base[j+1]);
		    t=1;
		  }
    i++;
	}
}*/