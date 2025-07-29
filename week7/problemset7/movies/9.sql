SELECT DISTINCT b.name
FROM movies a
LEFT JOIN stars c on a.id == c.movie_id
LEFT JOIN people b on b.id == c.person_id
WHERE a.year = '2004'
order by b.birth;
