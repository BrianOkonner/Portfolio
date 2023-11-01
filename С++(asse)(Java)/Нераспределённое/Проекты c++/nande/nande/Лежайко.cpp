#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>


using namespace std;

struct Product
{
	char *name;//={"\0"} ;
	int cost;
};

struct Company
{
	int sale;
	char name[20];// = { '\0' };
	Product assortment[100];
};

struct Presents
{
	int budget;
	int totalSize;
	char name[20];// = { '\0' };
};

void opening(ifstream &fin1, ifstream &fin2)
{
	if (!fin1.is_open() || !fin2.is_open())
	{
		cout << "Files didn't opening\n";
		exit(1);
	}
}

void closing(ifstream &fin1, ifstream &fin2)
{
	fin1.close();
	fin2.close();
}

int wordToNumber(char* word)
{
	int a = 0;
	for (int i = 0; i < strlen(word); ++i)
	{
		a *= 10;
		a += word[i] - '0';
	}
	return a;
}

int compare(const void *a, const void *b)
{
	return strcmp(*(char**)a, *(char**)b);
}

void presentsListFilling(Presents* presentsList, ifstream &fin)
{
	char* string = new char[100];
	string[0] = '\0';
	fin.getline(string, 100);
	presentsList->budget = wordToNumber(string);
	fin.getline(string, 100);
	int numberOfPresents = wordToNumber(string);
	presentsList->totalSize = numberOfPresents;
	char** presents = new char*[numberOfPresents];
	for (int i = 0; i < numberOfPresents; ++i)
	{
		presents[i] = new char[30];
		fin.getline(presents[i], 30);
	}
	qsort(presents, numberOfPresents, sizeof(presents), compare);
	for (int i = 0; i < numberOfPresents; ++i)
	{
		strcpy(presentsList[i].name, presents[i]);
	}
	delete[] string;
	for (int i = 0; i < numberOfPresents; ++i)
	{
		delete[] presents[i];
	}
	delete[] presents;
}

void sortPresentsFillig(Presents* presentsList)
{
	ofstream fout("SortPresents.txt");
	for (int i = 0; i < presentsList->totalSize; ++i)
	{
		fout << presentsList[i].name << endl;
	}
	fout.close();
}

int wordIsNumber(char* word)
{
	for (int i = 0; i < strlen(word); ++i)
	{
		if (word[i] < '0' || word[i] > '9')
		{
			return 0;
		}
	}
	return 1;
}

void candidatesListFilling(ifstream &fin, Company* candidates)
{
	char* string = new char[40];
	int companyCounter = -1;
	int assCounter;
	char* word;
	while (!fin.eof())
	{
		fin.getline(string, 40);
		if (!strlen(string))
		{
			fin.getline(string, 40);
		}
		if (wordIsNumber(string))
		{
			++companyCounter;
			candidates[companyCounter].sale = wordToNumber(string);
			fin.getline(string, 40);
			string[0] = ' ';
			strcpy(candidates[companyCounter].name, string);
			fin.getline(string, 40);
			assCounter = 0;
		}
		word = strtok(string, " ");
		strcpy(candidates[companyCounter].assortment[assCounter].name, word);
		word = strtok(NULL, " ");
		candidates[companyCounter].assortment[assCounter].cost = wordToNumber(word);
		++assCounter;
	}
	delete[] string;
}

int necessaryItem(Presents* presentsList, char* item)
{
	int i = 0;
	while (strlen(presentsList[i].name))
	{
		if (!strcmp(presentsList[i].name, item))
		{
			return 1;
		}
		++i;
	}
	return 0;
}

int FSum(Company candidate, Presents* presentsList, int sum, int counter)
{
	while(strlen(candidate.assortment[counter].name))
	{
		if (necessaryItem(presentsList, candidate.assortment[counter].name))
		{
			sum = FSum(candidate, presentsList, sum + candidate.assortment[counter].cost, counter + 1);
			break;
		}
		++counter;
	}
	return sum;
}

char* FMin(Company* candidates, Presents* presentsList)
{
	int i = 1;
	int minCost = 0;
	while (strlen(candidates[i].name))
	{
		if (FSum(candidates[minCost], presentsList, 0, 0) > FSum(candidates[i], presentsList, 0, 0))
		{
			minCost = i;
		}
		++i;
	}
	return candidates[minCost].name;
}

void sumCountFilling(Company* candidates, Presents* presentsList)
{
	int i = 0;
	int minCost;
	ofstream fout("SumCount.txt");
	while (strlen(candidates[i].name))
	{
		fout << candidates[i].name << " " << FSum(candidates[i], presentsList, 0, 0) << endl;
		if (!strcmp(candidates[i].name, FMin(candidates, presentsList)))
		{
			minCost = FSum(candidates[i], presentsList, 0, 0);
		}
		++i;
	}
	fout << FMin(candidates, presentsList) << " " << minCost << endl;
}

void swapItems(Company &candidates, int firstPosition, int secondPosition)
{
	char string[20];
	strcpy(string, candidates.assortment[firstPosition].name);
	strcpy(candidates.assortment[firstPosition].name, candidates.assortment[secondPosition].name);
	strcpy(candidates.assortment[secondPosition].name, string);
	swap(candidates.assortment[firstPosition].cost, candidates.assortment[secondPosition].cost);
}

void costSort(Company &candidates)
{
	int i = 0;
	int j = 0;
	int maxCostPos;
	while (strlen(candidates.assortment[i].name))
	{
		maxCostPos = i;
		while (strlen(candidates.assortment[j].name))
		{
			if (candidates.assortment[j].cost >= candidates.assortment[maxCostPos].cost)
			{
				maxCostPos = j;
			}
			++j;
		}
		swapItems(candidates, i, maxCostPos);
		++i;
		j = i;
	}
}

void resultFilling(Company* candidates, Presents* presentsList, ofstream &fout)
{
	int i = 0;
	int j = 0;
	fout << FMin(candidates, presentsList) << endl;
	while (strlen(candidates[i].name))
	{
		if (!strcmp(FMin(candidates, presentsList), candidates[i].name))
		{
			costSort(candidates[i]);
			while (strlen(candidates[i].assortment[j].name))
			{
				fout << candidates[i].assortment[j].name << " " << candidates[i].assortment[j].cost << " " << (int)(candidates[i].assortment[j].cost * (1 - 1.0 * candidates[i].sale / 100)) << endl;
				++j;
			}
			fout << "Sum without sale " << FSum(candidates[i], presentsList, 0, 0) << endl;
			fout << "Sum with sale " << (int) (FSum(candidates[i], presentsList, 0, 0) * (1 - 1.0 * candidates[i].sale / 100)) << endl;
			break;
		}
	}
}

void shift(Presents* presentsList, int position)
{
	int i = position + 1;
	while (strlen(presentsList[i].name))
	{
		strcpy(presentsList[i - 1].name, presentsList[i].name);
		++i;
	}
	strcpy(presentsList[i - 1].name, "\0");
}

int presentsCorrection(Presents* presentsList)
{
	int numberOfMissingItems;
	int j;
	cout << "Input number of missing items\n";
	cin >> numberOfMissingItems;
	if (!numberOfMissingItems)
	{
		return 0;
	}
	cout << "Input missing item's\n";
	Presents* missingItems = new Presents[numberOfMissingItems];
	for (int i = 0; i < numberOfMissingItems; ++i)
	{
		cin >> missingItems[i].name;
	}
	for (int i = 0; i < numberOfMissingItems; ++i)
	{
		j = 0;
		while (strcmp(missingItems[i].name, presentsList[j].name))
		{
			++j;
		}
		shift(presentsList, j);
	}
	delete[] missingItems;
	return 1;
}

void resultCorrection(Company* candidates, Presents* presentsList, ofstream &fout)
{
	fout << "\nAdjusted list\n";
	int i = 0;
	int j = 0;
	while (strlen(candidates[i].name))
	{
		if (!strcmp(FMin(candidates, presentsList), candidates[i].name))
		{
			fout << "Total sum " << (int)(FSum(candidates[i], presentsList, 0, 0) * (1 - 1.0 * candidates[i].sale / 100)) << endl;
			fout << "Remainder " << presentsList->budget - (int)(FSum(candidates[i], presentsList, 0, 0) * (1 - 1.0 * candidates[i].sale / 100)) << endl;
			costSort(candidates[i]);
			while (strlen(candidates[i].assortment[j].name))
			{
				fout << candidates[i].assortment[j].name << " " << candidates[i].assortment[j].cost << " " << (int)(candidates[i].assortment[j].cost * (1 - 1.0 * candidates[i].sale / 100)) << endl;
				++j;
			}
			break;
		}
	}

}

void correction(Company* candidates, Presents* presentsList, ifstream &fin, ofstream &fout)
{
	if (presentsCorrection(presentsList))
	{
		sortPresentsFillig(presentsList);
		resultCorrection(candidates, presentsList, fout);
	}
}

void run()
{
	Company candidates[5];
	Presents presentsList[15];
	ifstream finPresents("NamePresents.txt");
	ifstream finPrices("PriceList.txt");
	ofstream foutResult("Result.txt");
	opening(finPresents, finPrices);
	presentsListFilling(presentsList, finPresents);
	sortPresentsFillig(presentsList);
	candidatesListFilling(finPrices, candidates);
	sumCountFilling(candidates, presentsList);
	resultFilling(candidates, presentsList, foutResult);
	correction(candidates, presentsList, finPresents, foutResult);
	closing(finPresents, finPrices);
}

int main()
{
	run();
	system("pause");
	return 0;
}