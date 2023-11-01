procedure sort_shell(var a:tp;n:byte);
  var i,j,k,h,p:integer;
      r     :real;
begin
  r:=ln(n)/ln(2);
  h:=round(exp(r*ln(2)));
  if h>=n then  h:=round(exp((r-1)*ln(2)));
  h:=h div 2;
  while h>=1 do      {Для выбора шага группы}
   begin
    for k:=1 to h do {Для просмотра всех групп}
      begin
         i:=k+h;
           {Сортировка методом встaвок элементов группы}
           while i<=n do
             begin
              p:=a[i];
              j:=i-h;
                while (j>=k ) and (p<a[j]) do
                  {Находим место для вставки очередного элемента}
                 begin
                   a[j+h]:=a[j];
                   dec(j,h);
 { j }         end;
                 a[j+h]:=p;
              inc(i,h);
 { i }     end;
 { k }   end;
         h:=h div 2;
               for i:=1 to n do       { Промежуточные}
               write (a[i]:3);        { массивы }
               writeln
 { h } end;
               writeln ('Полученный массив ');
               for i:=1 to n do
               write (a[i]:3);
    writeln
end;

