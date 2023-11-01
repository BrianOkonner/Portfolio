// 3. Разложение натурального числа на простые множители.

#include <stdio.h>

int main()
{
	int a;

	printf("Input number: ");
	scanf("%d", &a);

   for (int i=2;i<=a;i++)	
      while (a%i==0)
      {
		   a=a/i;
		   printf("%d ",i);
      }
	return 1;
}