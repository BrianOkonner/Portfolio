use TestDatabas
select
otdel, god, sum(summa) as rashod
from test_table
group by
grouping sets(otdel,god)