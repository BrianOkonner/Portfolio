// создание файла прямого доступа

#include <stdio.h>

struct emp
{
	int code;
	char name[20];
	double salary;
};

int main()
{
	FILE* out;		// выходной поток
	struct emp s;	// для записей файла

		// открываем выходной поток в бинарном режиме
	if(!(out = fopen("C:\\employee.bin", "wb")))
	{
		printf("Open file failed.\n");
		return 0;
	}

	printf("Input code, name and salary.\n");
	printf("Press Ctrl+z to exit.\n");

	printf(">");
		// вводим первую запись с консоли
	scanf("%d%s%lf", &s.code, &s.name, &s.salary);

	while (!feof(stdin))
	{
			// пишем запись в файл
		fwrite(&s, sizeof(struct emp), 1, out);

		printf(">");
			// вводим следующие записи с консоли
		scanf("%d%s%lf", &s.code, &s.name, &s.salary); 
	}
		// закрываем выходной поток
	fclose(out);

	return 1;
}
