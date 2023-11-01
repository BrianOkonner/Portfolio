//Класс точка
// Функции описаны внутри класса
#include <conio.h>
#include <iostream>
using namespace std;
class point
{  protected:                 //Защищенные данные класса
	int x,y;                  //Координаты точки
 public:
	char *str;
	point(int xi=0,int yi=0)  //Конструктор
//Описание внутри класса
		{ x=xi;y=yi; };

	point (const point &p)  //Конструктор копирования
	{
		x = p.x;
		y = p.y;
	};

//  компонентная функции  перегрузка сложения //сохраняет складываемые два объекта
point operator +(point &p)
	{
		point d;
		d.x = this->x + p.x;    //this Можно не писать
		d.y = this->y + p.y;
		return d; ;//   вызывается конструктор - //т.к.  возвращает point  

	};
	
//  компонентная функции  перегрузка сложения не //сохраняет складываемые два обекта
/*	point & operator +(point &p)

	{	x = this->x + p.x;    //this Можно не писать
		y = this->y + p.y;
		return *this;//  не вызывается конструктор //- т.к.  возвращает point & 
	};
	*/					
	
point &operator =(const point &p)
	{
	if (this  == &p) return *this;
	x =  p.x;
	y =  p.y;
	return *this;//  не вызывается конструктор - т.к.  //возвращает point & 
	};

  	point &operator -(void)
	{
		x = -x;
		y = -y;
		return *this;
	};

	point operator -(point &p)
	{
		x = x - p.x;
		y = x - p.y;
		return *this;
	};

	point &operator -(int k)
	{
	
	 point d;
	 d.x =  x - k ;
	 d.y =  y - k ;
	 return d;
	 };

	point operator ++(int k)//постфиксная запись
	{
	 point d;
	 d.x = x++;
	 d.y = y++;

	 return d;
	 };

	point &operator ++()
	{
		 ++x;
		 ++y;
	 return *this;
	 };
bool operator>= (const point &r) const
{
	return (x >=  r.x && y >=  r.y);
}
	~point()
	{
		//cout<<"destroy"<<endl;
	}


	 void Print(void)
{  //cout << this->x << this->y << endl;
	cout << x << "   "<< y << endl;
	}

friend  point operator +(int k,point& p);
friend  point operator -(int k,point& p);
//friend  point operator ++(point& p);
friend  point operator +(const point& p,const point& p1);
		};
//  компонентная friend функции  перегрузка сложения  c константой слева
	point operator +(int k,point &p)
	{
	 point d;
	 d.x = k + p.x;
	 d.y = k + p.y;
	 return d;
	 }

//  компонентная friend функции  перегрузка вычитания  c константой слева
	point operator -(int k,point &p)
	{
	 point d;
	 d.x = k - p.x;
	 d.y = k - p.y;
	 return d;
	 }
//  перегрузка унарного оператора 
//с помощью friend функции 
    /*point operator ++(point& p)
     { point d;
     d=p.x++;
     d=p.y++;
     return d;}
	 */
//  компонентная friend функции 
 //перегрузка сложения
point operator +( const point &p,const point &p1)
	{  // Нельзя B=B+A, только С=B+А
	 point d;
	 d.x = p1.x + p.x;//для сохранения первоначального значения, напр. a=b+c+d
	 d.y = p1.y + p.y;
	 return d;
	}


//  Описание вне класса
//   point::point(int xi,int yi)
//{x=xi;y=yi;}
void main()
{

	point A(10,10),  B(20,20);
	point C(30,30),D;
	A=A+B;
	A.Print();

   

	
}
