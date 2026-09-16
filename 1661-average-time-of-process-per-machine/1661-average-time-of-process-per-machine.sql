# Write your MySQL query statement below
SELECT start.machine_id,round(avg(end.timestamp) - avg(start.timestamp),3) as processing_time
FROM Activity as start
JOIN Activity as end
ON start.machine_id = end.machine_id
and start.process_id = end.process_id
and start.activity_type = 'start'
and end.activity_type = 'end'
group by start.machine_id;