// ������������� ���������� �����

#include <stdio.h>

int main()
{
	int code;
	char name[80];
	double salary;
	FILE* temp;		// ��������� ����

		// ��������� ��������� ����
	if(!(temp = tmpfile()))
	{
		printf("Create temp file failed.\n");
		return 0;
	}

	printf("Input code, name and salary.\n");
	printf("Press Ctrl+z to exit.\n");

	printf(">");
		// ������ ������ ������ � �������
	scanf("%d%s%lf", &code, &name, &salary);

	while (!feof(stdin))
	{
			// ����� ������ � ���� �� ��������� ����
		fprintf(temp, "%d %s %f ", code, name, salary);

		printf(">");
			// ������ ��������� ������ � �������
		scanf("%d%s%lf", &code, &name, &salary);
	}
	
		// ������������� ��������� ������� �� ������ �����
	rewind(temp);

	printf("\nRead records from the temporary file.\n");
		// ������ ������ ������ �� ���������� �����
	fscanf(temp, "%d%s%lf", &code, name, &salary);
	while (!feof(temp))
	{
			// ������� ������ �� �������
		printf("code = %d name = %s sal = %f\n", code, name, salary);
			// ������ ��������� ������ �� ���������� �����
		fscanf(temp, "%d%s%lf", &code, name, &salary);
	}

		// ��������� ��������� ����
	fclose(temp);

	return 1;
}
