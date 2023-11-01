
// The second therm. Lab1.

/*	1. Создать  два бинарных файла с записями следующей структуры:
		struct  Student
		{
			long	num;		// номер зачетки
			char	name[10];	// имя студента
			int	group;		// номер группы
			double	grade;		// средний бал
		};

	1.1. Разработать программу, которая выполняет над заданными файлами 
алгебраические операции объединения (?), пересечения (?) и разности (?). 
Результат выполнения эти операций записывается в третий файл. Имя исходных 
файлов вводится с консоли, а имя выходного файла определяется самой 
программой и выводится на консоль. Операция над файлами удовлетворяют 
следующим требованиям:
-	операция объединения включает в результирующий файл только 
такие записи, которые находятся хотя бы в одном из двух входных файлах;
-	операция пересечения включает в результирующий файл только 
такие записи, которые находятся одновременно в двух входных файлах;
-	операция разности включает в результирующий файл только такие 
записи, которые находятся в первом файле и отсутствуют во втором файле;
Запросы на выполнение операций оформить в виде меню.
	1.2. Разработать программу, которая сортирует файл 
а) по номерам зачеток, 
б) по номерам групп, а внутри групп по фамилиям студентов. Запросы на сортировку выполнить в виде меню.
*/

#include <iostream>
#include <fstream>

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

/*
*/
struct student
{
	long num;		//номер зачётки
	char name[10];	//имя студента
	int group;		//номер группы
	double grade;	//средний бал
};

void createBF ( char * name );
long size_of_file ( ifstream & file );
int comparison ( student , student , int );
void association ( ifstream & file1 , ifstream & file2 );
void intersection ( ifstream & file1 , ifstream & file2 );
void difference ( ifstream & file1 , ifstream & file2  );
void printBF ( ifstream & file );
void sort ( ifstream & file , int );


int main()
{
	char file1[21], file2[21], menu;

	cout << "Enter the name of first file (numbers of simbols is less than 20)\n";
	cin >> file1;

	cout << endl << "If you want to create this file, press 'Y'" << endl <<
		"If you don't want to create file press 'N' \n";
	cin >> menu;

	if ( ( menu == 'Y') || ( menu == 'y' ) )
		createBF ( &file1[0] );
	
	cout << endl << "Enter the name of the second file (numbers of simbols is less then 20)\n";
	cin >> file2;

	cout << endl << "If you want to create this file, press 'Y'" << endl <<
		"If you don't want to create file press 'N' \n";
	cin >> menu;

	if ( ( menu == 'Y') || ( menu == 'y' ) )
		createBF ( & file2[0] );

	ifstream  pointF1 , pointF2 , pointF3 , pointF4;
	pointF1.open( file1 , ios_base :: in | ios_base :: binary );
	pointF2.open( file2 , ios_base :: in | ios_base :: binary );

	if ( !pointF1.is_open() || !pointF2.is_open() )
	{
		cout << "Error!!! File can't be opened\n";
		exit(0); 
	}

	cout << "If you want to see your information press 'Y', else press 'N'";
	cin >> menu;

	if ( ( menu == 'Y') || ( menu == 'y' ) )
	{
		printBF ( pointF1 );
		printBF ( pointF2 );
	}

	int ch;

label1:	cout << endl << "Now, please, choose one of the operation\n";
	cout << "1) association\n" << "2) intersection\n" << "3) difference\n" << "4) exit\n";   

	do
	{
		cin >> ch;
	}
	while ( ( ch < 1 ) || ( ch > 4 ) );
	
	char fcn[21];

	switch ( ch )
	{
	case 1 : association ( pointF1 , pointF2 );
			 strcpy ( &fcn[0] , "outAssociation.bin" );
			 break;

	case 2 : intersection ( pointF1 , pointF2 );
			 strcpy ( &fcn[0] , "outIntersection.bin" );
			 break;
	
	case 3 : difference ( pointF1 , pointF2 );
		     strcpy ( &fcn[0], "outDifference.bin" );
			 break;

	default : pointF1.close();
			  pointF2.close();
			  pointF3.close();
			  pointF4.close();
			  exit ( 0 );
	}

	pointF3.open( fcn , ios_base :: out | ios_base :: binary );

	if ( !pointF3.is_open() )
	{
		cout << endl << "Error!!! File can't be opened\n";
		exit(0);
	}

	cout << "If you want to see your information press 'Y', else press 'N'";
	cin >> menu;

	if ( ( menu == 'Y') || ( menu == 'y' ) )
		printBF ( pointF3 );

	cout << endl << "Choose, how do you want to sort\n 1)By NUM\n 2) By GROUP\n";

	do
	{
		cin >> ch;
	}
	while ( ( ch < 1 ) || ( ch > 2 ) );

	sort ( pointF3 , ch );

	pointF4.open ( "outSort.bin" , ios_base :: out | ios_base :: binary );

	if ( !pointF4.is_open() )
	{
		cout << "Error!!! File can't be opened\n";

		pointF1.close();
		pointF2.close();
		pointF3.close();

		exit(0);
	}

	cout << "If you want to see your information press 'Y', else press 'N'";
	cin >> menu;

	if ( ( menu == 'Y') || ( menu == 'y' ) )
		printBF ( pointF4 );
	
	pointF3.close();

	goto label1;

	return (0);
}

void createBF ( char * name )
{
	ofstream file;
	file.open( name , ios_base :: out | ios_base :: binary );

	if ( !file.is_open() )
	{
		cout << "Error!!! File can't be opened\n";
		exit(0);
	}

	cout << "PLease, enter number of yours structures\n";
	int i;
	cin >> i;
	i=i-1;

	student buf;

	cout << "Enter the data\n";
	cout << "Field's  NUM, NAME, GROUP and GRADE\n ";

	cin >> buf.num >> buf.name >> buf.group >> buf.grade;
	file.write( ( char * ) & buf , sizeof( student ) );

	for ( i ; i > 0 ; --i )
	{
		cout << "Field's NUM, NAME, GROUP and GRADE\n ";
		cin >> buf.num >> buf.name >> buf.group >> buf.grade;
		file.write( ( char * ) & buf , sizeof( student ) );
	}	
	
	file.close();
}

long size_of_file ( ifstream & file )
{
	file.seekg( 0 , ios :: end );
	long size=file.tellg();
	file.seekg( 0 , ios :: beg );
	
	return size;
}

int comparison ( student st1 , student st2, int kind )
{
	if ( kind == 0 )
	{
		if (( st1.num == st2.num ) && ( strcmp ( & st1.name[0] , & st2.name[0] ) == 0 ) && ( st1.group == st2.group ) && ( st1.grade == st2.grade ) )
		return 0;

		else
		return 1;
	}

	else
	{
		if ( st1.group == st2.group )
			return strcmp ( & st1.name[0] , & st2.name[0] ); 

		else
		{
			if ( st1.group > st2.group )
			return 1;

			else
			return -1;
		}
	}
}

void association ( ifstream & file1 , ifstream & file2 )
{
	ofstream file;
	file.open( "outAssociation.bin" , ios_base :: out | ios_base :: binary );

	if ( !file.is_open() )
	{
		cout << "Error!!! File can't be opened\n";

		file1.close();
		file2.close();

		exit(0);
	}

	student auxilary;

	file1.clear();
	file1.seekg( 0 , ios :: beg );
	file1.read( ( char * ) & auxilary , sizeof ( student ) );

	while ( !file1.eof() )
	{
		file.write( ( char * ) & auxilary , sizeof ( student ) );
		file1.read( ( char * ) & auxilary , sizeof ( student ) );
	}

	file2.clear();
	file2.seekg( 0 , ios :: beg );
	file2.read( ( char * ) & auxilary , sizeof ( student ) );

	while ( !file2.eof() )
	{
		file.write( ( char * ) & auxilary , sizeof ( student ) );
		file2.read( ( char * ) & auxilary , sizeof ( student ) );
	}

	cout << " Informations saved! \n The name of output file is  outAssociation.bin\n";

	file.close();
}

void intersection ( ifstream & file1 , ifstream & file2 )
{
	file1.clear();
	file1.seekg( 0 , ios :: beg );

	file2.clear();
	file2.seekg( 0 , ios :: beg );

	int strNumb1 = size_of_file ( file1 ) / ( int ) sizeof ( student );
	int strNumb2 = size_of_file ( file2 ) / ( int ) sizeof ( student );

	student *auxilary1 , *auxilary2 ;

	auxilary1 = new student [strNumb1];
	auxilary2 = new student [strNumb2];

	if ( ( auxilary1 == 0 ) || ( auxilary2 == 0 ) ) 
	{
		cout << "Error!!!\n";

		if ( auxilary1 != 0 )
			delete  [] auxilary1;

		file1.close();
		file2.close();

		exit(0);
	}
	
	ofstream file3;
	file3.open( "outIntersection.bin" , ios_base :: out | ios_base :: binary );
	
	if ( !file3.is_open() )
	{
		cout << "Error! Can't open file\n";

		file1.close();
		file2.close();

		delete [] auxilary1;
		delete [] auxilary2;

		exit(0);
	}
	
	for ( int i = 0 ; i < strNumb1 ; i++ )
		file1.read( ( char * ) & auxilary1[i] , sizeof ( student ) );

	
	for ( int j = 0 ; j < strNumb2 ; j++ )
		file2.read( ( char * ) & auxilary2[j] , sizeof ( student ) );

	for ( int n = 0 ; n < strNumb1 ; n++ ) 
	{
		for ( int m = 0 ; m < strNumb2 ; m++ )

			if ( comparison ( auxilary1[n] , auxilary2[m] , 0 ) == 0 )	
				file3.write( (char * ) & auxilary1[n] , sizeof ( student ) );
	}

	cout << "The name of output file is outIntersection.bin \n";

	delete [] auxilary1;
	delete [] auxilary2;

	file3.close();
}

void difference ( ifstream & file1 , ifstream & file2 )
{
	file1.clear();
	file1.seekg( 0 , ios :: beg );

	file2.clear();
	file2.seekg( 0 , ios :: beg );

	int strNumb1 = size_of_file ( file1 ) / ( int ) sizeof ( student );
	int strNumb2 = size_of_file ( file2 ) / ( int ) sizeof ( student );

	student *auxilary1, *auxilary2;

	auxilary1 = new student [ strNumb1 ];
	auxilary2 = new student [ strNumb2 ];

	if ( ( auxilary1 == 0 ) || ( auxilary2 == 0 ) )
	{
		cout << "Error!!!\n";

		if ( auxilary1 != 0 )
		delete [] auxilary1;

		file1.close();
		file2.close();

		exit(0);
	}

	ofstream file3;
	file3.open( "outDifference.bin" , ios_base :: out | ios_base :: binary );

	if ( !file3.is_open() )
	{
		cout << "Error!!!\n";

		file1.close();
		file2.close();

		delete [] auxilary1;
		delete [] auxilary2;

		exit(0);
	}
	
	for ( int i = 0 ; i < strNumb1 ; i++)
		file1.read( ( char * ) & auxilary1[i] , sizeof ( student ) );

	for ( int j = 0 ; j < strNumb2 ; j++)
		file2.read( ( char * ) & auxilary2[j] , sizeof ( student ) );
	
	for ( int n = 0 ; n < strNumb1 ; n++ )
	{
		int x=0;

		for ( int m = 0 ; m < strNumb2 ; m++ )
			if ( comparison ( auxilary1[n] , auxilary2[m] , 0 ) == 0 )			
				x=1;
	
		if ( x == 0 )
			file3.write( ( char * ) & auxilary1[n] , sizeof ( student ) );
	
	}

	cout << "The name of output file is outDifference.bin\n";

	delete [] auxilary1;
	delete [] auxilary2;
	
	file3.close();
}

void printBF ( ifstream & file )
{
	cout << " Information in your file: \n";
	file.clear();
	file.seekg( 0 , ios :: beg );

	int strNumb = size_of_file ( file ) / ( int ) sizeof ( student );

	if ( strNumb == 0 )
	{
		cout << "Your file if empty, What's a pity :( \n";

		file.close();
		exit(0);
	}
	student auxilary;

	cout << "NUM   NAME   GROUP   GRADE \n";

	for ( int i = 0 ; i < strNumb ; i++ ) 
	{
		file.read( ( char * ) & auxilary , sizeof ( student ) );
		cout << endl << auxilary.num << "   " << auxilary.name  << "   " << auxilary.group << "   " << auxilary.grade << endl;
	}
}

void sort( ifstream & file , int kind )
{
	ofstream sortfile;
	sortfile.open( "outSort.bin" , ios_base :: out | ios_base :: binary );

	if ( !sortfile.is_open() )
	{
		cout << " Error!!! File can't be opened\n";

		file.close();
		
		exit(0);
	}

	file.clear();
	file.seekg( 0 , ios :: beg );

	int strNumb = size_of_file ( file ) / ( int ) sizeof ( student );

	student *auxilary;
	auxilary = new student [strNumb];

	if ( auxilary == 0 )
	{
		cout << "Error!!!\n";

		file.close();
		sortfile.close();

		exit(0);
	}
	
	for ( int i = 0 ; i < strNumb ; i++)
		file.read( ( char * ) & auxilary[i] , sizeof ( student ) );
	
	if ( kind == 1 )
	{
		student hstd;

		for ( int j = 0 ; j < strNumb ; j++)
		{

			for ( int m = strNumb - 1 ; m > j ; m--)
			{
				if ( auxilary[m - 1].num > auxilary[m].num )
				{
					hstd = auxilary[m-1];
					auxilary[m-1] = auxilary[m];
					auxilary[m] = hstd;
				}
			}
		}
	}

	if ( kind == 2 )
	{
		student hstd;
		for ( int q = 0 ; q < strNumb ; q++ )
		{
			
			for ( int w = strNumb - 1 ; w > q ; w-- )
			{
				
				if ( comparison ( auxilary[w-1] , auxilary[w] , 1 ) == 1 )
				{
					hstd = auxilary[w-1];
					auxilary[w-1] = auxilary[w];
					auxilary[w] = hstd;
				}
			}
		}
	}

	for ( int value = 0 ; value < strNumb ; value ++ )
		sortfile.write( ( char * ) & auxilary[value] , sizeof ( student ) );
	
	cout << "Your information sorted! Congradulation!  The name of output file is sort.bin\n";
	
	sortfile.close();
	
	delete [] auxilary;
}