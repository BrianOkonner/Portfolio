 #include <stdlib.h>
void  Rnd_array (int ar[],int *n)
{
   //  ����  ����������� � ��������� ���������   ������������ �������
	int i,j;
    printf("Enter dimension n \n");
	scanf("%d",n);
   	for (i=0;i<*n;i++) 
	    ar[i]=rand()%100;  ; 
	 
 }
void Print_array ( int ar[],int n)
	//  �����   ���������    �������
{
	 printf("Items array\n");
	for ( int i=0;i<n;i++)
		           printf("%5d",ar[i]);

		printf("\n");
}
