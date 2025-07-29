SELECT DISTINCT name
FROM people a
LEFT JOIN stars b ON b.person_id == a.id
where b.movie_id in (SELECT a.id FROM movies a LEFT JOIN stars b ON a.id == b.movie_id LEFT JOIN people c ON c.id == b.person_id WHERE c.name = 'Kevin Bacon') and name is not 'Kevin Bacon';
