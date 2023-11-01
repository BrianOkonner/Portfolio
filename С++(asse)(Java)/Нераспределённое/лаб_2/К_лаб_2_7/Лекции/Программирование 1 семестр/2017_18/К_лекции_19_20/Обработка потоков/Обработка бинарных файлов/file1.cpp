
 
//пример создани€ бинарного файла, использу€ функцию write.

#include <iostream.h>
#include <fstream.h>

struct emp
{
	int code;
	char name[20];
	double salary;
};

int main()
{
	ofstream out;		// выходной поток
	struct emp s;		// дл€ записей файла

	// открываем выходной поток в бинарном режиме
	out.open("demo.bin", ofstream::binary);
	if(!out)
	{
		cerr << "Open file failed." << endl;
		return 1;
	}

	cout << "Input code, name and salary." << endl;
	cout << "Press Ctrl+z to exit." << endl;

	cout << '>';
		// вводим первую запись с консоли
	cin >> s.code >> s.name >> s.salary;

	while (!cin.eof())
	{
			// пишем запись в файл
		out.write((const char*)&s, sizeof(struct emp));

		cout << '>';
			// вводим следующие записи с консоли
		cin >> s.code >> s.name >> s.salary; 
	}
		// закрываем выходной поток
	out.close();

	return 0;
}

