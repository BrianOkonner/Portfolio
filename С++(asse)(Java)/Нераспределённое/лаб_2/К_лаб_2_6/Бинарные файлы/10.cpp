/* lab 2_10
2. ������ ��� �������� ����� � �������� ��������� ���������:
		struct  Student
		{
			long	num;		// ����� �������
			char	name[10];	// ��� ��������
			int	group;		// ����� ������
			double	grade;		// ������� ���
		};

	2.1. ����������� ���������, ������� ��������� ��� ��������� ������� �������������� ��������
	����������� ( ), ����������� ( ) � �������� ( ). ��������� ���������� ��� �������� 
	  ������������ � ������ ����. 
	��� �������� ������ �������� � �������, � ��� ��������� ����� ������������ ����� ���������� �
	��������� �� �������. �������� ��� ������� ������������� ��������� �����������:
-	�������� ����������� �������� � �������������� ���� ������ ����� ������, ������� ��������� 
���� �� � ����� �� ���� ������� ������;
-	�������� ����������� �������� � �������������� ���� ������ ����� ������, ������� ��������� 
������������ � ���� ������� ������;
-	�������� �������� �������� � �������������� ���� ������ ����� ������, ������� ��������� � 
������ ����� � ����������� �� ������ �����;
������� �� ���������� �������� �������� � ���� ����.
	2.2. ����������� ���������, ������� ��������� ���� �) �� ������� �������, 
	�) �� ������� �����, � ������ ����� �� �������� ���������. 
	 ������� �� ���������� ��������� � ���� ����.
	 */
//(c) Copyright 2008 GusevAV(Jubelee)
#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
struct  Student
{
	long	num;		// ����� �������
	char	name[10];	// ��� ��������
	int	group;		// ����� ������
	double	grade;		// ������� ���
};
void create(char *name)
{
	Student T;
	int n=1;
	int count=0;
	ofstream S(name,ios::binary);
	cout<<"Creating file: "<<name<<endl;
	cout<<"How many students do you want to input?"<<endl;
    cin>>count;
	cout<<"Enter information about students: "<<endl;
	while(n<=count)
	{
		cout<<"Student number "<<n<<endl;
		cout<<"Number of zachotka ";
    	cin>>T.num;
    	cout<<"Name of student 10 ";
    	cin>>T.name;
    	cout<<"Number of group ";
    	cin>>T.group;
    	cout<<"Grade ";
    	cin>>T.grade;
		S.write((char*)&T,sizeof(Student));
		n++;
	}
	S.close();
}
void unon(ifstream& A,ifstream& B)
{

}
void add(ifstream& A,ifstream& B)  //???????????
{
	Student T;
	ofstream out("output.bin",ios::binary);
	while(!A.eof())
	{
		A.read((char*)&T,sizeof(Student));
		out.write((char*)&T,sizeof(Student));
	}
	while(!B.eof())
	{
		B.read((char*)&T,sizeof(Student));
		out.write((char*)&T,sizeof(Student));
	}	

	printf("\n Output filename is output.bin\n");
}
void cross(ifstream& A,ifstream& B)
{
	Student *F1,*F2;
	Student T;
	double sz1,sz2;
	ofstream out("output.bin",ios::binary);
    A.seekg(0,ios::end);
	sz1=A.tellg();     //������ ����� �
    sz1/=sizeof(Student);
	A.seekg(0,ios::beg);
	B.seekg(0,ios::end);
	sz2=A.tellg()/sizeof(Student);     //������ ����� �
	B.seekg(0,ios::beg);
	F1=new Student[sz1];
	F2=new Student[sz2];
	for(int i=0;i<=sz1;i++)
        A.read((char*)&F1[i],sizeof(Student));
	for(int j=0;j<=sz2;j++)
		B.read((char*)&F2[j],sizeof(Student));
	for(i=0;i<=sz1;i++)
	{
		for(j=0;j<=0;j++)
			if(strcmp(F1[i].name,F2[j].name)&&(F1[i].grade==F2[j].grade)&&(F1[i].group==F2[j].group)&&(F1[i].num==F2[j].num))
				out.write((char*)&F1[i],sizeof(Student));
	}
}
void sub(ifstream& A,ifstream& B)
{
	Student *F1,*F2;
	Student T;
	double sz1,sz2;
	ofstream out("output.bin",ios::binary);
    A.seekg(0,ios::end);
	sz1=A.tellg();     //������ ����� �
    sz1/=sizeof(Student);
	A.seekg(0,ios::beg);
	B.seekg(0,ios::end);
	sz2=A.tellg()/sizeof(Student);     //������ ����� �
	B.seekg(0,ios::beg);
	F1=new Student[sz1];
	F2=new Student[sz2];
	for(int i=0;i<=sz1;i++)       //������� ���� �� ������ � ������
        A.read((char*)&F1[i],sizeof(Student));
	for(int j=0;j<=sz2;j++)
		B.read((char*)&F2[j],sizeof(Student));
	for(i=0;i<=sz1;i++)
	{
		for(j=0;j<=0;j++)
			if(!(strcmp(F1[i].name,F2[j].name)&&(F1[i].grade==F2[j].grade)&&(F1[i].group==F2[j].group)&&(F1[i].num==F2[j].num)))
				out.write((char*)&F1[i],sizeof(Student));
	}
}
void main()
{
	ofstream out("Students.dat",ios::binary);
	char FileNameA[30],FileNameB[30];
	int choise;
	ifstream A,B;
	cout<<"Do you already have a two .bin file 1/0?"<<endl;
	cin>>choise;
	if (choise==1)
	{
		cout<<"Enter name of file A: ";
		cin>>FileNameA;
		cout<<"Enter name of file B: ";
		cin>>FileNameB;
		ifstream A(FileNameA,ios::binary);
	    ifstream B(FileNameB,ios::binary);
		goto swit;
	}
	else
	{
crt:    
	    cout<<"Let's get create it!"<<endl;	 
		cout<<"Enter name of file A: ";
		cin>>FileNameA;
		cout<<"Enter name of file B: ";
		cin>>FileNameB;		
	    create(FileNameA);
		create(FileNameB);
		ifstream A (FileNameA,ios::binary);
	    ifstream B (FileNameB,ios::binary);
		goto swit;
	}
swit:
	cout<<endl<<endl;
	cout<<"Menu:"<<endl<<"1.Union"<<endl<<"2.Cross"<<endl<<"3.Sub"<<endl<<"4.Make .bin file"<<endl<<"5.Exit"<<endl<<"Enter Your Choise: ";
    cin>>choise;
	switch(choise)
	{
	case 1: {add(A,B);goto swit;};
	case 2: {cross(A,B);goto swit;};
	case 3: {sub(A,B);goto swit;};
	case 4:	goto crt;
	case 5: goto exit;
	}

exit:;
 

}

