
 
//пример вывода бинарного файла на консоль.

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
	ifstream in;		// выходной поток
	struct emp s;		// для записей файла

	// открываем выходной поток в бинарном режиме
	in.open("demo.bin", ifstream::binary);
	if(!in)
	{
		cerr << "Open file failed." << endl;
		return 1;
	}



//	while (!in.eof())
	while (in.read((char*)&s, sizeof(struct emp)))
	{
			// читаем запись из файла
	
		in.read((char*)&s, sizeof(struct emp));
	
		
		// выводим запись на консоль
		cout << "\tcode = " << s.code 
			<< " \tname = " << s.name 
			<< " \tsal = " << s.salary << endl;

	
	}
		// закрываем выходной поток
	in.close();

	return 0;
}

