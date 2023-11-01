//Cортировкa массива строк. 
//—троки ввод€тс€ с консоли.

int main()
{	const len = 80;	// max длина строки
	int   n;		// размер массива
	char* a;		// адрес массива строк
	int   i;		// индекс строки в массиве
	char  b[80];	// дл€ строки, которую будем искать в массиве
	char* s;		// адрес найденной строки
	printf("Input an array size: ");
	scanf("%d", &n);
	fflush(stdin);	// убираем символ новой строки из потока stdin
	a = (char*)malloc(n*len);
		// вводим строки
	printf("Input strings.\n");
	for (i = 0; i < n; ++i)
	{		putchar('>');
		gets(&a[i*len]);	// i*len - индекс первого символа строки	}	
	// сортируем массив строк
	qsort(a, n, len, (int (*)(const void*, const void*))strcmp);

		// выводим отсортированные строки
	printf("The sorted strings:\n");
	for (i = 0; i < n; ++i)
		puts(&a[i*len]);
		// вводим строку дл€ поиска
	printf("Input a string to search.\n>");
	gets(b);
		// ищем эту строку
	if(!(s = (char*) bsearch(b, a, n, len, 
			(int (*)(const void*, const void*))strcmp)))
		printf("There is no such a string.\n");
	else
		printf("The string index = %d.\n", (s-a)/len);
	free(a);	return 1;}
