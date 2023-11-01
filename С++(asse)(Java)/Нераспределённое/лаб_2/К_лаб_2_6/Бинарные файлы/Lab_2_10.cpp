

/*				Работа с потоками в С++.

	Deshko Katerina 7 group  I kurs
	Programmirovanie Lab_2_10

	1. Создать  два бинарных файла с записями следующей структуры:
		struct  Student
		{
			long	num;		// номер зачетки
			char	name[10];	// имя студента
			int	group;		// номер группы
			double	grade;		// средний бал
		};

	1.1. Разработать программу, которая выполняет над заданными файлами алгебраические операции объединения
		(И), пересечения (З) и разности (-).
		Результат выполнения эти операций записывается в третий файл. Имя исходных файлов вводится с консоли,
		  а имя выходного файла определяется самой программой и выводится на консоль. Операция над файлами 
		  удовлетворяют следующим требованиям:
- операция объединения включает в результирующий файл только такие записи, которые находятся хотя бы в 
        одном из двух входных файлах;
- операция пересечения включает в результирующий файл только такие записи, которые находятся одновременно
           в двух входных файлах;
- операция разности включает в результирующий файл только такие записи, которые находятся в первом 
                файле и отсутствуют во втором файле;
Запросы на выполнение операций оформить в виде меню.
	1.2. Разработать программу, которая сортирует файл а) по номерам зачеток, б) по номерам групп,
	а внутри групп по фамилиям студентов. Запросы на сортировку выполнить в виде меню.*/

//****************************************************************************************//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <iostream.h>
# include <fstream.h>
/////////////////////////////////////
struct Student
{
	long num;		//номер зачётки
	char name[10];	//имя студента
	int group;		//номер группы
	double grade;	//средний бал
};
/////////////////////////////////////
 void CreateBinFile()
{	
	ofstream out;
	struct Student s1;
	char *str1;
    str1=(char*)malloc(10*sizeof(char));
	printf("Input the name of the first file\n");
	scanf("%s",str1);
   	out.open(str1,ios::out|ios::binary);

	if(!(cin.in))
	{
		printf("Open file '%s' was failed.\n",str1);
		return ;
	}
    printf("Input num, name, group, grade to '%s'\n",str1);
	printf("Press Ctrl+z to exit.\n");
    printf("1. "); 
	int i=2;
	scanf("%ld%s%d%lf", &s1.num, &s1.name, &s1.group, &s1.grade);
	while (!feof(stdin))
	{
		out.write((char*)&s1, sizeof(struct Student));
		printf("%d. ",i);
		i++;
		scanf("%ld %s %d %lf", &s1.num, &s1.name, &s1.group, &s1.grade); 
	}
	out.close();
}
 ///////////////////////////////////////////////////////////////////////
 void ReadBinFile(char *name)
 {
    ifstream in;
	struct Student s;	
	unsigned i=0;	
	in.open(name, ios::in|ios::binary);
	if (!(cin.in))
 	{
		printf("Open file '%s.bin' failed.\n",name);
		return;
	}
	in.read((char*)&s,sizeof(struct Student));
	i++;
	printf("      num   name   group   grade \n");
	do
	{
		printf("%2d. %4d %5s %7d %9.2lf\n",i,s.num,s.name,s.group,s.grade);
		in.read((char*)&s,sizeof(struct Student));
		++i;
	} 
	while (!in.eof());
	in.close();
}
///////////////////////////////////////////////////////////////////////
 long SizeOfFile(ifstream &f)
{
	f.seekg(0,ios::end);
	long size=f.tellg();
	f.seekg(0,ios::beg);
	return size;
} 
//////////////////////////////////////////////////////////////////
int CmpStruct (struct Student s1,struct Student s2)//сравниваем 2 структуры
{
	if((s1.num==s2.num)&&(strcmp(&s1.name[0],&s2.name[0])==0)&&(s1.group==s2.group)&&(s1.grade==s2.grade))
	 return 0;//если структуры равны
	else return 1;//если структуры не равны
}
/////////////////////////////////////////////////
void MyUnion(char* name1,char* name2)
{
	ifstream f1a, f2a;
	f1a.open(name1,ios::in|ios::binary);
	f2a.open(name2,ios::in|ios::binary);
	
	ofstream f_union;
    char *str1;
	str1=(char*)malloc(20*sizeof(char));
	strcpy(str1,"Union.bin");
   	f_union.open(str1, ios::out|ios::binary);
    struct Student s;//указатели на структуры

	f1a.read((char*)&s,sizeof(struct Student));

	do
	{	
		f_union.write((char*)&s,sizeof(struct Student));
		f1a.read((char*)&s,sizeof(struct Student));
	}
	while(!f1a.eof());

	f2a.read((char*)&s,sizeof(struct Student));
	do
	{	
		f_union.write((char*)&s,sizeof(struct Student));
		f2a.read((char*)&s,sizeof(struct Student));
	}
	while(!f2a.eof());

	printf("\n Union struct is in the file '%s.'\n",str1);
	f_union.close();
	f1a.close();
	f2a.close();
}
//////////////////////////////////////////////////
void MyCrossing(char* name1, char* name2)
{
	ifstream f1,f2;
	f1.open(name1, ios::in|ios::binary);
	f2.open(name2, ios::in|ios::binary);
	ofstream f_cross;
	char *str1;
	str1=(char*)malloc(20*sizeof(char));
	strcpy(str1,"Crossing.bin");
	
	f_cross.open(str1, ios::out|ios::binary);
    struct Student *struct1,*struct2;//указатели на структуры
	long size1,size2,i,j; int n,m;
	
	size1=SizeOfFile(f1)/(long)sizeof(struct Student);//количество записей в первом файле
	size2=SizeOfFile(f2)/(long)sizeof(struct Student);//количество записей во втором файле
    struct1=(struct Student*)malloc(size1*sizeof(struct Student));
	struct2=(struct Student*)malloc(size2*sizeof(struct Student));

	for(n=0;n<size1;n++)
	{ f1.read((char*)&struct1[n],sizeof(struct Student)); }
	
	for( m=0;m<size2;m++)
	{ f2.read((char*)&struct2[m],sizeof(struct Student)); }

	for( i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
		if(CmpStruct(struct1[i],struct2[j])==0)//если записи равны, то пишем в файл
			{
				f_cross.write((char*)&struct1[i],sizeof(struct Student));	
			}
		}
	}
	printf("\n Crossing struct is the file '%s'\n",str1);
	f_cross.close();
	f1.close();
	f2.close();
}
/////////////////////////////////////////
void MyDifference(char* name1, char* name2)
{
	ifstream f1,f2;
	f1.open(name1, ios::in|ios::binary);
	f2.open(name2, ios::in|ios::binary);
	ofstream f_diff;
	char *str1;
	str1=(char*)malloc(20*sizeof(char));
	strcpy(str1,"Difference.bin");

	f_diff.open(str1,ios::out|ios::binary);
	struct Student *struct1,*struct2;
	int g,h,ind=0; long j,i,size1,size2;

	size1=SizeOfFile(f1)/(long)sizeof(struct Student);
	size2=SizeOfFile(f2)/(long)sizeof(struct Student);

    struct1=(struct Student*)malloc(size1*sizeof(struct Student));
	struct2=(struct Student*)malloc(size2*sizeof(struct Student));

	for(g=0;g<size1;g++)
	f1.read((char*)&struct1[g],sizeof(struct Student));
	
	for(h=0;h<size2;h++)
	f2.read((char*)&struct2[h],sizeof(struct Student));
	
	for(i=0;i<size1;i++)
	{
		ind=0;
		for(j=0;j<size2;j++)
		if(CmpStruct(struct1[i],struct2[j])==0) ind=1;
		if(ind==0)  f_diff.write((char*)&struct1[i],sizeof(struct Student));		
	}
	printf("\n Different struct is in the file '%s'\n",str1);

	f_diff.close();
}
//////////////////////////////////////////
void PrintBinFile(ifstream &fprint)
{
	struct Student s;	
	unsigned i=0;	
	fprint.read((char*)&s,sizeof(struct Student));
	i++;
	printf("      num   name   group   grade \n");
	do
	{
	
		printf("%2d. %4d %5s %7d %9.2lf\n",i,s.num,s.name,s.group,s.grade);
		fprint.read((char*)&s,sizeof(struct Student));
		++i;
	} 
	while (!fprint.eof());
	fprint.close();
}
/////////////////////////////////////////////////////////
void Sort(char* name1)
{
	ifstream sort;
	sort.open(name1, ios::in|ios::binary);
	struct Student *s, tmp;
	long i,j,n,m;
    int ind;
    ofstream f_sort;
    n=SizeOfFile(sort)/(long)sizeof(struct Student);
	s=(struct Student*)malloc(n*sizeof(struct Student));

	for(m=0;m<n;m++)
    sort.read((char*)&s[m],sizeof(struct Student));
	
Repeat:
	printf("\nPlease, choose type of sort\n 1-By number\n 2-By groupe and name\n 0-exit\n ");
	scanf("%d",&ind);
	switch (ind)
	{
	   case 1: printf("The struct was sorted by number\n"); break;
	   case 2: printf("The struct was sorted by groupe and name\n"); break;
	   default: printf("\n"); printf("Illegal number, please,input a correct number"); goto Repeat;
	}
if (ind==1)
{	
	for(i=0;i<n;i++)
		{
			for(j=n-1;j>i;j--)
			{
				if(s[j-1].num>s[j].num)
				{
					tmp=s[j-1];
					s[j-1]=s[j];
					s[j]=tmp;
				}
			}
		}
}
//////////
if (ind==2)
{
	for(j=0;j<n;j++)
		{
		
			for(i=n-1;i>j;i--)
			{
				if(s[i-1].group>s[i].group)
				{
					tmp=s[i-1];
					s[i-1]=s[i];
					s[i]=tmp;
				}
				if((s[i-1].group==s[i].group)&&(strcmp(s[i-1].name,s[i].name)>0))

				{
					tmp=s[i-1];
					s[i-1]=s[i];
					s[i]=tmp;
				}
			}
		}
}
//////
	    f_sort.open("Sort.bin", ios::out|ios::binary);
        for(i=0;i<n;i++)
		f_sort.write((char*)&s[i],sizeof(struct Student));
        sort.close();
		f_sort.close();
	}
////////////////////////////////////////////////////////////////////////
void main(void)
{
	ifstream fin1, fin2, fsort,fx;
	int ind;
	char *name1, *name2, *name;
name1=(char*)malloc(20*sizeof(char));
name2=(char*)malloc(20*sizeof(char));
name=(char*)malloc(20*sizeof(char*));
RepeateAgain:
	printf("\n Choose an operation: \n 1-create binary file\n 2-union\n 3-crossing\n 4-difference\n 5-sort\n 6-print binary file\n 0-exit\n");
    scanf("%d",&ind);
char tmp[80];
	switch (ind)
	{
	    case 1: CreateBinFile();goto RepeateAgain;

		case 2:	printf("Input the name of the first file\n");
			    scanf("%s",name1);
				printf("Input the name of the second file\n");
				scanf("%s",name2);
				MyUnion(name1,name2);
				strcpy(&tmp[0],"Union.bin");
				fx.open(tmp,ios::in|ios::binary);
 			    PrintBinFile(fx);
				goto RepeateAgain;

		case 3: printf("Input the name of the first file\n");
			    scanf("%s",name1);
				printf("Input the name of the second file\n");
				scanf("%s",name2);
			   	MyCrossing(name1,name2);				
				strcpy(&tmp[0],"Crossing.bin");
				fx.open(tmp,ios::in|ios::binary);
			    PrintBinFile(fx);
				goto RepeateAgain;

		case 4: printf("Input the name of the first file\n");
			    scanf("%s",name1);
				printf("Input the name of the second file\n");
				scanf("%s",name2);
				MyDifference(name1,name2);
				strcpy(&tmp[0],"Difference.bin");
				fx.open(tmp,ios::in|ios::binary);
			    PrintBinFile(fx);
				goto RepeateAgain;

		case 5: printf("Input the name of the file\n");
			    scanf("%s",name1);
				Sort(name1);
                strcpy(&tmp[0],"Sort.bin");
				fx.open(tmp,ios::in|ios::binary);
			    PrintBinFile(fx);
                goto RepeateAgain;

		case 6: printf("Input the name of the file\n");
			    scanf("%s",name1);
				ReadBinFile(name1);
				goto RepeateAgain;

		case 0: exit(0);
		default : printf("\n"); printf("Illegal number, please,input a correct number"); 
			goto RepeateAgain;
	}
	fsort.close();
	fx.close();
}


