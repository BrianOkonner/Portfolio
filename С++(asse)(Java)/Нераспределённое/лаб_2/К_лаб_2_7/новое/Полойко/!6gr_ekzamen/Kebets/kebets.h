void kebets()
{
	int i;
	char I_I=1,O_o=2,p=' ';
	for(i=1;i<25;++i)
	{
		if(i==1 || i==4 || i==12 || i==13 || i==14 || i==20 || i==23)
			cout<<O_o;
		if(i==7 || i==8 || i==9 || i==16 || i==17 || i==18)
			cout<<I_I;
		if(i==2|| i==3 || i==6 || i==11 || i==15 || i==19 || i==21 || i==22 || i==24)
			cout<<p;
	}
	cout<<endl;
	for(i=0;i<25;++i)
	{
		if(i==1 || i==3 || i==12 || i==20 || i==23)
			cout<<O_o;
		if(i==7 || i==16)
			cout<<I_I;
		if(i==2 || i==4 || i==6 || i==8 || i==9 || i==11 || i==13 || i==14 || i==15 || i==17 || i==18 || i==19 || i==21 || i==22 || i==24)
			cout<<p;
	}
	cout<<endl;
	for(i=0;i<25;++i)
	{
		if(i==2 || i==1 || i==12 || i==13 || i==14 || i==20 || i==23)
			cout<<O_o;
		if(i==7 || i==8 || i==9 || i==16 || i==17 || i==18)
			cout<<I_I;
		if(i==3 || i==4 || i==6 || i==11 || i==15 || i==19 || i==21 || i==22 || i==24)
			cout<<p;
	}
	cout<<endl;
	for(i=0;i<25;++i)
	{
		if(i==1 || i==3 || i==12 || i==20 || i==23 || i==14)
			cout<<O_o;
		if(i==7 || i==16)
			cout<<I_I;
		if(i==2 || i==4 || i==6 || i==8 || i==9 || i==11 || i==13 || i==15 || i==17 || i==18 || i==19 || i==21 || i==22 || i==24)
			cout<<p;
	}
	cout<<endl;
	for(i=1;i<25;++i)
	{
		if(i==1 || i==4 || i==12 || i==13 || i==14 || i==20 || i==23 || i==24 || i==21 || i==22)
			cout<<O_o;
		if(i==7 || i==8 || i==9 || i==16 || i==17 || i==18)
			cout<<I_I;
		if(i==2 || i==3 || i==6 || i==11 || i==15 || i==19)
			cout<<p;
	}
	cout<<endl;
	for(i=1;i<22;++i)
	{
		cout<<p;
	}
	cout<<O_o<<endl;
}