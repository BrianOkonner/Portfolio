{����祭�� �����᪮�� ������ ���⭮�� ���浪�
�����᪨� ������ - �� �����, � ���ன �㬬� ������⮢
������� �⮫�� ࠢ�� �㬬� ������⮢ ������ ��ப�}
 program magic;
  uses crt;
  type at=array [1..19,1..19] of integer;
  var  n,k,l,j,i,s :longint;
   a:at;
 begin
    clrscr;
    repeat
    writeln ('����� n');
    readln(n);
    until n mod 2<>0;
    {������塞 ������ ��ﬨ}
    fillchar(a,2*n*n,0);
    {��।��塞 ���न���� ��ࢮ� ������塞�� ���⪨}
    i:=n div 2;j:=(n+1) div 2;
      l:=1;
      while l<=n*n do
          begin
           if j = n+1 then {��諨 �ࠢ�}
                j:=1;
              if (i=0) and (j=0) then
              {�᫨ ��諨 � ���� ���孨� 㣮�}
                    begin
                       i:=n; j:=n;
                    end;
                  if (j<=n) and (j>0) then
                      if (i<=n) and (i>0)  then
                     {�᫨ ���⪠ ������� � �� �����}
                     if a[i,j]=0 then
                                   begin
                                      a[i,j]:=l;
                                      dec(i);
                                      dec(j);
                                      inc(l);
                                   end
                                else
              {�᫨ ���⪠ �������,�� �����}
                                  begin
                                      inc(j);
                                      dec(i);
                                  end
                      else
             {�᫨ ��諨 ᢥ���}
                       i:=n
                  else
              {�᫨ ��諨 ᫥��}
                  j:=n
          end;
   for i:=1 to n do
       begin
           for j:=1 to n do
               write(a[i,j]:4);
               writeln;
           end;
   readln;
 end.