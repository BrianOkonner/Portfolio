/*	
	������ ����������
		8 ������

B10         ����� ���������� ������ �� � , ��������� ������������ �����������:
		Xi=Xi-1/2 + A/(2*Xi-1 ), ��� �0 =�,  � ���������  0.0001.
		����  � ���������� �� d �� b � ����� h.  ���������� �������� � ���� �������.

	double msqrt(double a){
	double x0 = a, zn = 1;
	double e = 0.0001;
	if (a == 0) return 0;
	while (fabs(a / (zn*zn) - 1) > e) {                 
		zn = (x0 + a / x0) / 2;
		x0 = zn;
	}
	return 0;
}
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

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

void Input(double &d, double &b, double &h) {
	setlocale(0, "rus");
	cout << "������� ������ ������� - ";
	cin >> d;
	cout << "������� ������� ������� - ";
	cin >> b;
	cout << "������� ��� - ";
	cin >> h;
	cout << endl;

	if (d > b) {
		double tmp = d;
		d = b;
		b = tmp;
	}

	if (h > b - d || h == 0) {                                     
		cout << "������������ ���" << endl;;
		return;
	}

	if (d < 0 || b < 0) {                                             
		cout << "������������ ����������";
		return;
	}
}

double MySqrt(double a) {
	double e = 0.0001, copy = a, zn = 1, d2 = 2;
	if (a == 0) return 0;
	_asm {
		finit
L1 :
		//-----���������� �������� �����------------------------
			finit					// ������� ��������� �����
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

		//--------���������� ����� ��� ����� ��������-----------
			finit					// ������� ��������� �����
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
			fcomi st, st(1)				// ��������� � �������� + ��������� ������
			jb L1					// ������� �� �����, ���� �� ����������� ��������
	}
	return zn;
}

int main(){
	double d = 0, b = 0, h = 0, a = 0;
	Input(d, b, h);

	ofstream out("Output.txt");
	cout << "***********************************************************" << endl;
	cout << "**   �����      **    ����������    **     ����������    **" << endl;
	cout << "***********************************************************" << endl;
	for (; d <= b; d += h){
		cout << "**    " << left << setw(6) << d << "    **    " << left << setw(10) << AsmF(d) << "    **     " <<left << setw(10) << MySqrt(d) << "    **" << endl;
	}
	cout << "***********************************************************" << endl;
	cout << "***********************************************************" << endl;
	cout << endl << endl << endl;

	out.close();
	system("pause");
	return 0;
}