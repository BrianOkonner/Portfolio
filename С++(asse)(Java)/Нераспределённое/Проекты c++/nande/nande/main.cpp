#include "StudContainer.h"
#include "iostream"
#include <conio.h>
#include "iomanip"
using namespace std;
int main()
{
	try
	{
		ifstream in("inputStud.txt");
		Student s;
		int num;
		in>>num;
		StudContainer sc(num);
		while(!in.eof())
		{
			int i=0;
			in>>s.name>>s.num>>s.grade;
			sc.insert(s);
		}
		do
		{
			cout<<"Press:"<<endl;
			cout<<"0 to Exit."<<endl;
			cout<<"1 to Sort by surname and display."<<endl;
			cout<<"2 to Find student and display."<<endl;
			cout<<"3 to Sort by surname and group number and display."<<endl;
			cout<<"4 to Add student."<<endl;
			cout<<"5 to Delete info of student."<<endl;
			switch(_getch()-'0')
			{
				case 0:
				{
					system("cls");
					cout << " " << endl;
					return 0;
				}
				case 1:
				{
					system("cls");
					sc.sortByName();
					sc.print(cout); 
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					system("cls");
					cout<<"Enter surname of student: "<<endl;
					char *name=new char[20];
					cin>>name;
					cout<<"Info:"<<endl;
					s=*(sc.findByName(name));
					cout<<left<<setw(20)<<"Surname"<<setw(7)<<"Group"<<setw(5)<<"Grade"<<endl;
					cout<<left<<setw(20)<<s.name<<setw(7)<<s.num<<setw(5)<<setprecision(5)<<s.grade<<endl;
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					system("cls");
					sc.sortByGroupAndName();
					sc.print(cout); 
					system("pause");
					system("cls");
					break;
				}				
				case 4:
				{
					system("cls");
					cout<<"Enter surname of student: ";
					cin>>s.name;
					cout<<"Enter group of student: ";
					cin>>s.num;
					cout<<"Enter of average grade: ";
					cin>>s.grade;
					sc.insert(s);
					cout<<endl<< "Student added" <<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
				case 5:
				{
					system("cls");
					cout<<"Enter surname of student: "<<endl;
					char *name=new char[20];
					cin>>name;
					sc.del(name);
					cout<<"Info deleted"<<endl;
					system("pause");
					system("cls");
					break;
				}
				default:
				{
					system("cls");
					cout<<"invalid number of operation"<<endl;
					system("pause");
					system("cls");
					break;
				}
			}
		}
		while(true);
	}
	catch(int y)
	{
		cout<<"Exception"<<endl<<"code :"<<y;
	}
	return 0;
}