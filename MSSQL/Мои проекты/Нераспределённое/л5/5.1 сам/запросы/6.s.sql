select
case grouping_id(ush,predmet)
when 1 then '����� �� ������'
when 3 then '�����'
else ''
end as �����,
isnull(ush, '') as ush,
isnull(predmet, '') as predmet,
count(fio) as kol
from Table_uch1
group by
rollup(ush,predmet)