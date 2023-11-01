#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <ctime>
#include <stack>
#include <array>

#define FILE_PATH1 ("data1.dat")
#define FILE_PATH2 ("data2.dat")
#define FILE_PATH3 ("data3.dat")
#define FILE_PATH4 ("data4.dat")
#define FILE_PATH5 ("data5.dat")
using namespace std;

class Field
{

	struct cell
	{
		array<int,9>choice;
		double cntr_x, cntr_y;
		int number;
	};
	cell temp[9][9];

	double cell_size;
	bool error = 0;
	static int _x, _y;


public:
	//берём цифры от 1 до 9 
	//	проверяем в каждой клетке по порядку возможность установки цифры




	//  ставим цифру в первую незаполненную клетку
	//	проверяем есть ли ошибка
	//	если нет ставим цифру в следующую незаполненную клетку
	//	опять проверяем на ошибку и так далее
	//	если нахожим ошибку откатываемся на шаг назад
	//	меняем цифру и продолжаем рассуждение
	cell a[9][9];
	void solve(HDC hdc)
	{
		int min_i = 0, min_j = 0;
		srand(time(0));
	g1:
		for (int u = 0; u < 81; u++)
		{
			int c = 1;
			for (int q = 0; q < 20; q++)
			{


				for (int i = 0; i < 9; i++)// цикл по строкам
				{
					for (int j = 0; j < 9; j++) // цикл по столбцам
					{
						if (a[i][j].number == 0)
						{
							/*if (a[i][j].choice.size() != 0)
								a[i][j].choice.clear();*/
							for (c = 1; c <= 9; c++) // цикл по цифре в клетке
							{

								for (int i_col = 0; i_col < 9; i_col++)
								{
									if (a[i][i_col].number == 0 && (*this).iferror(c, i, i_col) == 0 && i_col != j) { break; }
									if ((*this).iferror(c, i, j) == 0 && i_col == 8)a[i][j].number = c;
								}
								if (a[i][j].number)break;
								for (int i_row = 0; i_row < 9; i_row++)
								{
									if (a[i_row][j].number == 0 && (*this).iferror(c, i_row, j) == 0 && i_row != i) { break; }
									if ((*this).iferror(c, i, j) == 0 && i_row == 8)a[i][j].number = c;
								}
								if (a[i][j].number)break;



								a[i][j].number = c;
								//	if ((*this).iferror(c, i, j) == 0) { a[i][j].choice[0]=c; }
								////	if (c == 9 && a[i][j].choice.size() < 2 && a[i][j].choice.size() != 0) { a[i][j].number = a[i][j].choice.back(); a[i][j].choice.pop_back(); }

								//	//if ((*this).iferror(c, i, j) == 0) { a[i][j].count++; a[i][j].memory[a[i][j].num_of_mem++] = c; }
								//	//if (c == 9 && a[i][j].count < 2) a[i][j].number = a[i][j].memory[a[i][j].num_of_mem - 1];
								//	error = 0;
								//}
								//if (a[i][j].choice.size() > 1) { a[i][j].number = 0; error = 0; }

							}
						}
					}
				}
			}
		}
				(*this).printexample(hdc);
		//	}
		//	if ((*this).solved()) return;

		//	int min = 9;

		//	for (int i = 0; i < 9; i++)// цикл по строкам
		//	{
		//		for (int j = 0; j < 9; j++) // цикл по столбцам
		//		{
		//			if (a[i][j].choice.size() <= min && a[i][j].choice.size())
		//			{
		//				min = a[i][j].choice.size();
		//				min_i = i; min_j = j;
		//			}
		//		}
		//	}
		//	if (u == 0)
		//		for (int i = 0; i < 9; i++)// цикл по строкам
		//			for (int j = 0; j < 9; j++) // цикл по столбцам
		//				temp[i][j].number = a[i][j].number;
		//	if (a[min_i][min_j].choice.size() > 0)
		//	{
		//		a[min_i][min_j].number = a[min_i][min_j].choice.back();
		//		//a[min_i][min_j].choice.pop_back();
		//	}
		//}

		//for (int i = 0; i < 9; i++)// цикл по строкам
		//	for (int j = 0; j < 9; j++) // цикл по столбцам
		//		a[i][j].number = temp[i][j].number;
		//goto g1;


	}

	bool iferror(int number, int x, int y)
	{
		error = 0;
		a[x][y].number = number;
		for (int i = 0; i < 9; i++)
			if ((a[x][y].number == a[x][i].number) && y != i)
			{
				error = 1; a[x][y].number = 0; return 1;
			}
		for (int i = 0; i < 9; i++)
			if (a[x][y].number == a[i][y].number&& x != i)
			{
				error = 1; a[x][y].number = 0; return 1;
			}
		if (x / 3 == 0 && y / 3 == 0)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (a[x][y].number == a[i][j].number && (x != i || y != j))
					{
						error = 1;
						a[x][y].number = 0;
						return 1;
					}
		}

		if (x / 3 == 1 && y / 3 == 0)
		{
			for (int i = 3; i < 6; i++)
				for (int j = 0; j < 3; j++)
					if (a[x][y].number == a[i][j].number && (x != i || y != j))
					{
						error = 1;
						a[x][y].number = 0;
						return 1;
					}
		}
		if (x / 3 == 2 && y / 3 == 0)
		{
			for (int i = 6; i < 9; i++)
				for (int j = 0; j < 3; j++)
					if (a[x][y].number == a[i][j].number && (x != i || y != j))
					{
						error = 1;
						a[x][y].number = 0;
						return 1;
					}
		}
		if (x / 3 == 0 && y / 3 == 1)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 3; j < 6; j++)
					if (a[x][y].number == a[i][j].number && (x != i || y != j))
					{
						error = 1;
						a[x][y].number = 0;
						return 1;
					}
		}
		if (x / 3 == 1 && y / 3 == 1)
		{
			for (int i = 3; i < 6; i++)
				for (int j = 3; j < 6; j++)
					if (a[x][y].number == a[i][j].number && (x != i || y != j))
					{
						error = 1;
						a[x][y].number = 0;
						return 1;
					}
		}
		if (x / 3 == 2 && y / 3 == 1)
		{
			for (int i = 6; i < 9; i++)
				for (int j = 3; j < 6; j++)
					if (a[x][y].number == a[i][j].number && (x != i || y != j))
					{
						error = 1;
						a[x][y].number = 0;
						return 1;
					}
		}
		if (x / 3 == 0 && y / 3 == 2)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 6; j < 9; j++)
					if (a[x][y].number == a[i][j].number && (x != i || y != j))
					{
						error = 1;
						a[x][y].number = 0;
						return 1;
					}
		}
		if (x / 3 == 1 && y / 3 == 2)
		{
			for (int i = 3; i < 6; i++)
				for (int j = 6; j < 9; j++)
					if (a[x][y].number == a[i][j].number && (x != i || y != j))
					{
						error = 1;
						a[x][y].number = 0;
						return 1;
					}
		}
		if (x / 3 == 2 && y / 3 == 2)
		{
			for (int i = 6; i < 9; i++)
				for (int j = 6; j < 9; j++)
					if (a[x][y].number == a[i][j].number && (x != i || y != j))
					{
						error = 1;
						a[x][y].number = 0;
						return 1;
					}
		}
		a[x][y].number = 0;
		return error;
	}
	void test()
	{
		a[0][0].number = 2;	a[0][3].number = 5; a[0][6].number = 8; a[0][8].number = 3;
		a[1][2].number = 6; a[1][4].number = 4; a[1][5].number = 9;
		a[2][0].number = 5; a[2][1].number = 1; a[2][5].number = 2; a[2][7].number = 4; a[2][8].number = 9;
		a[3][0].number = 4; a[3][1].number = 6; a[3][6].number = 9; a[3][7].number = 1; a[3][8].number = 5;
		a[4][3].number = 1; a[4][5].number = 3;
		a[5][0].number = 9; a[5][1].number = 2; a[5][2].number = 1; a[5][7].number = 8; a[5][8].number = 7;
		a[6][0].number = 8; a[6][1].number = 3; a[6][3].number = 4; a[6][7].number = 6; a[6][8].number = 2;
		a[7][3].number = 3; a[7][4].number = 7; a[7][6].number = 5;
		a[8][0].number = 6; a[8][2].number = 7; a[8][5].number = 8; a[8][8].number = 4;
	}
	void printexample(HDC hdc)
	{
		HFONT font = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");
		SelectObject(hdc, font);
		char buf[2];
		buf[1] = '0';
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				if (a[i][j].number)
				{
					_itoa_s(a[i][j].number, buf, 10);
					TextOut(hdc, a[i][j].cntr_x - 10, a[i][j].cntr_y - 17, (LPSTR)buf, 1);
				}
			}
	}
	void clear()
	{
		error = false;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				a[i][j].number = 0;
	}
	bool iferror(int number)
	{
		a[_x][_y].number = number;
		for (int i = 0; i < 9; i++)
			if ((a[_x][_y].number == a[_x][i].number) && _y != i)
			{
				error = 1; return 1;
			}
		for (int i = 0; i < 9; i++)
			if (a[_x][_y].number == a[i][_y].number&& _x != i)
			{
				error = 1; return 1;
			}
		error = 0;
		if (_x / 3 == 0 && _y / 3 == 0)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (a[_x][_y].number == a[i][j].number && (_x != i || _y != j))
					{
						error = 1;
						return 1;
					}
		}

		if (_x / 3 == 1 && _y / 3 == 0)
		{
			for (int i = 3; i < 6; i++)
				for (int j = 0; j < 3; j++)
					if (a[_x][_y].number == a[i][j].number && (_x != i || _y != j))
					{
						error = 1;
						return 1;
					}
		}
		if (_x / 3 == 2 && _y / 3 == 0)
		{
			for (int i = 6; i < 9; i++)
				for (int j = 0; j < 3; j++)
					if (a[_x][_y].number == a[i][j].number && (_x != i || _y != j))
					{
						error = 1;
						return 1;
					}
		}
		if (_x / 3 == 0 && _y / 3 == 1)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 3; j < 6; j++)
					if (a[_x][_y].number == a[i][j].number && (_x != i || _y != j))
					{
						error = 1;
						return 1;
					}
		}
		if (_x / 3 == 1 && _y / 3 == 1)
		{
			for (int i = 3; i < 6; i++)
				for (int j = 3; j < 6; j++)
					if (a[_x][_y].number == a[i][j].number && (_x != i || _y != j))
					{
						error = 1;
						return 1;
					}
		}
		if (_x / 3 == 2 && _y / 3 == 1)
		{
			for (int i = 6; i < 9; i++)
				for (int j = 3; j < 6; j++)
					if (a[_x][_y].number == a[i][j].number && (_x != i || _y != j))
					{
						error = 1;
						return 1;
					}
		}
		if (_x / 3 == 0 && _y / 3 == 2)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 6; j < 9; j++)
					if (a[_x][_y].number == a[i][j].number && (_x != i || _y != j))
					{
						error = 1;
						return 1;
					}
		}
		if (_x / 3 == 1 && _y / 3 == 2)
		{
			for (int i = 3; i < 6; i++)
				for (int j = 6; j < 9; j++)
					if (a[_x][_y].number == a[i][j].number && (_x != i || _y != j))
					{
						error = 1;
						return 1;
					}
		}
		if (_x / 3 == 2 && _y / 3 == 2)
		{
			for (int i = 6; i < 9; i++)
				for (int j = 6; j < 9; j++)
					if (a[_x][_y].number == a[i][j].number && (_x != i || _y != j))
					{
						error = 1;
						return 1;
					}
		}

		return error;
	}
	Field()
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				a[i][j].number = 0;
	}
	void Field1(int cx, int cy)
	{
		cell_size = cx / 9;
		int start_x = cx / 18 + 4, start_y = cy / 18;
		for (int i = 0; i < 9; i++)
		{
			a[i][0].cntr_x = start_x;
			a[i][0].cntr_y = start_y + (cy*i) / 9;

			for (int j = 1; j < 9; j++)
			{
				a[i][j].cntr_x = a[i][j - 1].cntr_x + cx / 9;
				a[i][j].cntr_y = a[i][j - 1].cntr_y;
			}
		}
	}
	double count_x(int x, int number)
	{

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				if (abs(a[i][j].cntr_x - x) < cell_size / 2.)
				{
					this->_y = j;
					return a[i][j].cntr_x;
				}
		}
		return 0;
	}
	double count_x(int x)
	{

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (abs(a[i][j].cntr_x - x) < cell_size / 2.)
					return a[i][j].cntr_x;
		return 0;
	}
	double count_y(int y, int number)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (abs(a[i][j].cntr_y - y) < cell_size / 2.)
				{
					this->_x = i;
					return a[i][j].cntr_y;
				}
		return 0;
	}
	double count_y(int y)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (abs(a[i][j].cntr_y - y) < cell_size / 2.)
					return a[i][j].cntr_y;
		return 0;
	}
	void clear_cell(int x, int y)
	{
		int X, Y;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (abs(a[i][j].cntr_x - x) < cell_size / 2.)
					Y = j;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (abs(a[i][j].cntr_y - y) < cell_size / 2.)
					X = i;
		a[X][Y].number = 0;
	}
	bool solved()
	{
		if (error == 1)return 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (!a[i][j].number)return 0;
		return 1;
	}
};
int Field::_x;
int Field::_y;