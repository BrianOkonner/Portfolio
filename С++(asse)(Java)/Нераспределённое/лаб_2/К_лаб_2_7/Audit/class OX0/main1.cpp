
#include <iostream>
#include <fstream>
using namespace std;
ofstream of("output.txt"); //��� ����� ���������� ����������
static int c=0;

class OX
{   private:
    int num;
  public:
  void print(); 
  void printN(); 
  OX();
  OX(int x);
  // OX(int x=10);
    ~OX () ;
 //   OX(const OX&) ;
  //  OX operator=(const OX);//���� ��� ������  ��� 6
	//   OX operator=(const &OX);//���� ��� ������  ��� 2
       //    OX & operator=(const &OX);//���� ��� ������  ��� 4
       operator int() { return num; }
friend    OX& operator +(  const OX &Y,const OX &Z);//���� ��� ����o� ��� 4
   // OX& operator +(  const OX Y,)//���� ��� ����o� ��� 4
//  OX operator +(  const OX Y)//���� ��� ����o� ��� 4
		
    
	};

   OX& operator +(  const OX &Y,const OX &Z)//���� ��� ����o� ��� 4
   // OX& operator +(  const OX Y,)//���� ��� ����o� ��� 4
//  OX operator +(  const OX Y)//���� ��� ����o� ��� 4
		{of<<"�������� ��������"<<endl;
  		OX X;
                X.num=Z.num+Y.num;
	        return X;
		}
    


// ����������� �� ���������
OX::OX()
  {
   cout<<"�����������"<<endl;
   num = 5; print();
  }
// ����������� 
OX::OX(int x)
  {  
   cout<<"�����������"<<endl;
   num = x; print();
  }
// ����������
OX::~OX()
  { 
   cout<<"����������"<<endl;
   print();
  }
// ����������� �����
//OX::OX(const OX& rhs)
//  { 
//   cout<<"����������� �����"<<endl;
//   num = rhs.num;
//   print();
//  }
// �������� ������������
//OX OX::operator=(const OX rhs)
//  {
//   if(this == &rhs) 
//	  return *this;
//   printN();
//   cout<<"�������� ������������"<<endl;
//   num = rhs. num;
//   print();
//   return *this;
//  }
// ������� �� ��������
OX Foo(void)
   {    return OX();
   }

void OX::printN()
   { 	cout<<++c<<' ';}
void OX::print()
   { 	cout<<num<<endl;}

void main(void)
 {
   setlocale(LC_ALL,"rus");
   {
   OX Z;   // �����������
   OX Y=Z; // ����������� �����
   }        // ����� ���� ������������
  //{
  //  OX A;    // �����������
  //  OX B(A); // ����������� �����
  //}         // ����� ���� ������������
  //{
  //  OX C, D; // ��� ������������
  //  C=D;    // �������� ������������
  //}         // ����� ���� ������������
  //{
  //  OX E=Foo() ; // �����������
  //}             // ����������
  {
      OX A,C;    // �����������
      OX B(1000); // ����������� �����
      C=A+B;
	  cout<<"**";
	  C.print();
  }
} 
 /*
		//	���� ������ 
1 �����������
2 �����������
3 ����������� �����
4 �������� ��������
5 �����������
6 ����������
7 �������� ������������
8 ����������
9 ����������
10 ���������� */   
		// ��� ������ � +
//1 �����������
//2 �����������
//3 ����������� �����
//4 ����������� �����
//5 �������� ��������
//6 �����������
//7 ����������� �����
//8 ����������
//9 ����������
//10 �������� ������������
//11 ����������
//12 ����������
//13 ����������
//14 ����������
				// ��� ������ � + =
//1 �����������
//2 �����������
//3 ����������� �����
//4 ����������� �����
//5 �������� ��������
//6 �����������
//7 ����������� �����
//8 ����������
//9 ����������
//10 �������� ������������
//11 ����������� �����
//12 ����������
//13 ����������
//14 ����������
//15 ����������
//16 ����������
