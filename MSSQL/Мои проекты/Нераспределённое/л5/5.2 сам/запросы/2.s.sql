use	TestDatabas
select
predmet,
��������,
�����
from ( select
predmet ,ush, ball
from
Table_uch1 ) as SOURCE_TABLE
pivot
( avg(ball)
for ush in (��������, �����) ) 
as PIVOT_TABLE
