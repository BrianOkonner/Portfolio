
/*
Мацкевич Максим ПМ 8
Задача 1.2	Описать процедуру,
которая подсчитывает количество элементов стека, у которых равные "соседи".
Решение
1)Запишем числа из файла в стек.
2)Далее пройдем по стеку ,причём будем запоминать в переменных а1,а2
значение 2-х предыдущих элементов стека.
3)Будем сравнивать в цикле  значение текущего элемента стека с
предпредыдущим  (n с n-2) ,а при совпадении увеличивать  число соседей на 1
Ввод через файл. Вывод на консоль.
Тесты
Ввод              Вывод
1513                3
531
15
13513
21
13513
21
21
21
Вывод

*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;
int main()
{
	stack <int> s;
	int a, a1, a2,i=1,k=0;
	setlocale(LC_ALL, "rus");
	ifstream in; in.open("input.txt");

	while (!in.eof())
	{
		in >> a;
		s.push(a);
	}

	a1 = s.top();
	s.pop();
	a2 = s.top();
	s.pop();

	while (!s.empty())
	{
		if (i % 2)
		{
			if (s.top() == a1) k++;
			a1 = s.top();
		}
		else
		{
		       if (s.top() == a2) k++;
				a2= s.top();
		}
	 s.pop();
	 i++;
	}



	cout << k << '\n';
	system("pause");
	return 0;
}































/*
void vstavka_spisok_end( spisok *&end,int a)
{
end->next=new spisok;
end=end->next;
end->x=a;
end->next=NULL;
}


void delete_spisok(spisok *&move)
{spisok *tmp=move->next;
delete move->next;
}

void vstavka_spicok_begin( spisok *&begin, int a)
{ spisok *tmp= new spisok;
tmp=begin;
begin->next=tmp;
begin->x=a;
}

void cout_spisok( spisok *begin)
{
while (begin)
   {
	   cout<<begin->x;
    begin=begin->next;
   }
}
void find_spisok_el(int a,spisok *begin, spisok  *&f)
{
while(begin->x!=a && begin->next)
   begin=begin->next;
if (begin->x==a) f=begin ;
else f=0;
} 
void vstavka_spisok(spisok *&move,int a)
{spisok *tmp= new spisok;
tmp=move->next;
move=tmp;
tmp->x=a;
}


*/






