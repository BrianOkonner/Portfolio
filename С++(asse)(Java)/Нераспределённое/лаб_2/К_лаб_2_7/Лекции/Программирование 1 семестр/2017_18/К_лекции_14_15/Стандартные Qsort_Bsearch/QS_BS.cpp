
/*������� qsort ��������� ���������� �������, �������� �������� �����
 ������������ ���. ��� ������� ��������� "������� ��������" ����������
 �������� � ����� ��������� ��������:

void  qsort(void *base, size_t n, size_t size, 
			int (*cmp) (const void *e1, const void *e2));
������� ������ � ������������ ����� stdlib.h. 
���������� ���������� ���� �������:
base	����� �������,
n	���������� ��������� � �������,
size	����� �������� �������,
cmp	��������� �� ������� ���������, ������� ����������:
-	������������� �����, ���� ������� e1 ������ �������� e2;
-	0, ���� ������� e1 ����� �������� e2;
-	������������� �����, ���� ������� e1 ������ �������� e2.

������� bsearch ��������� �������� ����� �������� � ��������������� �������.
 ��� ������� ����� ��������� ��������:
 void*  bsearch(const void *key, const void *base,
     size_t n, size_t size, int (*cmp)(const void *ck, const void  *ce);

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

/* ������� ��� ��������� ��������� ������� */
int comp_int(const int* e1, const int* e2)
{
	return *e1 - *e2;
}

/* ��������� ���������� ��������� ������� � ������ ������ ����� � ��������������� ������� */
int main()
{
	int  n;		/* ������ ������� */
	int* a;		/* ������ */
	int  i;		/* ������ */
	int  k;		/* ����� ��� ������ */
	int* s;		/* ����� ���������� ����� */

	cout<<"Input an array size: ";
	cin>>n;
	a =  new int [n];

	/* ������ ������ */
	cout<<"Input elements: ";
	for (i = 0; i < n; ++i)
		cin>>a[i];

	/* ��������� ������ */
	qsort(a, n, sizeof(int), 
		(int (*)(const void*, const void*))comp_int);


	/* ������� ��������������� ������ */
	cout<<"The sorted array: ";
	for (i = 0; i < n; ++i)
		cout<<a[i]<<' ';
	
	/* ������ ����� ��� ������ */
	cout<<endl<<"Input a number to search>";
	cin>>k;

	/* ���� ��� ����� � ��������������� ������� */
	if(!(s = (int*) bsearch(&k, a, n, sizeof(int), 
			(int (*)(const void*, const void*))comp_int)))
		cout<<"There is no such an integer"<<endl;
	else
		cout<<"The integer index = "<<s-a<<endl;
	free(a);

	return 0;
}
