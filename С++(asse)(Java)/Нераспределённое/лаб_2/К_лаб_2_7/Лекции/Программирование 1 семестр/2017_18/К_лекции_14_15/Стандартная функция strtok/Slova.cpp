
#include <iostream.h>
#include <stdio.h>
#include <string.h>
//������ ������ �� �����(�������)
void main()
{
//	char  str[ ] = "12 34,ab:cd;56";
	char* str;
	str= new char[20];
	cin>>str;  //����  ������ �� �������
	char *p;
	p = strtok(str, ";,: ");
	while (p)
	{
		cout<<p<<endl;
			/* �������� � ������� �������� ���� */
		p = strtok(NULL, ";,: ");
	}

}
