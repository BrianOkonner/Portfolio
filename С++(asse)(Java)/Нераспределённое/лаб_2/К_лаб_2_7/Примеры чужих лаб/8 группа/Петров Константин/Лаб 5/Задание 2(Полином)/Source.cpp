/*		
	Петров Константин
	8 группа
	Лаб 5 
	Задание 2. Класс полином.
*/

#include"Header.h"

int main() {
	try {
		Polynom a(1., 1., 2.), b(1., 1., 2.);
		a *= (b*2 + b/3)*(a+3);
		a.DisplayCoeff();
		cout << endl;
	}
	catch (PolynomExceptions &exc) {
		cout << exc.what() << endl;
		cout<<exc.GetDataState()<<endl;
	}
	return 0;
}


