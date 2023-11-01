use	TestDatabas
select
ush,
Математика,
Физика,
Химия
from ( select
ush, predmet, fio
from
Table_uch1 ) as SOURCE_TABLE
pivot
( count(fio)
for predmet in (Математика, Физика, Химия) ) 
as PIVOT_TABLE
