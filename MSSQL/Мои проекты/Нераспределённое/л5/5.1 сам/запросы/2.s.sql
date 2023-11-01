use	TestDatabas
select ush, predmet, min(ball)
as kol
from Table_uch1
group by ush, predmet with rollup