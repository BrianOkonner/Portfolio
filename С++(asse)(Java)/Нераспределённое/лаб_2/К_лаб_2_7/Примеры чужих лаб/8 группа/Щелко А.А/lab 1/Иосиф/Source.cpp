//Щелко Алексей 8 группа
//3.1	Задача Иосифа.Вокруг считающего стоит N человек, из которых выделен первый,
//а  остальные  занумерованы  по  часовой стрелке числами от 2 до N.Считающий,
//начиная с кого - то, ведет счет до M.Человек, на котором остановился счет,
//выходит из круга.Счет продолжается со следующего человека и так до тех пор,
//пока не останется один человек.Определить номер оставшегося человека, 
//если известно M и то, что счет начинался с первого человека.Результат записать в текстовый  файл

//Введите m :
//
//Количество людей:
//5
//Nomer ostavshegosya :
//2

#include <fstream>
#include <iostream>
#include <list>
#include <string.h>


using namespace std;

list <int> S;
int main()
{
	ofstream fout;
	fout.open("Output.txt");
	setlocale(LC_ALL, "rus");
	cout << "Введите m: " << endl;
	int n;
	cin >> n;
	if (n == 0) { cout << "error"; exit(0); }
	cout << "Количество людей:  " << endl;
	int kol;
	cin >> kol;
	for (int i = 1; i <= kol; S.push_back(i), i++);
	while (kol != 1)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j != n)
			{
				int y = S.front();
				S.pop_front();
				S.push_back(y);
			}
			else
			{
				S.pop_front();
			}
		}
		kol--;
	}
	fout << "Номер оставшегося человека:" << endl;
	fout << S.front() << endl;
	system("pause");
	return 0;
}

