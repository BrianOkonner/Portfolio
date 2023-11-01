/*Казанцев Павел Сергеевич
1 курс 8 группа
Лаб.раб. 4  - Класс рациональных дробей

*/

#include "Ratio.h"

int main() {
	setlocale(LC_ALL, "rus");
	Ratio A(2, 3), B(5, 6);
	
	cout << "A = " << A << endl;
	cout << "B = " << B << endl << endl;
	Ratio C = A * B;
	cout << "A * B = " << C << endl;
	C = A / B;
	cout << "A / B = " << C << endl;
	//C = A + B;
	//cout << "A + B = " << C << endl;
	C = A - B;
	cout << "A - B = " << C << endl;
	C = (A++) + (++A);
	cout << "A++ + ++A = " << C << endl;
	//C = C + ++A;
	A--;
	cout << "A-- = " << A << endl;
	A += B;
	cout << "A + =B  = " << A << endl;
	A -= B;
	cout << "A -= B  = " << A << endl;
	A *= B;
	cout << "A *= B  = " << A << endl;
	A /= B;
	cout << "A /= B  = " << A << endl;
	-A;
	cout << "-A = " << A << endl;
	-A;
	cout << "A>B - ?  - " << (A > B) << endl;
	cout << "A<B - ?  - " << (A < B) << endl;
	system("pause");
	return 0;

}