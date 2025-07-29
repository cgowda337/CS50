-- stars movies people
SELECT title
FROM movies
where id in (SELECT a.id FROM movies a LEFT JOIN stars b ON a.id == b.movie_id LEFT JOIN people c ON c.id == b.person_id WHERE c.name = 'Bradley Cooper') AND id in (SELECT a.id FROM movies a LEFT JOIN stars b ON a.id == b.movie_id LEFT JOIN people c ON c.id == b.person_id WHERE c.name = 'Jennifer Lopez');


