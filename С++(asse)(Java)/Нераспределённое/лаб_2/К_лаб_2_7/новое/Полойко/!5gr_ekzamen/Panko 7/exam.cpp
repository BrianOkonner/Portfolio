//������ 7 ��
#include<iostream>
using namespace std;
int const SIZE=100;
void sort(int*a,int size)
{
	FILE *f1;
	f1=fopen("rez.txt","w");
	if(!f1)
		return;
	
		for(int i=0;i<size-1;i++)
		for(int j=i+1;j<size;j++)
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			fprintf(f1,"prosto otsortirovanniy dinamocheskiy massiv\n");
			cout<<"\notsortirovanniy"<<endl;
		for(int i=0;i<size;i++)
		{	cout<<a[i]<<' ';
			fprintf(f1,"%d ",a[i]);
		}
			
	
	fclose(f1);
}
void funk(char *tokin)
{	
	cout<<"�������� � �������"<<endl;



}
void main()
{	char str[SIZE];
 char str1[SIZE];
 int i=0;
setlocale(LC_ALL,".1251");
	FILE *f1,*f2;
	if((f1=fopen("input.txt","r"))==0)//��������� ���� � ��������� �������� �� ��
	{
		cout<<"������ �������� �����"<<endl;
		return;//���� �� �������� �� �������
	}
	while(!feof(f1))//� ����� ��������� �� ����� �� ����� ������
	{
		fgets(str,80,f1);//��������� ������ � ���������� �� � str
		cout<<"������ �� �����"<<endl<<str<<"tokin:"<<endl<<endl;//������� str �� �����
//		����� ������ �� �������
		char *tokin;
		tokin= strtok(str, ";!,:.- ");
					while(tokin)
				{	
					cout<<tokin<<endl;
					tokin=strtok(NULL," ,.;:");
					funk(tokin);//������� ������ � �������
				}
		
	}
	fclose(f1);
	f2=fopen("output.txt","w");
	if (f2==0)
	{
		cout<<"no"<<endl;
		return;
	}
	
	cout<<"matrix"<<endl;
	for(int i=0; i<5;i++)
	{
		for(int j=0; j<5;j++)
		fprintf(f2,"��������� � �������    ");
		fprintf(f2,"\n ");
	}
			
		

	 fclose(f2);

int *mas,size,a;
cout<<"������� �����������"<<endl;
cin>>size;
mas=new int[size];
cout<<"������� ������ ��� ����������"<<endl;
for(int j=0; j<size;j++)
{
	cin>>a;
	mas[j]=a;
}
sort(mas,size);
}

/*//������� ��� ������ 
//����������� � ������
void main(void)
{
char str[255],ch;
int i=0,sum=0;
  
  gets(str);
 //����� ������� � ������
// �������� �������
  ch=getchar();
  while(str[i])
  	 if (ch==*(str+i++)) 
		  sum++;
	printf("sum :%d \n",sum);
}
*/