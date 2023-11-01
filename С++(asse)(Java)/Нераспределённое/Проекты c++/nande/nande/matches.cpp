#include <list>
struct team
{
	char name[30];
	int vict;
	int prop;
	int zab;
};
class teams
{
	list <team> tm;
public:
	teams(){}
};
#include <fstream>
#include <iostream>
int main()
{
	teams tm;
	ifstream in("inputt.txt");
	ofstream out("outputt.txt");
	char[
