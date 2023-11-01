// удаление файла

#include <stdio.h>

int main()
{
	if(remove("C:\\employee.bin"))
	{
		printf("There is no such a file.\n");
		return 0;
	}

	printf("The file was deleted.\n");

	return 1;
}
