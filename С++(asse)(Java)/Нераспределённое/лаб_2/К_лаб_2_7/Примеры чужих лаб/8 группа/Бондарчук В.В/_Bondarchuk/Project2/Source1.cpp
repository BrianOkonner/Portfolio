//Бондарчук
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
struct prizes
{
	char name[81];
	int numL;
};
struct item
{
	char name[81];
	int numD;
	int numL;
	int price;
	char firmNames[3];
};
struct firms
{
	char firmName[81];
	char firmName1[81];
	item info[100];
	int numL;
	int amount;
};



void bubbleSort(item* a, int n)
{
	item temp;
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (int i = 0; i< n - 1; i++)
			if (a[i].numD > a[i + 1].numD)
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				exit = false;
			}
	}
}
bool numb(char *str)
{
	int i;
	int f = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			f++;
		}
		else return false;
	}
	if (i == f) return true;
}
void sortfio(firms *p, int a) //сортировка по фамилии
{

	for (int l = 0; l<a; l++)
	{
		int n = p[l].amount;
		for (int i = 0; i < n; i++)
			for (int k = n - 1; k > i; --k)
			{
				if (p[l].info[k - 1].name[0] > p[l].info[k].name[0])
				{
					swap(p[l].info[k - 1], p[l].info[k]);
				}
				if (p[l].info[k - 1].name[0] == p[l].info[k].name[0])
				{
					if (p[l].info[k - 1].name[1] > p[l].info[k].name[1])
					{
						swap(p[l].info[k - 1], p[l].info[k]);
					}
				}
			}
	}
}
int recSum(firms a, int amount)
{
	int s = 0;
	for (int i = 0; i < amount; i++)
	{
		s = s + a.info[i].price;
	}
	return s;
}
firms maxP(firms *mas2, int n)
{
	firms temp = mas2[0];
	int max = recSum(mas2[0], mas2[0].amount);
	for (int i = 0; i < n; i++)
	{
		if ((recSum(mas2[i], mas2[i].amount))>max)
		{
			max = recSum(mas2[i], mas2[i].amount);
			temp = mas2[i];
		}

	}

	return temp;
}
int main()
{

	ifstream fin1("Pricelist.txt");
	ifstream fin2("NameFirm.txt");
	ifstream fin3("NamePrizes.txt");
	ofstream out1("SortPrizes.txt");
	ofstream out2("Sortlist.txt");
	fin3 >> S1 >> S2 >> S3 >> N1 >> N2 >> N3;
	char str[81];
	str[0] = '\0';
	int typePrizes = N1 + N2 + N3;
	item mas1[20];
	firms mas2[100];

	for (int j = 0; j<20; j++)
	{
		mas1[j].name[0] = '\0';

	}
	for (int j = 0; j<100; j++)
	{
		mas2[j].firmName[0] = '\0';
	}
	for (int j = 0; j<100; j++)
	{
		mas2[j].firmName1[0] = '\0';
	}
	for (int j = 0; j<100; j++)
	{
		for (int p = 0; p<100; p++)
		{
			mas2[j].info[p].name[0] = '\0';
			/*mas2[j].info[p].firmNames[0] = '\0';*/
		}
	}
	
	

	for (int i = 0; i<typePrizes; i++)
	{
		cout << setw(40) << mas1[i].name << setw(10) << mas1[i].numD << setw(10) << mas1[i].numL << endl;
		out1 << setw(40) << mas1[i].name << setw(10) << mas1[i].numD << setw(10) << mas1[i].numL << endl;
	}







	prizes mas3[5];

	for (int p = 0; p<100; p++)
	{
		mas3[p].name[0] = '\0';
	}

	int colvofirm;
	fin2 >> colvofirm;
	i = 0;
	fin2.getline(str, 81);
	while (!fin2.eof())
	{
		fin2.getline(str, 81);
		int c = colvoslov(str);
		char *word = strtok(str, " ");
		while (c - 1)
		{
			strcat(mas3[i].name, word);
			strcat(mas3[i].name, " ");
			word = strtok(NULL, " ");
			c--;
		}

		mas3[i].numL = atoi(word);
		i++;
	}
	//for (int j = 0; j<colvofirm; j++)
	//{
	//		for (int p = 0; p<colvofirm; p++)
	//		{
	//			for (int l = 0; l < mas2[p].amount; l++)
	//			{
	//				if (mas2[p].info[l].numL == mas3[j].numL)
	//				{
	//					strcpy(mas2[p].info[l].firmNames, mas3[j].name);
	//				}
	//			}
	//		}
	//}




	/*sortfio(  mas2, countFirms);
	*/
	cout << endl;




	for (int i = 0; i<countFirms; i++)
		for (int j = 0; j< mas2[i].amount; j++)
		{
			/*cout << setw(40) << mas2[i].tovar[j].name << setw(10) << mas2[i].tovar[j].price <<setw(10)<< mas2[i].firmName<<setw(10)<< mas2[i].firmName1<<setw(10) << endl;*/
			cout << setw(40) << mas2[i].tovar[j].name << setw(10) << mas2[i].tovar[j].price << setw(30) << mas2[i].fname << setw(10) << endl;
		}


	system("pause");

}