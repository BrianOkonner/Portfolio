// istream peek
#include <iostream>
using namespace std;

int main ()
{
	char c;
	int n;
	char str[256];

	cout << "Enter a number or a word: ";
	c = cin.peek();

	if ( (c >= '0') && (c <= '9') )
	{
		cin >> n;
		cout << "You have entered number " << n << endl;
	}
	else
	{
		cin >> str;
		cout << " You have entered word " << str << endl;
	}
	
	return 1;
}
