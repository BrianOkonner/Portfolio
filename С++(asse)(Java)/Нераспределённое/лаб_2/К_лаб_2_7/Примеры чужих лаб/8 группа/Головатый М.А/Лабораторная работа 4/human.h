#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;
class creature
{
	string name;
	int level;
	int xp;
	double health;
	double attack;
	double defence;
	inline void recount(int level);
	inline void levelUP();
	int Stat[100];
	
	//Stat statistic[10000];
public:
	void setstat();
	void getstat();
	int gethp() { return health; }
	int getlvl() { return level; }
	bool attacked(creature&a);
	void attacked1(creature&a);
	string getthename() { return name; }
	int getxp() { return xp; }
	double getattack() { return attack; }
	double getdefence() { return defence; }
	creature(int,string);
	creature(string);
	void showHP();
};
void character(creature&);
void Help();
void menu();

