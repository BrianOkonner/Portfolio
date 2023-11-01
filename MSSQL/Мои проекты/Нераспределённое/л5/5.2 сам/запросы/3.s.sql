use	TestDatabas
select
predmet, [Фамилия или школа]
from 
Table_uch1 
unpivot
( [Фамилия или школа] 
for Значение in (ush, fio) ) 
unpvt