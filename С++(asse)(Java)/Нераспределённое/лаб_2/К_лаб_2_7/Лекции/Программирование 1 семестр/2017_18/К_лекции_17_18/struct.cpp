#include <iostream>
struct  emp
	{
		int  empno;
		char  name[20];
		double  salary;
	};


	void  print(struct emp s)
//����� ��������� ������������ ��� �������� �������, �� ��� ���������� � 
//������� �� ��������, ��� � ������� � ����� ���������������� ��. ��������,
	{
		printf("%d %s %f\n", s.empno, s.name, s.salary);
	};
//��� ���� ����� ������� ����� �������� �������� ������ ���������, 
//��� ������ �������� ��������� �� ��� ���������.
//��� ������� � ������ ��������� ����� ��������� ������������ �������� '->'.
	void  init_emp(emp  *ps, int  en, char  *nm, double  sal)
	{
		ps->empno = en;
		strcpy(ps->name, nm);
		ps->salary = sal;
	};
main()
{
     emp s1,s2;
	 strcpy(s1.name,"****");
// ������, ����  s1.name="****";
	 s1.empno=7;
	 s1.salary=4.7;
	 print(s1);
	 init_emp(&s2,77,"!!!!",7.4);
	 print(s2);
}