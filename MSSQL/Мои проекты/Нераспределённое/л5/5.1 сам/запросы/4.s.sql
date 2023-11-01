use	TestDatabas
select 
coalesce(ush, '»“Œ√Œ') as ush,
coalesce(predmet, '»ÚÓ„Ó') as predmet,
count(fio) as kol
from Table_uch1
group by
rollup(predmet,ush)