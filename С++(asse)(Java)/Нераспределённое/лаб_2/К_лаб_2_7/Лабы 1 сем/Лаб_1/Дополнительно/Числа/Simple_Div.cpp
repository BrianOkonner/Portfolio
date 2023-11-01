// Ќахождение всех делителей натурального числа.
// Sergiencko Anna 2k 7gr.

#include <stdio.h>
#include <math.h>
  
int main()
{
	int a, b;

    printf("Enter of integer number: ");
	scanf("%d", &a);

	printf("%d\n",1);

    for (b=2; b<=a;b++)
	{
		if (a%b == 0)
		{
			printf("%d\n",b);
			a=a/b;
			b=2;
		}
	}
	return 1;
}
