#include <fstream>
#include <cstring>
#include "List.h"

using namespace std;

list_item* get_input()
{
	char delimiters[] = " -,.;:!\n";
	ifstream f("Input.txt");
	list_item* pHead = 0;
	char* t = new char[128];
	char* tmp;
	while (f.getline(t, 128))
	{
		tmp = strtok(t, delimiters);
		while (tmp)
		{
			add(pHead, tmp);
			tmp = strtok(0, delimiters);
		}
	}
	f.close();
	return pHead;
}
