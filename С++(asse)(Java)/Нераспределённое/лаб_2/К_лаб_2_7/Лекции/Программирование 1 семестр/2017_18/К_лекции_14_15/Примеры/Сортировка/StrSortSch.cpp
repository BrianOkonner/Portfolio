//C��������a ������� �����. 
//������ �������� � �������.

int main()
{	const len = 80;	// max ����� ������
	int   n;		// ������ �������
	char* a;		// ����� ������� �����
	int   i;		// ������ ������ � �������
	char  b[80];	// ��� ������, ������� ����� ������ � �������
	char* s;		// ����� ��������� ������
	printf("Input an array size: ");
	scanf("%d", &n);
	fflush(stdin);	// ������� ������ ����� ������ �� ������ stdin
	a = (char*)malloc(n*len);
		// ������ ������
	printf("Input strings.\n");
	for (i = 0; i < n; ++i)
	{		putchar('>');
		gets(&a[i*len]);	// i*len - ������ ������� ������� ������	}	
	// ��������� ������ �����
	qsort(a, n, len, (int (*)(const void*, const void*))strcmp);

		// ������� ��������������� ������
	printf("The sorted strings:\n");
	for (i = 0; i < n; ++i)
		puts(&a[i*len]);
		// ������ ������ ��� ������
	printf("Input a string to search.\n>");
	gets(b);
		// ���� ��� ������
	if(!(s = (char*) bsearch(b, a, n, len, 
			(int (*)(const void*, const void*))strcmp)))
		printf("There is no such a string.\n");
	else
		printf("The string index = %d.\n", (s-a)/len);
	free(a);	return 1;}
