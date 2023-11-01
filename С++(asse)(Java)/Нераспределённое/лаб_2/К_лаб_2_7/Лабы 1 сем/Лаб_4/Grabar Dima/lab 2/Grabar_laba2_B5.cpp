/*
15.10.2014
Пм 7 группа
Grabar Dmitry 

5. Вычислить значение ряда:  S= summa((x^(2*n+1))/(2*n+2))*cos 2nx при заданном m, если  х изменяется от a до b с шагом h. Результат получить в виде таблицы.
Значение x изменяется с шагом h. Вывести результат, используя для вычисления функций ряд Тейлора, а также используя встроенную библиотеку math

Идея алгоритма:
Напишем функции cos через ряд Тейлора. В цикле вычислим заданную формулу по условию задачи с помощью нашей функции     *
* синуса и косинуса, а также с помощтю встроенной.
*/

//ТЕСТЫ: 

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   M =          5                                                                      *
*   a =          0                                                                      *
*   b =          3                                                                      *
*   h =        0.3                                                                      *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*       X       *       Tylor COS         *        COS in <math>         *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*         0     *                          0      *                          0          *
*       0.3     *                0.000146755      *                0.000146755          *
*       0.6     *                -0.00313794      *                -0.00313794          *
*       0.9     *                  0.0235688      *                  0.0235688          *
*       1.2     *                   0.522492      *                   0.522492          *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

*/




//Подключаем библиотеки
//Для работы с файлами
#include <fstream>
//Для вывода ошибок и разной отладочной информации
#include <iostream>
//Для использования математический функций. Например sin, cos.
#include <cmath>
#include <iomanip>


//Определяем пространство имен
using namespace std;

//Определяем входной поток и выходной поток
ifstream input;
ofstream output;

const double EPS = 0.000000001;//Ничтожно маленькая величина, необходимая для вычисления погрешности
const double pi = 3.1415926535;

double rad(int A) 
{
	return(pi / 180 * A);
}

double TylorCos(double x) 
{
	double j = 1;
	double res = 0;
	int n = 1;

	//Убираем лишний угол. Отнимаем окружность.
	while ((x >= 2 * pi) || (x <= -2 * pi)) 
	{
		if (x < 0) x = x + 2 * pi;
		else x = x - 2 * pi;
	}
	//Вычисление значения cos
	do {
		res = res + j;
		j = j * (-1 * x * x / ((2 * n) * (2 * n - 1)));
		n++;
		}
	while (fabs(j) > EPS);

	//Дополнительно смотрим погрешность вычислений
	if ((res > 0) && (res <= EPS)) res = 0;
	if ((res < 0) && (res >= -EPS)) res = 0;
	return res;
}

//Функция возведения дробного числа в степень
double ex(double a, int n) {
	double res = 1;
	for (int i = 1; i <= n; i++)
		res = res * a;
	return res;
}

int main() 
{
	//Создаем переменные для входных данных. a, b - промежуток. h - шаг. M - сумма до M-го элемента последовательности
	double a, b, h;
	int M;

	input.open("inputData.txt");
	output.open("outputData.txt");

	//Делаем проверку открытия файла входных данных
	if (input.fail()) {
		cout << "Error! Input file can not be opened!" << endl;
		cout << "Please, create 'inputData.txt' file." << endl;
		system("pause");
		exit(1);
	}

	input >> M >> a >> b >> h;
	output << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	output << "*   M = " << setw(10) << M << "                                                                      *" << endl;
	output << "*   a = " << setw(10) << a << "                                                                      *" << endl;
	output << "*   b = " << setw(10) << b << "                                                                      *" << endl;
	output << "*   h = " << setw(10) << h << "                                                                      *" << endl;
	output << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	output << "*       X       *       Tylor COS         *        COS in <math>         *"                << endl;
	output << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

	double TylorRes = 0;
	double StandartRes = 0;
	int i;
	double x = a;
	double q = x;
	double sum1 = 0,sum2 = 0;
	while((a <= x) && (b >= x)){
		i = 1;
	while (i <= M) 
		{
		//q*=x*x;
		cout<<x<<" "<<q<<" "<<ex(x, 2*i+1)<<endl;
		TylorRes = ex(x, 2*i+1)/(2*i+2);
		//Чтобы не выполнять одно и тоже, просто приравняем
		StandartRes = TylorRes;
		TylorRes = TylorRes * TylorCos(2*i * x);
		StandartRes = StandartRes  * cos(2*i * x);
		sum1+=TylorRes;
		sum2+=StandartRes;
		i++;
	}

	output << "*" << setw(10) << x << "     *" << setw(27) << sum1 << "      *" << setw(27) << sum2 << "          *" << endl;
		
			x = x + h;
	}

	
	output << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	
	return 0;
}

