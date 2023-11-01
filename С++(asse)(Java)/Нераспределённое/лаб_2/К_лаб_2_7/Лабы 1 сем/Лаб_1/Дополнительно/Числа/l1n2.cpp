// 2. Определение простоты натурального числа.

#include <stdio.h>

int main()
{
	int a,k=0;

	printf("Input number: ");
	scanf("%d", &a);

   for (int i=2;i<=a/2;i++)	
      if (a%i==0)
	      k=1;

	if (k==0)
		printf("prostoe  ");
	else
		printf("ne prostoe  ");

	return 1;
}
