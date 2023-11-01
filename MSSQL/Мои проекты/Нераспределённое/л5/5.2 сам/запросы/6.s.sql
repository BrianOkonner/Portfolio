select fio, [2011],[2012],[2013],[2014],
[2015]
from dbo.test_table_pivot
pivot (sum(summa)for god in (
[2011],[2012],[2013],[2014],[2015]))
as test_pivot
