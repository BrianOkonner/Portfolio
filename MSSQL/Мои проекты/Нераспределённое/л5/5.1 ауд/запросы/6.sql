use	TestDatabas
select 
coalesce(predmet, '�����') as predmet,
coalesce(ush, '�����') as ush,
count(fio) as kol
from Table_uch1
group by
rollup(predmet,ush)