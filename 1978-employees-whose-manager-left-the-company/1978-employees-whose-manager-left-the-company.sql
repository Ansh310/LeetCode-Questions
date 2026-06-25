# Write your MySQL query statement below
select employee_id
from Employees
where salary < 30000 and manager_id is not null and not exists (
    select e1.employee_id
    from Employees e1
    where e1.employee_id = Employees.manager_id
)
order by employee_id 