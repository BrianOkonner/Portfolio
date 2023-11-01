{Динамическое заполнение матрицы по спирали
 с использованием возможностей модуля CRT}
{Используются процедуры для обхода матрицы по спирали}
program matriz_spiral;
 uses crt;
 type at=array [1..20,1..20] of integer;
 var  n,m,l,k,i,j : word;
     matr:at;
 procedure RICHT(var i,j,l,k:word);
   {Движение право}
  begin
    inc(i);
    inc(j);
      while j<=n-k do
        begin
         if matr[i,j]=0 then
            begin
                matr[i,j]:=l;
                textcolor(random(5)+1);
                gotoxy(j*4,i);
                write(l);
                delay(50);
                inc(j);
                inc(l);
               end;
            end;
     end;
  procedure  DOWN(var i,j,l,k:word);
       {Движение вниз}
    begin
      dec(j);
      inc(i);
      while i<=m-k do
        begin
          if matr[i,j]=0 then
             begin
               matr[i,j]:=l;
               textcolor(random(6)+2);
               gotoxy(j*4,i);
               write(l);
               delay(50);
               inc(i);
               inc(l);
             end;
        end;
     end;
  procedure LEFT(var i,j,l,k:word);
      {Движение влево}
   begin
     dec(i);
     dec(j);
       while j>k do
         begin
           if matr[i,j]=0 then
              begin
                matr[i,j]:=l;
                textcolor(random(10)+1);
                gotoxy(j*4,i);
                write(l);
                delay(50);
                dec(j);
                inc(l);
              end
          else dec(j);
       end;
    end;
  procedure DAUP(var i,j,l,k:word);
       {Движение вверх}
   begin
     inc(j);
     dec(i);
     inc(k);
       while i>k do
         begin
           if matr[i,j]=0 then
              begin
                matr[i,j]:=l;
                textcolor(random(16));
                gotoxy(j*4,i);
                write(l);
                delay(50);
                dec(i);
                inc(l);
              end
          else dec(i);
      end;
 end;
begin
    clrscr;
    fillchar(matr,m*n*2,0);
    repeat
      writeln ('введи m,n <20');
      readln(m,n);
    until (n<20) and (m<20);
    clrscr;
    i:=0;    j:=0;    l:=1;     k:=0;
     while l<=m*n do
       begin
            RICHT(i,j,l,k);
            DOWN(i,j,l,k);
            LEFT(i,j,l,k);
            DAUP(i,j,l,k);
               end;
    readln;
 end.

