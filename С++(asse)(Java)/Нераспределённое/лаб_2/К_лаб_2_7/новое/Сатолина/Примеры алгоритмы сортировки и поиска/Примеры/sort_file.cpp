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
	cout << "������� ��� ����� ��� ����������:";
	cin >> ifile;
	// ��������������� ������ ������ ifstream ��� ����� �� �����
	ifstream infile( ifile.c_str() );
	if ( ! infile )
	{
		cerr << "������: �� ���� ������� ������� ����:"
		<< ifile << endl;
		return -1;
	}
	string ofile = ifile + ".txt";
	// ��������������� ������ ������ ofstream ��� ������ � ����
	ofstream outfile( ofile.c_str() );
	if ( ! outfile) 
	{
		cerr << "������: �� ���� ������� �������� ����:"
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
	// ������� ��������������� ��������� ���� � ����
	vector< string >::iterator iter = text.begin();
	cout<<endl;
	for ( cnt = 1; iter != text.end(); ++iter, ++cnt )
	{
		outfile << *iter<<(cnt%8 ? " ": "\n" );
		cout<<*iter<<(cnt%8 ?" ": "\n" );
	}
	return 0;
}