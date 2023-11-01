//	3. Разложение натурального числа на простые множители.
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
	
	printf("Razlozhenie na prostiye.\nInput value: ");
	scanf("%d",&a);
	for(int i=2;i<=a;++i)
	{
		while(!(a%i))
		{
			a/=i;
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}
