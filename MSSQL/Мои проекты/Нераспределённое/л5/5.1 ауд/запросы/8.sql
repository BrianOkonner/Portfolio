select
case grouping_id(predmet, ush)
when 1 then '����� �� ���������'
when 3 then '�����'
else ''
end as �����,
isnull(predmet, '') as predmet,
isnull(ush, '') as ush,
count(fio) as kol
from Table_uch1
group by
rollup(predmet,ush)