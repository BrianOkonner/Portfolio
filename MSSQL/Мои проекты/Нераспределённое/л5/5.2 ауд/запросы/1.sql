use	TestDatabas
select
'����������' as [���������� �������� �� ���������],
����������,
������,
�����
from ( select
predmet, fio
from
Table_uch1 ) as SOURCE_TABLE
pivot
( count(fio)
for predmet in (����������, ������, �����) ) 
as PIVOT_TABLE
