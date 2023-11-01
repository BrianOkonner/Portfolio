#include <iostream>
#include <string>
using namespace std;
// Шаблон класса 
//  с функциями суммы двух объектов и вывода объекта на консоль
template <class T>
class SUMM{ 
private:
	T x;
	SUMM(){}; // конструктор по умолч.в private-блоке, чтобы не вызывли по умолчанию 
public:
	SUMM(const T& xx):x(xx)	{}
	SUMM(const SUMM& a):x(a.x) {}
	SUMM& operator=( const SUMM& a)
	{	
		x = a.x;
		return *this;
	}
	friend SUMM operator+( const SUMM& a, const SUMM& b);
	friend ostream& operator<<(ostream& out, const SUMM& a);
};
template <class T>
	SUMM<T> operator+( const SUMM<T>& a, const SUMM<T>& b)
	{	
		SUMM<T> c(a);
		c.x += b.x;
		return c;
	}
template <class T>
	ostream& operator<<(ostream& out, const SUMM<T>& a)
	 {
		 out<< a.x<< endl;
		 return out;
	 }

class mystr{
	char * S;
public:
	mystr():S(NULL){}
	mystr(char *s){
		S=new char[strlen(s)+1];
		strcpy(S,s);
	}
	mystr(const mystr& r){
		S=new char[strlen(r.S)+1];
		strcpy(S,r.S);
	}
	mystr& operator=(const mystr& r)
	{
		if (this != &r)
		{
			delete []S;
		S=new char[strlen(r.S)+1];
		strcpy(S,r.S);
		}
		return *this;
	}
	mystr& operator+=(const mystr& r)
	{
		char * X= new char [strlen(S)+ strlen(r.S)+1];
		strcpy(X,S);
		strcat(X,r.S);
			delete []S;
		S=X;
		return *this;
		}
	friend mystr operator+(const mystr& r,const mystr& r2)
	{
		mystr Z(r);
		Z += r2;
		return Z;
	}
	friend ostream& operator<<(ostream& out, const mystr& r)
	{
		out<<r.S<<endl;
		return out;
	}
};
main()
{
	SUMM <int> a(5),b(6);		//demo int
	SUMM <int> c(0);
	c=a+b;
	cout<<a<<b<<c<<endl;

	SUMM <double> a1(5.5),b1(6.7),c1(0.0);	////demo double
	c1=a1+b1;
	cout<<a1<<b1<<c1<<endl;

	SUMM <string> a2("Hello!"),b2("Good bye!"),c2(""); //demo string
	c2=a2+b2;
	cout<<a2<<b2<<c2<<endl;

	mystr x3("Hello!"), y3("Good bye!"), z3("");	//demo свой класс mystr
	SUMM <mystr> a3(x3),b3(y3),c3(z3);
	c3=a3+b3;
	cout<<a3<<b3<<c3<<endl;
}


