/*												Задача №B9
	Программу написал Владислав Владимирович Перевязчиков.( Специальность: прикладная матнмематика. Группа 8).
	Условие :Задан текстовый файл Input.txt, состоящий  из слов и некоторое предложение.
Разделителями между словами является некоторое множество знаков препинания.
Найти  строки, в которых встречается данное предложение, продублировать первое и последнее слова предложений. 
Результат записать  в новый файл Output.txt. Упорядочить слова  в искомых предложениях по  убыванию длин слов, результат сортировки
записать в файл Out_sort.txt. 
	Краткий алгоритм :(Предложение должно начинаться от точки и пробела(если в середине) и заканчиваться ею а также начинаться
с заглавной буквы) (в условии сказано даны слова с разделителями и прредложение(1) значит упорядочить и найти нужно только
одно потом просто вывалимся из цикла.)
	Тесты :*/
#include <iostream>
#include "fun_h.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio>  
using namespace std;
void main()
/*{ 
	int i=0;
	setlocale(LC_ALL,".1251");
	ifstream in("input.txt");
	ofstream out("output.txt");
    char *spr=" ,._!?:;+-",*s;
	s=new char [101];
	in.read(s,50*2);
	s[100]='\0';
	while (s[i]!='\0')
	{
		cout<<s[i];
		i++;
	}
	system("pause");
}*/
	/*ifstream in("input.txt");
	if (!in){ cout <<"jib,rf "<<endl; }
	in.seekg( 0, ios::end);
	long len =in.tellg();
	char *buf=new char [len+1];
	in.seekg(0,ios::beg);
	in.read(buf,len);
	buf[len]='\0';
	long n=0, i=0;
	while (buf[i])
	{
		if(buf[i]=='?')
		{
			for(i=n;i<=i;i++)
				cout<< buf[i];
			n=n+1;
		}
		if(buf[i]=='.'||buf[i]=='!')
			n=i+1;
		i++;
	}
	in.close();
	system("pause");
}*/
	
{
	setlocale(LC_ALL,".1251");
    char *spr=" ,._!?:;+-";
	ifstream in("input.txt");
	ofstream out("output.txt"), outs("out_sort.txt");
   // FILE *in = fopen_s("inputs.txt","r"),*out=fopen_s("output.txt","w"),*outs=fopen_s("out_sort.txt","w"); 
//	FILE *in,*out,*outs;
	/*fopen_s(&in,"input.txt","r");
	fopen_s(&out,"output.txt","w");
	fopen_s(&outs,"out_sort.txt","w");*/
    if(in==NULL||out==NULL||outs==NULL)  //если (файл) равен NULL,значит он не может открыться.Либо путь не тот.
    {
        cout<<"Ошибка в открытии файла "<<endl;
    }
    else
    {
		int i=0,o=-1,p=-1,l=0,h,q=1,a=0,g;
		char *str,up[100],c[]="1",*k;
		str=new char [100];
		k=new char[100];
		for(i='A';i<='Z';i++&&l++)
			up[l]=i;
		for(i='А';i<='Я';i++&&l++)
			up[l]=i;
		up[l]='Ё';
		up[l+1]='\0';
		l=0;
		cout<<"    Строки(а) в котрых встречается это предложение: "<<endl;
		while(!in.eof())
		{
			l++;
			in.getline(str,100,'\n');
			str[100]='\0';
			if(o!=-1&&p==-1)
				cout<<str<<endl;
		c[0]=str[0];
		if(strpbrk(c,up)!=0&&q==1&&o==-1)
			{
				cout<<str<<endl;
				o=0;
			h=l;
			for(i=0;str[i]<0||(ispunct(str[i])!=0&&isspace(str[i])!=0);i++)
				k[i]=str[i];
			k[i]=' ';
			k[i+1]=str[0];
			i++;
			//strcat(k,str);//Если ее убрать все работает
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
		{
			while(!in.eof())
			{
		in.getline(str,100,'\n');
		out<<endl;
		for(g=0;str[g]!='\0';g++)
		out<<str[g];
			}
		break;
		}
		}
		//for(i=0;!feof(in);i++);
	in.close();
	out.close();
	outs.close();
	}
/*	fclose(out);
	fclose(outs);
	fclose(in);*/
	system("pause");
}