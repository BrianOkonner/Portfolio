unit U_array;
interface
const
   CountArray = 100;
type
   TmyItems      = Longint;
   TmySizeArray  = Integer;
   TMyarray      = array [1..CountArray] of TmyItems;



procedure Change_Array ( var a: TMyarray; n: TmySizeArray);
  {Поменять порядок элементов на обратный}
procedure Max_Items(Const A: TMyarray;  n: TmySizeArray;
                    var   MaxItem:TmyItems; var num:TmySizeArray);
  {Поиск любого наибольшего и его номера}
procedure Min_Items(Const A: TMyarray;  n: TmySizeArray;
                    var   MinItem:TmyItems; var num:TmySizeArray);
   {Поиск любого наименьшего и его номера}
procedure MinALL(Const A: TMyarray;  n: TmySizeArray;
                 var B:TMyarray;  var Count:TmySizeArray);
   {Поиск номеров всех наименьших}
procedure InsertItem(Const A: TMyarray; n: TmySizeArray;
                   Item:TMyItems; K:TmySizeArray;
                   var B:TMyarray;  var Count:TmySizeArray);
   {А - входной массив; N -количество элементов в А}
   { вствавка в массив элемента Item  после   }
   { элемента с заданным номером   K      }
   {B - выходной массив; Count -количество элементов B}
Function Poisk_Item(const a:TmyArray; Ch:TmyItems;N:TmySizeArray):TmyItems;
   {Функция нахождения в массиве элемента равного Ch
    возвращает номер найденного элемента или -1,
    если элемент не найден}
Procedure Del_Item(var a:TmyArray; K:TmySizeArray;var N:TmySizeArray);
   {Процедура удаления из массива  элементa с заданным номером}
Procedure del_All(var a:TmyArray; Ch:TmyItems;var N:TmySizeArray);
   {Процедура удаления из массива всех элементов равных Ch}
procedure Muiti(const a,b:TmyArray;m,n:TmySizeArray;
                var C:TmyArray;var k:TmySizeArray);
    {Процедура умножения длинных чисел}
procedure Add_All(const a,b:TmyArray;m,n:TmySizeArray;
                var C:TmyArray;var k:TmySizeArray);
     {Процедура сложения длинных чисел}
implementation
procedure Change_Array ( var a: TMyarray; n: TmySizeArray);
{Поменять порядок элементов на обратный}
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
{Поиск любого наибольшего и его номера}
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
{Поиск любого наименьшего и его номера}
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
{Поиск номеров всех наименьших}
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
{А - входной массив; N -количество элементов в А}
{ вствавка в массив элемента Item  после   }
{ элемента с заданным номером   K      }
{B - выходной массив; Count -количество элементов B}
  var   i:integer;
 begin

    for i:=1 to k-1 do
        b[i]:=a[i];
        b[i+1]:=Item;
    for i:=k to n do
        b[i+1]:=a[i];
{Можно не вводить новый массив}
{      for i:=n downto k do
        a[n+1]:=a[i];
        a[i+1]:=Item;}
 count:=n+1;
 end;
Function Poisk_Item(const a:TmyArray; Ch:TmyItems;N:TmySizeArray):TmyItems;
   var i:TmySizeArray;
   {Функция нахождения в массиве элемента равного Ch
    возвращает номер найденного элемента или -1,
    если элемент не найден}
    begin
        i:=1;
        while (i<=n) and (ch<>a[i]) do
           inc (i);
        if i=n+1  then Poisk_Item:=-1
        else Poisk_item:=i;
    end;
 Procedure Del_Item(var a:TmyArray; K:TmySizeArray;var N:TmySizeArray);
   {Процедура удаления из массива  элементa с заданным номером}
    var i :TmySizeArray;
    begin
            for i:=k to n-1 do
             a[i]:=a[i+1];
            dec(n);
    end;
 Procedure del_All(var a:TmyArray; Ch:TmyItems;var N:TmySizeArray);
   var g,i :TmySizeArray;
   {Процедура удаления из массива всех элементов равных Ch}
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