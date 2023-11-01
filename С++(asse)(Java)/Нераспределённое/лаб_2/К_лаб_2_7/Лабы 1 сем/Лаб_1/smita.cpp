#include <iostream>
//проверка СМИТА
using namespace std;
int sumz(int a)
{int b=0;
     while (a>0)
	 {
        b=b+(a%10);
        a=a/10;
	 }    
	 return(b);
}
void main()
{ int s=0,s1=0,s2=0,k;
	int n,i=2;
	cout<<"Vvedite chislo:\n";
	cin>>n;
	s1=sumz(n);
    while (n!=1)
	{ s2=0;k=0;
		if (n%i==0)
		{
			s2=sumz(i);
			while (n%i==0)
			{
			cout<<i<<" ";   //Выводим делитель     
			;//Удаляем у числа  делители, кратные i
               n=n/i;
			   k++;
			}
			s2=s2*k;
		}
		s=s+s2;
		i++;
	}
	cout<<s1<' '<<s;
	if (s1==s)
    cout <<"yes";
	else "no";
	cout<<endl;
}
