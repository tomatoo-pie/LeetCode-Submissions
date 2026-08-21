# Write your MySQL query statement below
SELECT unique_id, name
FROM Employees as e
LEFT JOIN EmployeeUNI as en
On e.id = en.id;