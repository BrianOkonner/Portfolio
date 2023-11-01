bool prost(int n)
{
	if (n == 1)
		return false;
	for (int d = 2; d*d <= n; d++)
	{
		if (n%d == 0)
			return false;
	}
	return true;
}
int palindrom(int n)
{
	int s1 = n;
	int s = 0;
	while (n != 0)
	{
		s = s * 10 + n % 10; n = n / 10;
	}
	if (s1 == s) return 1;
	return 0;
}
