# Write your MySQL query statement below
select reports_to as employee_id,
(select name
from employees e1
where e.reports_to = e1.employee_id) as name,
count(reports_to) as reports_count,
round(
    avg(age)
) as average_age
from employees e
group by reports_to
having reports_count > 0
order by employee_id;
