SELECT DISTINCT d.name as name
FROM movies a
LEFT JOIN directors c on a.id == c.movie_id
LEFT JOIN ratings b on b.movie_id == a.id
LEFT JOIN people d on c.person_id == d.id
WHERE b.rating >= 9.0 and name is not NULL;
