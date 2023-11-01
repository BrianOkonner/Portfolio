// Титков Андрей группа №5

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale (LC_ALL,".1251");
	ifstream in("Input.txt");
	ofstream fout("Result1.txt");
	if (!in)                        //проверка на существование файла
	{cout<<"файла нет"<<endl;
	return 0;
	}
//--------------------------------------------------------------------------------------
	char a[80];
	int m=0;                
	while(in.getline(a,80))
	{
		if (strlen(a)>0)               //пустота файла
		{
			fout<<"номер слова"<<"   "<<"слово"<<"   "<<"символ"<<"   "<<"длина"<<"   "<<"номер символа"<<endl;
			cout<<"исходная строка    "<<a<<endl;
			m++;	

			char *del=new char[7];		//строка разделителей
			strcpy(del," .,;:-!");		
			char *d=new char[80];		
			d=strtok(a,del);
			int num=1;   //номер лексеммы
//------------------------------------------------------------------------------------
			
			
			while (d!=NULL )    //разбитие на лексеммы			
				{	
					int q=1;
					int kol=1;      //промежуточная частота встречаемости
					int dlin=strlen(d); //длина лексеммы
					char symbol;     //само часто встречающийся символ
					int col=1;       //частота встречаемости какой-либо буквы
					int nom=1;       // номер само часто встречающегося элемента
					
					{int i=0;
					symbol=d[0];
						for (int i=0;i<=dlin;i++)
					{
						if (d[i]==d[i+1])
							kol++;

					else
					if (kol>col)
					{symbol=d[i];
					nom=i-kol+2;

					col=kol;}
					}
//------------------------------------------------------------------------------
					fout<<num<<"   "<<d<<"  "<<symbol<<"   "<<col<<"   "<<nom<<endl;				
					num++;
					d=strtok(NULL,del);	
					q++;
					}

				}
		}
	}
//--------------------------------------------------------------------------------
		if (m==0) //Если колличество строк равно нулю
		{
			cout<<"файл пуст"<<endl;
			return 0;		}

	in.close();
	fout.close();

	ifstream in1("Result1.txt");
	ofstream fout1("Result2.txt");

	char b[80];
	in1.getline(b,80);
	
	while (in1.getline(b,80))
	{
		char *str=new char[80];
		char *del1=new char[7];
		strcpy(del1," ,.;;-!");


		str=strtok(b,del1);
		int z=0;
		
		while (str!=NULL)
		{
			
			z++;
			{for (int i=0;i<m;i++)					
			if (z!=2)
			{cout<<str<<' ';
			fout1<<str<<' '; 
			
			}
			}		
			str=strtok(NULL,del1);
		}
		fout1<<endl;
		cout<<endl;
	}
	
		in1.close();
		fout1.close();
	


}