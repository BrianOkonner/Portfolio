int Prost(int a)
{
    int t=1;
    for (int i=2; i<=a/2; i++)
    {
        if (a%i == 0) t=0;
    }
    return t;
}

int Cif(int a)
{
    int b=0;
    while (a>0)
    {
        b++;
        a/=10;
    }
    return b;
}

int Step(int a, int n)
{
    int x=1;
    while (n>0)
    {
        if (n%2==1) x=x*a;
        a=a*a;
        n/=2;
    }
    return x;
}

bool Palind(int a)
{
    int n = Cif(a);
    int n1 = n;

    for (int i=0; i<n1/2; i++)
    {
        if ( (a/(Step(10, n-1)))%10 != a%10 )
            return false;
        a /= 10;
        n--;
        n--;
    }
    return true;
}