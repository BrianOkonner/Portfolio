#include <iostream>
struct  emp
	{
		int  empno;
		char  name[20];
		double  salary;
	};


	void  print(struct emp s)
//Когда структура используется как параметр функции, то она передается в 
//функцию по значению, как и принято в языке программирования Си. Например,
	{
		printf("%d %s %f\n", s.empno, s.name, s.salary);
	};
//Для того чтобы функция могла изменить значения членов структуры, 
//она должна получить указатель на эту структуру.
//Для доступа к членам структуры через указатели используется оператор '->'.
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
// Ошибка, если  s1.name="****";
	 s1.empno=7;
	 s1.salary=4.7;
	 print(s1);
	 init_emp(&s2,77,"!!!!",7.4);
	 print(s2);
}