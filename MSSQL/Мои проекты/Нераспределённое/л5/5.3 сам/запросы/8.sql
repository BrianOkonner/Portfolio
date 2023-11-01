select otdel,
isnull(cast(god as varchar(30)),
case when grouping(god)=1 and grouping(otdel)=0
then 'Промежуточный итог' else 'Общий итог' end) as god,
sum(summa) as itog,
grouping(otdel) as grouping_otdel,
grouping(god) as grouping_god
from dbo.test_table
group by
rollup (otdel,god)