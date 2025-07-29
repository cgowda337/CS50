SELECT DISTINCT a.title
FROM movies a
LEFT JOIN directors c on a.id == c.movie_id
LEFT JOIN ratings b on b.movie_id == a.id
LEFT JOIN people d on c.person_id == d.id
WHERE d.name == 'Chadwick Boseman'
order by b.rating DESC
LIMIT 5;
