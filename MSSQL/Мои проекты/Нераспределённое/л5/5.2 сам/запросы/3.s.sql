use	TestDatabas
select
predmet, [������� ��� �����]
from 
Table_uch1 
unpivot
( [������� ��� �����] 
for �������� in (ush, fio) ) 
unpvt