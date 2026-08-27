# Write your MySQL query statement below
with NumberLags as (
    select
    num,
    lag(num,1) over() as prev1,
    lag(num,2) over() as prev2

    from Logs
)

select distinct num as ConsecutiveNums 
from NumberLags
where num = prev1 and num = prev2