# include <iostream>
# include <fstream>
using namespace std;
 int main ()
{	setlocale (LC_ALL, ".1251");
	ifstream in;
	in.open ("input.txt");
	char ln[80];
	int low=0,k=0;
	while (in.getline (ln,80))
	low++;
	//cout << low << endl;
	
for (int i=0; i<80; i++)
if (!(ln[i]<'0')||(ln[i] > '9')||(ln[i]==' ')||(ln[i]==':')||(ln[i]==';')||(ln[i]=='-')||(ln[i]=='!')||(ln[i]==',')||(ln[i]=='.'))
{
  cout <<ln[i] <<endl;
}
//cout << k << endl;


return 0;
 }
	
/*char str;
str = new char [80];
int k,n;






for (int i=0; i<80; i++)
cout <<"Номер слова " <<  << "слово " <<  << "Символ "<<  << "Длинна " <<  <<"номер символа" <<  <<endl;


		return 0;


 }
	*/