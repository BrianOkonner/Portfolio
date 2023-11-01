/*													Lab2_1 Stack(1)
	Программу написал Владислав Владимирович Перевязчиков.( Специальность: прикладная матнмематика. Группа 8)
	Условие :Использование (динамического) стека.
1.1	Задано выражение (инфиксная форма, например (5+45)*(55-5))  содержащее числа (любого типа), знаки операций, круглые скобки.
Записать его в виде обратной польской записи (постфиксная форма) и вычислить его значение. 
	Алгоритм :
Пока есть ещё символы для чтения:
Читаем очередной символ.
Если символ является числом, добавляем его к выходной строке..
Если символ является открывающей скобкой, помещаем его в стек.
Если символ является закрывающей скобкой:
До тех пор, пока верхним элементом стека не станет открывающая скобка, выталкиваем элементы из стека в выходную строку. При этом открывающая скобка удаляется из стека, но в выходную строку не добавляется. Если стек закончился раньше, чем мы встретили открывающую скобку, это означает, что в выражении либо неверно поставлен разделитель, либо не согласованы скобки.
Если символ является оператором о1, тогда:
1) пока приоритет o1 меньше либо равен приоритету оператора, находящегося на вершине стека выталкиваем верхние элементы стека в выходную строку;
2) помещаем оператор o1 в стек.
Когда входная строка закончилась, выталкиваем все символы из стека в выходную строку. В стеке должны были остаться только символы операторов; если это не так, значит в выражении не согласованы скобки.
 Тесты:
 inS1.txt :
 (5,8999*5*8+10000+35)*4
 файл Stack№1.txt:
 5.8999 5 * 8 * 10000 + 35 + 4 * 
Результат вычисления выражения равен:  41084
*/ 

#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
//int prrr(stack <char[15]> s,stack <double> l);
void main()
{
	ifstream in,out1("Stack№1.txt");
	ofstream out("Stack№1.txt");
	in.open("inS1.txt");
	double p;
    setlocale(LC_ALL,".1251");
	char t[15],g;
	int i=0;
	stack <char> s; stack <double> l;
	while(!in.eof())
	{
		i=0;
		in>>t[0];
		i++;
		if(isalnum(t[0])!=NULL)
		{
			while(in>>t[i]&&(isalnum(t[i])!=NULL||t[i]==','))
			{
				i++;
			}
			g=t[i];
			t[i]='\0';
			out << strtod(t, '\0')<<" ";
			if(t[i]=='(')
				s.push(g);
			else
				if (g == ')')
				{
					while (s.top() != '(')
					{
						out << s.top()<<" ";
						s.pop();
					}
					s.pop();
				}
				else
					if (g == '*'||g == '/')
					{
						while (s.empty()==false&&(s.top() == '*' || s.top() == '/'))
						{
							out << s.top()<<" ";
							s.pop();
						}
						s.push(g);
					}
					else
						{
							while (s.empty()==false&&s.top() != '(' && s.top() != ')')
							{
								out << s.top()<<" ";
								s.pop();
							}
						s.push(g);
						}
		}
		else
			if (t[0] == '(')
			{
				s.push(t[0]);
			}
			else
				if (t[0] == ')')
				{
					while (s.top() != '(')
					{
						out << s.top()<<" ";
						s.pop();
					}
					s.pop();
				}
				else
					if (t[0] == '*'||t[0] == '/')
					{
						while (s.empty()==false&&(s.top() == '*' || s.top() == '/'))
						{
							out << s.top()<<" ";
							s.pop();
						}
						s.push(t[0]);
					}
					else
					{
						while (s.empty() != 0 || s.top() != '(' || s.top() != ')')
						{
							out << s.top()<<" ";
							s.pop();
						}
						s.push(t[0]);
					}
		/*else
			if(t[0]==')'||t[0]=='(')
			{
				t[0]='\0';
			}
			else
			{
				g=t[0];
				s.push(g);
			}*/
	}
	out.clear();
	out.seekp(0,out.beg);
	while(!out1.eof())
	{
		out1>>t;
		if(!isalnum(t[0]))
		{
			if(t[0]=='+')
			{
				p=l.top();
				l.pop();
				p=l.top()+p;
				l.pop();
				l.push(p);
			}
			if(t[0]=='-')
			{
				p=l.top();
				l.pop();
				p=l.top()-p;
				l.pop();
				l.push(p);
			}
			if(t[0]=='*')
			{
				p=l.top();
				l.pop();
				p=l.top()*p;
				l.pop();
				l.push(p);
			}
			if(t[0]=='/')
			{
				p=l.top();
				l.pop();
				p=l.top()/p;
				l.pop();
				l.push(p);
			}
		}
		else
		{
			i=0;
			while(t[i]!=','&&t[i+1]!='\0')
			{
				if(t[i+1]=='.')		
				{
					t[i+1]=',';
					i++;
				}
				else
					i++;
			}
			l.push(strtod(t,'\0'));
		}
	}
	out1.clear();
	out.seekp(0,out.end);
	out<<endl<<"Результат вычисления выражения равен:  "<<l.top()<<endl;
	in.close();
	out.close();
	out1.close();
}

	/*s.push("(");
	s.push("5");
	s.push("+");
	s.push("45");
	s.push(")");
	s.push("*");
	s.push("(");
	s.push("55");
	s.push("-");
	s.push("5");
	s.push(")");
	s.push(")");*/
	/*while(!s.empty())
	{
		if(prrr(s,l)==1)
		{
			s.swap(m);
		}
		else
		{
			s.pop();
		}
	}
}
int prrr(stack <char[15]> s,stack <double> l)
{
	int i,n=0;
	for(i=0;i<10;i++)
		l.push(i);
	for(i=0;i<10;i++)
		if(((atof(s.top())%10)-1)==l.top()&&s.top()!="0")
		{
			n=1;
		}
		else
		{
			l.pop();
		}
		return n;
}
/*	f.push(1);
	f.push(2);
	f.push(3);
	f.push(5);
	f.push(7);
	f.push(11);
	f.push(13);
	f.push(17);
	f.push(29);
	d.push(121);
	d.push(232);
	d.push(323);
	d.push(431);
	d.push(55);
	d.push(171);
	d.push(131);
	d.push(171);
	d.push(292);*/
