//: C06:Stack4Test.cpp
//{L} Stack4
//{T} Stack4Test.cpp
// Конструкторы и деструкторы
#include "Stack4.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  requireArgs(argc, 1); // Аргумент - имя файла
  ifstream in(argv[1]);
  assure(in, argv[1]);
  Stack IntStack;
  // Чтение файла и сохранение строк в стеке:
    in>>IntStack;
	cout<<IntStack;

	Stack IntStack2(IntStack);
	cout<<IntStack;
	cout<<IntStack2;
	IntStack2.push(100);
	cout<<IntStack2;
	cout<<endl;
	IntStack=IntStack2;
	cout<<IntStack;
	cout<<IntStack2;

	ofstream res("out.txt");
	res<<IntStack;

	istringstream ist("5 5 4 3 2 1");
	ist>>IntStack;
	ostringstream st;
	st<<IntStack;
	string s;
	s=st.str();
	cout<<s<<endl;


} ///:~