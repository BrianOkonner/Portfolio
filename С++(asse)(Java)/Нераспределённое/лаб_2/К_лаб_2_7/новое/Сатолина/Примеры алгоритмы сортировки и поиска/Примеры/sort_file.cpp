#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <locale>
using namespace std;
int main()
{
	setlocale(LC_ALL,".1251");
	string ifile;
	cout << "Введите имя файла для сортировки:";
	cin >> ifile;
	// сконструировать объект класса ifstream для ввода из файла
	ifstream infile( ifile.c_str() );
	if ( ! infile )
	{
		cerr << "ошибка: не могу открыть входной файл:"
		<< ifile << endl;
		return -1;
	}
	string ofile = ifile + ".txt";
	// сконструировать объект класса ofstream для вывода в файл
	ofstream outfile( ofile.c_str() );
	if ( ! outfile) 
	{
		cerr << "ошибка: не могу открыть выходной файл:"
		<< ofile << endl;
		return -2;
	}
	string buffer;
	vector< string> text;
	int cnt = 1;
	while ( infile >> buffer ) 
	{
		text.push_back( buffer );
		cout << buffer << (cnt %8 ? " " : "\n");
	}
	sort( text.begin(), text.end() );
	// выводим отсортированное множество слов в файл
	vector< string >::iterator iter = text.begin();
	cout<<endl;
	for ( cnt = 1; iter != text.end(); ++iter, ++cnt )
	{
		outfile << *iter<<(cnt%8 ? " ": "\n" );
		cout<<*iter<<(cnt%8 ?" ": "\n" );
	}
	return 0;
}