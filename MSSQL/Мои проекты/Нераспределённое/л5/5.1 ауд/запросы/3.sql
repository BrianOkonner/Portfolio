use	TestDatabas
select predmet, ush, count(fio)
as kol
from Table_uch1
group by predmet, ush with rollup