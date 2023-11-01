#include <fstream>


struct Student
{
	char  name[15];		// ������� ��������
	int   num;			// ����� ������
	double  grade;		// ������� ���
};
class StudContainer
{
	int size;	  // ����������� �������
	Student* p;	  // ������ ������� � ���������
	int count;	  // ���������� ��������� � ����������
public:
	StudContainer(int& _n);	  // �����������
	StudContainer(const StudContainer& c);  // ����������� �����������
	~StudContainer();		  // ����������
	bool insert(const Student& s);  // ��������� �������� � ���������
	bool del(char* name);	  // ���������� �������� �� ����������
	void sortByName();	  // ���������� ������� �� ������
	Student* findByName(char* name);	// ����� �������� �� �����
	void sortByGroupAndName();	  // ���������� �� �������, ������
	void report(std::ostream& out);	  // ������� ����� � ����
	void print(std::ostream& out);	  // ����������� ������ ���������
	int Wsize();				  // ���������� ������ ����������
	int Wcount();	  // ���������� ���������� ������� � ����������
};

