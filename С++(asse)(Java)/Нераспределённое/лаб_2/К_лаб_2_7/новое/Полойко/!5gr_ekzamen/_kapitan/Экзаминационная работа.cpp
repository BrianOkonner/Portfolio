//Капитан 5 группа
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int simvol=1,mass[81],i=0,kol[81],n=0,MAX=0,k=0;
	setlocale(LC_ALL,".1251");
	FILE *infile = fopen("c:\\Temp\\Input.txt","r+");
	if (infile == NULL)
	{
	cout << "Ошибка открытия входного файла" << endl;
	return 1;
	}
	else
	{
	cout << "Файл открыт" << endl;
	//Считывание по символьно и занесение в массив
	while (simvol != NULL)
	{
		simvol = getc(infile);
		mass[i] = simvol;
		i = i + 1;
	}
	i = 0;
	//Поиск повторяющихся элементав в массиве с занесениес колса повторов в спомогательный массив
	while(mass[i] != 0)
		{
		if (mass[i] = mass[i+1])
		kol[n]=kol[n] + 1;
		else 
		n = n + 1;
		i = i + 1;
		}
	k = n;
	n = 0;
	MAX=kol[n];
	n = n +1;
			while(n < k)
				{
				if (MAX < kol[n])
				MAX = kol[n];
				else
				n = n + 1;
				}
	cout << "Максимальное кол-во повторений какогото символа равна=" << MAX << endl;
	fclose(infile);
	}
return 0;
}
