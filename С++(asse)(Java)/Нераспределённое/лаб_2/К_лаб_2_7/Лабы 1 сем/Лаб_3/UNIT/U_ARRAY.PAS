unit U_array;
interface
const
   CountArray = 100;
type
   TmyItems      = Longint;
   TmySizeArray  = Integer;
   TMyarray      = array [1..CountArray] of TmyItems;



procedure Change_Array ( var a: TMyarray; n: TmySizeArray);
  {�������� ���冷� ������⮢ �� �����}
procedure Max_Items(Const A: TMyarray;  n: TmySizeArray;
                    var   MaxItem:TmyItems; var num:TmySizeArray);
  {���� ��� �������襣� � ��� �����}
procedure Min_Items(Const A: TMyarray;  n: TmySizeArray;
                    var   MinItem:TmyItems; var num:TmySizeArray);
   {���� ��� �������襣� � ��� �����}
procedure MinALL(Const A: TMyarray;  n: TmySizeArray;
                 var B:TMyarray;  var Count:TmySizeArray);
   {���� ����஢ ��� ���������}
procedure InsertItem(Const A: TMyarray; n: TmySizeArray;
                   Item:TMyItems; K:TmySizeArray;
                   var B:TMyarray;  var Count:TmySizeArray);
   {� - �室��� ���ᨢ; N -������⢮ ������⮢ � �}
   { ��⢠��� � ���ᨢ ������� Item  ��᫥   }
   { ������� � ������� ����஬   K      }
   {B - ��室��� ���ᨢ; Count -������⢮ ������⮢ B}
Function Poisk_Item(const a:TmyArray; Ch:TmyItems;N:TmySizeArray):TmyItems;
   {�㭪�� ��宦����� � ���ᨢ� ������� ࠢ���� Ch
    �����頥� ����� ���������� ������� ��� -1,
    �᫨ ������� �� ������}
Procedure Del_Item(var a:TmyArray; K:TmySizeArray;var N:TmySizeArray);
   {��楤�� 㤠����� �� ���ᨢ�  �������a � ������� ����஬}
Procedure del_All(var a:TmyArray; Ch:TmyItems;var N:TmySizeArray);
   {��楤�� 㤠����� �� ���ᨢ� ��� ������⮢ ࠢ��� Ch}
procedure Muiti(const a,b:TmyArray;m,n:TmySizeArray;
                var C:TmyArray;var k:TmySizeArray);
    {��楤�� 㬭������ ������� �ᥫ}
procedure Add_All(const a,b:TmyArray;m,n:TmySizeArray;
                var C:TmyArray;var k:TmySizeArray);
     {��楤�� ᫮����� ������� �ᥫ}
implementation
procedure Change_Array ( var a: TMyarray; n: TmySizeArray);
{�������� ���冷� ������⮢ �� �����}
var i: TmySizeArray;
    k: TmyItems ;
begin
 for i := 1 to (n div 2) do
  begin
      k:=a[i];
      a[i]:=a[n-i+1];
      a[n-i+1]:=k;
  end;
end;

procedure Max_Items(Const A: TMyarray;  n: TmySizeArray;
                   var   MaxItem:TmyItems; var num:TmySizeArray);
{���� ��� �������襣� � ��� �����}
var i:TmySizeArray;
 begin
  MaxItem:=a[low(A)];
  num:=1;
   for i := 2 to n  do
    if MaxItem < A[i] then
     begin
      MaxItem :=a[i];
      num:=i;
     end;
end;

procedure Min_Items(Const A: TMyarray;  n: TmySizeArray;
                   var   MinItem:TmyItems; var num:TmySizeArray);
{���� ��� �������襣� � ��� �����}
var i:TmySizeArray;
 begin
  MinItem:=a[low(A)];
  num:=1;
   for i := 2 to n  do
    if MinItem > A[i] then
     begin
      MinItem :=a[i];
      num:=i;
     end;
end;

procedure MinALL(Const A: TMyarray;  n: TmySizeArray;
                   var B:TMyarray;  var Count:TmySizeArray);
{���� ����஢ ��� ���������}
var i:TmySizeArray;
    min:TmyItems;
 begin
  Min_Items(a,n,min,i);
  Count := 0;
   for i := 1 to n  do
    if Min = A[i] then
     begin
      count    := count+1;
      B[count] := A[i];
     end;
end;

procedure InsertItem(Const A: TMyarray; n: TmySizeArray;
                   Item:TMyItems; K:TmySizeArray;
                   var B:TMyarray;  var Count:TmySizeArray);
{� - �室��� ���ᨢ; N -������⢮ ������⮢ � �}
{ ��⢠��� � ���ᨢ ������� Item  ��᫥   }
{ ������� � ������� ����஬   K      }
{B - ��室��� ���ᨢ; Count -������⢮ ������⮢ B}
  var   i:integer;
 begin

    for i:=1 to k-1 do
        b[i]:=a[i];
        b[i+1]:=Item;
    for i:=k to n do
        b[i+1]:=a[i];
{����� �� ������� ���� ���ᨢ}
{      for i:=n downto k do
        a[n+1]:=a[i];
        a[i+1]:=Item;}
 count:=n+1;
 end;
Function Poisk_Item(const a:TmyArray; Ch:TmyItems;N:TmySizeArray):TmyItems;
   var i:TmySizeArray;
   {�㭪�� ��宦����� � ���ᨢ� ������� ࠢ���� Ch
    �����頥� ����� ���������� ������� ��� -1,
    �᫨ ������� �� ������}
    begin
        i:=1;
        while (i<=n) and (ch<>a[i]) do
           inc (i);
        if i=n+1  then Poisk_Item:=-1
        else Poisk_item:=i;
    end;
 Procedure Del_Item(var a:TmyArray; K:TmySizeArray;var N:TmySizeArray);
   {��楤�� 㤠����� �� ���ᨢ�  �������a � ������� ����஬}
    var i :TmySizeArray;
    begin
            for i:=k to n-1 do
             a[i]:=a[i+1];
            dec(n);
    end;
 Procedure del_All(var a:TmyArray; Ch:TmyItems;var N:TmySizeArray);
   var g,i :TmySizeArray;
   {��楤�� 㤠����� �� ���ᨢ� ��� ������⮢ ࠢ��� Ch}
    begin
         i:=1;
        while i<=N do
         begin
          if Ch=A[i] then
           begin
            for g:=i to N-1 do  A[g]:=A[g+1];
            dec(N);
           end
         else
         inc(i);
         end;
    end;
procedure Multi(const a,b:TmyArray;m,n:TmySizeArray;
                var C:TmyArray;var k:TmySizeArray);
var
 x,y:TMyArray;
 per:TmyItems;
 i,j:TmySizeArray;
 begin
 Fillchar(X,N*sizeof(TmyItems),0);
 Fillchar(Y,M*sizeof(TmyItems),0);
 for i:=1 to m do
   x[m-i+1]:=a[i];
 for i:=1 to n do
   y[n-i+1]:=a[i];

 for i:=1 to m+n do c[i]:=0;
 for i:=1 to m do
   for j:=1 to n do
     c[i+j-1]:=c[i+j-1]+x[i]*y[j];
 for i:=1 to m+n-1 do
    begin
     c[i+1]:=c[i+1]+C[i] div 10;
     c[i]:=c[i] mod 10;
    end;
    i:=m+n;
    while c[i]=0 do i:=i-1;
    k:=i;
    for i:=1 to  k div 2 do
     begin
        per:=c[k-i+1];
        c[k-i+1]:=c[i];
        c[i]:=per;
     end
  end;



procedure Add_All(const a,b:TmyArray;m,n:TmySizeArray;
                var C:TmyArray;var k:TmySizeArray);
var
 x,y:TMyArray;
 per:TmyItems;
 i,j:TmySizeArray;
 begin
 Fillchar(X,N*sizeof(TmyItems),0);
 Fillchar(Y,M*sizeof(TmyItems),0);
 for i:=1 to m do
   x[m-i+1]:=a[i];
 for i:=1 to n do
   y[n-i+1]:=a[i];
 if m>n then k:=m else k:=n;
 k:=k+1;
 for i:=1 to k do c[i]:=0;
 for i:=1 to k do
   begin
     c[i]:=c[i]+x[i]*y[j];
     if c[i]>=10 then
      begin
       c[i+1]:=c[i+1]+1;
       c[i]:=c[i] mod 10;
      end;
    end;
    while c[k]=0 do k:=k-1;
    for i:=1 to  k div 2 do
     begin
        per:=c[k-i+1];
        c[k-i+1]:=c[i];
        c[i]:=per;
     end
  end;


begin
end.