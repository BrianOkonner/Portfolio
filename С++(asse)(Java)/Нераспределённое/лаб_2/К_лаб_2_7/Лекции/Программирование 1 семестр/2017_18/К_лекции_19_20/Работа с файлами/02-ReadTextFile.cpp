// ������ ����� ����������������� �������

#include <stdio.h>

int main()
{
	int code;
	char name[80];
	double salary;
	FILE* in;		// ������� �����
	
		// ��������� ������� ����� � ��������� ������
	if(!(in = fopen("C:\\employee.txt", "r")))
	{
		printf("Open file failed.\n");
		return 0;
	}
		// ������ ������ ������
	fscanf(in, "%d%s%lf", &code, name, &salary);
	while (!feof(in))
	{
			// ������� ������ �� �������
		printf("code = %d name = %s sal = %f\n", code, name, salary);
			// ������ ��������� ������
		fscanf(in, "%d%s%lf", &code, name, &salary);
	}
		// ��������� ������� �����
	fclose(in);

	return 1;
}
