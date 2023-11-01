
//#include "Header.h"
#include "StudContainer.h"

int main()
{
	
		ifstream in("input.txt");
		ofstream out("output1.txt");
		int n;
		in >> n;
		int enter;
		StudContainer StudC(n);
		Student temp;
		while (!in.eof())
		{
			temp = Read_Write_file(in, out);
			StudC.insert(temp);
		}

		do
		{
			cout << "\nPlease, choose one of following options\n";
			cout << "1)Sort by names\n";
			cout << "2)Find by name\n";
			cout << "3)Sort by groups and names\n";
			cout << "4)Show report\n";
			cout << "5)Exit\n";

			cin >> enter;
			char* name = new char[80];
			Student* stud;

			switch (enter)
			{
			case 1:
				StudC.sortByName();
				StudC.print(cout);
				break;
			case 2:
				cout << "enter, the name of student\n";
				cin >> name;
				stud = StudC.findByName(name);
				if (stud)
					cout << (*stud).name << " " << (*stud).num << " " << (*stud).grade << endl;
				else
					cout << "Can not find this student\n";
				break;
			case 3:
				StudC.sortByGroupAndName();
				StudC.print(cout);
				break;
			case 4:
				StudC.report(cout);
				break;
			default:
				break;
			}
		} while (enter != 5);
		
	system("pause");
	return 0;
}