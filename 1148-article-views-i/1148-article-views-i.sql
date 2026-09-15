Select author_id as id
from Views
Where author_id = viewer_id
Group by id
order by id;