program sort;       (���. 198)
{��⮤ ����ன ���஢�� ���ᨢ�
ࠧ࡮⠭ � 1962 ���� �����஬ �����᪮�� 㭨������ �. ���஬
���ᨢ ������� �� ����㥬� ����ᥪ������� ���� ����� ���
 �� �⠭�� ࠢ��� 1.�� ��� 㯮�冷稢����� �� �⤥�쭮��}
 uses crt;
  type tm=array[1..20] of integer;
  const k : word =1;
   var       a  : tm;
       i,t,l    : longint;
   procedure Qsort(var a:tm;l,r:word);
    var b,p,i,j: integer;
    begin
      b:= a[(l+r) div 2]; i:=l; j:=r;
      while i<=j do
        begin
        while a[i] < b do  inc(i);
        while a[j] > b do  dec(j);
             if i<=j then
                 begin
                   p:=a[i];
                   a[i]:=a[j];
                   a[j]:=p;
                   inc(i);dec(j);
                  end;
         end;
         if l<j then Qsort(a,l,j);
         if i<r then Qsort(a,i,r);
      end;
begin
  clrscr;
  writeln('��室�� ���ᨢ : ');
  randomize;
  for i:=1 to 15 do
    begin
     a[i]:=(random(256));
     write(a[i]:4);
    end;
  Qsort(a,1,15);
  writeln;
  writeln('����祭� ���ᨢ : ');
    for i:=1 to 15 do write(a[i]:4);
  readln;
 end.