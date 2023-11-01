{Получение магического квадрата нечетного порядка
Магический квадрат - зто матрица, у которой сумма элементов
каждого столбца равна сумме элементов каждой строки}
 program magic;
  uses crt;
  type at=array [1..19,1..19] of integer;
  var  n,k,l,j,i,s :longint;
   a:at;
 begin
    clrscr;
    repeat
    writeln ('введи n');
    readln(n);
    until n mod 2<>0;
    {Заполняем матрицу нулями}
    fillchar(a,2*n*n,0);
    {Определяем координаты первой заполняемой клетки}
    i:=n div 2;j:=(n+1) div 2;
      l:=1;
      while l<=n*n do
          begin
           if j = n+1 then {вышли справа}
                j:=1;
              if (i=0) and (j=0) then
              {Если вышли в левый верхний угол}
                    begin
                       i:=n; j:=n;
                    end;
                  if (j<=n) and (j>0) then
                      if (i<=n) and (i>0)  then
                     {Если клетка существует и не занята}
                     if a[i,j]=0 then
                                   begin
                                      a[i,j]:=l;
                                      dec(i);
                                      dec(j);
                                      inc(l);
                                   end
                                else
              {Если клетка существует,но занята}
                                  begin
                                      inc(j);
                                      dec(i);
                                  end
                      else
             {Если вышли сверху}
                       i:=n
                  else
              {Если вышли слева}
                  j:=n
          end;
   for i:=1 to n do
       begin
           for j:=1 to n do
               write(a[i,j]:4);
               writeln;
           end;
   readln;
 end.