/*����� ���.
��������� �������� ��� �� ����������, ������� ������
������������ (���������� ����� �� ������ (������� �����
�������) � ����� �����).
������������ ��� ����� ���������� �� ������� �������
����, �������� ��� ������� (����������� � �������).

��������� ��������� 1 ����� 7 ������
����� �������.*/

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
	bool CanDraw(RECT rect);  //��������� �� � �������� ������� �������
	Cub(const Point& p,int s1);
	void ChangeSize(const Point& p);  //�������� ������ ��� ��������� ��������
	void Draw(HWND hwnd); 
};
