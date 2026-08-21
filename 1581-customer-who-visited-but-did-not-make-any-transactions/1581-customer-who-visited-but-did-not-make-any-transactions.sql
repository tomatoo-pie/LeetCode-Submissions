# Write your MySQL query statement below
SELECT customer_id, COUNT(*) as count_no_trans
FROM Visits as l
LEFT JOIN Transactions as r
ON l.visit_id = r.visit_id
    WHERE r.visit_id IS NULL
GROUP BY customer_id;