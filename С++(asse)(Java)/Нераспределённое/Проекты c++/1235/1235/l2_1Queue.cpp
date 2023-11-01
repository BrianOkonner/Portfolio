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
5+
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
#include "MineQueue.h"
#include "fun_h.h"
using namespace std;
void main()
{
	ifstream inq("Input.txt");
	ofstream outq("Queue.txt");
	Mqueue pr,pal;
//	queue <int> pr,pal;
	setlocale(LC_ALL,".1251");
	int buf,i=0;
	while(inq>>buf&&!inq.eof())		i+=2;
	int *j=new int (i);
	inq.clear();
	inq.seekg(inq.beg);
	i=0;
	while(inq>>buf&&!inq.eof())
	{
		if(Prime(buf))
		{
			j[i]=buf;
			pr.push(&j[i]);
			i++;
		}
		if(palindrom(buf))
		{
			j[i]=buf;
			pal.push(&j[i]);
			i++;
		}
	}
//	queue <int> res(pr);
	i=*(int*)pr.back();
	outq<<"	Очередь с простыми числами:"<<endl;
	while(i!=*(int*)pr.front())
	{
		outq<<*(int*)pr.front()<<" ";
		int *m=new int;
		*m=*(int*)pr.front();
		pr.pop();
		pr.push(m);
	}
	outq<<*(int*)pr.front()<<" ";
	outq<<endl;
	outq<<"	Очередь с числами-палиндромами:"<<endl;
	i=*(int*)pal.back();
	while(i!=*(int*)pal.front())
	{
		outq<<*(int*)pal.front()<<" ";
		int *m=new int;
		*m=*(int*)pal.front();
		pal.pop();
		pal.push(m);
	}
	outq<<*(int*)pal.front()<<" ";
	outq<<endl;
	i=*(int*)pal.back();//Если надо сохранить очередь добавить копию напр:queue <int> res(pr);
	Mqueue res(pr);
	while(i!=*(int*)pal.front())
	{
		int bf=0;
		for(buf=res.size();buf!=0;buf--)
		{
			if((*(int*)res.front())!=(*(int*)pal.front()))
			{
				int *m=new int;
				*m=*(int*)res.front();
				res.pop();
				res.push(m);
			}
			else
			{
				int *m=new int;
				*m=*(int*)pal.front();
				pal.pop();
				pal.push(m);
				bf=-1;
				break;
			}
		}
		if(bf!=-1)
			res.push(pal.front());
		int *m=new int;
		*m=*(int*)pal.front();
		pal.pop();
		pal.push(m);
	}
	outq<<"	3-я очередь с числами простыми и палиндромами:"<<endl;
	i=*(int*)res.back();
	while(i!=*(int*)res.front())
	{
		int *m=new int;
		outq<<*(int*)res.front()<<" ";
		*m=*(int*)res.front();
		res.pop();
		res.push(m);
	}
}
//push  front pop back size
