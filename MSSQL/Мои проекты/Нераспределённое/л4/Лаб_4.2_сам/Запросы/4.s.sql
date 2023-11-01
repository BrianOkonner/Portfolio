select	FirstName, VacationHours, SickLeaveHours
from DimEmployee
order by VacationHours + SickLeaveHours