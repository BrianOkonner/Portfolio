select
		*
from
		Student
order by	
		FIO
		OFFSET 4 rows
		fetch next 5 rows ONLY