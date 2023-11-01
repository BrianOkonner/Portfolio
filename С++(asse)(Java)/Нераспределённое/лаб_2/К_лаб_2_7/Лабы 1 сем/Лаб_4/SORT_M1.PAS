{Сквозная сортировка матрицы 10*10}
program matriz_spiral;
 uses crt;
 type tmatr=array [1..10,1..10] of integer;
      tarray=array [1..100] of integer;
 var  n,m,l,k,i,j : word;
               st : string;
                z : set of char;
     matr:tmatr;
     myarray: tarray absolute matr;
procedure init_matr;
 {Заполнение матрицы случайными числами}
 begin
    repeat
      writeln ('введи m,n =10');
      readln(m,n);
    until (n=10) and (m=10);

     for i:=1 to m do
       begin
           for j:=1 to n do
                matr[i,j]:=random(20);
           end;

 end;
procedure sort(var a:tarray;n:byte);
{ Сортировка массива методом "пузырька"}
var i,j,d:integer;
    t:boolean;
Begin
  i:=1;
  repeat
    t:=true;
    for j:=1 to n-i do
     begin
      if a[j]>a[j+1] then
       begin
        d:=a[j+1];
        a[j+1]:=a[j];
        a[j]:=d;
        t:=false;
       end;
     end;
    i:=i+1;
  until(i>n)or t;
End;
procedure print_matr;
  {Вывод элементов матрицы}
  begin
         for i:=1 to m do 
          begin
           for j:=1 to n do
               write(matr[i,j]:4);
               writeln;
           end;
 end;

BEGIN
  { Основная программа  }
    init_matr;
    print_matr;

    writeln('press on Enter');
    readln;
    sort(myarray,m*n);

    writeln('Result ');
    print_matr;

    writeln('press on Enter');
    readln;
 end.

