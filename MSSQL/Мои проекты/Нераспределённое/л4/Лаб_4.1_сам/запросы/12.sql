select
		*
from
		Student
order by	
		FIO
		OFFSET 6 rows
		fetch next 1 rows ONLY