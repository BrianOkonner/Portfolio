use	TestDatabas
select 
iif(grouping(predmet)=1, '�����', predmet) as predmet,
iif(grouping(ush)=1, '�����', ush) as ush,
count(fio) as kol
from Table_uch1
group by
cube (predmet,ush)