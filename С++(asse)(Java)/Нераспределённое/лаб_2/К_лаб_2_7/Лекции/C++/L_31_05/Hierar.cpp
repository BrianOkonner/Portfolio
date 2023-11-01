#include <iostream>
using namespace std;
class ex_abstr{ 
//  ����������� ����� � ��������� ����� ���� �������� � ���� ������� �� �������
public:
	// ������ ������
	// ����������� ������� sum (�������� ���������� �� ������)
virtual	 void sum(  ex_abstr* a, ex_abstr* b)=0;

	// ������ ������
	// ����������� ������� sum2 (�������� ���������� �� �������)
virtual	 void sum2(  ex_abstr& a, ex_abstr& b)=0;
	// ����������� ������� print (��� ����������)
virtual void print()=0;
};

// ������ ������� - ��� ������ � ������ �������
class ex_int:public ex_abstr{ 
private:
	int x;
public:
		 ex_int(int xx=0):x(xx){}
	 void sum( ex_abstr* a, ex_abstr* b)
	{	ex_int* Int1= (ex_int*)a;	// ���������� ���������� � ���� ��. �� �������
		ex_int* Int2= static_cast<ex_int*>(b);
		x = Int1->x + Int2->x;
	}
	 void sum2( ex_abstr& a, ex_abstr& b)
	{			
		 // ���������� ������ � ���� ������� (����� ���������)
		 ex_int& Int1= *((ex_int*)&a); 
		 ex_int& Int2= *((ex_int*)&b);
		x = Int1.x + Int2.x;
	}
	 void print()
	 {
		 cout<< x<< endl;
	 }
};
// ������ ������� - ��� ������ � ��������������� �������
class ex_double:public ex_abstr{ 
private:
	double x;
public:
		 ex_double(double xx=0.0):x(xx){}
	 void sum( ex_abstr* a, ex_abstr* b)
	{	ex_double* D1= (ex_double*)a;
		ex_double* D2= static_cast<ex_double*>(b);
		x = D1->x + D2->x;
	}
	 void sum2( ex_abstr& a, ex_abstr& b)
	{			
		 ex_double& D1= *((ex_double*)&a);
		 ex_double& D2= *((ex_double*)&b);
		x = D1.x + D2.x;
	}
	 void print()
	 {
		 cout<< x<< endl;
	 }
};

main()
{
	ex_int a(5),b(6),c;
	ex_abstr *A=&a,*B=&b,*C, &C2=c;
	C= &c;		// ��� ������ ����������� ������� ������� �������
				// ������������ �����
//-------------����� ����������� ������� ������� �������
	C->sum(A,B);
	C->print();
	C->sum2(*A,*B);	
	C->print();
				// ��� ������ ����������� ������� ������� �������
				// ������������ ������
	C2.sum(A,B); C2.print();

	ex_double a1(5.5),b1(6.6),c1;
	ex_abstr &C3=c1;
	A=&a1; B=&b1;
	C= &c1;		// ��� ������ ����������� ������� ������� �������
				// ������������ �����
//------------���, ���������� ���������� ����	
//-------------����� ����������� ������� ������� �������
	C->sum(A,B);
	C->print();
	C->sum2(*A,*B);	
	C->print();
				// ��� ������ ����������� ������� ������� �������
				// ������������ ������
	C3.sum(A,B); C3.print();
}


