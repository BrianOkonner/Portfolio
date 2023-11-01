use TestDatabas
select
otdel, sum(summa) as rashod
from test_table
Group by otdel with rollup