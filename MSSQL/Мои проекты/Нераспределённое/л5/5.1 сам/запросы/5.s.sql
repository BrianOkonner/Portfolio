use	TestDatabas
select 
iif(grouping(ush)=1, 'ÈÒÎÃÎ', ush) as ush,
iif(grouping(predmet)=1, 'Èòîãî', predmet) as predmet,
count(fio) as kol
from Table_uch1
group by
cube (ush,predmet)