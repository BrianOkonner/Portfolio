//����� �����
// ������� ������� ������ ������
#include <iostream>
using namespace std;
class point
{  //protected:                 //���������� ������ ������
	int x,y;                  //���������� �����
 public:
	char *str;
			//������������
	point(int xi=10,int yi=0) { x=xi;y=yi; };
//	point():x(0), y(0) { } 
//	point(int xi,int yi):x(xi), y(yi){ }  
			//����������� �����������
	point (const point &p); 
	
			// �������� ������������
	point &operator =(const point &p);
	
			// ������� ���������
	//point& operator += (const point& r);
	//point& operator -= (const point& r);
	//point& operator *= (const point& r);
	//point& operator /= (const point& r);

	point& point::operator += (const point& r);
	
	point& point::operator -= (const point& r);
	
	point& point::operator *= (const point& r);

	point& point::operator /= (const point& r);
	
// ������� ����� � ����
	//point operator -(void);
	//point& operator +(void);
	point & operator -(void)
	{
		x = -x;
		y = -y;
		return *this;
	};
	///*point operator -(void)
	//{	
	//	point r;
	//	r.n = -n;
	//	r.d = d;
	//	return r;
	//}*/
	point& operator +(void)
	{
		return *this;
	}
	// ����������
	point operator ++(int k);//����������� ������
	
	point &operator ++(); //���������� ������
	
		// ����������
	point operator --(int k);//����������� ������
	
	point &operator --();//���������� ������
	

		
	point operator -(point &p);//(���������  ��� �������)
	
	//point operator -(point &p) //( �� ���������  �������)
	//{
	//	x = this->x - p.x;
	//	y = this->x - p.y;
	//	return *this;
	//};
		
	//friend  point operator +(int k,point& p);
	//friend  point operator -(int k,point& p);
	friend  point operator +(int k,point &p);//�������� � ���������� �����
	
	point operator +(int k);//�������� � ���������� ������
	
	
	friend point operator -(int k,point &p);//��������� �� ���������
	
	point operator -(int k);//��������� ���������
	
		// ��������� ���������
	//friend bool operator < (const ratio& r1, const ratio& r2);
	//friend bool operator > (const ratio& r1, const ratio& r2);
	//friend bool operator == (const ratio& r1, const ratio& r2);
	//friend bool operator != (const ratio& r1, const ratio& r2);
	//friend bool operator <= (const ratio& r1, const ratio& r2);
	//friend bool operator >= (const ratio& r1, const ratio& r2);
	//friend bool operator < (const ratio& r1, const ratio& r2);

	bool operator>= (const point &r) const;

		// �������� ���������
			//  �������  ���������� �������� (��������� ������������ ��� �������)
	point operator +(point &p);

		//  �������  ���������� �������� (�� ��������� ������������ ��� ������)
/*	point & operator +(point &p)

	{	x = this->x + p.x;    
		y = this->y + p.y;
		return *this; //  �� ���������� ����������� - �.�.  ���������� point & 
	};
	*/		
	 friend point operator + (const point& p1, const point& p2);
	 
	//friend point operator - (const point& p1, const point& p2);
	//friend point operator * (const point& p1, const point& p2);
	//friend point operator / (const point& p1, const point& p2);

		// ��������� �����-������
	//friend istream& operator>>(istream& in, point& r);
	//friend ostream& operator<<(ostream& out, const point& r);

	 void Print(void); 
	~point();	
};

		