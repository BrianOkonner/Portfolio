// чтение файла прямого доступа

#include <stdio.h>

struct emp
{
	int code;
	char name[20];
	double salary;
};

int main()
{
	FILE* in;		// выходной поток
	struct emp s;	// для записей файла
	unsigned i;		// номер записи

		// открываем входной поток в бинарном режиме
	if(!(in = fopen("C:\\employee.bin", "rb")))
	{
		printf("Open file failed.\n");
		return 0;
	}

	printf("Press Ctrl+z to exit.\n");
		// читаем индекс
	printf("Input an index: ");
	scanf("%u", &i);

	while (!feof(stdin))
	{
			// устанавливает указатель на нужную запись
		fseek(in, i*sizeof(struct emp), SEEK_SET);
			// читаем запись из файла
		if(!fread(&s, sizeof(struct emp), 1, in))
		{
			printf("The wrong index.\n");
			continue;
		}
			// выводим запись на консоль
		printf("\tcode = %d name = %s sal = %f\n", 
			s.code, s.name, s.salary);
			// читаем индекс
		printf("Input an index: ");
		scanf("%u", &i);
	}
		// закрываем входной поток
	fclose(in);

	return 1;
}
