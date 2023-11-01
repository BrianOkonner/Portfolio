/*Лабораторная работа №10 Лисаевича М.Н.
1. Создать  два бинарных файла с записями следующей структуры:
		struct  Student
		{
			long	num;		// номер зачетки
			char	name[10];	// имя студента
			int	group;		// номер группы
			double	grade;		// средний бал
		};

	1.1. Разработать программу, которая выполняет над заданными файлами алгебраические операции объединения (?), пересечения (?) и разности (-). Результат выполнения эти операций записывается в третий файл. Имя исходных файлов вводится с консоли, а имя выходного файла определяется самой программой и выводится на консоль. Операция над файлами удовлетворяют следующим требованиям:
операция объединения включает в результирующий файл только такие записи, которые находятся хотя бы в одном из двух входных файлах;
операция пересечения включает в результирующий файл только такие записи, которые находятся одновременно в двух входных файлах;
операция разности включает в результирующий файл только такие записи, которые находятся в первом файле и отсутствуют во втором файле;
Запросы на выполнение операций оформить в виде меню.
	1.2. Разработать программу, которая сортирует файл а) по номерам зачеток, б) по номерам групп, а внутри групп по фамилиям студентов. Запросы на сортировку выполнить в виде меню.

*/
#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	long num;		//номер зачётки
	char name[10];	//имя студента
	int group;		//номер группы
	double grade;	//средний бал
};


void CreateBinFile(char *name)
{

	//FILE* out;		
	ofstream out(name,ofstream:: binary);		
	struct student s;		
	printf("\nEnter number, name, group, grade (To exit press CTRL+Z)\n");
	scanf("%ld %s %d %lf",&s.num,&s.name,&s.group,&s.grade);
//	printf("%lf",s.grade);
	while (!feof(stdin))
	{			
		//fwrite(&s, sizeof(struct Student ), 1, out);
		out.write((char*)&s, sizeof(s));
		printf("\nEnter number, name, group, grade (To exit press CTRL+Z)\n");
		scanf("%ld %s %d %lf",&s.num,&s.name,&s.group,&s.grade);

	}	
	//fclose(out);
	out.close();
}

int FileSize(ifstream& f)
{
	int i=0;
	struct student s;
//	s=(struct student*)calloc(20,sizeof(struct student));
	while (!f.eof())
	{
	f.read((char*)&s, sizeof(struct student));
	i++;
	}
	f.seekg(ios::beg);
	return (i-1); 
}

int CmpStruct (struct student s1,struct student s2)
{
	if((s1.num==s2.num)&&(strcmp(&s1.name[0],&s2.name[0])==0)&&(s1.group==s2.group)&&(s1.grade==s2.grade))
	{return 0;}
	return 1;
}

void add(char* name1,char* name2)
{
	//FILE* in1;
	//FILE* in2;
	//FILE* out;
	ifstream in1(name1, ifstream::binary);
	ifstream in2(name2, ifstream::binary);
	ofstream out("outputadd", ofstream::binary);

	struct student s1;	
	struct student s2;
	unsigned i;		
		i=0;
		//fseek(in1, i*sizeof(struct Student), SEEK_SET);
		in1.seekg(0);
		/*if(!fread(&s1, sizeof(struct Student), 1, in1))
		{
			printf("The wrong index.\n");
			return;
		}*/
		in1.read((char*)&s1, sizeof(s1));
		
		//fseek(in2, i*sizeof(struct Student), SEEK_SET);
   		in2.seekg(0);

	/*	if(!fread(&s2, sizeof(struct Student), 1, in2))
		{
			printf("The wrong index.\n");
			return;
		}*/
		in2.read((char*)&s2, sizeof(s2));

//fseek(out,0,SEEK_SET);
		out.seekp(0);		
   do
	{	
		 //fwrite(&s1, sizeof(struct Student), 1, out);	
		out.write((char*)&s1, sizeof(s1));
        //fread(&s1, sizeof(struct Student), 1, in1);
		in1.read((char*)&s1, sizeof(s1));
	}
	while (!in1.eof());
	 do
	{
		 //fwrite(&s2, sizeof(struct Student), 1, out);
		out.write((char*)&s2, sizeof(s2));
		//fread(&s2, sizeof(struct Student), 1, in2);	
		in2.read((char*)&s2, sizeof(s2));
	}
	while (!in2.eof());		
	//fclose(in1);
	//fclose(in2);
	//fclose(out);
	in1.close();
	in2.close();
	out.close();
}

void intersection(char* name1,char* name2)
{

	//FILE* in1;
	//FILE* in2;
	//FILE* out;
	ifstream in1(name1, ifstream::binary);
	ifstream in2(name2, ifstream::binary);
	ofstream out("intersection", ofstream::binary);
	struct student s1;	
	struct student s2;	
	/*if(!(in1 = fopen(p1, "rb")))
	{
		printf("Open file failed.\n");
		return ;
	}
		if(!(in2 = fopen(p2, "rb")))
	{
		printf("Open file failed.\n");
		return ;
	}
			if(!(out = fopen(p, "wb")))
	{
		printf("Open file failed.\n");
		return ;
	}	*/
		in1.seekg(0);
		/*if(!fread(&s1, sizeof(struct Student), 1, in1))
		{
			printf("The wrong index.\n");
			return;
		}*/
		in1.read((char*)&s1, sizeof(s1));
		
		//fseek(in2, i*sizeof(struct Student), SEEK_SET);
   		in2.seekg(0);

	/*	if(!fread(&s2, sizeof(struct Student), 1, in2))
		{
			printf("The wrong index.\n");
			return;
		}*/
		in2.read((char*)&s2, sizeof(s2));

//fseek(out,0,SEEK_SET);
		out.seekp(0);		
int x1,x2,x3;
do
{
	do
	{	
	 x1=strlen(s1.name);
	 x2=strlen(s2.name);
	 if(x1==x2)
		x3=strncmp(s1.name,s2.name,x1);	
	 else
		 x3=1;
		if((s1.num==s2.num)&&(x3==0)&&(s1.group==s2.group)&&(s1.grade==s2.grade))
			//fwrite(&s1, sizeof(struct Student), 1, out);	
			out.write((char*)&s1, sizeof(s1));
			
        //fread(&s1, sizeof(struct Student), 1, in1);		
		in1.read((char*)&s1, sizeof(s1));
	}
	while (!in1.eof());
  //fread(&s2, sizeof(struct Student), 1, in2);
	in2.read((char*)&s2, sizeof(s2));
//  fseek(in1, 0*sizeof(struct Student), SEEK_SET);

	in1.close();
	in1.open(name1, ifstream::binary);
		in1.seekg(0);

  // fread(&s1, sizeof(struct Student), 1, in1);		
	in1.read((char*)&s1, sizeof(s1));
}
while (!in2.eof());		
	//fclose(in1);
	//fclose(in2);
	//fclose(out);
	in1.close();
	in2.close();
	out.close();
}

void difference(char* name1,char* name2)
{
	//FILE* in1;
	//FILE* in2;
	//FILE* out;
	ifstream in1(name1, ifstream::binary);
	ifstream in2(name2, ifstream::binary);
	ofstream out("difference", ofstream::binary);
	struct student s1;	
	struct student s2;	
	in1.seekg(0);
	in1.read((char*)&s1, sizeof(s1));
	in2.read((char*)&s2, sizeof(s2));
	out.seekp(0);	
int x1,x2,x3,r=0;
do
{
	do
	{	
	 x1=strlen(s1.name);
	 x2=strlen(s2.name);
	 if(x1==x2)
		x3=strncmp(s1.name,s2.name,x1);	
	 else
		 x3=1;
		if((s1.num==s2.num)&&(x3==0)&&(s1.group==s2.group)&&(s1.grade==s2.grade))
			r=1;	
        //fread(&s2, sizeof(struct Student), 1, in2);	
	in2.read((char*)&s2, sizeof(s2));
	}
	while (!in2.eof());
	if(r!=1)
//	fwrite(&s1, sizeof(struct Student), 1, out);
	out.write((char*)&s1, sizeof(s1));
	r=0;
 // fread(&s1, sizeof(struct Student), 1, in1);
	in1.read((char*)&s1, sizeof(s1));

  //fseek(in2, 0*sizeof(struct Student), SEEK_SET);
	in2.close();
	in2.open(name2, ifstream::binary);
	in2.seekg(0);
  // fread(&s2, sizeof(struct Student), 1, in2);  
	in2.read((char*)&s2, sizeof(s2));
}
while (!in1.eof());		
	//fclose(in1);
	//fclose(in2);
	//fclose(out);
	in1.close();
	in2.close();
	out.close();
}
void PrintBinFile(char* p)
{
	//FILE* in;		
	ifstream in(p, ifstream::binary);
	struct student s;			
	in.read((char*)&s, sizeof(s));
	printf("\n number, name, group, grade\n");
   do
	{	
		printf(" %6ld %5s %6d  %2.2lf\n",s.num,s.name,s.group,s.grade); 
		//fread(&s, sizeof(struct Student), 1, in);		
		in.read((char*)&s, sizeof(s));
	}
	while (!in.eof());		//!feof(in)
	//fclose(in);
	in.close();
	printf("\n");
}
 
void  SortNum(char*p) 
{
	FILE* in;	
	struct student s[100];		
	int i=0,a[100],b[100],m,j,t,t2;
	if(!(in = fopen(p, "rb+")))
	{
		printf("Open file failed.\n");
		return ;
	}		
		fseek(in, 0*sizeof(struct student), SEEK_SET);    
		if(!fread(&s[i], sizeof(struct student), 1, in))
		{
			printf("The wrong index.\n");
			return;
		}		
		a[i]=s[i].num;
		b[i]=i;
	do
	{	
		i++;
        fread(&s[i], sizeof(struct student), 1, in);
		a[i]=s[i].num;
		b[i]=i;
	}
	while (!feof(in));
	 m=i;	
	for (i=0;i<m;i++)
	   for (j=m-1;j>i;j--)
		   if(a[j-1]>a[j])
		   {
			    t=a[j-1];
				a[j-1]=a[j];
				a[j]=t;

				t2=b[j-1];
				b[j-1]=b[j];
				b[j]=t2;		   
		   }
fclose(in);
if(!(in = fopen(p, "wb")))
	{
		printf("Open file failed.\n");
		return ;
	}		
	for (i=0;i<m;i++)
		fwrite(&s[b[i]], sizeof(struct student), 1, in);
	fclose(in);	
}

void  SortGroup(char*p) 
{
	FILE* in;	
	struct student s[100];	
	//struct Student s2;	
	int i=0,a[100],b[100],m,j,t,t2;
	char *f[100];
	if(!(in = fopen(p, "rb+")))
	{
		printf("Open file failed.\n");
		return ;
	}		
		fseek(in, 0*sizeof(struct student), SEEK_SET);    
		if(!fread(&s[i], sizeof(struct student), 1, in))
		{
			printf("The wrong index.\n");
			return;
		}
		//fseek(in,0,SEEK_SET);
		a[i]=s[i].group;
		b[i]=i;
	do
	{	
		i++;
        fread(&s[i], sizeof(struct student), 1, in);
		a[i]=s[i].group;
		b[i]=i;
	}
	while (!feof(in));
	 m=i;	
	for (i=0;i<m;i++)
	   for (j=m-1;j>i;j--)
		   if(a[j-1]>a[j])
		   {
			    t=a[j-1];
				a[j-1]=a[j];
				a[j]=t;

				t2=b[j-1];
				b[j-1]=b[j];
				b[j]=t2;		   
		   }

fclose(in);
	//	ReadBinFile(p);
if(!(in = fopen(p, "wb")))
	{
		printf("Open file failed.\n");
		return ;
	}		
	for (i=0;i<m;i++)
		fwrite(&s[b[i]], sizeof(struct student), 1, in);
	fclose(in);	
	if(!(in = fopen(p, "rb+")))
	{
		printf("Open file failed.\n");
		return ;
	}		
	i=0;
	int d;
		fseek(in, 0, SEEK_SET); 			
		if(!fread(&s[i], sizeof(struct student), 1, in))
		{
			printf("The wrong index.\n");
			return;
		}		
		d=strlen(s[i].name)+1;
			f[i]=(char*)malloc(10);
			strncpy(f[i],s[i].name,d);
		fseek(in, 0, SEEK_SET);
	while (!feof(in))
	{	
		if((s[i].num)>0)
		{
        fread(&s[i], sizeof(struct student), 1, in);
		d=strlen(s[i].name)+1;
		f[i]=(char*)malloc(10);
		strncpy(f[i],s[i].name,d);
		i++;
		}
		else
			break;
	}
//	m=i-1;
	qsort(f,m,sizeof(char*),(int (*)(const void*, const void*))CmpStruct);
	for (i=0;i<m;i++)
	{		
		d=strlen(f[i])+1;		
		strncpy(s[i].name,f[i],d);		
	}
	fclose(in);
		//	ReadBinFile(p);

if(!(in = fopen(p, "wb")))
	{
		printf("Open file failed.\n");
		return ;
	}		
		fseek(in, 0, SEEK_SET);
	for (i=0;i<m;i++)
		fwrite(&s[i], sizeof(struct student), 1, in);
		fclose(in);	
			//	ReadBinFile(p);

}

void Sort(char* name)
{
	int t;
	printf("\nPlease, choose type of sort\n1 - By number\n2 - By groupe and name\n");
	scanf("%d",&t);
	do
	{
		if (t==1) SortNum(name);
		if (t==2) SortGroup(name);
	}
	while ((t!=1)&&(t!=2));
}

void main(void)
{
	char file1[21],file2[21],file[21];
	int t;
	do
	{
		printf("\nPlease choose a function: ");
		printf("\n\n1 - Create file\n2 - Print file\n3 - Union\n4 - Intersection\n5 - Difference\n6 - Sort\n7 - Exit\n");
		scanf("%d",&t);
		
		switch (t)
		{
			case 1: printf("\nEnter name of first file (max 20 lettrs): ");
					scanf("%s",&file);
					CreateBinFile(file);				
					break;
			case 2: printf("Enter name of the file, please: ");
					scanf("%s",&file);
					PrintBinFile(file);
						break;
			case 3:	printf("\nEnter name of first file: ");
					scanf("%s",&file1);
					printf("\nEnter name of second file: ");
					scanf("%s",&file2);
					add(file1,file2);
					break;

			case 4: printf("\nEnter name of first file: ");
					scanf("%s",&file1);
					printf("\nEnter name of second file: ");
					scanf("%s",&file2);
					intersection(file1,file2);
					break;

			case 5: printf("\nEnter name of first file: ");
					scanf("%s",&file1);
					printf("\nEnter name of second file: ");
					scanf("%s",&file2);
					difference(file1,file2);
					break;
								
			case 6: printf("Enter name of the file, please: ");
					scanf("%s",&file);
					Sort(file);
					break;
			default: break;
		}
	}
	while (t!=7); 
}
