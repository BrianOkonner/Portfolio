{ ���������� �����.
������������ ������ 3 ������ �9.
�������.���� ��� ������������������ A=(ai) ,  i=1..n, (n,<=10) � �=(bj), j=1..m,
(m<=10) ����� �����. ����� ������������ ����� ������������������, ����������
 ���������������������� �����  �������������������.  ���������� ��������
 ������� n*k.



�������:������� � ������� �������� ��� ���������������������, ���������� �� �
�������� ��������������������� ������������ �����.
�����
����������� �������� 10
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

Function LenghtPosl(xx,yy,leng:integer):integer;  {����������� �������
                                         xx-����� ������� � ������� �;
                                         yy-����� ������� � ������� B;
                                         leng-���������� ��� ��������� �����������
                                         ��������� }
Var
 i,j,jj,k,k1,k2:integer;
Begin
 k:=leng;
 jj:=yy;
 k1:=0;                                  {������������ ����� ���������������������}
 for i:=xx to n do
  begin
   j:=jj+1;                              {������� � ������� B}
   while j<=m do
    Begin
     if A[i]=B[j]                        {���������� ��������}
      then
       begin
        k2:=LenghtPosl(i+1,jj,k);        {������������ ��������}
        if k2>k1                         {���������� ����� ����������������������}
         then
          k1:=k2;
        k:=k+1;                          {������� K}
        jj:=j;
        Break;                           {����� �� �����}
       end;
     inc(j);
    End;
  End;
 if k>k1                                 {������� �������� ������������ �����
                                         ���������������������}
  then
   k1:=k;
 LenghtPosl:=k1;
End;

begin
  writeln('vvedite size');               {������ �������}
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
  lengthm:=LenghtPosl(1,0,0);            {�������� ����������� �������}
  writeln('dlina posl: ',lengthm);
  readln;
  readln;
end.
