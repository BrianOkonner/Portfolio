select	FirstName, VacationHours + SickLeaveHours as FreeHours
from DimEmployee
order by FreeHours