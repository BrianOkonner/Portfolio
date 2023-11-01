#include "human.h"



creature::creature(string name)
{
	this->name = name;
	level = 1; exp = 0; health = 80; attack = 10; defence = 5;
}
creature::creature(int level, string name)
{
	this->name = name;
	this->level = level;
	health = level * 20;
	attack = level * 4;
	defence = level * 2;
}

bool creature::attacked(creature&a, HDC hdc)
{
	bool flag=false;
	(*this).showHP();
	menu();
	double multiply_attack = 1 - 0.05*a.defence / (1 + (0.05*a.defence));
	double damage = attack * multiply_attack;
	a.health -= damage;
	if (a.gethp() <= 0)
	{
		Stat[a.getlvl()]++;
		if (a.name == "BOSS")
		{
			for (;;) {}
		}
		if (exp >= level * 40)
		{
			levelUP();
		}
		exp += a.level * 5;
		a.health = a.level * 20;
		flag = true;
	}
	if (exp >= level * 40)
	{
		levelUP();
	}
	return flag;
	//cout << a.name<<" has " << a.gethp() << " hp\n";
}
void creature::attacked1(creature&a)
{
	double multiply_attack = 1 - 0.05*a.defence / (1 + (0.05*a.defence));
	double damage = attack * multiply_attack;
	a.health -= damage;
	//exp += damage;
	/*if (exp >= level * 50)
	{
	levelUP();
	}*/
}
void creature::levelUP()
{
	exp %= 40;
	level++;
	recount(level);
}
void creature::recount(int level)
{
	this->level = level;
	health = level * 80;
	attack = level * 7;
	if (defence <= 30)
		defence += (double)level / 2;
}
void character(creature&hero)
{
	system("cls");
	cout << "Name " << hero.getthename() << "\n"
		<< "Level " << hero.getlvl() << "\n"
		<< "EXP " << hero.getxp() << "/" << hero.getlvl() * 40 << "\n"
		<< "Health " << hero.gethp() << "\n"
		<< "Attack " << hero.getattack() << "\n"
		<< "Defence " << hero.getdefence() << "\n";
}
void creature::setstat()
{
	for (int i = 0; i < 100; i++)
		Stat[i] = 0;
}
void creature::getstat()
{
	system("cls");
	cout << "Вы убили: \n";
	for (int i = 0; i < 100; i++)
	{
		if (Stat[i])
			cout << Stat[i] << " персонажей " << i << "-го уровня\n";
	}
}
void Help()
{
	cout << "Уровень врагов повышается с возрастанием циферки у имени. Убивая врагов вы получаете опыт.Чем больше опыта, тем выше уровень\n" <<
		"Чем выше уровень, тем лучше характеристики. Получая новый уровень, вы восстанавливаете всё здоровье. Удачи!";
}
void menu()
{
	cout << "You have to kill the BOSS:\n";
	cout << "1: ennemy1\n2: ennemy2\n3: ennemy3\n4: ennemy4\n5: ennemy5\n6: BOSS\n7: help\n8: give up\n";
}
void creature::showHP()
{
	_int16 abc = 3;
	for (int i = 0; i < (health / (level * 8)) * 10; i++)
		cout << (char)164;
	cout << "\n";
}