// �������� ����� ������� �������

#include <stdio.h>

struct emp
{
	int code;
	char name[20];
	double salary;
};

int main()
{
	FILE* out;		// �������� �����
	struct emp s;	// ��� ������� �����

		// ��������� �������� ����� � �������� ������
	if(!(out = fopen("C:\\employee.bin", "wb")))
	{
		printf("Open file failed.\n");
		return 0;
	}

	printf("Input code, name and salary.\n");
	printf("Press Ctrl+z to exit.\n");

	printf(">");
		// ������ ������ ������ � �������
	scanf("%d%s%lf", &s.code, &s.name, &s.salary);

	while (!feof(stdin))
	{
			// ����� ������ � ����
		fwrite(&s, sizeof(struct emp), 1, out);

		printf(">");
			// ������ ��������� ������ � �������
		scanf("%d%s%lf", &s.code, &s.name, &s.salary); 
	}
		// ��������� �������� �����
	fclose(out);

	return 1;
}
