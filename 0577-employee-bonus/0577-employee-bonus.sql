# Write your MySQL query statement below
SELECT name, bonus
FROM Employee as e
LEFT JOIN Bonus as b
ON e.empID = b.empID
WHERE b.bonus IS NULL OR b.bonus < 1000;