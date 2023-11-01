#include"Header.h"
void F1(StudContainer stud);
void F2();
int main()
{
	try
	{
		setlocale(0, "rus");
		ifstream fin;
		fin.open("Input.txt");
		int n;
		char str[81]; str[0] = '\0';
		fin >> n;
		StudContainer S(n);
		fin.getline(str, 81);
		while (!fin.eof())
		{
			Student stud;
			fin.getline(str, 81);
			char *tmp = strtok(str, " ");
			strcpy(stud.name, tmp);
			tmp = strtok(NULL, " ");
			stud.num = atoi(tmp);
			tmp = strtok(NULL, " ");
			stud.grade = atof(tmp);
			S.insert(stud);
		}
		ofstream of("Output.txt");
		int w;
		for (;; )
		{
			system("cls");
			F2();
			cin >> w;
			system("cls");
			switch (w)
			{
			case 1: S.sortByName(); S.print(cout); system("pause"); break;
			case 2:  F1(S);  system("pause"); break;
			case 3: S.sortByGroupAndName(); S.print(cout); system("pause"); break;
			case 4: S.print(cout); system("pause"); break;
			case 5: exit(0);
				default: break;
			}
		}
	}
	
	catch (int a)
	{
		cout << "oshibka" <<"  "<<a<<endl;
	}
	system("pause");
}
void F1(StudContainer stud) 
{
	char N[81]; N[0] = '\0';
	cout << "найти студента по имени" << endl;
	cout << "введите имя:";
	cin >> N;
	Student S = *stud.findByName(N);
	if (S.num == 0)
	{
		cout << "такой студент не существует" << endl << endl;; return;
	}
	cout << "имя " << setw(22) << S.name << endl << "номер группы " << setw(11) << S.num << endl <<  "средний балл "<<setw(11)  << S.grade << endl;;
	cout << endl;
}
void F2()
{
	cout << "1- Отсортировать студентов по именам" << endl;
	cout << "2- найти студента по имени" << endl;
	cout << "3- Отсортировать студентов по группам, а внутри одной группы по именам" << endl;
	cout << "4- Вывести отчет о среднем бале студентов в каждой группе" << endl;
	cout << "5- выход" << endl;
}
