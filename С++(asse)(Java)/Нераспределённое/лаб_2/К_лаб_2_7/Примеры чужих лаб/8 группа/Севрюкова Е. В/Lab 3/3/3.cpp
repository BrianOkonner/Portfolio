/*	1 курс
	8 группа
	Севрюкова Елизавета
*/

#include "StudContainer.h"

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream in("Input.txt");
	ofstream Out("output1.txt");
	if (!in.is_open()) {
		cout << "File is not found"; return 0;
	}
	int n;
	in >> n;
	Student st;
    StudContainer StudC(n);
	for (int i = 0; i < n; i++)
	{
		in >> st.name >> st.num >> st.grade;
		StudC.insert(st);
		Out << st.name <<" "<< st.num << " " << st.grade << endl;
	}
	Out.close();

int enter;
do
{
	cout << "\nPlease, choose one of following options\n";
	cout << "1)Sort by names\n";
	cout << "2)Find by name\n";
	cout << "3)Sort by groups and names\n";
	cout << "4)Show report\n";
	cout << "5)Exit\n\n";

	cin >> enter;
	int Name_Len = 100;
	char* name = new char[Name_Len];
	Student* stud;
	switch (enter)
	{
	case 1:
		system("cls");
		StudC.sortByName();
		StudC.print(cout);
		break;
	case 2:
		system("cls");
		cout << "enter, the name of student\n";
		cin >> name;
		stud = StudC.findByName(name);
		if (stud)
			cout << (*stud).name << " " << (*stud).num << " " << (*stud).grade << endl;
		else
			cout << "Can not find this student\n";
		break;
	case 3:
		system("cls");
		StudC.sortByGroupAndName();
		StudC.print(cout);
		break;
	case 4:
		system("cls");
		StudC.report(cout);
		break;
	default:
		system("cls");
		break;
	}
} while (enter != 5);


return 0;
}