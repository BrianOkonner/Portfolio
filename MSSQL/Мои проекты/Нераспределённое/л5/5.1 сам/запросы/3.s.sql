use	TestDatabas
select ush, predmet, avg(ball)
as kol
from Table_uch1
group by ush, predmet with rollup