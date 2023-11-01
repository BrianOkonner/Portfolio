/* ласс куб.
ѕозвол€ет рисовать куб по параметрам, которые задает
пользователь (координаты одной из вершин (ближней левой
верхней) и длина ребра).
Ќарисованный куб можно перемещать по рабочей области
окна, измен€ть его размеры (раст€гивать и сжимать).

¬ыполнила студентка 1 курса 7 группы
 унец “ать€на.*/

#pragma once
#include"point.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

class Cub: public Point
{	
public:	int sdvig;
int size;
	Cub():Point(),size(0){}
	bool CanDraw(RECT rect);  //находимс€ ли в границах рабочей области
	Cub(const Point& p,int s1);
	void ChangeSize(const Point& p);  //измен€ет данные при изменении размеров
	void Draw(HWND hwnd); 
};
