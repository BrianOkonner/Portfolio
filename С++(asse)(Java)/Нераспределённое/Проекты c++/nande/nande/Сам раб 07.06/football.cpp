/*Перевязчиков Владислав
  8 группа
  
  Учловие:Вывести таблицы для каждой группы в текстовый файл 
  GroupsOut.txt. Перед каждой группой ее название.
  В файл Results.txt записать результаты всех матчей.
*/
/*#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class group 
{
public:
	struct team
	{
	public:
		char *name;
		int score;
		int vins;
		int draw;
		int lose;
		int goal;
		int lgoal;
	};
	team tm[4];
	char tag;
	~group()
	{
		for(int i=0;i<4;i++)
			delete tm[i].name;
	}
	int score(istream& in,char *name)
	{
		char bf[100];
		while(!in.eof())
		{
			in.getline(bf,100);
		}
	}
};
class result
{
	char * name;
	int score;
	int number;
};
int main()
{
	setlocale(LC_ALL,"rus");
	ofstream outt("GroupsOut.txt"),outg("Results.txt");
	ifstream inp("Game.txt"),ing("Groups.txt");
	char * bf;
	bf=new char[100];
	char tag;
	int i=0,k,ngr,count;
	group *gr;
	while(!ing.eof())
	{
		ing.getline(bf,100);
		i++;
	}
	ngr=i;
	i=0;
	while(!inp.eof())
	{
		inp.getline(bf,100);
		i++;
	}
	count=i;
	k=count/ngr;
	inp.clear();
	ing.clear();
	ing.seekg(0,ios::beg);
	inp.seekg(0,ios::beg);
	gr=new group[ngr];
	for(i=0;i<ngr;i++)
	{
		ing.getline(bf,100);
		gr[i].tag=bf[0];
		strtok(bf,"  ");
		for(int j=0;j<4;j++)
			gr[i].tm[j].name=strtok(NULL,"  ");
	}
}*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class group 
{
public:
	struct team
	{
	public:
		char *name;
		int score;
		int vins;
		int draw;
		int lose;
		int goal;
		int lgoal;
	};
	team tm[4];
	char tag;
	~group()
	{
		for(int i=0;i<4;i++)
			delete tm[i].name;
	}
	int score(istream& in,char *name)
	{
		char bf[100];
		while(!in.eof())
		{
			in.getline(bf,100);
		}
	}
};
class result
{
	char * name;
	int score;
	int number;
};
int main()
{
	setlocale(LC_ALL,"rus");
	ofstream outt("GroupsOut.txt"),outg("Results.txt");
	ifstream inp("Game.txt"),ing("Groups.txt");
	char * bf;
	bf=new char[100];
	char tag;
	int i=0,k,ngr,count;
	group *gr;
	while(!ing.eof())
	{
		ing.getline(bf,100);
		i++;
	}
	ngr=i;
	i=0;
	while(!inp.eof())
	{
		inp.getline(bf,100);
		i++;
	}
	count=i;
	k=count/ngr;
	inp.clear();
	ing.clear();
	ing.seekg(0,ios::beg);
	inp.seekg(0,ios::beg);
	gr=new group[ngr];
	for(i=0;i<ngr;i++)
	{
		ing.getline(bf,100);
		gr[i].tag=bf[0];
		strtok(bf,"  ");
		for(int j=0;j<4;j++)
			gr[i].tm[j].name=strtok(NULL,"  ");
	}
}