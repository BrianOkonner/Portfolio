 program matr_sort;
 { Ввод, вывод и сквозная сортировка
 в двумерном массиве (матрице)}
  uses crt;
  type  Tmatr=array [1..30,1..30] of integer;
  var  n :byte;     {Глобальные переменные}
       A :Tmatr;    { их используют процедуры}
       j,i,xmax,ymax :byte;
procedure init_matr;
 begin
    writeln ('введи n');
    readln(n);
           {ввод матрицы}
           for i:=1 to n do
              for j:=1 to n do
               {read(A[i,j]);}
               a[i,j]:=random(20);
 end;
procedure print_matr;
begin
           for i:=1 to n do
              begin
               for j:=1 to n do
               write(A[i,j]:4);
               writeln;
              end;
end;
procedure reverse( var a,b:integer);
 begin
   if a<>b then
    begin
     a:=a xor b;
     b:=a xor b;
     a:=a xor b;
    end;
  end;
procedure max_matr(x,y:byte;var xmax,ymax:byte);
 var i,j:byte;
 begin
           xmax:=x;
           ymax:=y;
            for j:=y+1 to n do
                  if A[x,j] > A[xmax,ymax]  then
                    begin
                      ymax:=j;
                    end;

           for i:=x+1 to n do
                 for j:=1 to n do
                  if A[i,j] > A[xmax,ymax]  then
                    begin
                      xmax:=i;
                      ymax:=j;
                    end;
end;
       begin
            Init_matr;
               writeln('Исходная мaтрица');
               Print_matr;
               for i:=1 to n do
                 for j:=1 to n do
                 begin
                  max_matr(i,j,xmax,ymax);
                  reverse(a[i,j],a[xmax,ymax]);
                 end;
            writeln('Упорядоченная мaтрица');
            Print_matr;
            end.
