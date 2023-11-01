// использование временного файла

#include <stdio.h>

int main()
{
	int code;
	char name[80];
	double salary;
	FILE* temp;		// временный файл

		// открываем временный файл
	if(!(temp = tmpfile()))
	{
		printf("Create temp file failed.\n");
		return 0;
	}

	printf("Input code, name and salary.\n");
	printf("Press Ctrl+z to exit.\n");

	printf(">");
		// вводим первую запись с консоли
	scanf("%d%s%lf", &code, &name, &salary);

	while (!feof(stdin))
	{
			// пишем запись в файл во временный файл
		fprintf(temp, "%d %s %f ", code, name, salary);

		printf(">");
			// вводим следующие записи с консоли
		scanf("%d%s%lf", &code, &name, &salary);
	}
	
		// устанавливаем индикатор позиции на начало файла
	rewind(temp);

	printf("\nRead records from the temporary file.\n");
		// читаем первую запись из временного файла
	fscanf(temp, "%d%s%lf", &code, name, &salary);
	while (!feof(temp))
	{
			// выводим запись на консоль
		printf("code = %d name = %s sal = %f\n", code, name, salary);
			// читаем следующие записи из временного файла
		fscanf(temp, "%d%s%lf", &code, name, &salary);
	}

		// закрываем временный файл
	fclose(temp);

	return 1;
}
