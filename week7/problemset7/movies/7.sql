SELECT a.title, b.rating
FROM movies as a
LEFT JOIN ratings b on b.movie_id == a.id
WHERE a.year = '2010' and b.rating not null
order by rating desc, title;
