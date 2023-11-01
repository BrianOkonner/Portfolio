// чтение файла последовательного доступа

#include <stdio.h>

int main()
{
	int code;
	char name[80];
	double salary;
	FILE* in;		// входной поток
	
		// открываем входной поток в текстовом режиме
	if(!(in = fopen("C:\\employee.txt", "r")))
	{
		printf("Open file failed.\n");
		return 0;
	}
		// читаем первую запись
	fscanf(in, "%d%s%lf", &code, name, &salary);
	while (!feof(in))
	{
			// выводим запись на консоль
		printf("code = %d name = %s sal = %f\n", code, name, salary);
			// читаем следующие записи
		fscanf(in, "%d%s%lf", &code, name, &salary);
	}
		// закрываем входной поток
	fclose(in);

	return 1;
}
