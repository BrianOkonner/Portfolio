#include "Header.h"

void Input(double &d, double &b, double &h) {
	setlocale(0, "rus");
	cout << "Введите нижнюю границу - ";
	cin >> d;
	cout << "Введите верхнюю границу - ";
	cin >> b;
	cout << "Введите шаг - ";
	cin >> h;
	cout << endl;

	if (d > b) {
		double tmp = d;
		d = b;
		b = tmp;
	}

	if (h > b - d || h == 0) {
		cout << "Некорректный шаг" << endl;;
		return;
	}

	if (d < 0 || b < 0) {
		cout << "Некорректный промежуток";
		return;
	}
}

double AsmF(double a) {
	double Asmsqrt;
	_asm {
		finit
		fld a
		fsqrt
		fst Asmsqrt
	}
	return Asmsqrt;
}

double MySqrt(double a) {
	double e = 0.0001, copy = a, zn = 1, d2 = 2;
	if (a == 0) return 0;
	_asm {
		finit
		L1 :
		//-----Вычисление значения корня------------------------
		finit					// Очистка регистров стека
			fld a					// st0 = a
			fld copy				// st0 = copy; st1 = a
			fdiv					// st0 = st1 / st0 = a / copy
			fld copy				// st0 = copy; st1 = a / copy 
			fadd					// st0 = copy + a / copy
			fld d2					// st0 = 2; st1 = copy + a / copy
			fdiv					// st0 = st1 / st0 = (copy + a / copy) / 2
			fst zn					// zn = (copy + a / copy) / 2
			fld zn					// copy  = 
			fst copy				//			 zn

									//--------Реализация цикла для учета точности-----------
			finit					// Очистка регистров стека
			fld zn					// st0 = zn
			fld zn					// st0 = zn; st1 = zn
			fmul					// st0 = zn * zn
			fld a					// st0 = a; st1 = zn * zn
			fxch st(1)				// st0 = zn * zn; st1 = a
			fdiv					// st0 = a / (zn * zn)
			fld1					// st0 = 1; st1 = a / (zn * zn)
			fxch st(1)				// st0 = a / (zn * zn); st1 = 1
			fsub					// st0 = a / (zn * zn) - 1
			fabs					// st0 = abs (a / (zn * zn) - 1)
			fld e					// st0 = e; st1 = abs (a / (zn * zn) - 1)
			fcomi st, st(1)			// Сравнение с точности + установка флагов
			jb L1					// Возврат на метку, если не достаточная точность
	}
	return zn;
}