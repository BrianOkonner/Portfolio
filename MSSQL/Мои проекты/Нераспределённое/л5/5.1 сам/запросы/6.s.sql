select
case grouping_id(ush,predmet)
when 1 then 'Итого по школам'
when 3 then 'Итого'
else ''
end as Итого,
isnull(ush, '') as ush,
isnull(predmet, '') as predmet,
count(fio) as kol
from Table_uch1
group by
rollup(ush,predmet)