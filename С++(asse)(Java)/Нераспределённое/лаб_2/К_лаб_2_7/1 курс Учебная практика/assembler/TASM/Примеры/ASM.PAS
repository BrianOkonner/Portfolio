program asd;
uses crt;
type c=array[1..10] of integer;
var a,b,s,n,i:integer;
    mas:c;
procedure aaa(var mas:c);
begin
asm
  les bx,mas
  mov cx,[bx]
  add cx,1
  mov [bx],cx
  mov cx,[bx+2]
  add cx,1
  mov [bx+2],cx
end;
end;

begin
clrscr;

for i:=1 to 2 do
read(mas[i]);
aaa(mas);
writeln(mas[1]);
writeln(mas[2]);
end.