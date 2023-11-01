//����� �����
// ������� ������� ������ ������
#include "point.h"
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
	/*point (const point &p)  
	{
		x = p.x;
		y = p.y;
		cout<<"KK"<<endl;
	};*/
			// �������� ������������
	point &operator =(const point &p)
	{
		if (this  == &p) return *this;
		x =  p.x;
		y =  p.y;
	return *this;//  �� ���������� ����������� - �.�.  ���������� point & 
	};
			// ������� ���������
	//point& operator += (const point& r);
	//point& operator -= (const point& r);
	//point& operator *= (const point& r);
	//point& operator /= (const point& r);

	point& point::operator += (const point& r)
	{
		x = x+r.x;
		y = y+r.y;
		return  *this;
}
	point& point::operator -= (const point& r)
	{
		x = x-r.x;
		y = y-r.y;
		return  *this;
	}
	point& point::operator *= (const point& r)
	{
		x = x*r.x;
		y = y*r.y;
		return  *this;
	}
	point& point::operator /= (const point& r)
	{
		x = x/r.x;
		y = y/r.y;
		return  *this;
	}
// ������� ����� � ����
	//point operator -(void);
	//point& operator +(void);
	point &operator -(void)
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
	point operator ++(int k)//����������� ������
	{
		point d;
		d.x = x++;
		d.y = y++;
	 return d;
	 };
	point &operator ++() //���������� ������
	{
		 ++x;
		 ++y;
	 return *this;
	 };

		// ����������
	point operator --(int k)//����������� ������
	{
		point d;
		d.x = x++;
		d.y = y++;
	 return d;
	 };
	point &operator --()//���������� ������
	{
		 ++x;
		 ++y;
	 return *this;
	 };

		
	point operator -(point &p)//(���������  ��� �������)
	{
		point d;
		d.x = this->x - p.x;    
		d.y = this->y - p.y;
		return d;//   ���������� ����������� - �.�.  ���������� point  
	};

	//point operator -(point &p) //( �� ���������  �������)
	//{
	//	x = this->x - p.x;
	//	y = this->x - p.y;
	//	return *this;
	//};
		
	//friend  point operator +(int k,point& p);
	//friend  point operator -(int k,point& p);
	friend  point operator +(int k,point &p)//�������� � ���������� �����
	{
	 point d;
	 d.x = k + p.x;
	 d.y = k + p.y;
	 return d;
	 }
	point operator +(int k)//�������� � ���������� ������
	{
		 point d;
		 d.x =  x + k ;
		 d.y =  y + k ;
	 return d;
	 };

	
	friend point operator -(int k,point &p)//��������� �� ���������
	{
	 point d;
	 d.x = k - p.x;
	 d.y = k - p.y;
	 return d;
	 }
	point operator -(int k)//��������� ���������
	{
		 point d;
		 d.x =  x - k ;
		 d.y =  y - k ;
	 return d;
	 };
		// ��������� ���������
	//friend bool operator < (const ratio& r1, const ratio& r2);
	//friend bool operator > (const ratio& r1, const ratio& r2);
	//friend bool operator == (const ratio& r1, const ratio& r2);
	//friend bool operator != (const ratio& r1, const ratio& r2);
	//friend bool operator <= (const ratio& r1, const ratio& r2);
	//friend bool operator >= (const ratio& r1, const ratio& r2);
	//friend bool operator < (const ratio& r1, const ratio& r2);

	bool point::operator>= (const point &r) const
	{
		return (x >=  r.x && y >=  r.y);
	}

		// �������� ���������
			//  �������  ���������� �������� (��������� ������������ ��� �������)
	point operator +(point &p)
	{
		point d;
		d.x = this->x + p.x;    //this ����� �� ������
		d.y = this->y + p.y;
		return d;//   ���������� ����������� - �.�.  ���������� point  
	};

		//  �������  ���������� �������� (�� ��������� ������������ ��� ������)
/*	point & operator +(point &p)

	{	x = this->x + p.x;    
		y = this->y + p.y;
		return *this; //  �� ���������� ����������� - �.�.  ���������� point & 
	};
	*/		
	 friend point operator + (const point& p1, const point& p2)
	 {  point d;
		d.x = p1.x + p2.x;//��� ���������� ��������������� ��������, ����. a=b+c+d
		d.y = p1.y + p2.y;
		 return d;
	}
	//friend point operator - (const point& p1, const point& p2);
	//friend point operator * (const point& p1, const point& p2);
	//friend point operator / (const point& p1, const point& p2);

		// ��������� �����-������
	//friend istream& operator>>(istream& in, point& r);
	//friend ostream& operator<<(ostream& out, const point& r);

	 void Print(void)
	{  
		//cout << this->x << this->y << endl;
		cout << x << "   "<< y << endl;
	}
	~point()
	{
		//cout<<"destroy"<<endl;
	}
};
