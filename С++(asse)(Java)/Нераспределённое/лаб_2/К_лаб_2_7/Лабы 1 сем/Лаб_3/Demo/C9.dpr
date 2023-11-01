{ Пельменева Елена.
Лабораторная работа 3 Задача С9.
Условие.Даны две последовательности A=(ai) ,  i=1..n, (n,<=10) и В=(bj), j=1..m,
(m<=10) целых чисел. Найти максимальную длину последовательности, являющейся
 подпоследовательностью обеих  последовательностей.  Количество операций
 порядка n*k.



Решение:находим с помощью рекурсии все подпоследовательности, сравниваем их и
выбираем подпоследовательность максимальной длины.
Тесты
Размерность массивов 10
 1.
Massiv A
    4    1    2    4    1    3    1    0    4    3
Massiv B
    2    0    4    3    2    2    0    0    4    4
dlina posl: 5


 2.
Massiv A
    4    4    4    4    4    2    3    4    2    3
Massiv B
    0    3    2    0    3    4    2    4    1    1
dlina posl: 4


 3.
Massiv A
    3    4    1    0    0    3    4    1    2    2
Massiv B
    1    2    4    3    3    4    1    4    4    2
dlina posl: 5

 4.
Massiv A
    0    4    4    1    2    2    2    1    1    0
Massiv B
    2    4    4    1    3    2    2    0    1    2
dlina posl: 6

 5.
Massiv A
    4    0    0    4    4    0    4    3    3    0
Massiv B
    3    3    3    3    4    0    2    2    4    2
dlina posl: 3}

program C9;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
tarray=array [1..10] of integer;
var
A,B:tarray;
j,i,n,m,lengthm:integer;

Function LenghtPosl(xx,yy,leng:integer):integer;  {рекурсивная функция
                                         xx-номер позиции в массиве А;
                                         yy-номер позиции в массиве B;
                                         leng-количество уже найденных совпадающих
                                         элементов }
Var
 i,j,jj,k,k1,k2:integer;
Begin
 k:=leng;
 jj:=yy;
 k1:=0;                                  {максимальная длина подпоследовательности}
 for i:=xx to n do
  begin
   j:=jj+1;                              {позиция в массиве B}
   while j<=m do
    Begin
     if A[i]=B[j]                        {сравниваем элементы}
      then
       begin
        k2:=LenghtPosl(i+1,jj,k);        {осуществляем рекурсию}
        if k2>k1                         {сравниваем длины подпоследовательностей}
         then
          k1:=k2;
        k:=k+1;                          {счетчик K}
        jj:=j;
        Break;                           {выход из цикла}
       end;
     inc(j);
    End;
  End;
 if k>k1                                 {находим конечную максимальную длину
                                         подпоследовательности}
  then
   k1:=k;
 LenghtPosl:=k1;
End;

begin
  writeln('vvedite size');               {вводим массивы}
  read(n,m);
  randomize;
  Writeln('Massiv A');
  for i:=1 to n do
   Begin
    A[i]:=random(5);
    Write(a[i]:5);
   end;
  Writeln;
  Writeln('Massiv B');
  for j:=1 to m do
   Begin
    B[j]:=random(5);
    Write(b[j]:5);
   end;
  Writeln;
  lengthm:=LenghtPosl(1,0,0);            {вызываем рекурсивную функцию}
  writeln('dlina posl: ',lengthm);
  readln;
  readln;
end.
