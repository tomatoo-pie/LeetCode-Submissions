Select product_name, year , price
from Sales s
JOIN Product p
on p.product_id = s.product_id;