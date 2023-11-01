program matr1_dynamig;

uses
  Forms;

{$R *.RES}

 var  m,n,j,i,s :longint;
   Ma:array  of array of integer;
 begin

    writeln ('vvod n');
    read(n);
     writeln ('vvod m');
    read(m);
          SetLength(Ma,n,m);
           for i:=0 to n-1 do
                 for j:=0 to m-1 do
               read(Ma[i,j]);

           s:=0;
           for i:=0 to n-1 do
                 for j:=0 to m-1 do
                  if Ma[i,j] mod 2<>0 then s:=s+Ma[i,j];

            writeln('Matriza');
           for i:=0 to n-1 do
              begin
                 for j:=0 to m-1 do
               write(Ma[i,j]:4);
               writeln;
              end;
             write('summa =',s);
               readln
 end.

