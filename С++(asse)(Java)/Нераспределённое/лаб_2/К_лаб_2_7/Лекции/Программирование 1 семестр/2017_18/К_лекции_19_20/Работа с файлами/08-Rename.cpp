// переименование файла

#include <stdio.h>

int main()
{
	if(rename("C:\\employee.txt", "C:\\emp.txt"))
	{
		printf("There is no such a file.\n");
		return 0;
	}

	printf("The file was renamed.\n");

	return 1;
}
