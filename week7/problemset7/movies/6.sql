Select AVG(rating)
from ratings
where movie_id in (SELECT id as movie_id
                   FROM movies
                   WHERE year = '2012');
