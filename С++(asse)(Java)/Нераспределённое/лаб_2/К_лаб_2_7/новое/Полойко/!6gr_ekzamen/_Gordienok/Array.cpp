int Array (int n)
{
	int t;
	if (n/10 == 0)
	{
		s+=n*n*n;
		return s;
	}
	else 
	{
		t = n%10;
		s+= t*t*t;
		Array (n/10);
	}
	return s;
}

int* ArrayAll (int n)
{
	int Arr[100], *outMass;
	i = 0;
	Arr[i++] = n;
	do
	{
		Arr[i++] = Array (Arr[i-1]);
		s = 0;
	}
	while (Arr[i-1] != 153);
	outMass = new int [i-1];
	for (int u = o;u<i-1;u++)
		outMass[u] = Arr[u];
	return outMass;
}