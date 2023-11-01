// B9(L5).cpp : Defines the entry point for the console application.
/*												Задача №B9
	Программу написал Владислав Владимирович Перевязчиков.( Специальность: прикладная матнмематика. Группа 8).
	Условие :Задан текстовый файл Input.txt, состоящий  из слов и некоторое предложение.
Разделителями между словами является некоторое множество знаков препинания.
Найти  строки, в которых встречается данное предложение, продублировать первое и последнее слова предложений. 
Результат записать  в новый файл Output.txt. Упорядочить слова  в искомых предложениях по  убыванию длин слов, результат сортировки
записать в файл Out_sort.txt. 
	Краткий алгоритм :(Предложение должно начинаться от точки и пробела(если в середине) и заканчиваться ею а также начинаться
с заглавной буквы) 
	Тесты :*/
// file_read.cpp: определяет точку входа для консольного приложения.
 
//#include <stdafx>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio> 
using namespace std;
 
int main()
{
    //setlocale(LC_ALL, "rus"); 
    setlocale(LC_ALL,".1251");// корректное отображение Кириллицы
	char buff[50]; // буфер промежуточного хранения считываемого из файла текста
   
	// Сдесь  надо вместо "r" "w" -> ios::in ios::out  т.к std Class 
	ifstream in("input.txt",ios::in);      //   открыли файл для чтения
	ofstream out("output.txt",ios::out);   //  для записи
	ofstream outs("out_sort.txt",ios::out); //  для записи сорт.
	//
	if(in==NULL||out==NULL||outs==NULL)//Сдесь правильно
   {
      cout<<"Ошибка в открытии файла "<<endl;
   }    
	else 
	{
	 
		// Для проверки--->
	// Удалить или закоментировать /*  */
	in >> buff; // считали первое слово из файла
    cout << buff << endl; // напечатали это слово
 
    in.getline(buff,50); // считали строку из файла
    
	cout << endl;

	cout << buff << endl; // напечатали эту строку
	
   // <-- Для проверки

	 
	  // !!! ЭТО КОМПМЛИРУЕТСЯ 
	 //   Но есть Ошибка Вылетает
	 // Дальше не проверял
		int i=0,o=-1,p=-1,l=0,j=0,h,q=1,a=0,g;
		char *str,up[100],*c="12",*k;
		c=new char(100);
		str=new char (100);
		k=new char(200);
	
		for(i='A';i<='Z';i++&&j++)
			up[j]=i;
		for(i='А';i<='Я';i++&&j++)
			up[j]=i;
		up[j]='Ё';
		up[j+1]='\0';
		for(j=j;j>=0;j--)
		cout<<up[j];
		while(!in.eof())
		{
			l++;
			in.getline(str,100,'\n');
		c[0]=str[0];
		if(strpbrk(c,up)!=0&&q==1)
			{o=0;
			h=l;
			for(i=0;str[i]<0||(ispunct(str[i])!=0&&isspace(str[i])!=0);i++)
				k[i]=str[i];
			k[i]=' ';
			k[i+1]=str[0];
			i++;
			for(g=1;str[g]!='\0';g++)//Если закомментировать строки начиная с этой
				k[i+g]=str[g];
			g=1;
			k[i+g]='\0';
			str=k;//По эту то все работает, иначе вылазит ошибка что куча была повреждена
		}
			//for(i==i;(str[i]>0&&ispunct(str[i])==0)||(str[i]>0&&isspace(str[i])==0);i++){}
			//InsStrNum(k,str,i);
			//break;
		i=0;
		q=0;
        while(str[i]!='\0')   
        {
			c[0]=str[i+2];
			if((str[i]=='.'||str[i]=='!'||str[i]=='?')&&str[i+1]==' '&&strpbrk(c,up)!=0&&o==-1)
			{
				o=i+2;
				h=l;
			for(g=2;str[g]<0||(ispunct(str[i+g])!=0&&isspace(str[i+g])!=0);g++)
				k[g]=str[i+g];
			k[i+g]=' ';
			k[i+g+1]='\0';
			i++;
			}
		if (o!=-1)
		{
			if((str[i]=='.'||str[i]=='!'||str[i]=='?')&&(str[i+1]=='\0'||str[i+1]==' '))
			{
				p=i;
				a=l;
				for(i--;str[i]<0||(ispunct(str[i])==0&&isspace(str[i])==0);i--){}
				i++;
			for(g=0;str[i+g]<0||(ispunct(str[i+g])==0&&isspace(str[i+g])==0);g++)
				k[g]=str[i+g];
			k[g]=' ';
			k[g+1]='\0';
			break;
			}
		}
		if(str[i]=='.'||str[i]=='!'||str[i]=='?')
			q=1;
			i++;
		}
		for(g=0;str[g]!='\0';g++)
			out<<str[g];
		out<<endl;
		if(p!=-1)
		break;
		}
		cout<<o<<" "<<p<<" "<<a<<" "<<h<<endl;
		//for(i=0;!feof(in);i++);
		cout<<k;
	
	// закрываем файлы
	in.close();
	out.close();
	outs.close();	
 
	}
   system("pause");
    return 0;
}