# Write your MySQL query statement below
SELECT name 
FROM Employee e1 
WHERE (
    SELECT COUNT(*) 
    FROM Employee e2 
    WHERE e2.managerId is not null and e2.managerId = e1.id
) >= 5;
