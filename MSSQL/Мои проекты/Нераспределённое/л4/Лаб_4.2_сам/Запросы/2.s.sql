use AdventureWorksDW2019
select	* from	DimEmployee;
select	FirstName + ' (' + LastName + ')', 
DepartmentName, VacationHours + SickLeaveHours
from DimEmployee;
--1
select	FirstName + ' (' + LastName + ')'  AS Name, 
DepartmentName, VacationHours + SickLeaveHours as FreeHours
from DimEmployee;
--2
select	FirstName + ' (' + LastName + ')'  AS Name, 
Title 
into EmployeeName
from DimEmployee;
select * from EmployeeName
--3