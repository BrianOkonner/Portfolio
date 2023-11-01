//	2. Определение простоты натурального числа.

#include <stdio.h>;

int test_prost(int a)
{
	int p = 1;
	for(int i=2;i<a;++i)
	{
		if(!(a%i))
			p = 0;
	}
	return p;
}

int main(void)
{
	int a=1;
	
	printf("Program finds if the value is simple.\nInput value: ");
	scanf("%d",&a);
	if (test_prost(a))
		printf("%d - simple\n",a);
	else
		printf("%d - is not simple\n",a);
	return 0;
}
