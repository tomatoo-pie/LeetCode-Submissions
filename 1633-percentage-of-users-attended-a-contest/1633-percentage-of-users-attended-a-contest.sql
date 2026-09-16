# Write your MySQL query statement below
Select r.contest_id, round((count(u.user_id)/(Select count(*) from Users)) * 100,2) as percentage 
from Users u
JOIN Register r
ON u.user_id = r.user_id
group by r.contest_id
order by percentage desc, r.contest_id;