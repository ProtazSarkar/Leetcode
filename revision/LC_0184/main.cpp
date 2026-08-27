# Write your MySQL query statement below
with MaxSalaryInDept as (
    select
        max(salary) as maxsalary,
        departmentId as dept
    from Employee
    group by departmentId
)

select 
    d.name as Department,
    e.name as Employee,
    e.salary
from Employee e
join Department d
on e.departmentId = d.id
where (e.salary,d.id) in (
    select maxsalary,dept
    from MaxSalaryInDept
)