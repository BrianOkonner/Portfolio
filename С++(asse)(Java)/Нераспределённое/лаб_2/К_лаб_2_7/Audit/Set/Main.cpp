#include <iostream.h>
#include <conio.h>
#include "set.h"

void main()
{
	int p[]={0,13,7,5,11,3};
	Set s1(p,6);
	cout<<"S1= "<<s1;
	s1=s1+1;
	s1=s1-0;
	cout<<"  \"s1=s1+1;\n   s1=s1-0;\"\nS1="<<s1;
	Set s2(s1);
	cout<<"  \"Set s2(s1);\"\nS2= "<<s2;
    s2=s2+17;
	s2=s2+(-1);
	cout<<"  \"s2=s2+17;\n   s2=s2+(-1);\"\nS2= "<<s2;		
	cout<<"Conjunction(S1+S2): "<<s1+s2;
	cout<<"Disjunction(S1*S2): "<<s1*s2;
	cout<<"Subtraction(S2-S1): "<<s2-s1;
	s1-=13;
    cout<<"  \"s1-=13;\"\nS1= "<<s1;
	cout<<"   s2.include(13)= "<<s2.include(13)<<'\n';
	cout<<"   s1.include(17)= "<<s1.include(17)<<'\n';
	cout<<"   (s1==s1)="<<(s1==s1)<<" (s1==s2)="<<(s1==s2)<<'\n';
	cout<<"   (s1>s1)="<<(s1>s1)<<"   (s1>=s1)="<<(s1>=s1)<<'\n';
    cout<<"   (s1>s2)="<<(s1>s2)<<"   (s2>=s1)="<<(s2>=s1)<<'\n';
	cout<<"   (s1<s1)="<<(s1<s1)<<"   (s1<=s1)="<<(s1<=s1)<<'\n';
    cout<<"   (s1<s2)="<<(s1<s2)<<"   (s2<=s1)="<<(s2<=s1)<<'\n';	
	cout<<"   \"cin>>s2;\"\n";
	cin>>s2;
	cout<<s2;
}
