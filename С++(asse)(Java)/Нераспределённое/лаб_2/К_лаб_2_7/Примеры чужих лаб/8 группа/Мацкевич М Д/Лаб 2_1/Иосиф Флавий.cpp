/*Мацкевич Максим ПМ 8
3.1 Задача Иосифа
Решение
1)создадим  список с элементами 1,2,3 .. n.
2)Сделаем двойной цикл 
Внешний цикл будет работать пока не удалим n-1 элементов.
3) Во внутреннем цикле будем двигаться по эелементам списка 
и перезаписывать их в другой конец списка до тех пор, 
пока  следущий элемент не нуждается в удалении.
удалим этот элемент из списка и вернёмся во внешний цикл.
Ввод с консоли , вывод в файл.
Примечание:если m=1 то сразу выведем очевидный ответ - n
Тесты
5 3                 4
100 1               100
3 3                 2
265 23              119
1000 100            876
*/

#include <iostream>
#include <fstream>
#include <list>
using namespace std;
int main()
{ofstream out; out.open("output.txt");
	int i,n,m,j,k;
cin>>n>>m;
if (m==1) 
{out<<n; system("pause"); return 0;}


list <int> s;
for (i=1; i<=n; i++)
s.push_front(i);

for ( i=1; i<n; i++)
{ 
 for ( j=1; j<m; j++)
    { 
	k=s.back();
    s.pop_back();
	s.push_front(k); 
    }
s.pop_back();
}

   
 out<<s.front();
out.close();
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






