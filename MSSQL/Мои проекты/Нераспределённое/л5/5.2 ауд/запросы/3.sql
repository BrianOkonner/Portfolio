use	TestDatabas
select
fio, [Предмет или школа]
from 
Table_uch1 
unpivot
( [Предмет или школа] 
for Значение in (ush, predmet) ) 
unpvt
