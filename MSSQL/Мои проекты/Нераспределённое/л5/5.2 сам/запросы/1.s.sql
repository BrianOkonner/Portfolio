use	TestDatabas
select
'Средний балл' as [Средний балл по школам],
Гимназия,
Лицей
from ( select
ush, ball
from
Table_uch1 ) as SOURCE_TABLE
pivot
( avg(ball)
for ush in (Гимназия, Лицей) ) 
as PIVOT_TABLE
