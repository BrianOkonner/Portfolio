#include <iostream>
using namespace std;

int strmasslen; // длина массива разультата

char* str_expres;    // исходная строка-выражение
int *levels;      //  массив уровней

void parse(char *str,char** strmass)
{   //    разбиение исходной строки-выражения str  и получение
	//	 масссива  строк strmass из скобок, знаков операций и чисел

strmasslen=strlen(str);
for(int i=0,k=0;i<strlen(str);i++)
	{
	char ch=str[i];
	if(ch>='0' && ch<='9')
		{
		char *s=new char[80];
		int j=0;
		bool b=0;
		while((str[i]>='0' && str[i]<='9') || (str[i]=='.'))
			{
			if(str[i]=='.')
				{
				if(b)
					{
					cout<<"Wrong expression";
					exit(1);
					}
				b=1;
				}
			s[j++]=str[i++];
			}
		s[j]=0;
		j--;
		strmasslen-=j;
		i--;
		strcpy(strmass[k++],s);
		}
	else
	{  char chs[2];
	   chs[0]=ch;
       chs[1]=0;
		strcpy(strmass[k++],chs);}
	}
}

void Level( char **strmass)
{ // из масссива  строк strmass получение массива levels уровней приоритета
	int length=strlen(str_expres);
	int k=0;
for (int i=0;i<length;i++)
{
char zn=strmass[i][0];
switch(zn)
	 {
	 case '+': k--; levels[i]=k;break;
	 case '-': k--; levels[i]=k;break;
	 case '*': k--; levels[i]=k;break;
	 case '/': k--; levels[i]=k;break;
	 case ')': k--; levels[i]=k;break;
	 case '(': k++; levels[i]=k;break;
	 default : k++; levels[i]=k;break;
	 }
}
}

int Max_Levels( int* Levels, int def )
{ //  поиск наибольшего уровня и его номера в массиве
	int i, max, imax;
	max=Levels[0];
	imax=0;
	for( i=0; i<def; i++ )
	{
		if( Levels[i]>=max )
		{
			max=Levels[i];
			imax=i;
		}
	}
	return imax;
}

void change(int index,char**strmass)
{
	// удаление выделенной  тройки  и получение промежуточного результата
double num;

char zn=strmass[index-1][0];
switch(zn)
	{
	case '+': num=atof(strmass[index-2])+atof(strmass[index]); break;
	case '-': num=atof(strmass[index-2])-atof(strmass[index]); break;
	case '*': num=atof(strmass[index-2])*atof(strmass[index]); break;
	case '/': if(atof(strmass[index]))
		 	num=atof(strmass[index-2])/atof(strmass[index]); break;
	default: cout<<"Impossible operation"; exit(1);
	}

if ( strlen(strmass[index-1])==1)
{
sprintf(strmass[index-3],"%f",num);
levels[index-3]=levels[index]-1;
for(int i=index-2;i<strmasslen;i++)
	{
	levels[i]=levels[i+4];
	strmass[i]=strmass[i+4];
	}
strmasslen-=4;
}
}
void main()
{
	FILE *In,*Out;
		In=fopen("Expression.txt","r");
		Out=fopen("Result.txt","w");
	int index;
	char** strmass=new char *[80];
for (int i=0;i<80;i++)
   strmass[i]=new char[80];
	str_expres=new char[100];
	levels=new int[100];
	fscanf(In,"%s",str_expres);
	printf("%s\n",str_expres);
	parse( str_expres, strmass);
	   //for (int i=0;i<strmasslen;i++)
	   //	cout<<strmass[i]<<endl;
       //  cout<<"**"<<endl;
      Level(strmass);
		
	for (int j=1;j<=strmasslen;j++) 
	{
	//		for (int i=0;i<strmasslen;i++)
	//			cout<<levels[i];
	//		cout<<endl;
		index = Max_Levels( levels, strmasslen );
	change(index,strmass);
 //   for (int i=0;i<strmasslen;i++)
 //	cout<<strmass[i]<<endl;
		
//	cout<<"---"<<endl;
	}
	cout<<"Result="<<strmass[strmasslen-1]<<endl;
	fprintf(Out,"%s\n",strmass[strmasslen-1]);
    fclose(In);
	fclose(Out);
}