use TestDatabas
select
otdel, god, sum(summa) as rashod
from test_table
Group by otdel, god with rollup