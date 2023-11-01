#include <stdio.h>
#include <iostream.h>
#include "ratio.h"

void main()
{	short k=0;
	ratio Drob,D1,Dt;
start:	
	try
	{	printf("Input first drob':\n");
		cin>>Drob;
		printf("\n");
		printf("Input second drob':\n");
		cin>>D1;
		printf("\n");
	while (k!=13)

	{	printf("Input\n\t1 for summ\n\t2 for sub\n\t3 for mult\n\t4 for div\n\t5 for convert\n\t6 for -\n\t7 for +\n\t8 for Summ(X+Y)\n\t9 for ==\n\t10 for ++(prefix)\n\t11 for ++(postfix)\n\t13 for exit\n");
		cin>>k;
		printf("\n");
		Dt=Drob;
		switch (k)
	{ case 1:	
		{	Drob+=D1;
				cout<<"X+Y= "<<Drob<<endl;
				break;}
			
		case 2:
			{
				Drob-=D1;
				cout<<"X-Y= "<<Drob<<endl;
				break;}
		case 3:	
			{
				Drob*=D1;
				cout<<"X*Y= "<<Drob<<endl;
				break;}
		case 4:	
			{
				Drob/=D1;
				cout<<"X/Y= "<<Drob<<endl;
				break;}
		case 5:
			{ cout<<double(Drob)<<endl;
				break;
			}
		case 6:{ cout<<"-X= "<<-Drob<<endl;
				break;} 
		case 7:{ cout<<"+X= "<<+Drob<<endl;
			   break;}
		case 8:
			{ cout<<"Summ= "<<Drob+D1<<endl;
				break;
			}
		case 9:
			{ cout<<"X==Y= "<<(Drob==D1)<<endl;
				break;
			}
		case 10:
			{  ++Drob;
				cout<<"++X "<<Drob<<endl;
				break;
			}
		case 11:

			{ Drob++;
				cout<<"X++ "<<Drob<<endl;
				break;
			}
		
		case 12:
			{ Drob=Drob+1;
				cout<<"X++ "<<Drob<<endl;
				break;
			}
		}
		Drob=Dt;
		printf("\n");
	}


	}
	catch(Zero_divide)
	{ cout<<"Zero divide!   Input New Data..."<<endl;
		goto start;}
}
