-- select top 5 songs by length, order by descending length
SELECT DISTINCT name
FROM songs
ORDER BY duration_ms DESC
LIMIT 5;
