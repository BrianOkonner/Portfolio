
void sort(int *a, int n)
{
	int i,t=1,temp;
	while(t!=0)
	{
		t=0;
		for(i=0;i<n-1;++i)
		{
			if(a[i]%10>a[i+1]%10)
			{
				temp=a[i+1];
				a[i+1]=a[i];
				a[i]=temp;
				++t;
			}
		}
	}
}
