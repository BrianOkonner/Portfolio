// �������� ����� ����������������� �������

#include <stdio.h>

int main()
{
	int code;
	char name[80];
	double salary;
	FILE* out;	// �������� �����

		// ��������� �������� ����� � ��������� ������
	if(!(out = fopen("C:\\employee.txt", "w")))
	{
		printf("Open file failed.\n");
		return 0;
	}

	printf("Input code, name and salary.\n");
	printf("Press Ctrl+z to exit.\n");

	printf(">");
		// ������ ������ ������ � �������
	scanf("%d%s%lf", &code, &name, &salary);

	while (!feof(stdin))
	{
			// ����� ������ � ����
		fprintf(out, "%d %s %f ", code, name, salary);

		printf(">");
			// ������ ��������� ������ � �������
		scanf("%d%s%lf", &code, &name, &salary); 
	}
		// ��������� �������� �����
	fclose(out);

	return 1;
}
