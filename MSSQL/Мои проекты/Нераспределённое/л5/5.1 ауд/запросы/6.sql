use	TestDatabas
select 
coalesce(predmet, '»“Œ√Œ') as predmet,
coalesce(ush, '»ÚÓ„Ó') as ush,
count(fio) as kol
from Table_uch1
group by
rollup(predmet,ush)