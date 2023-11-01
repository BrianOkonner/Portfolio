#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class group 
{
public:
	struct team
	{
		char *name;
		int score;
		int vins;
		int draw;
		int lose;
		int goal;
		int lgoal;
	};
	team tm[4];
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
	bf=new char[25];
	char tag;
	int i=0,k,ngr,count;
	group gr;
	while(!ing.eof())
	{
		ing.getline(bf,100);
		i++;
	}
	ngr=i;
	i=0;
	while(!inp.eof())
	{
		ing.getline(bf,100);
		i++;
	}
	count=i;
	k=count/ngr;
	inp.clear();
	ing.clear();
	for(i=0;i<ngr;i++)
	{
		ing.getline(bf,100);
		tag=bf[0];
		strtok(bf," ");
		for(int j=0;j<4;j++)
			gr.tm[i].name=strtok(bf," ");
	}
}
