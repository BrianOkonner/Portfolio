//Панько 7 гр
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
	cout<<"передана в функцию"<<endl;



}
void main()
{	char str[SIZE];
 char str1[SIZE];
 int i=0;
setlocale(LC_ALL,".1251");
	FILE *f1,*f2;
	if((f1=fopen("input.txt","r"))==0)//открываем файл и проверяем открылся ли он
	{
		cout<<"ошибка открытия файла"<<endl;
		return;//если не открылся то выходим
	}
	while(!feof(f1))//в цикле считываем из файла по одной строке
	{
		fgets(str,80,f1);//считываем строку и записываем ее в str
		cout<<"строка из файла"<<endl<<str<<"tokin:"<<endl<<endl;//выводим str на экран
//		делим строку на лексемы
		char *tokin;
		tokin= strtok(str, ";!,:.- ");
					while(tokin)
				{	
					cout<<tokin<<endl;
					tokin=strtok(NULL," ,.;:");
					funk(tokin);//передаём строку в функцию
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
		fprintf(f2,"результат в матрице    ");
		fprintf(f2,"\n ");
	}
			
		

	 fclose(f2);

int *mas,size,a;
cout<<"введите размерность"<<endl;
cin>>size;
mas=new int[size];
cout<<"введите массив для сортировки"<<endl;
for(int j=0; j<size;j++)
{
	cin>>a;
	mas[j]=a;
}
sort(mas,size);
}

/*//сколько раз символ 
//встречается в строке
void main(void)
{
char str[255],ch;
int i=0,sum=0;
  
  gets(str);
 //поиск символа в строке
// просмотр массива
  ch=getchar();
  while(str[i])
  	 if (ch==*(str+i++)) 
		  sum++;
	printf("sum :%d \n",sum);
}
*/