use	TestDatabas
select
'Количество' as [Количество учеников по предметам],
Математика,
Физика,
Химия
from ( select
predmet, fio
from
Table_uch1 ) as SOURCE_TABLE
pivot
( count(fio)
for predmet in (Математика, Физика, Химия) ) 
as PIVOT_TABLE
