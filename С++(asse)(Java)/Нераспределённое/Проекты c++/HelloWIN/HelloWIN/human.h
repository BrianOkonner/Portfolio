#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;
class creature
{
	string name;
	int level;
	int exp;
	double health;
	double attack;
	double defence;
	inline void recount(int level);
	inline void levelUP();
	int Stat[100];
public:
	void setstat();
	void getstat();
	int gethp() { return health; }
	int getlvl() { return level; }
	bool attacked(creature&a, HDC hdc);
	void attacked1(creature&a);
	string getthename() { return name; }
	int getxp() { return exp; }
	double getattack() { return attack; }
	double getdefence() { return defence; }
	creature(int, string);
	creature(string);
	void showHP();
};
void character(creature&);
void Help();
void menu();

