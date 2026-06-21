# Write your MySQL query statement below
select e.employee_id, e.department_id
from Employee e
where e.primary_flag = 'Y' or (not exists(
    select e1.employee_id
    from Employee e1
    where e1.employee_id = e.employee_id and e1.department_id != e.department_id
));