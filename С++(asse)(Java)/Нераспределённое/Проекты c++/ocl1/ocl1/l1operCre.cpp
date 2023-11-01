// Пример создания потока функцией CreateThread

#include <windows.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h> 
#include <iomanip>
using namespace std;
int strLength(const char* str)
{
    int size = 0;
    while(*str++) ++size;
    return size;
}
struct employee 
{
	int    num; // идентификационный номер сотрудника
	char   name[10]; // имя сотрудника    
	double hours; // количество отработанных часов  
};


int main()
{
	
	char lpszComLine[1024]="",lpszComLine2[1024]="",cs[]="D:\\Creator.exe",rs[]="D:\\Reporter.exe";
 
	 STARTUPINFO si;  PROCESS_INFORMATION pi; 
 
 ZeroMemory(&si, sizeof(STARTUPINFO));  si.cb=sizeof(STARTUPINFO); 

	int	inc = 10;
	char namef[1024],buft[256],buf[10];
	employee* empl;
	int colf;
	setlocale(LC_ALL,"1251");
	cout << "Enter name of bin file:" << endl;
	cin >> namef;
	cout << "Enter number records of file:" << endl;
	cin >> colf;
	strcat_s(lpszComLine,1000,cs);
	strcat_s(lpszComLine,1000," ");
	strcat_s(lpszComLine,1000,namef);
	strcat_s(lpszComLine,1000," ");
	strcat_s(lpszComLine,1000,itoa(colf,buf,10));
	system("pause");
	if (!CreateProcess(cs,lpszComLine, NULL, NULL, FALSE,    CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) 
	{
		 _cputs("The new process is not created.\n");
		 _cputs("Check a name of the process.\n");  
		 _cputs("Press any key to finish.\n");  
		 _getch();
		 return 0;
	}
	WaitForSingleObject(pi.hProcess, INFINITE); 
	ifstream in(namef,ios::binary);
	while(!in.eof())
	{
		cout<<in.getline(buft,256);
	}
	_cputs("\n");
	system("pause");
	strcat_s(lpszComLine2,rs);
	strcat_s(lpszComLine2," ");
	strcat_s(lpszComLine2,namef);
	cout << "Enter name of report file:" << endl;
	cin >> namef;
	cout << "Enter payment for hour:" << endl;
	cin >> colf;
	strcat_s(lpszComLine2," ");
	strcat_s(lpszComLine2,namef);
	strcat_s(lpszComLine2," ");
	strcat_s(lpszComLine2,itoa(colf,buf,10));
	if (!CreateProcess(rs,lpszComLine2, NULL, NULL, FALSE,    CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) 
	{
		 _cputs("The new process is not created.\n");
		 _cputs("Check a name of the process.\n");  
		 _cputs("Press any key to finish.\n");  
		 _getch();
		 return 0;
	}
	WaitForSingleObject(pi.hProcess, INFINITE); 
	ifstream in1(namef);
	while(!in1.eof())
	{
		cout<<in1.getline(buft,256);
	}
	system("pause");
	return 0;
}

/*fstream out(namef);
	empl=new emloyee[colf];
	out<<" "<< empl[i].num<<" "<< empl[i].hours<<" "<< empl[i].hours<<endl;
	for (int i = 0; i < colf; i++)
	{
		cout << "Введите данные сотрудника № " << i+1<<" через \"Enter\":"<<endl;
		cin >> empl[i].num >> empl[i].hours >> empl[i].hours;
		out<<" "<< empl[i].num<<" "<< empl[i].hours<<" "<< empl[i].hours<<endl;
	}
	system("pause");
	return 0;
}*/

/*int main(int argc, char* args[]) 
{
	setlocale(LC_ALL,"1251");
	int	inc = 10;
	char g[1024];
	char namef[1024]="",l[1024];
	strcat(namef,"pop.txt");
	const int h=atoi("1");
	employee* empl=new employee[h];
	setlocale(LC_ALL,"1251");
	ofstream out(namef);
//	out<<" "<< empl[i].num<<" "<< empl[i].hours<<" "<< empl[i].hours<<endl;
	for (int i = 0; i < h; i++)
	{
		_cputs("Enter data of the worker N");
		_cputs(itoa(i+1,l,1000));
		_cputs(" threw \"Enter\":\n");
		cin>> empl[i].num>> empl[i].name>> empl[i].hours;
		_itoa(empl[i].num,g,10);
		out.write(itoa(strLength(g),g,10),strLength(itoa(strLength(g),g,10)));
		out.write(" ", 1); 
		out.write(itoa(strLength(empl[i].name),g,10), strLength(itoa(strLength(empl[i].name),g,10))); 
		out.write(" ",1); 
		_ltoa(empl[i].hours,g,10);
		out.write(itoa(strLength(g),g,10), strLength(itoa(strLength(g),g,10))); 
		out.write(" ",1); 
		_itoa(empl[i].num,g,10);
		out.write(g,strLength(g)); 
		out.write(empl[i].name, strLength(empl[i].name)); 
		_ltoa(empl[i].hours,g,10);
		out.write(g,strLength(g)); 
	}
	out.close();
	system("pause");
	return 0;
}*/
/*int main(int argc, char* args[]) 
{
	setlocale(LC_ALL,"1251");
	int	inc = 10,i,j=0,po[3];
	char g[100],**jk;
	jk=new char*[3];
	for(i=0;i<3;i++)
		jk[i]=new char[100];
	//g[7]=' ';
	char namefb[100]="",namefot[100]="";
	strcat_s(namefb,args[1]);
	strcat_s(namefot,args[2]);
	const int h=atoi(args[3]);
	employee empl;
	setlocale(LC_ALL,"1251");
	ifstream in(namefb,ios::binary);
	ofstream out(namefot);
	out<<"Отчёт по файлу <<"<<namefb<<">>"<<endl;
	out<<setw(15)<<left<<"ID Работника"<<setw(15)<<"Имя"<<setw(15)<<"Часы работы"<<setw(15)<<"Зарплата"<<endl;
	char temp[1]="",temp2='=';
	int gh[10];
	gh[0]=(int)'0';
	gh[1]=(int)'1';
	gh[2]=(int)'2';
	gh[3]=(int)'3';
	gh[4]=(int)'4';
	gh[5]=(int)'5';
	gh[6]=(int)'6';
	gh[7]=(int)'7';
	gh[8]=(int)'8';
	gh[9]=(int)'9';
	while (!in.eof())
	{
/*	for(i=0;i<3;i++)
		{*/
	/*		while(temp2!=' ')
			{
				in.read(&temp2, 1);
				for(i=0;i<10;i++)
				{
					if((int)temp2==gh[i])
					{

					}
					temp[0]=temp2;
					g[j]=temp[0];
					j++;
				}
			g[j]='/r';
			char temp[1]="";
			j=0;
			po[i]=atoi(g);
			char g[100]={0};
			i++;
		}
		for(i=0;i<3;i++)
		{
			in.read(jk[i],po[i]);
		}
		empl.num=atoi(jk[0]);
		strcat_s(empl.name,1000,jk[1]);
		empl.hours=atol(jk[2]);
		out<<setw(15)<<left<<empl.num<<setw(15)<<empl.name<<setw(15)<<empl.hours<<setw(15)<<empl.hours*h<<endl;
		empl.num=empl.hours=0;
		for(i=0;i<10;i++)empl.name[i]=0;
		for(j=0;j<3;j++)
			for(i=0;i<100;i++)jk[j][i]=0;
		for(j=0;j<3;j++)po[j]=0;
	}
	out.close();
	in.close();
	cout<<654;
	return 0;
}*/