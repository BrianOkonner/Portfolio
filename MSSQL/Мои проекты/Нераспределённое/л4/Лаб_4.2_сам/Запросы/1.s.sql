use AdventureWorksDW2019
select	*
from
		DimEmployee;
select	FirstName + ' (' + LastName + ')' As Name, 
DepartmentName, VacationHours + SickLeaveHours As FreeHours
from
		DimEmployee;