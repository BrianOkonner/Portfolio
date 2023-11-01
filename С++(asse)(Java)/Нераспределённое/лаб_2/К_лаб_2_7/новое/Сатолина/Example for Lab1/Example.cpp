#include "header.h"

void main()
{
	Vector v1(5);  // ��������� ����������� � ����������
	Vector v2;	   // ��������� ���������� �� ���������
	Vector v3(v2); // ��������� ����������� �����������
	Vector v4(5);

	v1.input();
	cout << "Vector1" << endl;
	v1.output();
	v4.input();
	cout << "Vector2" << endl;
	v4.output();

	Vector result(5);
	try{
		result.add(v1,v4);
		cout << "VectorResult" << endl;
		result.output();
	}
	catch(char* str){
		cout << str << endl;
	}


}// ��������� ���������� 