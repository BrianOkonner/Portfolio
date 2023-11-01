//Класс точка
#include "class_point_h.h"
#include <iostream>
using namespace std;
point::point()
{  x=1;y=1;
}
	point::point(int p1 , int p2 )
	{  x=p1;y=p2;
     }
	point::	~point(){}
	point::point (const point &p)  
	{
		x = p.x;
		y = p.y;
	}
			// оператор присваивания
	point & point::operator =(const point &p)
	{
		if (this  == &p) return *this;
		x =  p.x;
		y =  p.y;
	return *this;//  не вызывается конструктор - т.к.  возвращает point & 
	}
		 point operator +(const point &p1,const point &p2)//Вычитание из константы
	{
	 point d;
	 d.x = p1.x + p2.x;
	 d.y = p1.y + p2.y;
	 return d;
	 }		

	  bool  operator ==(const point &p1,const point &p2)                                 
	{
	 point d;
	 if (p1.x ==p2.x&& p1.y == p2.y)return 1;
	  else return 0;
	 }	
//	point& point::operator += (const point& r)
//	{
//		x = x+r.x;
//		y = y+r.y;
//		return  *this;
//}
//	point& point::operator -= (const point& r)
//	{
//		x = x-r.x;
//		y = y-r.y;
//		return  *this;
//	}
//	point& point::operator *= (const point& r)
//	{
//		x = x*r.x;
//		y = y*r.y;
//		return  *this;
//	}
//	point& point::operator /= (const point& r)
//	{
//		x = x/r.x;
//		y = y/r.y;
//		return  *this;
//	}
//// унарный минус и плюс
//	//point operator -(void);
//	//point& operator +(void);
//	point &operator -(void)
//	{
//		x = -x;
//		y = -y;
//		return *this;
//	};
//	///*point operator -(void)
//	//{	
//	//	point r;
//	//	r.n = -n;
//	//	r.d = d;
//	//	return r;
//	//}*/
//	point& operator +(void)
//	{
//		return *this;
//	}
//	// увеличение
//	point operator ++(int k)//постфиксная запись
//	{
//		point d;
//		d.x = x++;
//		d.y = y++;
//	 return d;
//	 };
//	point &operator ++() //префиксная запись
//	{
//		 ++x;
//		 ++y;
//	 return *this;
//	 };
//
//		// уменьшение
//	point operator --(int k)//постфиксная запись
//	{
//		point d;
//		d.x = x++;
//		d.y = y++;
//	 return d;
//	 };
//	point &operator --()//префиксная запись
//	{
//		 ++x;
//		 ++y;
//	 return *this;
//	 };

//		
//	point operator -(point &p)//(сохраняет  два объекта)
//	{
//		point d;
//		d.x = this->x - p.x;    
//		d.y = this->y - p.y;
//		return d;//   вызывается конструктор - т.к.  возвращает point  
//	};
//
//	//point operator -(point &p) //( не сохраняет  объекты)
//	//{
//	//	x = this->x - p.x;
//	//	y = this->x - p.y;
//	//	return *this;
//	//};
//		
//	//friend  point operator +(int k,point& p);
//	//friend  point operator -(int k,point& p);
//	friend  point operator +(int k,point &p)//Сложение с константой слева
//	{
//	 point d;
//	 d.x = k + p.x;
//	 d.y = k + p.y;
//	 return d;
//	 }
//	point operator +(int k)//Сложение с константой справа
//	{
//		 point d;
//		 d.x =  x + k ;
//		 d.y =  y + k ;
//	 return d;
//	 };
//
//	
//	friend point operator -(int k,point &p)//Вычитание из константы
//	{
//	 point d;
//	 d.x = k - p.x;
//	 d.y = k - p.y;
//	 return d;
//	 }
//	point operator -(int k)//Вычитание константы
//	{
//		 point d;
//		 d.x =  x - k ;
//		 d.y =  y - k ;
//	 return d;
//	 };
//		// операторы сравнения
//	//friend bool operator < (const ratio& r1, const ratio& r2);
//	//friend bool operator > (const ratio& r1, const ratio& r2);
//	//friend bool operator == (const ratio& r1, const ratio& r2);
//	//friend bool operator != (const ratio& r1, const ratio& r2);
//	//friend bool operator <= (const ratio& r1, const ratio& r2);
//	//friend bool operator >= (const ratio& r1, const ratio& r2);
//	//friend bool operator < (const ratio& r1, const ratio& r2);
//
//	bool operator>= (const point &r) const
//	{
//		return (x >=  r.x && y >=  r.y);
//	}
//
//		// бинарные операторы
//			//  функция  перегрузки сложения (сохраняет складываемые два объекта)
//	point operator +(point &p)
//	{
//		point d;
//		d.x = this->x + p.x;    //this Можно не писать
//		d.y = this->y + p.y;
//		return d;//   вызывается конструктор - т.к.  возвращает point  
//	};
//
//		//  функция  перегрузки сложения (не сохраняет складываемые два обекта)
///*	point & operator +(point &p)
//
//	{	x = this->x + p.x;    
//		y = this->y + p.y;
//		return *this; //  не вызывается конструктор - т.к.  возвращает point & 
//	};
//	*/		
//	 friend point operator + (const point& p1, const point& p2)
//	 {  point d;
//		d.x = p1.x + p2.x;//для сохранения первоначального значения, напр. a=b+c+d
//		d.y = p1.y + p2.y;
//		 return d;
//	}
//	//friend point operator - (const point& p1, const point& p2);
//	//friend point operator * (const point& p1, const point& p2);
//	//friend point operator / (const point& p1, const point& p2);
//
		// операторы ввода-вывода
	/*friend istream& operator>>(istream& in, point& r);
	friend ostream& operator<<(ostream& out, const point& r);*/
//
//	 void Print(void)
//	{  
//		//cout << this->x << this->y << endl;
//		cout << x << "   "<< y << endl;
//	}
//	~point()
//	{
//		cout<<"destroy"<<endl;
//	}
//};


ostream& operator<<(ostream& out, const point& p)
{
	out<<p.x<<" "<<p.y<<endl;
		return out;
}
 istream& operator>>(istream& in, point& p)

{
	
		cout<<"x=";
		in>>p.x;
		cout<<"y=";
		in>>p.y;
		
	return in;
}
