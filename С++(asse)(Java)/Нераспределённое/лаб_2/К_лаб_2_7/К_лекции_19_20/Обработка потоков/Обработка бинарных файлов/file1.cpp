
 
//������ �������� ��������� �����, ��������� ������� write.

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
	ofstream out;		// �������� �����
	struct emp s;		// ��� ������� �����

	// ��������� �������� ����� � �������� ������
	out.open("demo.bin", ofstream::binary);
	if(!out)
	{
		cerr << "Open file failed." << endl;
		return 1;
	}

	cout << "Input code, name and salary." << endl;
	cout << "Press Ctrl+z to exit." << endl;

	cout << '>';
		// ������ ������ ������ � �������
	cin >> s.code >> s.name >> s.salary;

	while (!cin.eof())
	{
			// ����� ������ � ����
		out.write((const char*)&s, sizeof(struct emp));

		cout << '>';
			// ������ ��������� ������ � �������
		cin >> s.code >> s.name >> s.salary; 
	}
		// ��������� �������� �����
	out.close();

	return 0;
}

