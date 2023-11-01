unit Rec_procs;

interface

function  Shift(Num: Int64): Int64;
{ ������� ������������ ����������� �����
  ����� Num �� ���� ������ ������. }

function  GetPower(X: Int64; n: Word): Int64;
{ ���������� ������ ����� X � �����������
  ������� n.  }

function  GetFact(n:  Word): Int64;
{ ���������� n! }

function  GetNOD(X, Y:  Int64): Int64;
{ ���������� ���(X, Y) }

function GetComb(n, m:  Word):  Int64;
{ ���������� ���������� ��������� �� n �� m. }

function  GetFibNum(n:  Word):  Int64;
{ ���������� n-�� ����� ������������������ ��������.  }

function  GetSum(Num: Int64): Word;
{ ���������� ����� ���� ����� Num.  }

function  GetCount(Num: Int64): Word;
{ ���������� ���������� ���� ����� Num.  }

function  TurnNum(Num: Int64): Word;
{ ���������� �����-����������� ����� Num.  }

function  PasteDig(Num: Int64; Dig: Byte; i: Integer): Int64;
{ ������� i-� ����� ������ � �����.  }

function  DeleteDig(Num: Int64; i: Integer): Int64;
{ �������� i-� ����� ������ �� �����.  }

function  DeleteDigs(Num: Int64; Dig: Byte): Int64;
{ �������� ���� ���� Dig �� �����.  }

procedure MoveDisks (n: Byte; x, y, z:  Char);
{ ��������� �����.  }

procedure Sort(A: array of Integer);
{ ���������� �����. }

function  FindMax(A:  array of Integer):  Integer;
{ ����� max �������� � �������. }

function  IsPalindrome(A:  array of Integer):  Boolean;
{ �������� �� ��������������. }

procedure ShiftArrayRight(var A: array of Integer; Index, Count: Integer);
{ ����� ������� �� Count ��������� ������, ������� � A[Index]. }

procedure ShiftArrayLeft(var A: array of Integer; Index, Count: Integer);
{ ����� ������� �� Count ��������� �����, ������� � A[Index]. }

function  BinSearch(A: array of Integer; Val, LI, RI: Integer): Integer;
{ �������� �����, ��� LI <= Index <= RI (Result = -1, ���� ������� �� ������). } 

function  BinPasteSearch(A: array of Integer; Val, LI, RI: Integer): Integer;
{ �������� ����� ����� ������� �������� Val � ��������������� �������,
  ��� LI <= Index <= RI.  }

function  TurnWord(S: string): string;
{ ��������� �����.  }

implementation

function MakeShift(Num: Int64; Dig: Byte): Int64;
{ ����������� ����� ����� Num*10 + Dig
  �� ���� ������ ������ (����������� �������).  }
begin   
  if Num = 0 then
    Result:= Dig
  else
    Result:= Num mod 10 + 10*MakeShift(Num div 10, Dig)
end;

function  Shift(Num: Int64): Int64;
begin
  Result:= MakeShift(Num div 10, Num mod 10)
end;

function  GetPower(X: Int64; n: Word): Int64;
begin
  if  n = 0 then
    Result:= 1
  else
    Result:= X*GetPower(X, n - 1)
end;

function  GetFact(n:  Word): Int64;
begin
  if  n = 0 then
    Result:= 1
  else
    Result:= n*GetFact(n - 1)
end;  

function  GetNOD(X, Y:  Int64): Int64;
begin
  if X = Y then
    Result:= X
  else
    if  X > Y then
      Result:= GetNOD(X - Y, Y)
    else
      Result:= GetNOD(X, Y - X)
end;

function GetComb(n, m:  Word):  Int64;
begin
  if m = 1 then
    Result:= n
  else
    Result:= GetComb(n, m - 1)*(n - m + 1) div m
end;

function  GetFibNum(n:  Word):  Int64;
begin
  if (n = 1) or (n = 2) then
    Result:= 1
  else
    Result:= GetFibNum(n - 1) + GetFibNum(n - 2)
end;

function  GetSum(Num: Int64): Word;
begin
  if Num = 0 then
    Result:= 0
  else
    Result:= Num mod 10 + GetSum(Num div 10)
end;

function  GetCount(Num: Int64): Word;
begin
  if  Num = 0 then
    Result:= 0
  else
    Result:= 1 + GetCount(Num div 10)
end;

function  TurnNum(Num: Int64): Word;
begin
  if  Num = 0 then
    Result:= 0
  else
    Result:= GetPower(10, GetCount(Num div 10))*(Num mod 10) + TurnNum(Num div 10)
end;

function  PasteDig(Num: Int64; Dig: Byte; i: Integer): Int64;
begin
  if Num = 0 then
    Result:= 0
  else
    if i = 1 then
      Result:= Dig + 10*PasteDig(Num div 10, Dig, i - 1)
    else
      Result:= Num mod 10 + 10*PasteDig(Num div 10, Dig, i - 1)
end;

function  DeleteDig(Num: Int64; i: Integer): Int64;
begin
  if Num = 0 then
    Result:= 0
  else
    if i = 1 then
      Result:= DeleteDig(Num div 10, i - 1)
    else
      Result:= Num mod 10 + 10*DeleteDig(Num div 10, i - 1)
end;

function  DeleteDigs(Num: Int64; Dig: Byte): Int64;
begin
  if  Num = 0 then
    Result:= 0
  else
    if Num mod 10 = Dig then
      Result:= DeleteDigs(Num div 10, Dig)
    else
      Result:= Num mod 10 + 10*DeleteDigs(Num div 10, Dig)
end;

procedure MoveDisks (n: Byte; x, y, z:  Char);
{� - � y - �  z - C}
begin
  if n = 1 then
    Writeln('����  1 ' ,x,' -> ',y)
  else
    if n > 1 then
    begin
    {������������ n-1 ������� ������ � ��������� �������� ��
    ���������������, ��������� ������� ���� ��� �������������}
      MoveDisks(n - 1, x, z, y);
      Writeln('���� ',n:2, ' ',x,' -> ',y);
      MoveDisks(n - 1, z, y, x);
    {������������ ��� n-1  ������ ������������� ��  ���������������
    �������� �� ������� , ��������� �������� ���� ��� �������������}
    end
end;


end.
