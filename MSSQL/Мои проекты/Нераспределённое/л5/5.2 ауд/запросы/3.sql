use	TestDatabas
select
fio, [������� ��� �����]
from 
Table_uch1 
unpivot
( [������� ��� �����] 
for �������� in (ush, predmet) ) 
unpvt
