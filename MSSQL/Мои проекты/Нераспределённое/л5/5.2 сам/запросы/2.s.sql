use	TestDatabas
select
predmet,
Гимназия,
Лицей
from ( select
predmet ,ush, ball
from
Table_uch1 ) as SOURCE_TABLE
pivot
( avg(ball)
for ush in (Гимназия, Лицей) ) 
as PIVOT_TABLE
