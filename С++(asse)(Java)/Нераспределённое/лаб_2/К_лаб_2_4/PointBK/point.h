//Класс точка
// Функции описаны внутри класса
#include <iostream>
using namespace std;
class point
{  //protected:                 //Защищенные данные класса
	int x,y;                  //Координаты точки
 public:
	char *str;
			//Конструкторы
	point(int xi=10,int yi=0) { x=xi;y=yi; };
//	point():x(0), y(0) { } 
//	point(int xi,int yi):x(xi), y(yi){ }  
			//Конструктор копирования
	point (const point &p); 
	
			// оператор присваивания
	point &operator =(const point &p);
	
			// унарные операторы
	//point& operator += (const point& r);
	//point& operator -= (const point& r);
	//point& operator *= (const point& r);
	//point& operator /= (const point& r);

	point& point::operator += (const point& r);
	
	point& point::operator -= (const point& r);
	
	point& point::operator *= (const point& r);

	point& point::operator /= (const point& r);
	
// унарный минус и плюс
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
	// увеличение
	point operator ++(int k);//постфиксная запись
	
	point &operator ++(); //префиксная запись
	
		// уменьшение
	point operator --(int k);//постфиксная запись
	
	point &operator --();//префиксная запись
	

		
	point operator -(point &p);//(сохраняет  два объекта)
	
	//point operator -(point &p) //( не сохраняет  объекты)
	//{
	//	x = this->x - p.x;
	//	y = this->x - p.y;
	//	return *this;
	//};
		
	//friend  point operator +(int k,point& p);
	//friend  point operator -(int k,point& p);
	friend  point operator +(int k,point &p);//Сложение с константой слева
	
	point operator +(int k);//Сложение с константой справа
	
	
	friend point operator -(int k,point &p);//Вычитание из константы
	
	point operator -(int k);//Вычитание константы
	
		// операторы сравнения
	//friend bool operator < (const ratio& r1, const ratio& r2);
	//friend bool operator > (const ratio& r1, const ratio& r2);
	//friend bool operator == (const ratio& r1, const ratio& r2);
	//friend bool operator != (const ratio& r1, const ratio& r2);
	//friend bool operator <= (const ratio& r1, const ratio& r2);
	//friend bool operator >= (const ratio& r1, const ratio& r2);
	//friend bool operator < (const ratio& r1, const ratio& r2);

	bool operator>= (const point &r) const;

		// бинарные операторы
			//  функция  перегрузки сложения (сохраняет складываемые два объекта)
	point operator +(point &p);

		//  функция  перегрузки сложения (не сохраняет складываемые два обекта)
/*	point & operator +(point &p)

	{	x = this->x + p.x;    
		y = this->y + p.y;
		return *this; //  не вызывается конструктор - т.к.  возвращает point & 
	};
	*/		
	 friend point operator + (const point& p1, const point& p2);
	 
	//friend point operator - (const point& p1, const point& p2);
	//friend point operator * (const point& p1, const point& p2);
	//friend point operator / (const point& p1, const point& p2);

		// операторы ввода-вывода
	//friend istream& operator>>(istream& in, point& r);
	//friend ostream& operator<<(ostream& out, const point& r);

	 void Print(void); 
	~point();	
};

		