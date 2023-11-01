//Орловская Александра, 6 группа

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Spisok.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

/*struct Spisok	//двунаправленный список
{
	int data;
	Spisok *p;
};
*/
Spisok* first( int data )	//создание первого элемента
{
	Spisok *prev = new Spisok;
	prev -> data = data;
	prev -> p = 0;
	return prev;
}


int Count ( int n ) // количество цифр числа
{
	int c = 1;
	while ( n > 9 )
	{
		n = ( n - n % 10 ) / 10;
		c ++;
	}
return c;
}

int kub ( int a )
{
	int t = 0;
	int sum = 0;
	while ( t )
	{
		t = a % 10;
		sum = sum + t * t * t;
		a = a / 10;
	}
	return sum;

}

void Posled ( int* s, int x )
{
	int p = 0;

	s [ p ] = kub ( x );
			while ( s [ p ] != 153 )
				s [ ++p ] = kub ( s [ p ] );
}

int main ()
{
	setlocale ( LC_CTYPE, "Russian" );
	char** a = ( char** ) malloc ( sizeof ( char* ) * 100 );
	char str [ 80 ];
	char* point;
	int i = 0, n, c, n1, k = 0, p = 0;
	int* mas;
	int* s;
	int** Matr = ( int** ) malloc ( sizeof ( int* ) * 20 );
	int M1 = 3, M2 = 0;
	Spisok *top;

	FILE* in;		

	if( ! ( in = fopen("Input.txt", "r") ) )
	{
		printf("Open file failed.\n");
		return 1;
	}

	/*fgets ( str, 80, in );
		a [ 0 ] = new char [ strlen ( str ) ];
		a [ 0 ] = strtok ( str, " ,.:;" );*/

	/*while ( !feof ( in ) )
	
		while ( point = strtok ( NULL, " ,.:;" ) )
	{
		a [ ++i ] = new char [ 80 ];	
		a [ i ] = point;
	}	*/
	
	for ( int y = 0; y < 20; y++ )
		Matr [ y ] = new int [ 20 ];


		while (!feof(in))
	{
		
		
		fgets ( str, 80, in );
		a [ i ] = new char [ 80 ];
		a [ i++ ] = strtok ( str, " ,.:;" );
		cout << a [ i - 1 ] << "\n";
		
	while ( point = strtok ( NULL, " ,.:;" ) )
	{
		a [ i ] = new char [ 80 ];	
		a [ i++ ] = point;
		cout << a [ i - 1 ] << "\n";
	}	
		}

		n = i;
		mas = new int [ n ];

	for ( int j = 0; j < n; j++ )
	{
		c = atoi ( a [ j ] );
		if ( c )
		{
			top = first ( c );
			n1 = j;
			mas [ k ] = c;
			Matr [ 0 ][ 0 ] = c;
			break;
		}
	}

	for ( int j = n1 + 1; j < n; j++ )
	{
		c = atoi ( a [ j ] );
		if ( c )
		{
			mas [ ++k ] = c;
			Matr [ 0 ][ ++M2 ] = c;
			push( &top, c );
		}
	}

	if ( k == 0 )
	{
		cout << " в строках чисел нет !!! ";
		return 0;
	}
	cout << "строки-числа : \n";
	for ( int k1 = 0; k1 <= k; k1++ )
		cout << mas [ k1 ] << "\n";

	int cou = 0;
	M2 = 0;

	for ( int j = 0; j < k; j++ )
		if ( mas [ j ] % 3 == 0 )
		{
			cou++;
			Matr [ 2 ][ ++M2 ] = mas [ j ];
		}
	s = new int [ cou ];
	int t;

	for ( int j = 0; j < k; j++ )
	{
		p = 0;
		if ( mas [ j ] % 3 == 0 )
		{
			//Matr [ M1++ ][ 1 ] = mas [ j ]; 
			//Posled ( s, mas [ j ] );
			/*s [ p ] = kub ( mas [ j ] );

			while ( s [ p ] != 153 )
				s [ ++p ] = kub ( s [ p ] );
			*/	

			
		}
	}	
		
	FILE* out;		

	out = fopen("Out.txt", "w");

	for ( int v = 0; v < M1; v++ )
	
		for ( int v1 = 0; v1 < M2; v1++ )
		{
			fprintf ( out, "%d", Matr [ v ][ v1 ] );
			fprintf ( out, "%s", "   " );
		}
	




	//for ( int j = 0; j < n; j++ )
	//	cout << a [ j ] << "\n";

	//cout << "\n" << c;

	//while ( top )
	//	cout << pop ( &top ) << " ";

	//free ( a );

	fclose ( in );
	fclose ( out );
	cout << "\n\n";
	return 0;
}


