# Write your MySQL query statement below
Select *
From Cinema
Where id%2 != 0 and description not like 'boring'
order by rating desc;