program Tr_pas_dynamig;
  uses
  Forms;
 {$R *.RES}
   var  n,j,i,s :longint;
   Ma:array  of array of integer;
 begin
  writeln ('vvod n');
  read(n);
   SetLength(Ma,n);
     for i:=0 to n-1 do
        SetLength(Ma[i],i+1);
     for i:=0 to n-1 do
      begin
        Ma[i,i]:=1;
        Ma[i,0]:=1;
        for j:=1 to i-1 do
         Ma[i,j]:=Ma[i-1,j-1]+Ma[i-1,j];
       end;
     writeln('Matriza');
     for i:=0 to n-1 do
        begin
        for j:=0 to i do
          write(Ma[i,j]:4);
        writeln;
        end;
  readln
end.

