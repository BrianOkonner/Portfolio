/*													Lab2_1 Queue
	Программу написал Владислав Владимирович Перевязчиков.( Специальность: прикладная матнмематика. Группа 8)
	Условие :2.	 Использование (динамической) очереди.
2.1	Задан текстовый файл Input.txt, в котором есть некоторые числа, каждое число в отдельной строке. Создать  две очереди, 
в первой – простые числа, во второй _ палиндромы. Построить новую очередь, включив в нее по одному  разу элементы, которые входят 
хотя бы в одну из очередей Queue1 или Queue2. Результат записать в текстовый  файл. 
	Алгоритм :Проходимся по файлу и создаем очереди палиндромов и простых проверкой.Копируем в 3-ю очередь ожну из них. Дополняем 3-ю 
с помощью проверки на повторяемость.
	Тесты:
 Input.txt :
5
3
623
43645
35
12321
4654
76
67
8
1
11
131
141
152
64
245
66523
2
 файл Stack№1.txt:
	Очередь с простыми числами:
5 3 67 1 11 131 66523 
	Очередь с числами-палиндромами:
5 3 12321 8 1 11 131 141 
	3-я очередь с числами простыми и палиндромами:
131 66523 2 5 12321 8 3 67 1 */
#include <iostream>
#include <fstream>
#include <queue>
#include "fun_h.h"
using namespace std;
void main()
{
	ifstream inq("Input.txt");
	ofstream outq("Queue.txt");
	queue <int> pr,pal;
	setlocale(LC_ALL,".1251");
	int buf,i,m;
	while(inq>>buf&&!inq.eof())
	{
		if(Prime(buf))
			pr.push(buf);
		if(palindrom(buf))
			pal.push(buf);
	}
	queue <int> res(pr);
	i=pr.back();
	outq<<"	Очередь с простыми числами:"<<endl;
	while(i!=pr.front())
	{
		outq<<pr.front()<<" ";
		m=pr.front();
		pr.pop();
		pr.push(m);
	}
	outq<<pr.front()<<" ";
	outq<<endl;
	outq<<"	Очередь с числами-палиндромами:"<<endl;
	i=pal.back();
	while(i!=pal.front())
	{
		outq<<pal.front()<<" ";
		m=pal.front();
		pal.pop();
		pal.push(m);
	}
	outq<<pal.front()<<" ";
	outq<<endl;
	i=pal.back();//Если надо сохранить очередь добавить копию напр:queue <int> res(pr);
	while(i!=pal.front())
	{
		for(buf=res.size();buf!=0;buf--)
		{
			if(res.front()==pal.front())
			{
				m=pal.front();
				pal.pop();
				pal.push(m);
				m=-1;
				break;
			}
			else
			{
				m=res.front();
				res.pop();
				res.push(m);
			}
		}
		if(m!=-1)
			res.push(pal.front());
		m=pal.front();
		pal.pop();
		pal.push(m);
	}
	outq<<"	3-я очередь с числами простыми и палиндромами:"<<endl;
	i=res.back();
	while(i!=res.front())
	{
		outq<<res.front()<<" ";
		m=res.front();
		res.pop();
		res.push(m);
	}
}

