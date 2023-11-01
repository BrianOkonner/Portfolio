#include <iostream>
using namespace std;
class ex_abstr{ 
//  абстрактный класс с функциями суммы двух объектов и вода объекта на консоль
public:
	// Первый способ
	// абстрактная функция sum (передача параметров по адресу)
virtual	 void sum(  ex_abstr* a, ex_abstr* b)=0;

	// Второй способ
	// абстрактная функция sum2 (передача параметров по ссылкам)
virtual	 void sum2(  ex_abstr& a, ex_abstr& b)=0;
	// абстрактная функция print (без параметров)
virtual void print()=0;
};

// Первый потомок - для работы с целыми числами
class ex_int:public ex_abstr{ 
private:
	int x;
public:
		 ex_int(int xx=0):x(xx){}
	 void sum( ex_abstr* a, ex_abstr* b)
	{	ex_int* Int1= (ex_int*)a;	// приведение указателей к типу ук. на потомка
		ex_int* Int2= static_cast<ex_int*>(b);
		x = Int1->x + Int2->x;
	}
	 void sum2( ex_abstr& a, ex_abstr& b)
	{			
		 // приведение ссылок к типу потомка (через указатель)
		 ex_int& Int1= *((ex_int*)&a); 
		 ex_int& Int2= *((ex_int*)&b);
		x = Int1.x + Int2.x;
	}
	 void print()
	 {
		 cout<< x<< endl;
	 }
};
// Второй потомок - для работы с действительными числами
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
	C= &c;		// Для вызова виртуальных функций первого потомка
				// используется адрес
//-------------вызов виртуальных функций первого потомка
	C->sum(A,B);
	C->print();
	C->sum2(*A,*B);	
	C->print();
				// Для вызова виртуальных функций первого потомка
				// используется ссылка
	C2.sum(A,B); C2.print();

	ex_double a1(5.5),b1(6.6),c1;
	ex_abstr &C3=c1;
	A=&a1; B=&b1;
	C= &c1;		// Для вызова виртуальных функций второго потомка
				// используется адрес
//------------код, идентичный указанному выше	
//-------------вызов виртуальных функций второго потомка
	C->sum(A,B);
	C->print();
	C->sum2(*A,*B);	
	C->print();
				// Для вызова виртуальных функций второго потомка
				// используется ссылка
	C3.sum(A,B); C3.print();
}


