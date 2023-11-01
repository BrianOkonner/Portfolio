#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Windows.h"
#include <stdio.h>
#include <time.h> 
#include <string>
#include <conio.h>
#include <vector>
class olimp
{
	public:
	string Fio;
	string Name;
	int ball;
	int Diplom;
};
using namespace std;
int main()
{
	vector<int> ik;
	olimp *ol;
	int i=0;
	ifstream in("Olimp.txt");
	ofstream out("Medial.txt");
	while(!in.eof())
		i++;
	in.seekg(ios::beg);
	in.clear();
	ol=new olimp[i];
	i=0;
	while(!in.eof())
	{
		in>>ol[i].Fio>>ol[i].Name>>ol[i].ball>>ol[i].Diplom;
		i++;
	}
	ik.
}