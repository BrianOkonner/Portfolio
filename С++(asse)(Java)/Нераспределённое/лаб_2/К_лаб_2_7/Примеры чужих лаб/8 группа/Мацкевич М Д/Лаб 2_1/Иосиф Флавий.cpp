/*�������� ������ �� 8
3.1 ������ ������
�������
1)��������  ������ � ���������� 1,2,3 .. n.
2)������� ������� ���� 
������� ���� ����� �������� ���� �� ������ n-1 ���������.
3) �� ���������� ����� ����� ��������� �� ���������� ������ 
� �������������� �� � ������ ����� ������ �� ��� ���, 
����  �������� ������� �� ��������� � ��������.
������ ���� ������� �� ������ � ������� �� ������� ����.
���� � ������� , ����� � ����.
����������:���� m=1 �� ����� ������� ��������� ����� - n
�����
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






