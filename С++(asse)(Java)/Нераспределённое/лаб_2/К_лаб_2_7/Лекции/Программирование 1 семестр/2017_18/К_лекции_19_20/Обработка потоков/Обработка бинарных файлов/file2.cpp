
 
//������ ������ ��������� ����� �� �������.

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
	ifstream in;		// �������� �����
	struct emp s;		// ��� ������� �����

	// ��������� �������� ����� � �������� ������
	in.open("demo.bin", ifstream::binary);
	if(!in)
	{
		cerr << "Open file failed." << endl;
		return 1;
	}



//	while (!in.eof())
	while (in.read((char*)&s, sizeof(struct emp)))
	{
			// ������ ������ �� �����
	
		in.read((char*)&s, sizeof(struct emp));
	
		
		// ������� ������ �� �������
		cout << "\tcode = " << s.code 
			<< " \tname = " << s.name 
			<< " \tsal = " << s.salary << endl;

	
	}
		// ��������� �������� �����
	in.close();

	return 0;
}

