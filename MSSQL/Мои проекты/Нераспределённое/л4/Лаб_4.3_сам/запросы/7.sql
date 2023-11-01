use Lab4
select *
from Products 
where 
ProductCount > 2 and
(Manufacturer != 'samsung' or Price > 30000)