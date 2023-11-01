// ������ ����� ������� �������

#include <stdio.h>

struct emp
{
	int code;
	char name[20];
	double salary;
};

int main()
{
	FILE* in;		// �������� �����
	struct emp s;	// ��� ������� �����
	unsigned i;		// ����� ������

		// ��������� ������� ����� � �������� ������
	if(!(in = fopen("C:\\employee.bin", "rb")))
	{
		printf("Open file failed.\n");
		return 0;
	}

	printf("Press Ctrl+z to exit.\n");
		// ������ ������
	printf("Input an index: ");
	scanf("%u", &i);

	while (!feof(stdin))
	{
			// ������������� ��������� �� ������ ������
		fseek(in, i*sizeof(struct emp), SEEK_SET);
			// ������ ������ �� �����
		if(!fread(&s, sizeof(struct emp), 1, in))
		{
			printf("The wrong index.\n");
			continue;
		}
			// ������� ������ �� �������
		printf("\tcode = %d name = %s sal = %f\n", 
			s.code, s.name, s.salary);
			// ������ ������
		printf("Input an index: ");
		scanf("%u", &i);
	}
		// ��������� ������� �����
	fclose(in);

	return 1;
}
