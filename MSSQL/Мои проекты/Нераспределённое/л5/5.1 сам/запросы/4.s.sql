use	TestDatabas
select 
coalesce(ush, '�����') as ush,
coalesce(predmet, '�����') as predmet,
count(fio) as kol
from Table_uch1
group by
rollup(predmet,ush)