//������������
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
class Number
{

private:	
int m,n,mn;
// 0  ����������� �� ��������� ���� �� ��������� ��������� ������� �� ���������
/*Number()                  
	{ 	}
*/
public:
// c1 ����������� �����������
	Number(const Number& Obn)
	{ m=Obn.m;
	  n=Obn.n;
	}

//1  ����������� �� ��������� ��������� ��������� ������� �� ���������
Number()                  
	{ 	}
//2 �����������  � ����� ����������
	Number(int x)
	{ m=x;
	 n=12;
	}

//3 �����������  � ����� ����������  
Number(int x,int y)
	{ m=x;
	  n=y;
	}
//4 �����������  � ����������� �� ��������� 
/*Number(int x=3,int y=3,int d=10)
	{m=x;
	 n=y+d;
	}
*/
//5
int nod()
{
	mn=m*n;
	while (n != m)  
	
	if (n>m) 
      n=n-m;
	  else m=m-n;
	   	return n;
}
//6
int nod(int n, int m)
{
	return (!m)? n : nod(m,n%m);
//	return n;
}
//7
int nokr()
{
	return (mn)/nod(m,n);
}
//8
int nok()
{
	return (mn)/nod();
}
};

int main()

{	//  ���� ��� �������������  ��
//	Number nn1;    //��
//	Number x1[5];  //��

//  ���� ���� ����������� 0
//	Number nn2;  //������
	Number x2[5];//������


//  ���� ����  ������ ����������� 1 � ���  ������������ 0	
//	Number nn;  //��
	Number x[5];//��
	

//  ���� ���  ������������ 0  � ���  ����������� 1
//	���� ����������� 2	
//	Number nn;  //������, ����� ����������� 1
	Number xx[5];//������


//  ���� ���  ������������ 0  � ���  ����������� 1
//	���� ����������� 2 �  3	
//	Number nn(3,8);  // ��
	Number y[5];    //��


//  ���� ���  ������������ 0  � ���  ����������� 1
//	���� �����������  2 � 3 � 4	
//	Number nn(3,8);  // ������ ��������� ����� ����������� ��������
	Number z[5];     //��

//���������� ������������ �����������
    Number nk1(8,28); 
		Number nk2(nk1);  //ok
		Number nk3=nk1;   //ok
		nk2=nk3;          // no 
    Number n1(8);     // ������, ����  ����  ����������� 1 2 3 4 ������ 4
    Number n2(10,15); // ������, ���� ����  ����������� 1 2 3 4 ������ 4
    Number n3;        // ������, ���� ����  ����������� 1 2 3 4 ������ 4
	Number xy[5];     //  ��, ����  ����������� 1 2 3 4  �� ������ 4
	int m,n,r1,r2;
	r1=n1.nod();
	r2=n2.nok();
//	cout << "Nod="<<n1.nod()<<"Nok="<<n2.nok()<<endl;// ������	 �� ���������� ���������
	cout << "Nod="<<r1<<" Nok="<<r2<<endl; //��	

	cout << n2.nod()<<endl;
	cout << n2.nok()<<endl;
	return 1;
}	
