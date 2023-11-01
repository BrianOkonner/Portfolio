// создание файла последовательного доступа

#include <stdio.h>

int main()
{
	int code;
	char name[80];
	double salary;
	FILE* out;	// выходной поток

		// открываем выходной поток в текстовом режиме
	if(!(out = fopen("C:\\employee.txt", "w")))
	{
		printf("Open file failed.\n");
		return 0;
	}

	printf("Input code, name and salary.\n");
	printf("Press Ctrl+z to exit.\n");

	printf(">");
		// вводим первую запись с консоли
	scanf("%d%s%lf", &code, &name, &salary);

	while (!feof(stdin))
	{
			// пишем запись в файл
		fprintf(out, "%d %s %f ", code, name, salary);

		printf(">");
			// вводим следующие записи с консоли
		scanf("%d%s%lf", &code, &name, &salary); 
	}
		// закрываем выходной поток
	fclose(out);

	return 1;
}
