use TestDatabas
select
god, sum(summa) as rashod
from test_table
Group by god with rollup