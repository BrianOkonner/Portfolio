#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <fstream>

using namespace std;

int WINAPI WinMain (HINSTANCE hInst, HINSTANCE qwe, LPSTR qwer, int ss)
	{
		ifstream in;
		in.open("TextFile1.txt");
		int a, b;
		in >> a >> b;
		int sum = a + b;
		wchar_t str[100];
		swprintf(str, L"%d", sum);
		MessageBox (NULL, (LPCTSTR)str, _T("The sum"), MB_OK);
	}